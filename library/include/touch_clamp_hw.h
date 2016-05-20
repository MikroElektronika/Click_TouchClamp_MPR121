/****************************************************************************
* Title                 :   Touch Clamp HW layer
* Filename              :   touch_clamp_hw.h
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
 * @file touch_clamp_hw.h
 *
 * @brief <h3> Hardware layer </h3>
 */

/**
 * @page LIB_INFO Library Info
 * @date 13 Jan 2016
 * @author Milos Vidojevic
 * @copyright GNU Public License
 * @version .1 - Initial testing and verification
 */

/**
 * @page SCH Schematic
 * ![Schematic](../tc_sch.jpg)
 */

/**
 * @page PIN Pin Usage
 * ![Pins](../tc_pins.png)
 */

/**
 * @page TEST_CFG Test Configurations
 *
 * ### Test configuration STM : ###
 * @par
 * - <b> MCU           </b> :      STM32F107VC
 * - <b> Dev. Board    </b> :      EasyMx Pro v7
 * - <b> Oscillator    </b> :      72 Mhz internal
 * - <b> Ext. Modules  </b> :      CLICKNAME Click
 * - <b> SW            </b> :      MikroC PRO for ARM 4.7.1
 *
 * ### Test configuration PIC32 : ###
 * @par
 * - <b> MCU           </b> :      PIC32MX795F512L
 * - <b> Dev. Board    </b> :      EasyPIC Fusion v7
 * - <b> Oscillator    </b> :      80 Mhz internal
 * - <b> Ext. Modules  </b> :      CLICKNAME Click
 * - <b> SW            </b> :      MikroC PRO for PIC 3.6.0
 *
 * ### Test configuration FT90x : ###
 * @par
 * - <b> MCU           </b> :      FT900Q
 * - <b> Dev. Board    </b> :      EasyFT90x v7
 * - <b> Oscillator    </b> :      100 Mhz internal
 * - <b> Ext. Modules  </b> :      CLICKNAME Click
 * - <b> SW            </b> :      MikroC PRO for FT90x 1.2.1
 *
 * ### Test configuration PIC : ###
 * @par
 * - <b> MCU           </b> :      PIC18F87K22
 * - <b> Dev. Board    </b> :      EasyPIC Pro v7
 * - <b> Oscillator    </b> :      16 Mhz external
 * - <b> Ext. Modules  </b> :      CLICKNAME Click
 * - <b> SW            </b> :      MikroC PRO for PIC 6.6.3
 *
 * ### Test configuration dsPIC : ###
 * @par
 * - <b> MCU           </b> :      dsPIC33EJ256GP710A
 * - <b> Dev. Board    </b> :      EasyPIC Fusion v7
 * - <b> Oscillator    </b> :      8 Mhz internal
 * - <b> Ext. Modules  </b> :      CLICKNAME Click
 * - <b> SW            </b> :      MikroC PRO for dsPIC 6.2.1
 *
 * ### Test configuration AVR : ###
 * @par
 * - <b> MCU           </b> :      ATMEGA32
 * - <b> Dev. Board    </b> :      EasyAVR v7
 * - <b> Oscillator    </b> :      8 Mhz external
 * - <b> Ext. Modules  </b> :      CLICKNAME Click
 * - <b> SW            </b> :      MikroC PRO for FT90x 6.1.1
 */

/**
 * @mainpage
 * ### General Desription ###
 *
 * ![Click](../click.png)
 *
 * The MPR121 is the second generation capacitive touch sensor controller after
 * the initial release of the MPR03x series devices. The MPR121 features
 * increased internal intelligence, some of the major additions include an
 * increased electrode count, a hardware configurable I2C address, an
 * expanded filtering system with debounce, and completely independent
 * electrodes with auto-configuration built in.
 *
 * ### Features ###
 * - Low power operation
 *      + 1.71 V to 3.6 V supply operation
 *      + 29 μA supply current at 16 ms sampling interval period
 *      + 3 μA Stop mode current
 * - Complete touch detection
 *      + Auto-configuration for each sensing input
 *      + Auto-calibration for each sensing input
 *      + Touch / release threshold and debounce for touch detection
 * - I2C interface, with Interrupt output
 * - -40°C to +85°C operating temperature range
 */

#ifndef TOUCH_CLAMP_HW_H_
#define TOUCH_CLAMP_HW_H_
/******************************************************************************
* Includes
*******************************************************************************/
#include <stdbool.h>
#include <stdint.h>
#include "touch_clamp_hal.h"
/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
/**
 * ELE0 - ELE7 Touch Status */
#define T_STATUS_1              0x00
/**
 * ELE8 - ELE11, ELEPROX Touch Status */
#define T_STATUS_2              0x01
/**
 * ELE0 - ELE7 OOR Status */
#define OOR_STATUS_1            0x02
/**
 * ELE8 - ELE11, ELEPROX OOR Status */
#define OOR_STATUS_2            0x03
/**
 * Electrode Filtered Data LSB group of registers */
#define ExFDL                   0x04
/**
 * Electrode Filtered Data MSB group of registers */
#define ExFDH                   0x05
/**
 * Baseline Value group of registers */
#define ExBV                    0x1E
/**
 * MHD Rising */
#define MHDR                    0x2B
/**
 * NHD Rising */
#define NHDR                    0x2C
/**
 * NCL Rising */
#define NCLR                    0x2D
/**
 * FDL Rising */
#define FDLR                    0x2E
/**
 * MHD Falling */
#define MHDF                    0x2F
/**
 * NHD Falling */
#define NHDF                    0x30
/**
 * NCL Falling */
#define NCLF                    0x31
/**
 * FDL Falling*/
#define FDLF                    0x32
/**
 * NHD Touched */
#define NHDT                    0x33
/**
 * NCL Touched */
#define NCLT                    0x34
/**
 * FDL Touched */
#define FDLT                    0x35
/**
 * ELEPROX MHD Rising */
#define MHDPROXR                0x36
/**
 * ELEPROX NHD Rising */
#define NHDPROXR                0x37
/**
 * ELEPROX NCL Rising */
#define NCLPROXR                0x38
/**
 * ELEPROX FDL Rising */
#define FDLPROXR                0x39
/**
 * ELEPROX MHD Falling */
#define MHDPROXF                0x3A
/**
 * ELEPROX NHD Falling */
#define NHDPROXF                0x3B
/**
 * ELEPROX NCL Falling */
#define NCLPROXF                0x3C
/**
 * ELEPROX FDL Falling */
#define FDLPROXF                0x3D
/**
 * ELEPROX NHD Touched */
#define NHDPROXT                0x3E
/**
 * ELEPROX NCL Touched */
#define NCLPROXT                0x3F
/**
 * ELEPROX FDL Touched */
#define FDLPROXT                0x40
/**
 * Touch Threshold group of registers */
#define ExTTH                   0x41
/**
 * Release Threshold group of registers */
#define ExRTH                   0x42
/**
 * Debounce Touch & Release */
#define DRDT                    0x5B
/**
 * AFE Configuration 1 */
#define AFECFG1                 0x5C
/**
 * AFE Configuration 2 */
#define AFECFG2                 0x5D
/**
 * Electrode Configuration */
#define ECR                     0x5E
/**
 * Individual Electrode Current group of registers */
#define CDCx                    0x5F
/**
 * Individual Charge Time group of registers */
#define CDT_x                   0x6C
/**
 * GPIO Control Register 0 */
#define GPIOCTL0                0x73
/**
 * GPIO Control Register 1 */
#define GPIOCTL1                0x74
/**
 * GPIO Data Register */
#define GPIODAT                 0x75
/**
 * GPIO Direction Control Register */
#define GPIODIR                 0x76
/**
 * GPIO Enable Register */
#define GPIOEN                  0x77
/**
 * GPIO Data Set Register */
#define GPIOSET                 0x78
/**
 * GPIO Data Clear Register */
#define GPIOCLR                 0x79
/**
 * GPIO Data Toggle Register */
#define GPIOTOG                 0x7A
/**
 * AUTO-CONFIG Control Register 0 */
#define ACCR0                   0x7B
/**
 * AUTO-CONFIG Control Register 1 */
#define ACCR1                   0x7C
/**
 * AUTO-CONFIG USL Register */
#define ACUSL                   0x7D
/**
 * AUTO-CONFIG LSL Register */
#define ACLSL                   0x7E
/**
 * AUTO-CONFIG Target Level Register */
#define ACTL                    0x7F
/**
 * Soft Reset Register */
#define SRST                    0x80
/******************************************************************************
* Configuration Constants
*******************************************************************************/

/******************************************************************************
* Macros
*******************************************************************************/

/******************************************************************************
* Typedefs
*******************************************************************************/
/**
 * @enum TC_ELE_t
 * @brief Electrodes on touch clamp click board
 */
typedef enum {
    /**
     * G electrode */
    ELE_G   = 0,
    /**
     * F electrode */
    ELE_F   = 1,
    /**
     * E electrode */
    ELE_E   = 2,
    /**
     * D electrode */
    ELE_D   = 3,
    /**
     * H electrode */
    ELE_H   = 4,
    /**
     * C electrode */
    ELE_C   = 5,
    /**
     * B electrode */
    ELE_B   = 6,
    /**
     * A electrode */
    ELE_A   = 7

}TC_ELE_t;

/**
 * @enum TC_TS_t
 * @brief Touch Status
 */
typedef enum {
    /**
     * Channel is currently deemed as touch */
    TS_RELEASE,
    /**
     * Channel is deemed as release */
    TS_TOUCH

}TC_TS_t;

/**
 * @enum TC_ELEF_t
 * @brief Electrode function
 */
typedef enum {
    /**
     * Touch detection for electrode */
    ELEF_TOUCH,
    /**
     * Proximity detection for electrode */
    ELEF_PROXIMITY

}TC_ELEF_t;

/**
 * @enum TC_FCS_t
 * @brief Filter Control Scenario
 */
typedef enum {
    /**
     * Rising scenario */
    FCS_RISING,
    /**
     * Falling scenarion */
    FCS_FALLING,
    /**
     * Touched scenario */
    FCS_TOUCHED

}TC_FCS_t;

/**
 * @enum TC_OCFS_t
 * @brief Over Current Flag Status
 */
typedef enum {
    /**
     * Over current was detected on REXT pin.*/
    OCFS_NORMAL,
    /**
     * Normal condition*/
    OCFS_DETECTED

}TC_OCFS_t;

/**
 * @enum TC_FFI_t
 * @brief First Filter Iterations
 */
typedef enum {
    /**
     * Sets samples taken to 6 */
    FFI_06,
    /**
     * Sets samples taken to 10 */
    FFI_10,
    /**
     * Sets samples taken to 18 */
    FFI_18,
    /**
     * Sets samples taken to 34 */
    FFI_34

}TC_FFI_t;

/**
 * @enum TC_SFI_t
 * @brief Second Filter Iterations
 */
typedef enum {
    /**
     * Number of samples is 4 */
    SFI_04,
    /**
     * Number of samples is 6 */
    SFI_06,
    /**
     * Number of samples is 10 */
    SFI_10,
    /**
     * Number of samples is 18 */
    SFI_18

}TC_SFI_t;

/**
 * @enum TC_CDT_t
 * @brief Charge Discharge Time
 */
typedef enum {
    /**
     * Invalid */
    CDT_INVALID,
    /**
     * 500 nanoseconds */
    CDT_05,
    /**
     * 1 microseconds */
    CDT_1,
    /**
     * 2 microseconds */
    CDT_2,
    /**
     * 4 microseconds */
    CDT_4,
    /**
     * 8 microseconds */
    CDT_8,
    /**
     * 16 microseconds */
    CDT_16,
    /**
     * 32 microseconds */
    CDT_32

}TC_CDT_t;

/**
 * @enum TC_ESI_t
 * @brief Electrode Sample Interval
 */
typedef enum {
    /**
     * 1 milisecond */
    ESI_1,
    /**
     * 2 milisecond */
    ESI_2,
    /**
     * 4 milisecond */
    ESI_4,
    /**
     * 8 milisecond */
    ESI_8,
    /**
     * 16 milisecond */
    ESI_16,
    /**
     * 32 milisecond */
    ESI_32,
    /**
     * 64 milisecond */
    ESI_64,
    /**
     * 128 milisecond */
    ESI_128

}TC_ESI_t;

/**
 * @enum TC_CL_t
 * @brief Calibration Lock
 */
typedef enum {
    /**
     * Baseline tracking enable. The baseline values updates every {ESI x SFI}
     * period by MPR121 per baseline filter operation. The initial value is
     * unknown. */
    CL_0,
    /** Calibration lock. Baseline tracking disabled. Baseline values are
     * unchanged by MPR121. */
    CL_1,
    /** Baseline tracking and initialize enable. At the first {ESI x SFI},
     * MPR121 copy 5MSBs of the 2nd filter output to 10bit baseline value
     * (5LSBs become zero). Subsequent update is per nominal baseline filter
     * operation. */
    CL_2,
    /** Baseline tracking and initialize enable. At the first {ESI x SFI},
     * MPR121 copy the 2nd filter output to 10bit baseline value. Subsequent
     * update is per nominal baseline filter operation. */
    CL_3

}TC_CL_t;

/**
 * @enum TC_ELEPROX_t
 * @brief Proximity Detection
 */
typedef enum {
    /**
     * Proximity detection disabled */
    ELEPROX_DISABLED,
    /**
     * Proximity detection enabled on electrodes 0 ~ 1 */
    ELEPROX_01,
    /**
     * Proximity detection enabled on electrodes 0 ~ 3 */
    ELEPROX_03,
    /**
     * Proximity detection enabled on electrodes 0 ~ 11 */
    ELEPROX_11

}TC_ELEPROX_t;

/**
 * @enum TC_AC_t
 * @brief Auto Config Status
 */
typedef enum {
    /**
     * Disable auto config */
    AC_DISABLE,
    /**
     * Enable auto config */
    AC_ENABLE

}TC_AC_t;

/**
 * @enum TC_ARC_t
 * @brief Auto Reconfig Status
 */
typedef enum {
    /**
     * Disable auto reconfig */
    ARC_DISABLE,
    /**
     * Enable auto reconfig */
    ARC_ENABLE

}TC_ARC_t;

/**
 * @enum TC_BVAC_t
 * @brief Base Value Adjust Control
 */
typedef enum {
    /**
     * Baseline value is no change */
    BVAC_NOCHANGE,
    /**
     * Baseline value is cleared to zero */
    BVAC_ZERO,
    /**
     * Baseline is set to the AUTO-CONFIG baseline value with 5MSBs loaded and
     * the other lower bits cleared */
    BVAC_ACFG1,
    /**
     * Baseline is set to the AUTO-CONFIG baseline value */
    BVAC_ACFG2

}TC_BVAC_t;

/**
 * @enum TC_RETRY_t
 * @brief Retry Autoconfig or Autoreconfig After Failed
 */
typedef enum {
    /**
     * No retry */
    RETRY_NO,
    /**
     * 2 times */
    RETRY_2,
    /**
     * 4 times */
    RETRY_4,
    /**
     * 8 times */
    RETRY_8

}TC_RETRY_t;

/**
 * @enum TC_AFES_t
 * @brief AFE samples during binary search
 */
typedef enum {
    /**
     * 6 samples */
    AFES_06,
    /**
     * 10 samples */
    AFES_10,
    /**
     * 18 samples */
    AFES_18,
    /**
     * 34 samples */
    AFES_34

}TC_AFES_t;

/**
 * @enum TC_CTS_t
 * @brief Charge Time Search
 */
typedef enum {
    /**
     * Charge Time Search is executed during binary search */
    CTS_EXE,
    /**
     * Skip Charge Time Search during binary search */
    CTS_SKIP

}TC_CTS_t;

/**
 * @enum ACFIE_t
 * @brief Auto Config Interrupt Event
 */
typedef enum {
    /**
     * Autoconfig fail will not cause interrupt */
    ACFIE_DISABLE,
    /**
     * Autoconfig fail interrupt enable */
    ACFIE_ENABLE

}TC_ACFIE_t;

/**
 * @enum ARFIE_t
 * @brief Auto Reconfig Interrupt Event
 */
typedef enum {
    /**
     * Autoreconfig fail will not cause interrupt */
    ARFIE_DISABLE,
    /**
     * Autoreconfig fail interrupt enable */
    ARFIE_ENABLE

}TC_ARCFIE_t;

/**
 * @enum OORIE_t
 * @brief Out of Range Interrupt Event
 */
typedef enum {
    /**
     * Out of range will not cause interrupt */
    ORIE_DISABLE,
    /**
     * Out of range fail interrupt enable */
    ORIE_ENABLE

}TC_ORIE_t;

/**
 * @enum OOR_t
 * @brief Out of Range Status
 */
typedef enum {
    /**
     * No out of range detected */
    ORS_NO,
    /**
     * Out of range detected */
    ORS_DETECTED,

}TC_ORS_t;
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
 * @brief Touch Clamp Default Configuration
 *
 * The default configuration used for example.
 */
void tc_default_config( void );

/**
 * @brief Returns current status of electrode
 *
 * Returns the status of the requested electrode.
 *
 * @param[in] electrode
 *          ( ELE_A / ELE_B / ELE_C / ELE_D / ELE_E / ELE_F / ELE_G / ELE_H )
 *
 * @retval ( TS_TOUCH / TS_RELEASE )
 */
TC_TS_t tc_get_ts( TC_ELE_t electrode );

/**
 * @brief Returns current touch status register
 *
 * Every bit in the register represents the electrode.
 *
 * @note Order of bits is not same like order of electrodes.
 *
 * @return ( 0 ~ 255 );
 */
uint8_t tc_get_reg_ts( void );

/**
 * @brief Reads over current status
 *
 * When over current detected, the device goes to Stop Mode immediately.
 * The ExTS bits in status registers, output registers 0x04 ~ 0x2A,
 * and bit 0 ~ 5 in ECR will be also cleared on over current condition.
 *
 * @retval ( OCFS_NORMAL / OCFS_DETECTED )
 */
TC_OCFS_t tc_get_ocfs( void );

/**
 * @brief Clears over currrent flag
 *
 * After the flag is cleared device can be configured into run mode again.
 */
void tc_reset_ocfs( void );

/**
 * @brief Returns electrode data
 *
 * Electrode data is the second level filter filtered data output.
 *
 * @param[in] electrode
 *          ( ELE_A / ELE_B / ELE_C / ELE_D / ELE_E / ELE_F / ELE_G / ELE_H )
 *
 * @retval ( 0 ~ 1024 )
 */
uint16_t tc_get_ele_data( TC_ELE_t electrode );

/**
 * @brief Sets electrode baseline value
 *
 * Baseline value is the high 8 bits of the internal 10bit baseline value.
 *
 * @param[in] electrode
 *          ( ELE_A / ELE_B / ELE_C / ELE_D / ELE_E / ELE_F / ELE_G / ELE_H )
 * @param[in] value ( 0 ~ 255 )
 */
void tc_set_baseline( TC_ELE_t electrode,
                      uint8_t value );

/**
 * @brief Returns electrode baseline value
 *
 * Baseline value is the high 8 bits of the internal 10bit baseline value.
 *
 * @param[in] electrode
 *          ( ELE_A / ELE_B / ELE_C / ELE_D / ELE_E / ELE_F / ELE_G / ELE_H )
 *
 * @retval ( 0 ~ 255 )
 */
uint8_t tc_get_baseline( TC_ELE_t electrode );

/**
 * @brief Sets the maximum half delta value
 *
 * Determines the largest magnitude of variation to pass through the baseline
 * filter.
 *
 * @param[in] scenario ( FCS_RISING / FCS_RISING )
 * @param[in] function ( ELEF_TOUCH / ELEF_PROXIMITY )
 * @param[in] value ( 1 ~ 63 )
 */
void tc_set_max_hd( TC_FCS_t scenario,
                    TC_ELEF_t function,
                    uint8_t value );

/**
 * @brief Read maximum half delta value
 *
 * @param scenario ( FCS_RISING / FCS_RISING )
 * @param function ( ELEF_TOUCH / ELEF_PROXIMITY )
 * @return ( 1 ~ 63 )
 */
uint8_t tc_get_max_hd( TC_FCS_t scenario,
                       TC_ELEF_t function );

/**
 * @brief Sets the noise half delta value.
 *
 * Determines the incremental change when non-noise drift is detected.
 *
 * @param[in] scenario ( FCS_RISING / FCS_FALLING /  FCS_TOUCHED )
 * @param[in] function ( ELEF_TOUCH / ELEF_PROXIMITY )
 * @param[in] value ( 1 ~ 63 )
 */
void tc_set_noise_hd( TC_FCS_t scenario,
                      TC_ELEF_t function,
                      uint8_t value );

/**
 * @brief Read noise half delta value
 *
 * @param[in] scenario ( FCS_RISING / FCS_FALLING /  FCS_TOUCHED )
 * @param[in] function ( ELEF_TOUCH / ELEF_PROXIMITY )
 * @retval ( 1 ~ 63 )
 */
uint8_t tc_get_noise_hd( TC_FCS_t scenario,
                         TC_ELEF_t function );

/**
 * @brief Sets the noise count limit
 *
 * Determines the number of samples consecutively greater than the Max Half
 * Delta necessary before it can be determined that it is non-noise.
 *
 * @param[in] scenario ( FCS_RISING / FCS_FALLING /  FCS_TOUCHED )
 * @param[in] function ( ELEF_TOUCH / ELEF_PROXIMITY )
 * @param[in] value ( 0 ~ 255 )
 */
void tc_set_ncl( TC_FCS_t scenario,
                 TC_ELEF_t function,
                 uint8_t value );

/**
 * @brief Read noise count limit
 *
 * @param[in] scenario ( FCS_RISING / FCS_FALLING /  FCS_TOUCHED )
 * @param[in] function ( ELEF_TOUCH / ELEF_PROXIMITY )
 * @retval ( 0 ~ 255 )
 */
uint8_t tc_get_ncl( TC_FCS_t scenario,
                    TC_ELEF_t function );

/**
 * @brief Sets the filter delay count limit
 *
 * Determines the rate of operation of the filter. A larger number makes it
 * operate slower.
 *
 * @param[in] scenario ( FCS_RISING / FCS_FALLING /  FCS_TOUCHED )
 * @param[in] function ( ELEF_TOUCH / ELEF_PROXIMITY )
 * @param[in] value ( 0 ~ 255 )
 */
void tc_set_filter_dcl( TC_FCS_t scenario,
                        TC_ELEF_t function,
                        uint8_t value );

/**
 * @brief Read filter delay count
 *
 * @param[in] scenario ( FCS_RISING / FCS_FALLING /  FCS_TOUCHED )
 * @param[in] function ( ELEF_TOUCH / ELEF_PROXIMITY )
 * @retval ( 0 ~ 255 )
 */
uint8_t tc_get_filter_dcl( TC_FCS_t scenario,
                           TC_ELEF_t function );

/**
 * @brief Sets touch or release threshold
 *
 * Each of the 13 channels has its own set of touch threshold and release
 * threshold registers. The threshold is defined as a deviation value from the
 * baseline value, so it remains constant even baseline value changes.
 * Typically the touch threshold is a little bigger than the release threshold
 * to touch debounce and hysteresis. The setting of the threshold is depended
 * on the actual application.
 *
 * @param[in] status ( TS_RELEASE / TS_TOUCH )
 * @param[in] electrode
 *          ( ELE_A / ELE_B / ELE_C / ELE_D / ELE_E / ELE_F / ELE_G / ELE_H )
 * @param[in] th_value ( 0 ~ 255 )
 */
void tc_set_th( TC_TS_t status,
                TC_ELE_t electrode,
                uint8_t th_value );

/**
 * @brief Returns touch or release threshold
 *
 * @param[in] status ( TS_RELEASE / TS_TOUCH )
 * @param[in] electrode
 *          ( ELE_A / ELE_B / ELE_C / ELE_D / ELE_E / ELE_F / ELE_G / ELE_H )
 *
 * @retval ( 0 ~ 255 )
 */
uint8_t tc_get_th( TC_TS_t status,
                   TC_ELE_t electrode );

/**
 * @brief Sets touch or release debounce
 *
 * Debounce setting affecting the final touch and release status change in
 * 0x00 and 0x01. The status change will only take place after the number of
 * consecutive touch or release detection meets the debounce number.
 * If the number detected does not meet the debounce number, the status will
 * not change.
 *
 * @param[in] status ( TS_RELEASE / TS_TOUCH )
 * @param[in] value ( 0 ~ 7 )
 */
void tc_set_debounce( TC_TS_t status,
                      uint8_t value );

/**
 * @brief Returns touch or release debounce
 *
 * @param[in] status ( TS_RELEASE / TS_TOUCH )
 *
 * @retval ( 0 ~ 7 )
 */
uint8_t tc_get_debounce( TC_TS_t status );

/**
 * @brief Sets first filter iterations
 *
 * The first filter iterations field selects the number of samples taken as
 * input to the first level of filtering. Default value is SAMPLE_6.
 *
 * @param[in] samples ( FFI_6 / FFI_10 / FFI_18 / FFI_34 )
 */
void tc_set_ffi( TC_FFI_t samples );

/**
 * @brief Returns first filter iterations value
 *
 * @retval ( FFI_6 / FFI_10 / FFI_18 / FFI_34 )
 */
TC_FFI_t tc_get_ffi( void );

/**
 * @brief Sets global charge discharge current
 *
 * The Charge Discharge Current field selects the supply current to be used
 * when charging and discharging an electrode. Default value is 16 uA.
 *
 * @param[in] current - value in microAmpers ( 0 ~ 63 )
 */
void tc_set_global_cdc( uint8_t current );

/**
 * @brief Returns global charge discharge current
 *
 * @retval ( 0 ~ 63 )
 */
uint8_t tc_get_global_cdc( void );

/**
 * @brief Sets global charge time
 *
 * Sets the amount of time an electrode charges.
 * Default charge time is CDT_05 ( 0.5 uS ).
 *
 * @param[in] time ( CDT_05 / CDT_1 / CDT_2 / CDT_4 / CDT_8 / CDT_16 / CDT_32 )
 */
void tc_set_global_cdt( TC_CDT_t time );

/**
 * @brief Returns global charge time
 *
 * @retval ( CDT_05 / CDT_1 / CDT_2 / CDT_4 / CDT_8 / CDT_16 / CDT_32 )
 */
TC_CDT_t tc_get_global_cdt( void );

/**
 * @brief Sets second filter iterations
 *
 * Number of samples taken for the second level filter.
 * Defaul number of iterations is 4.
 *
 * @param[in] samples - ( SFI_04 / SFI_06 / SFI_10 / SFI_18 )
 */
void tc_set_sfi( TC_SFI_t samples );

/**
 * @brief Returns second filter iterations
 *
 * @retval ( SFI_04 / SFI_06 / SFI_10 / SFI_18 )
 */
TC_SFI_t tc_get_sfi( void );

/**
 * @brief Set electrode sample interval
 *
 * Period between samples used for the second level of filtering.
 *
 * @param[in] interval
 *      ( ESI_1 / ESI_2 / ESI_4 / ESI_8 / ESI_16 / ESI_32 / ESI_64 / ESI_128 )
 */
void tc_set_esi( TC_ESI_t interval );

/**
 * @brief Returns electrode sample interval
 *
 * @retval
 *      ( ESI_1 / ESI_2 / ESI_4 / ESI_8 / ESI_16 / ESI_32 / ESI_64 / ESI_128 )
 */
TC_ESI_t tc_get_esi( void );

/**
 * @brief Sets individual charge discharge current
 *
 * The power on reset default of these registers is all zeros.
 * If value is 0 than global charge discharge current will be used.
 *
 * @param[in] electrode
 *          ( ELE_A / ELE_B / ELE_C / ELE_D / ELE_E / ELE_F / ELE_G / ELE_H )
 * @param[in] current ( 0 ~ 63 )
 */
void tc_set_cdc( TC_ELE_t electrode,
                 uint8_t current );

/**
 * @brief Returns individual charge discharge current
 *
 * @param[in] electrode
 *          ( ELE_A / ELE_B / ELE_C / ELE_D / ELE_E / ELE_F / ELE_G / ELE_H )
 *
 * @retval ( 0 ~ 63 )
 */
uint8_t tc_get_cdc( TC_ELE_t electrode );

/**
 * @brief Sets individual charge time
 *
 * Individual charge discharge time value for each channel if global value is
 * not used. The power on reset default of these registers is all zeros.
 * If individual value is 0 then the global value is used.
 *
 * @param[in] electrode
 *          ( ELE_A / ELE_B / ELE_C / ELE_D / ELE_E / ELE_F / ELE_G / ELE_H )
 * @param[in] time
 *          ( CDT_05 / CDT_1 / CDT_2 / CDT_4 / CDT_8 / CDT_16 / CDT_32 )
 */
void tc_set_cdt( TC_ELE_t electrode,
                 TC_CDT_t time );

/**
 * @brief Returns individual charge time
 *
 * @param[in] electrode
 *          ( ELE_A / ELE_B / ELE_C / ELE_D / ELE_E / ELE_F / ELE_G / ELE_H )
 *
 * @retval ( CDT_05 / CDT_1 / CDT_2 / CDT_4 / CDT_8 / CDT_16 / CDT_32 )
 */
TC_CDT_t tc_get_cdt( TC_ELE_t electrode );

/**
 * @brief Sets calibration lock
 *
 * Controls the Baseline Value Register update. Typically CL_2 is used so the
 * baseline value can be initialized at the beginning stage with a value close
 * to the immediate data instead of starting from zero. Since the third level
 * filter has a big time constant, starting from zero may cause a long time
 * of no response with touch.
 *
 * @param[in] lock ( CL_0 / CL_1 / CL_2 / CL_3 )
 */
void tc_set_cl( TC_CL_t lock );

/**
 * @brief Returns calibration lock value
 *
 * @retval ( CL_0 / CL_1 / CL_2 / CL_3 )
 */
TC_CL_t tc_get_cl( void );

/**
 * @brief Sets touch detection enabled.
 *
 * When value is different than 0, electrode touch detection is enabled on
 * all electrodes between 0 and given value.
 *
 * @param[in] electrodes
 *          ( ELE_A / ELE_B / ELE_C / ELE_D / ELE_E / ELE_F / ELE_G / ELE_H )
 */
void tc_set_active( TC_ELE_t electrodes );

/**
 * @brief Returns touch detection status.
 *
 * @retval ( ELE_A / ELE_B / ELE_C / ELE_D / ELE_E / ELE_F / ELE_G / ELE_H )
 */
TC_ELE_t tc_get_active( void );

/**
 * @brief Sets proximity detection enabled
 *
 * When value is different than 0 proximity detection with specific
 * electrodes combination is enabled.
 *
 * @param[in] value ( ELEPROX_DISABLED / ELEPROX_01 / ELEPROX_03 / ELEPROX_11 )
 */
void tc_set_eleprox( TC_ELEPROX_t value );

/**
 * @brief Returns proximity detection status
 *
 * @retval ( ELEPROX_DISABLED / ELEPROX_01 / ELEPROX_03 / ELEPROX_11 )
 */
TC_ELEPROX_t tc_get_eleprox( void );

/**
 * @brief Sets upper side limit
 *
 * This value makes sure that the electrode data level is below the linear
 * upper limit range Vdd - 0.7 V . Typically the USL is set at the maximum
 * linear limit.
 *
 * @note USL = ( Vdd - 0.7 ) / Vdd x 256
 *
 * @param[in] value ( 0 ~ 256 )
 */
void tc_set_up_sl( uint8_t value );

/**
 * @brief Returns upper side limit
 *
 * @retval ( 0 ~ 256 )
 */
uint8_t tc_get_up_sl( void );

/**
 * @brief Sets lower side limit
 *
 * This value results the lower limit for the electrode data. To make sure the
 * touched electrode data still in the limit, the LSL should be low enough to
 * prevent unnecessary out of range error. In a typical touch application,
 * for example, the LSL can be set at 65% of the USL.
 *
 * @note LSL = ( Vdd - 0.7 ) / Vdd x 256 x 0.65
 *
 * @param[in] value ( 0 ~ 256 )
 */
void tc_set_low_sl( uint8_t value );

/**
 * @brief Returns lower side limit
 *
 * @retval ( 0 ~ 256 )
 */
uint8_t tc_get_low_sl( void );

/**
 * @brief Sets target level
 *
 * Target Level is the expected target electrode data level when untouched
 * after auto configuration. The TL shall be in between the USL and LSL and
 * should be as high as possible to maximize the sensing charge field to get
 * the maximum touch response. To anticipate possible capacitance decrease
 * range and Vdd variation, for example, a typical setting for TL is  90% of
 * the USL. If a searching result is outside the range limited by USL and LSL,
 * an Out Of Range (OOR) error will be reported at the end of auto configuration
 *
 * @note TL= USL x 0.9 = ( Vdd - 0.7 ) / Vdd x 256 x 0.9
 *
 * @param[in] value ( 0 ~ 256 )
 */
void tc_set_tl( uint8_t value );

/**
 * @brief Returnes target level
 *
 * @retval ( 0 ~ 256 )
 */
uint8_t tc_get_tl( void );

/**
 * @brief Sets autoconfig status
 *
 * @param[in] value ( AC_ENABLE / AC_DISABLE )
 */
void tc_set_auto_config( TC_AC_t value );

/**
 * @brief Returns autoconfig status
 *
 * @retval ( AC_ENABLE / AC_DISABLE )
 */
TC_AC_t tc_get_auto_config( void );

/**
 * @brief Sets auto-reconfig status
 *
 * @param[in] value ( ARC_ENABLE / ARC_DISABLE )
 */
void tc_set_auto_reconfig( TC_ARC_t value );

/**
 * @brief Returns auto-reconfig status
 *
 * @retval ( ARC_ENABLE / ARC_DISABLE )
 */
TC_ARC_t tc_get_auto_reconfig( void );

/**
 * @brief Sets baseline adjust control
 *
 * Specifies how to change baseline value for each channel upon finishing auto
 * configuration and auto re-configuration.
 *
 * @param[in] value ( BVAC_NOCHANGE / BVAC_ZERO / BVAC_ACFG1 / BVAC_ACFG2 )
 */
void tc_set_bvac( TC_BVAC_t value );

/**
 * @brief Returns baseline adjust control
 *
 * @retval ( BVAC_NOCHANGE / BVAC_ZERO / BVAC_ACFG1 / BVAC_ACFG2 )
 */
TC_BVAC_t tc_get_bvac( void );

/**
 * @brief Sets number of auto-reconfig retry
 *
 * @param[in] value ( RETRY_NO / RETRY_2 / RETRY_4 / RETRY_8 )
 */
void tc_set_config_retry( TC_RETRY_t value );

/**
 * @brief Returns number of auto-reconfig retry
 *
 * @retval ( RETRY_NO / RETRY_2 / RETRY_4 / RETRY_8 )
 */
TC_RETRY_t tc_get_config_retry( void );

/**
 * @brief Sets number of AFE samples during binary search
 *
 * Value should be as same as global FFI.
 *
 * @param[in] value ( AFES_06 / AFES_10 / AFES_18 / AFES_34 )
 */
void tc_set_afes( TC_AFES_t value );

/**
 * @brief Returns number of AFE samples during binary search
 *
 * @retval ( AFES_06 / AFES_10 / AFES_18 / AFES_34 )
 */
TC_AFES_t tc_get_afes( void );

/**
 * @brief Sets skip charge time search during binary search
 *
 * @param[in] value ( CTS_EXE / CTS_SKIP )
 */
void tc_set_cts( TC_CTS_t value );

/**
 * @brief Returns skip charge time search during binary search
 *
 * @retval ( CTS_EXE / CTS_SKIP )
 */
TC_CTS_t tc_get_cts( void );

/**
 * @brief Sets auto configuration interrupt status
 *
 * @param[in] value ( ACFIE_DISABLE / ACFIE_ENABLE )
 */
void tc_set_acfie( TC_ACFIE_t value );

/**
 * @brief Returns auto configuration interrupt status
 *
 * @retval ( ACFIE_DISABLE / ACFIE_ENABLE )
 */
TC_ACFIE_t tc_get_acife( void );

/**
 * @brief Sets auto reconfiguration interrupt status
 *
 * @param[in] value ( ARFIE_DISABLE / ARFIE_ENABLE )
 */
void tc_set_arcfie( TC_ARCFIE_t value );

/**
 * @brief Returns auto reconfiguration intterupt status
 *
 * @retval ( ARCFIE_DISABLE / ARCFIE_ENABLE )
 */
TC_ARCFIE_t tc_get_arcfie( void );

/**
 * @brief Sets out of range interrupt status
 *
 * @param[in] value ( ORIE_DISABLE / ORIE_ENABLE )
 */
void tc_set_orie( TC_ORIE_t value );

/**
 * @brief Gets out of range interrupt status
 *
 * @retval ( ORIE_DISABLE / ORIE_ENABLE )
 */
TC_ORIE_t tc_get_orie( void );

/**
 * @brief Returns out of range status
 *
 * @param[in] electrode
 *          ( ELE_A / ELE_B / ELE_C / ELE_D / ELE_E / ELE_F / ELE_G / ELE_H )
 *
 * @retval ( ORD_NO / ORS_DETECTED )
 */
TC_ORS_t tc_get_ors( TC_ELE_t electrode );

/**
 * @brief Resets the device
 *
 * The soft reset doesn’t affect I2C module, but all others reset as same as
 * power reset.
 */
void tc_soft_reset( void );

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* TOUCH_CLAMP_HW_H_ */
/*** End of File **************************************************************/
