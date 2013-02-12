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
#ifdef __HD44780_C
    #error "!!! FileName ID. It should be Unique !!!"
#else
    #define __HD44780_C
#endif

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file
 *===================================================================================================================*/
#include "hd44780.h"


/*=====================================================================================================================
 * Local constants
 *===================================================================================================================*/
#define cLCD_TYPE                           2u
#define cLCD_LINE_ADDRESS_1                 0x00u
#define cLCD_LINE_ADDRESS_2                 0x40u

/* Display ON/OFF Control defines */
#define cDON                                0b00001111  /* Display on      */
#define cDOFF                               0b00001011  /* Display off     */
#define cCURSOR_ON                          0b00001111  /* Cursor on       */
#define cCURSOR_OFF                         0b00001101  /* Cursor off      */
#define cBLINK_ON                           0b00001111  /* Cursor Blink    */
#define cBLINK_OFF                          0b00001110  /* Cursor No Blink */

/* Cursor or Display Shift defines */
#define cSHIFT_CUR_LEFT                     0b00010011  /* Cursor shifts to the left   */
#define cSHIFT_CUR_RIGHT                    0b00010111  /* Cursor shifts to the right  */
#define cSHIFT_DISP_LEFT                    0b00011011  /* Display shifts to the left  */
#define cSHIFT_DISP_RIGHT                   0b00011111  /* Display shifts to the right */

/* Function Set defines */
#define cFOUR_BIT                           0b00101111  /* 4-bit Interface               */
#define cEIGHT_BIT                          0b00111111  /* 8-bit Interface               */
#define cLINE_5X7                           0b00110011  /* 5x7 characters, single line   */
#define cLINE_5X10                          0b00110111  /* 5x10 characters               */
#define cLINES_5X7                          0b00111011  /* 5x7 characters, multiple line */

// Rev1 additional WH Tan
// Additional define to support display mode
#define cDISP_FLIP_NONE                     0b00111100  /* No flip                             */
#define cDISP_FLIP_VERTICAL                 0b00111101	/* Flip both vertically & horizontally */
#define cDISP_FLIP_HORIZONTAL               0b00111110	/* Flip horizontally                   */
#define cDISP_FLIP_BOTH                     0b00111111	/* Flip vertically                     */
// End Rev1

// Rev1 additional WH Tan
// Additional define to support entry mode & shift mode
#define cENTRY_CURSOR_DEC                   0b00000101	/* Entry cause cursor move to left  */
#define cENTRY_CURSOR_INC                   0b00000111	/* Entry cause cursor move to right */
#define cENTRY_DISPLAY_SHIFT                0b00000111 	/* Entry cause the display to shift */
#define cENTRY_DISPLAY_NO_SHIFT             0b00000110	/* Entry cause no shift             */

// Address defines
// 4 lines X 20 characters LCD
#ifdef LCD_4X20
    #define cLINE0	                        0x00u
    #define cLINE1                          0x40u
    #define	cLINE2                          0x14u
    #define cLINE3                          0x54u
#endif

// 2 lines X 20 characters LCD
#ifdef LCD_2X20
    #define cLINE0	                        0x00u
    #define cLINE1	                        0x40u
#else
    // Use generic address
    #define cLINE0	                        0x00u
    #define cLINE1	                        0x40u
    #define	cLINE2	                        0x14u
    #define cLINE3	                        0x54u
#endif
/*=====================================================================================================================
 * Local macros
 *===================================================================================================================*/
#define _LcdDataWrite(DataNibble)                                                                                       \
do                                                                                                                      \
{                                                                                                                       \
    _DioWritePin(cDioPin_Lcd_DB4, ((DataNibble) >> 0));                                                                 \
    _DioWritePin(cDioPin_Lcd_DB5, ((DataNibble) >> 1));                                                                 \
    _DioWritePin(cDioPin_Lcd_DB6, ((DataNibble) >> 2));                                                                 \
    _DioWritePin(cDioPin_Lcd_DB7, ((DataNibble) >> 3));                                                                 \
}while(0)

/*=====================================================================================================================
 * Local types
 *===================================================================================================================*/

/*=====================================================================================================================
 * Local data
 *===================================================================================================================*/

/*=====================================================================================================================
 * Constant Local Data
 *===================================================================================================================*/
const U8 u8LCD_INIT_STRING[4] = 
{
    0x20 | (cLCD_TYPE << 2), // Func set: 4-bit, 2 lines, 5x8 dots 
    0xc,					 // Display on 			
    1,						 // Clear display 
    6						 // Increment cursor 
};

/*=====================================================================================================================
 * Constant exported data                                                     
 *===================================================================================================================*/

/*=====================================================================================================================
 * Exported Data
 *===================================================================================================================*/
FILE *LcdStream;

/*=====================================================================================================================
 * Local Functions Prototypes
 *===================================================================================================================*/
static void HD44780_SendByte(U8 u8ByteToLcd, U8 u8Address);
static void HD44780_SendNibble(U8 u8Nibble);
static void HD44780_DelayUs(U16 u16DelayUs);
static void HD44780_Write(U8 *pBuff, U8 u8Len);

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
void HD44780_Init(void)
{
    U16 u16InitCounter;

    _DioWritePin(cDioPin_LcdBacklight, 1);
    _DioWritePin(cDioPin_Lcd_RS,       0);
    _DioWritePin(cDioPin_Lcd_RW,       0);
    _DioWritePin(cDioPin_LcdEnable,    0);
    _DioWritePin(cDioPin_Lcd_DB4,      0);
    _DioWritePin(cDioPin_Lcd_DB5,      0);
    _DioWritePin(cDioPin_Lcd_DB6,      0);
    _DioWritePin(cDioPin_Lcd_DB7,      0);

    _DioPinConfig(cDioPin_LcdBacklight, cPinModeOutput);
    _DioPinConfig(cDioPin_Lcd_RS,       cPinModeOutput);
    _DioPinConfig(cDioPin_Lcd_RW,       cPinModeOutput);
    _DioPinConfig(cDioPin_LcdEnable,    cPinModeOutput);
    _DioPinConfig(cDioPin_Lcd_DB4,      cPinModeOutput);
    _DioPinConfig(cDioPin_Lcd_DB5,      cPinModeOutput);
    _DioPinConfig(cDioPin_Lcd_DB6,      cPinModeOutput);
    _DioPinConfig(cDioPin_Lcd_DB7,      cPinModeOutput);

    HD44780_DelayUs(15ul);

    for(u16InitCounter =1; u16InitCounter <= 3; ++u16InitCounter)
    {
        HD44780_SendNibble(3);
        HD44780_DelayUs(5000ul);
    }

    HD44780_SendNibble(2);

    for(u16InitCounter=0; u16InitCounter < sizeof(u8LCD_INIT_STRING); ++u16InitCounter)
    {
        HD44780_SendByte(u8LCD_INIT_STRING[u16InitCounter], 0);	
    }
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *    y pos ___ 
 *             |                             DISPLAY SEGMENTS LAYOUT   
 *             V
 *                  +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+    ^ UP
 *             2    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
 *                  +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+    |
 *             1    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
 *                  +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+    v DOWN
 *         x pos ->   1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16
 *
 *===================================================================================================================*/
void HD44780_GotoXY(U8 x, U8 y)
{
    U8 u8Addr;

    if(y != 1)
    {
        u8Addr = cLCD_LINE_ADDRESS_2;
    }
    else
    {
        u8Addr = 0;
    }

    u8Addr += x - 1u;

    HD44780_SendByte((0x80u | u8Addr), 0);
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void HD44780_Printf(const char *format, ...)
{
    U8 u8Buff[cLCD_LINE_ADDRESS_2/4u];

    va_list ap;

    va_start(ap, format);

    /* Taking advantage of the fast sprintf() since v3.20 */
    vsprintf((char*)u8Buff, format, ap); 

    /* Write a string to LCD */
    HD44780_Write(u8Buff, sizeof(u8Buff));

    va_end(ap);
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description:  The following have special meaning:  
 *                \f  Clear display                   
 *                \n  Go to start of second line  
 *                \b  Move back one position  
 *===================================================================================================================*/
void HD44780_Putc(U8 u8CharToLcd)
{
    switch(u8CharToLcd)
    {
    case '\f': 	HD44780_SendByte(1,0);
        HD44780_DelayUs(120ul);
        break;
    case '\n': 	HD44780_GotoXY(1,2);
        break;	
    case '\b': 	HD44780_SendByte(0x10,0);
        break;		
    default:	HD44780_SendByte(u8CharToLcd, 1);
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
static void HD44780_SendByte(U8 u8ByteToLcd, U8 u8Address)
{
    _DioWritePin(cDioPin_Lcd_RS, 0);
    HD44780_DelayUs(20);
    _DioWritePin(cDioPin_Lcd_RS, (u8Address & 0x01));
    Nop();
    Nop();
    Nop();
    _DioWritePin(cDioPin_LcdEnable, 0);
    HD44780_SendNibble((u8ByteToLcd >> 4) & 0x0Fu);
    HD44780_SendNibble(u8ByteToLcd & 0x0Fu);
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
static void HD44780_SendNibble(U8 u8Nibble)
{
    _LcdDataWrite(u8Nibble);
    Nop();
    Nop();
    Nop();
    _DioWritePin(cDioPin_LcdEnable, 1);
    HD44780_DelayUs(10);
    _DioWritePin(cDioPin_LcdEnable, 0);
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
static void HD44780_DelayUs(U16 u16DelayUs)
{
#define cWhileLoopOverhead      12ul
#define cOneUsLoopScaled        (U32)((1000.0 * 1024.0) / (cTcy_Ns * (F32)cWhileLoopOverhead))

    volatile U32 u32Time;

    u32Time = (cOneUsLoopScaled * (U32)u16DelayUs) >> 10;
    while(u32Time--);
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
static void HD44780_Write(U8 *pBuff, U8 u8Len)
{
    U8 u8LenL = u8Len;

    while((*pBuff != '\0') && (u8LenL != 0))
    {
        HD44780_SendByte(*pBuff, 1);
        pBuff++;
        u8LenL--;
    }
}
