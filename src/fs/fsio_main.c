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
#include "gps_main.h"


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
//char sendBuffer[] = "This is test string 1";
//char send2[] = "2";

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
void __attribute__((user_init)) FsioMain_Init(void)
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
                // load device configuration
                Devconfig_LoadConfig();
                CardState = eCardInserted;
            }
            else
            {
                // init error
                _set_sd_card_present(0);
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
        _Assert(cFalse);
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

    s16res = SetClockVars(GpsData->DateTime.tm_year, 
                          GpsData->DateTime.tm_mon + 1,   // note that function receive month in different format
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
