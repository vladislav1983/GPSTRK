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
#ifdef __TIMER_C
    #error "!!! FileName ID. It should be Unique !!!"
#else
    #define __TIMER_C
#endif

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file
 *===================================================================================================================*/
#include "timer.h"
#include "alarm.h"
#include "kernelparam.h"


/*=====================================================================================================================
 * Local constants
 *===================================================================================================================*/
/* Timer1 Control Register (T1CON) Bit Defines */
#define T1_ON               0xffff      /* Timer1 ON */
#define T1_OFF              0x7fff      /* Timer1 OFF */

#define T1_IDLE_CON         0xdfff      /* operate during sleep */
#define T1_IDLE_STOP        0xffff      /* stop operation during sleep */

#define T1_GATE_ON          0xffff      /* Timer Gate time accumulation enabled */
#define T1_GATE_OFF         0xffbf      /* Timer Gate time accumulation disabled */

#define T1_PS_1_1           0xffcf      /* Prescaler 1:1 */
#define T1_PS_1_8           0xffdf      /*           1:8 */
#define T1_PS_1_64          0xffef      /*          1:64 */
#define T1_PS_1_256         0xffff      /*         1:256 */

#define T1_SYNC_EXT_ON      0xffff      /* Synch external clk input */
#define T1_SYNC_EXT_OFF     0xfffb      /* Do not synch external clk input */

#define T1_SOURCE_EXT       0xffff      /* External clock source */
#define T1_SOURCE_INT       0xfffd      /* Internal clock source */

/* Timer2 Control Register (T2CON) Bit Defines */
#define T2_ON               0xffff      /* Timer2 ON */
#define T2_OFF              0x7fff      /* Timer2 OFF */

#define T2_IDLE_CON         0xdfff      /* operate during sleep */
#define T2_IDLE_STOP        0xffff      /* stop operation during sleep */

#define T2_GATE_ON          0xffff      /* Timer2 Gate time accumulation enabled  */
#define T2_GATE_OFF         0xffbf      /* Timer2 Gate time accumulation disabled */

#define T2_PS_1_1           0xffcf      /* Prescaler 1:1   */
#define T2_PS_1_8           0xffdf      /*           1:8   */
#define T2_PS_1_64          0xffef      /*           1:64  */
#define T2_PS_1_256         0xffff      /*           1:256 */

#define T2_32BIT_MODE_ON    0xffff      /* Timer 2 and Timer 3 form a 32 bit Timer */
#define T2_32BIT_MODE_OFF   0xfff7      

#define T2_SOURCE_EXT       0xffff      /* External clock source */
#define T2_SOURCE_INT       0xfffd      /* Internal clock source */

/* Timer3 Control Register (T3CON) Bit Defines */
#define T3_ON               0xffff      /* Timer3 ON */
#define T3_OFF              0x7fff      /* Timer3 OFF */

#define T3_IDLE_CON         0xdfff      /* operate during sleep */
#define T3_IDLE_STOP        0xffff      /* stop operation during sleep */

#define T3_GATE_ON          0xffff      /* Timer3 Gate  time accumulation enabled  */
#define T3_GATE_OFF         0xffbf      /* Timer3 Gate time accumulation disabled */

#define T3_PS_1_1           0xffcf      /* Prescaler 1:1   */
#define T3_PS_1_8           0xffdf      /*           1:8   */
#define T3_PS_1_64          0xffef      /*           1:64  */
#define T3_PS_1_256         0xffff      /*           1:256 */
#define T3_SOURCE_EXT       0xffff      /* External clock source */
#define T3_SOURCE_INT       0xfffd      /* Internal clock source */

/* Timer4 Control Register (T4CON) Bit Defines */
#define T4_ON               0xffff      /* Timer4 ON */
#define T4_OFF              0x7fff      /* Timer4 OFF */

#define T4_IDLE_CON         0xdfff      /* operate during sleep */
#define T4_IDLE_STOP        0xffff      /* stop operation during sleep */

#define T4_GATE_ON          0xffff      /* Timer Gate time accumulation enabled */
#define T4_GATE_OFF         0xffbf      /* Timer Gate time accumulation disabled */

#define T4_PS_1_1           0xffcf      /* Prescaler 1:1   */
#define T4_PS_1_8           0xffdf      /*           1:8   */
#define T4_PS_1_64          0xffef      /*           1:64  */
#define T4_PS_1_256         0xffff      /*           1:256 */

#define T4_SOURCE_EXT       0xffff      /* External clock source */
#define T4_SOURCE_INT       0xfffd      /* Internal clock source */

#define T4_32BIT_MODE_ON    0xffff /* Timer 4 and Timer 5 form a 32 bit Timer */
#define T4_32BIT_MODE_OFF   0xfff7 

/* Timer5 Config Bit Defines */
#define T5_ON               0xffff      /* Timer5 ON */
#define T5_OFF              0x7fff      /* Timer5 OFF */

#define T5_IDLE_CON         0xdfff      /* operate during sleep */
#define T5_IDLE_STOP        0xffff      /* stop operation during sleep */

#define T5_GATE_ON          0xffff      /* Timer Gate time accumulation enabled */
#define T5_GATE_OFF         0xffbf      /* Timer Gate time accumulation disabled */

#define T5_PS_1_1           0xffcf      /* Prescaler 1:1   */
#define T5_PS_1_8           0xffdf      /*           1:8   */
#define T5_PS_1_64          0xffef      /*           1:64  */
#define T5_PS_1_256         0xffff      /*           1:256 */

#define T5_SOURCE_EXT       0xffff      /* External clock source */
#define T5_SOURCE_INT       0xfffd      /* Internal clock source */

/*=====================================================================================================================
 * Local macros
 *===================================================================================================================*/
/* On / Off timers */
#define _Timer1On()                     T1CONbits.TON = 1
#define _Timer1Off()                    T1CONbits.TON = 0
#define _Timer2On()                     T2CONbits.TON = 1
#define _Timer2Off()                    T2CONbits.TON = 0
#define _Timer3On()                     T3CONbits.TON = 1
#define _Timer3Off()                    T3CONbits.TON = 0
#define _Timer4On()                     T4CONbits.TON = 1
#define _Timer4Off()                    T4CONbits.TON = 0
#define _Timer5On()                     T4CONbits.TON = 1
#define _Timer5Off()                    T4CONbits.TON = 0

/*=====================================================================================================================
 * Local types
 *===================================================================================================================*/

/*=====================================================================================================================
 * Local data
 *===================================================================================================================*/

/*=====================================================================================================================
 * Constant Local Data
 *===================================================================================================================*/

/*=====================================================================================================================
 * Constant exported data                                                     
 *===================================================================================================================*/

/*=====================================================================================================================
 * Exported Data
 *===================================================================================================================*/
volatile U16             u16SoftTimerCounter;
volatile U16             u16SoftTimerListTicks[cNumberSoftTimers];
volatile tsSoftTimerList SoftTimerList[cNumberSoftTimers] = cSoftwareTimerList;

/*=====================================================================================================================
 * Local Functions Prototypes
 *===================================================================================================================*/
void __attribute__((__interrupt__,no_auto_psv)) _T1Interrupt();


/*=====================================================================================================================
 *
 *                                  E X P O R T E D    F U N C T I O N S
 *
 *===================================================================================================================*/
/*=====================================================================================================================
 * Parameters: Timer tick Us
 *
 * Return: void
 *
 * Description: Hardware timer 1 Init
 *===================================================================================================================*/
void __attribute__((user_init)) Timer1Init(void)
{
    U32 u32TimerTicks;

    _Timer1Off();
    _DisableIntT1();
    _ClearIntT1();

    T1CON = T1_OFF
          & T1_IDLE_CON     
          & T1_GATE_OFF     /* Timer Gate time accumulation disabled */
#if (cTimer1Prescaler == 1)
          & T1_PS_1_1       /* Prescaler 1:1 */
#elif(cTimer1Prescaler == 8)
          & T1_PS_1_8       /*           1:8 */
#elif(cTimer1Prescaler == 64)
          & T1_PS_1_64      /*          1:64 */
#elif(cTimer1Prescaler == 256)
          & T1_PS_1_256     /*         1:256 */
#else
    #error "Incorrect or missing Timer1 prescaller value!"
#endif
          & T1_SYNC_EXT_OFF /* Do not synch external clk input */
          & T1_SOURCE_INT;  /* Internal clock source */

    TMR1 = 0;

    u32TimerTicks = (U32)(((cFCY_MHz * cTimer1Ticks_us)/cTimer1Prescaler) - 1);
    _Assert(u32TimerTicks < 65535);
    PR1 = (U16)u32TimerTicks; /*set period1 register*/

    _SetPriorityIntT1(cTIMER1_ISR_Priority);
    _EnableIntT1();
    _Timer1On();
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void __attribute__((user_init)) SoftTimersInit(void)
{
    _Assert(cNumberSoftTimers > 0);
    u16SoftTimerCounter = 0;
    memset((void*)u16SoftTimerListTicks, 0, sizeof(u16SoftTimerListTicks));
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
_DECLARE_ISR(_T1Interrupt)
{
#if (cNumberSoftTimers > 1)
    U16 u16SoftTimerIndex;
#endif

    ++u16SoftTimerCounter;

#if (cNumberSoftTimers > 1)
    for(u16SoftTimerIndex = 0; u16SoftTimerIndex < cNumberSoftTimers; u16SoftTimerIndex++)
    {
        if(SoftTimerList[u16SoftTimerIndex].u16TimerTimeout != 0)
        {
            // Get timeouts in soft timer table
            if(SoftTimerList[u16SoftTimerIndex].u16TimerTimeout == (u16SoftTimerCounter - u16SoftTimerListTicks[u16SoftTimerIndex]))
            {
                // Save current tick
                u16SoftTimerListTicks[u16SoftTimerIndex] = u16SoftTimerCounter;
                // run callback
                SoftTimerList[u16SoftTimerIndex].Callback();
            }
        }
    }
#elif (cNumberSoftTimers == 1)
    if(SoftTimerList[cSchedulerTimerId].u16TimerTimeout != 0)
    {
        // Get timeouts in soft timer table
        if(SoftTimerList[cSchedulerTimerId].u16TimerTimeout == (u16SoftTimerCounter - u16SoftTimerListTicks[cSchedulerTimerId]))
        {
            // Save current tick
            u16SoftTimerListTicks[cSchedulerTimerId] = u16SoftTimerCounter;
            // run callback
            SoftTimerList[cSchedulerTimerId].Callback();
        }
    }
#else
    #error Error in number of software timers definition
#endif

    _ClearIntT1();
}
