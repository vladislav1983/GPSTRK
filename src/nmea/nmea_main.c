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
#ifdef __NMEA_MAIN_C
    #error "!!! FileName ID. It should be Unique !!!"
#else
    #define __NMEA_MAIN_C
#endif

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file
 *===================================================================================================================*/
#include <ctype.h>
#include "nmea_main.h"

#include "alarm.h"
#include "kernelinclude.h"


/*=====================================================================================================================
 * Local constants
 *===================================================================================================================*/
#define cNMEAMainTaskPeruidUs           10000UL
#define cNMEACommTimeoutUs              100000UL
#define cNMEAProcessingTimeoutUs        700000UL


/*=====================================================================================================================
 * Local macros
 *===================================================================================================================*/

/*=====================================================================================================================
 * Local types
 *===================================================================================================================*/
typedef enum teNmeaDecodeState
{
    eNMEA_DECODE_WAIT_DATA = 0,
    eNMEA_DECODE_PROCESSING
}eNmeaDecodeState;
/*=====================================================================================================================
 * Local data
 *===================================================================================================================*/
static tOSAlarm         NMEADecodeTaskAlarm;
static tOSTimer         NMEADecodeCommTimeout;
static eNmeaDecodeState NmeaDecodeState;
static U8               u8NmeaDecMsgCounter;
static U8               u8TempBuffer[cNMEATempBufferSize];
static U8              *pu8NmeaFields[cNMEAMaxFieldLen];

/*=====================================================================================================================
 * Constant Local Data
 *===================================================================================================================*/

/*=====================================================================================================================
 * Constant exported data                                                     
 *===================================================================================================================*/

/*=====================================================================================================================
 * Exported Data
 *===================================================================================================================*/
tNmeaDecoders NmeaDecoders[cGPS_BuffersNb] = cNMEADecodersInit();
tNMEA_GPS_Data NMEA_GPS_Data;

/*=====================================================================================================================
 * Local Functions Prototypes
 *===================================================================================================================*/
static HRESULT NMEAMain_MsgDecode(U8 u8MsgIndex);
static HRESULT NMEAMain_ChecksumCheck(tMsg Msg);
static U16     NMEAMain_MessageTrim(tMsg Msg);


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
void NMEAMain_Init(void)
{

    NMEADecodeTaskAlarm.TaskID = cNMEAMainDecodeTaskID;
    OsSetAlarm(&NMEADecodeTaskAlarm, (cNMEAMainTaskPeruidUs/cOsAlarmTickUs));

    NmeaDecodeState = eNMEA_DECODE_WAIT_DATA;
    u8NmeaDecMsgCounter = 0;
    memset((U8*)(void*)&NMEA_GPS_Data.AX25_GPS_Data, '0', sizeof(NMEA_GPS_Data.AX25_GPS_Data));
    NMEA_GPS_Data.u8GpsFixStatus = cGPS_STATUS_NO_FIX;
    NMEA_GPS_Data.u8GpsMode = cGPS_MODE_MODE_NOT_SEEN;
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void NMEAMain_DecodeTask(void)
{
    U16 u16Index;
    tMsg Msg;

    if(    (cFalse != OSIsTimerStarted(&NMEADecodeCommTimeout))
        && (cFalse != OSIsTimerElapsed(&NMEADecodeCommTimeout, (cNMEACommTimeoutUs/cOsTimerTickUs))))
    {
        OSStopTimer(&NMEADecodeCommTimeout);

        // Decode GPS messages
        for(u16Index = 0; u16Index < cGPS_BuffersNb; u16Index++)
        {
            (void)NMEAMain_MsgDecode(u16Index);
        }

        Msg.pBuff = (U8*)&GPS_STSTUS_FLAGS;
        Msg.Lng = sizeof(GPS_STSTUS_FLAGS);

        AppStatemachine_GpsMsgReceivedCallback(Msg);
        GPS_STSTUS_FLAGS = 0;
        
        _DioTogglePin(cDioPin_GpsLed);
    }
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void NmeaMain_RxCharCallback(void)
{
    OSStartTimer(&NMEADecodeCommTimeout);
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
static HRESULT NMEAMain_MsgDecode(U8 u8MsgIndex)
{
    HRESULT result = S_NOK;
    U8 u8CurrentBuffIndex = NmeaDecoders[u8MsgIndex].u8BufferIndex;
    U8 u8CurrentBuffSize  = NmeaDecoders[u8MsgIndex].u8BufferSize;
    tMsg Msg;
    U16 u16MsgFieldsCount;

    // verify buffer size
    //if(u8CurrentBuffSize == GPSMain_GetDataCnt(u8CurrentBuffIndex))
    {
        // get buffer
        Msg.pBuff = &u8TempBuffer[0];
        Msg.Lng = u8CurrentBuffSize;

        if(S_OK ==  GPSMain_GetMsg(u8CurrentBuffIndex, Msg))
        {
            // verify checksum
            if(S_OK == NMEAMain_ChecksumCheck(Msg))
            {
                // trim message - remove unusable information
                u16MsgFieldsCount = NMEAMain_MessageTrim(Msg);

                if( (pu8NmeaFields[0] != NULL) && (u16MsgFieldsCount >= NmeaDecoders[u8MsgIndex].uMsgFieldsNumber) )
                {
                    // decode message
                    GPS_STSTUS_FLAGS |= NmeaDecoders[u8MsgIndex].NmeaDecoder(&pu8NmeaFields[0], &NMEA_GPS_Data, GPS_STSTUS_FLAGS);
                    result = S_OK;
                }
            }

            // flush buffer
            GPSMain_ClearMsgBuff(u8CurrentBuffIndex);
        }
    }

    return result;
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
static HRESULT NMEAMain_ChecksumCheck(tMsg Msg)
{
    HRESULT result = S_NOK;
    U8* pu8BuffPtrL = Msg.pBuff;
    U8 u8CalculatedChecksum = '\0';
    U8 u8Char;
    U8 u8CalcChecksumString[3]; // 2 character checksum + '\0'

    if( (*pu8BuffPtrL == '$') && (Msg.Lng != 0) )
    {
        // first increment to skip '$'
        pu8BuffPtrL++;
        u8Char = *pu8BuffPtrL;

        while( ((u8Char)!= '*') && (u8Char != '\0') )
        {
            u8CalculatedChecksum ^= u8Char;
            pu8BuffPtrL++;
            u8Char = *pu8BuffPtrL;
        }

        // skip '*'
		pu8BuffPtrL++;
		
        (void)sprintf((char *)u8CalcChecksumString, "%02X", u8CalculatedChecksum);
        
        if(    (u8CalcChecksumString[0] == toupper(pu8BuffPtrL[0])) 
            && (u8CalcChecksumString[1] == toupper(pu8BuffPtrL[1])) )
        {
            result = S_OK;
        }
    }

    return result;
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: number of NMEA message fields
 *
 * Description: 
 *===================================================================================================================*/
static U16 NMEAMain_MessageTrim(tMsg Msg)
{
    U8 *pu8Buff;
    U16 u16Count;

    // discard checksum field
    for(pu8Buff = (U8*)Msg.pBuff; ((*pu8Buff != '*') && (*pu8Buff >= ' ')); ++pu8Buff);

    *pu8Buff = '\0';

    // slit message - filling the field array
    for(  u16Count = 0, pu8Buff = (U8*)Msg.pBuff; 
        ((pu8Buff != NULL) && (pu8Buff != '\0') && (u16Count < cNMEAMaxFieldLen)); 
        ++u16Count, pu8Buff = (U8*)strchr((const char *)pu8Buff, ','))
    {
        *pu8Buff = '\0';
        ++pu8Buff;
        pu8NmeaFields[u16Count] = pu8Buff;
    }

    return u16Count;
}
