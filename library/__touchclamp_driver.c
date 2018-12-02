/*
    __touchclamp_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__touchclamp_driver.h"
#include "__touchclamp_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __TOUCHCLAMP_DRV_I2C__
static uint8_t _slaveAddress;
#endif

const uint8_t _TOUCHCLAMP_I2C_ADDRESS = 0x5A;

/* MPR121 Register Defines */
// touch and OOR statuses
const uint8_t _TOUCHCLAMP_TS1       = 0x00;
const uint8_t _TOUCHCLAMP_TS2       = 0x01;
const uint8_t _TOUCHCLAMP_OORS1     = 0x02;
const uint8_t _TOUCHCLAMP_OORS2     = 0x03;
// filtered data
const uint8_t _TOUCHCLAMP_E0FDL     = 0x04;
const uint8_t _TOUCHCLAMP_E0FDH     = 0x05;
const uint8_t _TOUCHCLAMP_E1FDL     = 0x06;
const uint8_t _TOUCHCLAMP_E1FDH     = 0x07;
const uint8_t _TOUCHCLAMP_E2FDL     = 0x08;
const uint8_t _TOUCHCLAMP_E2FDH     = 0x09;
const uint8_t _TOUCHCLAMP_E3FDL     = 0x0A;
const uint8_t _TOUCHCLAMP_E3FDH     = 0x0B;
const uint8_t _TOUCHCLAMP_E4FDL     = 0x0C;
const uint8_t _TOUCHCLAMP_E4FDH     = 0x0D;
const uint8_t _TOUCHCLAMP_E5FDL     = 0x0E;
const uint8_t _TOUCHCLAMP_E5FDH     = 0x0F;
const uint8_t _TOUCHCLAMP_E6FDL     = 0x10;
const uint8_t _TOUCHCLAMP_E6FDH     = 0x11;
const uint8_t _TOUCHCLAMP_E7FDL     = 0x12;
const uint8_t _TOUCHCLAMP_E7FDH     = 0x13;
const uint8_t _TOUCHCLAMP_E8FDL     = 0x14;
const uint8_t _TOUCHCLAMP_E8FDH     = 0x15;
const uint8_t _TOUCHCLAMP_E9FDL     = 0x16;
const uint8_t _TOUCHCLAMP_E9FDH     = 0x17;
const uint8_t _TOUCHCLAMP_E10FDL    = 0x18;
const uint8_t _TOUCHCLAMP_E10FDH    = 0x19;
const uint8_t _TOUCHCLAMP_E11FDL    = 0x1A;
const uint8_t _TOUCHCLAMP_E11FDH    = 0x1B;
const uint8_t _TOUCHCLAMP_E12FDL    = 0x1C;
const uint8_t _TOUCHCLAMP_E12FDH    = 0x1D;
// baseline values
const uint8_t _TOUCHCLAMP_E0BV      = 0x1E;
const uint8_t _TOUCHCLAMP_E1BV      = 0x1F;
const uint8_t _TOUCHCLAMP_E2BV      = 0x20;
const uint8_t _TOUCHCLAMP_E3BV      = 0x21;
const uint8_t _TOUCHCLAMP_E4BV      = 0x22;
const uint8_t _TOUCHCLAMP_E5BV      = 0x23;
const uint8_t _TOUCHCLAMP_E6BV      = 0x24;
const uint8_t _TOUCHCLAMP_E7BV      = 0x25;
const uint8_t _TOUCHCLAMP_E8BV      = 0x26;
const uint8_t _TOUCHCLAMP_E9BV      = 0x27;
const uint8_t _TOUCHCLAMP_E10BV     = 0x28;
const uint8_t _TOUCHCLAMP_E11BV     = 0x29;
const uint8_t _TOUCHCLAMP_E12BV     = 0x2A;

/* General electrode touch sense baseline filters */
// rising filter
const uint8_t _TOUCHCLAMP_MHDR      = 0x2B;
const uint8_t _TOUCHCLAMP_NHDR      = 0x2C;
const uint8_t _TOUCHCLAMP_NCLR      = 0x2D;
const uint8_t _TOUCHCLAMP_FDLR      = 0x2E;
// falling filter
const uint8_t _TOUCHCLAMP_MHDF      = 0x2F;
const uint8_t _TOUCHCLAMP_NHDF      = 0x30;
const uint8_t _TOUCHCLAMP_NCLF      = 0x31;
const uint8_t _TOUCHCLAMP_FDLF      = 0x32;
// touched filter
const uint8_t _TOUCHCLAMP_NHDT      = 0x33;
const uint8_t _TOUCHCLAMP_NCLT      = 0x34;
const uint8_t _TOUCHCLAMP_FDLT      = 0x35;

/* Proximity electrode touch sense baseline filters */
// rising filter
const uint8_t _TOUCHCLAMP_MHDPROXR  = 0x36;
const uint8_t _TOUCHCLAMP_NHDPROXR  = 0x37;
const uint8_t _TOUCHCLAMP_NCLPROXR  = 0x38;
const uint8_t _TOUCHCLAMP_FDLPROXR  = 0x39;
// falling filter
const uint8_t _TOUCHCLAMP_MHDPROXF  = 0x3A;
const uint8_t _TOUCHCLAMP_NHDPROXF  = 0x3B;
const uint8_t _TOUCHCLAMP_NCLPROXF  = 0x3C;
const uint8_t _TOUCHCLAMP_FDLPROXF  = 0x3D;
// touched filter
const uint8_t _TOUCHCLAMP_NHDPROXT  = 0x3E;
const uint8_t _TOUCHCLAMP_NCLPROXT  = 0x3F;
const uint8_t _TOUCHCLAMP_FDLPROXT  = 0x40;
// electrode touch and release thresholds
const uint8_t _TOUCHCLAMP_E0TTH     = 0x41;
const uint8_t _TOUCHCLAMP_E0RTH     = 0x42;
const uint8_t _TOUCHCLAMP_E1TTH     = 0x43;
const uint8_t _TOUCHCLAMP_E1RTH     = 0x44;
const uint8_t _TOUCHCLAMP_E2TTH     = 0x45;
const uint8_t _TOUCHCLAMP_E2RTH     = 0x46;
const uint8_t _TOUCHCLAMP_E3TTH     = 0x47;
const uint8_t _TOUCHCLAMP_E3RTH     = 0x48;
const uint8_t _TOUCHCLAMP_E4TTH     = 0x49;
const uint8_t _TOUCHCLAMP_E4RTH     = 0x4A;
const uint8_t _TOUCHCLAMP_E5TTH     = 0x4B;
const uint8_t _TOUCHCLAMP_E5RTH     = 0x4C;
const uint8_t _TOUCHCLAMP_E6TTH     = 0x4D;
const uint8_t _TOUCHCLAMP_E6RTH     = 0x4E;
const uint8_t _TOUCHCLAMP_E7TTH     = 0x4F;
const uint8_t _TOUCHCLAMP_E7RTH     = 0x50;
const uint8_t _TOUCHCLAMP_E8TTH     = 0x51;
const uint8_t _TOUCHCLAMP_E8RTH     = 0x52;
const uint8_t _TOUCHCLAMP_E9TTH     = 0x53;
const uint8_t _TOUCHCLAMP_E9RTH     = 0x54;
const uint8_t _TOUCHCLAMP_E10TTH    = 0x55;
const uint8_t _TOUCHCLAMP_E10RTH    = 0x56;
const uint8_t _TOUCHCLAMP_E11TTH    = 0x57;
const uint8_t _TOUCHCLAMP_E11RTH    = 0x58;
const uint8_t _TOUCHCLAMP_E12TTH    = 0x59;
const uint8_t _TOUCHCLAMP_E12RTH    = 0x5A;
// debounce settings
const uint8_t _TOUCHCLAMP_DTR       = 0x5B;
// configuration registers
const uint8_t _TOUCHCLAMP_AFE1      = 0x5C;
const uint8_t _TOUCHCLAMP_AFE2      = 0x5D;
const uint8_t _TOUCHCLAMP_ECR       = 0x5E;
// electrode currents
const uint8_t _TOUCHCLAMP_CDC0      = 0x5F;
const uint8_t _TOUCHCLAMP_CDC1      = 0x60;
const uint8_t _TOUCHCLAMP_CDC2      = 0x61;
const uint8_t _TOUCHCLAMP_CDC3      = 0x62;
const uint8_t _TOUCHCLAMP_CDC4      = 0x63;
const uint8_t _TOUCHCLAMP_CDC5      = 0x64;
const uint8_t _TOUCHCLAMP_CDC6      = 0x65;
const uint8_t _TOUCHCLAMP_CDC7      = 0x66;
const uint8_t _TOUCHCLAMP_CDC8      = 0x67;
const uint8_t _TOUCHCLAMP_CDC9      = 0x68;
const uint8_t _TOUCHCLAMP_CDC10     = 0x69;
const uint8_t _TOUCHCLAMP_CDC11     = 0x6A;
const uint8_t _TOUCHCLAMP_CDC12     = 0x6B;
// electrode charge times
const uint8_t _TOUCHCLAMP_CDT01     = 0x6C;
const uint8_t _TOUCHCLAMP_CDT23     = 0x6D;
const uint8_t _TOUCHCLAMP_CDT45     = 0x6E;
const uint8_t _TOUCHCLAMP_CDT67     = 0x6F;
const uint8_t _TOUCHCLAMP_CDT89     = 0x70;
const uint8_t _TOUCHCLAMP_CDT1011   = 0x71;
const uint8_t _TOUCHCLAMP_CDT11     = 0x72;
// GPIO
const uint8_t _TOUCHCLAMP_CTL0      = 0x73;
const uint8_t _TOUCHCLAMP_CTL1      = 0x74;
const uint8_t _TOUCHCLAMP_DAT       = 0x75;
const uint8_t _TOUCHCLAMP_DIR       = 0x76;
const uint8_t _TOUCHCLAMP_EN        = 0x77;
const uint8_t _TOUCHCLAMP_SET       = 0x78;
const uint8_t _TOUCHCLAMP_CLR       = 0x79;
const uint8_t _TOUCHCLAMP_TOG       = 0x7A;
// auto-config
const uint8_t _TOUCHCLAMP_ACCR0     = 0x7B;
const uint8_t _TOUCHCLAMP_ACCR1     = 0x7C;
const uint8_t _TOUCHCLAMP_USL       = 0x7D;
const uint8_t _TOUCHCLAMP_LSL       = 0x7E;
const uint8_t _TOUCHCLAMP_TL        = 0x7F;
// soft reset
const uint8_t _TOUCHCLAMP_SRST      = 0x80;
// PWM
const uint8_t _TOUCHCLAMP_PWM0      = 0x81;
const uint8_t _TOUCHCLAMP_PWM1      = 0x82;
const uint8_t _TOUCHCLAMP_PWM2      = 0x83;
const uint8_t _TOUCHCLAMP_PWM3      = 0x84;


/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __TOUCHCLAMP_DRV_SPI__

void touchclamp_spiDriverInit(T_TOUCHCLAMP_P gpioObj, T_TOUCHCLAMP_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __TOUCHCLAMP_DRV_I2C__

void touchclamp_i2cDriverInit(T_TOUCHCLAMP_P gpioObj, T_TOUCHCLAMP_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __TOUCHCLAMP_DRV_UART__

void touchclamp_uartDriverInit(T_TOUCHCLAMP_P gpioObj, T_TOUCHCLAMP_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif



/* ----------------------------------------------------------- IMPLEMENTATION */



/* Generic write byte data to given register address function */
void touchclamp_writeByte( uint8_t address, uint8_t writeData )
{
    uint8_t bufferWrite[ 2 ];

    bufferWrite[ 0 ] = address;
    bufferWrite[ 1 ] = writeData;

    hal_i2cStart();
    hal_i2cWrite( _slaveAddress, bufferWrite, 2, END_MODE_STOP );
}

/* Generic read byte data from given register address function */
uint8_t touchclamp_readByte( uint8_t address )
{
    uint8_t bufferRead[ 1 ];
    uint8_t bufferWrite[ 1 ];

    bufferWrite[ 0 ] = address;

    hal_i2cStart();
    hal_i2cWrite( _slaveAddress, bufferWrite, 1, END_MODE_RESTART );
    hal_i2cRead( _slaveAddress, bufferRead, 1, END_MODE_STOP );

    return bufferRead[ 0 ];
}

/* Setting touch threshold for a specified electrode function */
void touchclamp_setTouchThreshold( uint8_t value )
{
    uint8_t counter;
    uint8_t tempData[ 2 ];
    uint8_t electrode = 0;

    tempData[ 1 ] = value;

    for( counter = 0; counter < 13; counter++ )
    {
        tempData[0] = _TOUCHCLAMP_E0TTH + electrode;
        hal_i2cStart();
        hal_i2cWrite( _slaveAddress, tempData, 2, END_MODE_STOP);
        electrode += 2;
    }
}

/* Get the current touch threshold for a specified electrode function */
uint8_t touchclamp_getTouchThreshold( uint8_t electrode )
{
    uint8_t result;

    electrode %= 12;

    result = touchclamp_readByte( _TOUCHCLAMP_E0TTH + ( electrode << 1 ) );

    return result;
}

/* Setting release threshold for a specified electrode function */
void touchclamp_setReleaseThreshold( uint8_t value )
{
    uint8_t counter;
    uint8_t tempData[ 2 ];
    uint8_t electrode = 0;

    tempData[ 1 ] = value;

    for( counter = 0; counter < 13; counter++ )
    {
        tempData[0] = _TOUCHCLAMP_E0RTH + electrode;
        hal_i2cStart();
        hal_i2cWrite( _slaveAddress, tempData, 2, END_MODE_STOP);
        electrode += 2;
    }
}

/* Get the current release threshold for a specified electrode function */
uint8_t touchclamp_getReleaseThreshold( uint8_t electrode )
{
    uint8_t result;
    
    electrode %= 12;
  
    result = touchclamp_readByte( _TOUCHCLAMP_E0RTH + ( electrode << 1 ) );
  
    return result;
}

/* Set default configuration function */
void touchclamp_defaultConfiguration()
{
    touchclamp_writeByte( _TOUCHCLAMP_ECR,  0x00 );
    touchclamp_writeByte( _TOUCHCLAMP_MHDR, 0x01 );
    touchclamp_writeByte( _TOUCHCLAMP_NHDR, 0x01 );
    touchclamp_writeByte( _TOUCHCLAMP_NCLR, 0x10 );
    touchclamp_writeByte( _TOUCHCLAMP_FDLR, 0x20 );
    touchclamp_writeByte( _TOUCHCLAMP_MHDF, 0x01 );
    touchclamp_writeByte( _TOUCHCLAMP_NHDF, 0x01 );
    touchclamp_writeByte( _TOUCHCLAMP_NCLF, 0x10 );
    touchclamp_writeByte( _TOUCHCLAMP_FDLF, 0x20 );
    touchclamp_writeByte( _TOUCHCLAMP_NHDT, 0x01 );
    touchclamp_writeByte( _TOUCHCLAMP_NCLT, 0x10 );
    touchclamp_writeByte( _TOUCHCLAMP_FDLT, 0xFF );
    touchclamp_writeByte( _TOUCHCLAMP_MHDPROXR, 0x0F );
    touchclamp_writeByte( _TOUCHCLAMP_NHDPROXR, 0x0F );
    touchclamp_writeByte( _TOUCHCLAMP_NCLPROXR, 0x00 );
    touchclamp_writeByte( _TOUCHCLAMP_FDLPROXR, 0x00 );
    touchclamp_writeByte( _TOUCHCLAMP_MHDPROXF, 0x01 );
    touchclamp_writeByte( _TOUCHCLAMP_NHDPROXF, 0x01 );
    touchclamp_writeByte( _TOUCHCLAMP_NCLPROXF, 0xFF );
    touchclamp_writeByte( _TOUCHCLAMP_FDLPROXF, 0xFF );
    touchclamp_writeByte( _TOUCHCLAMP_NHDPROXT, 0x00 );
    touchclamp_writeByte( _TOUCHCLAMP_NCLPROXT, 0x00 );
    touchclamp_writeByte( _TOUCHCLAMP_FDLPROXT, 0x00 );
    touchclamp_writeByte( _TOUCHCLAMP_DTR, 0x11 );
    touchclamp_writeByte( _TOUCHCLAMP_AFE1, 0xFF );
    touchclamp_writeByte( _TOUCHCLAMP_AFE2, 0x30 );

    touchclamp_setTouchThreshold( 40 );
    touchclamp_setReleaseThreshold( 20 );

    touchclamp_writeByte( _TOUCHCLAMP_ECR, 0x88 );
}

/* Get touch data function */
uint16_t touchclamp_getTouchData()
{
    uint16_t touchData;
    uint8_t tempDataLow;
    uint8_t tempDataHigh;
    
    tempDataLow = touchclamp_readByte( _TOUCHCLAMP_TS1 );
    tempDataHigh = touchclamp_readByte( _TOUCHCLAMP_TS2 );

    touchData = tempDataHigh;
    touchData <<= 8;
    touchData |= tempDataLow;

    return touchData;
}

/* Sets the sample period of the MPR121 function */
void touchclamp_setSamplePeriod( uint8_t samplePeriod )
{
    uint8_t scratch;

    scratch = touchclamp_readByte( _TOUCHCLAMP_AFE2 );
    
    touchclamp_writeByte( _TOUCHCLAMP_AFE2, ( scratch & 0xF8 ) | ( samplePeriod & 0x07 ) );
}

/* Toggles electrode set as GPIO output function */
void touchclamp_digitalToggle( uint8_t electrode )
{
      if( electrode > 3 && electrode < 12 )
      {
          electrode -= 4;
          touchclamp_writeByte( _TOUCHCLAMP_TOG, 1 << electrode );
      }
}

/* Get state of interrupt pin function */
uint8_t touchclamp_getInterrupt()
{
    return hal_gpio_intGet();
}

/* Soft reset function */
void touchclamp_softReset()
{
    touchclamp_writeByte( _TOUCHCLAMP_SRST, 0x63 );
}

/* Stop function */
void touchclamp_stop()
{
    uint8_t tempBck;
    
    tempBck = touchclamp_readByte( _TOUCHCLAMP_ECR );
    
    tempBck &= 0xC0;
    
    touchclamp_writeByte( _TOUCHCLAMP_ECR, tempBck );
}



/* -------------------------------------------------------------------------- */
/*
  __touchclamp_driver.c

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */