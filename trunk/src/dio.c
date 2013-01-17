/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/

/*=====================================================================================================================
 * Body Identification  
 *===================================================================================================================*/
#ifdef __DIO_C
    #error "!!! FileName ID. It should be Unique !!!"
#else
    #define __DIO_C
#endif 

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file
 *===================================================================================================================*/
#include "dio.h"
#include "alarm.h"
#include "kernelparam.h"
#include "kerneltimer.h"

/*=====================================================================================================================
 * Local constants
 *===================================================================================================================*/


/*=====================================================================================================================
 * Local macros
 *===================================================================================================================*/

/*=====================================================================================================================
 * Local types
 *===================================================================================================================*/

/*=====================================================================================================================
 * Local data
 *===================================================================================================================*/
static tOSAlarm DioTaskAlarm;
static tDioFilt DioFiltCounters[cDioPin_Number];
static tDioBuff DioInputBuffer[cDioBuffLen];
static tOSTimer LiveLedTimer;

/*=====================================================================================================================
 * Constant Local Data
 *===================================================================================================================*/
static const tDioFilt DioFilteringConstants[cDioPin_Number] = cDioFilteredConstants();
static const BOOL bDioInitBuff[cDioPin_Number] = cDioPinsInit();

/*=====================================================================================================================
 * Constant exported data                                                     
 *===================================================================================================================*/

/*=====================================================================================================================
 * Exported Data
 *===================================================================================================================*/
tDioBuff DioFilteredBuffer[cDioBuffLen];

/*=====================================================================================================================
 * Local Functions Prototypes
 *===================================================================================================================*/
static void Dio_ReadInputs(void);


/*=====================================================================================================================
 *
 *                                  E X P O R T E D    F U N C T I O N S
 *
 *===================================================================================================================*/
/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void __attribute__((user_init)) DioInit(void)
{
    U16 u16Index;

    /* Pins Init */
    _DioWritePin(cDioPin_GreenLed, 1);
    _DioPinConfig(cDioPin_GreenLed, cPinModeOutput);

    _DioPinConfig(cDioPin_SD_CardPresent, cPinModeInput);
    _DioAnalogConfig(cDioPin_SD_CardPresent, cPinModeDigital);

    _DioWritePin(cDioPin_DEBUG, 1);
    _DioPinConfig(cDioPin_DEBUG, cPinModeOutput);
    // Gps led config
    _DioWritePin(cDioPin_GpsLed, 1);
    _DioPinConfig(cDioPin_GpsLed, cPinModeOutput);

    // Gps led config
    _DioPinConfig(cDioPin_AssertLed, 1);
    _DioPinConfig(cDioPin_AssertLed, cPinModeOutput);

    memset(DioFiltCounters,   0, sizeof(DioFiltCounters));
    memset(DioInputBuffer,    0, sizeof(DioInputBuffer));
    memset(DioFilteredBuffer, 0, sizeof(DioFilteredBuffer));

    for(u16Index = 0; u16Index < sizeof(bDioInitBuff); u16Index++)
    {
        DioFilteredBuffer[u16Index/(8UL * sizeof(DioFilteredBuffer))] = bDioInitBuff[u16Index] << u16Index;
    }

    DioTaskAlarm.TaskID = cDioTaskId;
    OsSetAlarm(&DioTaskAlarm, (cDioTaskPeriodUs/cOsAlarmTickUs));

    OSStartTimer(&LiveLedTimer);
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void DioTask(void)
{
    U16 u16Index;
    BOOL bInputValue;

    Dio_ReadInputs();

    for(u16Index = 0; u16Index < cDioPin_Number; u16Index++)
    {
        bInputValue = DioInputBuffer[(u16Index/sizeof(tDioBuff))] >> u16Index;

        if(cFalse != bInputValue)
        {
            if(DioFiltCounters[u16Index] < DioFilteringConstants[u16Index])
            {
                ++DioFiltCounters[u16Index];
            }
            else
            {
                DioFilteredBuffer[(u16Index/sizeof(tDioBuff))] |= (tDioBuff)(1 << (u16Index % (sizeof(tDioBuff) * 8UL)));
            }
        }
        else
        {
            if(DioFiltCounters[u16Index] > 0)
            {
                --DioFiltCounters[u16Index];
            }
            else
            {
                DioFilteredBuffer[(u16Index/sizeof(tDioBuff))] &= (tDioBuff)(~(tDioBuff)(1 << (u16Index % (sizeof(tDioBuff) * 8UL))));
            }
        }
    }

    if(cFalse != OSIsTimerElapsed(&LiveLedTimer, (1000UL/(cOsTimerTickUs/1000UL))))
    {
        _DioTogglePin(cDioPin_GreenLed);
        OSStartTimer(&LiveLedTimer);
    }
}

/*=====================================================================================================================
 *                                                                            
 *                                     L O C A L    F U N C T I O N S                   
 *                                                                            
 *===================================================================================================================*/
/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
static void Dio_ReadInputs(void)
{
    DioInputBuffer[(cDioPin_SD_CardPresent_Index/sizeof(tDioBuff))] = (_DioReadPinImmediate(cDioPin_SD_CardPresent) << cDioPin_SD_CardPresent_Index);
    
}

