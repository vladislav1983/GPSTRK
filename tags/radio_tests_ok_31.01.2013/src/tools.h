/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/
#ifndef __TOOLS_H
#define __TOOLS_H

/*
** Module Identification
*/
#define __TOOLS

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file                
 *===================================================================================================================*/
#include "basedef.h"

/*=====================================================================================================================
 * Constant data                                                              
 *===================================================================================================================*/
#define 	SINTAB_LEN			512 	// 2^9
#define		SIN_LEN_DIV			9

#define 	SQRT_TAB_LEN		512 	// 2^9
#define 	SQRT_LEN_DIV		9

#define 	ATAN_TABLE_LEN		129
#define 	DEC_PLACES_BEFORE 	7     	/* Corresponds to 128 values */
#define 	DEC_PLACES_AFTER 	(15-DEC_PLACES_BEFORE)

/*
*	arithmetic constants
*	====================
*/
#ifndef PI
    #define PI          3.1415926535897931159979634685441851615905761718750
#endif
#define SQRT2			1.4142135623730950488016887242097
#define SQRT3			1.7320508075688772935274463415059
#define SQRT3OV2		0.86602540378443864676372317075294
/*
*	Fractional arithmetic constants
*	================================
*/
#define qOneBySq3		0x49E7			/*1/SQRT(3)*32768 (Fractional format)*/
#define qOneBy3			0x2AAB			/*1/3 * 32768 in fractional format*/
#define qSQRT3OV2		0x6EDA			/*SQRT(3)/2 in Fractional Format*/
#define qSQRT2			0xB504			/*SQRT(2)   in Fractional Format*/
#define qSQRT3			0xDDB3			/*SQRT(3)   in Fractional Format*/
#define qPI_deg			(32768ul)
#define qHalf_PI_deg	(qPI_deg / 2)

#define cSinTabLen      32  //2^5
#define cSinTabDiv      5

/*=====================================================================================================================
 * Exported type                                                             
 *===================================================================================================================*/

/*=====================================================================================================================
 * Exported data                                                              
 *===================================================================================================================*/
extern const S16 sintab[cSinTabLen];

/*=====================================================================================================================
 * Constant exported data                                                     
 *===================================================================================================================*/

/*=====================================================================================================================
 * Exported Macros                                                            
 *===================================================================================================================*/
/*=====================================================================================================================
 * Parameters: alpha = 2^16*x/(2*PI)
 *
 * Return: sin(x)*32768
 *
 * Description: Sine Function with linear interpolation in a small degrees input.
 *===================================================================================================================*/
// Fractional Product ->(A*B) >> 15
#define _fmul_q15(/*Q15*/ qA, /*Q15*/ qB)       (S16)((S32)((S32)qA * (S32)qB) >> 15)
#define sine(alpha)	                            (sintab[(alpha)>>(16-cSinTabDiv)])
/*
*	macro definitions
*	==========================================
*/
#define _Cat(x,y)           x ## y
#define _str(s)             #s

/*
*	macro definitions for arithmetic functions
*	==========================================
*/
#define _absi(x)                ((x)>=0 ? (x) : -(x))       /* absolute of integer */
#define _sign(x)		        ((x)>=0 ? 1 : -1)           /* sign function 1/-1 */
#define _sigm(x)			    ((x)>=0 ? 0 : 1)            /* sign function 0/1 */
#define _signmul(x,y)		    ((y)>=0 ? (x) : -(x))       /* set sign(x) according sign(y) */
#define _max_int(x,y)	        ((x)>=(y) ? (x) : (y))      /* return maximum of (x,y) */
#define _min_int(x,y)		    ((x)>=(y) ? (y) : (x))      /* return minimum of (x,y) */
#define _boolean(x)	            ((x)==0 ? 0 : 1)            /* integer to boolean conversion */
#define _MulFracBy2(x,y)        ((((S32)(x)*(y))<<1)>>16)   /* operands word */
#define _MulFracBy2L(x,y)       (((x)*(y))>>15)             /* operands long */
#define _div_mod2(x,n)          (((x)+(1<<((n)-1)))>>(n))   /* division modulo 2 with rounding, n >= 1! */
#define _HiPartBy2(x)           ((x)>>15)
#define _round(x)               (((x) < 0.0) ? ((x) - 0.5) : ((x) + 0.5)) 
#define _Q15_Conv(x)            ((S32)(_mulsu((Q15)(x), 32767)))

/*
 *	macro definitions for bit/byte functions
 *	==========================================
*/
#define _putbit(value,dst,bitn)	 (		\
{										\
    if(value)							\
    (dst) = ((dst) | (U16)(1u << (bitn)));	\
    else								\
    (dst) = ((dst) & (U16)~(1u << (bitn)));	\
})

#define _getbit(src,bitn)	((src) & (1 << (bitn)))

#define _Hi(LongVar)        (*((S16 *)(void*)&(LongVar)+1))
#define _Lo(LongVar)        (*(S16 *)(void*)&(LongVar))
#define _Hiu(LongVar)       (*((U16 *)(void*)&(LongVar)+1))
#define _Lou(LongVar)       (*(U16 *)(void*)&(LongVar))
#define _HiBy(WordVar)      (*((U8 *)(void*)&(WordVar)+1))
#define _LoBy(WordVar)      (*(U8 *)(void*)&(WordVar))

// Built-in arithmetic Functions Wrappers
#define _mulss(s16A, s16B)      __builtin_mulss((S16)(s16A), (S16)(s16B))       // Signed integer multiplication - S32 output
#define _mulsu(s16A, u16B)      __builtin_mulsu((S16)(s16A), (U16)(u16B))       // Signed mixed signs integer multiplication - S32 output
#define _mulus(u16A, s16B)      __builtin_mulus((U16)(u16A), (S16)(s16B))       // Signed mixed signs integer multiplication - S32 output
#define _muluu(u16A, u16B)      __builtin_mulus((U16)(u16A), (U16)(u16B))       // Unsigned integer multiplication - U32 output
#define _divsd(s32Num, s16Den)  __builtin_divsd((S32)(s32Num), (S16)(s16Den))   // Computes the quotient s32Num / s16Den - S16 output
#define _divud(u32Num, u16Den)  __builtin_divud((U32)(u32Num), (U16)(u16Den))   // Computes the quotient u32Num / u16Den - U16 output

/*=====================================================================================================================
 * Exported functions                     				                        
 *===================================================================================================================*/



#endif /* __TOOLS_H */
