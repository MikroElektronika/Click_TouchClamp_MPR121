/****************************************************************************
* Title                 :   Touch Clamp HAL layer
* Filename              :   touch_clamp_hal.h
* Author                :   MSV
* Origin Date           :   13/01/2016
* Notes                 :   None
*****************************************************************************/
/**************************CHANGE LIST **************************************
*
*    Date    Software Version    Initials   Description
*  13/01/16    XXXXXXXXXXX         MSV      Module Created.
*
*****************************************************************************/
/**
 * @file touch_clamp_hal.h
 *
 * @brief <h3> HAL Layer </h3>
 */
#ifndef TOUCH_CLAMP_HAL_H_
#define TOUCH_CLAMP_HAL_H_
/******************************************************************************
* Includes
*******************************************************************************/
#include <stdint.h>
/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
/*
 * ARM MCUs */
#define STM32
//#define LM
//#define TM

/*
 * AVR MCUs */
//#define ATMEGA
//#define ATXMEGA
/******************************************************************************
* Configuration Constants
*******************************************************************************/
/**
 * Register address size */
#define COMMAND_SIZE            1
/**
 * Maximum buffer size */
#define MAX_BUFF_SIZE           256
/******************************************************************************
* Macros
*******************************************************************************/
        
/******************************************************************************
* Typedefs
*******************************************************************************/

/******************************************************************************
* Variables
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

/**
 * @brief Hal layer initialization
 *
 * @param[in] touch clamp I2C hardware address
 */
void tc_hal_init( uint8_t address_id );

/**
 * @brief Write data to touch clamp through I2C
 *
 * @param[in] command - register address
 * @param[in] buffer - data buffer
 * @param[in] count - amount of data that shoud be written
 */
void tc_hal_write( uint8_t *command,
                   uint8_t *buffer,
                   uint16_t count );

/**
 * @brief Read data from touch clamp through I2C
 *
 * @param[in] command - register address
 * @param[out] buffer - data buffer
 * @param[in] count - amount of data that should be read
 */
void tc_hal_read( uint8_t *command,
                  uint8_t *buffer,
                  uint16_t count );

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* TOUCH_CLAMP_HAL_H_ */
/*** End of File **************************************************************/