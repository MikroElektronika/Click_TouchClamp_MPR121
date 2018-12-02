/*
    __touchclamp_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __touchclamp_driver.h
@brief    TouchClamp Driver
@mainpage TouchClamp Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   TOUCHCLAMP
@brief      TouchClamp Click Driver
@{

| Global Library Prefix | **TOUCHCLAMP** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Oct 2018.**      |
| Developer             | **Nenad Filipovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _TOUCHCLAMP_H_
#define _TOUCHCLAMP_H_

/** 
 * @macro T_TOUCHCLAMP_P
 * @brief Driver Abstract type 
 */
#define T_TOUCHCLAMP_P    const uint8_t*

/** @defgroup TOUCHCLAMP_COMPILE Compilation Config */              /** @{ */

//  #define   __TOUCHCLAMP_DRV_SPI__                            /**<     @macro __TOUCHCLAMP_DRV_SPI__  @brief SPI driver selector */
   #define   __TOUCHCLAMP_DRV_I2C__                            /**<     @macro __TOUCHCLAMP_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __TOUCHCLAMP_DRV_UART__                           /**<     @macro __TOUCHCLAMP_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup TOUCHCLAMP_VAR Variables */                           /** @{ */

extern const uint8_t _TOUCHCLAMP_I2C_ADDRESS;
extern const uint8_t _TOUCHCLAMP_TS1;
extern const uint8_t _TOUCHCLAMP_TS2;
extern const uint8_t _TOUCHCLAMP_OORS1;
extern const uint8_t _TOUCHCLAMP_OORS2;
extern const uint8_t _TOUCHCLAMP_E0FDL;
extern const uint8_t _TOUCHCLAMP_E0FDH;
extern const uint8_t _TOUCHCLAMP_E1FDL;
extern const uint8_t _TOUCHCLAMP_E1FDH;
extern const uint8_t _TOUCHCLAMP_E2FDL;
extern const uint8_t _TOUCHCLAMP_E2FDH;
extern const uint8_t _TOUCHCLAMP_E3FDL;
extern const uint8_t _TOUCHCLAMP_E3FDH;
extern const uint8_t _TOUCHCLAMP_E4FDL;
extern const uint8_t _TOUCHCLAMP_E4FDH;
extern const uint8_t _TOUCHCLAMP_E5FDL;
extern const uint8_t _TOUCHCLAMP_E5FDH;
extern const uint8_t _TOUCHCLAMP_E6FDL;
extern const uint8_t _TOUCHCLAMP_E6FDH;
extern const uint8_t _TOUCHCLAMP_E7FDL;
extern const uint8_t _TOUCHCLAMP_E7FDH;
extern const uint8_t _TOUCHCLAMP_E8FDL;
extern const uint8_t _TOUCHCLAMP_E8FDH;
extern const uint8_t _TOUCHCLAMP_E9FDL;
extern const uint8_t _TOUCHCLAMP_E9FDH;
extern const uint8_t _TOUCHCLAMP_E10FDL;
extern const uint8_t _TOUCHCLAMP_E10FDH;
extern const uint8_t _TOUCHCLAMP_E11FDL;
extern const uint8_t _TOUCHCLAMP_E11FDH;
extern const uint8_t _TOUCHCLAMP_E12FDL;
extern const uint8_t _TOUCHCLAMP_E12FDH;
extern const uint8_t _TOUCHCLAMP_E0BV;
extern const uint8_t _TOUCHCLAMP_E1BV;
extern const uint8_t _TOUCHCLAMP_E2BV;
extern const uint8_t _TOUCHCLAMP_E3BV;
extern const uint8_t _TOUCHCLAMP_E4BV;
extern const uint8_t _TOUCHCLAMP_E5BV;
extern const uint8_t _TOUCHCLAMP_E6BV;
extern const uint8_t _TOUCHCLAMP_E7BV;
extern const uint8_t _TOUCHCLAMP_E8BV;
extern const uint8_t _TOUCHCLAMP_E9BV;
extern const uint8_t _TOUCHCLAMP_E10BV;
extern const uint8_t _TOUCHCLAMP_E11BV;
extern const uint8_t _TOUCHCLAMP_E12BV;
extern const uint8_t _TOUCHCLAMP_MHDR;
extern const uint8_t _TOUCHCLAMP_NHDR;
extern const uint8_t _TOUCHCLAMP_NCLR;
extern const uint8_t _TOUCHCLAMP_FDLR;
extern const uint8_t _TOUCHCLAMP_MHDF;
extern const uint8_t _TOUCHCLAMP_NHDF;
extern const uint8_t _TOUCHCLAMP_NCLF;
extern const uint8_t _TOUCHCLAMP_FDLF;
extern const uint8_t _TOUCHCLAMP_NHDT;
extern const uint8_t _TOUCHCLAMP_NCLT;
extern const uint8_t _TOUCHCLAMP_FDLT;
extern const uint8_t _TOUCHCLAMP_MHDPROXR;
extern const uint8_t _TOUCHCLAMP_NHDPROXR;
extern const uint8_t _TOUCHCLAMP_NCLPROXR;
extern const uint8_t _TOUCHCLAMP_FDLPROXR;
extern const uint8_t _TOUCHCLAMP_MHDPROXF;
extern const uint8_t _TOUCHCLAMP_NHDPROXF;
extern const uint8_t _TOUCHCLAMP_NCLPROXF;
extern const uint8_t _TOUCHCLAMP_FDLPROXF;
extern const uint8_t _TOUCHCLAMP_NHDPROXT;
extern const uint8_t _TOUCHCLAMP_NCLPROXT;
extern const uint8_t _TOUCHCLAMP_FDLPROXT;
extern const uint8_t _TOUCHCLAMP_E0TTH;
extern const uint8_t _TOUCHCLAMP_E0RTH;
extern const uint8_t _TOUCHCLAMP_E1TTH;
extern const uint8_t _TOUCHCLAMP_E1RTH;
extern const uint8_t _TOUCHCLAMP_E2TTH;
extern const uint8_t _TOUCHCLAMP_E2RTH;
extern const uint8_t _TOUCHCLAMP_E3TTH;
extern const uint8_t _TOUCHCLAMP_E3RTH;
extern const uint8_t _TOUCHCLAMP_E4TTH;
extern const uint8_t _TOUCHCLAMP_E4RTH;
extern const uint8_t _TOUCHCLAMP_E5TTH;
extern const uint8_t _TOUCHCLAMP_E5RTH;
extern const uint8_t _TOUCHCLAMP_E6TTH;
extern const uint8_t _TOUCHCLAMP_E6RTH;
extern const uint8_t _TOUCHCLAMP_E7TTH;
extern const uint8_t _TOUCHCLAMP_E7RTH;
extern const uint8_t _TOUCHCLAMP_E8TTH;
extern const uint8_t _TOUCHCLAMP_E8RTH;
extern const uint8_t _TOUCHCLAMP_E9TTH;
extern const uint8_t _TOUCHCLAMP_E9RTH;
extern const uint8_t _TOUCHCLAMP_E10TTH;
extern const uint8_t _TOUCHCLAMP_E10RTH;
extern const uint8_t _TOUCHCLAMP_E11TTH;
extern const uint8_t _TOUCHCLAMP_E11RTH;
extern const uint8_t _TOUCHCLAMP_E12TTH;
extern const uint8_t _TOUCHCLAMP_E12RTH;
extern const uint8_t _TOUCHCLAMP_DTR;
extern const uint8_t _TOUCHCLAMP_AFE1;
extern const uint8_t _TOUCHCLAMP_AFE2;
extern const uint8_t _TOUCHCLAMP_ECR;
extern const uint8_t _TOUCHCLAMP_CDC0;
extern const uint8_t _TOUCHCLAMP_CDC1;
extern const uint8_t _TOUCHCLAMP_CDC2;
extern const uint8_t _TOUCHCLAMP_CDC3;
extern const uint8_t _TOUCHCLAMP_CDC4;
extern const uint8_t _TOUCHCLAMP_CDC5;
extern const uint8_t _TOUCHCLAMP_CDC6;
extern const uint8_t _TOUCHCLAMP_CDC7;
extern const uint8_t _TOUCHCLAMP_CDC8;
extern const uint8_t _TOUCHCLAMP_CDC9;
extern const uint8_t _TOUCHCLAMP_CDC10;
extern const uint8_t _TOUCHCLAMP_CDC11;
extern const uint8_t _TOUCHCLAMP_CDC12;
extern const uint8_t _TOUCHCLAMP_CDT01;
extern const uint8_t _TOUCHCLAMP_CDT23;
extern const uint8_t _TOUCHCLAMP_CDT45;
extern const uint8_t _TOUCHCLAMP_CDT67;
extern const uint8_t _TOUCHCLAMP_CDT89;
extern const uint8_t _TOUCHCLAMP_CDT1011;
extern const uint8_t _TOUCHCLAMP_CDT11;
extern const uint8_t _TOUCHCLAMP_CTL0;
extern const uint8_t _TOUCHCLAMP_CTL1;
extern const uint8_t _TOUCHCLAMP_DAT;
extern const uint8_t _TOUCHCLAMP_DIR;
extern const uint8_t _TOUCHCLAMP_EN;
extern const uint8_t _TOUCHCLAMP_SET;
extern const uint8_t _TOUCHCLAMP_CLR;
extern const uint8_t _TOUCHCLAMP_TOG;
extern const uint8_t _TOUCHCLAMP_ACCR0;
extern const uint8_t _TOUCHCLAMP_ACCR1;
extern const uint8_t _TOUCHCLAMP_USL;
extern const uint8_t _TOUCHCLAMP_LSL;
extern const uint8_t _TOUCHCLAMP_TL;
extern const uint8_t _TOUCHCLAMP_SRST;
extern const uint8_t _TOUCHCLAMP_PWM0;
extern const uint8_t _TOUCHCLAMP_PWM1;
extern const uint8_t _TOUCHCLAMP_PWM2;
extern const uint8_t _TOUCHCLAMP_PWM3;

                                                                       /** @} */
/** @defgroup TOUCHCLAMP_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup TOUCHCLAMP_INIT Driver Initialization */              /** @{ */

#ifdef   __TOUCHCLAMP_DRV_SPI__
void touchclamp_spiDriverInit(T_TOUCHCLAMP_P gpioObj, T_TOUCHCLAMP_P spiObj);
#endif
#ifdef   __TOUCHCLAMP_DRV_I2C__
void touchclamp_i2cDriverInit(T_TOUCHCLAMP_P gpioObj, T_TOUCHCLAMP_P i2cObj, uint8_t slave);
#endif
#ifdef   __TOUCHCLAMP_DRV_UART__
void touchclamp_uartDriverInit(T_TOUCHCLAMP_P gpioObj, T_TOUCHCLAMP_P uartObj);
#endif


/** @defgroup TOUCHCLAMP_FUNC Driver Functions */                   /** @{ */


/**
 * @brief Generic write byte data to given register address function
 *
 * @param[in] address                  8-bit register address
 *
 * @param[in] writeData                8-bit data to write
 *
 * Function write byte data to given register address of MPR121 chip.
 */
void touchclamp_writeByte( uint8_t address, uint8_t writeData );

/**
 * @brief Generic read byte data from given register address function
 *
 * @param[in] address                  8-bit register address
 *
 * @return readData                    8-bit data from given register address
 *
 * Function read byte data from given register address of MPR121 chip.
 */
uint8_t touchclamp_readByte( uint8_t address );

/**
 * @brief Setting touch threshold for a specified electrode function
 *
 * @param[in] electrode                8-bit release threshold value
 *
 * Function set touch threshold value
 * for a specified electrode of MPR121 chip.
 */
void touchclamp_setTouchThreshold( uint8_t electrode );

/**
 * @brief Get the current touch threshold for a specified electrode function
 *
 * @param[in] electrode                8-bit release threshold value
 *
 * Function get touch threshold value
 * for a specified electrode of MPR121 chip.
 */
uint8_t touchclamp_getTouchThreshold( uint8_t electrode );

/**
 * @brief Setting release threshold for a specified electrode function
 *
 * @param[in] electrode                8-bit release threshold value
 *
 * Function set realease threshold value
 * for a specified electrode of MPR121 chip.
 */
void touchclamp_setReleaseThreshold( uint8_t electrode );

/**
 * @brief Get release threshold for a specified electrode function
 *
 * @param[in] electrode                8-bit release threshold value
 *
 * Function get realease threshold value
 * for a specified electrode of MPR121 chip.
 */
uint8_t touchclamp_getReleaseThreshold( uint8_t electrode );

/**
 * @brief Set default configuration function
 *
 * @param[in] value                    8-bit release threshold value
 *
 * Function set default configuration to MPR121 chip.
 */
void touchclamp_defaultConfiguration();

/**
 * @brief Get touch data function
 *
 * @return touchData                   16-bit touch data
 *
 * Function read 16-bit touch data from two register address,
 * ELE0 - ELE7 Touch Status and
 * ELE8 - ELE11, ELEPROX Touch Status of MPR121 chip.
 */
uint16_t touchclamp_getTouchData();

/**
 * @brief Sets the sample period of the MPR121 function
 *
 * @param[in] samplePeriod             8-bit sample period value
 *
 * Sets the sample period of the MPR121 - the time between capacitive
 * readings. Higher values consume less power, but are less responsive.
 */
void touchclamp_setSamplePeriod( uint8_t samplePeriod );

/**
 * @brief Toggles electrode set as GPIO output function
 *
 * @param[in] electrode               8-bit electrode position value
 *
 * Function set toggles electrode as GPIO output of MPR121 chip.
 */
void touchclamp_digitalToggle( uint8_t electrode );

/**
 * @brief Get state of interrupt pin function
 *
 * Function get state of interrupt ( INT ) pin.
 */
uint8_t touchclamp_getInterrupt();

/**
 * @brief Soft reset function
 *
 * Function reset register to default value
 * by set 0x63 to Soft Reset Register of MPR121 chip.
 */
void touchclamp_softReset();

/**
 * @brief Stop function
 *
 * Function stop take the MPR121 chip in and out of stop mode
 * which reduces current consumption to 3uA.
 */
void touchclamp_stop();




                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_TouchClamp_STM.c
    @example Click_TouchClamp_TIVA.c
    @example Click_TouchClamp_CEC.c
    @example Click_TouchClamp_KINETIS.c
    @example Click_TouchClamp_MSP.c
    @example Click_TouchClamp_PIC.c
    @example Click_TouchClamp_PIC32.c
    @example Click_TouchClamp_DSPIC.c
    @example Click_TouchClamp_AVR.c
    @example Click_TouchClamp_FT90x.c
    @example Click_TouchClamp_STM.mbas
    @example Click_TouchClamp_TIVA.mbas
    @example Click_TouchClamp_CEC.mbas
    @example Click_TouchClamp_KINETIS.mbas
    @example Click_TouchClamp_MSP.mbas
    @example Click_TouchClamp_PIC.mbas
    @example Click_TouchClamp_PIC32.mbas
    @example Click_TouchClamp_DSPIC.mbas
    @example Click_TouchClamp_AVR.mbas
    @example Click_TouchClamp_FT90x.mbas
    @example Click_TouchClamp_STM.mpas
    @example Click_TouchClamp_TIVA.mpas
    @example Click_TouchClamp_CEC.mpas
    @example Click_TouchClamp_KINETIS.mpas
    @example Click_TouchClamp_MSP.mpas
    @example Click_TouchClamp_PIC.mpas
    @example Click_TouchClamp_PIC32.mpas
    @example Click_TouchClamp_DSPIC.mpas
    @example Click_TouchClamp_AVR.mpas
    @example Click_TouchClamp_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __touchclamp_driver.h

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