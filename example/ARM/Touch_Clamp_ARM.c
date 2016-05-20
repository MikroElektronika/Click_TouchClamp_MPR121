#include "touch_clamp_hw.h"
#include "touch_clamp_hal.h"
#include "resources.h"

unsigned int TFT_DataPort at GPIOE_ODR;
sbit TFT_RST at GPIOE_ODR.B8;
sbit TFT_RS at GPIOE_ODR.B12;
sbit TFT_CS at GPIOE_ODR.B15;
sbit TFT_RD at GPIOE_ODR.B10;
sbit TFT_WR at GPIOE_ODR.B11;
sbit TFT_BLED at GPIOE_ODR.B9;

uint8_t status = 0;
uint8_t status_last = 0;

void system_init()
{
    I2C1_Init_Advanced( 100000, &_GPIO_MODULE_I2C1_PB67 );
    Delay_ms( 200 );
}

static void display_init()
{
    TFT_Init_ILI9341_8bit( 320, 240 );
    TFT_Set_Pen( CL_WHITE, 1 );
    TFT_Set_Brush( 1, CL_WHITE, 0, 0, 0, 0 );
    TFT_Set_Font( TFT_defaultFont, CL_BLACK, FO_HORIZONTAL );
    TFT_Fill_Screen( CL_WHITE);
    TFT_Set_Pen( CL_Black, 1 );
    TFT_Line( 20, 220, 300, 220 );
    TFT_LIne( 20,  46, 300,  46 );
    TFT_Set_Font( &HandelGothic_BT21x22_Regular, CL_RED, FO_HORIZONTAL);
    TFT_Write_Text( "TouchClamp click", 75, 14 );
    TFT_Set_Font( &Verdana12x13_Regular, CL_BLACK, FO_HORIZONTAL );
    TFT_Write_Text( "EasyMx PRO v7 for STM32", 19, 223);
    TFT_Set_Font( &Verdana12x13_Regular, CL_RED, FO_HORIZONTAL );
    TFT_Write_Text( "www.mikroe.com", 200, 223 );
    TFT_Set_Font( &Tahoma15x16_Bold, CL_BLUE, FO_HORIZONTAL );
    TFT_Set_Pen( CL_WHITE, 1 );
}

void main()
{
    system_init();
    display_init();
    tc_hal_init( 0x5A );
    tc_default_config();
    Delay_ms( 200 );
    
    while( 1 )
    {
        status = tc_get_reg_ts();
        
        if( status != status_last )
        {
            TFT_Rectangle( 30, 50, 310, 210 );
            
            if( status & ( 1 << ELE_A ) )
            {
                TFT_Write_Text( "Ajvar", 135, 60 );
                TFT_Image_Jpeg( 40, 90, ajvar_jpg );
            }
            
            if( status & ( 1 << ELE_C ) )
            {
                TFT_Write_Text( "Coffee", 135, 60 );
                TFT_Image_Jpeg( 40, 90, coffee_jpg );
            }
            
            if( status & ( 1 << ELE_E ) )
            {
                TFT_Write_Text( "Sugar", 135, 60 );
                TFT_Image_Jpeg( 40, 90, sugar_jpg );
            }
            
            if( status & ( 1 << ELE_G ) )
            {
                TFT_Write_Text( "Muesli", 135, 60 );
                TFT_Image_Jpeg( 40, 90, muesli_jpg );
            }
        }
        status_last = status;
    }
}