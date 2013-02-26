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
#ifdef __TRAPS_C
    #error "!!! FileName ID. It should be Unique !!!"
#else
    #define __TRAPS_C
#endif

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file
 *===================================================================================================================*/
#include "traps.h"


/*=====================================================================================================================
 * Local constants
 *===================================================================================================================*/

/*=====================================================================================================================
 * Local macros
 *===================================================================================================================*/

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
void __attribute__((__interrupt__)) _DefaultInterrupt(void);
void __attribute__((__interrupt__)) _OscillatorFail(void);
void __attribute__((__interrupt__)) _AddressError(void);
void __attribute__((__interrupt__)) _StackError(void);
void __attribute__((__interrupt__)) _MathError(void);

void __attribute__((__interrupt__)) _AltOscillatorFail(void);
void __attribute__((__interrupt__)) _AltAddressError(void);
void __attribute__((__interrupt__)) _AltStackError(void);
void __attribute__((__interrupt__)) _AltMathError(void);

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
void __attribute__((noreturn)) AssertExternal(U16 u16Line, const char *File)
{
    volatile char DbgFileBuff[20];
    volatile U16 u16LineL = u16Line;

    (void)u16LineL;

    sprintf((char*)&DbgFileBuff[0], " %s", File);

    _DioPinConfig(cDioPin_AssertLed, 1);
    _DioPinConfig(cDioPin_AssertLed, cPinModeOutput);

    while(1)
    {
        ;
    }
}
/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void __attribute__((interrupt, no_auto_psv)) _DefaultInterrupt(void)
{
    //PIN_CPU_TRAP_LED = 1;
}

/*
** Primary Exception Vector handlers:
** These routines are used if INTCON2bits.ALTIVT = 0.
** All trap service routines in this file simply ensure that device
** continuously executes code within the trap service routine. Users
** may modify the basic framework provided here to suit to the needs
** of their application.
*/
/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void __attribute__((interrupt, no_auto_psv)) _OscillatorFail(void)
{
    //PIN_CPU_TRAP_LED = 1;
    INTCON1bits.OSCFAIL = 0;        //Clear the trap flag
    while (1);
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void __attribute__((interrupt, no_auto_psv)) _AddressError(void)
{
//     volatile U32 AddrError;
//     register U16 w0_local asm( "w0");
//     register U16 w1_local asm( "w1");
//     
//     asm volatile (" sub  w15,#12,w2 ");  // twelve bytes pushed since last trap!
//     asm volatile (" mov  [w2++], w0 ");  // w0 = PC[15:0] - PC LSB
//     asm volatile (" mov  [w2]  , w1 ");  // w1 = PC[22:16] - PC MSB
//     asm volatile (" mov  #0x7f , w3 ");  // Mask off non-address bits
//     asm volatile (" and  w1, w3, w1 ");  // Clear non address bits
//     
//     // now w1-w0 contain last address before trap. to get actual address decrement address by 2!
//     asm volatile (" mov  #2    , w3 ");  // Decrement the address by 2
//     asm volatile (" sub  w0,w3 , w0 ");  // w0 = w0 - w3 = w0 - 2 
//     asm volatile (" clr  w3         ");  // w3 = 0
//     asm volatile (" subb w1,w3 , w1 ");  // w1 = w1 - w3 - !C = w1 - 0 - !C (!C - inverted carry flag)
//         
//     AddrError = (U32)((U32)w0_local | ((U32)w1_local << 16));

    //PIN_CPU_TRAP_LED = 1;
    INTCON1bits.ADDRERR = 0;        //Clear the trap flag
	_dbgassert();
    //while (1);
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void __attribute__((interrupt, no_auto_psv)) _StackError(void)
{
//    PIN_CPU_TRAP_LED = 1;
    INTCON1bits.STKERR = 0;         //Clear the trap flag
    while (1);
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void __attribute__((interrupt, no_auto_psv)) _MathError(void)
{
    //PIN_CPU_TRAP_LED = 1;
    INTCON1bits.MATHERR = 0;        //Clear the trap flag
    _dbgassert();
    //while (1);
}


/*
** Alternate Exception Vector handlers:
** These routines are used if INTCON2bits.ALTIVT = 1.
** All trap service routines in this file simply ensure that device
** continuously executes code within the trap service routine. Users
** may modify the basic framework provided here to suit to the needs
** of their application.
*/
/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void __attribute__((interrupt, no_auto_psv)) _AltOscillatorFail(void)
{
    //PIN_CPU_TRAP_LED = 1;
    INTCON1bits.OSCFAIL = 0;
    while (1);
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void __attribute__((interrupt, no_auto_psv)) _AltAddressError(void)
{
    //PIN_CPU_TRAP_LED = 1;
    INTCON1bits.ADDRERR = 0;
    while (1);
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void __attribute__((interrupt, no_auto_psv)) _AltStackError(void)
{
    //PIN_CPU_TRAP_LED = 1;
    INTCON1bits.STKERR = 0;
    while (1);
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void __attribute__((interrupt, no_auto_psv)) _AltMathError(void)
{
    //PIN_CPU_TRAP_LED = 1;
    INTCON1bits.MATHERR = 0;
    while (1);
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

