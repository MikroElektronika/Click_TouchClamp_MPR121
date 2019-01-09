![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# TouchClamp Click

- **CIC Prefix**  : TOUCHCLAMP
- **Author**      : Nenad Filipovic
- **Verison**     : 1.0.1
- **Date**        : Oct 2018.

---

### Software Support

We provide a library for the TouchClamp Click on our [LibStock](https://libstock.mikroe.com/projects/view/1789/touchclamp-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library covers all the necessary functions to control TouchClamp Click board.
TouchClamp click communicates with the target board via I2C. 
This library contains drivers for write and read data from register address,
set ( get ) touch or release threshold, set default configuration, get touch data and others. 

Key functions :

- ``` void touchclamp_writeByte( uint8_t address, uint8_t writeData ) ``` - Generic write byte of data function
- ``` uint8_t touchclamp_readByte( uint8_t address ) ``` - Generic read byte of data function
- ``` uint16_t touchclamp_getTouchData() ``` - Get touch data function

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes I2C, GPIO and LOG structures, set INT pin as input.
- Application Initialization - Initialization driver enable's - I2C,
     soft reset register, set default configuration and start write log.
- Application Task - (code snippet) This is a example which demonstrates the use of TouchClamp Click board.
     TouchClamp Click communicates with MPR121 chip via I2C
     by write and read from register and get touch data.
     Results are being sent to the Usart Terminal where you can track their changes.
     All data logs on usb uart when the sensor is triggered.


```.c

void applicationTask()
{
    touchData = touchclamp_getTouchData();
    
    if ( touchDataOld != touchData )
    {
        if ( touchData == 0x10 )
            mikrobus_logWrite( "  - - - - - - - H ", _LOG_LINE );
            
        if ( touchData == 0x01 )
            mikrobus_logWrite( "  - - - - - - G - ", _LOG_LINE );
            
        if ( touchData == 0x02 )
            mikrobus_logWrite( "  - - - - - F - - ", _LOG_LINE );
            
        if ( touchData == 0x04 )
            mikrobus_logWrite( "  - - - - E - - - ", _LOG_LINE );
            
        if ( touchData == 0x08 )
            mikrobus_logWrite( "  - - - D - - - - ", _LOG_LINE );
            
        if ( touchData == 0x20 )
            mikrobus_logWrite( "  - - C - - - - - ", _LOG_LINE );
            
        if ( touchData == 0x40 )
            mikrobus_logWrite( "  - B - - - - - - ", _LOG_LINE );
            
        if ( touchData == 0x80 )
            mikrobus_logWrite( "  A - - - - - - - ", _LOG_LINE );
      
        touchDataOld = touchData;
    }
}

```



The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/1789/touchclamp-click) page.

Other mikroE Libraries used in the example:

- I2C
- UART


**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
