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


/*=====================================================================================================================
 * Local constants
 *===================================================================================================================*/
#define cAppStateMachineTaskPeriodUs            40E3
#define cOsTimerTick_ms                         (cOsTimerTickUs/1000UL)


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
    eAPP_WAIT_STATE
}tAppState;

/*=====================================================================================================================
 * Local data
 *===================================================================================================================*/
static tAppState AppState;
static tAppState AppNextState;
static tOSAlarm  AppStateAlarm;
static tOSTimer  AppStateTimer;
static tOSTimer  WaitTimeTicks;
static BOOL bGpsMsgReceived;
static tGpsMask GpsStatusLocal;
static BOOL bAprsMsgTxOk;


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
            //HD44780_Putc('\f');
            _lcdprintf(5, 1, "%s", "test");
            //_lcdprintf(0, 0, "%s", "test");
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
                    AppState = eAPP_SD_CARD_WRITE_POSITION;
                else
                    _assert(cFalse);
            }

            bGpsMsgReceived = cFalse;

            _lcdprintf(1, 2, "%04d", VTime_GetSystemTick());
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

        AppState = eAPP_ARRS_WAIT_TRANSMIT;

        break;
    //------------------------------------------------------------------------------------------------------------------
    case eAPP_ARRS_WAIT_TRANSMIT:

        if(cFalse != bAprsMsgTxOk)
        {
            bAprsMsgTxOk = cFalse;
            AppState = eAPP_SD_CARD_WRITE_POSITION;
        }

        break;
    //------------------------------------------------------------------------------------------------------------------
    case eAPP_SD_CARD_WRITE_POSITION:

        // TODO: not implemented yet!
        AppState = eAPP_NMEA_MSG_POOL;

        break;
    //------------------------------------------------------------------------------------------------------------------
    case eAPP_WAIT_STATE:

        _assert(AppState != AppNextState);

        if(cFalse != OSIsTimerElapsed(&AppStateTimer, WaitTimeTicks))
        {
            AppState = AppNextState;
        }

        break;
    
    //------------------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------------------
    default:
        _assert(cFalse);
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

