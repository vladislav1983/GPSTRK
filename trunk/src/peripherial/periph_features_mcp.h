#ifndef __PIC24F_PERIPH_FEATURES_H
#define __PIC24F_PERIPH_FEATURES_H


/******************************************************************************
 *                  PERIPHERAL SELECT HEADER FILE
 ******************************************************************************
 * FileName:        pic24f_periph_features.h
 * Dependencies:    See include below
 * Processor:       PIC24
 * Compiler:        MPLAB C30
 * Company:         Microchip Technology, Inc.
 *
 * Software License Agreement
 * The software supplied herewith by Microchip Technology Incorporated
 * (the “Company”) for its PICmicro® Microcontroller is intended and
 * supplied to you, the Company’s customer, for use solely and
 * exclusively on Microchip PICmicro Microcontroller products. The
 * software is owned by the Company and/or its supplier, and is
 * protected under applicable copyright laws. All rights are reserved.
 * Any use in violation of the foregoing restrictions may subject the
 * user to criminal sanctions under applicable laws, as well as to
 * civil liability for the breach of the terms and conditions of this
 * license.
 *
 * THIS SOFTWARE IS PROVIDED IN AN “AS IS” CONDITION. NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 * TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 * IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 *****************************************************************************/

/* By default, configuration constants are assembled from macros */
/* using the bit-wise AND operator (&). An alternate mode is */
/* available in which constants are assembled using the bit-wise */
/* OR operator (|) to set values and bit-wise AND (&) masks to */
/* clear values. To enable the alternate mode, define the */
/* USE_AND_OR symbol. */
/* */
/* To define this macro as a compiler option: */
/* -DUSE_AND_OR */
/* To define this macro in source code: */
/* #define USE_AND_OR */

#ifdef   __PIC24FJ128GA308__
/*############################################################*/
/*          Configuration for device =  'PIC24FJ128GA308'     */
/*############################################################*/

/* ADC */
#define adc_v5_1

/* CMP */
#define cmp_v2_5

/* CN */
#define cn_v2_13

/* CTMU */
#define ctmu_v2_4

/* INTERRUPT */
#define int_v1_2

/* INCAP */
#define icap_v2_4

/* I2C */
#define i2c_v1_4

/* SPI */
#define spi_v1_2

/* OUTCMP */
#define ocmp_v2_5

/* IOPORT */
#define port_v1_4

/* PWRMGNT */
#define pwrmgnt_v3_1

/* TIMERS */
#define tmr_v1_4

/* UART */
#define uart_v1_2

/* PMP */
#define epmp_v1_2

/* pps */
#define pps_v3_2

/* CRC */
#define ecrc_v1_1

/* RTCC */
#define rtcc_v1_1

/* WDT */
#define wdt_v1_1

/* DPSLP */
#define dpslp_v1_2

/* SRAM */
#define sram_v1_1

/* DMA */
#define dma_v1_1

/* PWM */
/*No configuration chosen for this peripheral*/
#else
    #error "Include file does not match processor setting"
#endif


#endif /*__PIC24F_PERIPH_FEATURES_H*/

