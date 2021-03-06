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
#ifdef __APRS_C
    #error "!!! FileName ID. It should be Unique !!!"
#else
    #define __APRS_C
#endif

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file
 *===================================================================================================================*/
#include "aprs.h"
#include "kernelinclude.h"
#include "tools.h"
#include "devconfig.h"
#include "gps_main.h"
#include "nmea_main.h"
#include "ax25.h"
#include "measure.h"
#include "ax25_crc.h"
#include "comparator.h"

/*=====================================================================================================================
 * Local constants
 *===================================================================================================================*/
#define cAPRS_BufferSize                        128UL

// Refer the APRS specification "aprs101.pdf" http://www.aprs.org => ax25 externsion
#define cAprs_Flag                              0x7E    // The flag field at each end of the frame is the bit sequence 0x7e that separates each frame.
#define cAprs_ControlField_UI                   0x03    // This field is set to 0x03 (UI-frame).
#define cAprs_Protocol_ID                       0xF0    // This field is set to 0xf0 (no layer 3 protocol).
// APRS data type (packet) identifiers "5 APRS DATA IN THE AX.25 INFORMATION FIELD"
#define cAprs_PID_Pos_wo_timestamp_no_aprs      '!'
#define cAprs_PID_Status                        '>'
#define cAprs_PID_Message                       ':'
#define cAprs_PID_Pos_wo_timestamp_aprs         '='
#define cAprs_PID_Pos_with_timestamp_aprs       '@'

#define cAprsTaskPeriod_us                      40E3
#define cAprs_TxTimeout_us                      1000E3
#define cAprs_AnotherStationTx_us               400E3

/*=====================================================================================================================
 * Local macros
 *===================================================================================================================*/
#if !defined(APRS_MSG_DEBUG)
    #define _AprsGetChar(ch)                    (((ch) << 1) & 0xFE)
#else
    #define _AprsGetChar(ch)                    (ch)
#endif
#define _AprsTerminateField(ch)                 ((ch) = ((ch) + 1))

/*=====================================================================================================================
 * Local types
 *===================================================================================================================*/
typedef enum teAprsTrmtState
{
    eAprs_TRMT_ANOTHER_STATION_TX_CHECK,
    eAprs_TRMT_SET_PTT,
    eAprs_TRMT_TRANSMIT,
    eAPRS_TRMT_WAIT_PTT,
    eAPRS_TRMT_WAIT_ONE_TASK_PERIOD,
    eAPRS_TRMT_WAIT_ANOTHER_STATION,
    eAPRS_IDLE
}tAprsTrmtState;

/*=====================================================================================================================
 * Local data
 *===================================================================================================================*/
static U8 au8AprsBuff[cAPRS_BufferSize];
static U8  u8Propath;
static tAprsTrmtState AprsTrmtState = eAPRS_IDLE;
static tOSAlarm AprsTaskAlarm;
static tOSTimer AprsTimer;
static tOSTimer AprsTimeoutTimer;
static tControl AprsTxType;
static BOOL bAnotherStationTx;

/*=====================================================================================================================
 * Constant Local Data
 *===================================================================================================================*/
static const U8 au8AprsWidePath[] = "WIDE";
static const U8 au8AprsAltitudeHeader[] = "/A=";

/*=====================================================================================================================
 * Constant exported data                                                     
 *===================================================================================================================*/

/*=====================================================================================================================
 * Exported Data
 *===================================================================================================================*/

/*=====================================================================================================================
 * Local Functions Prototypes
 *===================================================================================================================*/
static HRESULT Aprs_Transmit(BOOL Control);


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
void Arps_Init(void)
{
    memset(&au8AprsBuff[0], 0, sizeof(au8AprsBuff));
    u8Propath         = 0;
    AprsTrmtState     = eAPRS_IDLE;
    AprsTxType        = cAprs_NotTransmit;
    bAnotherStationTx = cFalse;

    AprsTaskAlarm.TaskID = cAprsTaskId;
    OsSetAlarm(&AprsTaskAlarm, (cAprsTaskPeriod_us/cOsAlarmTickUs));

    // Config PTT pin as open drain
    _DioWritePin(cDioPin_PTT, 1);
    _DioPinOpenDrainConfig(cDioPin_PTT, cPinOpenDrainMode);
    _DioPinConfig(cDioPin_PTT, cPinModeOutput);
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void Aprs_Task(void)
{
    switch(AprsTrmtState)
    {
    //------------------------------------------------------------------------------------------------------------------
    case eAPRS_IDLE:
        
        if((cAPRS_TransmitTrackerInfo == AprsTxType) || (cAPRS_TransmitData == AprsTxType))
        {
            bAnotherStationTx = cFalse;
            AprsTrmtState     = eAPRS_TRMT_WAIT_ONE_TASK_PERIOD;
        }

        break;
    //------------------------------------------------------------------------------------------------------------------
    case eAprs_TRMT_ANOTHER_STATION_TX_CHECK:

        if((cFalse == bAnotherStationTx))
        {
            _DioWritePin(cDioPin_AnotherStatTxLed, 0);
            AprsTrmtState = eAprs_TRMT_SET_PTT;
            Cmp_Control(cCtrl_Stop);
        }
        else if(cFalse != OSIsTimerElapsed(&AprsTimeoutTimer, (cAprs_TxTimeout_us/cOsTimerTickUs)))
        {
            _DioWritePin(cDioPin_AnotherStatTxLed, 0);
            App_Statemachine_AprsMsgTxCallback(cCallbackCtrlError);
            Cmp_Control(cCtrl_Stop);
            AprsTxType = cAprs_NotTransmit;
            AprsTrmtState = eAPRS_IDLE;
        }
        else
        {
            _DioWritePin(cDioPin_AnotherStatTxLed, 1);
            bAnotherStationTx = cFalse;
            OSStartTimer(&AprsTimer);
            AprsTrmtState = eAPRS_TRMT_WAIT_ANOTHER_STATION;
        }

        break;
    //------------------------------------------------------------------------------------------------------------------
    case eAprs_TRMT_SET_PTT:

        _DioWritePin(cDioPin_PTT, 0);
        AprsTrmtState = eAPRS_TRMT_WAIT_PTT;

        break;
    //------------------------------------------------------------------------------------------------------------------
    case eAPRS_TRMT_WAIT_PTT:

        AprsTrmtState = eAprs_TRMT_TRANSMIT;

        break;
    //------------------------------------------------------------------------------------------------------------------
    case eAprs_TRMT_TRANSMIT:

        _DioWritePin(cDioPin_AnotherStatTxLed, 0);
        // transmit APRS info message. 
        (void)Aprs_Transmit(AprsTxType);
        AprsTrmtState = eAPRS_IDLE;

        break;
    //------------------------------------------------------------------------------------------------------------------
    case eAPRS_TRMT_WAIT_ONE_TASK_PERIOD:

        OSStartTimer(&AprsTimeoutTimer);
        Cmp_Control(cCtrl_Start);
        AprsTrmtState = eAprs_TRMT_ANOTHER_STATION_TX_CHECK;

        break;
    //------------------------------------------------------------------------------------------------------------------
    case eAPRS_TRMT_WAIT_ANOTHER_STATION:

        if(cFalse != OSIsTimerElapsed(&AprsTimer, (cAprs_AnotherStationTx_us/cOsTimerTickUs)))
        {
            AprsTrmtState = eAprs_TRMT_ANOTHER_STATION_TX_CHECK;
        }


        break;
    //------------------------------------------------------------------------------------------------------------------
    default:
        _assert(cFalse);
        Cmp_Control(cCtrl_Stop);
        AprsTrmtState = eAPRS_IDLE;
        AprsTxType = cAprs_NotTransmit;

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
void Aprs_TransmitCallback(tCtrl Ctrl)
{
    if(Ctrl == cCallbackCtrlOK)
    {
        App_Statemachine_AprsMsgTxCallback(cCallbackCtrlOK);
    }
    else if(Ctrl == cCallbackCtrlError)
    {
        App_Statemachine_AprsMsgTxCallback(cCallbackCtrlError);
    }
    else
    {
        _assert(cFalse);
    }

    // immediately clear PTT pin in any case
    _DioWritePin(cDioPin_PTT, 1);
    AprsTrmtState = eAPRS_IDLE;
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void Aprs_Control(tControl Control)
{
    _assert(   Control == cAPRS_TransmitTrackerInfo 
            || Control == cAPRS_TransmitData
            || Control == cAprs_NotTransmit);


    AprsTxType = Control;
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void Aprs_AnotherStationTxCallback(void)
{
    bAnotherStationTx = cTrue;
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
static HRESULT Aprs_Transmit(tControl Control)
{
    HRESULT res = S_NOK;
    U16 u16Idx;
    U16 u16DataIndex = 0;
    tMsg Msg;
    U16 u16Checksum;
    F32 f32Tmp;

    // Don't do proportional pathing if 255
    if(DeviceConfigParams.u8ConfAprsPropath == 0xFFu)
    {
        u8Propath = 3;
    }
    else if(DeviceConfigParams.u8ConfAprsPropath == u8Propath)
    {
        u8Propath = 0;
    }
    else
    {
        u8Propath++;
    }

    //u8Propath = DeviceConfigParams.u8ConfAprsPropath;

    AX25_Control(cAX25CtrlStop);

    //  AX.25 UI-FRAME FORMAT
    //      ___________________________________________________________________________________________________________
    //     |       | Flag | Destination  | Source  | Digipeater | Control | Protocol |  INFORMATION FIELD | FCS | Flag |
    //     |       |      |   Address    | Address | Addresses  |  Field  |    ID    |                    |     |      |
    //     |       |      |              |         |    (0-8)   |   (UI)  |          |                    |     |      |
    //     |Bytes: |  1   |      7       |    7    |    0�56    |    1    |     1    |       1�256        |  2  |   1  |
    //     |___________________________________________________________________________________________________________|

    // destination
    for (u16Idx = 0; 
        (u16Idx < (sizeof(DeviceConfigParams.u8ConfigAprsDestAddr)-1)) && (DeviceConfigParams.u8ConfigAprsDestAddr[u16Idx] != '\0'); 
         u16Idx++)
    {
        au8AprsBuff[u16DataIndex] = _AprsGetChar(DeviceConfigParams.u8ConfigAprsDestAddr[u16Idx]);
        u16DataIndex++;
    }
    // source
    for( u16Idx = 0; 
        (u16Idx < (sizeof(DeviceConfigParams.u8ConfigAprsSourceAddr)-1)) && (DeviceConfigParams.u8ConfigAprsSourceAddr[u16Idx] != '\0');
         u16Idx++)
    {
        au8AprsBuff[u16DataIndex] = _AprsGetChar(DeviceConfigParams.u8ConfigAprsSourceAddr[u16Idx]);
        u16DataIndex++;
    }
    
    // terminate address field (src/dest) if proportional path = 0 => absolute addressing without repeating
    if(u8Propath == 0)
    {
        _AprsTerminateField(au8AprsBuff[u16DataIndex-1]);
    }
    // first digipeater
    if(u8Propath >= 1)
    {
        for( u16Idx = 0;
            (u16Idx < (sizeof(DeviceConfigParams.u8ConfigAprsDigipeater)-1)) && (DeviceConfigParams.u8ConfigAprsDigipeater[u16Idx] != '\0');
             u16Idx++)
        {
            au8AprsBuff[u16DataIndex] = _AprsGetChar(DeviceConfigParams.u8ConfigAprsDigipeater[u16Idx]);
            u16DataIndex++;
        }
    }

    // digipeater fill => hoping of type WIDEn-N
    if((u8Propath >= 2) && (u8Propath <= 7)) // two or more hopes
    {
        // copy "WIDE"
        for(u16Idx = 0; u16Idx < (sizeof(au8AprsWidePath)-1); u16Idx++)
        {
            au8AprsBuff[u16DataIndex] = _AprsGetChar(au8AprsWidePath[u16Idx]);
            u16DataIndex++;
        }

        // copy propath
        au8AprsBuff[u16DataIndex] = _AprsGetChar(u8Propath + '0');
        u16DataIndex++;
        au8AprsBuff[u16DataIndex] = _AprsGetChar(' ');
        u16DataIndex++;
        au8AprsBuff[u16DataIndex] = _AprsGetChar(u8Propath + '0');
        u16DataIndex++;
    }

    // terminate digipeater field
    _AprsTerminateField(au8AprsBuff[u16DataIndex - 1u]);
    
    // control field
    au8AprsBuff[u16DataIndex] = cAprs_ControlField_UI;
    u16DataIndex++;
    // protocol ID
    au8AprsBuff[u16DataIndex] = cAprs_Protocol_ID;
    u16DataIndex++;

    if(Control == cAPRS_TransmitData)
    {
        au8AprsBuff[u16DataIndex] = cAprs_PID_Pos_wo_timestamp_no_aprs;
        u16DataIndex++;

        // copy latitude
        memcpy((U8*)&au8AprsBuff[u16DataIndex], NMEA_GPS_Data.AX25_GPS_Data.u8Latitude, sizeof(NMEA_GPS_Data.AX25_GPS_Data.u8Latitude));
        u16DataIndex += sizeof(NMEA_GPS_Data.AX25_GPS_Data.u8Latitude);

        // symbol table => primary/secondary
        au8AprsBuff[u16DataIndex] = DeviceConfigParams.u8ConfAprsSymbolTable;   //'/';
        u16DataIndex++;

        // copy longitude
        memcpy((U8*)&au8AprsBuff[u16DataIndex], NMEA_GPS_Data.AX25_GPS_Data.u8Longitude, sizeof(NMEA_GPS_Data.AX25_GPS_Data.u8Longitude));
        u16DataIndex += sizeof(NMEA_GPS_Data.AX25_GPS_Data.u8Longitude);

        // symbol => car, bike, helicopter ... etc
        au8AprsBuff[u16DataIndex] = DeviceConfigParams.u8ConfAprsSymbol;
        u16DataIndex++;

        // course
        memcpy((U8*)&au8AprsBuff[u16DataIndex], NMEA_GPS_Data.AX25_GPS_Data.u8Course, sizeof(NMEA_GPS_Data.AX25_GPS_Data.u8Course));
        u16DataIndex += sizeof(NMEA_GPS_Data.AX25_GPS_Data.u8Course);
        
        au8AprsBuff[u16DataIndex] = '/';
        u16DataIndex++;

        // speed
        memcpy((U8*)&au8AprsBuff[u16DataIndex], NMEA_GPS_Data.AX25_GPS_Data.u8Speed, sizeof(NMEA_GPS_Data.AX25_GPS_Data.u8Speed));
        u16DataIndex += sizeof(NMEA_GPS_Data.AX25_GPS_Data.u8Speed);

        // altitude
        memcpy((U8*)&au8AprsBuff[u16DataIndex], au8AprsAltitudeHeader, (sizeof(au8AprsAltitudeHeader)-1));
        u16DataIndex += (sizeof(au8AprsAltitudeHeader)-1);
        memcpy((U8*)&au8AprsBuff[u16DataIndex], NMEA_GPS_Data.AX25_GPS_Data.u8Altitude, sizeof(NMEA_GPS_Data.AX25_GPS_Data.u8Altitude));
        u16DataIndex += sizeof(NMEA_GPS_Data.AX25_GPS_Data.u8Altitude);

        // set battery voltage text => _YY.XV Note: "_" is space
        f32Tmp = (F32)u16BatteryVoltage_mv / 1000UL;
        u16DataIndex += sprintf((char*)&au8AprsBuff[u16DataIndex], " %2.1fV", f32Tmp);
    
        // set temperature text => _YY.XC Note: "_" is space
        f32Tmp = (F32)u16Tmperature_x10 / 10UL;
        u16DataIndex +=sprintf((char*)&au8AprsBuff[u16DataIndex], " %2.1fC", f32Tmp);

        // TODO: beacon text
    } 
    else if(Control == cAPRS_TransmitTrackerInfo)
    {
        au8AprsBuff[u16DataIndex] = cAprs_PID_Status;
        u16DataIndex++;

        // copy tracker version. note that it is null terminated string
        for( u16Idx = 0;
            (u16Idx < (sizeof(DeviceConfigParams.u8ConfigTrackerVersion)-1u)) && (DeviceConfigParams.u8ConfigTrackerVersion[u16Idx] != '\0');
             u16Idx++)
        {
            au8AprsBuff[u16DataIndex] = DeviceConfigParams.u8ConfigTrackerVersion[u16Idx];
            //(_AprsGetChar(DeviceConfigParams.u8ConfigTrackerVersion[u16Idx]) >> 1u);
            u16DataIndex++;
        }
    }
    else
    {
        _assert(cFalse);
    }

    u16Checksum = Crc_Ax25Calc(&au8AprsBuff[0], u16DataIndex);

    // fill checksum. low byte first
    au8AprsBuff[u16DataIndex] = (U8)(u16Checksum & 0x00FF);
    u16DataIndex++;
    au8AprsBuff[u16DataIndex] = (U8)((u16Checksum >> 8) & 0x00FF);
    u16DataIndex++;

    // set transmit data and count
    Msg.pBuff = &au8AprsBuff[0];
    Msg.Lng = u16DataIndex;

    if(S_OK == AX25_SendData(Msg))
    {
        AX25_Control(cAX25CtrlStartTrmt);
        res = S_OK;
    }

    return res;
}





