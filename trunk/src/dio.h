/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/
#ifndef __DIO_H
#define __DIO_H

/*
** Module Identification
*/
#define __DIO

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file                
 *===================================================================================================================*/
#include "basedef.h"

/*=====================================================================================================================
 * Constant data                                                              
 *===================================================================================================================*/
#define cDioTaskPeriodUs                    10000UL   /* 10ms */
#define cDioBuffLen                         ((U16)(cDioPin_Number/sizeof(tDioBuff))+1UL)

#define cPinModeDigital                     0
#define cPinModeAnalog                      1
#define cPinModeInput                       1
#define cPinModeOutput                      0
#define cPinOpenDrainMode                   1
#define cPinOpenDrainNormal                 0

/*
** Define list of analog pins
*/
#define cDioPin_BatteryVoltage              _DeclarePin(B, 8)
#define cDioPin_Temperature                 _DeclarePin(B, 9)

/*
** Define list of digital non filtered pins
*/
#define cDioPin_GreenLed                    _DeclarePin(E, 1)
#define cDioPin_PTT                         _DeclarePin(F, 5)
#define cDioPin_DEBUG                       _DeclarePin(A, 9)
#define cDioPin_SPI_SDI                     _DeclarePin(G, 8)
#define cDioPin_SPI_SDO                     _DeclarePin(G, 7)
#define cDioPin_SPI_SCK                     _DeclarePin(G, 6)
#define cDioPin_GpsUartRx                   _DeclarePin(B, 6)
#define cDioPin_GpsUartTx                   _DeclarePin(B, 7)
#define cDioPin_GpsLed                      _DeclarePin(F, 1)
#define cDioPin_SD_CardLed                  _DeclarePin(G, 0)
#define cDioPin_CompInB                     _DeclarePin(B, 4)
#define cDioPin_AnotherStatTxLed            _DeclarePin(E, 3)

// LCD pins
#define cDioPin_LcdBacklight                _DeclarePin(D, 10)
#define cDioPin_Lcd_RS                      _DeclarePin(D, 11)
#define cDioPin_Lcd_RW                      _DeclarePin(C, 12)
#define cDioPin_LcdEnable                   _DeclarePin(C, 15)
#define cDioPin_Lcd_DB4                     _DeclarePin(A, 14)
#define cDioPin_Lcd_DB5                     _DeclarePin(A, 15)
#define cDioPin_Lcd_DB6                     _DeclarePin(D, 8)
#define cDioPin_Lcd_DB7                     _DeclarePin(D, 9)


/*
** Define input pins assigned to filtration -> consider the following syntax
** cDioPin_xxxx       -> pin define
** cDioPin_xxxx_Index -> pin index define
*/
#define cDioPin_SD_CardPresent              _DeclarePin(B, 14)
#define cDioPin_SD_CardPresent_Index        0
#define cDioPin_SD_CardFiltration_us        40000UL
#define cDioPin_Sd_CardInit                 1
// Total number of pins
#define cDioPin_Number                      1

/*
** Define input pins filtering constants
*/
#define cDioFilteredConstants()                                 \
{                                                               \
    (cDioPin_SD_CardFiltration_us/cDioTaskPeriodUs )            \
}

/*
** Define input pins initial state
*/
#define cDioPinsInit()                                          \
{                                                               \
    cDioPin_Sd_CardInit                                         \
}

/*=====================================================================================================================
 * Exported type                                                             
 *===================================================================================================================*/
typedef U16 tDioBuff;
typedef U8  tDioFilt;

/*=====================================================================================================================
 * Exported data                                                              
 *===================================================================================================================*/
extern U16 DioFilteredBuffer[cDioBuffLen];

/*=====================================================================================================================
 * Constant exported data                                                     
 *===================================================================================================================*/

/*=====================================================================================================================
 * Exported Macros                                                            
 *===================================================================================================================*/
/*
** Pins config macros
*/
#define _DioAnalogConfig(pin, mode)         _DioAnalogPin(pin) = (mode)
#define _DioPinConfig(pin, mode)            _DioDirectionPin(pin) = (mode)
#define _DioPinOpenDrainConfig(pin, mode)   _DioOpenDrainPin(pin) = (mode)
/*
** Pins access macros
*/
#define _DioReadPinImmediate(pin)           _DioInputPin(pin)
#define _DioReadPinFiltered(pin)            ((BOOL)(DioFilteredBuffer[((pin##_Index)/sizeof(tDioBuff))] >> (pin##_Index)))
#define _DioWritePin(pin, val)              _DioOutputPin(pin) = (val)
#define _DioTogglePin(pin)                  _DioOutputPin(pin) = (~(_DioOutputPin(pin)))
/*
** Pins helper macros. Do not use these macros directly!
*/
#define _DeclarePin(port, pin)              port##pin
#define _DioInputPin(pin)                   _R##pin
#define _DioAnalogPin(pin)                  _ANS##pin
#define _DioOutputPin(pin)                  _LAT##pin
#define _DioDirectionPin(pin)               _TRIS##pin
#define _DioOpenDrainPin(pin)               _OD##pin

#define _DioInit()                          DioInit()

/*=====================================================================================================================
 * Exported functions                     				                        
 *===================================================================================================================*/
extern void DioInit(void);
extern void DioTask(void);

#endif /* __DIO_H */
