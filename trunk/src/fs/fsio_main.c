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
#ifdef __FSIO_MAIN_C
    #error "!!! FileName ID. It should be Unique !!!"
#else
    #define __FSIO_MAIN_C
#endif

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file
 *===================================================================================================================*/
#include "fsio_main.h"
#include "FSIO.h"
#include "alarm.h"
#include "kernelparam.h"
#include "kerneltimer.h"
#include "devconfig.h"



/*=====================================================================================================================
 * Local constants
 *===================================================================================================================*/
#define cFSIO_PollingTask_us                40E3
#define cFSIO_DioInitTime_ms                300UL
#define cDioCardInsertsed                   0

/*=====================================================================================================================
 * Local macros
 *===================================================================================================================*/

/*=====================================================================================================================
 * Local types
 *===================================================================================================================*/
typedef enum teCardState
{
    cInitState = 0,
    eCardInitialize,
    cCardGetState,
    eCardInserted,
    eCardNotPresent,
    eCardWaitState
}tCardState;



/*=====================================================================================================================
 * Local data
 *===================================================================================================================*/
static tOSAlarm FSIO_Alarm; 
static tCardState CardState = cInitState;   // important to init ...
static tOSTimer CardInitTimer;

/*=====================================================================================================================
 * Constant Local Data
 *===================================================================================================================*/

/*=====================================================================================================================
 * Constant exported data                                                     
 *===================================================================================================================*/

/*=====================================================================================================================
 * Exported Data
 *===================================================================================================================*/

/*=====================================================================================================================
 * Local Functions Prototypes
 *===================================================================================================================*/


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
void FsioMain_Init(void)
{
    FSIO_Alarm.TaskID = cFSIOTaskId;
    OsSetAlarm(&FSIO_Alarm, cFSIO_PollingTask_us/cOsAlarmTickUs);
    CardState = cInitState;

    // Init SPI pins. It is important, because these pins are set as analog at power-up!
    _DioAnalogConfig(cDioPin_SPI_SCK, cPinModeDigital);
    _DioAnalogConfig(cDioPin_SPI_SDO, cPinModeDigital);
    _DioAnalogConfig(cDioPin_SPI_SDI, cPinModeDigital);
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void FSIO_Task(void)
{
    switch(CardState)
    {
    //------------------------------------------------------------------------------------------------------------------
    case cInitState:
         OSStartTimer(&CardInitTimer);
         CardState = eCardWaitState;
         _DioWritePin(cDioPin_SD_CardLed, 1);
        break;
    //------------------------------------------------------------------------------------------------------------------
    case eCardInitialize:
        // card is inserted, initialize card
        if(cFalse != MDD_MediaDetect())
        {
            if (cFalse != FSInit())
            {
                // init OK
                _set_sd_card_present(1);
                _DioWritePin(cDioPin_SD_CardLed, 0);
                // load device configuration
                Devconfig_LoadConfig();
                App_Statemachine_SD_CardCallback(cCallbackCtrlOK);

                CardState = eCardInserted;
            }
            else
            {
                // init error
                _set_sd_card_present(0);
                _DioWritePin(cDioPin_SD_CardLed, 1);

                CardState = eCardNotPresent;
            }
        }
        else
        {
            _set_sd_card_present(0);
            CardState = eCardNotPresent;
        }
        break;
    //-----------------------------------------------------------------------------------------------------------------
    case eCardInserted:
        if(cDioCardInsertsed != _DioReadPinFiltered(cDioPin_SD_CardPresent))
        {
            _set_sd_card_present(0);
            _DioWritePin(cDioPin_SD_CardLed, 1);
            App_Statemachine_SD_CardCallback(cCallbackCtrlNOK);

            CardState = eCardNotPresent;
        }
        break;
    //-------------------------------------------------------------------------------------------------------------------
    case eCardNotPresent:
        // wait card inserted
        if(cDioCardInsertsed == _DioReadPinFiltered(cDioPin_SD_CardPresent))
        {
            CardState = eCardInitialize;
        }
        break;
    //------------------------------------------------------------------------------------------------------------------
    case eCardWaitState:
        if(cFalse != OSIsTimerElapsed(&CardInitTimer, cFSIO_DioInitTime_ms/(cOsTimerTickUs/1000UL)))
        {
            // wait some time before start polling card state
            CardState = eCardNotPresent;
        }
        break;
    //-------------------------------------------------------------------------------------------------------------------
    default:
        _assert(cFalse);
        CardState = eCardNotPresent;
        break;
    }
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
HRESULT FSIOMain_SetTimeDate(tNMEA_GPS_Data *GpsData)
{
    S16 s16res;
    HRESULT res = S_NOK;

    s16res = SetClockVars( GpsData->DateTime.tm_year, 
                           GpsData->DateTime.tm_mon,
                           GpsData->DateTime.tm_mday,
                           GpsData->DateTime.tm_hour,
                           GpsData->DateTime.tm_min, 
                           GpsData->DateTime.tm_sec);
    if(s16res != -1)
        res = S_OK;

    return res;
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
