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
#ifdef __SYSTEM_C
    #error "!!! FileName ID. It should be Unique !!!"
#else
    #define __SYSTEM_C 
#endif

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file
 *===================================================================================================================*/
#include "system.h"
#include "alarm.h"
#include "kernelparam.h"
#include "nmea_main.h"
#include "pps_mcp.h"

/*=====================================================================================================================
 * Local constants
 *===================================================================================================================*/
#define cRefreshWatchDogPeriodUs            80E3
#define CLOCK_SWITCH                        0

/*=====================================================================================================================
 * Local macros
 *===================================================================================================================*/
#define _UnlockPeripherialPinSelect()       __builtin_write_OSCCONL(OSCCON & 0xbf) // unlock PPS
#define _LockPeripherialPinSelect()         __builtin_write_OSCCONL(OSCCON | 0x40) // lock   PPS

/*=====================================================================================================================
 * Local types
 *===================================================================================================================*/

/*=====================================================================================================================
 * Local data
 *===================================================================================================================*/
static tOSAlarm RefreshWatchDogAlarm;

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
#if CLOCK_SWITCH == 1
static void ClockSwitch(U16 u16ClockSouce);
#endif
static void SetupPeripheralPinSelect(void);
static void ClockInit(void);

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
void _system_lowlevel_init(void)
{   
    _WatchDOgDisable();

    ClockInit();

#if CLOCK_SWITCH == 1
    /* Init CPU clock before startup OS */
    ClockSwitch(FNOSC_FRCPLL); 
#endif

    SetupPeripheralPinSelect();

    _WatchDOgEnable();
} 

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void __attribute__((user_init)) SystemInit(void)
{
    /* Init refresh watchdog task */
    RefreshWatchDogAlarm.TaskID = cRefreshWatchDogTaskId;
    OsSetAlarm(&RefreshWatchDogAlarm, cRefreshWatchDogPeriodUs/cOsAlarmTickUs);
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void RefreshWatchDogTask(void)
{
    asm volatile ("clrwdt");
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void IdleTask(void)
{
    NMEAMain_DecodingEngine();
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
 * Description: Peripheral remapping setup
 *===================================================================================================================*/
static void SetupPeripheralPinSelect(void)
{
    _UnlockPeripherialPinSelect();

    /*
    ** This is hardware specific pin remapping
    */
    // RP30 -> U1RX
    iPPSInput(IN_FN_PPS_U1RX, IN_PIN_PPS_RP30);
    // U1TX -> RP16
    iPPSOutput(OUT_PIN_PPS_RP16, OUT_FN_PPS_U1TX);
    // RP21 -> SCK1
    iPPSOutput(OUT_PIN_PPS_RP21, OUT_FN_PPS_SCK1OUT);
    // SDI1 -> RP19
    iPPSInput(IN_FN_PPS_SDI1, IN_PIN_PPS_RP19);
    // SDO1 -> RP26
    iPPSOutput(OUT_PIN_PPS_RP26, OUT_FN_PPS_SDO1);
    // OC1 -> RP10
    iPPSOutput(OUT_PIN_PPS_RP10, OUT_FN_PPS_OC1);

    _LockPeripherialPinSelect();
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
static void ClockInit(void)
{
    CLKDIVbits.ROI = 0;     // 0 = Interrupts have no effect on the DOZEN bit
    CLKDIVbits.DOZE = 0;    // CPU Peripheral Clock Ratio Select bits
    CLKDIVbits.DOZEN = 0;   // CPU peripheral clock ratio set to 1:1
    CLKDIVbits.RCDIV = 0;   // FRC Postscaler Select bits 000 = 8 MHz (divide by 1)
}

#if CLOCK_SWITCH == 1
/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
static void ClockSwitch(U16 u16ClockSouce)
{
        // Place the new oscillator selection in W0
        asm volatile ("mov		w0,w1");

        // if NOSC_SOSC, OSCCONL = 0x3, else OSCCONL = 0x1.
        asm volatile ("mov		#0, w2");
        asm volatile ("mov		#4, w4");
        asm volatile ("cpsne	w0, w4");
        asm volatile ("mov.b	#3, w2");
        asm volatile ("ior		#1, w2");
        asm volatile ("mov.b	w2, w4");

        asm volatile ("mov.b 	OSCCONH,WREG");
        asm volatile ("and		#0xF8,w0");
        asm volatile ("ior		w0,w1,w0");

        // OSCCONH(High byte) Unlock Sequence
        asm volatile ("mov 	#OSCCONH, w1");
        asm volatile ("mov 	#0x78, w2");
        asm volatile ("mov 	#0x9a, w3");
        asm volatile ("mov.b 	w2, [w1]");
        asm volatile ("mov.b 	w3, [w1]");

        // Set New Oscillator Selection
        asm volatile ("mov.b 	WREG,OSCCONH");

        // OSCCONL(Low byte) Unlock Sequence
        asm volatile ("mov 	#OSCCONL, w1");
        asm volatile ("mov 	#0x46, w2");
        asm volatile ("mov 	#0x57, w3");
        asm volatile ("mov.b 	w2, [w1]");
        asm volatile ("mov.b 	w3, [w1]");

        // Start Oscillator Switch Operation
        asm volatile ("mov.b	w4, [w1]");

        // wait oscillator switch to complete
        while(OSCCONbits.OSWEN != 0);
}
#endif
