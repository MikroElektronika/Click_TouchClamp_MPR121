/*******************************************************************************
* Title                 :   Touch Clamp HW layer
* Filename              :   touch_clamp_hw.c
* Author                :   MSV
* Origin Date           :   13/01/2016
* Notes                 :   None
*******************************************************************************/
/*************** MODULE REVISION LOG ******************************************
*
*    Date    Software Version    Initials   Description 
*  13/01/16    XXXXXXXXXXX         MSV      Module Created.
*
*******************************************************************************/
/**
 * @file touch_clamp_hw.c
 *
 * @brief <h3> Hardware layer </h3>
 */
/******************************************************************************
* Includes
*******************************************************************************/
#include "touch_clamp_hw.h"
/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/******************************************************************************
* Module Typedefs
*******************************************************************************/

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Function Definitions
*******************************************************************************/
void tc_default_config( void )
{
    int i = 0;
    
    tc_set_cl( CL_0 );
    tc_set_active( 0 );
    tc_set_eleprox( ELEPROX_DISABLED );
    tc_set_max_hd( FCS_RISING, ELEF_TOUCH, 1 );
    tc_set_max_hd( FCS_FALLING, ELEF_TOUCH, 1 );
    tc_set_max_hd( FCS_RISING, ELEF_PROXIMITY, 15 );
    tc_set_max_hd( FCS_FALLING, ELEF_PROXIMITY, 1 );
    tc_set_noise_hd( FCS_RISING, ELEF_TOUCH, 1 );
    tc_set_noise_hd( FCS_FALLING, ELEF_TOUCH, 1 );
    tc_set_noise_hd( FCS_TOUCHED, ELEF_TOUCH, 1 );
    tc_set_noise_hd( FCS_RISING, ELEF_PROXIMITY, 15 );
    tc_set_noise_hd( FCS_FALLING, ELEF_PROXIMITY, 1 );
    tc_set_noise_hd( FCS_TOUCHED, ELEF_PROXIMITY, 0 );
    tc_set_ncl( FCS_RISING, ELEF_TOUCH, 16 );
    tc_set_ncl( FCS_FALLING, ELEF_TOUCH, 16 );
    tc_set_ncl( FCS_TOUCHED, ELEF_TOUCH, 16 );
    tc_set_ncl( FCS_RISING, ELEF_PROXIMITY, 0 );
    tc_set_ncl( FCS_FALLING, ELEF_PROXIMITY, 15 );
    tc_set_ncl( FCS_TOUCHED, ELEF_PROXIMITY, 0 );
    tc_set_filter_dcl( FCS_RISING, ELEF_TOUCH, 32 );
    tc_set_filter_dcl( FCS_FALLING, ELEF_TOUCH, 32 );
    tc_set_filter_dcl( FCS_TOUCHED, ELEF_TOUCH, 255 );
    tc_set_filter_dcl( FCS_RISING, ELEF_PROXIMITY, 0 );
    tc_set_filter_dcl( FCS_FALLING, ELEF_PROXIMITY, 255 );
    tc_set_filter_dcl( FCS_TOUCHED, ELEF_PROXIMITY, 0 );
    tc_set_debounce( TS_RELEASE, 1 );
    tc_set_debounce( TS_TOUCH, 1 );
    tc_set_ffi( FFI_34 );
    tc_set_global_cdc( 63 );
    tc_set_global_cdt( CDT_05 );
    tc_set_sfi( SFI_10 );
    tc_set_esi( ESI_1 );

    for ( i = 0; i < 13; i++ )
        tc_set_th( TS_TOUCH, i, 40 );

    for ( i = 0; i < 13; i++ )
        tc_set_th( TS_RELEASE, i, 20 );

    tc_set_cl( CL_2 );
    tc_set_active( 10 );
    tc_set_eleprox( ELEPROX_DISABLED );
}

TC_TS_t tc_get_ts( TC_ELE_t electrode )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = 0;

    if ( electrode > 12 )
        return TS_RELEASE;

    if ( electrode <= 8 )
        temp_cmd = T_STATUS_1;
    else
        temp_cmd = T_STATUS_2;

    tc_hal_read( &temp_cmd, &temp, 1 );

    return ( ( temp >> ( electrode % 8 ) ) & 0x01 ) ? TS_TOUCH : TS_RELEASE;
}

uint8_t tc_get_reg_ts( void )
{
   uint8_t temp         = 0;
   uint8_t temp_cmd     = T_STATUS_1;

   tc_hal_read( &temp_cmd, &temp, 1 );

   return temp;
}

TC_OCFS_t tc_get_ocfs()
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = T_STATUS_2;

    tc_hal_read( &temp_cmd, &temp, 1 );

    return temp >> 7;
}

void tc_reset_ocfs()
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = T_STATUS_2;
    
    temp = 1 << 7;

    tc_hal_write( &temp_cmd, &temp, 1 );
}

uint16_t tc_get_ele_data( TC_ELE_t electrode )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = 0;
    uint16_t output     = 0;

    temp_cmd    = ExFDH + ( 2 * electrode );
    tc_hal_read( &temp_cmd, &temp, 1 );
    output = ( temp & 0x03 ) << 8;
    temp_cmd    = ExFDL + ( 2 * electrode );
    tc_hal_read( &temp_cmd, &temp, 1 );
    output |= temp;

    return output;
}

void tc_set_baseline( TC_ELE_t electrode,
                      uint8_t value )
{
    uint8_t temp_cmd    = ExBV + electrode;

    tc_hal_write( &temp_cmd, &value, 1 );
}

uint8_t tc_get_baseline( TC_ELE_t electrode )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = ExBV + electrode;

    tc_hal_read( &temp_cmd, &temp, 1 );

    return temp;
}

void tc_set_max_hd( TC_FCS_t scenario,
                    TC_ELEF_t function,
                    uint8_t value )
{
    uint8_t temp_cmd    = 0;

    if ( !function )
    {
        switch ( scenario ) {

        case 0 :
            temp_cmd = MHDR;
            tc_hal_write( &temp_cmd, &value, 1 );
            break;

        case 1 :
            temp_cmd = MHDF;
            tc_hal_write( &temp_cmd, &value, 1 );
            break;

        default :
            break;
        }

    } else {

        switch ( scenario ) {

        case 0 :
            temp_cmd = MHDPROXR;
            tc_hal_write( &temp_cmd, &value, 1 );
            break;

        case 1 :
            temp_cmd = MHDPROXF;
            tc_hal_write( &temp_cmd, &value, 1 );
            break;

        default :
            break;
        }
    }
}

uint8_t tc_get_max_hd( TC_FCS_t scenario,
                       TC_ELEF_t function )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = 0;

    if ( !function )
    {
        switch ( scenario ) {

        case 0 :
            temp_cmd = MHDR;
            tc_hal_read( &temp_cmd, &temp, 1 );
            break;

        case 1 :
            temp_cmd = MHDF;
            tc_hal_read( &temp_cmd, &temp, 1 );
            break;

        default :
            break;
        }

    } else {

        switch ( scenario ) {

        case 0 :
            temp_cmd = MHDPROXR;
            tc_hal_write( &temp_cmd, &temp, 1 );
            break;

        case 1 :
            temp_cmd = MHDPROXF;
            tc_hal_write( &temp_cmd, &temp, 1 );
            break;

        default :
            break;
        }
    }
    return temp;
}

void tc_set_noise_hd( TC_FCS_t scenario,
                      TC_ELEF_t function,
                      uint8_t value )
{
    uint8_t temp_cmd    = 0;

    if ( !function )
    {
        switch ( scenario ) {

        case 0 :
            temp_cmd = NHDR;
            tc_hal_write( &temp_cmd, &value, 1 );
            break;

        case 1 :
            temp_cmd = NHDF;
            tc_hal_write( &temp_cmd, &value, 1 );
            break;

        case 2 :
            temp_cmd = NHDT;
            tc_hal_write( &temp_cmd, &value, 1 );
            break;
        }

    } else {

        switch ( scenario ) {

        case 0 :
            temp_cmd = NHDPROXR;
            tc_hal_write( &temp_cmd, &value, 1 );
            break;

        case 1 :
            temp_cmd = NHDPROXF;
            tc_hal_write( &temp_cmd, &value, 1 );
            break;

        case 2 :
            temp_cmd = NHDPROXT;
            tc_hal_write( &temp_cmd, &value, 1 );
            break;
        }
    }
}

uint8_t tc_get_noise_hd( TC_FCS_t scenario,
                         TC_ELEF_t function )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = 0;

    if ( !function )
    {
        switch ( scenario ) {

        case 0 :
            temp_cmd = NHDR;
            tc_hal_read( &temp_cmd, &temp, 1 );
            break;

        case 1 :
            temp_cmd = NHDF;
            tc_hal_read( &temp_cmd, &temp, 1 );
            break;

        case 2 :
            temp_cmd = NHDT;
            tc_hal_read( &temp_cmd, &temp, 1 );
            break;
        }

    } else {

        switch ( scenario ) {

        case 0 :
            temp_cmd = NHDPROXR;
            tc_hal_read( &temp_cmd, &temp, 1 );
            break;

        case 1 :
            temp_cmd = NHDPROXF;
            tc_hal_read( &temp_cmd, &temp, 1 );
            break;

        case 2 :
            temp_cmd = NHDPROXT;
            tc_hal_read( &temp_cmd, &temp, 1 );
            break;
        }
    }
    return temp;
}

void tc_set_ncl( TC_FCS_t scenario,
                 TC_ELEF_t function,
                 uint8_t value )
{
    uint8_t temp_cmd    = 0;

    if ( !function )
    {
        switch ( scenario ) {

        case 0 :
            temp_cmd = NCLR;
            tc_hal_write( &temp_cmd, &value, 1 );
            break;

        case 1 :
            temp_cmd = NCLF;
            tc_hal_write( &temp_cmd, &value, 1 );
            break;

        case 2 :
            temp_cmd = NCLT;
            tc_hal_write( &temp_cmd, &value, 1 );
            break;
        }

    } else {

        switch ( scenario ) {

        case 0 :
            temp_cmd = NCLPROXR;
            tc_hal_write( &temp_cmd, &value, 1 );
            break;

        case 1 :
            temp_cmd = NCLPROXF;
            tc_hal_write( &temp_cmd, &value, 1 );
            break;

        case 2 :
            temp_cmd = NCLPROXT;
            tc_hal_write( &temp_cmd, &value, 1 );
            break;
        }
    }
}

uint8_t tc_get_ncl( TC_FCS_t scenario,
                    TC_ELEF_t function )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = 0;

    if ( !function )
    {
        switch ( scenario ) {

        case 0 :
            temp_cmd = NCLR;
            tc_hal_read( &temp_cmd, &temp, 1 );
            break;

        case 1 :
            temp_cmd = NCLF;
            tc_hal_read( &temp_cmd, &temp, 1 );
            break;

        case 2 :
            temp_cmd = NCLT;
            tc_hal_read( &temp_cmd, &temp, 1 );
            break;
        }

    } else {

        switch ( scenario ) {

        case 0 :
            temp_cmd = NCLPROXR;
            tc_hal_read( &temp_cmd, &temp, 1 );
            break;

        case 1 :
            temp_cmd = NCLPROXF;
            tc_hal_read( &temp_cmd, &temp, 1 );
            break;

        case 2 :
            temp_cmd = NCLPROXT;
            tc_hal_read( &temp_cmd, &temp, 1 );
            break;
        }
    }
    return temp;
}

void tc_set_filter_dcl( TC_FCS_t scenario,
                        TC_ELEF_t function,
                        uint8_t value )
{
    uint8_t temp_cmd    = 0;

    if ( !function )
    {
        switch ( scenario ) {

        case 0 :
            temp_cmd = FDLR;
            tc_hal_write( &temp_cmd, &value, 1 );
            break;

        case 1 :
            temp_cmd = FDLF;
            tc_hal_write( &temp_cmd, &value, 1 );
            break;

        case 2 :
            temp_cmd = FDLT;
            tc_hal_write( &temp_cmd, &value, 1 );
            break;
        }

    } else {

        switch ( scenario ) {

        case 0 :
            temp_cmd = FDLPROXR;
            tc_hal_write( &temp_cmd, &value, 1 );
            break;

        case 1 :
            temp_cmd = FDLPROXF;
            tc_hal_write( &temp_cmd, &value, 1 );
            break;

        case 2 :
            temp_cmd = FDLPROXT;
            tc_hal_write( &temp_cmd, &value, 1 );
            break;
        }
    }
}

uint8_t tc_get_filter_dcl( TC_FCS_t scenario,
                           TC_ELEF_t function )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = 0;

    if ( !function )
    {
        switch ( scenario ) {

        case 0 :
            temp_cmd = FDLR;
            tc_hal_read( &temp_cmd, &temp, 1 );
            break;

        case 1 :
            temp_cmd = FDLF;
            tc_hal_read( &temp_cmd, &temp, 1 );
            break;

        case 2 :
            temp_cmd = FDLT;
            tc_hal_read( &temp_cmd, &temp, 1 );
            break;
        }

    } else {

        switch ( scenario ) {

        case 0 :
            temp_cmd = FDLPROXR;
            tc_hal_read( &temp_cmd, &temp, 1 );
            break;

        case 1 :
            temp_cmd = FDLPROXF;
            tc_hal_read( &temp_cmd, &temp, 1 );
            break;

        case 2 :
            temp_cmd = FDLPROXT;
            tc_hal_read( &temp_cmd, &temp, 1 );
            break;
        }
    }
    return temp;
}

void tc_set_th( TC_TS_t status,
                TC_ELE_t electrode,
                uint8_t th_value )
{
    uint8_t temp_cmd    = 0;

    if ( status )
    {
        temp_cmd = ExTTH + ( 2 * electrode );
        tc_hal_write( &temp_cmd, &th_value, 1 );

    } else {

        temp_cmd = ExRTH + ( 2 * electrode );
        tc_hal_write( &temp_cmd, &th_value, 1 );
    }
}

uint8_t tc_get_th( TC_TS_t status,
                   TC_ELE_t electrode )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = 0;

    if ( status )
    {
        temp_cmd = ExTTH + ( 2 * electrode );
        tc_hal_read( &temp_cmd, &temp, 1 );

    } else {

        temp_cmd = ExRTH + ( 2 * electrode );
        tc_hal_read( &temp_cmd, &temp, 1 );
    }

    return temp;
}

void tc_set_debounce( TC_TS_t status,
                      uint8_t value )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = DRDT;

    if ( status )
    {
        temp = value & 0x07;
        tc_hal_write( &temp_cmd, &temp, 1 );

    } else {

        temp = ( value & 0x07 ) << 4;
        tc_hal_write( &temp_cmd, &temp, 1 );
    }
}


uint8_t tc_get_debounce( TC_TS_t status )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = DRDT;

    if ( status )
    {
        tc_hal_write( &temp_cmd, &temp, 1 );
        temp &= 0x07;

    } else {

        tc_hal_write( &temp_cmd, &temp, 1 );
        temp = ( temp >> 4 ) & 0x07;
    }

    return temp;
}

void tc_set_ffi( TC_FFI_t samples )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = AFECFG1;

    tc_hal_read( &temp_cmd, &temp, 1 );
    temp &= 0x3F;
    temp |= samples << 6;
    tc_hal_write( &temp_cmd, &temp, 1 );
}

TC_FFI_t tc_get_ffi( void )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = AFECFG1;

    tc_hal_read( &temp_cmd, &temp, 1 );
    temp = ( temp >> 6 ) & 0x03;

    return temp;
}

void tc_set_global_cdc( uint8_t current )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = AFECFG1;

    tc_hal_read( &temp_cmd, &temp, 1 );
    temp &= 0xC0;
    temp |= ( current & 0x3F );
    tc_hal_write( &temp_cmd, &temp, 1 );
}

uint8_t tc_get_global_cdc( void )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = AFECFG1;

    tc_hal_read( &temp_cmd, &temp, 1 );
    temp &= 0x3F;

    return temp;
}
void tc_set_global_cdt( TC_CDT_t time )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = AFECFG2;

    tc_hal_read( &temp_cmd, &temp, 1 );
    temp &= 0x0E;
    temp |= time << 5;
    tc_hal_write( &temp_cmd, &temp, 1 );
}

TC_CDT_t tc_get_global_cdt( void )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = AFECFG2;

    tc_hal_read( &temp_cmd, &temp, 1 );
    temp = ( temp >> 5 ) & 0x07;

    return temp;
}

void tc_set_sfi( TC_SFI_t samples )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = AFECFG2;

    tc_hal_read( &temp_cmd, &temp, 1 );
    temp &= 0x18;
    temp |= samples << 3;
    tc_hal_write( &temp_cmd, &temp, 1 );
}

TC_SFI_t tc_get_sfi( void )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = AFECFG2;

    tc_hal_read( &temp_cmd, &temp, 1 );
    temp = ( temp >> 3 ) & 0x03;

    return temp;
}

void tc_set_esi( TC_ESI_t interval )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = AFECFG2;

    tc_hal_read( &temp_cmd, &temp, 1 );
    temp &= 0xF8;
    temp |= ( interval & 0x07 );
    tc_hal_write( &temp_cmd, &temp, 1 );
}

TC_ESI_t tc_get_esi( void )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = AFECFG2;

    tc_hal_read( &temp_cmd, &temp, 1 );
    temp &= 0x07;

    return temp;
}

void tc_set_cdc( TC_ELE_t electrode,
                 uint8_t current )
{
    uint8_t temp_cmd = CDCx + electrode;

    current &= 0x3F;
    tc_hal_write( &temp_cmd, &current, 1 );
}

uint8_t tc_get_cdc( TC_ELE_t electrode )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = CDCx + electrode;

    tc_hal_read( &temp_cmd, &temp, 1 );
    temp &= 0x3F;

    return temp;
}

void tc_set_cdt( TC_ELE_t electrode,
                 TC_CDT_t time )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = CDT_x + ( electrode / 2 );

    tc_hal_read( &temp_cmd, &temp, 1 );

    if ( electrode % 2 )
    {
        temp &= 0x8F;
        temp |= ( time << 4 );

    } else {

        temp &= 0xF8;
        temp |= time;
    }
    tc_hal_write( &temp_cmd, &temp, 1 );
}

TC_CDT_t tc_get_cdt( TC_ELE_t electrode )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = CDT_x + ( electrode / 2 );

    tc_hal_read( &temp_cmd, &temp, 1 );

    if ( electrode % 2 )
        temp = ( temp >> 4 ) & 0x07;
    else
        temp &= 0x07;

    return temp;
}

void tc_set_cl( TC_CL_t lock )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = ECR;

    tc_hal_read( &temp_cmd, &temp, 1 );
    temp &= 0x3F;
    temp |= ( lock << 6 );
    tc_hal_write( &temp_cmd, &temp, 1 );
}

TC_CL_t tc_get_cl( void )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = ECR;

    tc_hal_read( &temp_cmd, &temp, 1 );
    temp = ( temp >> 6 ) & 0x03;

    return temp;
}

void tc_set_active( TC_ELE_t electrodes )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = ECR;

    tc_hal_read( &temp_cmd, &temp, 1 );
    temp &= 0xF0;
    temp |= electrodes;
    tc_hal_write( &temp_cmd, &temp, 1 );
}

TC_ELE_t tc_get_active( void )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = ECR;

    tc_hal_read( &temp_cmd, &temp, 1 );
    temp &= 0x0F;

    return temp;
}

void tc_set_eleprox( TC_ELEPROX_t value )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = ECR;

    tc_hal_read( &temp_cmd, &temp, 1 );
    temp &= 0xCF;
    temp |= ( value << 4 );
    tc_hal_write( &temp_cmd, &temp, 1 );
}

TC_ELEPROX_t tc_get_eleprox( void )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = ECR;

    tc_hal_read( &temp_cmd, &temp, 1 );
    temp = ( temp >> 4 ) & 0x03;

    return temp;
}

void tc_set_up_sl( uint8_t value )
{
    uint8_t temp_cmd    = ACUSL;

    tc_hal_write( &temp_cmd, &value, 1 );
}

uint8_t tc_get_up_sl( void )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = ACUSL;

    tc_hal_read( &temp_cmd, &temp, 1 );

    return temp;
}

void tc_set_low_sl( uint8_t value )
{
    uint8_t temp_cmd    = ACLSL;

    tc_hal_write( &temp_cmd, &value, 1 );
}

uint8_t tc_get_low_sl( void )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = ACLSL;

    tc_hal_read( &temp_cmd, &temp, 1 );

    return temp;
}

void tc_set_tl( uint8_t value )
{
    uint8_t temp_cmd    = ACTL;

    tc_hal_write( &temp_cmd, &value, 1 );
}

uint8_t tc_get_tl( void )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = ACTL;

    tc_hal_read( &temp_cmd, &temp, 1 );

    return temp;
}

void tc_set_auto_config( TC_AC_t value )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = ACCR0;

    tc_hal_read( &temp_cmd, &temp, 1 );
    temp &= 0xFE;
    temp |= value;
    tc_hal_write( &temp_cmd, &temp, 1 );
}

TC_AC_t tc_get_auto_config( void )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = ACCR0;

    tc_hal_read( &temp_cmd, &temp, 1 );
    temp &= 0x01;

    return temp;
}

void tc_set_auto_reconfig( TC_ARC_t value )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = ACCR0;

    tc_hal_read( &temp_cmd, &temp, 1 );
    temp &= 0xFD;
    temp |= ( value << 1 );
    tc_hal_write( &temp_cmd, &temp, 1 );
}

TC_ARC_t tc_get_auto_reconfig( void )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = ACCR0;

    tc_hal_read( &temp_cmd, &temp, 1 );
    temp = ( temp >> 1 ) & 0x01;

    return temp;
}

void tc_set_bvac( TC_BVAC_t value )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = ACCR0;

    tc_hal_read( &temp_cmd, &temp, 1 );
    temp &= 0xF3;
    temp |= ( value << 2 );
    tc_hal_write( &temp_cmd, &temp, 1 );
}

TC_BVAC_t tc_get_bvac( void )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = ACCR0;

    tc_hal_read( &temp_cmd, &temp, 1 );
    temp = ( temp >> 2 ) & 0x03;

    return temp;
}

void tc_set_config_retry( TC_RETRY_t value )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = ACCR0;

    tc_hal_read( &temp_cmd, &temp, 1 );
    temp &= 0xCF;
    temp |= ( value << 4 );
    tc_hal_write( &temp_cmd, &temp, 1 );
}

TC_RETRY_t tc_get_config_retry( void )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = ACCR0;

    tc_hal_read( &temp_cmd, &temp, 1 );
    temp = ( temp >> 4 ) & 0x03;

    return temp;
}

void tc_set_afes( TC_AFES_t value )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = ACCR0;

    tc_hal_read( &temp_cmd, &temp, 1 );
    temp &= 0x3F;
    temp |= ( value << 6 );
    tc_hal_write( &temp_cmd, &temp, 1 );
}

TC_AFES_t tc_get_afes( void )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = ACCR0;

    tc_hal_read( &temp_cmd, &temp, 1 );
    temp = ( temp >> 6 ) & 0x03;

    return temp;
}

void tc_set_cts( TC_CTS_t value )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = ACCR1;

    tc_hal_read( &temp_cmd, &temp, 1 );
    temp &= 0x7F;
    temp |= ( value << 7 );
    tc_hal_write( &temp_cmd, &temp, 1 );
}

TC_CTS_t tc_get_cts( void )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = ACCR1;

    tc_hal_read( &temp_cmd, &temp, 1 );
    temp = ( temp >> 7 ) & 0x01;

    return temp;
}

void tc_set_acfie( TC_ACFIE_t value )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = ACCR1;

    tc_hal_read( &temp_cmd, &temp, 1 );
    temp &= 0xFE;
    temp |= value;
    tc_hal_write( &temp_cmd, &temp, 1 );
}

TC_ACFIE_t tc_get_acife( void )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = ACCR1;

    tc_hal_read( &temp_cmd, &temp, 1 );
    temp &= 0x01;

    return temp;
}

void tc_set_arcfie( TC_ARCFIE_t value )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = ACCR1;

    tc_hal_read( &temp_cmd, &temp, 1 );
    temp &= 0xFD;
    temp |= ( value << 1 );
    tc_hal_write( &temp_cmd, &temp, 1 );
}

TC_ARCFIE_t tc_get_arcfie( void )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = ACCR1;

    tc_hal_read( &temp_cmd, &temp, 1 );
    temp = ( temp >> 1 ) & 0x01;

    return temp;
}

void tc_set_orie( TC_ORIE_t value )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = ACCR1;

    tc_hal_read( &temp_cmd, &temp, 1 );
    temp &= 0xFB;
    temp |= ( value << 2 );
    tc_hal_write( &temp_cmd, &temp, 1 );
}

TC_ORIE_t tc_get_orie( void )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = ACCR1;

    tc_hal_read( &temp_cmd, &temp, 1 );
    temp = ( temp >> 2 ) & 0x01;

    return temp;
}

TC_ORS_t tc_get_ors( TC_ELE_t electrode )
{
    uint8_t temp        = 0;
    uint8_t temp_cmd    = 0;

    if ( electrode > 12 )
        return ORS_NO;

    if ( electrode < 8 )
        temp_cmd = OOR_STATUS_1;
    else
        temp_cmd = OOR_STATUS_2;

    tc_hal_read( &temp_cmd, &temp, 1 );

    return ( ( temp >> ( electrode % 8 ) ) & 0x01 ) ? ORS_DETECTED : ORS_NO;
}

void tc_soft_reset( void )
{
    uint8_t temp        = 0x63;
    uint8_t temp_cmd    = SRST;

    tc_hal_write( &temp_cmd, &temp, 1 );
}

/*************** END OF FUNCTIONS *********************************************/