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
#ifdef __VADC_C
    #error "!!! FileName ID. It should be Unique !!!"
#else
    #define __VADC_C
#endif

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file
 *===================================================================================================================*/
#include "vadc.h"
#include "adc_mcp.h"


/*=====================================================================================================================
 * Local constants
 *===================================================================================================================*/
#define cADC_ClockPeriod_us                 75000UL // 75ns clock
#define cAdc_Required_Tad                   12UL
#define cAdc_ConvClockSelect                ((cADC_ClockPeriod_us)/(1000000UL/cFCY_MHz))-1

/*=====================================================================================================================
 * Local macros
 *===================================================================================================================*/
#define _Adc_StartSampling()            (AD1CON1bits.ASAM = 1)
#define _Adc_StopSampling()             (AD1CON1bits.ASAM = 0)

#define _Adc_GetIsrFlag()               (IFS0bits.AD1IF)
#define _Adc_ClearIsrFlag()             (IFS0bits.AD1IF = 0)


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
void Adc_Init(void)
{
    DisableIntADC1;
    ADC1_Clear_Intr_Status_Bit;
    SetPriorityIntADC1(0);

    AD1CON1 = ADC_MODULE_OFF            /* A/D Converter off */
            & ADC_IDLE_STOP             /* A/D Stop in Idle mode */
            & ADC_DMA_PIA_MODE          /* A/D Peripheral Indirect Addressing mode is disabled*/
            & ADC_DMA_DISABLE           /* DMA operation of A/D is disabled*/
            & ADC_10BIT_MODE            /* 10-bit A/D operation*/ 
            & ADC_FORMAT_FRACT          /* A/D data format fractional */
            & ADC_CLK_AUTO              /* The SAMP bit is cleared after SAMC<4:0> number of TAD clocks following the SAMP bit being set.No Extended Sample Time is present.*/	
            & ADC_AUTO_SAMPLING_OFF     /* Sampling begins when SAMP bit is set */
            & ADC_SAMP_OFF;             /* sample / hold amplifiers are holding */

    AD1CON2 = ADC_POS_VREF_AVDD         /* Converter Positive Voltage Reference - AVDD*/
            & ADC_NEG_VREF_AVSS         /* Converter Negative Voltage Reference - AVSS */
            & ADC_OFFSET_CAL_OFF        /* Coverts to get the actual input value */
            & ADC_BUF_REG_ENABLE        /* Conversion result is loaded into buffer location determined by the converted channel*/
            & ADC_SCAN_ON               /* A/D Scan Input Selections for CH0 during SAMPLE A */
            & ADC_INTR_2_CONV           /* Interrupts at the completion of conversion of 2 samples */
            & ADC_ALT_BUF_OFF           /* Buffer configured as 1 16-word buffer */
            & ADC_ALT_INPUT_OFF;        /* use MUXA only */

    AD1CON3 = ADC_CONV_CLK_SYSTEM       /* Clock derived from system clock */
            & ADC_CHARGE_PUMP_DISABLE   /* Charge pump for switches is enabled*/
            & ADC_SAMPLE_TIME_12        /* A/D Auto Sample Time 12 Tad */
            & ADC_CONV_CLK_2Tcy;        /* A/D Conversion Clock is 2*Tcy */

    AD1CHS = ADC_CH0_NEG_SAMPLEB_VREFN  /* CH0 negative input is VREF- */
           & ADC_CH0_POS_SAMPLEB_AN8    /* A/D CH0 pos i/p sel for SAMPLE B is AN8 */
           & ADC_CH0_NEG_SAMPLEA_VREFN  /* CH0 negative input is VREF- */
           & ADC_CH0_POS_SAMPLEA_AN8;   /* A/D Chan 0 pos i/p sel for SAMPLE A is AN8 */

    AD1CSSL = ADC_SKIP_SCAN_AN0         /* Disable Input Scan AN0 */
            & ADC_SKIP_SCAN_AN1         /* Disable Input Scan AN1 */
            & ADC_SKIP_SCAN_AN2         /* Disable Input Scan AN2 */
            & ADC_SKIP_SCAN_AN3         /* Disable Input Scan AN3 */
            & ADC_SKIP_SCAN_AN4         /* Disable Input Scan AN4 */
            & ADC_SKIP_SCAN_AN5         /* Disable Input Scan AN5 */
            & ADC_SKIP_SCAN_AN6         /* Disable Input Scan AN6 */
            & ADC_SKIP_SCAN_AN7         /* Disable Input Scan AN7 */
            & ADC_SCAN_AN8              /* Enable Input Scan AN8 */
            & ADC_SCAN_AN9              /* Enable Input Scan AN9 */
            & ADC_SKIP_SCAN_AN10        /* Disable Input Scan AN10 */
            & ADC_SKIP_SCAN_AN11        /* Disable Input Scan AN11 */
            & ADC_SKIP_SCAN_AN12        /* Disable Input Scan AN12 */
            & ADC_SKIP_SCAN_AN13        /* Disable Input Scan AN13 */
            & ADC_SKIP_SCAN_AN14        /* Disable Input Scan AN14 */
            & ADC_SKIP_SCAN_AN15;       /* Disable Input Scan AN15 */

    // init analog pins
    _DioPinConfig(cDioPin_BatteryVoltage, cPinModeInput);
    _DioPinConfig(cDioPin_Temperature, cPinModeInput);

    _DioAnalogConfig(cDioPin_BatteryVoltage, cPinModeAnalog);
    _DioAnalogConfig(cDioPin_Temperature, cPinModeAnalog);

    EnableADC1;
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void Adc_ConvertChannels(tMsg Msg)
{
    U16 u16AdcIdx;
    U16 *pu16AdcBasePtr = (U16*)&ADC1BUF8;
#if cAdc_ConvClockSelect != 0
    U16 u16Timeout = (U16)(cAdc_ChannelsCnt * cAdc_Required_Tad * cAdc_ConvClockSelect);
#else
    U16 u16Timeout = (U16)(cAdc_ChannelsCnt * cAdc_Required_Tad);
#endif

    if(Msg.Lng == (sizeof(U16) * cAdc_ChannelsCnt))
    {
        _Adc_ClearIsrFlag();

        // start sampling
        _Adc_StartSampling();

        // wait conversion
        while((cFalse == _Adc_GetIsrFlag()) && (0 != u16Timeout))
        {
            u16Timeout--;
        }
        
        _Adc_StopSampling();
        _Adc_ClearIsrFlag();

        if(u16Timeout != 0)
        {
            // read results
            for(u16AdcIdx = 0; u16AdcIdx < cAdc_ChannelsCnt; u16AdcIdx++)
            {
                ((U16*)Msg.pBuff)[u16AdcIdx] = (U16)((*pu16AdcBasePtr) >> 1);
                pu16AdcBasePtr++;
            }
        }
        else
        {
            // read unavailable values
            for(u16AdcIdx = 0; u16AdcIdx < cAdc_ChannelsCnt; u16AdcIdx++)
            {
                ((U16*)Msg.pBuff)[u16AdcIdx] = 0xFFFF;
            }
        }
    }
    else
    {
        _assert(cFalse);
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

