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
#ifdef __VTIME_C
    #error "!!! FileName ID. It should be Unique !!!"
#else
    #define __VTIME_C
#endif

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file
 *===================================================================================================================*/
#include "vtime.h"
#include "kerneltimer.h"
#include "kernelparam.h"
#include "kerneltimer.h"

/*=====================================================================================================================
 * Local constants
 *===================================================================================================================*/
#define cTimeTickPeriodUs           40E3

/*=====================================================================================================================
 * Local macros
 *===================================================================================================================*/
#define mDD(s)	((U16)(((s)[0]-'0')*10)+((U16)((s)[1]-'0')))

/*=====================================================================================================================
 * Local types
 *===================================================================================================================*/

/*=====================================================================================================================
 * Local data
 *===================================================================================================================*/
static tOSAlarm TimeTickAlarm;
static tOSTimer TimeTimer;

/*=====================================================================================================================
 * Constant Local Data
 *===================================================================================================================*/

/*=====================================================================================================================
 * Constant exported data                                                     
 *===================================================================================================================*/

/*=====================================================================================================================
 * Exported Data
 *===================================================================================================================*/
U32 u32SystemTimeSec;

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
void __attribute__((user_init)) VTime_Init(void)
{
    TimeTickAlarm.TaskID = cSysTimeTaskId;
    OsSetAlarm(&TimeTickAlarm, (cTimeTickPeriodUs/cOsAlarmTickUs));

    u32SystemTimeSec = 0;
    OSStartTimer(&TimeTimer);
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void VTime_Task(void)
{
    if(cTrue == OSIsTimerElapsed(&TimeTimer, (1000UL/(cOsTimerTickUs/1000UL))-1UL))
    {
        ++u32SystemTimeSec;
        OSStartTimer(&TimeTimer);
    }
}
/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void VTime_GpsSet_ddmmyy(U8 *pu8ddmmyy, tNMEA_GPS_Data *GpsData)
{
    // 241012 - date 24.10.2012
    if(GpsData->DateTime.tm_year == 0)
    {
        GpsData->DateTime.tm_year = ((2000U + mDD(pu8ddmmyy+4)));
    }
    GpsData->DateTime.tm_mon = (mDD(pu8ddmmyy+2)-1U); /*month ( 0 to 11 where January = 0 )*/
    GpsData->DateTime.tm_mday = mDD(pu8ddmmyy);
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void VTime_GpsSet_hhmmss(U8 *pu8hhmmss, tNMEA_GPS_Data *GpsData)
{
    U16 u16OldHour = GpsData->DateTime.tm_hour;

    GpsData->DateTime.tm_hour = mDD(pu8hhmmss);
    if(GpsData->DateTime.tm_hour < u16OldHour)
    {
        GpsData->DateTime.tm_mday++;    // midnight wrap
    }
    GpsData->DateTime.tm_min = mDD(pu8hhmmss+2);
    GpsData->DateTime.tm_sec = mDD(pu8hhmmss+4);
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
