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
#ifdef __GPS_MAIN_C
    #error "!!! FileName ID. It should be Unique !!!"
#else
    #define __GPS_MAIN_C
#endif

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file
 *===================================================================================================================*/
#include "gps_main.h"
#include "nmea_main.h"


/*=====================================================================================================================
 * Local constants
 *===================================================================================================================*/
#define cTempBufferSize             6   // Temp buffer size, enough for max message header $GPxxx
#define cNMEA_HeaderSize            cTempBufferSize
#define cMTK_HeaderSize             cTempBufferSize - 1

/*=====================================================================================================================
 * Local macros
 *===================================================================================================================*/

/*=====================================================================================================================
 * Local types
 *===================================================================================================================*/
typedef enum teGpsDispatchState
{
    eIdentMessage = 0,
    eNMEAMsgCollect
}eGpsDispatchState;

/*=====================================================================================================================
 * Local data
 *===================================================================================================================*/
static eGpsDispatchState GpsDispatchState;
static U8 au8TempBuffer[cTempBufferSize+1];
static U8 u8BuffCounter = 0;
static U8 u8CurrentBuffIndex = 0;
static U8 u8CurrentBuffSize = 0;

static U8 au8NMEA_GGA_Buff[cGPS_NMEA_GGA_BufferLen];
static U8 au8NMEA_RMC_Buff[cGPS_NMEA_RMC_BufferLen];
static U8 au8NMEA_VTG_Buff[cGPS_NMEA_VTG_BufferLen];

// Msg.Lng is used as data counter. init with zero
static tMsg GPS_MSgBuffer[cGPS_BuffersNb] = 
{
    /*0*/ {.pBuff = au8NMEA_GGA_Buff, .Lng = 0},
    /*1*/ {.pBuff = au8NMEA_RMC_Buff, .Lng = 0},
    /*2*/ {.pBuff = au8NMEA_VTG_Buff, .Lng = 0}
};


/*=====================================================================================================================
 * Constant Local Data
 *===================================================================================================================*/
const U8 cu8NMEA_GGA_HEADER[] = "$GPGGA";
const U8 cu8NMEA_RMC_HEADER[] = "$GPRMC";
const U8 cu8NMEA_VTG_HEADER[] = "$GPVTG";
const U8 cu8PMTK_HEADER[]     = "$PMTK";

/*=====================================================================================================================
 * Constant exported data                                                     
 *===================================================================================================================*/

/*=====================================================================================================================
 * Exported Data
 *===================================================================================================================*/
GpsMask GPS_STSTUS_FLAGS;

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
void __attribute__((user_init)) GPSMain_Init(void)
{
    GpsDispatchState = eIdentMessage;
    // Init UART module
    UartDrv[cGPS_UART].UartInitFct(cGPS_Baudrate, cGPS_ParityBits, cGPS_StopBits, cGPS_UartRxIntPriority, cGPS_UartTxIntPriority);
    GPS_STSTUS_FLAGS = 0;
    memset(au8TempBuffer, '\0', sizeof(au8TempBuffer));
    u8CurrentBuffIndex = cGPS_NMEA_GGA_BuffIndex;
    u8CurrentBuffSize = cGPS_NMEA_GGA_BufferLen;
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
U8 GPSMain_GetDataCnt(U8 u8GpsBuffIndex)
{
    U8 u8MsgSize;

    _EnterCriticalSection();
    u8MsgSize = GPS_MSgBuffer[u8GpsBuffIndex].Lng;
    _LeaveCriticalSection();

    return u8MsgSize;
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
HRESULT GPSMain_GetMsg(U8 u8GpsBuffIndex, tMsg Msg)
{
    HRESULT result = S_NOK;

    _EnterCriticalSection();
    if(Msg.Lng >= GPS_MSgBuffer[u8GpsBuffIndex].Lng)
    {
        memcpy(Msg.pBuff, GPS_MSgBuffer[u8GpsBuffIndex].pBuff, GPS_MSgBuffer[u8GpsBuffIndex].Lng);
        result = S_OK;
    }
    _LeaveCriticalSection();

    return result;
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void GPSMain_ClearMsgBuff(U8 u8GpsBuffIndex)
{
    _EnterCriticalSection();
    GPS_MSgBuffer[u8GpsBuffIndex].Lng = 0;
    _LeaveCriticalSection();
}

/*=====================================================================================================================
 * Parameters: 
 *
 * Return: void
 *
 * Description: Callback from UART
 *===================================================================================================================*/
void GpsMain_RxCallback(U8 u8Char)
{
    // Callback to NMEA task that char is received
    NmeaMain_RxCharCallback();

    switch(GpsDispatchState)
    {
        //-----------------------------------------------------------------------------
    case eIdentMessage:
        
        // check for '$'
        if(u8Char == cNMEAHeaserStart)
        {
            // reset buffer counter
            u8BuffCounter = 0;
        }
        else if((u8Char == '\r') || (u8Char == '\n'))
        {
            u8BuffCounter = 0;
            // fast return when CR/LF  is received
            return;
        }

        au8TempBuffer[u8BuffCounter] = u8Char;
        ++u8BuffCounter;

        if(u8BuffCounter >= cTempBufferSize)
        {
            // check message header $GPxxx or $PMTK
            if(strcmp((const char*)cu8NMEA_GGA_HEADER, (const char*)au8TempBuffer) == 0)
            {
                // it is a GGA message
                memcpy(GPS_MSgBuffer[cGPS_NMEA_GGA_BuffIndex].pBuff, au8TempBuffer, cNMEA_HeaderSize);

                u8CurrentBuffIndex = cGPS_NMEA_GGA_BuffIndex;
                u8CurrentBuffSize = cGPS_NMEA_GGA_MsgLen;

                GpsDispatchState = eNMEAMsgCollect;
            }
            else if(strcmp((const char*)au8TempBuffer, (const char*)cu8NMEA_RMC_HEADER) == 0)
            {
                // it is a RMC message
                memcpy(GPS_MSgBuffer[cGPS_NMEA_RMC_BuffIndex].pBuff, au8TempBuffer, cNMEA_HeaderSize);

                u8CurrentBuffIndex = cGPS_NMEA_RMC_BuffIndex;
                u8CurrentBuffSize = cGPS_NMEA_RMC_MsgLen;

                GpsDispatchState = eNMEAMsgCollect;
            }
            else if(strcmp((const char*)au8TempBuffer, (const char*)cu8NMEA_VTG_HEADER) == 0)
            {
                // it is a VTG message
                memcpy(GPS_MSgBuffer[cGPS_NMEA_VTG_BuffIndex].pBuff, au8TempBuffer, cNMEA_HeaderSize);

                u8CurrentBuffIndex = cGPS_NMEA_VTG_BuffIndex;
                u8CurrentBuffSize = cGPS_NMEA_VTG_MsgLen;

                GpsDispatchState = eNMEAMsgCollect;
            }
            else if(strcmp((const char*)au8TempBuffer, (const char*)cu8PMTK_HEADER) == 0)
            {
                // it is a MTK NMEA message
                // TODO: Not implemented yet
                u8BuffCounter = 0;
            }
            else
            {
                u8BuffCounter = 0;
            }
        }
        break;
        //-----------------------------------------------------------------------------
    case eNMEAMsgCollect:
        
        if(u8BuffCounter < u8CurrentBuffSize)
        {
            if((u8Char == cNMEAHeaserStart) || (u8Char == '\r') || (u8Char == '\n'))
            {
                // terminate message
                // do not count null termination character '\0'
                ((U8*)(GPS_MSgBuffer[u8CurrentBuffIndex].pBuff))[u8BuffCounter] = '\0';
                // reset state and buffer counter
                u8BuffCounter = 0;
                GpsDispatchState = eIdentMessage;
                // fast return when CR/LF  is received
                return;
            }
            else
            {
                ((U8*)(GPS_MSgBuffer[u8CurrentBuffIndex].pBuff))[u8BuffCounter] = u8Char;
                ++u8BuffCounter;
                GPS_MSgBuffer[u8CurrentBuffIndex].Lng = u8BuffCounter;
            }
        }
        else
        {
            // terminate message
            // do not count null termination character '\0'
            ((U8*)(GPS_MSgBuffer[u8CurrentBuffIndex].pBuff))[u8BuffCounter] = '\0';
            u8BuffCounter = 0;
            GpsDispatchState = eIdentMessage;
        }

        break;
        //-----------------------------------------------------------------------------
    default:
        _assert(cFalse);
        break;
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

