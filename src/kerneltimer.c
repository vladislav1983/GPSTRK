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
#ifdef __KERNELTIMER_C
    #error "!!! FileName ID. It should be Unique !!!"
#else
    #define __KERNELTIMER_C
#endif

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file
 *===================================================================================================================*/
#include "kerneltimer.h"
#include "kernel.h"


/*=====================================================================================================================
 * Local constants
 *===================================================================================================================*/
#define cClockCycleInAlarmTick          (cOsTimerTickUs/cOsAlarmTickUs)
#define cMinMultiplicationValue         1

/*=====================================================================================================================
 * Local macros
 *===================================================================================================================*/
#ifdef USE_DISABLE_OSTIMER
    #define mGetMultiplier()            u8OSMultiplicationFactor
#else
    #define mGetMultiplier()            1
#endif

/*=====================================================================================================================
 * Local types
 *===================================================================================================================*/

/*=====================================================================================================================
 * Local data
 *===================================================================================================================*/
#ifdef USE_DISABLE_OSTIMER
    static tOSAlarm                     TOSAlarmTPO;
    static U8                           u8OSMultiplicationFactor;
#endif

/*=====================================================================================================================
 * Constant Local Data
 *===================================================================================================================*/

/*=====================================================================================================================
 * Constant exported data                                                     
 *===================================================================================================================*/

/*=====================================================================================================================
 * Exported Data
 *===================================================================================================================*/
tOSClock                                OSClock;

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
void OsTimerInit(void)
{
#ifndef USE_DISABLE_OSTIMER
    static tOSAlarm  Alarm;
#endif

    OSClock = 1;

    _Assert((cClockCycleInAlarmTick * cOsAlarmTickUs ) == cOsTimerTickUs);

#ifndef USE_DISABLE_OSTIMER
    Alarm.TaskID = cOsTimerTaskId;
    OsSetAlarm(&Alarm, cClockCycleInAlarmTick);
#else
    u8OSMultiplicationFactor = cMinMultiplicationValue;
    TOSAlarmTPO.TaskID = cOsTimerTaskId;
    OsSetAlarm(&TOSAlarmTPO, (tOSAlarmTick)(cClockCycleInAlarmTick * ((U32)u8OSMultiplicationFactor)));
#endif
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void OSStartTimer(tOSTimer *pTimer)
{
    *pTimer = OSClock;
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void OSStopTimer(tOSTimer *pTimer)
{
    *pTimer = 0;
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
BOOL OSIsTimerStarted(tOSTimer *pTimer)
{

    // A timer is never equal to 0
    // The 0 value is reserved to the timer stopped
    if (*pTimer != 0)
        return(1);

    return(0);
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
BOOL OSIsTimerElapsed(tOSTimer *pTimer, tOSTimer Timeout)
{
    tOSTimer Delay;

    // A timer is never equal to 0
    // The 0 value is reserved to the timer stopped
    if (*pTimer == 0)
    {
        return(1);
    }
    else
    {
        Delay = (tOSTimer)(OSClock - *pTimer);

        if(OSClock < *pTimer)
        {
            // The 0 value had been "jump" so we must substract 1 to the delay
            --Delay;
        }

        if ((Delay > Timeout) || (Timeout == 0))
        {
            // The timer is stopped
            *pTimer = 0;
            return(1);
        }
    }

    return(0);
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
tOSTimer OSGetTimerElapsedTime(tOSTimer *pTimer)
{
    tOSTimer Delay = 0;

    // A timer is never equal to 0
    // The 0 value is reserved to the timer stopped
    if ( *pTimer == 0 )
    {
        // This function must not be call with a stopped tempo
        _Assert( cFalse );
    }
    else
    {
        Delay = (tOSTimer)(OSClock - *pTimer);

        if(OSClock < *pTimer)
        {
            // The 0 value had been "jump" so we must substract 1 to the delay
            --Delay;
        }
    }

    return Delay;
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void OsTimerTask(void)
{
    OSClock += mGetMultiplier();

    if(OSClock < mGetMultiplier() )
    {
        ++OSClock;
    }
}

#ifdef USE_DISABLE_OSTIMER
/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void OSEnableTimer(U16 Period)
{
    _Assert(Period >= cMinMultiplicationValue);

    u8OSMultiplicationFactor = Period;
    TOSAlarmTPO.Period = (tOSAlarmTick)(cClockCycleInAlarmTick * ((U32)u8OSMultiplicationFactor));

    OsSetAlarm(&TOSAlarmTPO, (tOSAlarmTick)(cClockCycleInAlarmTick * ((U32)u8OSMultiplicationFactor)));
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void OSDisableTimer( void )
{
    OsCancelAlarm(&TOSAlarmTPO);
}
#endif

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

