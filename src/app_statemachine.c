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
#ifdef __APP_STATEMACHINE_C
    #error "!!! FileName ID. It should be Unique !!!"
#else
    #define __APP_STATEMACHINE_C
#endif

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file
 *===================================================================================================================*/
#include "app_statemachine.h"
#include "kernelinclude.h"
#include "FSIO.h"
#include "devconfig.h"
#include "nmea_process.h"
#include "fsio_main.h"
#include "aprs.h"
#include "hd44780.h"
#include "gpx.h"


/*=====================================================================================================================
 * Local constants
 *===================================================================================================================*/
#define cAppStateMachineTaskPeriodUs            40E3
#define cOsTimerTick_ms                         (cOsTimerTickUs/1000UL)
#define cLcdUpdateTime_ms                       300ul
#define cSD_CardPositiongWriteTimeout_ms        1000UL
#define cAprsTransmitTimeout_ms                 500UL
#define cLcdShowTime_ms                         3500UL


/*=====================================================================================================================
 * Local macros
 *===================================================================================================================*/

/*=====================================================================================================================
 * Local types
 *===================================================================================================================*/
typedef enum teAppState
{
    eAPP_STATE_INIT = 0,
    eAPP_STATE_WAIT_GPS,
    eAPP_STATE_WAIT_TIME_SYNC,
    eAPP_NMEA_MSG_POOL,
    eAPP_SD_CARD_WRITE_POSITION,
    eAPP_APRS_TRANSMIT_DATA,
    eAPP_APRS_TRANSMIT_INFO,
    eAPP_ARRS_WAIT_TRANSMIT,
    eAPP_ARRS_WAIT_POSITION_WRITE,
    aAPP_ERROR_STATE,
    eAPP_WAIT_STATE
}tAppState;


typedef enum teLcdState
{
    eLCD_STATE_INIT,
    eLCD_SHOW_INFO,
    eLCD_STATE_WAIT_GPS,
    eLCD_STATE_SHOW_LATLON,
    eLCD_STATE_SHOW_SPEED,
    eLCD_SHOW_CLOCK,
    eLCD_CLEAR,
    eLCD_STATE_WAIT_STATE
}tLcdState;

/*=====================================================================================================================
 * Local data
 *===================================================================================================================*/
static tAppState AppState;
static tAppState AppNextState;
static tOSAlarm  AppStateAlarm;
static tOSTimer  AppStateTimer;
static tOSTimer  WaitTimeTicks;
static BOOL      bGpsMsgReceived;
static tGpsMask  GpsStatusLocal;
static BOOL      bAprsMsgTxOk;
static BOOL      bPositionWriteOk;
static tOSTimer  AppLcdUpdateTimer;
static tLcdState LcdState;
static tLcdState LcdNextState;
static tOSTimer  LcdWaitTimer;
static tOSTimer  LcdWaitTicks;
static tOSTimer  LcdShowTimer;


/*=====================================================================================================================
 * Constant Local Data
 *===================================================================================================================*/

/*=====================================================================================================================
 * Constant exported data                                                     
 *===================================================================================================================*/

/*=====================================================================================================================
 * Exported Data
 *===================================================================================================================*/
U16 u16SYSTEM_FLAGS;

/*=====================================================================================================================
 * Local Functions Prototypes
 *===================================================================================================================*/
static void App_Statemachine_LCD(void);


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
void App_Init(void)
{
    AppState = eAPP_STATE_INIT;
    AppStateAlarm.TaskID = cAppStatemachineTaskId;
    OsSetAlarm(&AppStateAlarm, (cAppStateMachineTaskPeriodUs/cOsAlarmTickUs));
    u16SYSTEM_FLAGS = 0;
    bGpsMsgReceived = cFalse;
    bAprsMsgTxOk = cFalse;
    bPositionWriteOk = cFalse;
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void App_StatemachineTask(void)
{
    tAprsTrmtCmd BeaconTypeSend = cAprsProcNotSend;

    switch(AppState)
    {
    //------------------------------------------------------------------------------------------------------------------
    case eAPP_STATE_INIT:

        OSStartTimer(&AppStateTimer);
        // wait 2s before configuration load
        WaitTimeTicks = 2000UL/cOsTimerTick_ms;
        AppState = eAPP_WAIT_STATE;
        AppNextState = eAPP_STATE_WAIT_GPS;
        
        break;
        //------------------------------------------------------------------------------------------------------------------
    case eAPP_STATE_WAIT_GPS:

        if((GpsStatusLocal & cGPS_STAT_ONLINE_SET) && (GpsStatusLocal & cGPS_STAT_MODE_SET))
        {
            AppState = eAPP_STATE_WAIT_TIME_SYNC;
        }

        break;
    //------------------------------------------------------------------------------------------------------------------
    case eAPP_STATE_WAIT_TIME_SYNC:

        if((GpsStatusLocal & cGPS_STAT_TIME_SET ) && (GpsStatusLocal & cGPS_STAT_DATE_SET))
            AppState = eAPP_NMEA_MSG_POOL;

        break;
    //------------------------------------------------------------------------------------------------------------------
    case eAPP_NMEA_MSG_POOL:

        if (cFalse != bGpsMsgReceived)
        {
            // set file system date and time
            if (S_OK == FSIOMain_SetTimeDate(&NMEA_GPS_Data))
            {
                BeaconTypeSend = NMEAProc_AprsProcessingTransmit(&NMEA_GPS_Data);

                if(BeaconTypeSend == cAprsProcSendData)
                    AppState = eAPP_APRS_TRANSMIT_DATA;
                else if(BeaconTypeSend == cAprsProcSendTrackerInfo)
                    AppState = eAPP_APRS_TRANSMIT_INFO;
                else if(BeaconTypeSend == cAprsProcNotSend)
                {
                    // position write only when aprs message is not sent
                    if(cFalse != NMEAProc_PositioningWriteProcess(&NMEA_GPS_Data))
                        AppState = eAPP_SD_CARD_WRITE_POSITION;
                }
                else
                    _assert(cFalse);
            }

            bGpsMsgReceived = cFalse;
        }

        break;
    //------------------------------------------------------------------------------------------------------------------
    case eAPP_APRS_TRANSMIT_DATA:
        
        Aprs_Control(cAPRS_TransmitData);
        AppState = eAPP_ARRS_WAIT_TRANSMIT;

        break;
    //------------------------------------------------------------------------------------------------------------------
    case eAPP_APRS_TRANSMIT_INFO:

        Aprs_Control(cAPRS_TransmitTrackerInfo);
        // set one timeout here ... just for any case
        OSStartTimer(&AppStateTimer);
        AppState = eAPP_ARRS_WAIT_TRANSMIT;

        break;
    //------------------------------------------------------------------------------------------------------------------
    case eAPP_ARRS_WAIT_TRANSMIT:

        if((cFalse != bAprsMsgTxOk) || (cFalse != OSIsTimerElapsed(&AppStateTimer, (cAprsTransmitTimeout_ms/cOsTimerTick_ms))))
        {
            bAprsMsgTxOk = cFalse;
            AppState = eAPP_NMEA_MSG_POOL;
        }

        break;
    //------------------------------------------------------------------------------------------------------------------
    case eAPP_SD_CARD_WRITE_POSITION:

        if(S_OK == Gpx_WritePosition(&NMEA_GPS_Data))
        {
            // set one timeout here ... just for any case
            OSStartTimer(&AppStateTimer);
            // TODO: remove this :)
            bPositionWriteOk = cTrue;
            AppState = eAPP_ARRS_WAIT_POSITION_WRITE;
        }
        else
        {
            AppState = aAPP_ERROR_STATE;
        }
        break;
    //------------------------------------------------------------------------------------------------------------------
    case eAPP_ARRS_WAIT_POSITION_WRITE:

        if((cFalse != bPositionWriteOk) || (cFalse != OSIsTimerElapsed(&AppStateTimer, (cSD_CardPositiongWriteTimeout_ms/cOsTimerTick_ms))))
        {
            bPositionWriteOk = cFalse;
            AppState = eAPP_NMEA_MSG_POOL;
        }

        break;
    //------------------------------------------------------------------------------------------------------------------
    case eAPP_WAIT_STATE:

        _assert(AppState != AppNextState);

        if(cFalse != OSIsTimerElapsed(&AppStateTimer, WaitTimeTicks))
            AppState = AppNextState;

        break;
    //------------------------------------------------------------------------------------------------------------------
    case aAPP_ERROR_STATE:
            
            _OsResetCpu();

        break;
    //------------------------------------------------------------------------------------------------------------------
    default:
        _assert(cFalse);
        break;
    }

    App_Statemachine_LCD();
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void AppStatemachine_GpsMsgReceivedCallback(tMsg Msg)
{

    if(sizeof(tGpsMask) == Msg.Lng)
    {
        GpsStatusLocal = 0;
        GpsStatusLocal = *(tGpsMask*)Msg.pBuff;
    }
    else
    {
        _assert(cFalse);
    }

    bGpsMsgReceived = cTrue; 
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void App_Statemachine_AprsMsgTxCallback(tCtrl Control)
{
    if(Control == cCallbackCtrlOK)
    {
        
    }
    else if(Control == cCallbackCtrlError)
    {

    }
    else
    {
        _assert(cFalse);
    }

    bAprsMsgTxOk = cTrue;
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
static void App_Statemachine_LCD(void)
{
    U8 u8TmpBuff[10];

    if((LcdState == eLCD_CLEAR) || (cFalse != OSIsTimerElapsed(&AppLcdUpdateTimer, (cLcdUpdateTime_ms/cOsTimerTick_ms))))
    {
        switch(LcdState)
        {
        case eLCD_STATE_INIT:

            OSStartTimer(&AppLcdUpdateTimer);

            LcdWaitTicks = 1000UL/cOsTimerTick_ms;
            OSStartTimer(&LcdWaitTimer);

            LcdState = eLCD_STATE_WAIT_STATE;
            LcdNextState = eLCD_SHOW_INFO;

            break;
        //--------------------------------------------------------------------------------------------------------------
        case eLCD_SHOW_INFO:
    

            if(_sd_card_present())
                _lcdprintf(1, 1, "%s", "SD CARD PRESENT");
            else
                _lcdprintf(1, 1, "%s", "SD CARD NOT PRESENT");

            LcdWaitTicks = 3000UL/cOsTimerTick_ms;
            OSStartTimer(&LcdWaitTimer);

            LcdState = eLCD_STATE_WAIT_STATE;
            LcdNextState = eLCD_STATE_WAIT_GPS;

            break;
        //--------------------------------------------------------------------------------------------------------------
        case eLCD_STATE_WAIT_GPS:
            
            if(AppState == eAPP_STATE_WAIT_GPS || AppState == eAPP_STATE_WAIT_TIME_SYNC)
            {
                _lcdprintf(1, 1, "%s", "Waiting GPS ...");

                LcdWaitTicks = 3000UL/cOsTimerTick_ms;
                OSStartTimer(&LcdWaitTimer);

                LcdState     = eLCD_STATE_WAIT_STATE;
                LcdNextState = eLCD_STATE_WAIT_GPS;
            }
            else
            {
                LcdState     = eLCD_CLEAR;
                LcdNextState = eLCD_STATE_SHOW_LATLON;
            }
            
            break;
        //--------------------------------------------------------------------------------------------------------------
        case eLCD_STATE_SHOW_LATLON:

            if(cFalse == OSIsTimerElapsed(&LcdShowTimer, (cLcdShowTime_ms/cOsTimerTick_ms)))
            {
                memcpy(u8TmpBuff, NMEA_GPS_Data.AX25_GPS_Data.u8Latitude, sizeof(NMEA_GPS_Data.AX25_GPS_Data.u8Latitude));
                u8TmpBuff[sizeof(NMEA_GPS_Data.AX25_GPS_Data.u8Latitude)] = '\0';
                _lcdprintf(1, 1, "Lat:%s", u8TmpBuff);

                memcpy(u8TmpBuff, NMEA_GPS_Data.AX25_GPS_Data.u8Longitude, sizeof(NMEA_GPS_Data.AX25_GPS_Data.u8Longitude));
                u8TmpBuff[sizeof(NMEA_GPS_Data.AX25_GPS_Data.u8Longitude)] = '\0';
                _lcdprintf(1, 2, "Lon:%s", u8TmpBuff);
            }
            else
            {
                LcdState     = eLCD_CLEAR;
                LcdNextState = eLCD_STATE_SHOW_SPEED;
            }
            
            break;
        //--------------------------------------------------------------------------------------------------------------
        case eLCD_STATE_SHOW_SPEED:

            //_lcdprintf(1, 2, "Sat used = %02d", NMEA_GPS_Data.u16SatNumber);
            if(cFalse == OSIsTimerElapsed(&LcdShowTimer, (cLcdShowTime_ms/cOsTimerTick_ms)))
            {
                _lcdprintf(1, 1, "Speed:%03d km/h", NMEA_GPS_Data.u16GpsSpeed);
                _lcdprintf(1, 2, "Alt:%04d m", NMEA_GPS_Data.u16Altitude);
            }
            else
            {
                LcdState     = eLCD_CLEAR;
                LcdNextState = eLCD_SHOW_CLOCK;
            }

            break;
        //--------------------------------------------------------------------------------------------------------------
        case eLCD_SHOW_CLOCK:

            if(cFalse == OSIsTimerElapsed(&LcdShowTimer, (cLcdShowTime_ms/cOsTimerTick_ms)))
            {
                _lcdprintf(4, 1, "%02d-%02d-%04d",NMEA_GPS_Data.DateTime.tm_mday, 
                                                  NMEA_GPS_Data.DateTime.tm_mon,
                                                  NMEA_GPS_Data.DateTime.tm_year);

                _lcdprintf(5, 2, "%02d:%02d:%02d", NMEA_GPS_Data.DateTime.tm_hour,
                                                   NMEA_GPS_Data.DateTime.tm_min,
                                                   NMEA_GPS_Data.DateTime.tm_sec);
            }
            else
            {
                // state change
                LcdState     = eLCD_CLEAR;
                LcdNextState = eLCD_STATE_SHOW_LATLON;
            }

            break;
        //--------------------------------------------------------------------------------------------------------------
        case eLCD_CLEAR:
            
            _assert(LcdState != LcdNextState);
            OSStartTimer(&LcdShowTimer);
            // on state change clear LCD
            HD44780_Putc('\f');

            LcdState = LcdNextState;

            break;
        //--------------------------------------------------------------------------------------------------------------
        case eLCD_STATE_WAIT_STATE:

            _assert(LcdState != LcdNextState);

            if(cFalse != OSIsTimerElapsed(&LcdWaitTimer, LcdWaitTicks))
                LcdState = LcdNextState;

            break;
        //--------------------------------------------------------------------------------------------------------------
        default:
            _assert(cFalse);
            LcdState = eLCD_STATE_WAIT_GPS;
            break;
        }

        // restart timer
        OSStartTimer(&AppLcdUpdateTimer);
    }
}
