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
#ifdef __NMEA_PROCESS_C
    #error "!!! FileName ID. It should be Unique !!!"
#else
    #define __NMEA_PROCESS_C
#endif

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file
 *===================================================================================================================*/
#include "nmea_process.h"
#include "nmea_main.h"
#include "vtime.h"
#include "devconfig.h"


/*=====================================================================================================================
 * Local constants
 *===================================================================================================================*/
#define cMinDecayInSeconds                  8u
#define cMaxInfoBeaconIntervalSec           1800u
#define cTurnThresholdMaxDeg                80u
#define cAprsDataTransmitTimeshift_sec      cMinDecayInSeconds/2u

/*
* smart beaconing params
*/
#define cSbTurnMinimum_deg          20u     // cSbTurnMinimum_deg   Minimum degrees at which corner pegging will occur.  
                                            //                      The next parameter affects this for lower speeds.
#define cSbTurnSlope                25u     // cSbTurnSlope         Fidget factor for making turns less sensitive at
                                            //                      lower speeds.  No real units on this one.
                                            //                      It ends up being non-linear over the speed
                                            //                      range the way the original SmartBeaconing(tm)algorithm works.
#define cSbTurnTime_sec             5u      // cSbTurnTime_sec      Dead-time before/after a corner peg beacon.
                                            //                      Units are in seconds.

/*=====================================================================================================================
 * Local macros
 *===================================================================================================================*/

/*=====================================================================================================================
 * Local types
 *===================================================================================================================*/

/*=====================================================================================================================
 * Local data
 *===================================================================================================================*/
static U16 u16AprsSystemTimeStamp;
static U16 u16AprsBeaconDecay;
static U16 u16AprsBeaconingDownCounter;
/*=====================================================================================================================
 * Constant Local Data
 *===================================================================================================================*/
static tSmartBeaconingRef AprsSmartBeaconingRef = cAprsSmartBeaconingRef();
static tSmartBeaconingRef GpxSmartBeaconingRef = cGpxSmartBeaconingRef();

/*=====================================================================================================================
 * Constant exported data                                                     
 *===================================================================================================================*/

/*=====================================================================================================================
 * Exported Data
 *===================================================================================================================*/

/*=====================================================================================================================
 * Local Functions Prototypes
 *===================================================================================================================*/
static BOOL NmeaProc_SmartBeaconing(tNMEA_GPS_Data *GpsData, tSmartBeaconingRef *SbRefData);

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
void NMEAProc_Init(void)
{
    u16AprsSystemTimeStamp = 0;
    u16AprsBeaconDecay = cMinDecayInSeconds;
    u16AprsBeaconingDownCounter = cMinDecayInSeconds;
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
tAprsTrmtCmd NMEAProc_AprsProcessingTransmit(tNMEA_GPS_Data *GpsData)
{
    U16 u16CurrentSystemTimeL;
    tAprsTrmtCmd BeaconTypeSend = cAprsProcNotSend;

    /* status packets are transmitted by the tracker using the STANDARD APRS
	 * DECAY DESIGN... that is, the packet is transmitted immediately, then
	 * 8 seconds later, then 16, then 32, then 64, then 2 mins then 4 mins,
	 * then 8 mins and then 16 mins and then 30 mins. Thus there is excellent
	 * probability that the packet is delivered quickly, but then there is
	 * redundancy in case of collisions. */

    // get system time in seconds
    u16CurrentSystemTimeL = VTime_GetSystemTick();

    if(u16AprsBeaconingDownCounter < (U16)(u16CurrentSystemTimeL - u16AprsSystemTimeStamp))
    {
        // send tracker info
        BeaconTypeSend = cAprsProcSendTrackerInfo;

        // beacon decay multiplier ^2
        u16AprsBeaconDecay *= 2u;
        if(u16AprsBeaconDecay >= cMaxInfoBeaconIntervalSec)
            u16AprsBeaconDecay = cMaxInfoBeaconIntervalSec;

        u16AprsBeaconingDownCounter = u16AprsBeaconDecay;
        // update system time
        u16AprsSystemTimeStamp = u16CurrentSystemTimeL;
    }
    else
    {
        if((u16AprsSystemTimeStamp != 0ul) && ((u16AprsSystemTimeStamp + cAprsDataTransmitTimeshift_sec) == u16CurrentSystemTimeL))
        {
            // send data with period = info period + ime shift
            // this is by default to set first location even if you are not moving
            BeaconTypeSend = cAprsProcSendData;
            // reset beacon time rate
            AprsSmartBeaconingRef.u16BeaconTimeStamp = u16CurrentSystemTimeL;
        }
        else
        {
            // smart beaconing will produce transmission
            if(cFalse != NmeaProc_SmartBeaconing(GpsData, &AprsSmartBeaconingRef))
                BeaconTypeSend = cAprsProcSendData;
        }
    }

    return BeaconTypeSend;
}
/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
BOOL NMEAProc_PositioningWriteProcess(tNMEA_GPS_Data *GpsData)
{
    BOOL bPosWrite = cFalse;

    bPosWrite = NmeaProc_SmartBeaconing(GpsData, &GpxSmartBeaconingRef);

    return bPosWrite;
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
static BOOL NmeaProc_SmartBeaconing(tNMEA_GPS_Data *GpsData, tSmartBeaconingRef *SbRefData)
{
    U16  u16BeaconTimeStampL;
    U16  u16Seconds;
    BOOL bBeaconSend      = cFalse;
    U16  u16Speed         = GpsData->u16GpsSpeed;
    U16  s16CurrentCourse = GpsData->u16GpsCouse;
    
    /* Code to compute SmartBeaconing(tm) rates. (borrowed from Xastir)
	 *
	 * SmartBeaconing(tm) was invented by Steve Bragg (KA9MVA) and
	 * Tony Arnerich (KD7TA).
	 * Its main goal is to change the beacon rate based on speed
	 * and cornering.  It does speed-variant corner pegging and
	 * speed-variant posit rate.
	 *
	 * Several special SmartBeaconing(tm) parameters come into play here:
	 *
	 * cSbTurnMinimum_deg                   Minimum degrees at which corner pegging will
	 *                                      occur.  The next parameter affects this for
	 *                                      lower speeds.
	 *
	 * cSbTurnSlope                         Fidget factor for making turns less sensitive at
	 *                                      lower speeds.  No real units on this one.
	 *                                      It ends up being non-linear over the speed
	 *                                      range the way the original SmartBeaconing(tm)
	 *                                      algorithm works.
	 *
	 * cSbTurnTime_sec                      Dead-time before/after a corner peg beacon.
	 *                                      Units are in seconds.
	 *
	 * u8ConfAprsSbPositFast_sec         Fast posit rate, used if >= sb_high_speed_limit.
	 *                                      Units are in seconds.
	 *
	 * u8ConfAprsSbPositSlow_min         Slow posit rate, used if <= sb_low_speed_limit.
	 *                                      Units are in minutes.
	 *
	 * u8ConfAprsSbLowSpeedLimit_kmh    Low speed limit
	 *
	 * u8ConfAprsSbHighSpeedLimit_kmh   High speed limit
	 */

    u16BeaconTimeStampL = VTime_GetSystemTick();

    // do smart beaconing if beacon interval = 0 sec
    if (*SbRefData->pu16SbInterval_sec != 0)
    {
        if(*SbRefData->pu16SbInterval_sec < (U16)(u16BeaconTimeStampL - SbRefData->u16BeaconTimeStamp))
        {
            bBeaconSend = cTrue;
            SbRefData->u16BeaconTimeStamp = u16BeaconTimeStampL;
        }
    }
    else
    {
        if(u16Speed <= *SbRefData->pu8SbLowSpeedLimit_kmh)
        {
            // set slow position rate
            SbRefData->u16SmartBeaconingRateSec = (U16)*SbRefData->pu8SbPositSlow_min * 60u;

            // Reset s16CourseChangeSinceBeacon to avoid cyclic 
			// triggering of beacon_now when we suddenly drop below the low speed limit.
            SbRefData->s16CourseChangeSinceBeacon = 0;
        }
        else
        {
            // We're moving faster than the low speed limit
            // Start with turn_min degrees as the threshold
            SbRefData->u8TurnThreshold = cSbTurnMinimum_deg;

            // Adjust rate according to speed
            if(u16Speed > *SbRefData->pu8SbHighSpeedLimit_kmh)
            {
                // We're above the high limit
                SbRefData->u16SmartBeaconingRateSec = *SbRefData->pu8SbPositFast_sec;
            } 
            else
            {
                // We're between the high/low limits. Set a between rate
                SbRefData->u16SmartBeaconingRateSec = ((U16)*SbRefData->pu8SbPositFast_sec * (U16)*SbRefData->pu8SbHighSpeedLimit_kmh) / u16Speed;
                // Adjust turn threshold according to speed
                SbRefData->u8TurnThreshold += (U8)(((U16)cSbTurnSlope * 10u) / u16Speed);
            }

            // Force a maximum turn threshold of 80 degrees 
            if(SbRefData->u8TurnThreshold > cTurnThresholdMaxDeg)
                SbRefData->u8TurnThreshold = cTurnThresholdMaxDeg;

            // Check to see if we've written anything into sb_last_heading variable yet.  If not, write the current course into it.
            if(SbRefData->s16LastCourse == -1)
                SbRefData->s16LastCourse = s16CurrentCourse;

            // Corner-pegging.  Note that we don't corner-peg if we're
            // below the low-speed threshold.
            SbRefData->s16CourseChangeSinceBeacon = s16CurrentCourse - SbRefData->s16LastCourse;

            if(SbRefData->s16CourseChangeSinceBeacon < 0)
                SbRefData->s16CourseChangeSinceBeacon = SbRefData->s16LastCourse - s16CurrentCourse;

            if(SbRefData->s16CourseChangeSinceBeacon > 180u)
                SbRefData->s16CourseChangeSinceBeacon = 360u - SbRefData->s16CourseChangeSinceBeacon;

            u16Seconds = u16BeaconTimeStampL - SbRefData->u16BeaconTimeStamp;

            // sneaky condition, but needed
            if( (    (SbRefData->s16CourseChangeSinceBeacon > SbRefData->u8TurnThreshold) 
                  && (u16Seconds > cSbTurnTime_sec)
                )
                  || (u16Seconds > SbRefData->u16SmartBeaconingRateSec)
              )
            {
                bBeaconSend = cTrue;
                SbRefData->s16LastCourse = s16CurrentCourse;
                SbRefData->u16BeaconTimeStamp = u16BeaconTimeStampL;
            }
        }
    }

    return bBeaconSend;
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
