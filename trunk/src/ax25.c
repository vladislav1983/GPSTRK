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
#ifdef __AX25_C
    #error "!!! FileName ID. It should be Unique !!!"
#else
    #define __AX25_C
#endif

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file
 *===================================================================================================================*/
#include "ax25.h"
#include "devconfig.h"
#include "timer_mcp.h"
#include "dma_mcp.h"
#include "outcompare_mcp.h"


/*=====================================================================================================================
 * Local constants
 *===================================================================================================================*/
#define RUNTIME_CRC_CALC                        0

#define cAX25_1200Hz                            1200UL
#define cAx25_2200Hz                            2200UL

#define cSinTabLength                           16UL
#define cAprsBitTime_us                         (1000000.0 / (F32)cAX25_1200Hz)
#define c1200Hz_TriggerTimerIntPer_us           ((1000000.0 / (F32)cAX25_1200Hz) / (F32)cSinTabLength)
#define c2200Hz_TriggerTimerIntPer_us           (((F32)cAX25_1200Hz * (F32)c1200Hz_TriggerTimerIntPer_us) / (F32)cAx25_2200Hz)
#define cAprsTriggerTimerPrescaller             1UL
#define cAprsBitTimerPrescaller                 1UL
#define cOC_PwmFrequencyHz                      60000UL

#define cPwmDutyMarginPercent                   5UL
#define cPwmDutyMax                             ((cFCY_MHz * (1000000UL/cOC_PwmFrequencyHz)) - 1UL) // abs max pwm value
#define cPwmDutyHighLimit                       (cPwmDutyMax - (cPwmDutyMax * cPwmDutyMarginPercent) / 100UL)

#define cAX25_Level_MARK                        1UL // 1200Hz
#define cAX25_Level_SPACE                       0UL // 2200Hz

#define cTrigTimerPeriodReloadMargin            10UL    // margin in number of instructions

#define cAprs_Flag                              0x7E    // The flag field at each end of the frame is the bit sequence 0x7e that separates each frame.
#define cAprs_CRC_Init                          0xFFFFU
#define cAprs_CRC_Poly                          0x8408U

/*=====================================================================================================================
 * Local macros
 *===================================================================================================================*/
#define _StartAprsTriggerTimer()                (T2CONbits.TON = 1U)
#define _StopAprsTriggerTimer()                 (T2CONbits.TON = 0U)

// before load period make sure that current value of timer counter is not greater that current period
#define _SetAprsTriggerTimerPeriod(Per_us)                                                                              \
{                                                                                                                       \
    U16 u16Period = (U16)((((F32)cFCY_MHz * (F32)(Per_us)) / (F32)cAprsTriggerTimerPrescaller) - 1UL);                  \
    if(TMR2 >= (u16Period - (U16)cTrigTimerPeriodReloadMargin))                                                         \
    {                                                                                                                   \
        TMR2 = 0;                                                                                                       \
    }                                                                                                                   \
    PR2 = u16Period;                                                                                                    \
}

#define _StartAprsBitTimer()                    (T3CONbits.TON = 1U)
#define _StopAprsBitTimer()                     (T3CONbits.TON = 0U)
#define _SetAprsBitTimerPeriod(Per_us)          (PR3 = (U16)(((F32)cFCY_MHz * (F32)(Per_us)) / (F32)cAprsBitTimerPrescaller) - 1UL)

#define _Dma0_Start()                           (DMACH0bits.CHEN = 1)
#define _Dma0_Stop()                            (DMACH0bits.CHEN = 0)

#define _Dma0_ClearCompletionFlag()             (DMAINT0bits.DONEIF = 0)
#define _Dma0_ClearHalfIntWatermark()           (DMAINT0bits.HALFIF = 0)

#define _GetLSB_Bit(data, bit)                  (((U16)(data) >> (U16)(bit)) & 0x01)
// NRZI at '0' transition. Example:
// TX line transition by 1 -> 0 
// DATA -> | 1 | 0 | 1 | 1 | 0 | 0 | 0 | 1 | 1 | 0 | 1 | 0 |
//             |   |   |   |   |   |   |   |   |   |   |   |
//  1 ->   ____|            ___     ___________         ___
//             |           |   |   |           |       |   |
//  0 ->       |___________|   |___|           |_______|   |

// SPACE is a 2200Hz tone and MARK is 1200Hz tone.
#define _NRZI_AtZeroCode(bit, out_lev)                                                                                  \
do                                                                                                                      \
{                                                                                                                       \
    if(!(bit))                                                                                                          \
    {                                                                                                                   \
        /* Change level according coding scheme */                                                                      \
        (out_lev) = !(out_lev);                                                                                         \
        /* clear bit stuff counter*/                                                                                    \
        u16BitStuffCnt = 0;                                                                                             \
        if((out_lev) == cAX25_Level_SPACE)                                                                              \
        {                                                                                                               \
            /* SPACE level is "0" = 2200Hz. Set 2200Hz timer trigger. */                                                \
            _SetAprsTriggerTimerPeriod(c2200Hz_TriggerTimerIntPer_us);                                                  \
        }                                                                                                               \
        else                                                                                                            \
        {                                                                                                               \
            /* MARK is "1" = 1200Hz. Set 1200Hz timer trigger. */                                                       \
            _SetAprsTriggerTimerPeriod(c1200Hz_TriggerTimerIntPer_us);                                                  \
        }                                                                                                               \
        _DioWritePin(cDioPin_DEBUG,(out_lev));                                                                          \
    }                                                                                                                   \
} while (0);                                                                                                            \

#define cAX25SetIdle()                                                                                                  \
do                                                                                                                      \
{                                                                                                                       \
    _StopAprsTriggerTimer();                                                                                            \
    _StopAprsBitTimer();                                                                                                \
    AX25Msg.pBuff = NULL;                                                                                               \
    AX25Msg.Lng = 0;                                                                                                    \
    /*set 0% duty*/                                                                                                     \
    OC1R = 0;                                                                                                           \
}while (0);

#define cAX25InitAndStartTransmit()                                                                                     \
do                                                                                                                      \
{                                                                                                                       \
    u16DataIndex = 0;                                                                                                   \
    u16BitTxCnt = 0;                                                                                                    \
    u16BitStuffCnt = 0;                                                                                                 \
    bAX25_OutputLevel = cAX25_Level_MARK;                                                                               \
    AX25TrmtState = eAX25_TX_DELAY;                                                                                     \
    _StartAprsTriggerTimer();                                                                                           \
    _StartAprsBitTimer();                                                                                               \
}while (0);
/*=====================================================================================================================
 * Local types
 *===================================================================================================================*/
typedef enum teAX25TrmtState
{
    eAX25_TX_DELAY = 0,
    eAX25_SEND_FLAG,
    eAX25_SEND_DATA,
    eAX25_TERMINATE,
    eAX25_IDLE
}tAX25TrmtState;

/*=====================================================================================================================
 * Local data
 *===================================================================================================================*/
static U16 u16SinTab[(U32)cSinTabLength] __attribute__((section(".dmaram")));
static U16 u16DataIndex;
static U16 u16BitTxCnt;
static U16 u16BitStuffCnt;
static BOOL bAX25_OutputLevel;
static tAX25TrmtState AX25TrmtState;
static tMsg AX25Msg;
#if (RUNTIME_CRC_CALC == 1)
static U16 u16Crc;
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

/*=====================================================================================================================
 * Local Functions Prototypes
 *===================================================================================================================*/
static void AX25_TimersInit(void);
static void AX25_OutputCompareInit(void);
static void AX25_DmaInit(void);

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
void __attribute__((user_init)) AX25_Init(void)
{
    U16 u16Index;
    U16 u16Degrees = 0;

    // fill sintab table with reference sine table
    for(u16Index = 0; u16Index < cSinTabLength; u16Index++, u16Degrees += (65536UL/cSinTabLength))
    {
        u16SinTab[u16Index] = (U16)((S16)(cPwmDutyMax/2UL) + (S16)(((U32)(cPwmDutyHighLimit/2UL) * (U32)sine(u16Degrees)) >> 15));
    }

    u16DataIndex = 0;
    u16BitStuffCnt = 0;
    u16BitTxCnt = 0;
    // start with high level
    bAX25_OutputLevel = cAX25_Level_MARK;
    AX25Msg.Lng = 0;
    AX25Msg.pBuff = NULL;
    AX25TrmtState = eAX25_IDLE;

    // init hardware
    AX25_TimersInit();
    AX25_OutputCompareInit();
    AX25_DmaInit();
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void AX25_Control(tControl Ctrl)
{
    if(Ctrl == cAprsCtrlStartTrmt)
    {
        if(AX25Msg.pBuff != NULL && AX25Msg.Lng != 0)
        {
#if (RUNTIME_CRC_CALC == 1)
            u16Crc = cAprs_CRC_Init;
#endif
            cAX25InitAndStartTransmit();
        }
        else
        {
            cAX25SetIdle();
        }
    } 
    else if(Ctrl == cAprsCtrlStop)
    {
        AX25Msg.pBuff = NULL;
        AX25Msg.Lng = 0;
        cAX25SetIdle();
    }
    else
    {
        _Assert(cFalse);
    }
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
HRESULT AX25_SendData(tMsg Msg)
{
    HRESULT res = S_NOK;

    if(AX25TrmtState == eAX25_IDLE)
    {
        AX25Msg.pBuff = Msg.pBuff;
        AX25Msg.Lng = Msg.Lng;

        res = S_OK;
    }

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
_DECLARE_ISR(_T3Interrupt)
{
    BOOL bTxBit;
#if (RUNTIME_CRC_CALC == 1)
    U16 u16CrcXor;
#endif

    switch(AX25TrmtState)
    {
    //------------------------------------------------------------------------------------------------------------------
    case eAX25_TX_DELAY:
        // FLAG ->     |           0x7E                |           0x7E                |           0x7E                |
        // DATA -> | 1 | 0 | 1 | 1 | 1 | 1 | 1 | 1 | 0 | 0 | 1 | 1 | 1 | 1 | 1 | 1 | 0 | 0 | 1 | 1 | 1 | 1 | 1 | 1 | 0 |
        //             |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
        //  1 ->   ____|                            ___                             ___                             ___
        //             |                           |   |                           |   |                           |
        //  0 ->       |___________________________|   |___________________________|   |___________________________|

        // get bit
        bTxBit = _GetLSB_Bit(cAprs_Flag, u16BitTxCnt);

        _NRZI_AtZeroCode(bTxBit, bAX25_OutputLevel);

        if(u16BitTxCnt >= 7)
        {
            u16BitTxCnt = 0;
            u16DataIndex++;
        }
        else
        {
            u16BitTxCnt++;    
        }

        if(u16DataIndex >= DeviceConfigParams.u8ConfAprsTxDelay + 1)
        {
            u16BitTxCnt = 0;
            u16DataIndex  = 0;
            AX25TrmtState = eAX25_SEND_FLAG;
        }

        break;
    //------------------------------------------------------------------------------------------------------------------
    case eAX25_SEND_FLAG:
        // get bit
        bTxBit = _GetLSB_Bit(cAprs_Flag, u16BitTxCnt);
        _NRZI_AtZeroCode(bTxBit, bAX25_OutputLevel);

        if(u16BitTxCnt >= 7) 
        {
            u16BitTxCnt = 0;
            u16DataIndex++;
        }
        else
        {
            u16BitTxCnt++;    
        }

        if(u16DataIndex >= 1)
        {
            u16BitTxCnt = 0;
            u16DataIndex  = 0;
            AX25TrmtState = eAX25_SEND_DATA;
        }
        break;
    //------------------------------------------------------------------------------------------------------------------
    case eAX25_SEND_DATA:

        if(u16BitStuffCnt >= 5)
        {
            bTxBit = 0;
            _NRZI_AtZeroCode(bTxBit, bAX25_OutputLevel);
        }
        else
        {
	        u16BitStuffCnt++;
	        
            // get bit
            bTxBit = _GetLSB_Bit(((U8)((U8*)(AX25Msg.pBuff))[u16DataIndex]), u16BitTxCnt);
            _NRZI_AtZeroCode(bTxBit, bAX25_OutputLevel);
              
            if(u16BitTxCnt >= 7)
            {
	            u16BitTxCnt = 0;
	            u16DataIndex++;
	        }
	        else
		    {
                u16BitTxCnt++;    
            }

#if (RUNTIME_CRC_CALC == 1)
            u16CrcXor = (u16Crc ^ bTxBit) & 0x0001u;
            u16Crc >>= 1;

            if(u16CrcXor)
                u16Crc ^= cAprs_CRC_Poly;
#endif
        }

        if(u16DataIndex < AX25Msg.Lng)
        {}
        else
        {
#if (RUNTIME_CRC_CALC == 1)
            u16Crc ^= 0xFFFFu;
#endif
            u16BitTxCnt = 0;
            u16DataIndex  = 0;
            AX25TrmtState = eAX25_TERMINATE;
        }
        break;
    //------------------------------------------------------------------------------------------------------------------
    case eAX25_TERMINATE:
        // get bit
        bTxBit = _GetLSB_Bit(cAprs_Flag, u16BitTxCnt);
        _NRZI_AtZeroCode(bTxBit, bAX25_OutputLevel);

        if(u16BitTxCnt >= 7)
        {
            u16BitTxCnt = 0;
            u16DataIndex++;
        }
        else
        {
            u16BitTxCnt++;
        }

        if(u16DataIndex >= 1)
        {
            cAX25SetIdle();
            Aprs_TransmitCallback(cAprsCallbackCtrlOK);
            AX25TrmtState = eAX25_IDLE;
        }
        break;
    //------------------------------------------------------------------------------------------------------------------
    case eAX25_IDLE:
        // do nothing
        break;
    //------------------------------------------------------------------------------------------------------------------
    default:
        AX25TrmtState = eAX25_IDLE;
        _Assert(cFalse);
        break;
    }

    T3_Clear_Intr_Status_Bit;
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
static void AX25_TimersInit(void)
{
    U32 u32TimerTicks;

    /*
    ** APRS trigger timer => used as interval timer to trigger DMA transfer
    */ 
    DisableIntT2;
    T2_Clear_Intr_Status_Bit;
    SetPriorityIntT2(0);

    _StopAprsTriggerTimer();

    T2CON =  T2_OFF
           & T2_IDLE_STOP
           & T2_GATE_OFF
#if (cAprsTriggerTimerPrescaller == 1)
           & T2_PS_1_1
#elif (cAprsTriggerTimerPrescaller == 8)
           & T2_PS_1_8
#elif (cAprsTriggerTimerPrescaller == 64)
           & T2_PS_1_64
#elif (cAprsTriggerTimerPrescaller == 256)
           & T2_PS_1_256
#else
    #error "Incorrect or missing Timer2 prescaler value!"
#endif
           & T2_32BIT_MODE_OFF
           & T2_SOURCE_INT;

    TMR2 = TMR2_VALUE;
    // check 1200Hz trigger period
    u32TimerTicks = (U32)((((F32)cFCY_MHz * (F32)(c1200Hz_TriggerTimerIntPer_us)) / (F32)cAprsTriggerTimerPrescaller) - 1UL);
    _Assert(u32TimerTicks < 65535UL);
    // set 2200Hz trigger period
    u32TimerTicks = (U32)((((F32)cFCY_MHz * (F32)(c2200Hz_TriggerTimerIntPer_us)) / (F32)cAprsTriggerTimerPrescaller) - 1UL);
    _Assert(u32TimerTicks < 65535UL);
    // set period
    PR2 = (U16)u32TimerTicks;

    /*
    ** APRS Bit timer=> used as interval timer to set new bit tone
    */
    DisableIntT3;
    T3_Clear_Intr_Status_Bit;
    SetPriorityIntT3(cTIMER3_ISR_Priority);

    _StopAprsBitTimer();

    T3CON =  T3_OFF
           & T3_IDLE_STOP
           & T3_GATE_OFF
#if (cAprsBitTimerPrescaller == 1)
           & T3_PS_1_1
#elif (cAprsBitTimerPrescaller == 8)
           & T3_PS_1_8
#elif (cAprsBitTimerPrescaller == 64)
           & T3_PS_1_64
#elif (cAprsBitTimerPrescaller == 256)
           & T3_PS_1_256
#else
    #error "Incorrect or missing Timer2 prescaler value!"
#endif
           & T3_SOURCE_INT;

    TMR3 = TMR3_VALUE;
    // check trigger period
    u32TimerTicks = (U32)((((F32)cFCY_MHz * (F32)(cAprsBitTime_us)) / (F32)cAprsBitTimerPrescaller) - 1UL);
    _Assert(u32TimerTicks < 65535UL);
    // set period
    PR3 = (U16)u32TimerTicks;

    EnableIntT3;
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
static void AX25_OutputCompareInit(void)
{
    DisableIntOC1;
    OC1_Clear_Intr_Status_Bit;
    SetPriorityIntOC1(0);

    OC1CON1 = OC_IDLE_STOP              /* stop in idle mode */
            & OC_SYSCLK_SRC             /*System Clock is the clock source for OutputCompare*/
            & CMP_FAULT2_IN_DISABLE     /*PWM COMPARATOR Fault 2 Input Disabled*/
            & OC_FAULT1_IN_DISABLE      /*OC/PWM Fault 1 Input Disabled*/
            & OC_FAULT0_IN_DISABLE      /*OC/PWM Fault 0 Input Disabled*/
            & OC_PWM_FAULT_CLEAR        /*Fault status bit will be cleared in software*/
            & OC_TRIG_CLEAR_SYNC        /*Trigger is cleared synchronously(OCxRs=TIMER) or by software*/
            & OC_PWM_EDGE_ALIGN;        /* Edge Aligned PWM Mode on OCx pin */

    OC1CON2 = OC_FAULT_MODE_CLEAR_SW    /*Fault condition maintained until OCxFLT is cleared*/
            & OC_PWM_FAULT_OUT_LOW      /*Output compare output is driven low during fault condition*/
            & OC_FAULT_PIN_UNCHANGE     /*oc_oe_out is unchanged during fault condition*/
            & OC_OUT_INVERT             /*OutputCompare output is inverted*/
            & DELAY_OC_FALL_EDGE_00     /*OCx falling edge occurs by starting of the instruction cycle*/
            & OC_CASCADE_DISABLE        /*Output Compare Cascade Module Disabled*/
            & OC_TRIGGER_ENABLE         /*sync_trig[x] used to trigger the module timer*/
            & OC_TRIGGER_TIMER          /* Timer has been triggered and is running */
            & OC_DIRN_OUTPUT            /*The signal ocmp_oe_out is forced to zero*/
            & OC_SYNC_TRIG_IN_CURR_OC;  /*for current OC module  */

    // set carrier frequency
    OC1RS = (U16)((cFCY_MHz * (1000000UL/cOC_PwmFrequencyHz)) - 1UL);
    // set 50% duty
    OC1R = (U16)(((cFCY_MHz * (1000000UL/cOC_PwmFrequencyHz)) - 1UL) / 2UL);
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
static void AX25_DmaInit(void)
{ 
    DisableIntDMACH0;
    DMACH0_Clear_Intr_Status_Bit;
    SetPriorityIntDMACH0(0);

    // Enable DMA module
    DMACON = DMACON_VALUE
           | DMA_ENABLE
           | DMA_FIXED_PRIORITY_SCHEME;

    // Program DMAH and DMAL with appropriate upper and lower address boundaries for data RAM operations.
    // dmaram_start and dmaram_end exported from linker script.
    DMAL = (U16)(&dmaram_start - 1);
    DMAH = (U16)(&dmaram_end + 1);

    _Dma0_Stop();

    // Select the DMA channel to be used and disable its operation (CHEN = 0).
    DMACH0 = DMACH0_VALUE
           | DMA_NULL_WRITE_MODE_DISABLE    /* No dummy write is initiated */
           | DMA_ADD_COUNT_RELOAD_ENABLE    /* DMASRC,DMADST & DMACNT registers are reloaded to their previous values upon the start of next operation*/
           | DMA_SRC_INCR_MODE              /* DMASRC is incremented based on SIZE bit after a transfer completion*/
           | DMA_DST_UNCNGD_MODE            /* DMADST remains unchanged after a transfer completion*/
           | DMA_REPEATED_ONE_SHOT          /* Repeated One-Shot mode enabled*/
           | DMA_DATA_WORD                  /* Data size is word(16-bit) */
           | DMA_CH_DISABLE;

    DMAINT0 = 0;
    DMAINT0 |= DMA_TRIG_SRC_TIMER2
            |  DMA_HLFWY_COMPLTN_WATER_MARK_DSBL;
    // Program the DMACNTn register for the number of triggers per transfer
    DMACNT0 = cSinTabLength;
    // Program destination -> Output compare duty cycle register
    DMADST0 = (U16)&OC1R;
    // Program source -> sin table
    DMASRC0 = (U16)&u16SinTab[0];

    _Dma0_Start();
}
