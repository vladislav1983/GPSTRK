/*-------------------------------------------------------------------------
 * MPLAB-Cxx  PIC24FJ128GA308 processor header
 *
 * (c) Copyright 1999-2011 Microchip Technology, All rights reserved
 *-------------------------------------------------------------------------*/

#ifndef __PIC24FJ128GA308__
#error "Include file does not match processor setting"
#endif

#ifndef __24FJ128GA308_H
#define __24FJ128GA308_H

extern volatile unsigned int  WREG0 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG1 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG2 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG3 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG4 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG5 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG6 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG7 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG8 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG9 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG10 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG11 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG12 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG13 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG14 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG15 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  SPLIM __attribute__((__sfr__));
extern volatile unsigned int  PCL __attribute__((__sfr__));
extern volatile unsigned char PCH __attribute__((__sfr__));
extern volatile unsigned int  DSRPAG __attribute__((__sfr__));
extern volatile unsigned int  DSWPAG __attribute__((__sfr__));
extern volatile unsigned int  RCOUNT __attribute__((__sfr__));
extern volatile unsigned int  SR __attribute__((__sfr__));
__extension__ typedef struct tagSRBITS {
  union {
    struct {
      unsigned C:1;
      unsigned Z:1;
      unsigned OV:1;
      unsigned N:1;
      unsigned RA:1;
      unsigned IPL:3;
      unsigned DC:1;
    };
    struct {
      unsigned :5;
      unsigned IPL0:1;
      unsigned IPL1:1;
      unsigned IPL2:1;
    };
  };
} SRBITS;
extern volatile SRBITS SRbits __attribute__((__sfr__));

extern volatile unsigned int  CORCON __attribute__((__sfr__));
typedef struct tagCORCONBITS {
  unsigned :3;
  unsigned IPL3:1;
} CORCONBITS;
extern volatile CORCONBITS CORCONbits __attribute__((__sfr__));

extern volatile unsigned int  DISICNT __attribute__((__sfr__));
extern volatile unsigned int  TBLPAG __attribute__((__sfr__));
extern volatile unsigned int  CNPD1 __attribute__((__sfr__));
typedef struct tagCNPD1BITS {
  unsigned :2;
  unsigned CN2PDE:1;
  unsigned CN3PDE:1;
  unsigned CN4PDE:1;
  unsigned CN5PDE:1;
  unsigned CN6PDE:1;
  unsigned CN7PDE:1;
  unsigned CN8PDE:1;
  unsigned CN9PDE:1;
  unsigned CN10PDE:1;
  unsigned CN11PDE:1;
  unsigned CN12PDE:1;
  unsigned CN13PDE:1;
  unsigned CN14PDE:1;
  unsigned CN15PDE:1;
} CNPD1BITS;
extern volatile CNPD1BITS CNPD1bits __attribute__((__sfr__));

extern volatile unsigned int  CNPD2 __attribute__((__sfr__));
typedef struct tagCNPD2BITS {
  unsigned CN16PDE:1;
  unsigned CN17PDE:1;
  unsigned CN18PDE:1;
  unsigned CN19PDE:1;
  unsigned CN20PDE:1;
  unsigned CN21PDE:1;
  unsigned CN22PDE:1;
  unsigned CN23PDE:1;
  unsigned CN24PDE:1;
  unsigned CN25PDE:1;
  unsigned CN26PDE:1;
  unsigned CN27PDE:1;
  unsigned CN28PDE:1;
  unsigned CN29PDE:1;
  unsigned CN30PDE:1;
  unsigned CN31PDE:1;
} CNPD2BITS;
extern volatile CNPD2BITS CNPD2bits __attribute__((__sfr__));

extern volatile unsigned int  CNPD3 __attribute__((__sfr__));
typedef struct tagCNPD3BITS {
  unsigned CN32PDE:1;
  unsigned :8;
  unsigned CN41PDE:1;
  unsigned CN42PDE:1;
  unsigned CN43PDE:1;
  unsigned CN44PDE:1;
  unsigned CN45PDE:1;
  unsigned CN46PDE:1;
  unsigned CN47PDE:1;
} CNPD3BITS;
extern volatile CNPD3BITS CNPD3bits __attribute__((__sfr__));

extern volatile unsigned int  CNPD4 __attribute__((__sfr__));
typedef struct tagCNPD4BITS {
  unsigned :1;
  unsigned CN49PDE:1;
  unsigned CN50PDE:1;
  unsigned CN51PDE:1;
  unsigned CN52PDE:1;
  unsigned CN53PDE:1;
  unsigned CN54PDE:1;
  unsigned CN55PDE:1;
  unsigned CN56PDE:1;
  unsigned CN57PDE:1;
  unsigned CN58PDE:1;
  unsigned CN59PDE:1;
  unsigned CN60PDE:1;
  unsigned CN61PDE:1;
  unsigned CN62PDE:1;
  unsigned CN63PDE:1;
} CNPD4BITS;
extern volatile CNPD4BITS CNPD4bits __attribute__((__sfr__));

extern volatile unsigned int  CNPD5 __attribute__((__sfr__));
typedef struct tagCNPD5BITS {
  unsigned CN64PDE:1;
  unsigned CN65PDE:1;
  unsigned CN66PDE:1;
  unsigned CN67PDE:1;
  unsigned CN68PDE:1;
  unsigned CN69PDE:1;
  unsigned CN70PDE:1;
  unsigned CN71PDE:1;
  unsigned CN72PDE:1;
  unsigned CN73PDE:1;
  unsigned CN74PDE:1;
  unsigned :2;
  unsigned CN77PDE:1;
  unsigned CN78PDE:1;
} CNPD5BITS;
extern volatile CNPD5BITS CNPD5bits __attribute__((__sfr__));

extern volatile unsigned int  CNPD6 __attribute__((__sfr__));
typedef struct tagCNPD6BITS {
  unsigned :3;
  unsigned CN83PDE:1;
  unsigned CN84PDE:1;
} CNPD6BITS;
extern volatile CNPD6BITS CNPD6bits __attribute__((__sfr__));

extern volatile unsigned int  CNEN1 __attribute__((__sfr__));
typedef struct tagCNEN1BITS {
  unsigned :2;
  unsigned CN2IE:1;
  unsigned CN3IE:1;
  unsigned CN4IE:1;
  unsigned CN5IE:1;
  unsigned CN6IE:1;
  unsigned CN7IE:1;
  unsigned CN8IE:1;
  unsigned CN9IE:1;
  unsigned CN10IE:1;
  unsigned CN11IE:1;
  unsigned CN12IE:1;
  unsigned CN13IE:1;
  unsigned CN14IE:1;
  unsigned CN15IE:1;
} CNEN1BITS;
extern volatile CNEN1BITS CNEN1bits __attribute__((__sfr__));

extern volatile unsigned int  CNEN2 __attribute__((__sfr__));
typedef struct tagCNEN2BITS {
  unsigned CN16IE:1;
  unsigned CN17IE:1;
  unsigned CN18IE:1;
  unsigned CN19IE:1;
  unsigned CN20IE:1;
  unsigned CN21IE:1;
  unsigned CN22IE:1;
  unsigned CN23IE:1;
  unsigned CN24IE:1;
  unsigned CN25IE:1;
  unsigned CN26IE:1;
  unsigned CN27IE:1;
  unsigned CN28IE:1;
  unsigned CN29IE:1;
  unsigned CN30IE:1;
  unsigned CN31IE:1;
} CNEN2BITS;
extern volatile CNEN2BITS CNEN2bits __attribute__((__sfr__));

extern volatile unsigned int  CNEN3 __attribute__((__sfr__));
typedef struct tagCNEN3BITS {
  unsigned CN32IE:1;
  unsigned :8;
  unsigned CN41IE:1;
  unsigned CN42IE:1;
  unsigned CN43IE:1;
  unsigned CN44IE:1;
  unsigned CN45IE:1;
  unsigned CN46IE:1;
  unsigned CN47IE:1;
} CNEN3BITS;
extern volatile CNEN3BITS CNEN3bits __attribute__((__sfr__));

extern volatile unsigned int  CNEN4 __attribute__((__sfr__));
typedef struct tagCNEN4BITS {
  unsigned :1;
  unsigned CN49IE:1;
  unsigned CN50IE:1;
  unsigned CN51IE:1;
  unsigned CN52IE:1;
  unsigned CN53IE:1;
  unsigned CN54IE:1;
  unsigned CN55IE:1;
  unsigned CN56IE:1;
  unsigned CN57IE:1;
  unsigned CN58IE:1;
  unsigned CN59IE:1;
  unsigned CN60IE:1;
  unsigned CN61IE:1;
  unsigned CN62IE:1;
  unsigned CN63IE:1;
} CNEN4BITS;
extern volatile CNEN4BITS CNEN4bits __attribute__((__sfr__));

extern volatile unsigned int  CNEN5 __attribute__((__sfr__));
typedef struct tagCNEN5BITS {
  unsigned CN64IE:1;
  unsigned CN65IE:1;
  unsigned CN66IE:1;
  unsigned CN67IE:1;
  unsigned CN68IE:1;
  unsigned CN69IE:1;
  unsigned CN70IE:1;
  unsigned CN71IE:1;
  unsigned CN72IE:1;
  unsigned CN73IE:1;
  unsigned CN74IE:1;
  unsigned :2;
  unsigned CN77IE:1;
  unsigned CN78IE:1;
} CNEN5BITS;
extern volatile CNEN5BITS CNEN5bits __attribute__((__sfr__));

extern volatile unsigned int  CNEN6 __attribute__((__sfr__));
typedef struct tagCNEN6BITS {
  unsigned :3;
  unsigned CN83IE:1;
  unsigned CN84IE:1;
} CNEN6BITS;
extern volatile CNEN6BITS CNEN6bits __attribute__((__sfr__));

extern volatile unsigned int  CNPU1 __attribute__((__sfr__));
typedef struct tagCNPU1BITS {
  unsigned :2;
  unsigned CN2PUE:1;
  unsigned CN3PUE:1;
  unsigned CN4PUE:1;
  unsigned CN5PUE:1;
  unsigned CN6PUE:1;
  unsigned CN7PUE:1;
  unsigned CN8PUE:1;
  unsigned CN9PUE:1;
  unsigned CN10PUE:1;
  unsigned CN11PUE:1;
  unsigned CN12PUE:1;
  unsigned CN13PUE:1;
  unsigned CN14PUE:1;
  unsigned CN15PUE:1;
} CNPU1BITS;
extern volatile CNPU1BITS CNPU1bits __attribute__((__sfr__));

extern volatile unsigned int  CNPU2 __attribute__((__sfr__));
typedef struct tagCNPU2BITS {
  unsigned CN16PUE:1;
  unsigned CN17PUE:1;
  unsigned CN18PUE:1;
  unsigned CN19PUE:1;
  unsigned CN20PUE:1;
  unsigned CN21PUE:1;
  unsigned CN22PUE:1;
  unsigned CN23PUE:1;
  unsigned CN24PUE:1;
  unsigned CN25PUE:1;
  unsigned CN26PUE:1;
  unsigned CN27PUE:1;
  unsigned CN28PUE:1;
  unsigned CN29PUE:1;
  unsigned CN30PUE:1;
  unsigned CN31PUE:1;
} CNPU2BITS;
extern volatile CNPU2BITS CNPU2bits __attribute__((__sfr__));

extern volatile unsigned int  CNPU3 __attribute__((__sfr__));
typedef struct tagCNPU3BITS {
  unsigned CN32PUE:1;
  unsigned :8;
  unsigned CN41PUE:1;
  unsigned CN42PUE:1;
  unsigned CN43PUE:1;
  unsigned CN44PUE:1;
  unsigned CN45PUE:1;
  unsigned CN46PUE:1;
  unsigned CN47PUE:1;
} CNPU3BITS;
extern volatile CNPU3BITS CNPU3bits __attribute__((__sfr__));

extern volatile unsigned int  CNPU4 __attribute__((__sfr__));
typedef struct tagCNPU4BITS {
  unsigned :1;
  unsigned CN49PUE:1;
  unsigned CN50PUE:1;
  unsigned CN51PUE:1;
  unsigned CN52PUE:1;
  unsigned CN53PUE:1;
  unsigned CN54PUE:1;
  unsigned CN55PUE:1;
  unsigned CN56PUE:1;
  unsigned CN57PUE:1;
  unsigned CN58PUE:1;
  unsigned CN59PUE:1;
  unsigned CN60PUE:1;
  unsigned CN61PUE:1;
  unsigned CN62PUE:1;
  unsigned CN63PUE:1;
} CNPU4BITS;
extern volatile CNPU4BITS CNPU4bits __attribute__((__sfr__));

extern volatile unsigned int  CNPU5 __attribute__((__sfr__));
typedef struct tagCNPU5BITS {
  unsigned CN64PUE:1;
  unsigned CN65PUE:1;
  unsigned CN66PUE:1;
  unsigned CN67PUE:1;
  unsigned CN68PUE:1;
  unsigned CN69PUE:1;
  unsigned CN70PUE:1;
  unsigned CN71PUE:1;
  unsigned CN72PUE:1;
  unsigned CN73PUE:1;
  unsigned CN74PUE:1;
  unsigned :2;
  unsigned CN77PUE:1;
  unsigned CN78PUE:1;
} CNPU5BITS;
extern volatile CNPU5BITS CNPU5bits __attribute__((__sfr__));

extern volatile unsigned int  CNPU6 __attribute__((__sfr__));
typedef struct tagCNPU6BITS {
  unsigned :3;
  unsigned CN83PUE:1;
  unsigned CN84PUE:1;
} CNPU6BITS;
extern volatile CNPU6BITS CNPU6bits __attribute__((__sfr__));

extern volatile unsigned int  INTCON1 __attribute__((__sfr__));
typedef struct tagINTCON1BITS {
  unsigned :1;
  unsigned OSCFAIL:1;
  unsigned STKERR:1;
  unsigned ADDRERR:1;
  unsigned MATHERR:1;
  unsigned :10;
  unsigned NSTDIS:1;
} INTCON1BITS;
extern volatile INTCON1BITS INTCON1bits __attribute__((__sfr__));

extern volatile unsigned int  INTCON2 __attribute__((__sfr__));
typedef struct tagINTCON2BITS {
  unsigned INT0EP:1;
  unsigned INT1EP:1;
  unsigned INT2EP:1;
  unsigned INT3EP:1;
  unsigned INT4EP:1;
  unsigned :9;
  unsigned DISI:1;
  unsigned ALTIVT:1;
} INTCON2BITS;
extern volatile INTCON2BITS INTCON2bits __attribute__((__sfr__));

extern volatile unsigned int  IFS0 __attribute__((__sfr__));
typedef struct tagIFS0BITS {
  unsigned INT0IF:1;
  unsigned IC1IF:1;
  unsigned OC1IF:1;
  unsigned T1IF:1;
  unsigned DMA0IF:1;
  unsigned IC2IF:1;
  unsigned OC2IF:1;
  unsigned T2IF:1;
  unsigned T3IF:1;
  unsigned SPF1IF:1;
  unsigned SPI1IF:1;
  unsigned U1RXIF:1;
  unsigned U1TXIF:1;
  unsigned AD1IF:1;
  unsigned DMA1IF:1;
} IFS0BITS;
extern volatile IFS0BITS IFS0bits __attribute__((__sfr__));

extern volatile unsigned int  IFS1 __attribute__((__sfr__));
typedef struct tagIFS1BITS {
  unsigned SI2C1IF:1;
  unsigned MI2C1IF:1;
  unsigned CMIF:1;
  unsigned CNIF:1;
  unsigned INT1IF:1;
  unsigned :1;
  unsigned IC7IF:1;
  unsigned :1;
  unsigned DMA2IF:1;
  unsigned OC3IF:1;
  unsigned OC4IF:1;
  unsigned T4IF:1;
  unsigned T5IF:1;
  unsigned INT2IF:1;
  unsigned U2RXIF:1;
  unsigned U2TXIF:1;
} IFS1BITS;
extern volatile IFS1BITS IFS1bits __attribute__((__sfr__));

extern volatile unsigned int  IFS2 __attribute__((__sfr__));
typedef struct tagIFS2BITS {
  unsigned SPF2IF:1;
  unsigned SPI2IF:1;
  unsigned :2;
  unsigned DMA3IF:1;
  unsigned IC3IF:1;
  unsigned IC4IF:1;
  unsigned IC5IF:1;
  unsigned IC6IF:1;
  unsigned OC5IF:1;
  unsigned OC6IF:1;
  unsigned OC7IF:1;
  unsigned :1;
  unsigned PMPIF:1;
  unsigned DMA4IF:1;
} IFS2BITS;
extern volatile IFS2BITS IFS2bits __attribute__((__sfr__));

extern volatile unsigned int  IFS3 __attribute__((__sfr__));
typedef struct tagIFS3BITS {
  unsigned :1;
  unsigned SI2C2IF:1;
  unsigned MI2C2IF:1;
  unsigned :2;
  unsigned INT3IF:1;
  unsigned INT4IF:1;
  unsigned :6;
  unsigned DMA5IF:1;
  unsigned RTCIF:1;
} IFS3BITS;
extern volatile IFS3BITS IFS3bits __attribute__((__sfr__));

extern volatile unsigned int  IFS4 __attribute__((__sfr__));
typedef struct tagIFS4BITS {
  unsigned :1;
  unsigned U1ERIF:1;
  unsigned U2ERIF:1;
  unsigned CRCIF:1;
  unsigned :4;
  unsigned LVDIF:1;
  unsigned :4;
  unsigned CTMUIF:1;
} IFS4BITS;
extern volatile IFS4BITS IFS4bits __attribute__((__sfr__));

extern volatile unsigned int  IFS5 __attribute__((__sfr__));
typedef struct tagIFS5BITS {
  unsigned :1;
  unsigned U3ERIF:1;
  unsigned U3RXIF:1;
  unsigned U3TXIF:1;
  unsigned :3;
  unsigned U4ERIF:1;
  unsigned U4RXIF:1;
  unsigned U4TXIF:1;
} IFS5BITS;
extern volatile IFS5BITS IFS5bits __attribute__((__sfr__));

extern volatile unsigned int  IFS6 __attribute__((__sfr__));
typedef struct tagIFS6BITS {
  unsigned :4;
  unsigned LCDIF:1;
} IFS6BITS;
extern volatile IFS6BITS IFS6bits __attribute__((__sfr__));

extern volatile unsigned int  IFS7 __attribute__((__sfr__));
typedef struct tagIFS7BITS {
  unsigned :5;
  unsigned JTAGIF:1;
} IFS7BITS;
extern volatile IFS7BITS IFS7bits __attribute__((__sfr__));

extern volatile unsigned int  IEC0 __attribute__((__sfr__));
typedef struct tagIEC0BITS {
  unsigned INT0IE:1;
  unsigned IC1IE:1;
  unsigned OC1IE:1;
  unsigned T1IE:1;
  unsigned DMA0IE:1;
  unsigned IC2IE:1;
  unsigned OC2IE:1;
  unsigned T2IE:1;
  unsigned T3IE:1;
  unsigned SPF1IE:1;
  unsigned SPI1IE:1;
  unsigned U1RXIE:1;
  unsigned U1TXIE:1;
  unsigned AD1IE:1;
  unsigned DMA1IE:1;
} IEC0BITS;
extern volatile IEC0BITS IEC0bits __attribute__((__sfr__));

extern volatile unsigned int  IEC1 __attribute__((__sfr__));
typedef struct tagIEC1BITS {
  unsigned SI2C1IE:1;
  unsigned MI2C1IE:1;
  unsigned CMIE:1;
  unsigned CNIE:1;
  unsigned INT1IE:1;
  unsigned :1;
  unsigned IC7IE:1;
  unsigned :1;
  unsigned DMA2IE:1;
  unsigned OC3IE:1;
  unsigned OC4IE:1;
  unsigned T4IE:1;
  unsigned T5IE:1;
  unsigned INT2IE:1;
  unsigned U2RXIE:1;
  unsigned U2TXIE:1;
} IEC1BITS;
extern volatile IEC1BITS IEC1bits __attribute__((__sfr__));

extern volatile unsigned int  IEC2 __attribute__((__sfr__));
typedef struct tagIEC2BITS {
  unsigned SPF2IE:1;
  unsigned SPI2IE:1;
  unsigned :2;
  unsigned DMA3IE:1;
  unsigned IC3IE:1;
  unsigned IC4IE:1;
  unsigned IC5IE:1;
  unsigned IC6IE:1;
  unsigned OC5IE:1;
  unsigned OC6IE:1;
  unsigned OC7IE:1;
  unsigned :1;
  unsigned PMPIE:1;
  unsigned DMA4IE:1;
} IEC2BITS;
extern volatile IEC2BITS IEC2bits __attribute__((__sfr__));

extern volatile unsigned int  IEC3 __attribute__((__sfr__));
typedef struct tagIEC3BITS {
  unsigned :1;
  unsigned SI2C2IE:1;
  unsigned MI2C2IE:1;
  unsigned :2;
  unsigned INT3IE:1;
  unsigned INT4IE:1;
  unsigned :6;
  unsigned DMA5IE:1;
  unsigned RTCIE:1;
} IEC3BITS;
extern volatile IEC3BITS IEC3bits __attribute__((__sfr__));

extern volatile unsigned int  IEC4 __attribute__((__sfr__));
typedef struct tagIEC4BITS {
  unsigned :1;
  unsigned U1ERIE:1;
  unsigned U2ERIE:1;
  unsigned CRCIE:1;
  unsigned :4;
  unsigned LVDIE:1;
  unsigned :4;
  unsigned CTMUIE:1;
} IEC4BITS;
extern volatile IEC4BITS IEC4bits __attribute__((__sfr__));

extern volatile unsigned int  IEC5 __attribute__((__sfr__));
typedef struct tagIEC5BITS {
  unsigned :1;
  unsigned U3ERIE:1;
  unsigned U3RXIE:1;
  unsigned U3TXIE:1;
  unsigned :3;
  unsigned U4ERIE:1;
  unsigned U4RXIE:1;
  unsigned U4TXIE:1;
} IEC5BITS;
extern volatile IEC5BITS IEC5bits __attribute__((__sfr__));

extern volatile unsigned int  IEC6 __attribute__((__sfr__));
typedef struct tagIEC6BITS {
  unsigned :4;
  unsigned LCDIE:1;
} IEC6BITS;
extern volatile IEC6BITS IEC6bits __attribute__((__sfr__));

extern volatile unsigned int  IEC7 __attribute__((__sfr__));
typedef struct tagIEC7BITS {
  unsigned :5;
  unsigned JTAGIE:1;
} IEC7BITS;
extern volatile IEC7BITS IEC7bits __attribute__((__sfr__));

extern volatile unsigned int  IPC0 __attribute__((__sfr__));
__extension__ typedef struct tagIPC0BITS {
  union {
    struct {
      unsigned INT0IP:3;
      unsigned :1;
      unsigned IC1IP:3;
      unsigned :1;
      unsigned OC1IP:3;
      unsigned :1;
      unsigned T1IP:3;
    };
    struct {
      unsigned INT0IP0:1;
      unsigned INT0IP1:1;
      unsigned INT0IP2:1;
      unsigned :1;
      unsigned IC1IP0:1;
      unsigned IC1IP1:1;
      unsigned IC1IP2:1;
      unsigned :1;
      unsigned OC1IP0:1;
      unsigned OC1IP1:1;
      unsigned OC1IP2:1;
      unsigned :1;
      unsigned T1IP0:1;
      unsigned T1IP1:1;
      unsigned T1IP2:1;
    };
  };
} IPC0BITS;
extern volatile IPC0BITS IPC0bits __attribute__((__sfr__));

extern volatile unsigned int  IPC1 __attribute__((__sfr__));
__extension__ typedef struct tagIPC1BITS {
  union {
    struct {
      unsigned DMA0IP:3;
      unsigned :1;
      unsigned IC2IP:3;
      unsigned :1;
      unsigned OC2IP:3;
      unsigned :1;
      unsigned T2IP:3;
    };
    struct {
      unsigned DMA0IP0:1;
      unsigned DMA0IP1:1;
      unsigned DMA0IP2:1;
      unsigned :1;
      unsigned IC2IP0:1;
      unsigned IC2IP1:1;
      unsigned IC2IP2:1;
      unsigned :1;
      unsigned OC2IP0:1;
      unsigned OC2IP1:1;
      unsigned OC2IP2:1;
      unsigned :1;
      unsigned T2IP0:1;
      unsigned T2IP1:1;
      unsigned T2IP2:1;
    };
  };
} IPC1BITS;
extern volatile IPC1BITS IPC1bits __attribute__((__sfr__));

extern volatile unsigned int  IPC2 __attribute__((__sfr__));
__extension__ typedef struct tagIPC2BITS {
  union {
    struct {
      unsigned T3IP:3;
      unsigned :1;
      unsigned SPF1IP:3;
      unsigned :1;
      unsigned SPI1IP:3;
      unsigned :1;
      unsigned U1RXIP:3;
    };
    struct {
      unsigned T3IP0:1;
      unsigned T3IP1:1;
      unsigned T3IP2:1;
      unsigned :1;
      unsigned SPF1IP0:1;
      unsigned SPF1IP1:1;
      unsigned SPF1IP2:1;
      unsigned :1;
      unsigned SPI1IP0:1;
      unsigned SPI1IP1:1;
      unsigned SPI1IP2:1;
      unsigned :1;
      unsigned U1RXIP0:1;
      unsigned U1RXIP1:1;
      unsigned U1RXIP2:1;
    };
  };
} IPC2BITS;
extern volatile IPC2BITS IPC2bits __attribute__((__sfr__));

extern volatile unsigned int  IPC3 __attribute__((__sfr__));
__extension__ typedef struct tagIPC3BITS {
  union {
    struct {
      unsigned U1TXIP:3;
      unsigned :1;
      unsigned AD1IP:3;
      unsigned :1;
      unsigned DMA1IP:3;
    };
    struct {
      unsigned U1TXIP0:1;
      unsigned U1TXIP1:1;
      unsigned U1TXIP2:1;
      unsigned :1;
      unsigned AD1IP0:1;
      unsigned AD1IP1:1;
      unsigned AD1IP2:1;
      unsigned :1;
      unsigned DMA1IP0:1;
      unsigned DMA1IP1:1;
      unsigned DMA1IP2:1;
    };
  };
} IPC3BITS;
extern volatile IPC3BITS IPC3bits __attribute__((__sfr__));

extern volatile unsigned int  IPC4 __attribute__((__sfr__));
__extension__ typedef struct tagIPC4BITS {
  union {
    struct {
      unsigned SI2C1IP:3;
      unsigned :1;
      unsigned MI2C1IP:3;
      unsigned :1;
      unsigned CMIP:3;
      unsigned :1;
      unsigned CNIP:3;
    };
    struct {
      unsigned SI2C1IP0:1;
      unsigned SI2C1IP1:1;
      unsigned SI2C1IP2:1;
      unsigned :1;
      unsigned MI2C1IP0:1;
      unsigned MI2C1IP1:1;
      unsigned MI2C1IP2:1;
      unsigned :1;
      unsigned CMIP0:1;
      unsigned CMIP1:1;
      unsigned CMIP2:1;
      unsigned :1;
      unsigned CNIP0:1;
      unsigned CNIP1:1;
      unsigned CNIP2:1;
    };
    struct {
      unsigned SI2C1P:3;
      unsigned :1;
      unsigned MI2C1P:3;
    };
    struct {
      unsigned SI2C1P0:1;
      unsigned SI2C1P1:1;
      unsigned SI2C1P2:1;
      unsigned :1;
      unsigned MI2C1P0:1;
      unsigned MI2C1P1:1;
      unsigned MI2C1P2:1;
    };
  };
} IPC4BITS;
extern volatile IPC4BITS IPC4bits __attribute__((__sfr__));

extern volatile unsigned int  IPC5 __attribute__((__sfr__));
__extension__ typedef struct tagIPC5BITS {
  union {
    struct {
      unsigned INT1IP:3;
      unsigned :5;
      unsigned IC7IP:3;
    };
    struct {
      unsigned INT1IP0:1;
      unsigned INT1IP1:1;
      unsigned INT1IP2:1;
      unsigned :5;
      unsigned IC7IP0:1;
      unsigned IC7IP1:1;
      unsigned IC7IP2:1;
    };
  };
} IPC5BITS;
extern volatile IPC5BITS IPC5bits __attribute__((__sfr__));

extern volatile unsigned int  IPC6 __attribute__((__sfr__));
__extension__ typedef struct tagIPC6BITS {
  union {
    struct {
      unsigned DMA2IP:3;
      unsigned :1;
      unsigned OC3IP:3;
      unsigned :1;
      unsigned OC4IP:3;
      unsigned :1;
      unsigned T4IP:3;
    };
    struct {
      unsigned DMA2IP0:1;
      unsigned DMA2IP1:1;
      unsigned DMA2IP2:1;
      unsigned :1;
      unsigned OC3IP0:1;
      unsigned OC3IP1:1;
      unsigned OC3IP2:1;
      unsigned :1;
      unsigned OC4IP0:1;
      unsigned OC4IP1:1;
      unsigned OC4IP2:1;
      unsigned :1;
      unsigned T4IP0:1;
      unsigned T4IP1:1;
      unsigned T4IP2:1;
    };
  };
} IPC6BITS;
extern volatile IPC6BITS IPC6bits __attribute__((__sfr__));

extern volatile unsigned int  IPC7 __attribute__((__sfr__));
__extension__ typedef struct tagIPC7BITS {
  union {
    struct {
      unsigned T5IP:3;
      unsigned :1;
      unsigned INT2IP:3;
      unsigned :1;
      unsigned U2RXIP:3;
      unsigned :1;
      unsigned U2TXIP:3;
    };
    struct {
      unsigned T5IP0:1;
      unsigned T5IP1:1;
      unsigned T5IP2:1;
      unsigned :1;
      unsigned INT2IP0:1;
      unsigned INT2IP1:1;
      unsigned INT2IP2:1;
      unsigned :1;
      unsigned U2RXIP0:1;
      unsigned U2RXIP1:1;
      unsigned U2RXIP2:1;
      unsigned :1;
      unsigned U2TXIP0:1;
      unsigned U2TXIP1:1;
      unsigned U2TXIP2:1;
    };
  };
} IPC7BITS;
extern volatile IPC7BITS IPC7bits __attribute__((__sfr__));

extern volatile unsigned int  IPC8 __attribute__((__sfr__));
__extension__ typedef struct tagIPC8BITS {
  union {
    struct {
      unsigned SPF2IP:3;
      unsigned :1;
      unsigned SPI2IP:3;
    };
    struct {
      unsigned SPF2IP0:1;
      unsigned SPF2IP1:1;
      unsigned SPF2IP2:1;
      unsigned :1;
      unsigned SPI2IP0:1;
      unsigned SPI2IP1:1;
      unsigned SPI2IP2:1;
    };
  };
} IPC8BITS;
extern volatile IPC8BITS IPC8bits __attribute__((__sfr__));

extern volatile unsigned int  IPC9 __attribute__((__sfr__));
__extension__ typedef struct tagIPC9BITS {
  union {
    struct {
      unsigned DMA3IP:3;
      unsigned :1;
      unsigned IC3IP:3;
      unsigned :1;
      unsigned IC4IP:3;
      unsigned :1;
      unsigned IC5IP:3;
    };
    struct {
      unsigned DMA3IP0:1;
      unsigned DMA3IP1:1;
      unsigned DMA3IP2:1;
      unsigned :1;
      unsigned IC3IP0:1;
      unsigned IC3IP1:1;
      unsigned IC3IP2:1;
      unsigned :1;
      unsigned IC4IP0:1;
      unsigned IC4IP1:1;
      unsigned IC4IP2:1;
      unsigned :1;
      unsigned IC5IP0:1;
      unsigned IC5IP1:1;
      unsigned IC5IP2:1;
    };
  };
} IPC9BITS;
extern volatile IPC9BITS IPC9bits __attribute__((__sfr__));

extern volatile unsigned int  IPC10 __attribute__((__sfr__));
__extension__ typedef struct tagIPC10BITS {
  union {
    struct {
      unsigned IC6IP:3;
      unsigned :1;
      unsigned OC5IP:3;
      unsigned :1;
      unsigned OC6IP:3;
      unsigned :1;
      unsigned OC7IP:3;
    };
    struct {
      unsigned IC6IP0:1;
      unsigned IC6IP1:1;
      unsigned IC6IP2:1;
      unsigned :1;
      unsigned OC5IP0:1;
      unsigned OC5IP1:1;
      unsigned OC5IP2:1;
      unsigned :1;
      unsigned OC6IP0:1;
      unsigned OC6IP1:1;
      unsigned OC6IP2:1;
      unsigned :1;
      unsigned OC7IP0:1;
      unsigned OC7IP1:1;
      unsigned OC7IP2:1;
    };
  };
} IPC10BITS;
extern volatile IPC10BITS IPC10bits __attribute__((__sfr__));

extern volatile unsigned int  IPC11 __attribute__((__sfr__));
__extension__ typedef struct tagIPC11BITS {
  union {
    struct {
      unsigned :4;
      unsigned PMPIP:3;
      unsigned :1;
      unsigned DMA4IP:3;
    };
    struct {
      unsigned :4;
      unsigned PMPIP0:1;
      unsigned PMPIP1:1;
      unsigned PMPIP2:1;
      unsigned :1;
      unsigned DMA4IP0:1;
      unsigned DMA4IP1:1;
      unsigned DMA4IP2:1;
    };
  };
} IPC11BITS;
extern volatile IPC11BITS IPC11bits __attribute__((__sfr__));

extern volatile unsigned int  IPC12 __attribute__((__sfr__));
__extension__ typedef struct tagIPC12BITS {
  union {
    struct {
      unsigned :4;
      unsigned SI2C2IP:3;
      unsigned :1;
      unsigned MI2C2IP:3;
    };
    struct {
      unsigned :4;
      unsigned SI2C2IP0:1;
      unsigned SI2C2IP1:1;
      unsigned SI2C2IP2:1;
      unsigned :1;
      unsigned MI2C2IP0:1;
      unsigned MI2C2IP1:1;
      unsigned MI2C2IP2:1;
    };
    struct {
      unsigned :4;
      unsigned SI2C2P0:1;
      unsigned SI2C2P1:1;
      unsigned SI2C2P2:1;
      unsigned :1;
      unsigned MI2C2P0:1;
      unsigned MI2C2P1:1;
      unsigned MI2C2P2:1;
    };
    struct {
      unsigned :4;
      unsigned SI2C2P:3;
      unsigned :1;
      unsigned MI2C2P:3;
    };
  };
} IPC12BITS;
extern volatile IPC12BITS IPC12bits __attribute__((__sfr__));

extern volatile unsigned int  IPC13 __attribute__((__sfr__));
__extension__ typedef struct tagIPC13BITS {
  union {
    struct {
      unsigned :4;
      unsigned INT3IP:3;
      unsigned :1;
      unsigned INT4IP:3;
    };
    struct {
      unsigned :4;
      unsigned INT3IP0:1;
      unsigned INT3IP1:1;
      unsigned INT3IP2:1;
      unsigned :1;
      unsigned INT4IP0:1;
      unsigned INT4IP1:1;
      unsigned INT4IP2:1;
    };
  };
} IPC13BITS;
extern volatile IPC13BITS IPC13bits __attribute__((__sfr__));

extern volatile unsigned int  IPC15 __attribute__((__sfr__));
__extension__ typedef struct tagIPC15BITS {
  union {
    struct {
      unsigned :4;
      unsigned DMA5IP:3;
      unsigned :1;
      unsigned RTCIP:3;
    };
    struct {
      unsigned :4;
      unsigned DMA5IP0:1;
      unsigned DMA5IP1:1;
      unsigned DMA5IP2:1;
      unsigned :1;
      unsigned RTCIP0:1;
      unsigned RTCIP1:1;
      unsigned RTCIP2:1;
    };
  };
} IPC15BITS;
extern volatile IPC15BITS IPC15bits __attribute__((__sfr__));

extern volatile unsigned int  IPC16 __attribute__((__sfr__));
__extension__ typedef struct tagIPC16BITS {
  union {
    struct {
      unsigned :4;
      unsigned U1ERIP:3;
      unsigned :1;
      unsigned U2ERIP:3;
      unsigned :1;
      unsigned CRCIP:3;
    };
    struct {
      unsigned :4;
      unsigned U1ERIP0:1;
      unsigned U1ERIP1:1;
      unsigned U1ERIP2:1;
      unsigned :1;
      unsigned U2ERIP0:1;
      unsigned U2ERIP1:1;
      unsigned U2ERIP2:1;
      unsigned :1;
      unsigned CRCIP0:1;
      unsigned CRCIP1:1;
      unsigned CRCIP2:1;
    };
  };
} IPC16BITS;
extern volatile IPC16BITS IPC16bits __attribute__((__sfr__));

extern volatile unsigned int  IPC18 __attribute__((__sfr__));
__extension__ typedef struct tagIPC18BITS {
  union {
    struct {
      unsigned LVDIP:3;
    };
    struct {
      unsigned LVDIP0:1;
      unsigned LVDIP1:1;
      unsigned LVDIP2:1;
    };
  };
} IPC18BITS;
extern volatile IPC18BITS IPC18bits __attribute__((__sfr__));

extern volatile unsigned int  IPC19 __attribute__((__sfr__));
__extension__ typedef struct tagIPC19BITS {
  union {
    struct {
      unsigned :4;
      unsigned CTMUIP:3;
    };
    struct {
      unsigned :4;
      unsigned CTMUIP0:1;
      unsigned CTMUIP1:1;
      unsigned CTMUIP2:1;
    };
  };
} IPC19BITS;
extern volatile IPC19BITS IPC19bits __attribute__((__sfr__));

extern volatile unsigned int  IPC20 __attribute__((__sfr__));
__extension__ typedef struct tagIPC20BITS {
  union {
    struct {
      unsigned :4;
      unsigned U3ERIP:3;
      unsigned :1;
      unsigned U3RXIP:3;
      unsigned :1;
      unsigned U3TXIP:3;
    };
    struct {
      unsigned :4;
      unsigned U3ERIP0:1;
      unsigned U3ERIP1:1;
      unsigned U3ERIP2:1;
      unsigned :1;
      unsigned U3RXIP0:1;
      unsigned U3RXIP1:1;
      unsigned U3RXIP2:1;
      unsigned :1;
      unsigned U3TXIP0:1;
      unsigned U3TXIP1:1;
      unsigned U3TXIP2:1;
    };
  };
} IPC20BITS;
extern volatile IPC20BITS IPC20bits __attribute__((__sfr__));

extern volatile unsigned int  IPC21 __attribute__((__sfr__));
__extension__ typedef struct tagIPC21BITS {
  union {
    struct {
      unsigned :12;
      unsigned U4ERIP:3;
    };
    struct {
      unsigned :12;
      unsigned U4ERIP0:1;
      unsigned U4ERIP1:1;
      unsigned U4ERIP2:1;
    };
  };
} IPC21BITS;
extern volatile IPC21BITS IPC21bits __attribute__((__sfr__));

extern volatile unsigned int  IPC22 __attribute__((__sfr__));
__extension__ typedef struct tagIPC22BITS {
  union {
    struct {
      unsigned U4RXIP:3;
      unsigned :1;
      unsigned U4TXIP:3;
    };
    struct {
      unsigned U4RXIP0:1;
      unsigned U4RXIP1:1;
      unsigned U4RXIP2:1;
      unsigned :1;
      unsigned U4TXIP0:1;
      unsigned U4TXIP1:1;
      unsigned U4TXIP2:1;
    };
  };
} IPC22BITS;
extern volatile IPC22BITS IPC22bits __attribute__((__sfr__));

extern volatile unsigned int  IPC25 __attribute__((__sfr__));
__extension__ typedef struct tagIPC25BITS {
  union {
    struct {
      unsigned LCDIP:3;
    };
    struct {
      unsigned LCDIP0:1;
      unsigned LCDIP1:1;
      unsigned LCDIP2:1;
    };
  };
} IPC25BITS;
extern volatile IPC25BITS IPC25bits __attribute__((__sfr__));

extern volatile unsigned int  IPC29 __attribute__((__sfr__));
__extension__ typedef struct tagIPC29BITS {
  union {
    struct {
      unsigned :4;
      unsigned JTAGIP:3;
    };
    struct {
      unsigned :4;
      unsigned JTAGIP0:1;
      unsigned JTAGIP1:1;
      unsigned JTAGIP2:1;
    };
  };
} IPC29BITS;
extern volatile IPC29BITS IPC29bits __attribute__((__sfr__));

extern volatile unsigned int  INTTREG __attribute__((__sfr__));
__extension__ typedef struct tagINTTREGBITS {
  union {
    struct {
      unsigned VECNUM:7;
      unsigned :1;
      unsigned ILR:4;
      unsigned :1;
      unsigned VHOLD:1;
      unsigned :1;
      unsigned CPUIRQ:1;
    };
    struct {
      unsigned VECNUM0:1;
      unsigned VECNUM1:1;
      unsigned VECNUM2:1;
      unsigned VECNUM3:1;
      unsigned VECNUM4:1;
      unsigned VECNUM5:1;
      unsigned VECNUM6:1;
      unsigned :1;
      unsigned ILR0:1;
      unsigned ILR1:1;
      unsigned ILR2:1;
      unsigned ILR3:1;
    };
  };
} INTTREGBITS;
extern volatile INTTREGBITS INTTREGbits __attribute__((__sfr__));

extern volatile unsigned int  TMR1 __attribute__((__sfr__));
extern volatile unsigned int  PR1 __attribute__((__sfr__));
extern volatile unsigned int  T1CON __attribute__((__sfr__));
__extension__ typedef struct tagT1CONBITS {
  union {
    struct {
      unsigned :1;
      unsigned TCS:1;
      unsigned TSYNC:1;
      unsigned :1;
      unsigned TCKPS:2;
      unsigned TGATE:1;
      unsigned :1;
      unsigned TIECS:2;
      unsigned :3;
      unsigned TSIDL:1;
      unsigned :1;
      unsigned TON:1;
    };
    struct {
      unsigned :4;
      unsigned TCKPS0:1;
      unsigned TCKPS1:1;
      unsigned :2;
      unsigned T1ECS0:1;
      unsigned T1ECS1:1;
    };
  };
} T1CONBITS;
extern volatile T1CONBITS T1CONbits __attribute__((__sfr__));

extern volatile unsigned int  TMR2 __attribute__((__sfr__));
extern volatile unsigned int  TMR3HLD __attribute__((__sfr__));
extern volatile unsigned int  TMR3 __attribute__((__sfr__));
extern volatile unsigned int  PR2 __attribute__((__sfr__));
extern volatile unsigned int  PR3 __attribute__((__sfr__));
extern volatile unsigned int  T2CON __attribute__((__sfr__));
__extension__ typedef struct tagT2CONBITS {
  union {
    struct {
      unsigned :1;
      unsigned TCS:1;
      unsigned :1;
      unsigned T32:1;
      unsigned TCKPS:2;
      unsigned TGATE:1;
      unsigned :6;
      unsigned TSIDL:1;
      unsigned :1;
      unsigned TON:1;
    };
    struct {
      unsigned :4;
      unsigned TCKPS0:1;
      unsigned TCKPS1:1;
    };
  };
} T2CONBITS;
extern volatile T2CONBITS T2CONbits __attribute__((__sfr__));

extern volatile unsigned int  T3CON __attribute__((__sfr__));
__extension__ typedef struct tagT3CONBITS {
  union {
    struct {
      unsigned :1;
      unsigned TCS:1;
      unsigned :2;
      unsigned TCKPS:2;
      unsigned TGATE:1;
      unsigned :6;
      unsigned TSIDL:1;
      unsigned :1;
      unsigned TON:1;
    };
    struct {
      unsigned :4;
      unsigned TCKPS0:1;
      unsigned TCKPS1:1;
    };
  };
} T3CONBITS;
extern volatile T3CONBITS T3CONbits __attribute__((__sfr__));

extern volatile unsigned int  TMR4 __attribute__((__sfr__));
extern volatile unsigned int  TMR5HLD __attribute__((__sfr__));
extern volatile unsigned int  TMR5 __attribute__((__sfr__));
extern volatile unsigned int  PR4 __attribute__((__sfr__));
extern volatile unsigned int  PR5 __attribute__((__sfr__));
extern volatile unsigned int  T4CON __attribute__((__sfr__));
__extension__ typedef struct tagT4CONBITS {
  union {
    struct {
      unsigned :1;
      unsigned TCS:1;
      unsigned :1;
      unsigned T45:1;
      unsigned TCKPS:2;
      unsigned TGATE:1;
      unsigned :6;
      unsigned TSIDL:1;
      unsigned :1;
      unsigned TON:1;
    };
    struct {
      unsigned :4;
      unsigned TCKPS0:1;
      unsigned TCKPS1:1;
    };
  };
} T4CONBITS;
extern volatile T4CONBITS T4CONbits __attribute__((__sfr__));

extern volatile unsigned int  T5CON __attribute__((__sfr__));
__extension__ typedef struct tagT5CONBITS {
  union {
    struct {
      unsigned :1;
      unsigned TCS:1;
      unsigned :2;
      unsigned TCKPS:2;
      unsigned TGATE:1;
      unsigned :6;
      unsigned TSIDL:1;
      unsigned :1;
      unsigned TON:1;
    };
    struct {
      unsigned :4;
      unsigned TCKPS0:1;
      unsigned TCKPS1:1;
    };
  };
} T5CONBITS;
extern volatile T5CONBITS T5CONbits __attribute__((__sfr__));

extern volatile unsigned int  IC1CON1 __attribute__((__sfr__));
__extension__ typedef struct tagIC1CON1BITS {
  union {
    struct {
      unsigned ICM:3;
      unsigned ICBNE:1;
      unsigned ICOV:1;
      unsigned ICI:2;
      unsigned :3;
      unsigned ICTSEL:3;
      unsigned ICSIDL:1;
    };
    struct {
      unsigned ICM0:1;
      unsigned ICM1:1;
      unsigned ICM2:1;
      unsigned :2;
      unsigned ICI0:1;
      unsigned ICI1:1;
      unsigned :3;
      unsigned ICTSEL0:1;
      unsigned ICTSEL1:1;
      unsigned ICTSEL2:1;
    };
  };
} IC1CON1BITS;
extern volatile IC1CON1BITS IC1CON1bits __attribute__((__sfr__));

extern volatile unsigned int  IC1CON2 __attribute__((__sfr__));
__extension__ typedef struct tagIC1CON2BITS {
  union {
    struct {
      unsigned SYNCSEL:5;
      unsigned :1;
      unsigned TRIGSTAT:1;
      unsigned ICTRIG:1;
      unsigned IC32:1;
    };
    struct {
      unsigned SYNCSEL0:1;
      unsigned SYNCSEL1:1;
      unsigned SYNCSEL2:1;
      unsigned SYNCSEL3:1;
      unsigned SYNCSEL4:1;
    };
  };
} IC1CON2BITS;
extern volatile IC1CON2BITS IC1CON2bits __attribute__((__sfr__));


/* Generic structure of entire SFR area for Input Capture modules */
typedef struct tagIC {
        unsigned int icxbuf;
        unsigned int icxcon;
} IC, *PIC;

/* SFR blocks for Input Capture modules */
extern volatile IC IC1 __attribute__((__sfr__));
extern volatile IC IC2 __attribute__((__sfr__));
extern volatile IC IC3 __attribute__((__sfr__));
extern volatile IC IC4 __attribute__((__sfr__));
extern volatile IC IC5 __attribute__((__sfr__));

extern volatile unsigned int  IC1BUF __attribute__((__sfr__));
extern volatile unsigned int  IC1TMR __attribute__((__sfr__));
extern volatile unsigned int  IC2CON1 __attribute__((__sfr__));
__extension__ typedef struct tagIC2CON1BITS {
  union {
    struct {
      unsigned ICM:3;
      unsigned ICBNE:1;
      unsigned ICOV:1;
      unsigned ICI:2;
      unsigned :3;
      unsigned ICTSEL:3;
      unsigned ICSIDL:1;
    };
    struct {
      unsigned ICM0:1;
      unsigned ICM1:1;
      unsigned ICM2:1;
      unsigned :2;
      unsigned ICI0:1;
      unsigned ICI1:1;
      unsigned :3;
      unsigned ICTSEL0:1;
      unsigned ICTSEL1:1;
      unsigned ICTSEL2:1;
    };
  };
} IC2CON1BITS;
extern volatile IC2CON1BITS IC2CON1bits __attribute__((__sfr__));

extern volatile unsigned int  IC2CON2 __attribute__((__sfr__));
__extension__ typedef struct tagIC2CON2BITS {
  union {
    struct {
      unsigned SYNCSEL:5;
      unsigned :1;
      unsigned TRIGSTAT:1;
      unsigned ICTRIG:1;
      unsigned IC32:1;
    };
    struct {
      unsigned SYNCSEL0:1;
      unsigned SYNCSEL1:1;
      unsigned SYNCSEL2:1;
      unsigned SYNCSEL3:1;
      unsigned SYNCSEL4:1;
    };
  };
} IC2CON2BITS;
extern volatile IC2CON2BITS IC2CON2bits __attribute__((__sfr__));

extern volatile unsigned int  IC2BUF __attribute__((__sfr__));
extern volatile unsigned int  IC2TMR __attribute__((__sfr__));
extern volatile unsigned int  IC3CON1 __attribute__((__sfr__));
__extension__ typedef struct tagIC3CON1BITS {
  union {
    struct {
      unsigned ICM:3;
      unsigned ICBNE:1;
      unsigned ICOV:1;
      unsigned ICI:2;
      unsigned :3;
      unsigned ICTSEL:3;
      unsigned ICSIDL:1;
    };
    struct {
      unsigned ICM0:1;
      unsigned ICM1:1;
      unsigned ICM2:1;
      unsigned :2;
      unsigned ICI0:1;
      unsigned ICI1:1;
      unsigned :3;
      unsigned ICTSEL0:1;
      unsigned ICTSEL1:1;
      unsigned ICTSEL2:1;
    };
  };
} IC3CON1BITS;
extern volatile IC3CON1BITS IC3CON1bits __attribute__((__sfr__));

extern volatile unsigned int  IC3CON2 __attribute__((__sfr__));
__extension__ typedef struct tagIC3CON2BITS {
  union {
    struct {
      unsigned SYNCSEL:5;
      unsigned :1;
      unsigned TRIGSTAT:1;
      unsigned ICTRIG:1;
      unsigned IC32:1;
    };
    struct {
      unsigned SYNCSEL0:1;
      unsigned SYNCSEL1:1;
      unsigned SYNCSEL2:1;
      unsigned SYNCSEL3:1;
      unsigned SYNCSEL4:1;
    };
  };
} IC3CON2BITS;
extern volatile IC3CON2BITS IC3CON2bits __attribute__((__sfr__));

extern volatile unsigned int  IC3BUF __attribute__((__sfr__));
extern volatile unsigned int  IC3TMR __attribute__((__sfr__));
extern volatile unsigned int  IC4CON1 __attribute__((__sfr__));
__extension__ typedef struct tagIC4CON1BITS {
  union {
    struct {
      unsigned ICM:3;
      unsigned ICBNE:1;
      unsigned ICOV:1;
      unsigned ICI:2;
      unsigned :3;
      unsigned ICTSEL:3;
      unsigned ICSIDL:1;
    };
    struct {
      unsigned ICM0:1;
      unsigned ICM1:1;
      unsigned ICM2:1;
      unsigned :2;
      unsigned ICI0:1;
      unsigned ICI1:1;
      unsigned :3;
      unsigned ICTSEL0:1;
      unsigned ICTSEL1:1;
      unsigned ICTSEL2:1;
    };
  };
} IC4CON1BITS;
extern volatile IC4CON1BITS IC4CON1bits __attribute__((__sfr__));

extern volatile unsigned int  IC4CON2 __attribute__((__sfr__));
__extension__ typedef struct tagIC4CON2BITS {
  union {
    struct {
      unsigned SYNCSEL:5;
      unsigned :1;
      unsigned TRIGSTAT:1;
      unsigned ICTRIG:1;
      unsigned IC32:1;
    };
    struct {
      unsigned SYNCSEL0:1;
      unsigned SYNCSEL1:1;
      unsigned SYNCSEL2:1;
      unsigned SYNCSEL3:1;
      unsigned SYNCSEL4:1;
    };
  };
} IC4CON2BITS;
extern volatile IC4CON2BITS IC4CON2bits __attribute__((__sfr__));

extern volatile unsigned int  IC4BUF __attribute__((__sfr__));
extern volatile unsigned int  IC4TMR __attribute__((__sfr__));
extern volatile unsigned int  IC5CON1 __attribute__((__sfr__));
__extension__ typedef struct tagIC5CON1BITS {
  union {
    struct {
      unsigned ICM:3;
      unsigned ICBNE:1;
      unsigned ICOV:1;
      unsigned ICI:2;
      unsigned :3;
      unsigned ICTSEL:3;
      unsigned ICSIDL:1;
    };
    struct {
      unsigned ICM0:1;
      unsigned ICM1:1;
      unsigned ICM2:1;
      unsigned :2;
      unsigned ICI0:1;
      unsigned ICI1:1;
      unsigned :3;
      unsigned ICTSEL0:1;
      unsigned ICTSEL1:1;
      unsigned ICTSEL2:1;
    };
  };
} IC5CON1BITS;
extern volatile IC5CON1BITS IC5CON1bits __attribute__((__sfr__));

extern volatile unsigned int  IC5CON2 __attribute__((__sfr__));
__extension__ typedef struct tagIC5CON2BITS {
  union {
    struct {
      unsigned SYNCSEL:5;
      unsigned :1;
      unsigned TRIGSTAT:1;
      unsigned ICTRIG:1;
      unsigned IC32:1;
    };
    struct {
      unsigned SYNCSEL0:1;
      unsigned SYNCSEL1:1;
      unsigned SYNCSEL2:1;
      unsigned SYNCSEL3:1;
      unsigned SYNCSEL4:1;
    };
  };
} IC5CON2BITS;
extern volatile IC5CON2BITS IC5CON2bits __attribute__((__sfr__));

extern volatile unsigned int  IC5BUF __attribute__((__sfr__));
extern volatile unsigned int  IC5TMR __attribute__((__sfr__));
extern volatile unsigned int  IC6CON1 __attribute__((__sfr__));
__extension__ typedef struct tagIC6CON1BITS {
  union {
    struct {
      unsigned ICM:3;
      unsigned ICBNE:1;
      unsigned ICOV:1;
      unsigned ICI:2;
      unsigned :3;
      unsigned ICTSEL:3;
      unsigned ICSIDL:1;
    };
    struct {
      unsigned ICM0:1;
      unsigned ICM1:1;
      unsigned ICM2:1;
      unsigned :2;
      unsigned ICI0:1;
      unsigned ICI1:1;
      unsigned :3;
      unsigned ICTSEL0:1;
      unsigned ICTSEL1:1;
      unsigned ICTSEL2:1;
    };
  };
} IC6CON1BITS;
extern volatile IC6CON1BITS IC6CON1bits __attribute__((__sfr__));

extern volatile unsigned int  IC6CON2 __attribute__((__sfr__));
__extension__ typedef struct tagIC6CON2BITS {
  union {
    struct {
      unsigned SYNCSEL:5;
      unsigned :1;
      unsigned TRIGSTAT:1;
      unsigned ICTRIG:1;
      unsigned IC32:1;
    };
    struct {
      unsigned SYNCSEL0:1;
      unsigned SYNCSEL1:1;
      unsigned SYNCSEL2:1;
      unsigned SYNCSEL3:1;
      unsigned SYNCSEL4:1;
    };
  };
} IC6CON2BITS;
extern volatile IC6CON2BITS IC6CON2bits __attribute__((__sfr__));

extern volatile unsigned int  IC6BUF __attribute__((__sfr__));
extern volatile unsigned int  IC6TMR __attribute__((__sfr__));
extern volatile unsigned int  IC7CON1 __attribute__((__sfr__));
__extension__ typedef struct tagIC7CON1BITS {
  union {
    struct {
      unsigned ICM:3;
      unsigned ICBNE:1;
      unsigned ICOV:1;
      unsigned ICI:2;
      unsigned :3;
      unsigned ICTSEL:3;
      unsigned ICSIDL:1;
    };
    struct {
      unsigned ICM0:1;
      unsigned ICM1:1;
      unsigned ICM2:1;
      unsigned :2;
      unsigned ICI0:1;
      unsigned ICI1:1;
      unsigned :3;
      unsigned ICTSEL0:1;
      unsigned ICTSEL1:1;
      unsigned ICTSEL2:1;
    };
  };
} IC7CON1BITS;
extern volatile IC7CON1BITS IC7CON1bits __attribute__((__sfr__));

extern volatile unsigned int  IC7CON2 __attribute__((__sfr__));
__extension__ typedef struct tagIC7CON2BITS {
  union {
    struct {
      unsigned SYNCSEL:5;
      unsigned :1;
      unsigned TRIGSTAT:1;
      unsigned ICTRIG:1;
      unsigned IC32:1;
    };
    struct {
      unsigned SYNCSEL0:1;
      unsigned SYNCSEL1:1;
      unsigned SYNCSEL2:1;
      unsigned SYNCSEL3:1;
      unsigned SYNCSEL4:1;
    };
  };
} IC7CON2BITS;
extern volatile IC7CON2BITS IC7CON2bits __attribute__((__sfr__));

extern volatile unsigned int  IC7BUF __attribute__((__sfr__));
extern volatile unsigned int  IC7TMR __attribute__((__sfr__));
extern volatile unsigned int  OC1CON1 __attribute__((__sfr__));
__extension__ typedef struct tagOC1CON1BITS {
  union {
    struct {
      unsigned OCM:3;
      unsigned TRIGMODE:1;
      unsigned OCFLT:3;
      unsigned ENFLT:3;
      unsigned OCTSEL:3;
      unsigned OCSIDL:1;
    };
    struct {
      unsigned OCM0:1;
      unsigned OCM1:1;
      unsigned OCM2:1;
      unsigned :1;
      unsigned OCFLT0:1;
      unsigned OCFLT1:1;
      unsigned OCFLT2:1;
      unsigned ENFLT0:1;
      unsigned ENFLT1:1;
      unsigned ENFLT2:1;
      unsigned OCTSEL0:1;
      unsigned OCTSEL1:1;
      unsigned OCTSEL2:1;
    };
  };
} OC1CON1BITS;
extern volatile OC1CON1BITS OC1CON1bits __attribute__((__sfr__));

extern volatile unsigned int  OC1CON2 __attribute__((__sfr__));
__extension__ typedef struct tagOC1CON2BITS {
  union {
    struct {
      unsigned SYNCSEL:5;
      unsigned OCTRIS:1;
      unsigned TRIGSTAT:1;
      unsigned OCTRIG:1;
      unsigned OC32:1;
      unsigned DCB:2;
      unsigned :1;
      unsigned OCINV:1;
      unsigned FLTTRIEN:1;
      unsigned FLTOUT:1;
      unsigned FLTMD:1;
    };
    struct {
      unsigned SYNCSEL0:1;
      unsigned SYNCSEL1:1;
      unsigned SYNCSEL2:1;
      unsigned SYNCSEL3:1;
      unsigned SYNCSEL4:1;
      unsigned :4;
      unsigned DCB0:1;
      unsigned DCB1:1;
      unsigned :4;
      unsigned FLTMODE:1;
    };
  };
} OC1CON2BITS;
extern volatile OC1CON2BITS OC1CON2bits __attribute__((__sfr__));


/* Generic structure of entire SFR area for Output Compare modules */
typedef struct tagOC {
        unsigned int ocxrs;
        unsigned int ocxr;
        unsigned int ocxcon;
} OC, *POC;

/* SFR blocks for Output Compare modules */
extern volatile OC OC1 __attribute__((__sfr__));
extern volatile OC OC2 __attribute__((__sfr__));
extern volatile OC OC3 __attribute__((__sfr__));
extern volatile OC OC4 __attribute__((__sfr__));
extern volatile OC OC5 __attribute__((__sfr__));

extern volatile unsigned int  OC1RS __attribute__((__sfr__));
extern volatile unsigned int  OC1R __attribute__((__sfr__));
extern volatile unsigned int  OC1TMR __attribute__((__sfr__));
extern volatile unsigned int  OC2CON1 __attribute__((__sfr__));
__extension__ typedef struct tagOC2CON1BITS {
  union {
    struct {
      unsigned OCM:3;
      unsigned TRIGMODE:1;
      unsigned OCFLT:3;
      unsigned ENFLT:3;
      unsigned OCTSEL:3;
      unsigned OCSIDL:1;
    };
    struct {
      unsigned OCM0:1;
      unsigned OCM1:1;
      unsigned OCM2:1;
      unsigned :1;
      unsigned OCFLT0:1;
      unsigned OCFLT1:1;
      unsigned OCFLT2:1;
      unsigned ENFLT0:1;
      unsigned ENFLT1:1;
      unsigned ENFLT2:1;
      unsigned OCTSEL0:1;
      unsigned OCTSEL1:1;
      unsigned OCTSEL2:1;
    };
  };
} OC2CON1BITS;
extern volatile OC2CON1BITS OC2CON1bits __attribute__((__sfr__));

extern volatile unsigned int  OC2CON2 __attribute__((__sfr__));
__extension__ typedef struct tagOC2CON2BITS {
  union {
    struct {
      unsigned SYNCSEL:5;
      unsigned OCTRIS:1;
      unsigned TRIGSTAT:1;
      unsigned OCTRIG:1;
      unsigned OC32:1;
      unsigned DCB:2;
      unsigned :1;
      unsigned OCINV:1;
      unsigned FLTTRIEN:1;
      unsigned FLTOUT:1;
      unsigned FLTMD:1;
    };
    struct {
      unsigned SYNCSEL0:1;
      unsigned SYNCSEL1:1;
      unsigned SYNCSEL2:1;
      unsigned SYNCSEL3:1;
      unsigned SYNCSEL4:1;
      unsigned :4;
      unsigned DCB0:1;
      unsigned DCB1:1;
      unsigned :4;
      unsigned FLTMODE:1;
    };
  };
} OC2CON2BITS;
extern volatile OC2CON2BITS OC2CON2bits __attribute__((__sfr__));

extern volatile unsigned int  OC2RS __attribute__((__sfr__));
extern volatile unsigned int  OC2R __attribute__((__sfr__));
extern volatile unsigned int  OC2TMR __attribute__((__sfr__));
extern volatile unsigned int  OC3CON1 __attribute__((__sfr__));
__extension__ typedef struct tagOC3CON1BITS {
  union {
    struct {
      unsigned OCM:3;
      unsigned TRIGMODE:1;
      unsigned OCFLT:3;
      unsigned ENFLT:3;
      unsigned OCTSEL:3;
      unsigned OCSIDL:1;
    };
    struct {
      unsigned OCM0:1;
      unsigned OCM1:1;
      unsigned OCM2:1;
      unsigned :1;
      unsigned OCFLT0:1;
      unsigned OCFLT1:1;
      unsigned OCFLT2:1;
      unsigned ENFLT0:1;
      unsigned ENFLT1:1;
      unsigned ENFLT2:1;
      unsigned OCTSEL0:1;
      unsigned OCTSEL1:1;
      unsigned OCTSEL2:1;
    };
  };
} OC3CON1BITS;
extern volatile OC3CON1BITS OC3CON1bits __attribute__((__sfr__));

extern volatile unsigned int  OC3CON2 __attribute__((__sfr__));
__extension__ typedef struct tagOC3CON2BITS {
  union {
    struct {
      unsigned SYNCSEL:5;
      unsigned OCTRIS:1;
      unsigned TRIGSTAT:1;
      unsigned OCTRIG:1;
      unsigned OC32:1;
      unsigned DCB:2;
      unsigned :1;
      unsigned OCINV:1;
      unsigned FLTTRIEN:1;
      unsigned FLTOUT:1;
      unsigned FLTMD:1;
    };
    struct {
      unsigned SYNCSEL0:1;
      unsigned SYNCSEL1:1;
      unsigned SYNCSEL2:1;
      unsigned SYNCSEL3:1;
      unsigned SYNCSEL4:1;
      unsigned :4;
      unsigned DCB0:1;
      unsigned DCB1:1;
      unsigned :4;
      unsigned FLTMODE:1;
    };
  };
} OC3CON2BITS;
extern volatile OC3CON2BITS OC3CON2bits __attribute__((__sfr__));

extern volatile unsigned int  OC3RS __attribute__((__sfr__));
extern volatile unsigned int  OC3R __attribute__((__sfr__));
extern volatile unsigned int  OC3TMR __attribute__((__sfr__));
extern volatile unsigned int  OC4CON1 __attribute__((__sfr__));
__extension__ typedef struct tagOC4CON1BITS {
  union {
    struct {
      unsigned OCM:3;
      unsigned TRIGMODE:1;
      unsigned OCFLT:3;
      unsigned ENFLT:3;
      unsigned OCTSEL:3;
      unsigned OCSIDL:1;
    };
    struct {
      unsigned OCM0:1;
      unsigned OCM1:1;
      unsigned OCM2:1;
      unsigned :1;
      unsigned OCFLT0:1;
      unsigned OCFLT1:1;
      unsigned OCFLT2:1;
      unsigned ENFLT0:1;
      unsigned ENFLT1:1;
      unsigned ENFLT2:1;
      unsigned OCTSEL0:1;
      unsigned OCTSEL1:1;
      unsigned OCTSEL2:1;
    };
  };
} OC4CON1BITS;
extern volatile OC4CON1BITS OC4CON1bits __attribute__((__sfr__));

extern volatile unsigned int  OC4CON2 __attribute__((__sfr__));
__extension__ typedef struct tagOC4CON2BITS {
  union {
    struct {
      unsigned SYNCSEL:5;
      unsigned OCTRIS:1;
      unsigned TRIGSTAT:1;
      unsigned OCTRIG:1;
      unsigned OC32:1;
      unsigned DCB:2;
      unsigned :1;
      unsigned OCINV:1;
      unsigned FLTTRIEN:1;
      unsigned FLTOUT:1;
      unsigned FLTMD:1;
    };
    struct {
      unsigned SYNCSEL0:1;
      unsigned SYNCSEL1:1;
      unsigned SYNCSEL2:1;
      unsigned SYNCSEL3:1;
      unsigned SYNCSEL4:1;
      unsigned :4;
      unsigned DCB0:1;
      unsigned DCB1:1;
      unsigned :4;
      unsigned FLTMODE:1;
    };
  };
} OC4CON2BITS;
extern volatile OC4CON2BITS OC4CON2bits __attribute__((__sfr__));

extern volatile unsigned int  OC4RS __attribute__((__sfr__));
extern volatile unsigned int  OC4R __attribute__((__sfr__));
extern volatile unsigned int  OC4TMR __attribute__((__sfr__));
extern volatile unsigned int  OC5CON1 __attribute__((__sfr__));
__extension__ typedef struct tagOC5CON1BITS {
  union {
    struct {
      unsigned OCM:3;
      unsigned TRIGMODE:1;
      unsigned OCFLT:3;
      unsigned ENFLT:3;
      unsigned OCTSEL:3;
      unsigned OCSIDL:1;
    };
    struct {
      unsigned OCM0:1;
      unsigned OCM1:1;
      unsigned OCM2:1;
      unsigned :1;
      unsigned OCFLT0:1;
      unsigned OCFLT1:1;
      unsigned OCFLT2:1;
      unsigned ENFLT0:1;
      unsigned ENFLT1:1;
      unsigned ENFLT2:1;
      unsigned OCTSEL0:1;
      unsigned OCTSEL1:1;
      unsigned OCTSEL2:1;
    };
  };
} OC5CON1BITS;
extern volatile OC5CON1BITS OC5CON1bits __attribute__((__sfr__));

extern volatile unsigned int  OC5CON2 __attribute__((__sfr__));
__extension__ typedef struct tagOC5CON2BITS {
  union {
    struct {
      unsigned SYNCSEL:5;
      unsigned OCTRIS:1;
      unsigned TRIGSTAT:1;
      unsigned OCTRIG:1;
      unsigned OC32:1;
      unsigned DCB:2;
      unsigned :1;
      unsigned OCINV:1;
      unsigned FLTTRIEN:1;
      unsigned FLTOUT:1;
      unsigned FLTMD:1;
    };
    struct {
      unsigned SYNCSEL0:1;
      unsigned SYNCSEL1:1;
      unsigned SYNCSEL2:1;
      unsigned SYNCSEL3:1;
      unsigned SYNCSEL4:1;
      unsigned :4;
      unsigned DCB0:1;
      unsigned DCB1:1;
      unsigned :4;
      unsigned FLTMODE:1;
    };
  };
} OC5CON2BITS;
extern volatile OC5CON2BITS OC5CON2bits __attribute__((__sfr__));

extern volatile unsigned int  OC5RS __attribute__((__sfr__));
extern volatile unsigned int  OC5R __attribute__((__sfr__));
extern volatile unsigned int  OC5TMR __attribute__((__sfr__));
extern volatile unsigned int  OC6CON1 __attribute__((__sfr__));
__extension__ typedef struct tagOC6CON1BITS {
  union {
    struct {
      unsigned OCM:3;
      unsigned TRIGMODE:1;
      unsigned OCFLT:3;
      unsigned ENFLT:3;
      unsigned OCTSEL:3;
      unsigned OCSIDL:1;
    };
    struct {
      unsigned OCM0:1;
      unsigned OCM1:1;
      unsigned OCM2:1;
      unsigned :1;
      unsigned OCFLT0:1;
      unsigned OCFLT1:1;
      unsigned OCFLT2:1;
      unsigned ENFLT0:1;
      unsigned ENFLT1:1;
      unsigned ENFLT2:1;
      unsigned OCTSEL0:1;
      unsigned OCTSEL1:1;
      unsigned OCTSEL2:1;
    };
  };
} OC6CON1BITS;
extern volatile OC6CON1BITS OC6CON1bits __attribute__((__sfr__));

extern volatile unsigned int  OC6CON2 __attribute__((__sfr__));
__extension__ typedef struct tagOC6CON2BITS {
  union {
    struct {
      unsigned SYNCSEL:5;
      unsigned OCTRIS:1;
      unsigned TRIGSTAT:1;
      unsigned OCTRIG:1;
      unsigned OC32:1;
      unsigned DCB:2;
      unsigned :1;
      unsigned OCINV:1;
      unsigned FLTTRIEN:1;
      unsigned FLTOUT:1;
      unsigned FLTMD:1;
    };
    struct {
      unsigned SYNCSEL0:1;
      unsigned SYNCSEL1:1;
      unsigned SYNCSEL2:1;
      unsigned SYNCSEL3:1;
      unsigned SYNCSEL4:1;
      unsigned :4;
      unsigned DCB0:1;
      unsigned DCB1:1;
      unsigned :4;
      unsigned FLTMODE:1;
    };
  };
} OC6CON2BITS;
extern volatile OC6CON2BITS OC6CON2bits __attribute__((__sfr__));

extern volatile unsigned int  OC6RS __attribute__((__sfr__));
extern volatile unsigned int  OC6R __attribute__((__sfr__));
extern volatile unsigned int  OC6TMR __attribute__((__sfr__));
extern volatile unsigned int  OC7CON1 __attribute__((__sfr__));
__extension__ typedef struct tagOC7CON1BITS {
  union {
    struct {
      unsigned OCM:3;
      unsigned TRIGMODE:1;
      unsigned OCFLT:3;
      unsigned ENFLT:3;
      unsigned OCTSEL:3;
      unsigned OCSIDL:1;
    };
    struct {
      unsigned OCM0:1;
      unsigned OCM1:1;
      unsigned OCM2:1;
      unsigned :1;
      unsigned OCFLT0:1;
      unsigned OCFLT1:1;
      unsigned OCFLT2:1;
      unsigned ENFLT0:1;
      unsigned ENFLT1:1;
      unsigned ENFLT2:1;
      unsigned OCTSEL0:1;
      unsigned OCTSEL1:1;
      unsigned OCTSEL2:1;
    };
  };
} OC7CON1BITS;
extern volatile OC7CON1BITS OC7CON1bits __attribute__((__sfr__));

extern volatile unsigned int  OC7CON2 __attribute__((__sfr__));
__extension__ typedef struct tagOC7CON2BITS {
  union {
    struct {
      unsigned SYNCSEL:5;
      unsigned OCTRIS:1;
      unsigned TRIGSTAT:1;
      unsigned OCTRIG:1;
      unsigned OC32:1;
      unsigned DCB:2;
      unsigned :1;
      unsigned OCINV:1;
      unsigned FLTTRIEN:1;
      unsigned FLTOUT:1;
      unsigned FLTMD:1;
    };
    struct {
      unsigned SYNCSEL0:1;
      unsigned SYNCSEL1:1;
      unsigned SYNCSEL2:1;
      unsigned SYNCSEL3:1;
      unsigned SYNCSEL4:1;
      unsigned :4;
      unsigned DCB0:1;
      unsigned DCB1:1;
      unsigned :4;
      unsigned FLTMODE:1;
    };
  };
} OC7CON2BITS;
extern volatile OC7CON2BITS OC7CON2bits __attribute__((__sfr__));

extern volatile unsigned int  OC7RS __attribute__((__sfr__));
extern volatile unsigned int  OC7R __attribute__((__sfr__));
extern volatile unsigned int  OC7TMR __attribute__((__sfr__));
extern volatile unsigned int  I2C1RCV __attribute__((__sfr__));
extern volatile unsigned int  I2C1TRN __attribute__((__sfr__));
extern volatile unsigned int  I2C1BRG __attribute__((__sfr__));
extern volatile unsigned int  I2C1CON __attribute__((__sfr__));
typedef struct tagI2C1CONBITS {
  unsigned SEN:1;
  unsigned RSEN:1;
  unsigned PEN:1;
  unsigned RCEN:1;
  unsigned ACKEN:1;
  unsigned ACKDT:1;
  unsigned STREN:1;
  unsigned GCEN:1;
  unsigned SMEN:1;
  unsigned DISSLW:1;
  unsigned A10M:1;
  unsigned IPMIEN:1;
  unsigned SCLREL:1;
  unsigned I2CSIDL:1;
  unsigned :1;
  unsigned I2CEN:1;
} I2C1CONBITS;
extern volatile I2C1CONBITS I2C1CONbits __attribute__((__sfr__));

extern volatile unsigned int  I2C1STAT __attribute__((__sfr__));
__extension__ typedef struct tagI2C1STATBITS {
  union {
    struct {
      unsigned TBF:1;
      unsigned RBF:1;
      unsigned R_NOT_W:1;
      unsigned S:1;
      unsigned P:1;
      unsigned D_NOT_A:1;
      unsigned I2COV:1;
      unsigned IWCOL:1;
      unsigned ADD10:1;
      unsigned GCSTAT:1;
      unsigned BCL:1;
      unsigned :3;
      unsigned TRSTAT:1;
      unsigned ACKSTAT:1;
    };
    struct {
      unsigned :2;
      unsigned R_W:1;
      unsigned :2;
      unsigned D_A:1;
    };
  };
} I2C1STATBITS;
extern volatile I2C1STATBITS I2C1STATbits __attribute__((__sfr__));

extern volatile unsigned int  I2C1ADD __attribute__((__sfr__));
extern volatile unsigned int  I2C1MSK __attribute__((__sfr__));
extern volatile unsigned int  I2C2RCV __attribute__((__sfr__));
extern volatile unsigned int  I2C2TRN __attribute__((__sfr__));
extern volatile unsigned int  I2C2BRG __attribute__((__sfr__));
extern volatile unsigned int  I2C2CON __attribute__((__sfr__));
typedef struct tagI2C2CONBITS {
  unsigned SEN:1;
  unsigned RSEN:1;
  unsigned PEN:1;
  unsigned RCEN:1;
  unsigned ACKEN:1;
  unsigned ACKDT:1;
  unsigned STREN:1;
  unsigned GCEN:1;
  unsigned SMEN:1;
  unsigned DISSLW:1;
  unsigned A10M:1;
  unsigned IPMIEN:1;
  unsigned SCLREL:1;
  unsigned I2CSIDL:1;
  unsigned :1;
  unsigned I2CEN:1;
} I2C2CONBITS;
extern volatile I2C2CONBITS I2C2CONbits __attribute__((__sfr__));

extern volatile unsigned int  I2C2STAT __attribute__((__sfr__));
__extension__ typedef struct tagI2C2STATBITS {
  union {
    struct {
      unsigned TBF:1;
      unsigned RBF:1;
      unsigned R_NOT_W:1;
      unsigned S:1;
      unsigned P:1;
      unsigned D_NOT_A:1;
      unsigned I2COV:1;
      unsigned IWCOL:1;
      unsigned ADD10:1;
      unsigned GCSTAT:1;
      unsigned BCL:1;
      unsigned :3;
      unsigned TRSTAT:1;
      unsigned ACKSTAT:1;
    };
    struct {
      unsigned :2;
      unsigned R_W:1;
      unsigned :2;
      unsigned D_A:1;
    };
  };
} I2C2STATBITS;
extern volatile I2C2STATBITS I2C2STATbits __attribute__((__sfr__));

extern volatile unsigned int  I2C2ADD __attribute__((__sfr__));
extern volatile unsigned int  I2C2MSK __attribute__((__sfr__));

/* Generic structure of entire SFR area for each UART module */
typedef struct tagUART {
        unsigned int uxmode;
        unsigned int uxsta;
        unsigned int uxtxreg;
        unsigned int uxrxreg;
        unsigned int uxbrg;
} UART, *PUART;

#define UxMODEBITS U1MODEBITS
#define UxSTABITS U1STABITS
#define UxTXREGBITS U1TXREGBITS
#define UxRXREGBITS U1RXREGBITS
#define UxBRGBITS U1BRGBITS

/* SFR blocks for each UART module */
extern volatile UART UART1 __attribute__((__sfr__));
extern volatile UART UART2 __attribute__((__sfr__));

extern volatile unsigned int  U1MODE __attribute__((__sfr__));
__extension__ typedef struct tagU1MODEBITS {
  union {
    struct {
      unsigned STSEL:1;
      unsigned PDSEL:2;
      unsigned BRGH:1;
      unsigned RXINV:1;
      unsigned ABAUD:1;
      unsigned LPBACK:1;
      unsigned WAKE:1;
      unsigned UEN:2;
      unsigned :1;
      unsigned RTSMD:1;
      unsigned IREN:1;
      unsigned USIDL:1;
      unsigned :1;
      unsigned UARTEN:1;
    };
    struct {
      unsigned :1;
      unsigned PDSEL0:1;
      unsigned PDSEL1:1;
      unsigned :5;
      unsigned UEN0:1;
      unsigned UEN1:1;
    };
  };
} U1MODEBITS;
extern volatile U1MODEBITS U1MODEbits __attribute__((__sfr__));

extern volatile unsigned int  U1STA __attribute__((__sfr__));
__extension__ typedef struct tagU1STABITS {
  union {
    struct {
      unsigned URXDA:1;
      unsigned OERR:1;
      unsigned FERR:1;
      unsigned PERR:1;
      unsigned RIDLE:1;
      unsigned ADDEN:1;
      unsigned URXISEL:2;
      unsigned TRMT:1;
      unsigned UTXBF:1;
      unsigned UTXEN:1;
      unsigned UTXBRK:1;
      unsigned :1;
      unsigned UTXISEL0:1;
      unsigned UTXINV:1;
      unsigned UTXISEL1:1;
    };
    struct {
      unsigned :6;
      unsigned URXISEL0:1;
      unsigned URXISEL1:1;
    };
  };
} U1STABITS;
extern volatile U1STABITS U1STAbits __attribute__((__sfr__));

extern volatile unsigned int  U1TXREG __attribute__((__sfr__));
typedef struct tagU1TXREGBITS {
  unsigned UTXREG0:1;
  unsigned UTXREG1:1;
  unsigned UTXREG2:1;
  unsigned UTXREG3:1;
  unsigned UTXREG4:1;
  unsigned UTXREG5:1;
  unsigned UTXREG6:1;
  unsigned UTXREG7:1;
  unsigned UTXREG8:1;
} U1TXREGBITS;
extern volatile U1TXREGBITS U1TXREGbits __attribute__((__sfr__));

extern volatile unsigned int  U1RXREG __attribute__((__sfr__));
typedef struct tagU1RXREGBITS {
  unsigned URXREG0:1;
  unsigned URXREG1:1;
  unsigned URXREG2:1;
  unsigned URXREG3:1;
  unsigned URXREG4:1;
  unsigned URXREG5:1;
  unsigned URXREG6:1;
  unsigned URXREG7:1;
  unsigned URXREG8:1;
} U1RXREGBITS;
extern volatile U1RXREGBITS U1RXREGbits __attribute__((__sfr__));

extern volatile unsigned int  U1BRG __attribute__((__sfr__));
extern volatile unsigned int  U2MODE __attribute__((__sfr__));
__extension__ typedef struct tagU2MODEBITS {
  union {
    struct {
      unsigned STSEL:1;
      unsigned PDSEL:2;
      unsigned BRGH:1;
      unsigned RXINV:1;
      unsigned ABAUD:1;
      unsigned LPBACK:1;
      unsigned WAKE:1;
      unsigned UEN:2;
      unsigned :1;
      unsigned RTSMD:1;
      unsigned IREN:1;
      unsigned USIDL:1;
      unsigned :1;
      unsigned UARTEN:1;
    };
    struct {
      unsigned :1;
      unsigned PDSEL0:1;
      unsigned PDSEL1:1;
      unsigned :5;
      unsigned UEN0:1;
      unsigned UEN1:1;
    };
  };
} U2MODEBITS;
extern volatile U2MODEBITS U2MODEbits __attribute__((__sfr__));

extern volatile unsigned int  U2STA __attribute__((__sfr__));
__extension__ typedef struct tagU2STABITS {
  union {
    struct {
      unsigned URXDA:1;
      unsigned OERR:1;
      unsigned FERR:1;
      unsigned PERR:1;
      unsigned RIDLE:1;
      unsigned ADDEN:1;
      unsigned URXISEL:2;
      unsigned TRMT:1;
      unsigned UTXBF:1;
      unsigned UTXEN:1;
      unsigned UTXBRK:1;
      unsigned :1;
      unsigned UTXISEL0:1;
      unsigned UTXINV:1;
      unsigned UTXISEL1:1;
    };
    struct {
      unsigned :6;
      unsigned URXISEL0:1;
      unsigned URXISEL1:1;
    };
  };
} U2STABITS;
extern volatile U2STABITS U2STAbits __attribute__((__sfr__));

extern volatile unsigned int  U2TXREG __attribute__((__sfr__));
typedef struct tagU2TXREGBITS {
  unsigned UTXREG0:1;
  unsigned UTXREG1:1;
  unsigned UTXREG2:1;
  unsigned UTXREG3:1;
  unsigned UTXREG4:1;
  unsigned UTXREG5:1;
  unsigned UTXREG6:1;
  unsigned UTXREG7:1;
  unsigned UTXREG8:1;
} U2TXREGBITS;
extern volatile U2TXREGBITS U2TXREGbits __attribute__((__sfr__));

extern volatile unsigned int  U2RXREG __attribute__((__sfr__));
typedef struct tagU2RXREGBITS {
  unsigned URXREG0:1;
  unsigned URXREG1:1;
  unsigned URXREG2:1;
  unsigned URXREG3:1;
  unsigned URXREG4:1;
  unsigned URXREG5:1;
  unsigned URXREG6:1;
  unsigned URXREG7:1;
  unsigned URXREG8:1;
} U2RXREGBITS;
extern volatile U2RXREGBITS U2RXREGbits __attribute__((__sfr__));

extern volatile unsigned int  U2BRG __attribute__((__sfr__));

/* Generic structure of entire SFR area for each SPI module */
typedef struct tagSPI {
        unsigned int spixstat;
        unsigned int spixcon1;
        unsigned int spixcon2;
        unsigned int unused;
        unsigned int spixbuf;
} SPI, *PSPI;

#define SPIxSTATBITS SPI1STATBITS
#define SPIxCONBITS SPI1CONBITS

/* SFR blocks for each SPI module */
extern volatile SPI SPI1 __attribute__((__sfr__));
extern volatile SPI SPI2 __attribute__((__sfr__));

extern volatile unsigned int  SPI1STAT __attribute__((__sfr__));
__extension__ typedef struct tagSPI1STATBITS {
  union {
    struct {
      unsigned SPIRBF:1;
      unsigned SPITBF:1;
      unsigned SISEL:3;
      unsigned SRXMPT:1;
      unsigned SPIROV:1;
      unsigned SRMPT:1;
      unsigned SPIBEC:3;
      unsigned :2;
      unsigned SPISIDL:1;
      unsigned :1;
      unsigned SPIEN:1;
    };
    struct {
      unsigned :2;
      unsigned SISEL0:1;
      unsigned SISEL1:1;
      unsigned SISEL2:1;
      unsigned :3;
      unsigned SPIBEC0:1;
      unsigned SPIBEC1:1;
      unsigned SPIBEC2:1;
    };
  };
} SPI1STATBITS;
extern volatile SPI1STATBITS SPI1STATbits __attribute__((__sfr__));

extern volatile unsigned int  SPI1CON1 __attribute__((__sfr__));
__extension__ typedef struct tagSPI1CON1BITS {
  union {
    struct {
      unsigned PPRE:2;
      unsigned SPRE:3;
      unsigned MSTEN:1;
      unsigned CKP:1;
      unsigned SSEN:1;
      unsigned CKE:1;
      unsigned SMP:1;
      unsigned MODE16:1;
      unsigned DISSDO:1;
      unsigned DISSCK:1;
    };
    struct {
      unsigned PPRE0:1;
      unsigned PPRE1:1;
      unsigned SPRE0:1;
      unsigned SPRE1:1;
      unsigned SPRE2:1;
    };
  };
} SPI1CON1BITS;
extern volatile SPI1CON1BITS SPI1CON1bits __attribute__((__sfr__));

extern volatile unsigned int  SPI1CON2 __attribute__((__sfr__));
typedef struct tagSPI1CON2BITS {
  unsigned SPIBEN:1;
  unsigned SPIFE:1;
  unsigned :11;
  unsigned SPIFPOL:1;
  unsigned SPIFSD:1;
  unsigned FRMEN:1;
} SPI1CON2BITS;
extern volatile SPI1CON2BITS SPI1CON2bits __attribute__((__sfr__));

extern volatile unsigned int  SPI1BUF __attribute__((__sfr__));
extern volatile unsigned int  U3MODE __attribute__((__sfr__));
__extension__ typedef struct tagU3MODEBITS {
  union {
    struct {
      unsigned STSEL:1;
      unsigned PDSEL:2;
      unsigned BRGH:1;
      unsigned RXINV:1;
      unsigned ABAUD:1;
      unsigned LPBACK:1;
      unsigned WAKE:1;
      unsigned UEN:2;
      unsigned :1;
      unsigned RTSMD:1;
      unsigned IREN:1;
      unsigned USIDL:1;
      unsigned :1;
      unsigned UARTEN:1;
    };
    struct {
      unsigned :1;
      unsigned PDSEL0:1;
      unsigned PDSEL1:1;
      unsigned :5;
      unsigned UEN0:1;
      unsigned UEN1:1;
    };
  };
} U3MODEBITS;
extern volatile U3MODEBITS U3MODEbits __attribute__((__sfr__));

extern volatile unsigned int  U3STA __attribute__((__sfr__));
__extension__ typedef struct tagU3STABITS {
  union {
    struct {
      unsigned URXDA:1;
      unsigned OERR:1;
      unsigned FERR:1;
      unsigned PERR:1;
      unsigned RIDLE:1;
      unsigned ADDEN:1;
      unsigned URXISEL:2;
      unsigned TRMT:1;
      unsigned UTXBF:1;
      unsigned UTXEN:1;
      unsigned UTXBRK:1;
      unsigned :1;
      unsigned UTXISEL0:1;
      unsigned UTXINV:1;
      unsigned UTXISEL1:1;
    };
    struct {
      unsigned :6;
      unsigned URXISEL0:1;
      unsigned URXISEL1:1;
    };
  };
} U3STABITS;
extern volatile U3STABITS U3STAbits __attribute__((__sfr__));

extern volatile unsigned int  U3TXREG __attribute__((__sfr__));
typedef struct tagU3TXREGBITS {
  unsigned UTXREG0:1;
  unsigned UTXREG1:1;
  unsigned UTXREG2:1;
  unsigned UTXREG3:1;
  unsigned UTXREG4:1;
  unsigned UTXREG5:1;
  unsigned UTXREG6:1;
  unsigned UTXREG7:1;
  unsigned UTXREG8:1;
} U3TXREGBITS;
extern volatile U3TXREGBITS U3TXREGbits __attribute__((__sfr__));

extern volatile unsigned int  U3RXREG __attribute__((__sfr__));
typedef struct tagU3RXREGBITS {
  unsigned URXREG0:1;
  unsigned URXREG1:1;
  unsigned URXREG2:1;
  unsigned URXREG3:1;
  unsigned URXREG4:1;
  unsigned URXREG5:1;
  unsigned URXREG6:1;
  unsigned URXREG7:1;
  unsigned URXREG8:1;
} U3RXREGBITS;
extern volatile U3RXREGBITS U3RXREGbits __attribute__((__sfr__));

extern volatile unsigned int  U3BRG __attribute__((__sfr__));
extern volatile unsigned int  SPI2STAT __attribute__((__sfr__));
__extension__ typedef struct tagSPI2STATBITS {
  union {
    struct {
      unsigned SPIRBF:1;
      unsigned SPITBF:1;
      unsigned SISEL:3;
      unsigned SRXMPT:1;
      unsigned SPIROV:1;
      unsigned SRMPT:1;
      unsigned SPIBEC:3;
      unsigned :2;
      unsigned SPISIDL:1;
      unsigned :1;
      unsigned SPIEN:1;
    };
    struct {
      unsigned :2;
      unsigned SISEL0:1;
      unsigned SISEL1:1;
      unsigned SISEL2:1;
      unsigned :3;
      unsigned SPIBEC0:1;
      unsigned SPIBEC1:1;
      unsigned SPIBEC2:1;
    };
  };
} SPI2STATBITS;
extern volatile SPI2STATBITS SPI2STATbits __attribute__((__sfr__));

extern volatile unsigned int  SPI2CON1 __attribute__((__sfr__));
__extension__ typedef struct tagSPI2CON1BITS {
  union {
    struct {
      unsigned PPRE:2;
      unsigned SPRE:3;
      unsigned MSTEN:1;
      unsigned CKP:1;
      unsigned SSEN:1;
      unsigned CKE:1;
      unsigned SMP:1;
      unsigned MODE16:1;
      unsigned DISSDO:1;
      unsigned DISSCK:1;
    };
    struct {
      unsigned PPRE0:1;
      unsigned PPRE1:1;
      unsigned SPRE0:1;
      unsigned SPRE1:1;
      unsigned SPRE2:1;
    };
  };
} SPI2CON1BITS;
extern volatile SPI2CON1BITS SPI2CON1bits __attribute__((__sfr__));

extern volatile unsigned int  SPI2CON2 __attribute__((__sfr__));
typedef struct tagSPI2CON2BITS {
  unsigned SPIBEN:1;
  unsigned SPIFE:1;
  unsigned :11;
  unsigned SPIFPOL:1;
  unsigned SPIFSD:1;
  unsigned FRMEN:1;
} SPI2CON2BITS;
extern volatile SPI2CON2BITS SPI2CON2bits __attribute__((__sfr__));

extern volatile unsigned int  SPI2BUF __attribute__((__sfr__));
extern volatile unsigned int  U4MODE __attribute__((__sfr__));
__extension__ typedef struct tagU4MODEBITS {
  union {
    struct {
      unsigned STSEL:1;
      unsigned PDSEL:2;
      unsigned BRGH:1;
      unsigned RXINV:1;
      unsigned ABAUD:1;
      unsigned LPBACK:1;
      unsigned WAKE:1;
      unsigned UEN:2;
      unsigned :1;
      unsigned RTSMD:1;
      unsigned IREN:1;
      unsigned USIDL:1;
      unsigned :1;
      unsigned UARTEN:1;
    };
    struct {
      unsigned :1;
      unsigned PDSEL0:1;
      unsigned PDSEL1:1;
      unsigned :5;
      unsigned UEN0:1;
      unsigned UEN1:1;
    };
  };
} U4MODEBITS;
extern volatile U4MODEBITS U4MODEbits __attribute__((__sfr__));

extern volatile unsigned int  U4STA __attribute__((__sfr__));
__extension__ typedef struct tagU4STABITS {
  union {
    struct {
      unsigned URXDA:1;
      unsigned OERR:1;
      unsigned FERR:1;
      unsigned PERR:1;
      unsigned RIDLE:1;
      unsigned ADDEN:1;
      unsigned URXISEL:2;
      unsigned TRMT:1;
      unsigned UTXBF:1;
      unsigned UTXEN:1;
      unsigned UTXBRK:1;
      unsigned :1;
      unsigned UTXISEL0:1;
      unsigned UTXINV:1;
      unsigned UTXISEL1:1;
    };
    struct {
      unsigned :6;
      unsigned URXISEL0:1;
      unsigned URXISEL1:1;
    };
  };
} U4STABITS;
extern volatile U4STABITS U4STAbits __attribute__((__sfr__));

extern volatile unsigned int  U4TXREG __attribute__((__sfr__));
typedef struct tagU4TXREGBITS {
  unsigned UTXREG0:1;
  unsigned UTXREG1:1;
  unsigned UTXREG2:1;
  unsigned UTXREG3:1;
  unsigned UTXREG4:1;
  unsigned UTXREG5:1;
  unsigned UTXREG6:1;
  unsigned UTXREG7:1;
  unsigned UTXREG8:1;
} U4TXREGBITS;
extern volatile U4TXREGBITS U4TXREGbits __attribute__((__sfr__));

extern volatile unsigned int  U4RXREG __attribute__((__sfr__));
typedef struct tagU4RXREGBITS {
  unsigned URXREG0:1;
  unsigned URXREG1:1;
  unsigned URXREG2:1;
  unsigned URXREG3:1;
  unsigned URXREG4:1;
  unsigned URXREG5:1;
  unsigned URXREG6:1;
  unsigned URXREG7:1;
  unsigned URXREG8:1;
} U4RXREGBITS;
extern volatile U4RXREGBITS U4RXREGbits __attribute__((__sfr__));

extern volatile unsigned int  U4BRG __attribute__((__sfr__));
extern volatile unsigned int  TRISA __attribute__((__sfr__));
typedef struct tagTRISABITS {
  unsigned :9;
  unsigned TRISA9:1;
  unsigned TRISA10:1;
  unsigned :3;
  unsigned TRISA14:1;
  unsigned TRISA15:1;
} TRISABITS;
extern volatile TRISABITS TRISAbits __attribute__((__sfr__));

extern volatile unsigned int  PORTA __attribute__((__sfr__));
typedef struct tagPORTABITS {
  unsigned :9;
  unsigned RA9:1;
  unsigned RA10:1;
  unsigned :3;
  unsigned RA14:1;
  unsigned RA15:1;
} PORTABITS;
extern volatile PORTABITS PORTAbits __attribute__((__sfr__));

extern volatile unsigned int  LATA __attribute__((__sfr__));
typedef struct tagLATABITS {
  unsigned :9;
  unsigned LATA9:1;
  unsigned LATA10:1;
  unsigned :3;
  unsigned LATA14:1;
  unsigned LATA15:1;
} LATABITS;
extern volatile LATABITS LATAbits __attribute__((__sfr__));

extern volatile unsigned int  ODCA __attribute__((__sfr__));
typedef struct tagODCABITS {
  unsigned :9;
  unsigned ODA9:1;
  unsigned ODA10:1;
  unsigned :3;
  unsigned ODA14:1;
  unsigned ODA15:1;
} ODCABITS;
extern volatile ODCABITS ODCAbits __attribute__((__sfr__));

extern volatile unsigned int  TRISB __attribute__((__sfr__));
typedef struct tagTRISBBITS {
  unsigned TRISB0:1;
  unsigned TRISB1:1;
  unsigned TRISB2:1;
  unsigned TRISB3:1;
  unsigned TRISB4:1;
  unsigned TRISB5:1;
  unsigned TRISB6:1;
  unsigned TRISB7:1;
  unsigned TRISB8:1;
  unsigned TRISB9:1;
  unsigned TRISB10:1;
  unsigned TRISB11:1;
  unsigned TRISB12:1;
  unsigned TRISB13:1;
  unsigned TRISB14:1;
  unsigned TRISB15:1;
} TRISBBITS;
extern volatile TRISBBITS TRISBbits __attribute__((__sfr__));

extern volatile unsigned int  PORTB __attribute__((__sfr__));
typedef struct tagPORTBBITS {
  unsigned RB0:1;
  unsigned RB1:1;
  unsigned RB2:1;
  unsigned RB3:1;
  unsigned RB4:1;
  unsigned RB5:1;
  unsigned RB6:1;
  unsigned RB7:1;
  unsigned RB8:1;
  unsigned RB9:1;
  unsigned RB10:1;
  unsigned RB11:1;
  unsigned RB12:1;
  unsigned RB13:1;
  unsigned RB14:1;
  unsigned RB15:1;
} PORTBBITS;
extern volatile PORTBBITS PORTBbits __attribute__((__sfr__));

extern volatile unsigned int  LATB __attribute__((__sfr__));
typedef struct tagLATBBITS {
  unsigned LATB0:1;
  unsigned LATB1:1;
  unsigned LATB2:1;
  unsigned LATB3:1;
  unsigned LATB4:1;
  unsigned LATB5:1;
  unsigned LATB6:1;
  unsigned LATB7:1;
  unsigned LATB8:1;
  unsigned LATB9:1;
  unsigned LATB10:1;
  unsigned LATB11:1;
  unsigned LATB12:1;
  unsigned LATB13:1;
  unsigned LATB14:1;
  unsigned LATB15:1;
} LATBBITS;
extern volatile LATBBITS LATBbits __attribute__((__sfr__));

extern volatile unsigned int  ODCB __attribute__((__sfr__));
typedef struct tagODCBBITS {
  unsigned ODB0:1;
  unsigned ODB1:1;
  unsigned ODB2:1;
  unsigned ODB3:1;
  unsigned ODB4:1;
  unsigned ODB5:1;
  unsigned ODB6:1;
  unsigned ODB7:1;
  unsigned ODB8:1;
  unsigned ODB9:1;
  unsigned ODB10:1;
  unsigned ODB11:1;
  unsigned ODB12:1;
  unsigned ODB13:1;
  unsigned ODB14:1;
  unsigned ODB15:1;
} ODCBBITS;
extern volatile ODCBBITS ODCBbits __attribute__((__sfr__));

extern volatile unsigned int  TRISC __attribute__((__sfr__));
typedef struct tagTRISCBITS {
  unsigned :1;
  unsigned TRISC1:1;
  unsigned :1;
  unsigned TRISC3:1;
  unsigned :8;
  unsigned TRISC12:1;
  unsigned :2;
  unsigned TRISC15:1;
} TRISCBITS;
extern volatile TRISCBITS TRISCbits __attribute__((__sfr__));

extern volatile unsigned int  PORTC __attribute__((__sfr__));
typedef struct tagPORTCBITS {
  unsigned :1;
  unsigned RC1:1;
  unsigned :1;
  unsigned RC3:1;
  unsigned :8;
  unsigned RC12:1;
  unsigned RC13:1;
  unsigned RC14:1;
  unsigned RC15:1;
} PORTCBITS;
extern volatile PORTCBITS PORTCbits __attribute__((__sfr__));

extern volatile unsigned int  LATC __attribute__((__sfr__));
typedef struct tagLATCBITS {
  unsigned :1;
  unsigned LATC1:1;
  unsigned :1;
  unsigned LATC3:1;
  unsigned :8;
  unsigned LATC12:1;
  unsigned LATC13:1;
  unsigned LATC14:1;
  unsigned LATC15:1;
} LATCBITS;
extern volatile LATCBITS LATCbits __attribute__((__sfr__));

extern volatile unsigned int  ODCC __attribute__((__sfr__));
typedef struct tagODCCBITS {
  unsigned :1;
  unsigned ODC1:1;
  unsigned :1;
  unsigned ODC3:1;
  unsigned :8;
  unsigned ODC12:1;
  unsigned ODC13:1;
  unsigned ODC14:1;
  unsigned ODC15:1;
} ODCCBITS;
extern volatile ODCCBITS ODCCbits __attribute__((__sfr__));

extern volatile unsigned int  TRISD __attribute__((__sfr__));
typedef struct tagTRISDBITS {
  unsigned TRISD0:1;
  unsigned TRISD1:1;
  unsigned TRISD2:1;
  unsigned TRISD3:1;
  unsigned TRISD4:1;
  unsigned TRISD5:1;
  unsigned TRISD6:1;
  unsigned TRISD7:1;
  unsigned TRISD8:1;
  unsigned TRISD9:1;
  unsigned TRISD10:1;
  unsigned TRISD11:1;
  unsigned TRISD12:1;
  unsigned TRISD13:1;
  unsigned TRISD14:1;
  unsigned TRISD15:1;
} TRISDBITS;
extern volatile TRISDBITS TRISDbits __attribute__((__sfr__));

extern volatile unsigned int  PORTD __attribute__((__sfr__));
typedef struct tagPORTDBITS {
  unsigned RD0:1;
  unsigned RD1:1;
  unsigned RD2:1;
  unsigned RD3:1;
  unsigned RD4:1;
  unsigned RD5:1;
  unsigned RD6:1;
  unsigned RD7:1;
  unsigned RD8:1;
  unsigned RD9:1;
  unsigned RD10:1;
  unsigned RD11:1;
  unsigned RD12:1;
  unsigned RD13:1;
  unsigned RD14:1;
  unsigned RD15:1;
} PORTDBITS;
extern volatile PORTDBITS PORTDbits __attribute__((__sfr__));

extern volatile unsigned int  LATD __attribute__((__sfr__));
typedef struct tagLATDBITS {
  unsigned LATD0:1;
  unsigned LATD1:1;
  unsigned LATD2:1;
  unsigned LATD3:1;
  unsigned LATD4:1;
  unsigned LATD5:1;
  unsigned LATD6:1;
  unsigned LATD7:1;
  unsigned LATD8:1;
  unsigned LATD9:1;
  unsigned LATD10:1;
  unsigned LATD11:1;
  unsigned LATD12:1;
  unsigned LATD13:1;
  unsigned LATD14:1;
  unsigned LATD15:1;
} LATDBITS;
extern volatile LATDBITS LATDbits __attribute__((__sfr__));

extern volatile unsigned int  ODCD __attribute__((__sfr__));
typedef struct tagODCDBITS {
  unsigned ODD0:1;
  unsigned ODD1:1;
  unsigned ODD2:1;
  unsigned ODD3:1;
  unsigned ODD4:1;
  unsigned ODD5:1;
  unsigned ODD6:1;
  unsigned ODD7:1;
  unsigned ODD8:1;
  unsigned ODD9:1;
  unsigned ODD10:1;
  unsigned ODD11:1;
  unsigned ODD12:1;
  unsigned ODD13:1;
  unsigned ODD14:1;
  unsigned ODD15:1;
} ODCDBITS;
extern volatile ODCDBITS ODCDbits __attribute__((__sfr__));

extern volatile unsigned int  TRISE __attribute__((__sfr__));
typedef struct tagTRISEBITS {
  unsigned TRISE0:1;
  unsigned TRISE1:1;
  unsigned TRISE2:1;
  unsigned TRISE3:1;
  unsigned TRISE4:1;
  unsigned TRISE5:1;
  unsigned TRISE6:1;
  unsigned TRISE7:1;
  unsigned TRISE8:1;
  unsigned TRISE9:1;
} TRISEBITS;
extern volatile TRISEBITS TRISEbits __attribute__((__sfr__));

extern volatile unsigned int  PORTE __attribute__((__sfr__));
typedef struct tagPORTEBITS {
  unsigned RE0:1;
  unsigned RE1:1;
  unsigned RE2:1;
  unsigned RE3:1;
  unsigned RE4:1;
  unsigned RE5:1;
  unsigned RE6:1;
  unsigned RE7:1;
  unsigned RE8:1;
  unsigned RE9:1;
} PORTEBITS;
extern volatile PORTEBITS PORTEbits __attribute__((__sfr__));

extern volatile unsigned int  LATE __attribute__((__sfr__));
typedef struct tagLATEBITS {
  unsigned LATE0:1;
  unsigned LATE1:1;
  unsigned LATE2:1;
  unsigned LATE3:1;
  unsigned LATE4:1;
  unsigned LATE5:1;
  unsigned LATE6:1;
  unsigned LATE7:1;
  unsigned LATE8:1;
  unsigned LATE9:1;
} LATEBITS;
extern volatile LATEBITS LATEbits __attribute__((__sfr__));

extern volatile unsigned int  ODCE __attribute__((__sfr__));
typedef struct tagODCEBITS {
  unsigned ODE0:1;
  unsigned ODE1:1;
  unsigned ODE2:1;
  unsigned ODE3:1;
  unsigned ODE4:1;
  unsigned ODE5:1;
  unsigned ODE6:1;
  unsigned ODE7:1;
  unsigned ODE8:1;
  unsigned ODE9:1;
} ODCEBITS;
extern volatile ODCEBITS ODCEbits __attribute__((__sfr__));

extern volatile unsigned int  TRISF __attribute__((__sfr__));
typedef struct tagTRISFBITS {
  unsigned TRISF0:1;
  unsigned TRISF1:1;
  unsigned TRISF2:1;
  unsigned TRISF3:1;
  unsigned TRISF4:1;
  unsigned TRISF5:1;
  unsigned TRISF6:1;
  unsigned :5;
  unsigned TRISF12:1;
  unsigned TRISF13:1;
} TRISFBITS;
extern volatile TRISFBITS TRISFbits __attribute__((__sfr__));

extern volatile unsigned int  PORTF __attribute__((__sfr__));
typedef struct tagPORTFBITS {
  unsigned RF0:1;
  unsigned RF1:1;
  unsigned RF2:1;
  unsigned RF3:1;
  unsigned RF4:1;
  unsigned RF5:1;
  unsigned RF6:1;
  unsigned :5;
  unsigned RF12:1;
  unsigned RF13:1;
} PORTFBITS;
extern volatile PORTFBITS PORTFbits __attribute__((__sfr__));

extern volatile unsigned int  LATF __attribute__((__sfr__));
typedef struct tagLATFBITS {
  unsigned LATF0:1;
  unsigned LATF1:1;
  unsigned LATF2:1;
  unsigned LATF3:1;
  unsigned LATF4:1;
  unsigned LATF5:1;
  unsigned LATF6:1;
  unsigned :5;
  unsigned LATF12:1;
  unsigned LATF13:1;
} LATFBITS;
extern volatile LATFBITS LATFbits __attribute__((__sfr__));

extern volatile unsigned int  ODCF __attribute__((__sfr__));
typedef struct tagODCFBITS {
  unsigned ODF0:1;
  unsigned ODF1:1;
  unsigned ODF2:1;
  unsigned ODF3:1;
  unsigned ODF4:1;
  unsigned ODF5:1;
  unsigned ODF6:1;
  unsigned :5;
  unsigned ODF12:1;
  unsigned ODF13:1;
} ODCFBITS;
extern volatile ODCFBITS ODCFbits __attribute__((__sfr__));

extern volatile unsigned int  TRISG __attribute__((__sfr__));
typedef struct tagTRISGBITS {
  unsigned TRISG0:1;
  unsigned TRISG1:1;
  unsigned TRISG2:1;
  unsigned TRISG3:1;
  unsigned :2;
  unsigned TRISG6:1;
  unsigned TRISG7:1;
  unsigned TRISG8:1;
  unsigned TRISG9:1;
} TRISGBITS;
extern volatile TRISGBITS TRISGbits __attribute__((__sfr__));

extern volatile unsigned int  PORTG __attribute__((__sfr__));
typedef struct tagPORTGBITS {
  unsigned RG0:1;
  unsigned RG1:1;
  unsigned RG2:1;
  unsigned RG3:1;
  unsigned :2;
  unsigned RG6:1;
  unsigned RG7:1;
  unsigned RG8:1;
  unsigned RG9:1;
} PORTGBITS;
extern volatile PORTGBITS PORTGbits __attribute__((__sfr__));

extern volatile unsigned int  LATG __attribute__((__sfr__));
typedef struct tagLATGBITS {
  unsigned LATG0:1;
  unsigned LATG1:1;
  unsigned LATG2:1;
  unsigned LATG3:1;
  unsigned :2;
  unsigned LATG6:1;
  unsigned LATG7:1;
  unsigned LATG8:1;
  unsigned LATG9:1;
} LATGBITS;
extern volatile LATGBITS LATGbits __attribute__((__sfr__));

extern volatile unsigned int  ODCG __attribute__((__sfr__));
typedef struct tagODCGBITS {
  unsigned ODG0:1;
  unsigned ODG1:1;
  unsigned ODG2:1;
  unsigned ODG3:1;
  unsigned :2;
  unsigned ODG6:1;
  unsigned ODG7:1;
  unsigned ODG8:1;
  unsigned ODG9:1;
} ODCGBITS;
extern volatile ODCGBITS ODCGbits __attribute__((__sfr__));

extern volatile unsigned int  PADCFG1 __attribute__((__sfr__));
typedef struct tagPADCFG1BITS {
  unsigned PMPTTL:1;
} PADCFG1BITS;
extern volatile PADCFG1BITS PADCFG1bits __attribute__((__sfr__));

extern volatile unsigned int  ADC1BUF0 __attribute__((__sfr__));
extern volatile unsigned int  ADC1BUF1 __attribute__((__sfr__));
extern volatile unsigned int  ADC1BUF2 __attribute__((__sfr__));
extern volatile unsigned int  ADC1BUF3 __attribute__((__sfr__));
extern volatile unsigned int  ADC1BUF4 __attribute__((__sfr__));
extern volatile unsigned int  ADC1BUF5 __attribute__((__sfr__));
extern volatile unsigned int  ADC1BUF6 __attribute__((__sfr__));
extern volatile unsigned int  ADC1BUF7 __attribute__((__sfr__));
extern volatile unsigned int  ADC1BUF8 __attribute__((__sfr__));
extern volatile unsigned int  ADC1BUF9 __attribute__((__sfr__));
extern volatile unsigned int  ADC1BUF10 __attribute__((__sfr__));
extern volatile unsigned int  ADC1BUF11 __attribute__((__sfr__));
extern volatile unsigned int  ADC1BUF12 __attribute__((__sfr__));
extern volatile unsigned int  ADC1BUF13 __attribute__((__sfr__));
extern volatile unsigned int  ADC1BUF14 __attribute__((__sfr__));
extern volatile unsigned int  ADC1BUF15 __attribute__((__sfr__));
extern volatile unsigned int  ADC1BUF24 __attribute__((__sfr__));
extern volatile unsigned int  ADC1BUF25 __attribute__((__sfr__));
extern volatile unsigned int  AD1CON1 __attribute__((__sfr__));
__extension__ typedef struct tagAD1CON1BITS {
  union {
    struct {
      unsigned DONE:1;
      unsigned SAMP:1;
      unsigned ASAM:1;
      unsigned :1;
      unsigned SSRC:4;
      unsigned FORM:2;
      unsigned MODE12:1;
      unsigned DMAEN:1;
      unsigned DMABM:1;
      unsigned ADSIDL:1;
      unsigned :1;
      unsigned ADON:1;
    };
    struct {
      unsigned :4;
      unsigned SSRC0:1;
      unsigned SSRC1:1;
      unsigned SSRC2:1;
      unsigned SSRC3:1;
      unsigned FORM0:1;
      unsigned FORM1:1;
    };
  };
} AD1CON1BITS;
extern volatile AD1CON1BITS AD1CON1bits __attribute__((__sfr__));

extern volatile unsigned int  AD1CON2 __attribute__((__sfr__));
__extension__ typedef struct tagAD1CON2BITS {
  union {
    struct {
      unsigned ALTS:1;
      unsigned BUFM:1;
      unsigned SMPI:5;
      unsigned BUFS:1;
      unsigned :2;
      unsigned CSCNA:1;
      unsigned BUFREGEN:1;
      unsigned OFFCAL:1;
      unsigned NVCFG0:1;
      unsigned PVCFG:2;
    };
    struct {
      unsigned :2;
      unsigned SMPI0:1;
      unsigned SMPI1:1;
      unsigned SMPI2:1;
      unsigned SMPI3:1;
      unsigned SMPI4:1;
      unsigned :7;
      unsigned PCVFG0:1;
      unsigned PCVFG1:1;
    };
  };
} AD1CON2BITS;
extern volatile AD1CON2BITS AD1CON2bits __attribute__((__sfr__));

extern volatile unsigned int  AD1CON3 __attribute__((__sfr__));
__extension__ typedef struct tagAD1CON3BITS {
  union {
    struct {
      unsigned ADCS:8;
      unsigned SAMC:5;
      unsigned PUMPEN:1;
      unsigned EXTSAM:1;
      unsigned ADRC:1;
    };
    struct {
      unsigned ADCS0:1;
      unsigned ADCS1:1;
      unsigned ADCS2:1;
      unsigned ADCS3:1;
      unsigned ADCS4:1;
      unsigned ADCS5:1;
      unsigned ADCS6:1;
      unsigned ADCS7:1;
      unsigned SAMC0:1;
      unsigned SAMC1:1;
      unsigned SAMC2:1;
      unsigned SAMC3:1;
      unsigned SAMC4:1;
    };
  };
} AD1CON3BITS;
extern volatile AD1CON3BITS AD1CON3bits __attribute__((__sfr__));

extern volatile unsigned int  AD1CHS __attribute__((__sfr__));
__extension__ typedef struct tagAD1CHSBITS {
  union {
    struct {
      unsigned CH0SA:5;
      unsigned CH0NA:3;
      unsigned CH0SB:5;
      unsigned CH0NB:3;
    };
    struct {
      unsigned CH0SA0:1;
      unsigned CH0SA1:1;
      unsigned CH0SA2:1;
      unsigned CH0SA3:1;
      unsigned CH0SA4:1;
      unsigned CH0NA0:1;
      unsigned CH0NA1:1;
      unsigned CH0NA2:1;
      unsigned CH0SB0:1;
      unsigned CH0SB1:1;
      unsigned CH0SB2:1;
      unsigned CH0SB3:1;
      unsigned CH0SB4:1;
      unsigned CH0NB0:1;
      unsigned CH0NB1:1;
      unsigned CH0NB2:1;
    };
  };
} AD1CHSBITS;
extern volatile AD1CHSBITS AD1CHSbits __attribute__((__sfr__));

extern volatile unsigned int  AD1CHS0 __attribute__((__sfr__));
__extension__ typedef struct tagAD1CHS0BITS {
  union {
    struct {
      unsigned CH0SA:5;
      unsigned CH0NA:3;
      unsigned CH0SB:5;
      unsigned CH0NB:3;
    };
    struct {
      unsigned CH0SA0:1;
      unsigned CH0SA1:1;
      unsigned CH0SA2:1;
      unsigned CH0SA3:1;
      unsigned CH0SA4:1;
      unsigned CH0NA0:1;
      unsigned CH0NA1:1;
      unsigned CH0NA2:1;
      unsigned CH0SB0:1;
      unsigned CH0SB1:1;
      unsigned CH0SB2:1;
      unsigned CH0SB3:1;
      unsigned CH0SB4:1;
      unsigned CH0NB0:1;
      unsigned CH0NB1:1;
      unsigned CH0NB2:1;
    };
  };
} AD1CHS0BITS;
extern volatile AD1CHS0BITS AD1CHS0bits __attribute__((__sfr__));

extern volatile unsigned int  AD1CSSH __attribute__((__sfr__));
typedef struct tagAD1CSSHBITS {
  unsigned CSS16:1;
  unsigned CSS17:1;
  unsigned CSS18:1;
  unsigned CSS19:1;
  unsigned CSS20:1;
  unsigned CSS21:1;
  unsigned CSS22:1;
  unsigned CSS23:1;
  unsigned CSS24:1;
  unsigned CSS25:1;
  unsigned CSS26:1;
  unsigned CSS27:1;
  unsigned CSS28:1;
  unsigned CSS29:1;
  unsigned CSS30:1;
} AD1CSSHBITS;
extern volatile AD1CSSHBITS AD1CSSHbits __attribute__((__sfr__));

extern volatile unsigned int  AD1CSSL __attribute__((__sfr__));
typedef struct tagAD1CSSLBITS {
  unsigned CSS0:1;
  unsigned CSS1:1;
  unsigned CSS2:1;
  unsigned CSS3:1;
  unsigned CSS4:1;
  unsigned CSS5:1;
  unsigned CSS6:1;
  unsigned CSS7:1;
  unsigned CSS8:1;
  unsigned CSS9:1;
  unsigned CSS10:1;
  unsigned CSS11:1;
  unsigned CSS12:1;
  unsigned CSS13:1;
  unsigned CSS14:1;
  unsigned CSS15:1;
} AD1CSSLBITS;
extern volatile AD1CSSLBITS AD1CSSLbits __attribute__((__sfr__));

extern volatile unsigned int  AD1CON4 __attribute__((__sfr__));
__extension__ typedef struct tagAD1CON4BITS {
  union {
    struct {
      unsigned DMABL:3;
    };
    struct {
      unsigned DMABL0:1;
      unsigned DMABL1:1;
      unsigned DMABL2:1;
    };
  };
} AD1CON4BITS;
extern volatile AD1CON4BITS AD1CON4bits __attribute__((__sfr__));

extern volatile unsigned int  AD1CON5 __attribute__((__sfr__));
__extension__ typedef struct tagAD1CON5BITS {
  union {
    struct {
      unsigned CM:2;
      unsigned WM:2;
      unsigned :4;
      unsigned ASINT:2;
      unsigned :2;
      unsigned BGREQ:1;
      unsigned CTMREQ:1;
      unsigned LPEN:1;
      unsigned ASEN:1;
    };
    struct {
      unsigned CM0:1;
      unsigned CM1:1;
      unsigned WM0:1;
      unsigned WM1:1;
      unsigned :4;
      unsigned ASINT0:1;
      unsigned ASINT1:1;
    };
  };
} AD1CON5BITS;
extern volatile AD1CON5BITS AD1CON5bits __attribute__((__sfr__));

extern volatile unsigned int  AD1CHITL __attribute__((__sfr__));
typedef struct tagAD1CHITLBITS {
  unsigned CHH0:1;
  unsigned CHH1:1;
  unsigned CHH2:1;
  unsigned CHH3:1;
  unsigned CHH4:1;
  unsigned CHH5:1;
  unsigned CHH6:1;
  unsigned CHH7:1;
  unsigned CHH8:1;
  unsigned CHH9:1;
  unsigned CHH10:1;
  unsigned CHH11:1;
  unsigned CHH12:1;
  unsigned CHH13:1;
  unsigned CHH14:1;
  unsigned CHH15:1;
} AD1CHITLBITS;
extern volatile AD1CHITLBITS AD1CHITLbits __attribute__((__sfr__));

extern volatile unsigned int  CTMUCON1 __attribute__((__sfr__));
typedef struct tagCTMUCON1BITS {
  unsigned :8;
  unsigned CTTRIG:1;
  unsigned IDISSEN:1;
  unsigned EDGSEQEN:1;
  unsigned EDGEN:1;
  unsigned TGEN:1;
  unsigned CTMUSIDL:1;
  unsigned :1;
  unsigned CTMUEN:1;
} CTMUCON1BITS;
extern volatile CTMUCON1BITS CTMUCON1bits __attribute__((__sfr__));

extern volatile unsigned int  CTMUCON2 __attribute__((__sfr__));
__extension__ typedef struct tagCTMUCON2BITS {
  union {
    struct {
      unsigned :2;
      unsigned EDG2SEL:4;
      unsigned EDG2POL:1;
      unsigned EDG2MOD:1;
      unsigned EDG1STAT:1;
      unsigned EDG2STAT:1;
      unsigned EDG1SEL:4;
      unsigned EDG1POL:1;
      unsigned EDG1MOD:1;
    };
    struct {
      unsigned :2;
      unsigned EDG2SEL0:1;
      unsigned EDG2SEL1:1;
      unsigned EDG2SEL2:1;
      unsigned EDG2SEL3:1;
      unsigned :4;
      unsigned EDG1SEL0:1;
      unsigned EDG1SEL1:1;
      unsigned EDG1SEL2:1;
      unsigned EDG1SEL3:1;
    };
  };
} CTMUCON2BITS;
extern volatile CTMUCON2BITS CTMUCON2bits __attribute__((__sfr__));

extern volatile unsigned int  CTMUICON __attribute__((__sfr__));
__extension__ typedef struct tagCTMUICONBITS {
  union {
    struct {
      unsigned :8;
      unsigned IRNG:2;
      unsigned ITRIM:6;
    };
    struct {
      unsigned :8;
      unsigned IRNG0:1;
      unsigned IRNG1:1;
      unsigned ITRIM0:1;
      unsigned ITRIM1:1;
      unsigned ITRIM2:1;
      unsigned ITRIM3:1;
      unsigned ITRIM4:1;
      unsigned ITRIM5:1;
    };
  };
} CTMUICONBITS;
extern volatile CTMUICONBITS CTMUICONbits __attribute__((__sfr__));

extern volatile unsigned int  AD1CTMENH __attribute__((__sfr__));
typedef struct tagAD1CTMENHBITS {
  unsigned CTMEN16:1;
  unsigned CTMEN17:1;
  unsigned CTMEN18:1;
  unsigned CTMEN19:1;
  unsigned CTMEN20:1;
  unsigned CTMEN21:1;
  unsigned CTMEN22:1;
  unsigned CTMEN23:1;
  unsigned CTMEN24:1;
  unsigned CTMEN25:1;
  unsigned CTMEN26:1;
  unsigned CTMEN27:1;
  unsigned CTMEN28:1;
  unsigned CTMEN29:1;
  unsigned CTMEN30:1;
  unsigned CTMEN31:1;
} AD1CTMENHBITS;
extern volatile AD1CTMENHBITS AD1CTMENHbits __attribute__((__sfr__));

extern volatile unsigned int  AD1CTMENL __attribute__((__sfr__));
typedef struct tagAD1CTMENLBITS {
  unsigned CTMEN0:1;
  unsigned CTMEN1:1;
  unsigned CTMEN2:1;
  unsigned CTMEN3:1;
  unsigned CTMEN4:1;
  unsigned CTMEN5:1;
  unsigned CTMEN6:1;
  unsigned CTMEN7:1;
  unsigned CTMEN8:1;
  unsigned CTMEN9:1;
  unsigned CTMEN10:1;
  unsigned CTMEN11:1;
  unsigned CTMEN12:1;
  unsigned CTMEN13:1;
  unsigned CTMEN14:1;
  unsigned CTMEN15:1;
} AD1CTMENLBITS;
extern volatile AD1CTMENLBITS AD1CTMENLbits __attribute__((__sfr__));

extern volatile unsigned int  AD1DMBUF __attribute__((__sfr__));
extern volatile unsigned int  DMACON __attribute__((__sfr__));
typedef struct tagDMACONBITS {
  unsigned PRSSEL:1;
  unsigned :14;
  unsigned DMAEN:1;
} DMACONBITS;
extern volatile DMACONBITS DMACONbits __attribute__((__sfr__));

extern volatile unsigned int  DMABUF __attribute__((__sfr__));
extern volatile unsigned int  DMAL __attribute__((__sfr__));
extern volatile unsigned int  DMAH __attribute__((__sfr__));
extern volatile unsigned int  DMACH0 __attribute__((__sfr__));
__extension__ typedef struct tagDMACH0BITS {
  union {
    struct {
      unsigned CHEN:1;
      unsigned BYTE:1;
      unsigned TRMODE:2;
      unsigned DAMODE:2;
      unsigned SAMODE:2;
      unsigned CHREQ:1;
      unsigned RELOAD:1;
      unsigned NULLW:1;
    };
    struct {
      unsigned :2;
      unsigned TRMODE0:1;
      unsigned TRMODE1:1;
      unsigned DAMODE0:1;
      unsigned DAMODE1:1;
      unsigned SAMODE0:1;
      unsigned SAMODE1:1;
    };
  };
} DMACH0BITS;
extern volatile DMACH0BITS DMACH0bits __attribute__((__sfr__));

extern volatile unsigned int  DMAINT0 __attribute__((__sfr__));
__extension__ typedef struct tagDMAINT0BITS {
  union {
    struct {
      unsigned HALFEN:1;
      unsigned :2;
      unsigned OVRUNIF:1;
      unsigned HALFIF:1;
      unsigned DONEIF:1;
      unsigned LOWIF:1;
      unsigned HIGHIF:1;
      unsigned CHSEL:6;
      unsigned :1;
      unsigned DBUFWF:1;
    };
    struct {
      unsigned :8;
      unsigned CHSEL0:1;
      unsigned CHSEL1:1;
      unsigned CHSEL2:1;
      unsigned CHSEL3:1;
      unsigned CHSEL4:1;
      unsigned CHSEL5:1;
    };
  };
} DMAINT0BITS;
extern volatile DMAINT0BITS DMAINT0bits __attribute__((__sfr__));

extern volatile unsigned int  DMASRC0 __attribute__((__sfr__));
extern volatile unsigned int  DMADST0 __attribute__((__sfr__));
extern volatile unsigned int  DMACNT0 __attribute__((__sfr__));
extern volatile unsigned int  DMACH1 __attribute__((__sfr__));
__extension__ typedef struct tagDMACH1BITS {
  union {
    struct {
      unsigned CHEN:1;
      unsigned BYTE:1;
      unsigned TRMODE:2;
      unsigned DAMODE:2;
      unsigned SAMODE:2;
      unsigned CHREQ:1;
      unsigned RELOAD:1;
      unsigned NULLW:1;
    };
    struct {
      unsigned :2;
      unsigned TRMODE0:1;
      unsigned TRMODE1:1;
      unsigned DAMODE0:1;
      unsigned DAMODE1:1;
      unsigned SAMODE0:1;
      unsigned SAMODE1:1;
    };
  };
} DMACH1BITS;
extern volatile DMACH1BITS DMACH1bits __attribute__((__sfr__));

extern volatile unsigned int  DMAINT1 __attribute__((__sfr__));
__extension__ typedef struct tagDMAINT1BITS {
  union {
    struct {
      unsigned HALFEN:1;
      unsigned :2;
      unsigned OVRUNIF:1;
      unsigned HALFIF:1;
      unsigned DONEIF:1;
      unsigned LOWIF:1;
      unsigned HIGHIF:1;
      unsigned CHSEL:6;
      unsigned :1;
      unsigned DBUFWF:1;
    };
    struct {
      unsigned :8;
      unsigned CHSEL0:1;
      unsigned CHSEL1:1;
      unsigned CHSEL2:1;
      unsigned CHSEL3:1;
      unsigned CHSEL4:1;
      unsigned CHSEL5:1;
    };
  };
} DMAINT1BITS;
extern volatile DMAINT1BITS DMAINT1bits __attribute__((__sfr__));

extern volatile unsigned int  DMASRC1 __attribute__((__sfr__));
extern volatile unsigned int  DMADST1 __attribute__((__sfr__));
extern volatile unsigned int  DMACNT1 __attribute__((__sfr__));
extern volatile unsigned int  DMACH2 __attribute__((__sfr__));
__extension__ typedef struct tagDMACH2BITS {
  union {
    struct {
      unsigned CHEN:1;
      unsigned BYTE:1;
      unsigned TRMODE:2;
      unsigned DAMODE:2;
      unsigned SAMODE:2;
      unsigned CHREQ:1;
      unsigned RELOAD:1;
      unsigned NULLW:1;
    };
    struct {
      unsigned :2;
      unsigned TRMODE0:1;
      unsigned TRMODE1:1;
      unsigned DAMODE0:1;
      unsigned DAMODE1:1;
      unsigned SAMODE0:1;
      unsigned SAMODE1:1;
    };
  };
} DMACH2BITS;
extern volatile DMACH2BITS DMACH2bits __attribute__((__sfr__));

extern volatile unsigned int  DMAINT2 __attribute__((__sfr__));
__extension__ typedef struct tagDMAINT2BITS {
  union {
    struct {
      unsigned HALFEN:1;
      unsigned :2;
      unsigned OVRUNIF:1;
      unsigned HALFIF:1;
      unsigned DONEIF:1;
      unsigned LOWIF:1;
      unsigned HIGHIF:1;
      unsigned CHSEL:6;
      unsigned :1;
      unsigned DBUFWF:1;
    };
    struct {
      unsigned :8;
      unsigned CHSEL0:1;
      unsigned CHSEL1:1;
      unsigned CHSEL2:1;
      unsigned CHSEL3:1;
      unsigned CHSEL4:1;
      unsigned CHSEL5:1;
    };
  };
} DMAINT2BITS;
extern volatile DMAINT2BITS DMAINT2bits __attribute__((__sfr__));

extern volatile unsigned int  DMASRC2 __attribute__((__sfr__));
extern volatile unsigned int  DMADST2 __attribute__((__sfr__));
extern volatile unsigned int  DMACNT2 __attribute__((__sfr__));
extern volatile unsigned int  DMACH3 __attribute__((__sfr__));
__extension__ typedef struct tagDMACH3BITS {
  union {
    struct {
      unsigned CHEN:1;
      unsigned BYTE:1;
      unsigned TRMODE:2;
      unsigned DAMODE:2;
      unsigned SAMODE:2;
      unsigned CHREQ:1;
      unsigned RELOAD:1;
      unsigned NULLW:1;
    };
    struct {
      unsigned :2;
      unsigned TRMODE0:1;
      unsigned TRMODE1:1;
      unsigned DAMODE0:1;
      unsigned DAMODE1:1;
      unsigned SAMODE0:1;
      unsigned SAMODE1:1;
    };
  };
} DMACH3BITS;
extern volatile DMACH3BITS DMACH3bits __attribute__((__sfr__));

extern volatile unsigned int  DMAINT3 __attribute__((__sfr__));
__extension__ typedef struct tagDMAINT3BITS {
  union {
    struct {
      unsigned HALFEN:1;
      unsigned :2;
      unsigned OVRUNIF:1;
      unsigned HALFIF:1;
      unsigned DONEIF:1;
      unsigned LOWIF:1;
      unsigned HIGHIF:1;
      unsigned CHSEL:6;
      unsigned :1;
      unsigned DBUFWF:1;
    };
    struct {
      unsigned :8;
      unsigned CHSEL0:1;
      unsigned CHSEL1:1;
      unsigned CHSEL2:1;
      unsigned CHSEL3:1;
      unsigned CHSEL4:1;
      unsigned CHSEL5:1;
    };
  };
} DMAINT3BITS;
extern volatile DMAINT3BITS DMAINT3bits __attribute__((__sfr__));

extern volatile unsigned int  DMASRC3 __attribute__((__sfr__));
extern volatile unsigned int  DMADST3 __attribute__((__sfr__));
extern volatile unsigned int  DMACNT3 __attribute__((__sfr__));
extern volatile unsigned int  DMACH4 __attribute__((__sfr__));
__extension__ typedef struct tagDMACH4BITS {
  union {
    struct {
      unsigned CHEN:1;
      unsigned BYTE:1;
      unsigned TRMODE:2;
      unsigned DAMODE:2;
      unsigned SAMODE:2;
      unsigned CHREQ:1;
      unsigned RELOAD:1;
      unsigned NULLW:1;
    };
    struct {
      unsigned :2;
      unsigned TRMODE0:1;
      unsigned TRMODE1:1;
      unsigned DAMODE0:1;
      unsigned DAMODE1:1;
      unsigned SAMODE0:1;
      unsigned SAMODE1:1;
    };
  };
} DMACH4BITS;
extern volatile DMACH4BITS DMACH4bits __attribute__((__sfr__));

extern volatile unsigned int  DMAINT4 __attribute__((__sfr__));
__extension__ typedef struct tagDMAINT4BITS {
  union {
    struct {
      unsigned HALFEN:1;
      unsigned :2;
      unsigned OVRUNIF:1;
      unsigned HALFIF:1;
      unsigned DONEIF:1;
      unsigned LOWIF:1;
      unsigned HIGHIF:1;
      unsigned CHSEL:6;
      unsigned :1;
      unsigned DBUFWF:1;
    };
    struct {
      unsigned :8;
      unsigned CHSEL0:1;
      unsigned CHSEL1:1;
      unsigned CHSEL2:1;
      unsigned CHSEL3:1;
      unsigned CHSEL4:1;
      unsigned CHSEL5:1;
    };
  };
} DMAINT4BITS;
extern volatile DMAINT4BITS DMAINT4bits __attribute__((__sfr__));

extern volatile unsigned int  DMASRC4 __attribute__((__sfr__));
extern volatile unsigned int  DMADST4 __attribute__((__sfr__));
extern volatile unsigned int  DMACNT4 __attribute__((__sfr__));
extern volatile unsigned int  DMACH5 __attribute__((__sfr__));
__extension__ typedef struct tagDMACH5BITS {
  union {
    struct {
      unsigned CHEN:1;
      unsigned BYTE:1;
      unsigned TRMODE:2;
      unsigned DAMODE:2;
      unsigned SAMODE:2;
      unsigned CHREQ:1;
      unsigned RELOAD:1;
      unsigned NULLW:1;
    };
    struct {
      unsigned :2;
      unsigned TRMODE0:1;
      unsigned TRMODE1:1;
      unsigned DAMODE0:1;
      unsigned DAMODE1:1;
      unsigned SAMODE0:1;
      unsigned SAMODE1:1;
    };
  };
} DMACH5BITS;
extern volatile DMACH5BITS DMACH5bits __attribute__((__sfr__));

extern volatile unsigned int  DMAINT5 __attribute__((__sfr__));
__extension__ typedef struct tagDMAINT5BITS {
  union {
    struct {
      unsigned HALFEN:1;
      unsigned :2;
      unsigned OVRUNIF:1;
      unsigned HALFIF:1;
      unsigned DONEIF:1;
      unsigned LOWIF:1;
      unsigned HIGHIF:1;
      unsigned CHSEL:6;
      unsigned :1;
      unsigned DBUFWF:1;
    };
    struct {
      unsigned :8;
      unsigned CHSEL0:1;
      unsigned CHSEL1:1;
      unsigned CHSEL2:1;
      unsigned CHSEL3:1;
      unsigned CHSEL4:1;
      unsigned CHSEL5:1;
    };
  };
} DMAINT5BITS;
extern volatile DMAINT5BITS DMAINT5bits __attribute__((__sfr__));

extern volatile unsigned int  DMASRC5 __attribute__((__sfr__));
extern volatile unsigned int  DMADST5 __attribute__((__sfr__));
extern volatile unsigned int  DMACNT5 __attribute__((__sfr__));
extern volatile unsigned int  ANCFG __attribute__((__sfr__));
typedef struct tagANCFGBITS {
  unsigned VBGEN:1;
  unsigned VBG2EN:1;
  unsigned VBG6EN:1;
} ANCFGBITS;
extern volatile ANCFGBITS ANCFGbits __attribute__((__sfr__));

extern volatile unsigned int  ANSB __attribute__((__sfr__));
typedef struct tagANSBBITS {
  unsigned ANSB0:1;
  unsigned ANSB1:1;
  unsigned ANSB2:1;
  unsigned ANSB3:1;
  unsigned ANSB4:1;
  unsigned ANSB5:1;
  unsigned ANSB6:1;
  unsigned ANSB7:1;
  unsigned ANSB8:1;
  unsigned ANSB9:1;
  unsigned ANSB10:1;
  unsigned ANSB11:1;
  unsigned ANSB12:1;
  unsigned ANSB13:1;
  unsigned ANSB14:1;
  unsigned ANSB15:1;
} ANSBBITS;
extern volatile ANSBBITS ANSBbits __attribute__((__sfr__));

extern volatile unsigned int  ANSD __attribute__((__sfr__));
typedef struct tagANSDBITS {
  unsigned :6;
  unsigned ANSD6:1;
  unsigned ANSD7:1;
  unsigned :2;
  unsigned ANSD10:1;
  unsigned ANSD11:1;
} ANSDBITS;
extern volatile ANSDBITS ANSDbits __attribute__((__sfr__));

extern volatile unsigned int  ANSE __attribute__((__sfr__));
typedef struct tagANSEBITS {
  unsigned :4;
  unsigned ANSE4:1;
  unsigned ANSE5:1;
  unsigned ANSE6:1;
  unsigned ANSE7:1;
  unsigned :1;
  unsigned ANSE9:1;
} ANSEBITS;
extern volatile ANSEBITS ANSEbits __attribute__((__sfr__));

extern volatile unsigned int  ANSG __attribute__((__sfr__));
typedef struct tagANSGBITS {
  unsigned :6;
  unsigned ANSG6:1;
  unsigned ANSG7:1;
  unsigned ANSG8:1;
  unsigned ANSG9:1;
} ANSGBITS;
extern volatile ANSGBITS ANSGbits __attribute__((__sfr__));

extern volatile unsigned int  LCDREG __attribute__((__sfr__));
__extension__ typedef struct tagLCDREGBITS {
  union {
    struct {
      unsigned CKSEL:2;
      unsigned MODE13:1;
      unsigned BIAS:3;
      unsigned :9;
      unsigned CPEN:1;
    };
    struct {
      unsigned CKSEL0:1;
      unsigned CKSEL1:1;
      unsigned :1;
      unsigned BIAS0:1;
      unsigned BIAS1:1;
      unsigned BIAS2:1;
    };
  };
} LCDREGBITS;
extern volatile LCDREGBITS LCDREGbits __attribute__((__sfr__));

extern volatile unsigned int  LCDREF __attribute__((__sfr__));
__extension__ typedef struct tagLCDREFBITS {
  union {
    struct {
      unsigned LRLAT:3;
      unsigned :1;
      unsigned LRLBP:2;
      unsigned LRLAP:2;
      unsigned VLCD1PE:1;
      unsigned VLCD2PE:1;
      unsigned VLCD3PE:1;
      unsigned LCDCST:3;
      unsigned :1;
      unsigned LCDIRE:1;
    };
    struct {
      unsigned LRLAT0:1;
      unsigned LRLAT1:1;
      unsigned LRLAT2:1;
      unsigned :1;
      unsigned LRLBP0:1;
      unsigned LRLBP1:1;
      unsigned LRLAP0:1;
      unsigned LRLAP1:1;
      unsigned :3;
      unsigned LCDCST0:1;
      unsigned LCDCST1:1;
      unsigned LCDCST2:1;
    };
  };
} LCDREFBITS;
extern volatile LCDREFBITS LCDREFbits __attribute__((__sfr__));

extern volatile unsigned int  LCDCON __attribute__((__sfr__));
__extension__ typedef struct tagLCDCONBITS {
  union {
    struct {
      unsigned LMUX:3;
      unsigned CS:2;
      unsigned WERR:1;
      unsigned SLPEN:1;
      unsigned :6;
      unsigned LCDSIDL:1;
      unsigned :1;
      unsigned LCDEN:1;
    };
    struct {
      unsigned LMUX0:1;
      unsigned LMUX1:1;
      unsigned LMUX2:1;
      unsigned CS0:1;
      unsigned CS1:1;
    };
  };
} LCDCONBITS;
extern volatile LCDCONBITS LCDCONbits __attribute__((__sfr__));

extern volatile unsigned int  LCDPS __attribute__((__sfr__));
__extension__ typedef struct tagLCDPSBITS {
  union {
    struct {
      unsigned LP:4;
      unsigned WA:1;
      unsigned LCDA:1;
      unsigned BIASMD:1;
      unsigned WFT:1;
    };
    struct {
      unsigned LP0:1;
      unsigned LP1:1;
      unsigned LP2:1;
      unsigned LP3:1;
    };
  };
} LCDPSBITS;
extern volatile LCDPSBITS LCDPSbits __attribute__((__sfr__));

extern volatile unsigned int  LCDSE0 __attribute__((__sfr__));
typedef struct tagLCDSE0BITS {
  unsigned SE00:1;
  unsigned SE01:1;
  unsigned SE02:1;
  unsigned SE03:1;
  unsigned SE04:1;
  unsigned SE05:1;
  unsigned SE06:1;
  unsigned SE07:1;
  unsigned SE08:1;
  unsigned SE09:1;
  unsigned SE10:1;
  unsigned SE11:1;
  unsigned SE12:1;
  unsigned SE13:1;
  unsigned SE14:1;
  unsigned SE15:1;
} LCDSE0BITS;
extern volatile LCDSE0BITS LCDSE0bits __attribute__((__sfr__));

extern volatile unsigned int  LCDSE1 __attribute__((__sfr__));
typedef struct tagLCDSE1BITS {
  unsigned SE16:1;
  unsigned SE17:1;
  unsigned SE18:1;
  unsigned SE19:1;
  unsigned SE20:1;
  unsigned SE21:1;
  unsigned SE22:1;
  unsigned SE23:1;
  unsigned SE24:1;
  unsigned SE25:1;
  unsigned SE26:1;
  unsigned SE27:1;
  unsigned SE28:1;
  unsigned SE29:1;
  unsigned SE30:1;
  unsigned SE31:1;
} LCDSE1BITS;
extern volatile LCDSE1BITS LCDSE1bits __attribute__((__sfr__));

extern volatile unsigned int  LCDSE2 __attribute__((__sfr__));
typedef struct tagLCDSE2BITS {
  unsigned SE32:1;
  unsigned SE33:1;
  unsigned SE34:1;
  unsigned SE35:1;
  unsigned SE36:1;
  unsigned SE37:1;
  unsigned SE38:1;
  unsigned SE39:1;
  unsigned SE40:1;
  unsigned SE41:1;
  unsigned SE42:1;
  unsigned SE43:1;
  unsigned SE44:1;
  unsigned SE45:1;
  unsigned SE46:1;
  unsigned SE47:1;
} LCDSE2BITS;
extern volatile LCDSE2BITS LCDSE2bits __attribute__((__sfr__));

extern volatile unsigned int  LCDSE3 __attribute__((__sfr__));
typedef struct tagLCDSE3BITS {
  unsigned SE48:1;
  unsigned :1;
  unsigned SE50:1;
} LCDSE3BITS;
extern volatile LCDSE3BITS LCDSE3bits __attribute__((__sfr__));

extern volatile unsigned int  LCDDATA0 __attribute__((__sfr__));
typedef struct tagLCDDATA0BITS {
  unsigned S00C0:1;
  unsigned S01C0:1;
  unsigned S02C0:1;
  unsigned S03C0:1;
  unsigned S04C0:1;
  unsigned S05C0:1;
  unsigned S06C0:1;
  unsigned S07C0:1;
  unsigned S08C0:1;
  unsigned S09C0:1;
  unsigned S10C0:1;
  unsigned S11C0:1;
  unsigned S12C0:1;
  unsigned S13C0:1;
  unsigned S14C0:1;
  unsigned S15C0:1;
} LCDDATA0BITS;
extern volatile LCDDATA0BITS LCDDATA0bits __attribute__((__sfr__));

extern volatile unsigned int  LCDDATA1 __attribute__((__sfr__));
typedef struct tagLCDDATA1BITS {
  unsigned S16C0:1;
  unsigned S17C0:1;
  unsigned S18C0:1;
  unsigned S19C0:1;
  unsigned S20C0:1;
  unsigned S21C0:1;
  unsigned S22C0:1;
  unsigned S23C0:1;
  unsigned S24C0:1;
  unsigned S25C0:1;
  unsigned S26C0:1;
  unsigned S27C0:1;
  unsigned S28C0:1;
  unsigned S29C0:1;
  unsigned S30C0:1;
  unsigned S31C0:1;
} LCDDATA1BITS;
extern volatile LCDDATA1BITS LCDDATA1bits __attribute__((__sfr__));

extern volatile unsigned int  LCDDATA2 __attribute__((__sfr__));
typedef struct tagLCDDATA2BITS {
  unsigned S32C0:1;
  unsigned S33C0:1;
  unsigned S34C0:1;
  unsigned S35C0:1;
  unsigned S36C0:1;
  unsigned S37C0:1;
  unsigned S38C0:1;
  unsigned S39C0:1;
  unsigned S40C0:1;
  unsigned S41C0:1;
  unsigned S42C0:1;
  unsigned S43C0:1;
  unsigned S44C0:1;
  unsigned S45C0:1;
  unsigned S46C0:1;
  unsigned S47C0:1;
} LCDDATA2BITS;
extern volatile LCDDATA2BITS LCDDATA2bits __attribute__((__sfr__));

extern volatile unsigned int  LCDDATA3 __attribute__((__sfr__));
typedef struct tagLCDDATA3BITS {
  unsigned S48C0:1;
  unsigned :1;
  unsigned S50C0:1;
} LCDDATA3BITS;
extern volatile LCDDATA3BITS LCDDATA3bits __attribute__((__sfr__));

extern volatile unsigned int  LCDDATA4 __attribute__((__sfr__));
typedef struct tagLCDDATA4BITS {
  unsigned S00C1:1;
  unsigned S01C1:1;
  unsigned S02C1:1;
  unsigned S03C1:1;
  unsigned S04C1:1;
  unsigned S05C1:1;
  unsigned S06C1:1;
  unsigned S07C1:1;
  unsigned S08C1:1;
  unsigned S09C1:1;
  unsigned S10C1:1;
  unsigned S11C1:1;
  unsigned S12C1:1;
  unsigned S13C1:1;
  unsigned S14C1:1;
  unsigned S15C1:1;
} LCDDATA4BITS;
extern volatile LCDDATA4BITS LCDDATA4bits __attribute__((__sfr__));

extern volatile unsigned int  LCDDATA5 __attribute__((__sfr__));
typedef struct tagLCDDATA5BITS {
  unsigned S16C1:1;
  unsigned S17C1:1;
  unsigned S18C1:1;
  unsigned S19C1:1;
  unsigned S20C1:1;
  unsigned S21C1:1;
  unsigned S22C1:1;
  unsigned S23C1:1;
  unsigned S24C1:1;
  unsigned S25C1:1;
  unsigned S26C1:1;
  unsigned S27C1:1;
  unsigned S28C1:1;
  unsigned S29C1:1;
  unsigned S30C1:1;
  unsigned S31C1:1;
} LCDDATA5BITS;
extern volatile LCDDATA5BITS LCDDATA5bits __attribute__((__sfr__));

extern volatile unsigned int  LCDDATA6 __attribute__((__sfr__));
typedef struct tagLCDDATA6BITS {
  unsigned S32C1:1;
  unsigned S33C1:1;
  unsigned S34C1:1;
  unsigned S35C1:1;
  unsigned S36C1:1;
  unsigned S37C1:1;
  unsigned S38C1:1;
  unsigned S39C1:1;
  unsigned S40C1:1;
  unsigned S41C1:1;
  unsigned S42C1:1;
  unsigned S43C1:1;
  unsigned S44C1:1;
  unsigned S45C1:1;
  unsigned S46C1:1;
  unsigned S47C1:1;
} LCDDATA6BITS;
extern volatile LCDDATA6BITS LCDDATA6bits __attribute__((__sfr__));

extern volatile unsigned int  LCDDATA7 __attribute__((__sfr__));
typedef struct tagLCDDATA7BITS {
  unsigned S48C1:1;
  unsigned :1;
  unsigned S50C1:1;
} LCDDATA7BITS;
extern volatile LCDDATA7BITS LCDDATA7bits __attribute__((__sfr__));

extern volatile unsigned int  LCDDATA8 __attribute__((__sfr__));
typedef struct tagLCDDATA8BITS {
  unsigned S00C2:1;
  unsigned S01C2:1;
  unsigned S02C2:1;
  unsigned S03C2:1;
  unsigned S04C2:1;
  unsigned S05C2:1;
  unsigned S06C2:1;
  unsigned S07C2:1;
  unsigned S08C2:1;
  unsigned S09C2:1;
  unsigned S10C2:1;
  unsigned S11C2:1;
  unsigned S12C2:1;
  unsigned S13C2:1;
  unsigned S14C2:1;
  unsigned S15C2:1;
} LCDDATA8BITS;
extern volatile LCDDATA8BITS LCDDATA8bits __attribute__((__sfr__));

extern volatile unsigned int  LCDDATA9 __attribute__((__sfr__));
typedef struct tagLCDDATA9BITS {
  unsigned S16C2:1;
  unsigned S17C2:1;
  unsigned S18C2:1;
  unsigned S19C2:1;
  unsigned S20C2:1;
  unsigned S21C2:1;
  unsigned S22C2:1;
  unsigned S23C2:1;
  unsigned S24C2:1;
  unsigned S25C2:1;
  unsigned S26C2:1;
  unsigned S27C2:1;
  unsigned S28C2:1;
  unsigned S29C2:1;
  unsigned S30C2:1;
  unsigned S31C2:1;
} LCDDATA9BITS;
extern volatile LCDDATA9BITS LCDDATA9bits __attribute__((__sfr__));

extern volatile unsigned int  LCDDATA10 __attribute__((__sfr__));
typedef struct tagLCDDATA10BITS {
  unsigned S32C2:1;
  unsigned S33C2:1;
  unsigned S34C2:1;
  unsigned S35C2:1;
  unsigned S36C2:1;
  unsigned S37C2:1;
  unsigned S38C2:1;
  unsigned S39C2:1;
  unsigned S40C2:1;
  unsigned S41C2:1;
  unsigned S42C2:1;
  unsigned S43C2:1;
  unsigned S44C2:1;
  unsigned S45C2:1;
  unsigned S46C2:1;
  unsigned S47C2:1;
} LCDDATA10BITS;
extern volatile LCDDATA10BITS LCDDATA10bits __attribute__((__sfr__));

extern volatile unsigned int  LCDDATA11 __attribute__((__sfr__));
typedef struct tagLCDDATA11BITS {
  unsigned S48C2:1;
  unsigned :1;
  unsigned S50C2:1;
} LCDDATA11BITS;
extern volatile LCDDATA11BITS LCDDATA11bits __attribute__((__sfr__));

extern volatile unsigned int  LCDDATA12 __attribute__((__sfr__));
typedef struct tagLCDDATA12BITS {
  unsigned S00C3:1;
  unsigned S01C3:1;
  unsigned S02C3:1;
  unsigned S03C3:1;
  unsigned S04C3:1;
  unsigned S05C3:1;
  unsigned S06C3:1;
  unsigned S07C3:1;
  unsigned S08C3:1;
  unsigned S09C3:1;
  unsigned S10C3:1;
  unsigned S11C3:1;
  unsigned S12C3:1;
  unsigned S13C3:1;
  unsigned S14C3:1;
  unsigned S15C3:1;
} LCDDATA12BITS;
extern volatile LCDDATA12BITS LCDDATA12bits __attribute__((__sfr__));

extern volatile unsigned int  LCDDATA13 __attribute__((__sfr__));
typedef struct tagLCDDATA13BITS {
  unsigned S16C3:1;
  unsigned S17C3:1;
  unsigned S18C3:1;
  unsigned S19C3:1;
  unsigned S20C3:1;
  unsigned S21C3:1;
  unsigned S22C3:1;
  unsigned S23C3:1;
  unsigned S24C3:1;
  unsigned S25C3:1;
  unsigned S26C3:1;
  unsigned S27C3:1;
  unsigned S28C3:1;
  unsigned S29C3:1;
  unsigned S30C3:1;
  unsigned S31C3:1;
} LCDDATA13BITS;
extern volatile LCDDATA13BITS LCDDATA13bits __attribute__((__sfr__));

extern volatile unsigned int  LCDDATA14 __attribute__((__sfr__));
typedef struct tagLCDDATA14BITS {
  unsigned S32C3:1;
  unsigned S33C3:1;
  unsigned S34C3:1;
  unsigned S35C3:1;
  unsigned S36C3:1;
  unsigned S37C3:1;
  unsigned S38C3:1;
  unsigned S39C3:1;
  unsigned S40C3:1;
  unsigned S41C3:1;
  unsigned S42C3:1;
  unsigned S43C3:1;
  unsigned S44C3:1;
  unsigned S45C3:1;
  unsigned S46C3:1;
  unsigned S47C3:1;
} LCDDATA14BITS;
extern volatile LCDDATA14BITS LCDDATA14bits __attribute__((__sfr__));

extern volatile unsigned int  LCDDATA15 __attribute__((__sfr__));
typedef struct tagLCDDATA15BITS {
  unsigned S48C3:1;
  unsigned :1;
  unsigned S50C3:1;
} LCDDATA15BITS;
extern volatile LCDDATA15BITS LCDDATA15bits __attribute__((__sfr__));

extern volatile unsigned int  LCDDATA16 __attribute__((__sfr__));
typedef struct tagLCDDATA16BITS {
  unsigned S00C4:1;
  unsigned S01C4:1;
  unsigned S02C4:1;
  unsigned S03C4:1;
  unsigned S04C4:1;
  unsigned S05C4:1;
  unsigned S06C4:1;
  unsigned S07C4:1;
  unsigned S08C4:1;
  unsigned S09C4:1;
  unsigned S10C4:1;
  unsigned S11C4:1;
  unsigned S12C4:1;
  unsigned S13C4:1;
  unsigned S14C4:1;
  unsigned S15C4:1;
} LCDDATA16BITS;
extern volatile LCDDATA16BITS LCDDATA16bits __attribute__((__sfr__));

extern volatile unsigned int  LCDDATA17 __attribute__((__sfr__));
typedef struct tagLCDDATA17BITS {
  unsigned S16C4:1;
  unsigned S17C4:1;
  unsigned S18C4:1;
  unsigned S19C4:1;
  unsigned S20C4:1;
  unsigned S21C4:1;
  unsigned S22C4:1;
  unsigned S23C4:1;
  unsigned S24C4:1;
  unsigned S25C4:1;
  unsigned S26C4:1;
  unsigned S27C4:1;
  unsigned S28C4:1;
  unsigned S29C4:1;
  unsigned S30C4:1;
  unsigned S31C4:1;
} LCDDATA17BITS;
extern volatile LCDDATA17BITS LCDDATA17bits __attribute__((__sfr__));

extern volatile unsigned int  LCDDATA18 __attribute__((__sfr__));
typedef struct tagLCDDATA18BITS {
  unsigned S32C4:1;
  unsigned S33C4:1;
  unsigned S34C4:1;
  unsigned S35C4:1;
  unsigned S36C4:1;
  unsigned S37C4:1;
  unsigned S38C4:1;
  unsigned S39C4:1;
  unsigned S40C4:1;
  unsigned S41C4:1;
  unsigned S42C4:1;
  unsigned S43C4:1;
  unsigned S44C4:1;
  unsigned S45C4:1;
  unsigned S46C4:1;
  unsigned S47C4:1;
} LCDDATA18BITS;
extern volatile LCDDATA18BITS LCDDATA18bits __attribute__((__sfr__));

extern volatile unsigned int  LCDDATA19 __attribute__((__sfr__));
typedef struct tagLCDDATA19BITS {
  unsigned S48C4:1;
  unsigned :1;
  unsigned S50C4:1;
} LCDDATA19BITS;
extern volatile LCDDATA19BITS LCDDATA19bits __attribute__((__sfr__));

extern volatile unsigned int  LCDDATA20 __attribute__((__sfr__));
typedef struct tagLCDDATA20BITS {
  unsigned S00C5:1;
  unsigned S01C5:1;
  unsigned S02C5:1;
  unsigned S03C5:1;
  unsigned S04C5:1;
  unsigned S05C5:1;
  unsigned S06C5:1;
  unsigned S07C5:1;
  unsigned S08C5:1;
  unsigned S09C5:1;
  unsigned S10C5:1;
  unsigned S11C5:1;
  unsigned S12C5:1;
  unsigned S13C5:1;
  unsigned S14C5:1;
  unsigned S15C5:1;
} LCDDATA20BITS;
extern volatile LCDDATA20BITS LCDDATA20bits __attribute__((__sfr__));

extern volatile unsigned int  LCDDATA21 __attribute__((__sfr__));
typedef struct tagLCDDATA21BITS {
  unsigned S16C5:1;
  unsigned S17C5:1;
  unsigned S18C5:1;
  unsigned S19C5:1;
  unsigned S20C5:1;
  unsigned S21C5:1;
  unsigned S22C5:1;
  unsigned S23C5:1;
  unsigned S24C5:1;
  unsigned S25C5:1;
  unsigned S26C5:1;
  unsigned S27C5:1;
  unsigned S28C5:1;
  unsigned S29C5:1;
  unsigned S30C5:1;
  unsigned S31C5:1;
} LCDDATA21BITS;
extern volatile LCDDATA21BITS LCDDATA21bits __attribute__((__sfr__));

extern volatile unsigned int  LCDDATA22 __attribute__((__sfr__));
typedef struct tagLCDDATA22BITS {
  unsigned S32C5:1;
  unsigned S33C5:1;
  unsigned S34C5:1;
  unsigned S35C5:1;
  unsigned S36C5:1;
  unsigned S37C5:1;
  unsigned S38C5:1;
  unsigned S39C5:1;
  unsigned S40C5:1;
  unsigned S41C5:1;
  unsigned S42C5:1;
  unsigned S43C5:1;
  unsigned S44C5:1;
  unsigned S45C5:1;
  unsigned S46C5:1;
  unsigned S47C5:1;
} LCDDATA22BITS;
extern volatile LCDDATA22BITS LCDDATA22bits __attribute__((__sfr__));

extern volatile unsigned int  LCDDATA23 __attribute__((__sfr__));
typedef struct tagLCDDATA23BITS {
  unsigned S48C5:1;
  unsigned :1;
  unsigned S50C5:1;
} LCDDATA23BITS;
extern volatile LCDDATA23BITS LCDDATA23bits __attribute__((__sfr__));

extern volatile unsigned int  LCDDATA24 __attribute__((__sfr__));
typedef struct tagLCDDATA24BITS {
  unsigned S00C6:1;
  unsigned S01C6:1;
  unsigned S02C6:1;
  unsigned S03C6:1;
  unsigned S04C6:1;
  unsigned S05C6:1;
  unsigned S06C6:1;
  unsigned S07C6:1;
  unsigned S08C6:1;
  unsigned S09C6:1;
  unsigned S10C6:1;
  unsigned S11C6:1;
  unsigned S12C6:1;
  unsigned S13C6:1;
  unsigned S14C6:1;
  unsigned S15C6:1;
} LCDDATA24BITS;
extern volatile LCDDATA24BITS LCDDATA24bits __attribute__((__sfr__));

extern volatile unsigned int  LCDDATA25 __attribute__((__sfr__));
typedef struct tagLCDDATA25BITS {
  unsigned S16C6:1;
  unsigned S17C6:1;
  unsigned S18C6:1;
  unsigned S19C6:1;
  unsigned S20C6:1;
  unsigned S21C6:1;
  unsigned S22C6:1;
  unsigned S23C6:1;
  unsigned S24C6:1;
  unsigned S25C6:1;
  unsigned S26C6:1;
  unsigned S27C6:1;
  unsigned S28C6:1;
  unsigned S29C6:1;
  unsigned S30C6:1;
  unsigned S31C6:1;
} LCDDATA25BITS;
extern volatile LCDDATA25BITS LCDDATA25bits __attribute__((__sfr__));

extern volatile unsigned int  LCDDATA26 __attribute__((__sfr__));
typedef struct tagLCDDATA26BITS {
  unsigned S32C6:1;
  unsigned S33C6:1;
  unsigned S34C6:1;
  unsigned S35C6:1;
  unsigned S36C6:1;
  unsigned S37C6:1;
  unsigned S38C6:1;
  unsigned S39C6:1;
  unsigned S40C6:1;
  unsigned S41C6:1;
  unsigned S42C6:1;
  unsigned S43C6:1;
  unsigned S44C6:1;
  unsigned S45C6:1;
  unsigned S46C6:1;
  unsigned S47C6:1;
} LCDDATA26BITS;
extern volatile LCDDATA26BITS LCDDATA26bits __attribute__((__sfr__));

extern volatile unsigned int  LCDDATA27 __attribute__((__sfr__));
typedef struct tagLCDDATA27BITS {
  unsigned S48C6:1;
  unsigned :1;
  unsigned S50C6:1;
} LCDDATA27BITS;
extern volatile LCDDATA27BITS LCDDATA27bits __attribute__((__sfr__));

extern volatile unsigned int  LCDDATA28 __attribute__((__sfr__));
typedef struct tagLCDDATA28BITS {
  unsigned S00C7:1;
  unsigned S01C7:1;
  unsigned S02C7:1;
  unsigned S03C7:1;
  unsigned S04C7:1;
  unsigned S05C7:1;
  unsigned S06C7:1;
  unsigned S07C7:1;
  unsigned S08C7:1;
  unsigned S09C7:1;
  unsigned S10C7:1;
  unsigned S11C7:1;
  unsigned S12C7:1;
  unsigned S13C7:1;
  unsigned S14C7:1;
  unsigned S15C7:1;
} LCDDATA28BITS;
extern volatile LCDDATA28BITS LCDDATA28bits __attribute__((__sfr__));

extern volatile unsigned int  LCDDATA29 __attribute__((__sfr__));
typedef struct tagLCDDATA29BITS {
  unsigned S16C7:1;
  unsigned S17C7:1;
  unsigned S18C7:1;
  unsigned S19C7:1;
  unsigned S20C7:1;
  unsigned S21C7:1;
  unsigned S22C7:1;
  unsigned S23C7:1;
  unsigned S24C7:1;
  unsigned S25C7:1;
  unsigned S26C7:1;
  unsigned S27C7:1;
  unsigned S28C7:1;
  unsigned S29C7:1;
  unsigned S30C7:1;
  unsigned S31C7:1;
} LCDDATA29BITS;
extern volatile LCDDATA29BITS LCDDATA29bits __attribute__((__sfr__));

extern volatile unsigned int  LCDDATA30 __attribute__((__sfr__));
typedef struct tagLCDDATA30BITS {
  unsigned S32C7:1;
  unsigned S33C7:1;
  unsigned S34C7:1;
  unsigned S35C7:1;
  unsigned S36C7:1;
  unsigned S37C7:1;
  unsigned S38C7:1;
  unsigned S39C7:1;
  unsigned S40C7:1;
  unsigned S41C7:1;
  unsigned S42C7:1;
  unsigned S43C7:1;
  unsigned S44C7:1;
  unsigned S45C7:1;
  unsigned S46C7:1;
  unsigned S47C7:1;
} LCDDATA30BITS;
extern volatile LCDDATA30BITS LCDDATA30bits __attribute__((__sfr__));

extern volatile unsigned int  LCDDATA31 __attribute__((__sfr__));
typedef struct tagLCDDATA31BITS {
  unsigned S48C7:1;
  unsigned :1;
  unsigned S50C7:1;
} LCDDATA31BITS;
extern volatile LCDDATA31BITS LCDDATA31bits __attribute__((__sfr__));

extern volatile unsigned int  PMCON1 __attribute__((__sfr__));
__extension__ typedef struct tagPMCON1BITS {
  union {
    struct {
      unsigned IRQM:2;
      unsigned BUSKEEP:1;
      unsigned :1;
      unsigned ALMODE:1;
      unsigned ALP:1;
      unsigned CSF:2;
      unsigned MODE:2;
      unsigned :1;
      unsigned ADRMUX:2;
      unsigned PSIDL:1;
      unsigned :1;
      unsigned PMPEN:1;
    };
    struct {
      unsigned IRQM0:1;
      unsigned IRQM1:1;
      unsigned :4;
      unsigned CSF0:1;
      unsigned CSF1:1;
      unsigned MODE0:1;
      unsigned MODE1:1;
      unsigned :1;
      unsigned ADRMUX0:1;
      unsigned ADRMUX1:1;
    };
  };
} PMCON1BITS;
extern volatile PMCON1BITS PMCON1bits __attribute__((__sfr__));

extern volatile unsigned int  PMCON2 __attribute__((__sfr__));
__extension__ typedef struct tagPMCON2BITS {
  union {
    struct {
      unsigned RADDR:8;
      unsigned :4;
      unsigned TIMEOUT:1;
      unsigned ERROR:1;
      unsigned :1;
      unsigned BUSY:1;
    };
    struct {
      unsigned RADDR16:1;
      unsigned RADDR17:1;
      unsigned RADDR18:1;
      unsigned RADDR19:1;
      unsigned RADDR20:1;
      unsigned RADDR21:1;
      unsigned RADDR22:1;
      unsigned RADDR23:1;
    };
  };
} PMCON2BITS;
extern volatile PMCON2BITS PMCON2bits __attribute__((__sfr__));

extern volatile unsigned int  PMCON3 __attribute__((__sfr__));
__extension__ typedef struct tagPMCON3BITS {
  union {
    struct {
      unsigned PTEN16:1;
      unsigned PTEN17:1;
      unsigned PTEN18:1;
      unsigned PTEN19:1;
      unsigned PTEN20:1;
      unsigned PTEN21:1;
      unsigned PTEN22:1;
      unsigned :1;
      unsigned AWAITE:1;
      unsigned AWAITM:2;
      unsigned :1;
      unsigned PTBE0EN:1;
      unsigned PTBE1EN:1;
      unsigned PTRDEN:1;
      unsigned PTWREN:1;
    };
    struct {
      unsigned :9;
      unsigned AWAITM0:1;
      unsigned AWAITM1:1;
    };
  };
} PMCON3BITS;
extern volatile PMCON3BITS PMCON3bits __attribute__((__sfr__));

extern volatile unsigned int  PMCON4 __attribute__((__sfr__));
typedef struct tagPMCON4BITS {
  unsigned PTEN0:1;
  unsigned PTEN1:1;
  unsigned PTEN2:1;
  unsigned PTEN3:1;
  unsigned PTEN4:1;
  unsigned PTEN5:1;
  unsigned PTEN6:1;
  unsigned PTEN7:1;
  unsigned PTEN8:1;
  unsigned PTEN9:1;
  unsigned PTEN10:1;
  unsigned PTEN11:1;
  unsigned PTEN12:1;
  unsigned PTEN13:1;
  unsigned PTEN14:1;
  unsigned PTEN15:1;
} PMCON4BITS;
extern volatile PMCON4BITS PMCON4bits __attribute__((__sfr__));

extern volatile unsigned int  PMCS1CF __attribute__((__sfr__));
__extension__ typedef struct tagPMCS1CFBITS {
  union {
    struct {
      unsigned :5;
      unsigned PTSZ:2;
      unsigned ACKP:1;
      unsigned SM:1;
      unsigned RDSP:1;
      unsigned WRSP:1;
      unsigned :1;
      unsigned BEP:1;
      unsigned CSPTEN:1;
      unsigned CSP:1;
      unsigned CSDIS:1;
    };
    struct {
      unsigned :5;
      unsigned PTSZ0:1;
      unsigned PTSZ1:1;
    };
  };
} PMCS1CFBITS;
extern volatile PMCS1CFBITS PMCS1CFbits __attribute__((__sfr__));

extern volatile unsigned int  PMCS1BS __attribute__((__sfr__));
typedef struct tagPMCS1BSBITS {
  unsigned :3;
  unsigned BASE11:1;
  unsigned :3;
  unsigned BASE15:1;
  unsigned BASE16:1;
  unsigned BASE17:1;
  unsigned BASE18:1;
  unsigned BASE19:1;
  unsigned BASE20:1;
  unsigned BASE21:1;
  unsigned BASE22:1;
  unsigned BASE23:1;
} PMCS1BSBITS;
extern volatile PMCS1BSBITS PMCS1BSbits __attribute__((__sfr__));

extern volatile unsigned int  PMCS1MD __attribute__((__sfr__));
__extension__ typedef struct tagPMCS1MDBITS {
  union {
    struct {
      unsigned DWAITE:2;
      unsigned DWAITM:4;
      unsigned DWAITB:2;
      unsigned :3;
      unsigned AMWAIT:3;
      unsigned ACKM:2;
    };
    struct {
      unsigned DWAITE0:1;
      unsigned DWAITE1:1;
      unsigned DWAITM0:1;
      unsigned DWAITM1:1;
      unsigned DWAITM2:1;
      unsigned DWAITM3:1;
      unsigned DWAITB0:1;
      unsigned DWAITB1:1;
      unsigned :3;
      unsigned AMWAIT0:1;
      unsigned AMWAIT1:1;
      unsigned AMWAIT2:1;
      unsigned ACKM0:1;
      unsigned ACKM1:1;
    };
  };
} PMCS1MDBITS;
extern volatile PMCS1MDBITS PMCS1MDbits __attribute__((__sfr__));

extern volatile unsigned int  PMCS2CF __attribute__((__sfr__));
__extension__ typedef struct tagPMCS2CFBITS {
  union {
    struct {
      unsigned :5;
      unsigned PTSZ:2;
      unsigned ACKP:1;
      unsigned SM:1;
      unsigned RDSP:1;
      unsigned WRSP:1;
      unsigned :1;
      unsigned BEP:1;
      unsigned CSPTEN:1;
      unsigned CSP:1;
      unsigned CSDIS:1;
    };
    struct {
      unsigned :5;
      unsigned PTSZ0:1;
      unsigned PTSZ1:1;
    };
  };
} PMCS2CFBITS;
extern volatile PMCS2CFBITS PMCS2CFbits __attribute__((__sfr__));

extern volatile unsigned int  PMCS2BS __attribute__((__sfr__));
typedef struct tagPMCS2BSBITS {
  unsigned :3;
  unsigned BASE11:1;
  unsigned :3;
  unsigned BASE15:1;
  unsigned BASE16:1;
  unsigned BASE17:1;
  unsigned BASE18:1;
  unsigned BASE19:1;
  unsigned BASE20:1;
  unsigned BASE21:1;
  unsigned BASE22:1;
  unsigned BASE23:1;
} PMCS2BSBITS;
extern volatile PMCS2BSBITS PMCS2BSbits __attribute__((__sfr__));

extern volatile unsigned int  PMCS2MD __attribute__((__sfr__));
__extension__ typedef struct tagPMCS2MDBITS {
  union {
    struct {
      unsigned DWAITE:2;
      unsigned DWAITM:4;
      unsigned DWAITB:2;
      unsigned :3;
      unsigned AMWAIT:3;
      unsigned ACKM:2;
    };
    struct {
      unsigned DWAITE0:1;
      unsigned DWAITE1:1;
      unsigned DWAITM0:1;
      unsigned DWAITM1:1;
      unsigned DWAITM2:1;
      unsigned DWAITM3:1;
      unsigned DWAITB0:1;
      unsigned DWAITB1:1;
      unsigned :3;
      unsigned AMWAIT0:1;
      unsigned AMWAIT1:1;
      unsigned AMWAIT2:1;
      unsigned ACKM0:1;
      unsigned ACKM1:1;
    };
  };
} PMCS2MDBITS;
extern volatile PMCS2MDBITS PMCS2MDbits __attribute__((__sfr__));

extern volatile unsigned int  PMDOUT1 __attribute__((__sfr__));
extern volatile unsigned int  PMDOUT2 __attribute__((__sfr__));
extern volatile unsigned int  PMDIN1 __attribute__((__sfr__));
extern volatile unsigned int  PMDIN2 __attribute__((__sfr__));
extern volatile unsigned int  PMSTAT __attribute__((__sfr__));
typedef struct tagPMSTATBITS {
  unsigned OB0E:1;
  unsigned OB1E:1;
  unsigned OB2E:1;
  unsigned OB3E:1;
  unsigned :2;
  unsigned OBUF:1;
  unsigned OBE:1;
  unsigned IB0F:1;
  unsigned IB1F:1;
  unsigned IB2F:1;
  unsigned IB3F:1;
  unsigned :2;
  unsigned IBOV:1;
  unsigned IBF:1;
} PMSTATBITS;
extern volatile PMSTATBITS PMSTATbits __attribute__((__sfr__));

extern volatile unsigned int  ALRMVAL __attribute__((__sfr__));
extern volatile unsigned int  ALCFGRPT __attribute__((__sfr__));
__extension__ typedef struct tagALCFGRPTBITS {
  union {
    struct {
      unsigned ARPT:8;
      unsigned ALRMPTR:2;
      unsigned AMASK:4;
      unsigned CHIME:1;
      unsigned ALRMEN:1;
    };
    struct {
      unsigned ARPT0:1;
      unsigned ARPT1:1;
      unsigned ARPT2:1;
      unsigned ARPT3:1;
      unsigned ARPT4:1;
      unsigned ARPT5:1;
      unsigned ARPT6:1;
      unsigned ARPT7:1;
      unsigned ALRMPTR0:1;
      unsigned ALRMPTR1:1;
      unsigned AMASK0:1;
      unsigned AMASK1:1;
      unsigned AMASK2:1;
      unsigned AMASK3:1;
    };
  };
} ALCFGRPTBITS;
extern volatile ALCFGRPTBITS ALCFGRPTbits __attribute__((__sfr__));

extern volatile unsigned int  RTCVAL __attribute__((__sfr__));
extern volatile unsigned int  RCFGCAL __attribute__((__sfr__));
__extension__ typedef struct tagRCFGCALBITS {
  union {
    struct {
      unsigned CAL:8;
      unsigned RTCPTR:2;
      unsigned RTCOE:1;
      unsigned HALFSEC:1;
      unsigned RTCSYNC:1;
      unsigned RTCWREN:1;
      unsigned :1;
      unsigned RTCEN:1;
    };
    struct {
      unsigned CAL0:1;
      unsigned CAL1:1;
      unsigned CAL2:1;
      unsigned CAL3:1;
      unsigned CAL4:1;
      unsigned CAL5:1;
      unsigned CAL6:1;
      unsigned CAL7:1;
      unsigned RTCPTR0:1;
      unsigned RTCPTR1:1;
    };
  };
} RCFGCALBITS;
extern volatile RCFGCALBITS RCFGCALbits __attribute__((__sfr__));

extern volatile unsigned int  RTCPWC __attribute__((__sfr__));
__extension__ typedef struct tagRTCPWCBITS {
  union {
    struct {
      unsigned :8;
      unsigned RTCOUT:2;
      unsigned RTCLK:2;
      unsigned PWSPRE:1;
      unsigned PWCPRE:1;
      unsigned PWCPOL:1;
      unsigned PWCEN:1;
    };
    struct {
      unsigned :8;
      unsigned RTCOUT0:1;
      unsigned RTCOUT1:1;
      unsigned RTCLK0:1;
      unsigned RTCLK1:1;
    };
  };
} RTCPWCBITS;
extern volatile RTCPWCBITS RTCPWCbits __attribute__((__sfr__));

extern volatile unsigned int  MDCON __attribute__((__sfr__));
typedef struct tagMDCONBITS {
  unsigned MDBIT:1;
  unsigned :3;
  unsigned MDOPOL:1;
  unsigned MDSLR:1;
  unsigned MDOE:1;
  unsigned :6;
  unsigned MDSIDL:1;
  unsigned :1;
  unsigned MDEN:1;
} MDCONBITS;
extern volatile MDCONBITS MDCONbits __attribute__((__sfr__));

extern volatile unsigned int  MDSRC __attribute__((__sfr__));
__extension__ typedef struct tagMDSRCBITS {
  union {
    struct {
      unsigned MS:4;
      unsigned :3;
      unsigned SODIS:1;
    };
    struct {
      unsigned MS0:1;
      unsigned MS1:1;
      unsigned MS2:1;
      unsigned MS3:1;
    };
  };
} MDSRCBITS;
extern volatile MDSRCBITS MDSRCbits __attribute__((__sfr__));

extern volatile unsigned int  MDCAR __attribute__((__sfr__));
__extension__ typedef struct tagMDCARBITS {
  union {
    struct {
      unsigned CL:4;
      unsigned :1;
      unsigned CLSYNC:1;
      unsigned CLPOL:1;
      unsigned CLODIS:1;
      unsigned CH:4;
      unsigned :1;
      unsigned CHSYNC:1;
      unsigned CHPOL:1;
      unsigned CHODIS:1;
    };
    struct {
      unsigned CL0:1;
      unsigned CL1:1;
      unsigned CL2:1;
      unsigned CL3:1;
      unsigned :4;
      unsigned CH0:1;
      unsigned CH1:1;
      unsigned CH2:1;
      unsigned CH3:1;
    };
  };
} MDCARBITS;
extern volatile MDCARBITS MDCARbits __attribute__((__sfr__));

extern volatile unsigned int  CMSTAT __attribute__((__sfr__));
typedef struct tagCMSTATBITS {
  unsigned C1OUT:1;
  unsigned C2OUT:1;
  unsigned C3OUT:1;
  unsigned :5;
  unsigned C1EVT:1;
  unsigned C2EVT:1;
  unsigned C3EVT:1;
  unsigned :4;
  unsigned CMIDL:1;
} CMSTATBITS;
extern volatile CMSTATBITS CMSTATbits __attribute__((__sfr__));

extern volatile unsigned int  CVRCON __attribute__((__sfr__));
__extension__ typedef struct tagCVRCONBITS {
  union {
    struct {
      unsigned CVR:4;
      unsigned CVRSS:1;
      unsigned CVRR:1;
      unsigned CVROE:1;
      unsigned CVREN:1;
      unsigned CVREFM:2;
      unsigned CVREFP:1;
    };
    struct {
      unsigned CVR0:1;
      unsigned CVR1:1;
      unsigned CVR2:1;
      unsigned CVR3:1;
      unsigned :4;
      unsigned CVREFM0:1;
      unsigned CVREFM1:1;
    };
  };
} CVRCONBITS;
extern volatile CVRCONBITS CVRCONbits __attribute__((__sfr__));

extern volatile unsigned int  CM1CON __attribute__((__sfr__));
__extension__ typedef struct tagCM1CONBITS {
  union {
    struct {
      unsigned CCH:2;
      unsigned :2;
      unsigned CREF:1;
      unsigned :1;
      unsigned EVPOL:2;
      unsigned COUT:1;
      unsigned CEVT:1;
      unsigned :3;
      unsigned CPOL:1;
      unsigned COE:1;
      unsigned CON:1;
    };
    struct {
      unsigned CCH0:1;
      unsigned CCH1:1;
      unsigned :4;
      unsigned EVPOL0:1;
      unsigned EVPOL1:1;
      unsigned :7;
      unsigned CEN:1;
    };
  };
} CM1CONBITS;
extern volatile CM1CONBITS CM1CONbits __attribute__((__sfr__));

extern volatile unsigned int  CM2CON __attribute__((__sfr__));
__extension__ typedef struct tagCM2CONBITS {
  union {
    struct {
      unsigned CCH:2;
      unsigned :2;
      unsigned CREF:1;
      unsigned :1;
      unsigned EVPOL:2;
      unsigned COUT:1;
      unsigned CEVT:1;
      unsigned :3;
      unsigned CPOL:1;
      unsigned COE:1;
      unsigned CON:1;
    };
    struct {
      unsigned CCH0:1;
      unsigned CCH1:1;
      unsigned :4;
      unsigned EVPOL0:1;
      unsigned EVPOL1:1;
      unsigned :7;
      unsigned CEN:1;
    };
  };
} CM2CONBITS;
extern volatile CM2CONBITS CM2CONbits __attribute__((__sfr__));

extern volatile unsigned int  CM3CON __attribute__((__sfr__));
__extension__ typedef struct tagCM3CONBITS {
  union {
    struct {
      unsigned CCH:2;
      unsigned :2;
      unsigned CREF:1;
      unsigned :1;
      unsigned EVPOL:2;
      unsigned COUT:1;
      unsigned CEVT:1;
      unsigned :3;
      unsigned CPOL:1;
      unsigned COE:1;
      unsigned CON:1;
    };
    struct {
      unsigned CCH0:1;
      unsigned CCH1:1;
      unsigned :4;
      unsigned EVPOL0:1;
      unsigned EVPOL1:1;
      unsigned :7;
      unsigned CEN:1;
    };
  };
} CM3CONBITS;
extern volatile CM3CONBITS CM3CONbits __attribute__((__sfr__));

extern volatile unsigned int  CRCCON1 __attribute__((__sfr__));
__extension__ typedef struct tagCRCCON1BITS {
  union {
    struct {
      unsigned :3;
      unsigned LENDIAN:1;
      unsigned CRCGO:1;
      unsigned CRCISEL:1;
      unsigned CRCMPT:1;
      unsigned CRCFUL:1;
      unsigned VWORD:5;
      unsigned CSIDL:1;
      unsigned :1;
      unsigned CRCEN:1;
    };
    struct {
      unsigned :8;
      unsigned VWORD0:1;
      unsigned VWORD1:1;
      unsigned VWORD2:1;
      unsigned VWORD3:1;
      unsigned VWORD4:1;
    };
  };
} CRCCON1BITS;
extern volatile CRCCON1BITS CRCCON1bits __attribute__((__sfr__));

extern volatile unsigned int  CRCCON2 __attribute__((__sfr__));
__extension__ typedef struct tagCRCCON2BITS {
  union {
    struct {
      unsigned PLEN:5;
      unsigned :3;
      unsigned DWIDTH:5;
    };
    struct {
      unsigned PLEN0:1;
      unsigned PLEN1:1;
      unsigned PLEN2:1;
      unsigned PLEN3:1;
      unsigned PLEN4:1;
      unsigned :3;
      unsigned DWIDTH0:1;
      unsigned DWIDTH1:1;
      unsigned DWIDTH2:1;
      unsigned DWIDTH3:1;
      unsigned DWIDTH4:1;
    };
  };
} CRCCON2BITS;
extern volatile CRCCON2BITS CRCCON2bits __attribute__((__sfr__));

extern volatile unsigned int  CRCXORL __attribute__((__sfr__));
typedef struct tagCRCXORLBITS {
  unsigned :1;
  unsigned X1:1;
  unsigned X2:1;
  unsigned X3:1;
  unsigned X4:1;
  unsigned X5:1;
  unsigned X6:1;
  unsigned X7:1;
  unsigned X8:1;
  unsigned X9:1;
  unsigned X10:1;
  unsigned X11:1;
  unsigned X12:1;
  unsigned X13:1;
  unsigned X14:1;
  unsigned X15:1;
} CRCXORLBITS;
extern volatile CRCXORLBITS CRCXORLbits __attribute__((__sfr__));

extern volatile unsigned int  CRCXORH __attribute__((__sfr__));
typedef struct tagCRCXORHBITS {
  unsigned X16:1;
  unsigned X17:1;
  unsigned X18:1;
  unsigned X19:1;
  unsigned X20:1;
  unsigned X21:1;
  unsigned X22:1;
  unsigned X23:1;
  unsigned X24:1;
  unsigned X25:1;
  unsigned X26:1;
  unsigned X27:1;
  unsigned X28:1;
  unsigned X29:1;
  unsigned X30:1;
  unsigned X31:1;
} CRCXORHBITS;
extern volatile CRCXORHBITS CRCXORHbits __attribute__((__sfr__));

extern volatile unsigned int  CRCDAT __attribute__((__sfr__));
extern volatile unsigned long CRCDAT32 __attribute__((__sfr__));
extern volatile unsigned char CRCDAT8 __attribute__((__sfr__));
extern volatile unsigned int  CRCDATL __attribute__((__sfr__));
extern volatile unsigned int  CRCDATH __attribute__((__sfr__));
extern volatile unsigned int  CRCWDATL __attribute__((__sfr__));
extern volatile unsigned int  CRCWDATH __attribute__((__sfr__));
extern volatile unsigned int  RPINR0 __attribute__((__sfr__));
__extension__ typedef struct tagRPINR0BITS {
  union {
    struct {
      unsigned :8;
      unsigned INT1R:6;
    };
    struct {
      unsigned :8;
      unsigned INT1R0:1;
      unsigned INT1R1:1;
      unsigned INT1R2:1;
      unsigned INT1R3:1;
      unsigned INT1R4:1;
      unsigned INT1R5:1;
    };
  };
} RPINR0BITS;
extern volatile RPINR0BITS RPINR0bits __attribute__((__sfr__));

extern volatile unsigned int  RPINR1 __attribute__((__sfr__));
__extension__ typedef struct tagRPINR1BITS {
  union {
    struct {
      unsigned INT2R:6;
      unsigned :2;
      unsigned INT3R:6;
    };
    struct {
      unsigned INT2R0:1;
      unsigned INT2R1:1;
      unsigned INT2R2:1;
      unsigned INT2R3:1;
      unsigned INT2R4:1;
      unsigned INT2R5:1;
      unsigned :2;
      unsigned INT3R0:1;
      unsigned INT3R1:1;
      unsigned INT3R2:1;
      unsigned INT3R3:1;
      unsigned INT3R4:1;
      unsigned INT3R5:1;
    };
  };
} RPINR1BITS;
extern volatile RPINR1BITS RPINR1bits __attribute__((__sfr__));

extern volatile unsigned int  RPINR2 __attribute__((__sfr__));
__extension__ typedef struct tagRPINR2BITS {
  union {
    struct {
      unsigned INT4R:6;
    };
    struct {
      unsigned INT4R0:1;
      unsigned INT4R1:1;
      unsigned INT4R2:1;
      unsigned INT5R3:1;
      unsigned INT4R4:1;
      unsigned INT4R5:1;
      unsigned :2;
      unsigned OC3R0:1;
      unsigned OC3R1:1;
      unsigned OC3R2:1;
      unsigned OC3R3:1;
      unsigned OC3R4:1;
      unsigned OC3R5:1;
    };
  };
} RPINR2BITS;
extern volatile RPINR2BITS RPINR2bits __attribute__((__sfr__));

extern volatile unsigned int  RPINR3 __attribute__((__sfr__));
__extension__ typedef struct tagRPINR3BITS {
  union {
    struct {
      unsigned T2CKR:6;
      unsigned :2;
      unsigned T3CKR:6;
    };
    struct {
      unsigned T2CKR0:1;
      unsigned T2CKR1:1;
      unsigned T2CKR2:1;
      unsigned T2CKR3:1;
      unsigned T2CKR4:1;
      unsigned T2CKR5:1;
      unsigned :2;
      unsigned T3CKR0:1;
      unsigned T3CKR1:1;
      unsigned T3CKR2:1;
      unsigned T3CKR3:1;
      unsigned T3CKR4:1;
      unsigned T3CKR5:1;
    };
  };
} RPINR3BITS;
extern volatile RPINR3BITS RPINR3bits __attribute__((__sfr__));

extern volatile unsigned int  RPINR4 __attribute__((__sfr__));
__extension__ typedef struct tagRPINR4BITS {
  union {
    struct {
      unsigned T4CKR:6;
      unsigned :2;
      unsigned T5CKR:6;
    };
    struct {
      unsigned T4CKR0:1;
      unsigned T4CKR1:1;
      unsigned T4CKR2:1;
      unsigned T4CKR3:1;
      unsigned T4CKR4:1;
      unsigned T4CKR5:1;
      unsigned :2;
      unsigned T5CKR0:1;
      unsigned T5CKR1:1;
      unsigned T5CKR2:1;
      unsigned T5CKR3:1;
      unsigned T5CKR4:1;
      unsigned T5CKR5:1;
    };
  };
} RPINR4BITS;
extern volatile RPINR4BITS RPINR4bits __attribute__((__sfr__));

extern volatile unsigned int  RPINR7 __attribute__((__sfr__));
__extension__ typedef struct tagRPINR7BITS {
  union {
    struct {
      unsigned IC1R:6;
      unsigned :2;
      unsigned IC2R:6;
    };
    struct {
      unsigned IC1R0:1;
      unsigned IC1R1:1;
      unsigned IC1R2:1;
      unsigned IC1R3:1;
      unsigned IC1R4:1;
      unsigned IC1R5:1;
      unsigned :2;
      unsigned IC2R0:1;
      unsigned IC2R1:1;
      unsigned IC2R2:1;
      unsigned IC2R3:1;
      unsigned IC2R4:1;
      unsigned IC2R5:1;
    };
  };
} RPINR7BITS;
extern volatile RPINR7BITS RPINR7bits __attribute__((__sfr__));

extern volatile unsigned int  RPINR8 __attribute__((__sfr__));
__extension__ typedef struct tagRPINR8BITS {
  union {
    struct {
      unsigned IC3R:6;
      unsigned :2;
      unsigned IC4R:6;
    };
    struct {
      unsigned IC3R0:1;
      unsigned IC3R1:1;
      unsigned IC3R2:1;
      unsigned IC3R3:1;
      unsigned IC3R4:1;
      unsigned IC3R5:1;
      unsigned :2;
      unsigned IC4R0:1;
      unsigned IC4R1:1;
      unsigned IC4R2:1;
      unsigned IC4R3:1;
      unsigned IC4R4:1;
      unsigned IC4R5:1;
    };
  };
} RPINR8BITS;
extern volatile RPINR8BITS RPINR8bits __attribute__((__sfr__));

extern volatile unsigned int  RPINR9 __attribute__((__sfr__));
__extension__ typedef struct tagRPINR9BITS {
  union {
    struct {
      unsigned IC5R:6;
      unsigned :2;
      unsigned IC6R:6;
    };
    struct {
      unsigned IC5R0:1;
      unsigned IC5R1:1;
      unsigned IC5R2:1;
      unsigned IC5R3:1;
      unsigned IC5R4:1;
      unsigned IC5R5:1;
      unsigned :2;
      unsigned IC6R0:1;
      unsigned IC6R1:1;
      unsigned IC6R2:1;
      unsigned IC6R3:1;
      unsigned IC6R4:1;
      unsigned IC6R5:1;
    };
  };
} RPINR9BITS;
extern volatile RPINR9BITS RPINR9bits __attribute__((__sfr__));

extern volatile unsigned int  RPINR10 __attribute__((__sfr__));
__extension__ typedef struct tagRPINR10BITS {
  union {
    struct {
      unsigned IC7R:6;
    };
    struct {
      unsigned IC7R0:1;
      unsigned IC7R1:1;
      unsigned IC7R2:1;
      unsigned IC7R3:1;
      unsigned IC7R4:1;
      unsigned IC7R5:1;
      unsigned :2;
      unsigned IC8R0:1;
      unsigned IC8R1:1;
      unsigned IC8R2:1;
      unsigned IC8R3:1;
      unsigned IC8R4:1;
      unsigned IC8R5:1;
    };
  };
} RPINR10BITS;
extern volatile RPINR10BITS RPINR10bits __attribute__((__sfr__));

extern volatile unsigned int  RPINR11 __attribute__((__sfr__));
__extension__ typedef struct tagRPINR11BITS {
  union {
    struct {
      unsigned OCFAR:6;
      unsigned :2;
      unsigned OCFBR:6;
    };
    struct {
      unsigned OCFAR0:1;
      unsigned OCFAR1:1;
      unsigned OCFAR2:1;
      unsigned OCFAR3:1;
      unsigned OCFAR4:1;
      unsigned OCFAR5:1;
      unsigned :2;
      unsigned OCFBR0:1;
      unsigned OCFBR1:1;
      unsigned OCFBR2:1;
      unsigned OCFBR3:1;
      unsigned OCFBR4:1;
      unsigned OCFBR5:1;
    };
  };
} RPINR11BITS;
extern volatile RPINR11BITS RPINR11bits __attribute__((__sfr__));

extern volatile unsigned int  RPINR17 __attribute__((__sfr__));
__extension__ typedef struct tagRPINR17BITS {
  union {
    struct {
      unsigned :8;
      unsigned U3RXR:6;
    };
    struct {
      unsigned :8;
      unsigned U3RXR0:1;
      unsigned U3RXR1:1;
      unsigned U3RXR2:1;
      unsigned U3RXR3:1;
      unsigned U3RXR4:1;
      unsigned U3RXR5:1;
    };
  };
} RPINR17BITS;
extern volatile RPINR17BITS RPINR17bits __attribute__((__sfr__));

extern volatile unsigned int  RPINR18 __attribute__((__sfr__));
__extension__ typedef struct tagRPINR18BITS {
  union {
    struct {
      unsigned U1RXR:6;
      unsigned :2;
      unsigned U1CTSR:6;
    };
    struct {
      unsigned U1RXR0:1;
      unsigned U1RXR1:1;
      unsigned U1RXR2:1;
      unsigned U1RXR3:1;
      unsigned U1RXR4:1;
      unsigned U1RXR5:1;
      unsigned :2;
      unsigned U1CTSR0:1;
      unsigned U1CTSR1:1;
      unsigned U1CTSR2:1;
      unsigned U1CTSR3:1;
      unsigned U1CTSR4:1;
      unsigned U1CTSR5:1;
    };
  };
} RPINR18BITS;
extern volatile RPINR18BITS RPINR18bits __attribute__((__sfr__));

extern volatile unsigned int  RPINR19 __attribute__((__sfr__));
__extension__ typedef struct tagRPINR19BITS {
  union {
    struct {
      unsigned U2RXR:6;
      unsigned :2;
      unsigned U2CTSR:6;
    };
    struct {
      unsigned U2RXR0:1;
      unsigned U2RXR1:1;
      unsigned U2RXR2:1;
      unsigned U2RXR3:1;
      unsigned U2RXR4:1;
      unsigned U2RXR5:1;
      unsigned :2;
      unsigned U2CTSR0:1;
      unsigned U2CTSR1:1;
      unsigned U2CTSR2:1;
      unsigned U2CTSR3:1;
      unsigned U2CTSR4:1;
      unsigned U2CTSR5:1;
    };
  };
} RPINR19BITS;
extern volatile RPINR19BITS RPINR19bits __attribute__((__sfr__));

extern volatile unsigned int  RPINR20 __attribute__((__sfr__));
__extension__ typedef struct tagRPINR20BITS {
  union {
    struct {
      unsigned SDI1R:6;
      unsigned :2;
      unsigned SCK1R:6;
    };
    struct {
      unsigned SDI1R0:1;
      unsigned SDI1R1:1;
      unsigned SDI1R2:1;
      unsigned SDI1R3:1;
      unsigned SDI1R4:1;
      unsigned SDI1R5:1;
      unsigned :2;
      unsigned SCK1R0:1;
      unsigned SCK1R1:1;
      unsigned SCK1R2:1;
      unsigned SCK1R3:1;
      unsigned SCK1R4:1;
      unsigned SCK1R5:1;
    };
  };
} RPINR20BITS;
extern volatile RPINR20BITS RPINR20bits __attribute__((__sfr__));

extern volatile unsigned int  RPINR21 __attribute__((__sfr__));
__extension__ typedef struct tagRPINR21BITS {
  union {
    struct {
      unsigned SS1R:6;
      unsigned :2;
      unsigned U3CTSR:6;
    };
    struct {
      unsigned SS1R0:1;
      unsigned SS1R1:1;
      unsigned SS1R2:1;
      unsigned SS1R3:1;
      unsigned SS1R4:1;
      unsigned SS1R5:1;
      unsigned :2;
      unsigned U3CTSR0:1;
      unsigned U3CTSR1:1;
      unsigned U3CTSR2:1;
      unsigned U3CTSR3:1;
      unsigned U3CTSR4:1;
      unsigned U3CTSR5:1;
    };
  };
} RPINR21BITS;
extern volatile RPINR21BITS RPINR21bits __attribute__((__sfr__));

extern volatile unsigned int  RPINR22 __attribute__((__sfr__));
__extension__ typedef struct tagRPINR22BITS {
  union {
    struct {
      unsigned SDI2R:6;
      unsigned :2;
      unsigned SCK2R:6;
    };
    struct {
      unsigned SDI2R0:1;
      unsigned SDI2R1:1;
      unsigned SDI2R2:1;
      unsigned SDI2R3:1;
      unsigned SDI2R4:1;
      unsigned SDI2R5:1;
      unsigned :2;
      unsigned SCK2R0:1;
      unsigned SCK2R1:1;
      unsigned SCK2R2:1;
      unsigned SCK2R3:1;
      unsigned SCK2R4:1;
      unsigned SCK2R5:1;
    };
  };
} RPINR22BITS;
extern volatile RPINR22BITS RPINR22bits __attribute__((__sfr__));

extern volatile unsigned int  RPINR23 __attribute__((__sfr__));
__extension__ typedef struct tagRPINR23BITS {
  union {
    struct {
      unsigned SS2R:6;
      unsigned :2;
      unsigned T1CKR:6;
    };
    struct {
      unsigned SS2R0:1;
      unsigned SS2R1:1;
      unsigned SS2R2:1;
      unsigned SS2R3:1;
      unsigned SS2R4:1;
      unsigned SS2R5:1;
      unsigned :2;
      unsigned T1CKR0:1;
      unsigned T1CKR1:1;
      unsigned T1CKR2:1;
      unsigned T1CKR3:1;
      unsigned T1CKR4:1;
      unsigned T1CKR5:1;
    };
  };
} RPINR23BITS;
extern volatile RPINR23BITS RPINR23bits __attribute__((__sfr__));

extern volatile unsigned int  RPINR27 __attribute__((__sfr__));
__extension__ typedef struct tagRPINR27BITS {
  union {
    struct {
      unsigned U4RXR:6;
      unsigned :2;
      unsigned U4CTSR:6;
    };
    struct {
      unsigned U4RXR0:1;
      unsigned U4RXR1:1;
      unsigned U4RXR2:1;
      unsigned U4RXR3:1;
      unsigned U4RXR4:1;
      unsigned U4RXR5:1;
      unsigned :2;
      unsigned U4CTSR0:1;
      unsigned U4CTSR1:1;
      unsigned U4CTSR2:1;
      unsigned U4CTSR3:1;
      unsigned U4CTSR4:1;
      unsigned U4CTSR5:1;
    };
  };
} RPINR27BITS;
extern volatile RPINR27BITS RPINR27bits __attribute__((__sfr__));

extern volatile unsigned int  RPINR30 __attribute__((__sfr__));
__extension__ typedef struct tagRPINR30BITS {
  union {
    struct {
      unsigned MDMIR:6;
    };
    struct {
      unsigned MDMIR0:1;
      unsigned MDMIR1:1;
      unsigned MDMIR2:1;
      unsigned MDMIR3:1;
      unsigned MDMIR4:1;
      unsigned MDMIR5:1;
    };
  };
} RPINR30BITS;
extern volatile RPINR30BITS RPINR30bits __attribute__((__sfr__));

extern volatile unsigned int  RPINR31 __attribute__((__sfr__));
__extension__ typedef struct tagRPINR31BITS {
  union {
    struct {
      unsigned MDC1R:6;
      unsigned :2;
      unsigned MDC2R:6;
    };
    struct {
      unsigned MDC1R0:1;
      unsigned MDC1R1:1;
      unsigned MDC1R2:1;
      unsigned MDC1R3:1;
      unsigned MDC1R4:1;
      unsigned MDC1R5:1;
      unsigned :2;
      unsigned MDC2R0:1;
      unsigned MDC2R1:1;
      unsigned MDC2R2:1;
      unsigned MDC2R3:1;
      unsigned MDC2R4:1;
      unsigned MDC2R5:1;
    };
  };
} RPINR31BITS;
extern volatile RPINR31BITS RPINR31bits __attribute__((__sfr__));

extern volatile unsigned int  RPOR0 __attribute__((__sfr__));
__extension__ typedef struct tagRPOR0BITS {
  union {
    struct {
      unsigned RP0R:6;
      unsigned :2;
      unsigned RP1R:6;
    };
    struct {
      unsigned RP0R0:1;
      unsigned RP0R1:1;
      unsigned RP0R2:1;
      unsigned RP0R3:1;
      unsigned RP0R4:1;
      unsigned RP0R5:1;
      unsigned :2;
      unsigned RP1R0:1;
      unsigned RP1R1:1;
      unsigned RP1R2:1;
      unsigned RP1R3:1;
      unsigned RP1R4:1;
      unsigned RP1R5:1;
    };
  };
} RPOR0BITS;
extern volatile RPOR0BITS RPOR0bits __attribute__((__sfr__));

extern volatile unsigned int  RPOR1 __attribute__((__sfr__));
__extension__ typedef struct tagRPOR1BITS {
  union {
    struct {
      unsigned RP2R:6;
      unsigned :2;
      unsigned RP3R:6;
    };
    struct {
      unsigned RP2R0:1;
      unsigned RP2R1:1;
      unsigned RP2R2:1;
      unsigned RP2R3:1;
      unsigned RP2R4:1;
      unsigned RP2R5:1;
      unsigned :2;
      unsigned RP3R0:1;
      unsigned RP3R1:1;
      unsigned RP3R2:1;
      unsigned RP3R3:1;
      unsigned RP3R4:1;
      unsigned RP3R5:1;
    };
  };
} RPOR1BITS;
extern volatile RPOR1BITS RPOR1bits __attribute__((__sfr__));

extern volatile unsigned int  RPOR2 __attribute__((__sfr__));
__extension__ typedef struct tagRPOR2BITS {
  union {
    struct {
      unsigned RP4R:6;
      unsigned :2;
      unsigned RP5R:6;
    };
    struct {
      unsigned RP4R0:1;
      unsigned RP4R1:1;
      unsigned RP4R2:1;
      unsigned RP4R3:1;
      unsigned RP4R4:1;
      unsigned RP4R5:1;
      unsigned :2;
      unsigned RP5R0:1;
      unsigned RP5R1:1;
      unsigned RP5R2:1;
      unsigned RP5R3:1;
      unsigned RP5R4:1;
      unsigned RP5R5:1;
    };
  };
} RPOR2BITS;
extern volatile RPOR2BITS RPOR2bits __attribute__((__sfr__));

extern volatile unsigned int  RPOR3 __attribute__((__sfr__));
__extension__ typedef struct tagRPOR3BITS {
  union {
    struct {
      unsigned RP6R:6;
      unsigned :2;
      unsigned RP7R:6;
    };
    struct {
      unsigned RP6R0:1;
      unsigned RP6R1:1;
      unsigned RP6R2:1;
      unsigned RP6R3:1;
      unsigned RP6R4:1;
      unsigned RP6R5:1;
      unsigned :2;
      unsigned RP7R0:1;
      unsigned RP7R1:1;
      unsigned RP7R2:1;
      unsigned RP7R3:1;
      unsigned RP7R4:1;
      unsigned RP7R5:1;
    };
  };
} RPOR3BITS;
extern volatile RPOR3BITS RPOR3bits __attribute__((__sfr__));

extern volatile unsigned int  RPOR4 __attribute__((__sfr__));
__extension__ typedef struct tagRPOR4BITS {
  union {
    struct {
      unsigned RP8R:6;
      unsigned :2;
      unsigned RP9R:6;
    };
    struct {
      unsigned RP8R0:1;
      unsigned RP8R1:1;
      unsigned RP8R2:1;
      unsigned RP8R3:1;
      unsigned RP8R4:1;
      unsigned RP8R5:1;
      unsigned :2;
      unsigned RP9R0:1;
      unsigned RP9R1:1;
      unsigned RP9R2:1;
      unsigned RP9R3:1;
      unsigned RP9R4:1;
      unsigned RP9R5:1;
    };
  };
} RPOR4BITS;
extern volatile RPOR4BITS RPOR4bits __attribute__((__sfr__));

extern volatile unsigned int  RPOR5 __attribute__((__sfr__));
__extension__ typedef struct tagRPOR5BITS {
  union {
    struct {
      unsigned RP10R:6;
      unsigned :2;
      unsigned RP11R:6;
    };
    struct {
      unsigned RP10R0:1;
      unsigned RP10R1:1;
      unsigned RP10R2:1;
      unsigned RP10R3:1;
      unsigned RP10R4:1;
      unsigned RP10R5:1;
      unsigned :2;
      unsigned RP11R0:1;
      unsigned RP11R1:1;
      unsigned RP11R2:1;
      unsigned RP11R3:1;
      unsigned RP11R4:1;
      unsigned RP11R5:1;
    };
  };
} RPOR5BITS;
extern volatile RPOR5BITS RPOR5bits __attribute__((__sfr__));

extern volatile unsigned int  RPOR6 __attribute__((__sfr__));
__extension__ typedef struct tagRPOR6BITS {
  union {
    struct {
      unsigned RP12R:6;
      unsigned :2;
      unsigned RP13R:6;
    };
    struct {
      unsigned RP12R0:1;
      unsigned RP12R1:1;
      unsigned RP12R2:1;
      unsigned RP12R3:1;
      unsigned RP12R4:1;
      unsigned RP12R5:1;
      unsigned :2;
      unsigned RP13R0:1;
      unsigned RP13R1:1;
      unsigned RP13R2:1;
      unsigned RP13R3:1;
      unsigned RP13R4:1;
      unsigned RP13R5:1;
    };
  };
} RPOR6BITS;
extern volatile RPOR6BITS RPOR6bits __attribute__((__sfr__));

extern volatile unsigned int  RPOR7 __attribute__((__sfr__));
__extension__ typedef struct tagRPOR7BITS {
  union {
    struct {
      unsigned RP14R:6;
      unsigned :2;
      unsigned RP15R:6;
    };
    struct {
      unsigned RP14R0:1;
      unsigned RP14R1:1;
      unsigned RP14R2:1;
      unsigned RP14R3:1;
      unsigned RP14R4:1;
      unsigned RP14R5:1;
      unsigned :2;
      unsigned RP15R0:1;
      unsigned RP15R1:1;
      unsigned RP15R2:1;
      unsigned RP15R3:1;
      unsigned RP15R4:1;
      unsigned RP15R5:1;
    };
  };
} RPOR7BITS;
extern volatile RPOR7BITS RPOR7bits __attribute__((__sfr__));

extern volatile unsigned int  RPOR8 __attribute__((__sfr__));
__extension__ typedef struct tagRPOR8BITS {
  union {
    struct {
      unsigned RP16R:6;
      unsigned :2;
      unsigned RP17R:6;
    };
    struct {
      unsigned RP16R0:1;
      unsigned RP16R1:1;
      unsigned RP16R2:1;
      unsigned RP16R3:1;
      unsigned RP16R4:1;
      unsigned RP16R5:1;
      unsigned :2;
      unsigned RP17R0:1;
      unsigned RP17R1:1;
      unsigned RP17R2:1;
      unsigned RP17R3:1;
      unsigned RP17R4:1;
      unsigned RP17R5:1;
    };
  };
} RPOR8BITS;
extern volatile RPOR8BITS RPOR8bits __attribute__((__sfr__));

extern volatile unsigned int  RPOR9 __attribute__((__sfr__));
__extension__ typedef struct tagRPOR9BITS {
  union {
    struct {
      unsigned RP18R:6;
      unsigned :2;
      unsigned RP19R:6;
    };
    struct {
      unsigned RP18R0:1;
      unsigned RP18R1:1;
      unsigned RP18R2:1;
      unsigned RP18R3:1;
      unsigned RP18R4:1;
      unsigned RP18R5:1;
      unsigned :2;
      unsigned RP19R0:1;
      unsigned RP19R1:1;
      unsigned RP19R2:1;
      unsigned RP19R3:1;
      unsigned RP19R4:1;
      unsigned RP19R5:1;
    };
  };
} RPOR9BITS;
extern volatile RPOR9BITS RPOR9bits __attribute__((__sfr__));

extern volatile unsigned int  RPOR10 __attribute__((__sfr__));
__extension__ typedef struct tagRPOR10BITS {
  union {
    struct {
      unsigned RP20R:6;
      unsigned :2;
      unsigned RP21R:6;
    };
    struct {
      unsigned RP20R0:1;
      unsigned RP20R1:1;
      unsigned RP20R2:1;
      unsigned RP20R3:1;
      unsigned RP20R4:1;
      unsigned RP20R5:1;
      unsigned :2;
      unsigned RP21R0:1;
      unsigned RP21R1:1;
      unsigned RP21R2:1;
      unsigned RP21R3:1;
      unsigned RP21R4:1;
      unsigned RP21R5:1;
    };
  };
} RPOR10BITS;
extern volatile RPOR10BITS RPOR10bits __attribute__((__sfr__));

extern volatile unsigned int  RPOR11 __attribute__((__sfr__));
__extension__ typedef struct tagRPOR11BITS {
  union {
    struct {
      unsigned RP22R:6;
      unsigned :2;
      unsigned RP23R:6;
    };
    struct {
      unsigned RP22R0:1;
      unsigned RP22R1:1;
      unsigned RP22R2:1;
      unsigned RP22R3:1;
      unsigned RP22R4:1;
      unsigned RP22R5:1;
      unsigned :2;
      unsigned RP23R0:1;
      unsigned RP23R1:1;
      unsigned RP23R2:1;
      unsigned RP23R3:1;
      unsigned RP23R4:1;
      unsigned RP23R5:1;
    };
  };
} RPOR11BITS;
extern volatile RPOR11BITS RPOR11bits __attribute__((__sfr__));

extern volatile unsigned int  RPOR12 __attribute__((__sfr__));
__extension__ typedef struct tagRPOR12BITS {
  union {
    struct {
      unsigned RP24R:6;
      unsigned :2;
      unsigned RP25R:6;
    };
    struct {
      unsigned RP24R0:1;
      unsigned RP24R1:1;
      unsigned RP24R2:1;
      unsigned RP24R3:1;
      unsigned RP24R4:1;
      unsigned RP24R5:1;
      unsigned :2;
      unsigned RP25R0:1;
      unsigned RP25R1:1;
      unsigned RP25R2:1;
      unsigned RP25R3:1;
      unsigned RP25R4:1;
      unsigned RP25R5:1;
    };
  };
} RPOR12BITS;
extern volatile RPOR12BITS RPOR12bits __attribute__((__sfr__));

extern volatile unsigned int  RPOR13 __attribute__((__sfr__));
__extension__ typedef struct tagRPOR13BITS {
  union {
    struct {
      unsigned RP26R:6;
      unsigned :2;
      unsigned RP27R:6;
    };
    struct {
      unsigned RP26R0:1;
      unsigned RP26R1:1;
      unsigned RP26R2:1;
      unsigned RP26R3:1;
      unsigned RP26R4:1;
      unsigned RP26R5:1;
      unsigned :2;
      unsigned RP27R0:1;
      unsigned RP27R1:1;
      unsigned RP27R2:1;
      unsigned RP27R3:1;
      unsigned RP27R4:1;
      unsigned RP27R5:1;
    };
  };
} RPOR13BITS;
extern volatile RPOR13BITS RPOR13bits __attribute__((__sfr__));

extern volatile unsigned int  RPOR14 __attribute__((__sfr__));
__extension__ typedef struct tagRPOR14BITS {
  union {
    struct {
      unsigned RP28R:6;
      unsigned :2;
      unsigned RP29R:6;
    };
    struct {
      unsigned RP28R0:1;
      unsigned RP28R1:1;
      unsigned RP28R2:1;
      unsigned RP28R3:1;
      unsigned RP28R4:1;
      unsigned RP28R5:1;
      unsigned :2;
      unsigned RP29R0:1;
      unsigned RP29R1:1;
      unsigned RP29R2:1;
      unsigned RP29R3:1;
      unsigned RP29R4:1;
      unsigned RP29R5:1;
    };
  };
} RPOR14BITS;
extern volatile RPOR14BITS RPOR14bits __attribute__((__sfr__));

extern volatile unsigned int  RPOR15 __attribute__((__sfr__));
__extension__ typedef struct tagRPOR15BITS {
  union {
    struct {
      unsigned RP30R:6;
    };
    struct {
      unsigned RP30R0:1;
      unsigned RP30R1:1;
      unsigned RP30R2:1;
      unsigned RP30R3:1;
      unsigned RP30R4:1;
      unsigned RP30R5:1;
    };
  };
} RPOR15BITS;
extern volatile RPOR15BITS RPOR15bits __attribute__((__sfr__));

extern volatile unsigned int  RCON __attribute__((__sfr__));
typedef struct tagRCONBITS {
  unsigned POR:1;
  unsigned BOR:1;
  unsigned IDLE:1;
  unsigned SLEEP:1;
  unsigned WDTO:1;
  unsigned SWDTEN:1;
  unsigned SWR:1;
  unsigned EXTR:1;
  unsigned VREGS:1;
  unsigned CM:1;
  unsigned DPSLP:1;
  unsigned :1;
  unsigned RETEN:1;
  unsigned :1;
  unsigned IOPUWR:1;
  unsigned TRAPR:1;
} RCONBITS;
extern volatile RCONBITS RCONbits __attribute__((__sfr__));

extern volatile unsigned int  OSCCON __attribute__((__sfr__));
__extension__ typedef struct tagOSCCONBITS {
  union {
    struct {
      unsigned OSWEN:1;
      unsigned SOSCEN:1;
      unsigned POSCEN:1;
      unsigned CF:1;
      unsigned :1;
      unsigned LOCK:1;
      unsigned IOLOCK:1;
      unsigned CLKLOCK:1;
      unsigned NOSC:3;
      unsigned :1;
      unsigned COSC:3;
    };
    struct {
      unsigned :8;
      unsigned NOSC0:1;
      unsigned NOSC1:1;
      unsigned NOSC2:1;
      unsigned :1;
      unsigned COSC0:1;
      unsigned COSC1:1;
      unsigned COSC2:1;
    };
  };
} OSCCONBITS;
extern volatile OSCCONBITS OSCCONbits __attribute__((__sfr__));

extern volatile unsigned char OSCCONL __attribute__((__sfr__));
extern volatile unsigned char OSCCONH __attribute__((__sfr__));
extern volatile unsigned int  CLKDIV __attribute__((__sfr__));
__extension__ typedef struct tagCLKDIVBITS {
  union {
    struct {
      unsigned :8;
      unsigned RCDIV:3;
      unsigned DOZEN:1;
      unsigned DOZE:3;
      unsigned ROI:1;
    };
    struct {
      unsigned :8;
      unsigned RCDIV0:1;
      unsigned RCDIV1:1;
      unsigned RCDIV2:1;
      unsigned :1;
      unsigned DOZE0:1;
      unsigned DOZE1:1;
      unsigned DOZE2:1;
    };
  };
} CLKDIVBITS;
extern volatile CLKDIVBITS CLKDIVbits __attribute__((__sfr__));

extern volatile unsigned int  OSCTUN __attribute__((__sfr__));
__extension__ typedef struct tagOSCTUNBITS {
  union {
    struct {
      unsigned TUN:6;
    };
    struct {
      unsigned TUN0:1;
      unsigned TUN1:1;
      unsigned TUN2:1;
      unsigned TUN3:1;
      unsigned TUN4:1;
      unsigned TUN5:1;
    };
  };
} OSCTUNBITS;
extern volatile OSCTUNBITS OSCTUNbits __attribute__((__sfr__));

extern volatile unsigned int  REFOCON __attribute__((__sfr__));
__extension__ typedef struct tagREFOCONBITS {
  union {
    struct {
      unsigned :8;
      unsigned RODIV:4;
      unsigned ROSEL:1;
      unsigned ROSSLP:1;
      unsigned :1;
      unsigned ROEN:1;
    };
    struct {
      unsigned :8;
      unsigned RODIV0:1;
      unsigned RODIV1:1;
      unsigned RODIV2:1;
      unsigned RODIV3:1;
      unsigned :3;
      unsigned ROON:1;
    };
  };
} REFOCONBITS;
extern volatile REFOCONBITS REFOCONbits __attribute__((__sfr__));

extern volatile unsigned int  HLVDCON __attribute__((__sfr__));
__extension__ typedef struct tagHLVDCONBITS {
  union {
    struct {
      unsigned HLVDL:4;
      unsigned :1;
      unsigned IRVST:1;
      unsigned BGVST:1;
      unsigned VDIR:1;
      unsigned :5;
      unsigned LSIDL:1;
      unsigned :1;
      unsigned HLVDEN:1;
    };
    struct {
      unsigned HLVDL0:1;
      unsigned HLVDL1:1;
      unsigned HLVDL2:1;
      unsigned HLVDL3:1;
    };
  };
} HLVDCONBITS;
extern volatile HLVDCONBITS HLVDCONbits __attribute__((__sfr__));

extern volatile unsigned int  DSCON __attribute__((__sfr__));
typedef struct tagDSCONBITS {
  unsigned RELEASE:1;
  unsigned DSBOR:1;
  unsigned :13;
  unsigned DSEN:1;
} DSCONBITS;
extern volatile DSCONBITS DSCONbits __attribute__((__sfr__));

extern volatile unsigned int  DSWAKE __attribute__((__sfr__));
typedef struct tagDSWAKEBITS {
  unsigned :2;
  unsigned DSMCLR:1;
  unsigned DSRTCC:1;
  unsigned DSWDT:1;
  unsigned :2;
  unsigned DSFLT:1;
  unsigned DSINT0:1;
} DSWAKEBITS;
extern volatile DSWAKEBITS DSWAKEbits __attribute__((__sfr__));

extern volatile unsigned int  DSGPR0 __attribute__((__sfr__));
extern volatile unsigned int  DSGPR1 __attribute__((__sfr__));
extern volatile unsigned int  NVMCON __attribute__((__sfr__));
__extension__ typedef struct tagNVMCONBITS {
  union {
    struct {
      unsigned NVMOP:4;
      unsigned :2;
      unsigned ERASE:1;
      unsigned :6;
      unsigned WRERR:1;
      unsigned WREN:1;
      unsigned WR:1;
    };
    struct {
      unsigned NVMOP0:1;
      unsigned NVMOP1:1;
      unsigned NVMOP2:1;
      unsigned NVMOP3:1;
    };
    struct {
      unsigned PROGOP0:1;
      unsigned PROGOP1:1;
      unsigned PROGOP2:1;
      unsigned PROGOP3:1;
    };
    struct {
      unsigned PROGOP:4;
    };
  };
} NVMCONBITS;
extern volatile NVMCONBITS NVMCONbits __attribute__((__sfr__));

extern volatile unsigned int  RCON2 __attribute__((__sfr__));
typedef struct tagRCON2BITS {
  unsigned VBAT:1;
  unsigned VBPOR:1;
  unsigned VDDPOR:1;
  unsigned VDDBOR:1;
} RCON2BITS;
extern volatile RCON2BITS RCON2bits __attribute__((__sfr__));

extern volatile unsigned int  NVMKEY __attribute__((__sfr__));
extern volatile unsigned int  PMD1 __attribute__((__sfr__));
typedef struct tagPMD1BITS {
  unsigned ADC1MD:1;
  unsigned :2;
  unsigned SPI1MD:1;
  unsigned SPI2MD:1;
  unsigned U1MD:1;
  unsigned U2MD:1;
  unsigned I2C1MD:1;
  unsigned :3;
  unsigned T1MD:1;
  unsigned T2MD:1;
  unsigned T3MD:1;
  unsigned T4MD:1;
  unsigned T5MD:1;
} PMD1BITS;
extern volatile PMD1BITS PMD1bits __attribute__((__sfr__));

extern volatile unsigned int  PMD2 __attribute__((__sfr__));
typedef struct tagPMD2BITS {
  unsigned OC1MD:1;
  unsigned OC2MD:1;
  unsigned OC3MD:1;
  unsigned OC4MD:1;
  unsigned OC5MD:1;
  unsigned OC6MD:1;
  unsigned OC7MD:1;
  unsigned :1;
  unsigned IC1MD:1;
  unsigned IC2MD:1;
  unsigned IC3MD:1;
  unsigned IC4MD:1;
  unsigned IC5MD:1;
  unsigned IC6MD:1;
  unsigned IC7MD:1;
} PMD2BITS;
extern volatile PMD2BITS PMD2bits __attribute__((__sfr__));

extern volatile unsigned int  PMD3 __attribute__((__sfr__));
__extension__ typedef struct tagPMD3BITS {
  union {
    struct {
      unsigned :1;
      unsigned I2C2MD:1;
      unsigned :1;
      unsigned U3MD:1;
      unsigned :3;
      unsigned CRCMD:1;
      unsigned PMPMD:1;
      unsigned RTCCMD:1;
      unsigned CMPMD:1;
      unsigned TXMMD:1;
    };
    struct {
      unsigned :7;
      unsigned CRCPMD:1;
      unsigned :3;
      unsigned DSMMD:1;
    };
  };
} PMD3BITS;
extern volatile PMD3BITS PMD3bits __attribute__((__sfr__));

extern volatile unsigned int  PMD4 __attribute__((__sfr__));
typedef struct tagPMD4BITS {
  unsigned :1;
  unsigned LVDMD:1;
  unsigned CTMUMD:1;
  unsigned REFOMD:1;
  unsigned :1;
  unsigned U4MD:1;
  unsigned UPWMMD:1;
} PMD4BITS;
extern volatile PMD4BITS PMD4bits __attribute__((__sfr__));

extern volatile unsigned int  PMD6 __attribute__((__sfr__));
typedef struct tagPMD6BITS {
  unsigned SPI3MD:1;
  unsigned :5;
  unsigned LCDMD:1;
} PMD6BITS;
extern volatile PMD6BITS PMD6bits __attribute__((__sfr__));

extern volatile unsigned int  PMD7 __attribute__((__sfr__));
typedef struct tagPMD7BITS {
  unsigned :4;
  unsigned DMA0MD:1;
  unsigned DMA1MD:1;
} PMD7BITS;
extern volatile PMD7BITS PMD7bits __attribute__((__sfr__));



/* ---------------------------------------------------------- */
/* Defines for unique SFR bit names                           */
/* ---------------------------------------------------------- */

/* SR */
#define _C SRbits.C
#define _Z SRbits.Z
#define _OV SRbits.OV
#define _N SRbits.N
#define _RA SRbits.RA
#define _IPL SRbits.IPL
#define _DC SRbits.DC
#define _IPL0 SRbits.IPL0
#define _IPL1 SRbits.IPL1
#define _IPL2 SRbits.IPL2

/* CORCON */
#define _IPL3 CORCONbits.IPL3

/* CNPD1 */
#define _CN2PDE CNPD1bits.CN2PDE
#define _CN3PDE CNPD1bits.CN3PDE
#define _CN4PDE CNPD1bits.CN4PDE
#define _CN5PDE CNPD1bits.CN5PDE
#define _CN6PDE CNPD1bits.CN6PDE
#define _CN7PDE CNPD1bits.CN7PDE
#define _CN8PDE CNPD1bits.CN8PDE
#define _CN9PDE CNPD1bits.CN9PDE
#define _CN10PDE CNPD1bits.CN10PDE
#define _CN11PDE CNPD1bits.CN11PDE
#define _CN12PDE CNPD1bits.CN12PDE
#define _CN13PDE CNPD1bits.CN13PDE
#define _CN14PDE CNPD1bits.CN14PDE
#define _CN15PDE CNPD1bits.CN15PDE

/* CNPD2 */
#define _CN16PDE CNPD2bits.CN16PDE
#define _CN17PDE CNPD2bits.CN17PDE
#define _CN18PDE CNPD2bits.CN18PDE
#define _CN19PDE CNPD2bits.CN19PDE
#define _CN20PDE CNPD2bits.CN20PDE
#define _CN21PDE CNPD2bits.CN21PDE
#define _CN22PDE CNPD2bits.CN22PDE
#define _CN23PDE CNPD2bits.CN23PDE
#define _CN24PDE CNPD2bits.CN24PDE
#define _CN25PDE CNPD2bits.CN25PDE
#define _CN26PDE CNPD2bits.CN26PDE
#define _CN27PDE CNPD2bits.CN27PDE
#define _CN28PDE CNPD2bits.CN28PDE
#define _CN29PDE CNPD2bits.CN29PDE
#define _CN30PDE CNPD2bits.CN30PDE
#define _CN31PDE CNPD2bits.CN31PDE

/* CNPD3 */
#define _CN32PDE CNPD3bits.CN32PDE
#define _CN41PDE CNPD3bits.CN41PDE
#define _CN42PDE CNPD3bits.CN42PDE
#define _CN43PDE CNPD3bits.CN43PDE
#define _CN44PDE CNPD3bits.CN44PDE
#define _CN45PDE CNPD3bits.CN45PDE
#define _CN46PDE CNPD3bits.CN46PDE
#define _CN47PDE CNPD3bits.CN47PDE

/* CNPD4 */
#define _CN49PDE CNPD4bits.CN49PDE
#define _CN50PDE CNPD4bits.CN50PDE
#define _CN51PDE CNPD4bits.CN51PDE
#define _CN52PDE CNPD4bits.CN52PDE
#define _CN53PDE CNPD4bits.CN53PDE
#define _CN54PDE CNPD4bits.CN54PDE
#define _CN55PDE CNPD4bits.CN55PDE
#define _CN56PDE CNPD4bits.CN56PDE
#define _CN57PDE CNPD4bits.CN57PDE
#define _CN58PDE CNPD4bits.CN58PDE
#define _CN59PDE CNPD4bits.CN59PDE
#define _CN60PDE CNPD4bits.CN60PDE
#define _CN61PDE CNPD4bits.CN61PDE
#define _CN62PDE CNPD4bits.CN62PDE
#define _CN63PDE CNPD4bits.CN63PDE

/* CNPD5 */
#define _CN64PDE CNPD5bits.CN64PDE
#define _CN65PDE CNPD5bits.CN65PDE
#define _CN66PDE CNPD5bits.CN66PDE
#define _CN67PDE CNPD5bits.CN67PDE
#define _CN68PDE CNPD5bits.CN68PDE
#define _CN69PDE CNPD5bits.CN69PDE
#define _CN70PDE CNPD5bits.CN70PDE
#define _CN71PDE CNPD5bits.CN71PDE
#define _CN72PDE CNPD5bits.CN72PDE
#define _CN73PDE CNPD5bits.CN73PDE
#define _CN74PDE CNPD5bits.CN74PDE
#define _CN77PDE CNPD5bits.CN77PDE
#define _CN78PDE CNPD5bits.CN78PDE

/* CNPD6 */
#define _CN83PDE CNPD6bits.CN83PDE
#define _CN84PDE CNPD6bits.CN84PDE

/* CNEN1 */
#define _CN2IE CNEN1bits.CN2IE
#define _CN3IE CNEN1bits.CN3IE
#define _CN4IE CNEN1bits.CN4IE
#define _CN5IE CNEN1bits.CN5IE
#define _CN6IE CNEN1bits.CN6IE
#define _CN7IE CNEN1bits.CN7IE
#define _CN8IE CNEN1bits.CN8IE
#define _CN9IE CNEN1bits.CN9IE
#define _CN10IE CNEN1bits.CN10IE
#define _CN11IE CNEN1bits.CN11IE
#define _CN12IE CNEN1bits.CN12IE
#define _CN13IE CNEN1bits.CN13IE
#define _CN14IE CNEN1bits.CN14IE
#define _CN15IE CNEN1bits.CN15IE

/* CNEN2 */
#define _CN16IE CNEN2bits.CN16IE
#define _CN17IE CNEN2bits.CN17IE
#define _CN18IE CNEN2bits.CN18IE
#define _CN19IE CNEN2bits.CN19IE
#define _CN20IE CNEN2bits.CN20IE
#define _CN21IE CNEN2bits.CN21IE
#define _CN22IE CNEN2bits.CN22IE
#define _CN23IE CNEN2bits.CN23IE
#define _CN24IE CNEN2bits.CN24IE
#define _CN25IE CNEN2bits.CN25IE
#define _CN26IE CNEN2bits.CN26IE
#define _CN27IE CNEN2bits.CN27IE
#define _CN28IE CNEN2bits.CN28IE
#define _CN29IE CNEN2bits.CN29IE
#define _CN30IE CNEN2bits.CN30IE
#define _CN31IE CNEN2bits.CN31IE

/* CNEN3 */
#define _CN32IE CNEN3bits.CN32IE
#define _CN41IE CNEN3bits.CN41IE
#define _CN42IE CNEN3bits.CN42IE
#define _CN43IE CNEN3bits.CN43IE
#define _CN44IE CNEN3bits.CN44IE
#define _CN45IE CNEN3bits.CN45IE
#define _CN46IE CNEN3bits.CN46IE
#define _CN47IE CNEN3bits.CN47IE

/* CNEN4 */
#define _CN49IE CNEN4bits.CN49IE
#define _CN50IE CNEN4bits.CN50IE
#define _CN51IE CNEN4bits.CN51IE
#define _CN52IE CNEN4bits.CN52IE
#define _CN53IE CNEN4bits.CN53IE
#define _CN54IE CNEN4bits.CN54IE
#define _CN55IE CNEN4bits.CN55IE
#define _CN56IE CNEN4bits.CN56IE
#define _CN57IE CNEN4bits.CN57IE
#define _CN58IE CNEN4bits.CN58IE
#define _CN59IE CNEN4bits.CN59IE
#define _CN60IE CNEN4bits.CN60IE
#define _CN61IE CNEN4bits.CN61IE
#define _CN62IE CNEN4bits.CN62IE
#define _CN63IE CNEN4bits.CN63IE

/* CNEN5 */
#define _CN64IE CNEN5bits.CN64IE
#define _CN65IE CNEN5bits.CN65IE
#define _CN66IE CNEN5bits.CN66IE
#define _CN67IE CNEN5bits.CN67IE
#define _CN68IE CNEN5bits.CN68IE
#define _CN69IE CNEN5bits.CN69IE
#define _CN70IE CNEN5bits.CN70IE
#define _CN71IE CNEN5bits.CN71IE
#define _CN72IE CNEN5bits.CN72IE
#define _CN73IE CNEN5bits.CN73IE
#define _CN74IE CNEN5bits.CN74IE
#define _CN77IE CNEN5bits.CN77IE
#define _CN78IE CNEN5bits.CN78IE

/* CNEN6 */
#define _CN83IE CNEN6bits.CN83IE
#define _CN84IE CNEN6bits.CN84IE

/* CNPU1 */
#define _CN2PUE CNPU1bits.CN2PUE
#define _CN3PUE CNPU1bits.CN3PUE
#define _CN4PUE CNPU1bits.CN4PUE
#define _CN5PUE CNPU1bits.CN5PUE
#define _CN6PUE CNPU1bits.CN6PUE
#define _CN7PUE CNPU1bits.CN7PUE
#define _CN8PUE CNPU1bits.CN8PUE
#define _CN9PUE CNPU1bits.CN9PUE
#define _CN10PUE CNPU1bits.CN10PUE
#define _CN11PUE CNPU1bits.CN11PUE
#define _CN12PUE CNPU1bits.CN12PUE
#define _CN13PUE CNPU1bits.CN13PUE
#define _CN14PUE CNPU1bits.CN14PUE
#define _CN15PUE CNPU1bits.CN15PUE

/* CNPU2 */
#define _CN16PUE CNPU2bits.CN16PUE
#define _CN17PUE CNPU2bits.CN17PUE
#define _CN18PUE CNPU2bits.CN18PUE
#define _CN19PUE CNPU2bits.CN19PUE
#define _CN20PUE CNPU2bits.CN20PUE
#define _CN21PUE CNPU2bits.CN21PUE
#define _CN22PUE CNPU2bits.CN22PUE
#define _CN23PUE CNPU2bits.CN23PUE
#define _CN24PUE CNPU2bits.CN24PUE
#define _CN25PUE CNPU2bits.CN25PUE
#define _CN26PUE CNPU2bits.CN26PUE
#define _CN27PUE CNPU2bits.CN27PUE
#define _CN28PUE CNPU2bits.CN28PUE
#define _CN29PUE CNPU2bits.CN29PUE
#define _CN30PUE CNPU2bits.CN30PUE
#define _CN31PUE CNPU2bits.CN31PUE

/* CNPU3 */
#define _CN32PUE CNPU3bits.CN32PUE
#define _CN41PUE CNPU3bits.CN41PUE
#define _CN42PUE CNPU3bits.CN42PUE
#define _CN43PUE CNPU3bits.CN43PUE
#define _CN44PUE CNPU3bits.CN44PUE
#define _CN45PUE CNPU3bits.CN45PUE
#define _CN46PUE CNPU3bits.CN46PUE
#define _CN47PUE CNPU3bits.CN47PUE

/* CNPU4 */
#define _CN49PUE CNPU4bits.CN49PUE
#define _CN50PUE CNPU4bits.CN50PUE
#define _CN51PUE CNPU4bits.CN51PUE
#define _CN52PUE CNPU4bits.CN52PUE
#define _CN53PUE CNPU4bits.CN53PUE
#define _CN54PUE CNPU4bits.CN54PUE
#define _CN55PUE CNPU4bits.CN55PUE
#define _CN56PUE CNPU4bits.CN56PUE
#define _CN57PUE CNPU4bits.CN57PUE
#define _CN58PUE CNPU4bits.CN58PUE
#define _CN59PUE CNPU4bits.CN59PUE
#define _CN60PUE CNPU4bits.CN60PUE
#define _CN61PUE CNPU4bits.CN61PUE
#define _CN62PUE CNPU4bits.CN62PUE
#define _CN63PUE CNPU4bits.CN63PUE

/* CNPU5 */
#define _CN64PUE CNPU5bits.CN64PUE
#define _CN65PUE CNPU5bits.CN65PUE
#define _CN66PUE CNPU5bits.CN66PUE
#define _CN67PUE CNPU5bits.CN67PUE
#define _CN68PUE CNPU5bits.CN68PUE
#define _CN69PUE CNPU5bits.CN69PUE
#define _CN70PUE CNPU5bits.CN70PUE
#define _CN71PUE CNPU5bits.CN71PUE
#define _CN72PUE CNPU5bits.CN72PUE
#define _CN73PUE CNPU5bits.CN73PUE
#define _CN74PUE CNPU5bits.CN74PUE
#define _CN77PUE CNPU5bits.CN77PUE
#define _CN78PUE CNPU5bits.CN78PUE

/* CNPU6 */
#define _CN83PUE CNPU6bits.CN83PUE
#define _CN84PUE CNPU6bits.CN84PUE

/* INTCON1 */
#define _OSCFAIL INTCON1bits.OSCFAIL
#define _STKERR INTCON1bits.STKERR
#define _ADDRERR INTCON1bits.ADDRERR
#define _MATHERR INTCON1bits.MATHERR
#define _NSTDIS INTCON1bits.NSTDIS

/* INTCON2 */
#define _INT0EP INTCON2bits.INT0EP
#define _INT1EP INTCON2bits.INT1EP
#define _INT2EP INTCON2bits.INT2EP
#define _INT3EP INTCON2bits.INT3EP
#define _INT4EP INTCON2bits.INT4EP
#define _DISI INTCON2bits.DISI
#define _ALTIVT INTCON2bits.ALTIVT

/* IFS0 */
#define _INT0IF IFS0bits.INT0IF
#define _IC1IF IFS0bits.IC1IF
#define _OC1IF IFS0bits.OC1IF
#define _T1IF IFS0bits.T1IF
#define _DMA0IF IFS0bits.DMA0IF
#define _IC2IF IFS0bits.IC2IF
#define _OC2IF IFS0bits.OC2IF
#define _T2IF IFS0bits.T2IF
#define _T3IF IFS0bits.T3IF
#define _SPF1IF IFS0bits.SPF1IF
#define _SPI1IF IFS0bits.SPI1IF
#define _U1RXIF IFS0bits.U1RXIF
#define _U1TXIF IFS0bits.U1TXIF
#define _AD1IF IFS0bits.AD1IF
#define _DMA1IF IFS0bits.DMA1IF

/* IFS1 */
#define _SI2C1IF IFS1bits.SI2C1IF
#define _MI2C1IF IFS1bits.MI2C1IF
#define _CMIF IFS1bits.CMIF
#define _CNIF IFS1bits.CNIF
#define _INT1IF IFS1bits.INT1IF
#define _IC7IF IFS1bits.IC7IF
#define _DMA2IF IFS1bits.DMA2IF
#define _OC3IF IFS1bits.OC3IF
#define _OC4IF IFS1bits.OC4IF
#define _T4IF IFS1bits.T4IF
#define _T5IF IFS1bits.T5IF
#define _INT2IF IFS1bits.INT2IF
#define _U2RXIF IFS1bits.U2RXIF
#define _U2TXIF IFS1bits.U2TXIF

/* IFS2 */
#define _SPF2IF IFS2bits.SPF2IF
#define _SPI2IF IFS2bits.SPI2IF
#define _DMA3IF IFS2bits.DMA3IF
#define _IC3IF IFS2bits.IC3IF
#define _IC4IF IFS2bits.IC4IF
#define _IC5IF IFS2bits.IC5IF
#define _IC6IF IFS2bits.IC6IF
#define _OC5IF IFS2bits.OC5IF
#define _OC6IF IFS2bits.OC6IF
#define _OC7IF IFS2bits.OC7IF
#define _PMPIF IFS2bits.PMPIF
#define _DMA4IF IFS2bits.DMA4IF

/* IFS3 */
#define _SI2C2IF IFS3bits.SI2C2IF
#define _MI2C2IF IFS3bits.MI2C2IF
#define _INT3IF IFS3bits.INT3IF
#define _INT4IF IFS3bits.INT4IF
#define _DMA5IF IFS3bits.DMA5IF
#define _RTCIF IFS3bits.RTCIF

/* IFS4 */
#define _U1ERIF IFS4bits.U1ERIF
#define _U2ERIF IFS4bits.U2ERIF
#define _CRCIF IFS4bits.CRCIF
#define _LVDIF IFS4bits.LVDIF
#define _CTMUIF IFS4bits.CTMUIF

/* IFS5 */
#define _U3ERIF IFS5bits.U3ERIF
#define _U3RXIF IFS5bits.U3RXIF
#define _U3TXIF IFS5bits.U3TXIF
#define _U4ERIF IFS5bits.U4ERIF
#define _U4RXIF IFS5bits.U4RXIF
#define _U4TXIF IFS5bits.U4TXIF

/* IFS6 */
#define _LCDIF IFS6bits.LCDIF

/* IFS7 */
#define _JTAGIF IFS7bits.JTAGIF

/* IEC0 */
#define _INT0IE IEC0bits.INT0IE
#define _IC1IE IEC0bits.IC1IE
#define _OC1IE IEC0bits.OC1IE
#define _T1IE IEC0bits.T1IE
#define _DMA0IE IEC0bits.DMA0IE
#define _IC2IE IEC0bits.IC2IE
#define _OC2IE IEC0bits.OC2IE
#define _T2IE IEC0bits.T2IE
#define _T3IE IEC0bits.T3IE
#define _SPF1IE IEC0bits.SPF1IE
#define _SPI1IE IEC0bits.SPI1IE
#define _U1RXIE IEC0bits.U1RXIE
#define _U1TXIE IEC0bits.U1TXIE
#define _AD1IE IEC0bits.AD1IE
#define _DMA1IE IEC0bits.DMA1IE

/* IEC1 */
#define _SI2C1IE IEC1bits.SI2C1IE
#define _MI2C1IE IEC1bits.MI2C1IE
#define _CMIE IEC1bits.CMIE
#define _CNIE IEC1bits.CNIE
#define _INT1IE IEC1bits.INT1IE
#define _IC7IE IEC1bits.IC7IE
#define _DMA2IE IEC1bits.DMA2IE
#define _OC3IE IEC1bits.OC3IE
#define _OC4IE IEC1bits.OC4IE
#define _T4IE IEC1bits.T4IE
#define _T5IE IEC1bits.T5IE
#define _INT2IE IEC1bits.INT2IE
#define _U2RXIE IEC1bits.U2RXIE
#define _U2TXIE IEC1bits.U2TXIE

/* IEC2 */
#define _SPF2IE IEC2bits.SPF2IE
#define _SPI2IE IEC2bits.SPI2IE
#define _DMA3IE IEC2bits.DMA3IE
#define _IC3IE IEC2bits.IC3IE
#define _IC4IE IEC2bits.IC4IE
#define _IC5IE IEC2bits.IC5IE
#define _IC6IE IEC2bits.IC6IE
#define _OC5IE IEC2bits.OC5IE
#define _OC6IE IEC2bits.OC6IE
#define _OC7IE IEC2bits.OC7IE
#define _PMPIE IEC2bits.PMPIE
#define _DMA4IE IEC2bits.DMA4IE

/* IEC3 */
#define _SI2C2IE IEC3bits.SI2C2IE
#define _MI2C2IE IEC3bits.MI2C2IE
#define _INT3IE IEC3bits.INT3IE
#define _INT4IE IEC3bits.INT4IE
#define _DMA5IE IEC3bits.DMA5IE
#define _RTCIE IEC3bits.RTCIE

/* IEC4 */
#define _U1ERIE IEC4bits.U1ERIE
#define _U2ERIE IEC4bits.U2ERIE
#define _CRCIE IEC4bits.CRCIE
#define _LVDIE IEC4bits.LVDIE
#define _CTMUIE IEC4bits.CTMUIE

/* IEC5 */
#define _U3ERIE IEC5bits.U3ERIE
#define _U3RXIE IEC5bits.U3RXIE
#define _U3TXIE IEC5bits.U3TXIE
#define _U4ERIE IEC5bits.U4ERIE
#define _U4RXIE IEC5bits.U4RXIE
#define _U4TXIE IEC5bits.U4TXIE

/* IEC6 */
#define _LCDIE IEC6bits.LCDIE

/* IEC7 */
#define _JTAGIE IEC7bits.JTAGIE

/* IPC0 */
#define _INT0IP IPC0bits.INT0IP
#define _IC1IP IPC0bits.IC1IP
#define _OC1IP IPC0bits.OC1IP
#define _T1IP IPC0bits.T1IP
#define _INT0IP0 IPC0bits.INT0IP0
#define _INT0IP1 IPC0bits.INT0IP1
#define _INT0IP2 IPC0bits.INT0IP2
#define _IC1IP0 IPC0bits.IC1IP0
#define _IC1IP1 IPC0bits.IC1IP1
#define _IC1IP2 IPC0bits.IC1IP2
#define _OC1IP0 IPC0bits.OC1IP0
#define _OC1IP1 IPC0bits.OC1IP1
#define _OC1IP2 IPC0bits.OC1IP2
#define _T1IP0 IPC0bits.T1IP0
#define _T1IP1 IPC0bits.T1IP1
#define _T1IP2 IPC0bits.T1IP2

/* IPC1 */
#define _DMA0IP IPC1bits.DMA0IP
#define _IC2IP IPC1bits.IC2IP
#define _OC2IP IPC1bits.OC2IP
#define _T2IP IPC1bits.T2IP
#define _DMA0IP0 IPC1bits.DMA0IP0
#define _DMA0IP1 IPC1bits.DMA0IP1
#define _DMA0IP2 IPC1bits.DMA0IP2
#define _IC2IP0 IPC1bits.IC2IP0
#define _IC2IP1 IPC1bits.IC2IP1
#define _IC2IP2 IPC1bits.IC2IP2
#define _OC2IP0 IPC1bits.OC2IP0
#define _OC2IP1 IPC1bits.OC2IP1
#define _OC2IP2 IPC1bits.OC2IP2
#define _T2IP0 IPC1bits.T2IP0
#define _T2IP1 IPC1bits.T2IP1
#define _T2IP2 IPC1bits.T2IP2

/* IPC2 */
#define _T3IP IPC2bits.T3IP
#define _SPF1IP IPC2bits.SPF1IP
#define _SPI1IP IPC2bits.SPI1IP
#define _U1RXIP IPC2bits.U1RXIP
#define _T3IP0 IPC2bits.T3IP0
#define _T3IP1 IPC2bits.T3IP1
#define _T3IP2 IPC2bits.T3IP2
#define _SPF1IP0 IPC2bits.SPF1IP0
#define _SPF1IP1 IPC2bits.SPF1IP1
#define _SPF1IP2 IPC2bits.SPF1IP2
#define _SPI1IP0 IPC2bits.SPI1IP0
#define _SPI1IP1 IPC2bits.SPI1IP1
#define _SPI1IP2 IPC2bits.SPI1IP2
#define _U1RXIP0 IPC2bits.U1RXIP0
#define _U1RXIP1 IPC2bits.U1RXIP1
#define _U1RXIP2 IPC2bits.U1RXIP2

/* IPC3 */
#define _U1TXIP IPC3bits.U1TXIP
#define _AD1IP IPC3bits.AD1IP
#define _DMA1IP IPC3bits.DMA1IP
#define _U1TXIP0 IPC3bits.U1TXIP0
#define _U1TXIP1 IPC3bits.U1TXIP1
#define _U1TXIP2 IPC3bits.U1TXIP2
#define _AD1IP0 IPC3bits.AD1IP0
#define _AD1IP1 IPC3bits.AD1IP1
#define _AD1IP2 IPC3bits.AD1IP2
#define _DMA1IP0 IPC3bits.DMA1IP0
#define _DMA1IP1 IPC3bits.DMA1IP1
#define _DMA1IP2 IPC3bits.DMA1IP2

/* IPC4 */
#define _SI2C1IP IPC4bits.SI2C1IP
#define _MI2C1IP IPC4bits.MI2C1IP
#define _CMIP IPC4bits.CMIP
#define _CNIP IPC4bits.CNIP
#define _SI2C1IP0 IPC4bits.SI2C1IP0
#define _SI2C1IP1 IPC4bits.SI2C1IP1
#define _SI2C1IP2 IPC4bits.SI2C1IP2
#define _MI2C1IP0 IPC4bits.MI2C1IP0
#define _MI2C1IP1 IPC4bits.MI2C1IP1
#define _MI2C1IP2 IPC4bits.MI2C1IP2
#define _CMIP0 IPC4bits.CMIP0
#define _CMIP1 IPC4bits.CMIP1
#define _CMIP2 IPC4bits.CMIP2
#define _CNIP0 IPC4bits.CNIP0
#define _CNIP1 IPC4bits.CNIP1
#define _CNIP2 IPC4bits.CNIP2
#define _SI2C1P IPC4bits.SI2C1P
#define _MI2C1P IPC4bits.MI2C1P
#define _SI2C1P0 IPC4bits.SI2C1P0
#define _SI2C1P1 IPC4bits.SI2C1P1
#define _SI2C1P2 IPC4bits.SI2C1P2
#define _MI2C1P0 IPC4bits.MI2C1P0
#define _MI2C1P1 IPC4bits.MI2C1P1
#define _MI2C1P2 IPC4bits.MI2C1P2

/* IPC5 */
#define _INT1IP IPC5bits.INT1IP
#define _IC7IP IPC5bits.IC7IP
#define _INT1IP0 IPC5bits.INT1IP0
#define _INT1IP1 IPC5bits.INT1IP1
#define _INT1IP2 IPC5bits.INT1IP2
#define _IC7IP0 IPC5bits.IC7IP0
#define _IC7IP1 IPC5bits.IC7IP1
#define _IC7IP2 IPC5bits.IC7IP2

/* IPC6 */
#define _DMA2IP IPC6bits.DMA2IP
#define _OC3IP IPC6bits.OC3IP
#define _OC4IP IPC6bits.OC4IP
#define _T4IP IPC6bits.T4IP
#define _DMA2IP0 IPC6bits.DMA2IP0
#define _DMA2IP1 IPC6bits.DMA2IP1
#define _DMA2IP2 IPC6bits.DMA2IP2
#define _OC3IP0 IPC6bits.OC3IP0
#define _OC3IP1 IPC6bits.OC3IP1
#define _OC3IP2 IPC6bits.OC3IP2
#define _OC4IP0 IPC6bits.OC4IP0
#define _OC4IP1 IPC6bits.OC4IP1
#define _OC4IP2 IPC6bits.OC4IP2
#define _T4IP0 IPC6bits.T4IP0
#define _T4IP1 IPC6bits.T4IP1
#define _T4IP2 IPC6bits.T4IP2

/* IPC7 */
#define _T5IP IPC7bits.T5IP
#define _INT2IP IPC7bits.INT2IP
#define _U2RXIP IPC7bits.U2RXIP
#define _U2TXIP IPC7bits.U2TXIP
#define _T5IP0 IPC7bits.T5IP0
#define _T5IP1 IPC7bits.T5IP1
#define _T5IP2 IPC7bits.T5IP2
#define _INT2IP0 IPC7bits.INT2IP0
#define _INT2IP1 IPC7bits.INT2IP1
#define _INT2IP2 IPC7bits.INT2IP2
#define _U2RXIP0 IPC7bits.U2RXIP0
#define _U2RXIP1 IPC7bits.U2RXIP1
#define _U2RXIP2 IPC7bits.U2RXIP2
#define _U2TXIP0 IPC7bits.U2TXIP0
#define _U2TXIP1 IPC7bits.U2TXIP1
#define _U2TXIP2 IPC7bits.U2TXIP2

/* IPC8 */
#define _SPF2IP IPC8bits.SPF2IP
#define _SPI2IP IPC8bits.SPI2IP
#define _SPF2IP0 IPC8bits.SPF2IP0
#define _SPF2IP1 IPC8bits.SPF2IP1
#define _SPF2IP2 IPC8bits.SPF2IP2
#define _SPI2IP0 IPC8bits.SPI2IP0
#define _SPI2IP1 IPC8bits.SPI2IP1
#define _SPI2IP2 IPC8bits.SPI2IP2

/* IPC9 */
#define _DMA3IP IPC9bits.DMA3IP
#define _IC3IP IPC9bits.IC3IP
#define _IC4IP IPC9bits.IC4IP
#define _IC5IP IPC9bits.IC5IP
#define _DMA3IP0 IPC9bits.DMA3IP0
#define _DMA3IP1 IPC9bits.DMA3IP1
#define _DMA3IP2 IPC9bits.DMA3IP2
#define _IC3IP0 IPC9bits.IC3IP0
#define _IC3IP1 IPC9bits.IC3IP1
#define _IC3IP2 IPC9bits.IC3IP2
#define _IC4IP0 IPC9bits.IC4IP0
#define _IC4IP1 IPC9bits.IC4IP1
#define _IC4IP2 IPC9bits.IC4IP2
#define _IC5IP0 IPC9bits.IC5IP0
#define _IC5IP1 IPC9bits.IC5IP1
#define _IC5IP2 IPC9bits.IC5IP2

/* IPC10 */
#define _IC6IP IPC10bits.IC6IP
#define _OC5IP IPC10bits.OC5IP
#define _OC6IP IPC10bits.OC6IP
#define _OC7IP IPC10bits.OC7IP
#define _IC6IP0 IPC10bits.IC6IP0
#define _IC6IP1 IPC10bits.IC6IP1
#define _IC6IP2 IPC10bits.IC6IP2
#define _OC5IP0 IPC10bits.OC5IP0
#define _OC5IP1 IPC10bits.OC5IP1
#define _OC5IP2 IPC10bits.OC5IP2
#define _OC6IP0 IPC10bits.OC6IP0
#define _OC6IP1 IPC10bits.OC6IP1
#define _OC6IP2 IPC10bits.OC6IP2
#define _OC7IP0 IPC10bits.OC7IP0
#define _OC7IP1 IPC10bits.OC7IP1
#define _OC7IP2 IPC10bits.OC7IP2

/* IPC11 */
#define _PMPIP IPC11bits.PMPIP
#define _DMA4IP IPC11bits.DMA4IP
#define _PMPIP0 IPC11bits.PMPIP0
#define _PMPIP1 IPC11bits.PMPIP1
#define _PMPIP2 IPC11bits.PMPIP2
#define _DMA4IP0 IPC11bits.DMA4IP0
#define _DMA4IP1 IPC11bits.DMA4IP1
#define _DMA4IP2 IPC11bits.DMA4IP2

/* IPC12 */
#define _SI2C2IP IPC12bits.SI2C2IP
#define _MI2C2IP IPC12bits.MI2C2IP
#define _SI2C2IP0 IPC12bits.SI2C2IP0
#define _SI2C2IP1 IPC12bits.SI2C2IP1
#define _SI2C2IP2 IPC12bits.SI2C2IP2
#define _MI2C2IP0 IPC12bits.MI2C2IP0
#define _MI2C2IP1 IPC12bits.MI2C2IP1
#define _MI2C2IP2 IPC12bits.MI2C2IP2
#define _SI2C2P0 IPC12bits.SI2C2P0
#define _SI2C2P1 IPC12bits.SI2C2P1
#define _SI2C2P2 IPC12bits.SI2C2P2
#define _MI2C2P0 IPC12bits.MI2C2P0
#define _MI2C2P1 IPC12bits.MI2C2P1
#define _MI2C2P2 IPC12bits.MI2C2P2
#define _SI2C2P IPC12bits.SI2C2P
#define _MI2C2P IPC12bits.MI2C2P

/* IPC13 */
#define _INT3IP IPC13bits.INT3IP
#define _INT4IP IPC13bits.INT4IP
#define _INT3IP0 IPC13bits.INT3IP0
#define _INT3IP1 IPC13bits.INT3IP1
#define _INT3IP2 IPC13bits.INT3IP2
#define _INT4IP0 IPC13bits.INT4IP0
#define _INT4IP1 IPC13bits.INT4IP1
#define _INT4IP2 IPC13bits.INT4IP2

/* IPC15 */
#define _DMA5IP IPC15bits.DMA5IP
#define _RTCIP IPC15bits.RTCIP
#define _DMA5IP0 IPC15bits.DMA5IP0
#define _DMA5IP1 IPC15bits.DMA5IP1
#define _DMA5IP2 IPC15bits.DMA5IP2
#define _RTCIP0 IPC15bits.RTCIP0
#define _RTCIP1 IPC15bits.RTCIP1
#define _RTCIP2 IPC15bits.RTCIP2

/* IPC16 */
#define _U1ERIP IPC16bits.U1ERIP
#define _U2ERIP IPC16bits.U2ERIP
#define _CRCIP IPC16bits.CRCIP
#define _U1ERIP0 IPC16bits.U1ERIP0
#define _U1ERIP1 IPC16bits.U1ERIP1
#define _U1ERIP2 IPC16bits.U1ERIP2
#define _U2ERIP0 IPC16bits.U2ERIP0
#define _U2ERIP1 IPC16bits.U2ERIP1
#define _U2ERIP2 IPC16bits.U2ERIP2
#define _CRCIP0 IPC16bits.CRCIP0
#define _CRCIP1 IPC16bits.CRCIP1
#define _CRCIP2 IPC16bits.CRCIP2

/* IPC18 */
#define _LVDIP IPC18bits.LVDIP
#define _LVDIP0 IPC18bits.LVDIP0
#define _LVDIP1 IPC18bits.LVDIP1
#define _LVDIP2 IPC18bits.LVDIP2

/* IPC19 */
#define _CTMUIP IPC19bits.CTMUIP
#define _CTMUIP0 IPC19bits.CTMUIP0
#define _CTMUIP1 IPC19bits.CTMUIP1
#define _CTMUIP2 IPC19bits.CTMUIP2

/* IPC20 */
#define _U3ERIP IPC20bits.U3ERIP
#define _U3RXIP IPC20bits.U3RXIP
#define _U3TXIP IPC20bits.U3TXIP
#define _U3ERIP0 IPC20bits.U3ERIP0
#define _U3ERIP1 IPC20bits.U3ERIP1
#define _U3ERIP2 IPC20bits.U3ERIP2
#define _U3RXIP0 IPC20bits.U3RXIP0
#define _U3RXIP1 IPC20bits.U3RXIP1
#define _U3RXIP2 IPC20bits.U3RXIP2
#define _U3TXIP0 IPC20bits.U3TXIP0
#define _U3TXIP1 IPC20bits.U3TXIP1
#define _U3TXIP2 IPC20bits.U3TXIP2

/* IPC21 */
#define _U4ERIP IPC21bits.U4ERIP
#define _U4ERIP0 IPC21bits.U4ERIP0
#define _U4ERIP1 IPC21bits.U4ERIP1
#define _U4ERIP2 IPC21bits.U4ERIP2

/* IPC22 */
#define _U4RXIP IPC22bits.U4RXIP
#define _U4TXIP IPC22bits.U4TXIP
#define _U4RXIP0 IPC22bits.U4RXIP0
#define _U4RXIP1 IPC22bits.U4RXIP1
#define _U4RXIP2 IPC22bits.U4RXIP2
#define _U4TXIP0 IPC22bits.U4TXIP0
#define _U4TXIP1 IPC22bits.U4TXIP1
#define _U4TXIP2 IPC22bits.U4TXIP2

/* IPC25 */
#define _LCDIP IPC25bits.LCDIP
#define _LCDIP0 IPC25bits.LCDIP0
#define _LCDIP1 IPC25bits.LCDIP1
#define _LCDIP2 IPC25bits.LCDIP2

/* IPC29 */
#define _JTAGIP IPC29bits.JTAGIP
#define _JTAGIP0 IPC29bits.JTAGIP0
#define _JTAGIP1 IPC29bits.JTAGIP1
#define _JTAGIP2 IPC29bits.JTAGIP2

/* INTTREG */
#define _VECNUM INTTREGbits.VECNUM
#define _ILR INTTREGbits.ILR
#define _VHOLD INTTREGbits.VHOLD
#define _CPUIRQ INTTREGbits.CPUIRQ
#define _VECNUM0 INTTREGbits.VECNUM0
#define _VECNUM1 INTTREGbits.VECNUM1
#define _VECNUM2 INTTREGbits.VECNUM2
#define _VECNUM3 INTTREGbits.VECNUM3
#define _VECNUM4 INTTREGbits.VECNUM4
#define _VECNUM5 INTTREGbits.VECNUM5
#define _VECNUM6 INTTREGbits.VECNUM6
#define _ILR0 INTTREGbits.ILR0
#define _ILR1 INTTREGbits.ILR1
#define _ILR2 INTTREGbits.ILR2
#define _ILR3 INTTREGbits.ILR3

/* T1CON */
#define _TCS T1CONbits.TCS
#define _TSYNC T1CONbits.TSYNC
#define _TCKPS T1CONbits.TCKPS
#define _TGATE T1CONbits.TGATE
#define _TIECS T1CONbits.TIECS
#define _TSIDL T1CONbits.TSIDL
#define _TON T1CONbits.TON
#define _TCKPS0 T1CONbits.TCKPS0
#define _TCKPS1 T1CONbits.TCKPS1
#define _T1ECS0 T1CONbits.T1ECS0
#define _T1ECS1 T1CONbits.T1ECS1

/* T2CON */
/* Bitname _TCS cannot be defined because it is used by more than one SFR */
#define _T32 T2CONbits.T32
/* Bitname _TCKPS cannot be defined because it is used by more than one SFR */
/* Bitname _TGATE cannot be defined because it is used by more than one SFR */
/* Bitname _TSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _TON cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS0 cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS1 cannot be defined because it is used by more than one SFR */

/* T3CON */
/* Bitname _TCS cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS cannot be defined because it is used by more than one SFR */
/* Bitname _TGATE cannot be defined because it is used by more than one SFR */
/* Bitname _TSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _TON cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS0 cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS1 cannot be defined because it is used by more than one SFR */

/* T4CON */
/* Bitname _TCS cannot be defined because it is used by more than one SFR */
#define _T45 T4CONbits.T45
/* Bitname _TCKPS cannot be defined because it is used by more than one SFR */
/* Bitname _TGATE cannot be defined because it is used by more than one SFR */
/* Bitname _TSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _TON cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS0 cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS1 cannot be defined because it is used by more than one SFR */

/* T5CON */
/* Bitname _TCS cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS cannot be defined because it is used by more than one SFR */
/* Bitname _TGATE cannot be defined because it is used by more than one SFR */
/* Bitname _TSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _TON cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS0 cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS1 cannot be defined because it is used by more than one SFR */

/* IC1CON1 */
/* Bitname _ICM cannot be defined because it is used by more than one SFR */
/* Bitname _ICBNE cannot be defined because it is used by more than one SFR */
/* Bitname _ICOV cannot be defined because it is used by more than one SFR */
/* Bitname _ICI cannot be defined because it is used by more than one SFR */
/* Bitname _ICTSEL cannot be defined because it is used by more than one SFR */
/* Bitname _ICSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _ICM0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICM1 cannot be defined because it is used by more than one SFR */
/* Bitname _ICM2 cannot be defined because it is used by more than one SFR */
/* Bitname _ICI0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICI1 cannot be defined because it is used by more than one SFR */
/* Bitname _ICTSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICTSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _ICTSEL2 cannot be defined because it is used by more than one SFR */

/* IC1CON2 */
/* Bitname _SYNCSEL cannot be defined because it is used by more than one SFR */
/* Bitname _TRIGSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _ICTRIG cannot be defined because it is used by more than one SFR */
/* Bitname _IC32 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL2 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL3 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL4 cannot be defined because it is used by more than one SFR */

/* IC2CON1 */
/* Bitname _ICM cannot be defined because it is used by more than one SFR */
/* Bitname _ICBNE cannot be defined because it is used by more than one SFR */
/* Bitname _ICOV cannot be defined because it is used by more than one SFR */
/* Bitname _ICI cannot be defined because it is used by more than one SFR */
/* Bitname _ICTSEL cannot be defined because it is used by more than one SFR */
/* Bitname _ICSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _ICM0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICM1 cannot be defined because it is used by more than one SFR */
/* Bitname _ICM2 cannot be defined because it is used by more than one SFR */
/* Bitname _ICI0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICI1 cannot be defined because it is used by more than one SFR */
/* Bitname _ICTSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICTSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _ICTSEL2 cannot be defined because it is used by more than one SFR */

/* IC2CON2 */
/* Bitname _SYNCSEL cannot be defined because it is used by more than one SFR */
/* Bitname _TRIGSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _ICTRIG cannot be defined because it is used by more than one SFR */
/* Bitname _IC32 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL2 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL3 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL4 cannot be defined because it is used by more than one SFR */

/* IC3CON1 */
/* Bitname _ICM cannot be defined because it is used by more than one SFR */
/* Bitname _ICBNE cannot be defined because it is used by more than one SFR */
/* Bitname _ICOV cannot be defined because it is used by more than one SFR */
/* Bitname _ICI cannot be defined because it is used by more than one SFR */
/* Bitname _ICTSEL cannot be defined because it is used by more than one SFR */
/* Bitname _ICSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _ICM0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICM1 cannot be defined because it is used by more than one SFR */
/* Bitname _ICM2 cannot be defined because it is used by more than one SFR */
/* Bitname _ICI0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICI1 cannot be defined because it is used by more than one SFR */
/* Bitname _ICTSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICTSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _ICTSEL2 cannot be defined because it is used by more than one SFR */

/* IC3CON2 */
/* Bitname _SYNCSEL cannot be defined because it is used by more than one SFR */
/* Bitname _TRIGSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _ICTRIG cannot be defined because it is used by more than one SFR */
/* Bitname _IC32 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL2 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL3 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL4 cannot be defined because it is used by more than one SFR */

/* IC4CON1 */
/* Bitname _ICM cannot be defined because it is used by more than one SFR */
/* Bitname _ICBNE cannot be defined because it is used by more than one SFR */
/* Bitname _ICOV cannot be defined because it is used by more than one SFR */
/* Bitname _ICI cannot be defined because it is used by more than one SFR */
/* Bitname _ICTSEL cannot be defined because it is used by more than one SFR */
/* Bitname _ICSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _ICM0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICM1 cannot be defined because it is used by more than one SFR */
/* Bitname _ICM2 cannot be defined because it is used by more than one SFR */
/* Bitname _ICI0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICI1 cannot be defined because it is used by more than one SFR */
/* Bitname _ICTSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICTSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _ICTSEL2 cannot be defined because it is used by more than one SFR */

/* IC4CON2 */
/* Bitname _SYNCSEL cannot be defined because it is used by more than one SFR */
/* Bitname _TRIGSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _ICTRIG cannot be defined because it is used by more than one SFR */
/* Bitname _IC32 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL2 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL3 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL4 cannot be defined because it is used by more than one SFR */

/* IC5CON1 */
/* Bitname _ICM cannot be defined because it is used by more than one SFR */
/* Bitname _ICBNE cannot be defined because it is used by more than one SFR */
/* Bitname _ICOV cannot be defined because it is used by more than one SFR */
/* Bitname _ICI cannot be defined because it is used by more than one SFR */
/* Bitname _ICTSEL cannot be defined because it is used by more than one SFR */
/* Bitname _ICSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _ICM0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICM1 cannot be defined because it is used by more than one SFR */
/* Bitname _ICM2 cannot be defined because it is used by more than one SFR */
/* Bitname _ICI0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICI1 cannot be defined because it is used by more than one SFR */
/* Bitname _ICTSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICTSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _ICTSEL2 cannot be defined because it is used by more than one SFR */

/* IC5CON2 */
/* Bitname _SYNCSEL cannot be defined because it is used by more than one SFR */
/* Bitname _TRIGSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _ICTRIG cannot be defined because it is used by more than one SFR */
/* Bitname _IC32 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL2 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL3 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL4 cannot be defined because it is used by more than one SFR */

/* IC6CON1 */
/* Bitname _ICM cannot be defined because it is used by more than one SFR */
/* Bitname _ICBNE cannot be defined because it is used by more than one SFR */
/* Bitname _ICOV cannot be defined because it is used by more than one SFR */
/* Bitname _ICI cannot be defined because it is used by more than one SFR */
/* Bitname _ICTSEL cannot be defined because it is used by more than one SFR */
/* Bitname _ICSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _ICM0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICM1 cannot be defined because it is used by more than one SFR */
/* Bitname _ICM2 cannot be defined because it is used by more than one SFR */
/* Bitname _ICI0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICI1 cannot be defined because it is used by more than one SFR */
/* Bitname _ICTSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICTSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _ICTSEL2 cannot be defined because it is used by more than one SFR */

/* IC6CON2 */
/* Bitname _SYNCSEL cannot be defined because it is used by more than one SFR */
/* Bitname _TRIGSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _ICTRIG cannot be defined because it is used by more than one SFR */
/* Bitname _IC32 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL2 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL3 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL4 cannot be defined because it is used by more than one SFR */

/* IC7CON1 */
/* Bitname _ICM cannot be defined because it is used by more than one SFR */
/* Bitname _ICBNE cannot be defined because it is used by more than one SFR */
/* Bitname _ICOV cannot be defined because it is used by more than one SFR */
/* Bitname _ICI cannot be defined because it is used by more than one SFR */
/* Bitname _ICTSEL cannot be defined because it is used by more than one SFR */
/* Bitname _ICSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _ICM0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICM1 cannot be defined because it is used by more than one SFR */
/* Bitname _ICM2 cannot be defined because it is used by more than one SFR */
/* Bitname _ICI0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICI1 cannot be defined because it is used by more than one SFR */
/* Bitname _ICTSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICTSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _ICTSEL2 cannot be defined because it is used by more than one SFR */

/* IC7CON2 */
/* Bitname _SYNCSEL cannot be defined because it is used by more than one SFR */
/* Bitname _TRIGSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _ICTRIG cannot be defined because it is used by more than one SFR */
/* Bitname _IC32 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL2 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL3 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL4 cannot be defined because it is used by more than one SFR */

/* OC1CON1 */
/* Bitname _OCM cannot be defined because it is used by more than one SFR */
/* Bitname _TRIGMODE cannot be defined because it is used by more than one SFR */
/* Bitname _OCFLT cannot be defined because it is used by more than one SFR */
/* Bitname _ENFLT cannot be defined because it is used by more than one SFR */
/* Bitname _OCTSEL cannot be defined because it is used by more than one SFR */
/* Bitname _OCSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _OCM0 cannot be defined because it is used by more than one SFR */
/* Bitname _OCM1 cannot be defined because it is used by more than one SFR */
/* Bitname _OCM2 cannot be defined because it is used by more than one SFR */
/* Bitname _OCFLT0 cannot be defined because it is used by more than one SFR */
/* Bitname _OCFLT1 cannot be defined because it is used by more than one SFR */
/* Bitname _OCFLT2 cannot be defined because it is used by more than one SFR */
/* Bitname _ENFLT0 cannot be defined because it is used by more than one SFR */
/* Bitname _ENFLT1 cannot be defined because it is used by more than one SFR */
/* Bitname _ENFLT2 cannot be defined because it is used by more than one SFR */
/* Bitname _OCTSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _OCTSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _OCTSEL2 cannot be defined because it is used by more than one SFR */

/* OC1CON2 */
/* Bitname _SYNCSEL cannot be defined because it is used by more than one SFR */
/* Bitname _OCTRIS cannot be defined because it is used by more than one SFR */
/* Bitname _TRIGSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _OCTRIG cannot be defined because it is used by more than one SFR */
/* Bitname _OC32 cannot be defined because it is used by more than one SFR */
/* Bitname _DCB cannot be defined because it is used by more than one SFR */
/* Bitname _OCINV cannot be defined because it is used by more than one SFR */
/* Bitname _FLTTRIEN cannot be defined because it is used by more than one SFR */
/* Bitname _FLTOUT cannot be defined because it is used by more than one SFR */
/* Bitname _FLTMD cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL2 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL3 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL4 cannot be defined because it is used by more than one SFR */
/* Bitname _DCB0 cannot be defined because it is used by more than one SFR */
/* Bitname _DCB1 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTMODE cannot be defined because it is used by more than one SFR */

/* OC2CON1 */
/* Bitname _OCM cannot be defined because it is used by more than one SFR */
/* Bitname _TRIGMODE cannot be defined because it is used by more than one SFR */
/* Bitname _OCFLT cannot be defined because it is used by more than one SFR */
/* Bitname _ENFLT cannot be defined because it is used by more than one SFR */
/* Bitname _OCTSEL cannot be defined because it is used by more than one SFR */
/* Bitname _OCSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _OCM0 cannot be defined because it is used by more than one SFR */
/* Bitname _OCM1 cannot be defined because it is used by more than one SFR */
/* Bitname _OCM2 cannot be defined because it is used by more than one SFR */
/* Bitname _OCFLT0 cannot be defined because it is used by more than one SFR */
/* Bitname _OCFLT1 cannot be defined because it is used by more than one SFR */
/* Bitname _OCFLT2 cannot be defined because it is used by more than one SFR */
/* Bitname _ENFLT0 cannot be defined because it is used by more than one SFR */
/* Bitname _ENFLT1 cannot be defined because it is used by more than one SFR */
/* Bitname _ENFLT2 cannot be defined because it is used by more than one SFR */
/* Bitname _OCTSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _OCTSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _OCTSEL2 cannot be defined because it is used by more than one SFR */

/* OC2CON2 */
/* Bitname _SYNCSEL cannot be defined because it is used by more than one SFR */
/* Bitname _OCTRIS cannot be defined because it is used by more than one SFR */
/* Bitname _TRIGSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _OCTRIG cannot be defined because it is used by more than one SFR */
/* Bitname _OC32 cannot be defined because it is used by more than one SFR */
/* Bitname _DCB cannot be defined because it is used by more than one SFR */
/* Bitname _OCINV cannot be defined because it is used by more than one SFR */
/* Bitname _FLTTRIEN cannot be defined because it is used by more than one SFR */
/* Bitname _FLTOUT cannot be defined because it is used by more than one SFR */
/* Bitname _FLTMD cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL2 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL3 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL4 cannot be defined because it is used by more than one SFR */
/* Bitname _DCB0 cannot be defined because it is used by more than one SFR */
/* Bitname _DCB1 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTMODE cannot be defined because it is used by more than one SFR */

/* OC3CON1 */
/* Bitname _OCM cannot be defined because it is used by more than one SFR */
/* Bitname _TRIGMODE cannot be defined because it is used by more than one SFR */
/* Bitname _OCFLT cannot be defined because it is used by more than one SFR */
/* Bitname _ENFLT cannot be defined because it is used by more than one SFR */
/* Bitname _OCTSEL cannot be defined because it is used by more than one SFR */
/* Bitname _OCSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _OCM0 cannot be defined because it is used by more than one SFR */
/* Bitname _OCM1 cannot be defined because it is used by more than one SFR */
/* Bitname _OCM2 cannot be defined because it is used by more than one SFR */
/* Bitname _OCFLT0 cannot be defined because it is used by more than one SFR */
/* Bitname _OCFLT1 cannot be defined because it is used by more than one SFR */
/* Bitname _OCFLT2 cannot be defined because it is used by more than one SFR */
/* Bitname _ENFLT0 cannot be defined because it is used by more than one SFR */
/* Bitname _ENFLT1 cannot be defined because it is used by more than one SFR */
/* Bitname _ENFLT2 cannot be defined because it is used by more than one SFR */
/* Bitname _OCTSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _OCTSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _OCTSEL2 cannot be defined because it is used by more than one SFR */

/* OC3CON2 */
/* Bitname _SYNCSEL cannot be defined because it is used by more than one SFR */
/* Bitname _OCTRIS cannot be defined because it is used by more than one SFR */
/* Bitname _TRIGSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _OCTRIG cannot be defined because it is used by more than one SFR */
/* Bitname _OC32 cannot be defined because it is used by more than one SFR */
/* Bitname _DCB cannot be defined because it is used by more than one SFR */
/* Bitname _OCINV cannot be defined because it is used by more than one SFR */
/* Bitname _FLTTRIEN cannot be defined because it is used by more than one SFR */
/* Bitname _FLTOUT cannot be defined because it is used by more than one SFR */
/* Bitname _FLTMD cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL2 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL3 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL4 cannot be defined because it is used by more than one SFR */
/* Bitname _DCB0 cannot be defined because it is used by more than one SFR */
/* Bitname _DCB1 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTMODE cannot be defined because it is used by more than one SFR */

/* OC4CON1 */
/* Bitname _OCM cannot be defined because it is used by more than one SFR */
/* Bitname _TRIGMODE cannot be defined because it is used by more than one SFR */
/* Bitname _OCFLT cannot be defined because it is used by more than one SFR */
/* Bitname _ENFLT cannot be defined because it is used by more than one SFR */
/* Bitname _OCTSEL cannot be defined because it is used by more than one SFR */
/* Bitname _OCSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _OCM0 cannot be defined because it is used by more than one SFR */
/* Bitname _OCM1 cannot be defined because it is used by more than one SFR */
/* Bitname _OCM2 cannot be defined because it is used by more than one SFR */
/* Bitname _OCFLT0 cannot be defined because it is used by more than one SFR */
/* Bitname _OCFLT1 cannot be defined because it is used by more than one SFR */
/* Bitname _OCFLT2 cannot be defined because it is used by more than one SFR */
/* Bitname _ENFLT0 cannot be defined because it is used by more than one SFR */
/* Bitname _ENFLT1 cannot be defined because it is used by more than one SFR */
/* Bitname _ENFLT2 cannot be defined because it is used by more than one SFR */
/* Bitname _OCTSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _OCTSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _OCTSEL2 cannot be defined because it is used by more than one SFR */

/* OC4CON2 */
/* Bitname _SYNCSEL cannot be defined because it is used by more than one SFR */
/* Bitname _OCTRIS cannot be defined because it is used by more than one SFR */
/* Bitname _TRIGSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _OCTRIG cannot be defined because it is used by more than one SFR */
/* Bitname _OC32 cannot be defined because it is used by more than one SFR */
/* Bitname _DCB cannot be defined because it is used by more than one SFR */
/* Bitname _OCINV cannot be defined because it is used by more than one SFR */
/* Bitname _FLTTRIEN cannot be defined because it is used by more than one SFR */
/* Bitname _FLTOUT cannot be defined because it is used by more than one SFR */
/* Bitname _FLTMD cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL2 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL3 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL4 cannot be defined because it is used by more than one SFR */
/* Bitname _DCB0 cannot be defined because it is used by more than one SFR */
/* Bitname _DCB1 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTMODE cannot be defined because it is used by more than one SFR */

/* OC5CON1 */
/* Bitname _OCM cannot be defined because it is used by more than one SFR */
/* Bitname _TRIGMODE cannot be defined because it is used by more than one SFR */
/* Bitname _OCFLT cannot be defined because it is used by more than one SFR */
/* Bitname _ENFLT cannot be defined because it is used by more than one SFR */
/* Bitname _OCTSEL cannot be defined because it is used by more than one SFR */
/* Bitname _OCSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _OCM0 cannot be defined because it is used by more than one SFR */
/* Bitname _OCM1 cannot be defined because it is used by more than one SFR */
/* Bitname _OCM2 cannot be defined because it is used by more than one SFR */
/* Bitname _OCFLT0 cannot be defined because it is used by more than one SFR */
/* Bitname _OCFLT1 cannot be defined because it is used by more than one SFR */
/* Bitname _OCFLT2 cannot be defined because it is used by more than one SFR */
/* Bitname _ENFLT0 cannot be defined because it is used by more than one SFR */
/* Bitname _ENFLT1 cannot be defined because it is used by more than one SFR */
/* Bitname _ENFLT2 cannot be defined because it is used by more than one SFR */
/* Bitname _OCTSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _OCTSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _OCTSEL2 cannot be defined because it is used by more than one SFR */

/* OC5CON2 */
/* Bitname _SYNCSEL cannot be defined because it is used by more than one SFR */
/* Bitname _OCTRIS cannot be defined because it is used by more than one SFR */
/* Bitname _TRIGSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _OCTRIG cannot be defined because it is used by more than one SFR */
/* Bitname _OC32 cannot be defined because it is used by more than one SFR */
/* Bitname _DCB cannot be defined because it is used by more than one SFR */
/* Bitname _OCINV cannot be defined because it is used by more than one SFR */
/* Bitname _FLTTRIEN cannot be defined because it is used by more than one SFR */
/* Bitname _FLTOUT cannot be defined because it is used by more than one SFR */
/* Bitname _FLTMD cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL2 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL3 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL4 cannot be defined because it is used by more than one SFR */
/* Bitname _DCB0 cannot be defined because it is used by more than one SFR */
/* Bitname _DCB1 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTMODE cannot be defined because it is used by more than one SFR */

/* OC6CON1 */
/* Bitname _OCM cannot be defined because it is used by more than one SFR */
/* Bitname _TRIGMODE cannot be defined because it is used by more than one SFR */
/* Bitname _OCFLT cannot be defined because it is used by more than one SFR */
/* Bitname _ENFLT cannot be defined because it is used by more than one SFR */
/* Bitname _OCTSEL cannot be defined because it is used by more than one SFR */
/* Bitname _OCSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _OCM0 cannot be defined because it is used by more than one SFR */
/* Bitname _OCM1 cannot be defined because it is used by more than one SFR */
/* Bitname _OCM2 cannot be defined because it is used by more than one SFR */
/* Bitname _OCFLT0 cannot be defined because it is used by more than one SFR */
/* Bitname _OCFLT1 cannot be defined because it is used by more than one SFR */
/* Bitname _OCFLT2 cannot be defined because it is used by more than one SFR */
/* Bitname _ENFLT0 cannot be defined because it is used by more than one SFR */
/* Bitname _ENFLT1 cannot be defined because it is used by more than one SFR */
/* Bitname _ENFLT2 cannot be defined because it is used by more than one SFR */
/* Bitname _OCTSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _OCTSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _OCTSEL2 cannot be defined because it is used by more than one SFR */

/* OC6CON2 */
/* Bitname _SYNCSEL cannot be defined because it is used by more than one SFR */
/* Bitname _OCTRIS cannot be defined because it is used by more than one SFR */
/* Bitname _TRIGSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _OCTRIG cannot be defined because it is used by more than one SFR */
/* Bitname _OC32 cannot be defined because it is used by more than one SFR */
/* Bitname _DCB cannot be defined because it is used by more than one SFR */
/* Bitname _OCINV cannot be defined because it is used by more than one SFR */
/* Bitname _FLTTRIEN cannot be defined because it is used by more than one SFR */
/* Bitname _FLTOUT cannot be defined because it is used by more than one SFR */
/* Bitname _FLTMD cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL2 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL3 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL4 cannot be defined because it is used by more than one SFR */
/* Bitname _DCB0 cannot be defined because it is used by more than one SFR */
/* Bitname _DCB1 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTMODE cannot be defined because it is used by more than one SFR */

/* OC7CON1 */
/* Bitname _OCM cannot be defined because it is used by more than one SFR */
/* Bitname _TRIGMODE cannot be defined because it is used by more than one SFR */
/* Bitname _OCFLT cannot be defined because it is used by more than one SFR */
/* Bitname _ENFLT cannot be defined because it is used by more than one SFR */
/* Bitname _OCTSEL cannot be defined because it is used by more than one SFR */
/* Bitname _OCSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _OCM0 cannot be defined because it is used by more than one SFR */
/* Bitname _OCM1 cannot be defined because it is used by more than one SFR */
/* Bitname _OCM2 cannot be defined because it is used by more than one SFR */
/* Bitname _OCFLT0 cannot be defined because it is used by more than one SFR */
/* Bitname _OCFLT1 cannot be defined because it is used by more than one SFR */
/* Bitname _OCFLT2 cannot be defined because it is used by more than one SFR */
/* Bitname _ENFLT0 cannot be defined because it is used by more than one SFR */
/* Bitname _ENFLT1 cannot be defined because it is used by more than one SFR */
/* Bitname _ENFLT2 cannot be defined because it is used by more than one SFR */
/* Bitname _OCTSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _OCTSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _OCTSEL2 cannot be defined because it is used by more than one SFR */

/* OC7CON2 */
/* Bitname _SYNCSEL cannot be defined because it is used by more than one SFR */
/* Bitname _OCTRIS cannot be defined because it is used by more than one SFR */
/* Bitname _TRIGSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _OCTRIG cannot be defined because it is used by more than one SFR */
/* Bitname _OC32 cannot be defined because it is used by more than one SFR */
/* Bitname _DCB cannot be defined because it is used by more than one SFR */
/* Bitname _OCINV cannot be defined because it is used by more than one SFR */
/* Bitname _FLTTRIEN cannot be defined because it is used by more than one SFR */
/* Bitname _FLTOUT cannot be defined because it is used by more than one SFR */
/* Bitname _FLTMD cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL2 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL3 cannot be defined because it is used by more than one SFR */
/* Bitname _SYNCSEL4 cannot be defined because it is used by more than one SFR */
/* Bitname _DCB0 cannot be defined because it is used by more than one SFR */
/* Bitname _DCB1 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTMODE cannot be defined because it is used by more than one SFR */

/* I2C1CON */
#define _SEN I2C1CONbits.SEN
#define _RSEN I2C1CONbits.RSEN
#define _PEN I2C1CONbits.PEN
#define _RCEN I2C1CONbits.RCEN
#define _ACKEN I2C1CONbits.ACKEN
#define _ACKDT I2C1CONbits.ACKDT
#define _STREN I2C1CONbits.STREN
#define _GCEN I2C1CONbits.GCEN
#define _SMEN I2C1CONbits.SMEN
#define _DISSLW I2C1CONbits.DISSLW
#define _A10M I2C1CONbits.A10M
#define _IPMIEN I2C1CONbits.IPMIEN
#define _SCLREL I2C1CONbits.SCLREL
#define _I2CSIDL I2C1CONbits.I2CSIDL
#define _I2CEN I2C1CONbits.I2CEN

/* I2C1STAT */
#define _TBF I2C1STATbits.TBF
#define _RBF I2C1STATbits.RBF
#define _R_NOT_W I2C1STATbits.R_NOT_W
#define _S I2C1STATbits.S
#define _P I2C1STATbits.P
#define _D_NOT_A I2C1STATbits.D_NOT_A
#define _I2COV I2C1STATbits.I2COV
#define _IWCOL I2C1STATbits.IWCOL
#define _ADD10 I2C1STATbits.ADD10
#define _GCSTAT I2C1STATbits.GCSTAT
#define _BCL I2C1STATbits.BCL
#define _TRSTAT I2C1STATbits.TRSTAT
#define _ACKSTAT I2C1STATbits.ACKSTAT
#define _R_W I2C1STATbits.R_W
#define _D_A I2C1STATbits.D_A

/* I2C2CON */
/* Bitname _SEN cannot be defined because it is used by more than one SFR */
/* Bitname _RSEN cannot be defined because it is used by more than one SFR */
/* Bitname _PEN cannot be defined because it is used by more than one SFR */
/* Bitname _RCEN cannot be defined because it is used by more than one SFR */
/* Bitname _ACKEN cannot be defined because it is used by more than one SFR */
/* Bitname _ACKDT cannot be defined because it is used by more than one SFR */
/* Bitname _STREN cannot be defined because it is used by more than one SFR */
/* Bitname _GCEN cannot be defined because it is used by more than one SFR */
/* Bitname _SMEN cannot be defined because it is used by more than one SFR */
/* Bitname _DISSLW cannot be defined because it is used by more than one SFR */
/* Bitname _A10M cannot be defined because it is used by more than one SFR */
/* Bitname _IPMIEN cannot be defined because it is used by more than one SFR */
/* Bitname _SCLREL cannot be defined because it is used by more than one SFR */
/* Bitname _I2CSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _I2CEN cannot be defined because it is used by more than one SFR */

/* I2C2STAT */
/* Bitname _TBF cannot be defined because it is used by more than one SFR */
/* Bitname _RBF cannot be defined because it is used by more than one SFR */
/* Bitname _R_NOT_W cannot be defined because it is used by more than one SFR */
/* Bitname _S cannot be defined because it is used by more than one SFR */
/* Bitname _P cannot be defined because it is used by more than one SFR */
/* Bitname _D_NOT_A cannot be defined because it is used by more than one SFR */
/* Bitname _I2COV cannot be defined because it is used by more than one SFR */
/* Bitname _IWCOL cannot be defined because it is used by more than one SFR */
/* Bitname _ADD10 cannot be defined because it is used by more than one SFR */
/* Bitname _GCSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _BCL cannot be defined because it is used by more than one SFR */
/* Bitname _TRSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _ACKSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _R_W cannot be defined because it is used by more than one SFR */
/* Bitname _D_A cannot be defined because it is used by more than one SFR */

/* U1MODE */
/* Bitname _STSEL cannot be defined because it is used by more than one SFR */
/* Bitname _PDSEL cannot be defined because it is used by more than one SFR */
/* Bitname _BRGH cannot be defined because it is used by more than one SFR */
/* Bitname _RXINV cannot be defined because it is used by more than one SFR */
/* Bitname _ABAUD cannot be defined because it is used by more than one SFR */
/* Bitname _LPBACK cannot be defined because it is used by more than one SFR */
/* Bitname _WAKE cannot be defined because it is used by more than one SFR */
/* Bitname _UEN cannot be defined because it is used by more than one SFR */
/* Bitname _RTSMD cannot be defined because it is used by more than one SFR */
/* Bitname _IREN cannot be defined because it is used by more than one SFR */
/* Bitname _USIDL cannot be defined because it is used by more than one SFR */
/* Bitname _UARTEN cannot be defined because it is used by more than one SFR */
/* Bitname _PDSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _PDSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _UEN0 cannot be defined because it is used by more than one SFR */
/* Bitname _UEN1 cannot be defined because it is used by more than one SFR */

/* U1STA */
/* Bitname _URXDA cannot be defined because it is used by more than one SFR */
/* Bitname _OERR cannot be defined because it is used by more than one SFR */
/* Bitname _FERR cannot be defined because it is used by more than one SFR */
/* Bitname _PERR cannot be defined because it is used by more than one SFR */
/* Bitname _RIDLE cannot be defined because it is used by more than one SFR */
/* Bitname _ADDEN cannot be defined because it is used by more than one SFR */
/* Bitname _URXISEL cannot be defined because it is used by more than one SFR */
/* Bitname _TRMT cannot be defined because it is used by more than one SFR */
/* Bitname _UTXBF cannot be defined because it is used by more than one SFR */
/* Bitname _UTXEN cannot be defined because it is used by more than one SFR */
/* Bitname _UTXBRK cannot be defined because it is used by more than one SFR */
/* Bitname _UTXISEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXINV cannot be defined because it is used by more than one SFR */
/* Bitname _UTXISEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _URXISEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _URXISEL1 cannot be defined because it is used by more than one SFR */

/* U1TXREG */
/* Bitname _UTXREG0 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG1 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG2 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG3 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG4 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG5 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG6 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG7 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG8 cannot be defined because it is used by more than one SFR */

/* U1RXREG */
/* Bitname _URXREG0 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG1 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG2 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG3 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG4 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG5 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG6 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG7 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG8 cannot be defined because it is used by more than one SFR */

/* U2MODE */
/* Bitname _STSEL cannot be defined because it is used by more than one SFR */
/* Bitname _PDSEL cannot be defined because it is used by more than one SFR */
/* Bitname _BRGH cannot be defined because it is used by more than one SFR */
/* Bitname _RXINV cannot be defined because it is used by more than one SFR */
/* Bitname _ABAUD cannot be defined because it is used by more than one SFR */
/* Bitname _LPBACK cannot be defined because it is used by more than one SFR */
/* Bitname _WAKE cannot be defined because it is used by more than one SFR */
/* Bitname _UEN cannot be defined because it is used by more than one SFR */
/* Bitname _RTSMD cannot be defined because it is used by more than one SFR */
/* Bitname _IREN cannot be defined because it is used by more than one SFR */
/* Bitname _USIDL cannot be defined because it is used by more than one SFR */
/* Bitname _UARTEN cannot be defined because it is used by more than one SFR */
/* Bitname _PDSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _PDSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _UEN0 cannot be defined because it is used by more than one SFR */
/* Bitname _UEN1 cannot be defined because it is used by more than one SFR */

/* U2STA */
/* Bitname _URXDA cannot be defined because it is used by more than one SFR */
/* Bitname _OERR cannot be defined because it is used by more than one SFR */
/* Bitname _FERR cannot be defined because it is used by more than one SFR */
/* Bitname _PERR cannot be defined because it is used by more than one SFR */
/* Bitname _RIDLE cannot be defined because it is used by more than one SFR */
/* Bitname _ADDEN cannot be defined because it is used by more than one SFR */
/* Bitname _URXISEL cannot be defined because it is used by more than one SFR */
/* Bitname _TRMT cannot be defined because it is used by more than one SFR */
/* Bitname _UTXBF cannot be defined because it is used by more than one SFR */
/* Bitname _UTXEN cannot be defined because it is used by more than one SFR */
/* Bitname _UTXBRK cannot be defined because it is used by more than one SFR */
/* Bitname _UTXISEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXINV cannot be defined because it is used by more than one SFR */
/* Bitname _UTXISEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _URXISEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _URXISEL1 cannot be defined because it is used by more than one SFR */

/* U2TXREG */
/* Bitname _UTXREG0 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG1 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG2 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG3 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG4 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG5 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG6 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG7 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG8 cannot be defined because it is used by more than one SFR */

/* U2RXREG */
/* Bitname _URXREG0 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG1 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG2 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG3 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG4 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG5 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG6 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG7 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG8 cannot be defined because it is used by more than one SFR */

/* SPI1STAT */
#define _SPIRBF SPI1STATbits.SPIRBF
#define _SPITBF SPI1STATbits.SPITBF
#define _SISEL SPI1STATbits.SISEL
#define _SRXMPT SPI1STATbits.SRXMPT
#define _SPIROV SPI1STATbits.SPIROV
#define _SRMPT SPI1STATbits.SRMPT
#define _SPIBEC SPI1STATbits.SPIBEC
#define _SPISIDL SPI1STATbits.SPISIDL
#define _SPIEN SPI1STATbits.SPIEN
#define _SISEL0 SPI1STATbits.SISEL0
#define _SISEL1 SPI1STATbits.SISEL1
#define _SISEL2 SPI1STATbits.SISEL2
#define _SPIBEC0 SPI1STATbits.SPIBEC0
#define _SPIBEC1 SPI1STATbits.SPIBEC1
#define _SPIBEC2 SPI1STATbits.SPIBEC2

/* SPI1CON1 */
#define _PPRE SPI1CON1bits.PPRE
#define _SPRE SPI1CON1bits.SPRE
#define _MSTEN SPI1CON1bits.MSTEN
#define _CKP SPI1CON1bits.CKP
#define _SSEN SPI1CON1bits.SSEN
#define _CKE SPI1CON1bits.CKE
#define _SMP SPI1CON1bits.SMP
#define _MODE16 SPI1CON1bits.MODE16
#define _DISSDO SPI1CON1bits.DISSDO
#define _DISSCK SPI1CON1bits.DISSCK
#define _PPRE0 SPI1CON1bits.PPRE0
#define _PPRE1 SPI1CON1bits.PPRE1
#define _SPRE0 SPI1CON1bits.SPRE0
#define _SPRE1 SPI1CON1bits.SPRE1
#define _SPRE2 SPI1CON1bits.SPRE2

/* SPI1CON2 */
#define _SPIBEN SPI1CON2bits.SPIBEN
#define _SPIFE SPI1CON2bits.SPIFE
#define _SPIFPOL SPI1CON2bits.SPIFPOL
#define _SPIFSD SPI1CON2bits.SPIFSD
#define _FRMEN SPI1CON2bits.FRMEN

/* U3MODE */
/* Bitname _STSEL cannot be defined because it is used by more than one SFR */
/* Bitname _PDSEL cannot be defined because it is used by more than one SFR */
/* Bitname _BRGH cannot be defined because it is used by more than one SFR */
/* Bitname _RXINV cannot be defined because it is used by more than one SFR */
/* Bitname _ABAUD cannot be defined because it is used by more than one SFR */
/* Bitname _LPBACK cannot be defined because it is used by more than one SFR */
/* Bitname _WAKE cannot be defined because it is used by more than one SFR */
/* Bitname _UEN cannot be defined because it is used by more than one SFR */
/* Bitname _RTSMD cannot be defined because it is used by more than one SFR */
/* Bitname _IREN cannot be defined because it is used by more than one SFR */
/* Bitname _USIDL cannot be defined because it is used by more than one SFR */
/* Bitname _UARTEN cannot be defined because it is used by more than one SFR */
/* Bitname _PDSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _PDSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _UEN0 cannot be defined because it is used by more than one SFR */
/* Bitname _UEN1 cannot be defined because it is used by more than one SFR */

/* U3STA */
/* Bitname _URXDA cannot be defined because it is used by more than one SFR */
/* Bitname _OERR cannot be defined because it is used by more than one SFR */
/* Bitname _FERR cannot be defined because it is used by more than one SFR */
/* Bitname _PERR cannot be defined because it is used by more than one SFR */
/* Bitname _RIDLE cannot be defined because it is used by more than one SFR */
/* Bitname _ADDEN cannot be defined because it is used by more than one SFR */
/* Bitname _URXISEL cannot be defined because it is used by more than one SFR */
/* Bitname _TRMT cannot be defined because it is used by more than one SFR */
/* Bitname _UTXBF cannot be defined because it is used by more than one SFR */
/* Bitname _UTXEN cannot be defined because it is used by more than one SFR */
/* Bitname _UTXBRK cannot be defined because it is used by more than one SFR */
/* Bitname _UTXISEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXINV cannot be defined because it is used by more than one SFR */
/* Bitname _UTXISEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _URXISEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _URXISEL1 cannot be defined because it is used by more than one SFR */

/* U3TXREG */
/* Bitname _UTXREG0 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG1 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG2 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG3 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG4 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG5 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG6 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG7 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG8 cannot be defined because it is used by more than one SFR */

/* U3RXREG */
/* Bitname _URXREG0 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG1 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG2 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG3 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG4 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG5 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG6 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG7 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG8 cannot be defined because it is used by more than one SFR */

/* SPI2STAT */
/* Bitname _SPIRBF cannot be defined because it is used by more than one SFR */
/* Bitname _SPITBF cannot be defined because it is used by more than one SFR */
/* Bitname _SISEL cannot be defined because it is used by more than one SFR */
/* Bitname _SRXMPT cannot be defined because it is used by more than one SFR */
/* Bitname _SPIROV cannot be defined because it is used by more than one SFR */
/* Bitname _SRMPT cannot be defined because it is used by more than one SFR */
/* Bitname _SPIBEC cannot be defined because it is used by more than one SFR */
/* Bitname _SPISIDL cannot be defined because it is used by more than one SFR */
/* Bitname _SPIEN cannot be defined because it is used by more than one SFR */
/* Bitname _SISEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _SISEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _SISEL2 cannot be defined because it is used by more than one SFR */
/* Bitname _SPIBEC0 cannot be defined because it is used by more than one SFR */
/* Bitname _SPIBEC1 cannot be defined because it is used by more than one SFR */
/* Bitname _SPIBEC2 cannot be defined because it is used by more than one SFR */

/* SPI2CON1 */
/* Bitname _PPRE cannot be defined because it is used by more than one SFR */
/* Bitname _SPRE cannot be defined because it is used by more than one SFR */
/* Bitname _MSTEN cannot be defined because it is used by more than one SFR */
/* Bitname _CKP cannot be defined because it is used by more than one SFR */
/* Bitname _SSEN cannot be defined because it is used by more than one SFR */
/* Bitname _CKE cannot be defined because it is used by more than one SFR */
/* Bitname _SMP cannot be defined because it is used by more than one SFR */
/* Bitname _MODE16 cannot be defined because it is used by more than one SFR */
/* Bitname _DISSDO cannot be defined because it is used by more than one SFR */
/* Bitname _DISSCK cannot be defined because it is used by more than one SFR */
/* Bitname _PPRE0 cannot be defined because it is used by more than one SFR */
/* Bitname _PPRE1 cannot be defined because it is used by more than one SFR */
/* Bitname _SPRE0 cannot be defined because it is used by more than one SFR */
/* Bitname _SPRE1 cannot be defined because it is used by more than one SFR */
/* Bitname _SPRE2 cannot be defined because it is used by more than one SFR */

/* SPI2CON2 */
/* Bitname _SPIBEN cannot be defined because it is used by more than one SFR */
/* Bitname _SPIFE cannot be defined because it is used by more than one SFR */
/* Bitname _SPIFPOL cannot be defined because it is used by more than one SFR */
/* Bitname _SPIFSD cannot be defined because it is used by more than one SFR */
/* Bitname _FRMEN cannot be defined because it is used by more than one SFR */

/* U4MODE */
/* Bitname _STSEL cannot be defined because it is used by more than one SFR */
/* Bitname _PDSEL cannot be defined because it is used by more than one SFR */
/* Bitname _BRGH cannot be defined because it is used by more than one SFR */
/* Bitname _RXINV cannot be defined because it is used by more than one SFR */
/* Bitname _ABAUD cannot be defined because it is used by more than one SFR */
/* Bitname _LPBACK cannot be defined because it is used by more than one SFR */
/* Bitname _WAKE cannot be defined because it is used by more than one SFR */
/* Bitname _UEN cannot be defined because it is used by more than one SFR */
/* Bitname _RTSMD cannot be defined because it is used by more than one SFR */
/* Bitname _IREN cannot be defined because it is used by more than one SFR */
/* Bitname _USIDL cannot be defined because it is used by more than one SFR */
/* Bitname _UARTEN cannot be defined because it is used by more than one SFR */
/* Bitname _PDSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _PDSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _UEN0 cannot be defined because it is used by more than one SFR */
/* Bitname _UEN1 cannot be defined because it is used by more than one SFR */

/* U4STA */
/* Bitname _URXDA cannot be defined because it is used by more than one SFR */
/* Bitname _OERR cannot be defined because it is used by more than one SFR */
/* Bitname _FERR cannot be defined because it is used by more than one SFR */
/* Bitname _PERR cannot be defined because it is used by more than one SFR */
/* Bitname _RIDLE cannot be defined because it is used by more than one SFR */
/* Bitname _ADDEN cannot be defined because it is used by more than one SFR */
/* Bitname _URXISEL cannot be defined because it is used by more than one SFR */
/* Bitname _TRMT cannot be defined because it is used by more than one SFR */
/* Bitname _UTXBF cannot be defined because it is used by more than one SFR */
/* Bitname _UTXEN cannot be defined because it is used by more than one SFR */
/* Bitname _UTXBRK cannot be defined because it is used by more than one SFR */
/* Bitname _UTXISEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXINV cannot be defined because it is used by more than one SFR */
/* Bitname _UTXISEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _URXISEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _URXISEL1 cannot be defined because it is used by more than one SFR */

/* U4TXREG */
/* Bitname _UTXREG0 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG1 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG2 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG3 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG4 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG5 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG6 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG7 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG8 cannot be defined because it is used by more than one SFR */

/* U4RXREG */
/* Bitname _URXREG0 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG1 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG2 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG3 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG4 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG5 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG6 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG7 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG8 cannot be defined because it is used by more than one SFR */

/* TRISA */
#define _TRISA9 TRISAbits.TRISA9
#define _TRISA10 TRISAbits.TRISA10
#define _TRISA14 TRISAbits.TRISA14
#define _TRISA15 TRISAbits.TRISA15

/* PORTA */
#define _RA9 PORTAbits.RA9
#define _RA10 PORTAbits.RA10
#define _RA14 PORTAbits.RA14
#define _RA15 PORTAbits.RA15

/* LATA */
#define _LATA9 LATAbits.LATA9
#define _LATA10 LATAbits.LATA10
#define _LATA14 LATAbits.LATA14
#define _LATA15 LATAbits.LATA15

/* ODCA */
#define _ODA9 ODCAbits.ODA9
#define _ODA10 ODCAbits.ODA10
#define _ODA14 ODCAbits.ODA14
#define _ODA15 ODCAbits.ODA15

/* TRISB */
#define _TRISB0 TRISBbits.TRISB0
#define _TRISB1 TRISBbits.TRISB1
#define _TRISB2 TRISBbits.TRISB2
#define _TRISB3 TRISBbits.TRISB3
#define _TRISB4 TRISBbits.TRISB4
#define _TRISB5 TRISBbits.TRISB5
#define _TRISB6 TRISBbits.TRISB6
#define _TRISB7 TRISBbits.TRISB7
#define _TRISB8 TRISBbits.TRISB8
#define _TRISB9 TRISBbits.TRISB9
#define _TRISB10 TRISBbits.TRISB10
#define _TRISB11 TRISBbits.TRISB11
#define _TRISB12 TRISBbits.TRISB12
#define _TRISB13 TRISBbits.TRISB13
#define _TRISB14 TRISBbits.TRISB14
#define _TRISB15 TRISBbits.TRISB15

/* PORTB */
#define _RB0 PORTBbits.RB0
#define _RB1 PORTBbits.RB1
#define _RB2 PORTBbits.RB2
#define _RB3 PORTBbits.RB3
#define _RB4 PORTBbits.RB4
#define _RB5 PORTBbits.RB5
#define _RB6 PORTBbits.RB6
#define _RB7 PORTBbits.RB7
#define _RB8 PORTBbits.RB8
#define _RB9 PORTBbits.RB9
#define _RB10 PORTBbits.RB10
#define _RB11 PORTBbits.RB11
#define _RB12 PORTBbits.RB12
#define _RB13 PORTBbits.RB13
#define _RB14 PORTBbits.RB14
#define _RB15 PORTBbits.RB15

/* LATB */
#define _LATB0 LATBbits.LATB0
#define _LATB1 LATBbits.LATB1
#define _LATB2 LATBbits.LATB2
#define _LATB3 LATBbits.LATB3
#define _LATB4 LATBbits.LATB4
#define _LATB5 LATBbits.LATB5
#define _LATB6 LATBbits.LATB6
#define _LATB7 LATBbits.LATB7
#define _LATB8 LATBbits.LATB8
#define _LATB9 LATBbits.LATB9
#define _LATB10 LATBbits.LATB10
#define _LATB11 LATBbits.LATB11
#define _LATB12 LATBbits.LATB12
#define _LATB13 LATBbits.LATB13
#define _LATB14 LATBbits.LATB14
#define _LATB15 LATBbits.LATB15

/* ODCB */
#define _ODB0 ODCBbits.ODB0
#define _ODB1 ODCBbits.ODB1
#define _ODB2 ODCBbits.ODB2
#define _ODB3 ODCBbits.ODB3
#define _ODB4 ODCBbits.ODB4
#define _ODB5 ODCBbits.ODB5
#define _ODB6 ODCBbits.ODB6
#define _ODB7 ODCBbits.ODB7
#define _ODB8 ODCBbits.ODB8
#define _ODB9 ODCBbits.ODB9
#define _ODB10 ODCBbits.ODB10
#define _ODB11 ODCBbits.ODB11
#define _ODB12 ODCBbits.ODB12
#define _ODB13 ODCBbits.ODB13
#define _ODB14 ODCBbits.ODB14
#define _ODB15 ODCBbits.ODB15

/* TRISC */
#define _TRISC1 TRISCbits.TRISC1
#define _TRISC3 TRISCbits.TRISC3
#define _TRISC12 TRISCbits.TRISC12
#define _TRISC15 TRISCbits.TRISC15

/* PORTC */
#define _RC1 PORTCbits.RC1
#define _RC3 PORTCbits.RC3
#define _RC12 PORTCbits.RC12
#define _RC13 PORTCbits.RC13
#define _RC14 PORTCbits.RC14
#define _RC15 PORTCbits.RC15

/* LATC */
#define _LATC1 LATCbits.LATC1
#define _LATC3 LATCbits.LATC3
#define _LATC12 LATCbits.LATC12
#define _LATC13 LATCbits.LATC13
#define _LATC14 LATCbits.LATC14
#define _LATC15 LATCbits.LATC15

/* ODCC */
#define _ODC1 ODCCbits.ODC1
#define _ODC3 ODCCbits.ODC3
#define _ODC12 ODCCbits.ODC12
#define _ODC13 ODCCbits.ODC13
#define _ODC14 ODCCbits.ODC14
#define _ODC15 ODCCbits.ODC15

/* TRISD */
#define _TRISD0 TRISDbits.TRISD0
#define _TRISD1 TRISDbits.TRISD1
#define _TRISD2 TRISDbits.TRISD2
#define _TRISD3 TRISDbits.TRISD3
#define _TRISD4 TRISDbits.TRISD4
#define _TRISD5 TRISDbits.TRISD5
#define _TRISD6 TRISDbits.TRISD6
#define _TRISD7 TRISDbits.TRISD7
#define _TRISD8 TRISDbits.TRISD8
#define _TRISD9 TRISDbits.TRISD9
#define _TRISD10 TRISDbits.TRISD10
#define _TRISD11 TRISDbits.TRISD11
#define _TRISD12 TRISDbits.TRISD12
#define _TRISD13 TRISDbits.TRISD13
#define _TRISD14 TRISDbits.TRISD14
#define _TRISD15 TRISDbits.TRISD15

/* PORTD */
#define _RD0 PORTDbits.RD0
#define _RD1 PORTDbits.RD1
#define _RD2 PORTDbits.RD2
#define _RD3 PORTDbits.RD3
#define _RD4 PORTDbits.RD4
#define _RD5 PORTDbits.RD5
#define _RD6 PORTDbits.RD6
#define _RD7 PORTDbits.RD7
#define _RD8 PORTDbits.RD8
#define _RD9 PORTDbits.RD9
#define _RD10 PORTDbits.RD10
#define _RD11 PORTDbits.RD11
#define _RD12 PORTDbits.RD12
#define _RD13 PORTDbits.RD13
#define _RD14 PORTDbits.RD14
#define _RD15 PORTDbits.RD15

/* LATD */
#define _LATD0 LATDbits.LATD0
#define _LATD1 LATDbits.LATD1
#define _LATD2 LATDbits.LATD2
#define _LATD3 LATDbits.LATD3
#define _LATD4 LATDbits.LATD4
#define _LATD5 LATDbits.LATD5
#define _LATD6 LATDbits.LATD6
#define _LATD7 LATDbits.LATD7
#define _LATD8 LATDbits.LATD8
#define _LATD9 LATDbits.LATD9
#define _LATD10 LATDbits.LATD10
#define _LATD11 LATDbits.LATD11
#define _LATD12 LATDbits.LATD12
#define _LATD13 LATDbits.LATD13
#define _LATD14 LATDbits.LATD14
#define _LATD15 LATDbits.LATD15

/* ODCD */
#define _ODD0 ODCDbits.ODD0
#define _ODD1 ODCDbits.ODD1
#define _ODD2 ODCDbits.ODD2
#define _ODD3 ODCDbits.ODD3
#define _ODD4 ODCDbits.ODD4
#define _ODD5 ODCDbits.ODD5
#define _ODD6 ODCDbits.ODD6
#define _ODD7 ODCDbits.ODD7
#define _ODD8 ODCDbits.ODD8
#define _ODD9 ODCDbits.ODD9
#define _ODD10 ODCDbits.ODD10
#define _ODD11 ODCDbits.ODD11
#define _ODD12 ODCDbits.ODD12
#define _ODD13 ODCDbits.ODD13
#define _ODD14 ODCDbits.ODD14
#define _ODD15 ODCDbits.ODD15

/* TRISE */
#define _TRISE0 TRISEbits.TRISE0
#define _TRISE1 TRISEbits.TRISE1
#define _TRISE2 TRISEbits.TRISE2
#define _TRISE3 TRISEbits.TRISE3
#define _TRISE4 TRISEbits.TRISE4
#define _TRISE5 TRISEbits.TRISE5
#define _TRISE6 TRISEbits.TRISE6
#define _TRISE7 TRISEbits.TRISE7
#define _TRISE8 TRISEbits.TRISE8
#define _TRISE9 TRISEbits.TRISE9

/* PORTE */
#define _RE0 PORTEbits.RE0
#define _RE1 PORTEbits.RE1
#define _RE2 PORTEbits.RE2
#define _RE3 PORTEbits.RE3
#define _RE4 PORTEbits.RE4
#define _RE5 PORTEbits.RE5
#define _RE6 PORTEbits.RE6
#define _RE7 PORTEbits.RE7
#define _RE8 PORTEbits.RE8
#define _RE9 PORTEbits.RE9

/* LATE */
#define _LATE0 LATEbits.LATE0
#define _LATE1 LATEbits.LATE1
#define _LATE2 LATEbits.LATE2
#define _LATE3 LATEbits.LATE3
#define _LATE4 LATEbits.LATE4
#define _LATE5 LATEbits.LATE5
#define _LATE6 LATEbits.LATE6
#define _LATE7 LATEbits.LATE7
#define _LATE8 LATEbits.LATE8
#define _LATE9 LATEbits.LATE9

/* ODCE */
#define _ODE0 ODCEbits.ODE0
#define _ODE1 ODCEbits.ODE1
#define _ODE2 ODCEbits.ODE2
#define _ODE3 ODCEbits.ODE3
#define _ODE4 ODCEbits.ODE4
#define _ODE5 ODCEbits.ODE5
#define _ODE6 ODCEbits.ODE6
#define _ODE7 ODCEbits.ODE7
#define _ODE8 ODCEbits.ODE8
#define _ODE9 ODCEbits.ODE9

/* TRISF */
#define _TRISF0 TRISFbits.TRISF0
#define _TRISF1 TRISFbits.TRISF1
#define _TRISF2 TRISFbits.TRISF2
#define _TRISF3 TRISFbits.TRISF3
#define _TRISF4 TRISFbits.TRISF4
#define _TRISF5 TRISFbits.TRISF5
#define _TRISF6 TRISFbits.TRISF6
#define _TRISF12 TRISFbits.TRISF12
#define _TRISF13 TRISFbits.TRISF13

/* PORTF */
#define _RF0 PORTFbits.RF0
#define _RF1 PORTFbits.RF1
#define _RF2 PORTFbits.RF2
#define _RF3 PORTFbits.RF3
#define _RF4 PORTFbits.RF4
#define _RF5 PORTFbits.RF5
#define _RF6 PORTFbits.RF6
#define _RF12 PORTFbits.RF12
#define _RF13 PORTFbits.RF13

/* LATF */
#define _LATF0 LATFbits.LATF0
#define _LATF1 LATFbits.LATF1
#define _LATF2 LATFbits.LATF2
#define _LATF3 LATFbits.LATF3
#define _LATF4 LATFbits.LATF4
#define _LATF5 LATFbits.LATF5
#define _LATF6 LATFbits.LATF6
#define _LATF12 LATFbits.LATF12
#define _LATF13 LATFbits.LATF13

/* ODCF */
#define _ODF0 ODCFbits.ODF0
#define _ODF1 ODCFbits.ODF1
#define _ODF2 ODCFbits.ODF2
#define _ODF3 ODCFbits.ODF3
#define _ODF4 ODCFbits.ODF4
#define _ODF5 ODCFbits.ODF5
#define _ODF6 ODCFbits.ODF6
#define _ODF12 ODCFbits.ODF12
#define _ODF13 ODCFbits.ODF13

/* TRISG */
#define _TRISG0 TRISGbits.TRISG0
#define _TRISG1 TRISGbits.TRISG1
#define _TRISG2 TRISGbits.TRISG2
#define _TRISG3 TRISGbits.TRISG3
#define _TRISG6 TRISGbits.TRISG6
#define _TRISG7 TRISGbits.TRISG7
#define _TRISG8 TRISGbits.TRISG8
#define _TRISG9 TRISGbits.TRISG9

/* PORTG */
#define _RG0 PORTGbits.RG0
#define _RG1 PORTGbits.RG1
#define _RG2 PORTGbits.RG2
#define _RG3 PORTGbits.RG3
#define _RG6 PORTGbits.RG6
#define _RG7 PORTGbits.RG7
#define _RG8 PORTGbits.RG8
#define _RG9 PORTGbits.RG9

/* LATG */
#define _LATG0 LATGbits.LATG0
#define _LATG1 LATGbits.LATG1
#define _LATG2 LATGbits.LATG2
#define _LATG3 LATGbits.LATG3
#define _LATG6 LATGbits.LATG6
#define _LATG7 LATGbits.LATG7
#define _LATG8 LATGbits.LATG8
#define _LATG9 LATGbits.LATG9

/* ODCG */
#define _ODG0 ODCGbits.ODG0
#define _ODG1 ODCGbits.ODG1
#define _ODG2 ODCGbits.ODG2
#define _ODG3 ODCGbits.ODG3
#define _ODG6 ODCGbits.ODG6
#define _ODG7 ODCGbits.ODG7
#define _ODG8 ODCGbits.ODG8
#define _ODG9 ODCGbits.ODG9

/* PADCFG1 */
#define _PMPTTL PADCFG1bits.PMPTTL

/* AD1CON1 */
#define _DONE AD1CON1bits.DONE
#define _SAMP AD1CON1bits.SAMP
#define _ASAM AD1CON1bits.ASAM
#define _SSRC AD1CON1bits.SSRC
#define _FORM AD1CON1bits.FORM
#define _MODE12 AD1CON1bits.MODE12
/* Bitname _DMAEN cannot be defined because it is used by more than one SFR */
#define _DMABM AD1CON1bits.DMABM
#define _ADSIDL AD1CON1bits.ADSIDL
#define _ADON AD1CON1bits.ADON
#define _SSRC0 AD1CON1bits.SSRC0
#define _SSRC1 AD1CON1bits.SSRC1
#define _SSRC2 AD1CON1bits.SSRC2
#define _SSRC3 AD1CON1bits.SSRC3
#define _FORM0 AD1CON1bits.FORM0
#define _FORM1 AD1CON1bits.FORM1

/* AD1CON2 */
#define _ALTS AD1CON2bits.ALTS
#define _BUFM AD1CON2bits.BUFM
#define _SMPI AD1CON2bits.SMPI
#define _BUFS AD1CON2bits.BUFS
#define _CSCNA AD1CON2bits.CSCNA
#define _BUFREGEN AD1CON2bits.BUFREGEN
#define _OFFCAL AD1CON2bits.OFFCAL
#define _NVCFG0 AD1CON2bits.NVCFG0
#define _PVCFG AD1CON2bits.PVCFG
#define _SMPI0 AD1CON2bits.SMPI0
#define _SMPI1 AD1CON2bits.SMPI1
#define _SMPI2 AD1CON2bits.SMPI2
#define _SMPI3 AD1CON2bits.SMPI3
#define _SMPI4 AD1CON2bits.SMPI4
#define _PCVFG0 AD1CON2bits.PCVFG0
#define _PCVFG1 AD1CON2bits.PCVFG1

/* AD1CON3 */
#define _ADCS AD1CON3bits.ADCS
#define _SAMC AD1CON3bits.SAMC
#define _PUMPEN AD1CON3bits.PUMPEN
#define _EXTSAM AD1CON3bits.EXTSAM
#define _ADRC AD1CON3bits.ADRC
#define _ADCS0 AD1CON3bits.ADCS0
#define _ADCS1 AD1CON3bits.ADCS1
#define _ADCS2 AD1CON3bits.ADCS2
#define _ADCS3 AD1CON3bits.ADCS3
#define _ADCS4 AD1CON3bits.ADCS4
#define _ADCS5 AD1CON3bits.ADCS5
#define _ADCS6 AD1CON3bits.ADCS6
#define _ADCS7 AD1CON3bits.ADCS7
#define _SAMC0 AD1CON3bits.SAMC0
#define _SAMC1 AD1CON3bits.SAMC1
#define _SAMC2 AD1CON3bits.SAMC2
#define _SAMC3 AD1CON3bits.SAMC3
#define _SAMC4 AD1CON3bits.SAMC4

/* AD1CHS */
#define _CH0SA AD1CHSbits.CH0SA
#define _CH0NA AD1CHSbits.CH0NA
#define _CH0SB AD1CHSbits.CH0SB
#define _CH0NB AD1CHSbits.CH0NB
#define _CH0SA0 AD1CHSbits.CH0SA0
#define _CH0SA1 AD1CHSbits.CH0SA1
#define _CH0SA2 AD1CHSbits.CH0SA2
#define _CH0SA3 AD1CHSbits.CH0SA3
#define _CH0SA4 AD1CHSbits.CH0SA4
#define _CH0NA0 AD1CHSbits.CH0NA0
#define _CH0NA1 AD1CHSbits.CH0NA1
#define _CH0NA2 AD1CHSbits.CH0NA2
#define _CH0SB0 AD1CHSbits.CH0SB0
#define _CH0SB1 AD1CHSbits.CH0SB1
#define _CH0SB2 AD1CHSbits.CH0SB2
#define _CH0SB3 AD1CHSbits.CH0SB3
#define _CH0SB4 AD1CHSbits.CH0SB4
#define _CH0NB0 AD1CHSbits.CH0NB0
#define _CH0NB1 AD1CHSbits.CH0NB1
#define _CH0NB2 AD1CHSbits.CH0NB2

/* AD1CSSH */
#define _CSS16 AD1CSSHbits.CSS16
#define _CSS17 AD1CSSHbits.CSS17
#define _CSS18 AD1CSSHbits.CSS18
#define _CSS19 AD1CSSHbits.CSS19
#define _CSS20 AD1CSSHbits.CSS20
#define _CSS21 AD1CSSHbits.CSS21
#define _CSS22 AD1CSSHbits.CSS22
#define _CSS23 AD1CSSHbits.CSS23
#define _CSS24 AD1CSSHbits.CSS24
#define _CSS25 AD1CSSHbits.CSS25
#define _CSS26 AD1CSSHbits.CSS26
#define _CSS27 AD1CSSHbits.CSS27
#define _CSS28 AD1CSSHbits.CSS28
#define _CSS29 AD1CSSHbits.CSS29
#define _CSS30 AD1CSSHbits.CSS30

/* AD1CSSL */
#define _CSS0 AD1CSSLbits.CSS0
#define _CSS1 AD1CSSLbits.CSS1
#define _CSS2 AD1CSSLbits.CSS2
#define _CSS3 AD1CSSLbits.CSS3
#define _CSS4 AD1CSSLbits.CSS4
#define _CSS5 AD1CSSLbits.CSS5
#define _CSS6 AD1CSSLbits.CSS6
#define _CSS7 AD1CSSLbits.CSS7
#define _CSS8 AD1CSSLbits.CSS8
#define _CSS9 AD1CSSLbits.CSS9
#define _CSS10 AD1CSSLbits.CSS10
#define _CSS11 AD1CSSLbits.CSS11
#define _CSS12 AD1CSSLbits.CSS12
#define _CSS13 AD1CSSLbits.CSS13
#define _CSS14 AD1CSSLbits.CSS14
#define _CSS15 AD1CSSLbits.CSS15

/* AD1CON4 */
#define _DMABL AD1CON4bits.DMABL
#define _DMABL0 AD1CON4bits.DMABL0
#define _DMABL1 AD1CON4bits.DMABL1
#define _DMABL2 AD1CON4bits.DMABL2

/* AD1CON5 */
/* Bitname _CM cannot be defined because it is used by more than one SFR */
#define _WM AD1CON5bits.WM
#define _ASINT AD1CON5bits.ASINT
#define _BGREQ AD1CON5bits.BGREQ
#define _CTMREQ AD1CON5bits.CTMREQ
#define _LPEN AD1CON5bits.LPEN
#define _ASEN AD1CON5bits.ASEN
#define _CM0 AD1CON5bits.CM0
#define _CM1 AD1CON5bits.CM1
#define _WM0 AD1CON5bits.WM0
#define _WM1 AD1CON5bits.WM1
#define _ASINT0 AD1CON5bits.ASINT0
#define _ASINT1 AD1CON5bits.ASINT1

/* AD1CHITL */
#define _CHH0 AD1CHITLbits.CHH0
#define _CHH1 AD1CHITLbits.CHH1
#define _CHH2 AD1CHITLbits.CHH2
#define _CHH3 AD1CHITLbits.CHH3
#define _CHH4 AD1CHITLbits.CHH4
#define _CHH5 AD1CHITLbits.CHH5
#define _CHH6 AD1CHITLbits.CHH6
#define _CHH7 AD1CHITLbits.CHH7
#define _CHH8 AD1CHITLbits.CHH8
#define _CHH9 AD1CHITLbits.CHH9
#define _CHH10 AD1CHITLbits.CHH10
#define _CHH11 AD1CHITLbits.CHH11
#define _CHH12 AD1CHITLbits.CHH12
#define _CHH13 AD1CHITLbits.CHH13
#define _CHH14 AD1CHITLbits.CHH14
#define _CHH15 AD1CHITLbits.CHH15

/* CTMUCON1 */
#define _CTTRIG CTMUCON1bits.CTTRIG
#define _IDISSEN CTMUCON1bits.IDISSEN
#define _EDGSEQEN CTMUCON1bits.EDGSEQEN
#define _EDGEN CTMUCON1bits.EDGEN
#define _TGEN CTMUCON1bits.TGEN
#define _CTMUSIDL CTMUCON1bits.CTMUSIDL
#define _CTMUEN CTMUCON1bits.CTMUEN

/* CTMUCON2 */
#define _EDG2SEL CTMUCON2bits.EDG2SEL
#define _EDG2POL CTMUCON2bits.EDG2POL
#define _EDG2MOD CTMUCON2bits.EDG2MOD
#define _EDG1STAT CTMUCON2bits.EDG1STAT
#define _EDG2STAT CTMUCON2bits.EDG2STAT
#define _EDG1SEL CTMUCON2bits.EDG1SEL
#define _EDG1POL CTMUCON2bits.EDG1POL
#define _EDG1MOD CTMUCON2bits.EDG1MOD
#define _EDG2SEL0 CTMUCON2bits.EDG2SEL0
#define _EDG2SEL1 CTMUCON2bits.EDG2SEL1
#define _EDG2SEL2 CTMUCON2bits.EDG2SEL2
#define _EDG2SEL3 CTMUCON2bits.EDG2SEL3
#define _EDG1SEL0 CTMUCON2bits.EDG1SEL0
#define _EDG1SEL1 CTMUCON2bits.EDG1SEL1
#define _EDG1SEL2 CTMUCON2bits.EDG1SEL2
#define _EDG1SEL3 CTMUCON2bits.EDG1SEL3

/* CTMUICON */
#define _IRNG CTMUICONbits.IRNG
#define _ITRIM CTMUICONbits.ITRIM
#define _IRNG0 CTMUICONbits.IRNG0
#define _IRNG1 CTMUICONbits.IRNG1
#define _ITRIM0 CTMUICONbits.ITRIM0
#define _ITRIM1 CTMUICONbits.ITRIM1
#define _ITRIM2 CTMUICONbits.ITRIM2
#define _ITRIM3 CTMUICONbits.ITRIM3
#define _ITRIM4 CTMUICONbits.ITRIM4
#define _ITRIM5 CTMUICONbits.ITRIM5

/* AD1CTMENH */
#define _CTMEN16 AD1CTMENHbits.CTMEN16
#define _CTMEN17 AD1CTMENHbits.CTMEN17
#define _CTMEN18 AD1CTMENHbits.CTMEN18
#define _CTMEN19 AD1CTMENHbits.CTMEN19
#define _CTMEN20 AD1CTMENHbits.CTMEN20
#define _CTMEN21 AD1CTMENHbits.CTMEN21
#define _CTMEN22 AD1CTMENHbits.CTMEN22
#define _CTMEN23 AD1CTMENHbits.CTMEN23
#define _CTMEN24 AD1CTMENHbits.CTMEN24
#define _CTMEN25 AD1CTMENHbits.CTMEN25
#define _CTMEN26 AD1CTMENHbits.CTMEN26
#define _CTMEN27 AD1CTMENHbits.CTMEN27
#define _CTMEN28 AD1CTMENHbits.CTMEN28
#define _CTMEN29 AD1CTMENHbits.CTMEN29
#define _CTMEN30 AD1CTMENHbits.CTMEN30
#define _CTMEN31 AD1CTMENHbits.CTMEN31

/* AD1CTMENL */
#define _CTMEN0 AD1CTMENLbits.CTMEN0
#define _CTMEN1 AD1CTMENLbits.CTMEN1
#define _CTMEN2 AD1CTMENLbits.CTMEN2
#define _CTMEN3 AD1CTMENLbits.CTMEN3
#define _CTMEN4 AD1CTMENLbits.CTMEN4
#define _CTMEN5 AD1CTMENLbits.CTMEN5
#define _CTMEN6 AD1CTMENLbits.CTMEN6
#define _CTMEN7 AD1CTMENLbits.CTMEN7
#define _CTMEN8 AD1CTMENLbits.CTMEN8
#define _CTMEN9 AD1CTMENLbits.CTMEN9
#define _CTMEN10 AD1CTMENLbits.CTMEN10
#define _CTMEN11 AD1CTMENLbits.CTMEN11
#define _CTMEN12 AD1CTMENLbits.CTMEN12
#define _CTMEN13 AD1CTMENLbits.CTMEN13
#define _CTMEN14 AD1CTMENLbits.CTMEN14
#define _CTMEN15 AD1CTMENLbits.CTMEN15

/* DMACON */
#define _PRSSEL DMACONbits.PRSSEL
/* Bitname _DMAEN cannot be defined because it is used by more than one SFR */

/* DMACH0 */
/* Bitname _CHEN cannot be defined because it is used by more than one SFR */
/* Bitname _BYTE cannot be defined because it is used by more than one SFR */
/* Bitname _TRMODE cannot be defined because it is used by more than one SFR */
/* Bitname _DAMODE cannot be defined because it is used by more than one SFR */
/* Bitname _SAMODE cannot be defined because it is used by more than one SFR */
/* Bitname _CHREQ cannot be defined because it is used by more than one SFR */
/* Bitname _RELOAD cannot be defined because it is used by more than one SFR */
/* Bitname _NULLW cannot be defined because it is used by more than one SFR */
/* Bitname _TRMODE0 cannot be defined because it is used by more than one SFR */
/* Bitname _TRMODE1 cannot be defined because it is used by more than one SFR */
/* Bitname _DAMODE0 cannot be defined because it is used by more than one SFR */
/* Bitname _DAMODE1 cannot be defined because it is used by more than one SFR */
/* Bitname _SAMODE0 cannot be defined because it is used by more than one SFR */
/* Bitname _SAMODE1 cannot be defined because it is used by more than one SFR */

/* DMAINT0 */
/* Bitname _HALFEN cannot be defined because it is used by more than one SFR */
/* Bitname _OVRUNIF cannot be defined because it is used by more than one SFR */
/* Bitname _HALFIF cannot be defined because it is used by more than one SFR */
/* Bitname _DONEIF cannot be defined because it is used by more than one SFR */
/* Bitname _LOWIF cannot be defined because it is used by more than one SFR */
/* Bitname _HIGHIF cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL cannot be defined because it is used by more than one SFR */
/* Bitname _DBUFWF cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL2 cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL3 cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL4 cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL5 cannot be defined because it is used by more than one SFR */

/* DMACH1 */
/* Bitname _CHEN cannot be defined because it is used by more than one SFR */
/* Bitname _BYTE cannot be defined because it is used by more than one SFR */
/* Bitname _TRMODE cannot be defined because it is used by more than one SFR */
/* Bitname _DAMODE cannot be defined because it is used by more than one SFR */
/* Bitname _SAMODE cannot be defined because it is used by more than one SFR */
/* Bitname _CHREQ cannot be defined because it is used by more than one SFR */
/* Bitname _RELOAD cannot be defined because it is used by more than one SFR */
/* Bitname _NULLW cannot be defined because it is used by more than one SFR */
/* Bitname _TRMODE0 cannot be defined because it is used by more than one SFR */
/* Bitname _TRMODE1 cannot be defined because it is used by more than one SFR */
/* Bitname _DAMODE0 cannot be defined because it is used by more than one SFR */
/* Bitname _DAMODE1 cannot be defined because it is used by more than one SFR */
/* Bitname _SAMODE0 cannot be defined because it is used by more than one SFR */
/* Bitname _SAMODE1 cannot be defined because it is used by more than one SFR */

/* DMAINT1 */
/* Bitname _HALFEN cannot be defined because it is used by more than one SFR */
/* Bitname _OVRUNIF cannot be defined because it is used by more than one SFR */
/* Bitname _HALFIF cannot be defined because it is used by more than one SFR */
/* Bitname _DONEIF cannot be defined because it is used by more than one SFR */
/* Bitname _LOWIF cannot be defined because it is used by more than one SFR */
/* Bitname _HIGHIF cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL cannot be defined because it is used by more than one SFR */
/* Bitname _DBUFWF cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL2 cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL3 cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL4 cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL5 cannot be defined because it is used by more than one SFR */

/* DMACH2 */
/* Bitname _CHEN cannot be defined because it is used by more than one SFR */
/* Bitname _BYTE cannot be defined because it is used by more than one SFR */
/* Bitname _TRMODE cannot be defined because it is used by more than one SFR */
/* Bitname _DAMODE cannot be defined because it is used by more than one SFR */
/* Bitname _SAMODE cannot be defined because it is used by more than one SFR */
/* Bitname _CHREQ cannot be defined because it is used by more than one SFR */
/* Bitname _RELOAD cannot be defined because it is used by more than one SFR */
/* Bitname _NULLW cannot be defined because it is used by more than one SFR */
/* Bitname _TRMODE0 cannot be defined because it is used by more than one SFR */
/* Bitname _TRMODE1 cannot be defined because it is used by more than one SFR */
/* Bitname _DAMODE0 cannot be defined because it is used by more than one SFR */
/* Bitname _DAMODE1 cannot be defined because it is used by more than one SFR */
/* Bitname _SAMODE0 cannot be defined because it is used by more than one SFR */
/* Bitname _SAMODE1 cannot be defined because it is used by more than one SFR */

/* DMAINT2 */
/* Bitname _HALFEN cannot be defined because it is used by more than one SFR */
/* Bitname _OVRUNIF cannot be defined because it is used by more than one SFR */
/* Bitname _HALFIF cannot be defined because it is used by more than one SFR */
/* Bitname _DONEIF cannot be defined because it is used by more than one SFR */
/* Bitname _LOWIF cannot be defined because it is used by more than one SFR */
/* Bitname _HIGHIF cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL cannot be defined because it is used by more than one SFR */
/* Bitname _DBUFWF cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL2 cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL3 cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL4 cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL5 cannot be defined because it is used by more than one SFR */

/* DMACH3 */
/* Bitname _CHEN cannot be defined because it is used by more than one SFR */
/* Bitname _BYTE cannot be defined because it is used by more than one SFR */
/* Bitname _TRMODE cannot be defined because it is used by more than one SFR */
/* Bitname _DAMODE cannot be defined because it is used by more than one SFR */
/* Bitname _SAMODE cannot be defined because it is used by more than one SFR */
/* Bitname _CHREQ cannot be defined because it is used by more than one SFR */
/* Bitname _RELOAD cannot be defined because it is used by more than one SFR */
/* Bitname _NULLW cannot be defined because it is used by more than one SFR */
/* Bitname _TRMODE0 cannot be defined because it is used by more than one SFR */
/* Bitname _TRMODE1 cannot be defined because it is used by more than one SFR */
/* Bitname _DAMODE0 cannot be defined because it is used by more than one SFR */
/* Bitname _DAMODE1 cannot be defined because it is used by more than one SFR */
/* Bitname _SAMODE0 cannot be defined because it is used by more than one SFR */
/* Bitname _SAMODE1 cannot be defined because it is used by more than one SFR */

/* DMAINT3 */
/* Bitname _HALFEN cannot be defined because it is used by more than one SFR */
/* Bitname _OVRUNIF cannot be defined because it is used by more than one SFR */
/* Bitname _HALFIF cannot be defined because it is used by more than one SFR */
/* Bitname _DONEIF cannot be defined because it is used by more than one SFR */
/* Bitname _LOWIF cannot be defined because it is used by more than one SFR */
/* Bitname _HIGHIF cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL cannot be defined because it is used by more than one SFR */
/* Bitname _DBUFWF cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL2 cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL3 cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL4 cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL5 cannot be defined because it is used by more than one SFR */

/* DMACH4 */
/* Bitname _CHEN cannot be defined because it is used by more than one SFR */
/* Bitname _BYTE cannot be defined because it is used by more than one SFR */
/* Bitname _TRMODE cannot be defined because it is used by more than one SFR */
/* Bitname _DAMODE cannot be defined because it is used by more than one SFR */
/* Bitname _SAMODE cannot be defined because it is used by more than one SFR */
/* Bitname _CHREQ cannot be defined because it is used by more than one SFR */
/* Bitname _RELOAD cannot be defined because it is used by more than one SFR */
/* Bitname _NULLW cannot be defined because it is used by more than one SFR */
/* Bitname _TRMODE0 cannot be defined because it is used by more than one SFR */
/* Bitname _TRMODE1 cannot be defined because it is used by more than one SFR */
/* Bitname _DAMODE0 cannot be defined because it is used by more than one SFR */
/* Bitname _DAMODE1 cannot be defined because it is used by more than one SFR */
/* Bitname _SAMODE0 cannot be defined because it is used by more than one SFR */
/* Bitname _SAMODE1 cannot be defined because it is used by more than one SFR */

/* DMAINT4 */
/* Bitname _HALFEN cannot be defined because it is used by more than one SFR */
/* Bitname _OVRUNIF cannot be defined because it is used by more than one SFR */
/* Bitname _HALFIF cannot be defined because it is used by more than one SFR */
/* Bitname _DONEIF cannot be defined because it is used by more than one SFR */
/* Bitname _LOWIF cannot be defined because it is used by more than one SFR */
/* Bitname _HIGHIF cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL cannot be defined because it is used by more than one SFR */
/* Bitname _DBUFWF cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL2 cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL3 cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL4 cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL5 cannot be defined because it is used by more than one SFR */

/* DMACH5 */
/* Bitname _CHEN cannot be defined because it is used by more than one SFR */
/* Bitname _BYTE cannot be defined because it is used by more than one SFR */
/* Bitname _TRMODE cannot be defined because it is used by more than one SFR */
/* Bitname _DAMODE cannot be defined because it is used by more than one SFR */
/* Bitname _SAMODE cannot be defined because it is used by more than one SFR */
/* Bitname _CHREQ cannot be defined because it is used by more than one SFR */
/* Bitname _RELOAD cannot be defined because it is used by more than one SFR */
/* Bitname _NULLW cannot be defined because it is used by more than one SFR */
/* Bitname _TRMODE0 cannot be defined because it is used by more than one SFR */
/* Bitname _TRMODE1 cannot be defined because it is used by more than one SFR */
/* Bitname _DAMODE0 cannot be defined because it is used by more than one SFR */
/* Bitname _DAMODE1 cannot be defined because it is used by more than one SFR */
/* Bitname _SAMODE0 cannot be defined because it is used by more than one SFR */
/* Bitname _SAMODE1 cannot be defined because it is used by more than one SFR */

/* DMAINT5 */
/* Bitname _HALFEN cannot be defined because it is used by more than one SFR */
/* Bitname _OVRUNIF cannot be defined because it is used by more than one SFR */
/* Bitname _HALFIF cannot be defined because it is used by more than one SFR */
/* Bitname _DONEIF cannot be defined because it is used by more than one SFR */
/* Bitname _LOWIF cannot be defined because it is used by more than one SFR */
/* Bitname _HIGHIF cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL cannot be defined because it is used by more than one SFR */
/* Bitname _DBUFWF cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL1 cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL2 cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL3 cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL4 cannot be defined because it is used by more than one SFR */
/* Bitname _CHSEL5 cannot be defined because it is used by more than one SFR */

/* ANCFG */
#define _VBGEN ANCFGbits.VBGEN
#define _VBG2EN ANCFGbits.VBG2EN
#define _VBG6EN ANCFGbits.VBG6EN

/* ANSB */
#define _ANSB0 ANSBbits.ANSB0
#define _ANSB1 ANSBbits.ANSB1
#define _ANSB2 ANSBbits.ANSB2
#define _ANSB3 ANSBbits.ANSB3
#define _ANSB4 ANSBbits.ANSB4
#define _ANSB5 ANSBbits.ANSB5
#define _ANSB6 ANSBbits.ANSB6
#define _ANSB7 ANSBbits.ANSB7
#define _ANSB8 ANSBbits.ANSB8
#define _ANSB9 ANSBbits.ANSB9
#define _ANSB10 ANSBbits.ANSB10
#define _ANSB11 ANSBbits.ANSB11
#define _ANSB12 ANSBbits.ANSB12
#define _ANSB13 ANSBbits.ANSB13
#define _ANSB14 ANSBbits.ANSB14
#define _ANSB15 ANSBbits.ANSB15

/* ANSD */
#define _ANSD6 ANSDbits.ANSD6
#define _ANSD7 ANSDbits.ANSD7
#define _ANSD10 ANSDbits.ANSD10
#define _ANSD11 ANSDbits.ANSD11

/* ANSE */
#define _ANSE4 ANSEbits.ANSE4
#define _ANSE5 ANSEbits.ANSE5
#define _ANSE6 ANSEbits.ANSE6
#define _ANSE7 ANSEbits.ANSE7
#define _ANSE9 ANSEbits.ANSE9

/* ANSG */
#define _ANSG6 ANSGbits.ANSG6
#define _ANSG7 ANSGbits.ANSG7
#define _ANSG8 ANSGbits.ANSG8
#define _ANSG9 ANSGbits.ANSG9

/* LCDREG */
#define _CKSEL LCDREGbits.CKSEL
#define _MODE13 LCDREGbits.MODE13
#define _BIAS LCDREGbits.BIAS
#define _CPEN LCDREGbits.CPEN
#define _CKSEL0 LCDREGbits.CKSEL0
#define _CKSEL1 LCDREGbits.CKSEL1
#define _BIAS0 LCDREGbits.BIAS0
#define _BIAS1 LCDREGbits.BIAS1
#define _BIAS2 LCDREGbits.BIAS2

/* LCDREF */
#define _LRLAT LCDREFbits.LRLAT
#define _LRLBP LCDREFbits.LRLBP
#define _LRLAP LCDREFbits.LRLAP
#define _VLCD1PE LCDREFbits.VLCD1PE
#define _VLCD2PE LCDREFbits.VLCD2PE
#define _VLCD3PE LCDREFbits.VLCD3PE
#define _LCDCST LCDREFbits.LCDCST
#define _LCDIRE LCDREFbits.LCDIRE
#define _LRLAT0 LCDREFbits.LRLAT0
#define _LRLAT1 LCDREFbits.LRLAT1
#define _LRLAT2 LCDREFbits.LRLAT2
#define _LRLBP0 LCDREFbits.LRLBP0
#define _LRLBP1 LCDREFbits.LRLBP1
#define _LRLAP0 LCDREFbits.LRLAP0
#define _LRLAP1 LCDREFbits.LRLAP1
#define _LCDCST0 LCDREFbits.LCDCST0
#define _LCDCST1 LCDREFbits.LCDCST1
#define _LCDCST2 LCDREFbits.LCDCST2

/* LCDCON */
#define _LMUX LCDCONbits.LMUX
#define _CS LCDCONbits.CS
#define _WERR LCDCONbits.WERR
#define _SLPEN LCDCONbits.SLPEN
#define _LCDSIDL LCDCONbits.LCDSIDL
#define _LCDEN LCDCONbits.LCDEN
#define _LMUX0 LCDCONbits.LMUX0
#define _LMUX1 LCDCONbits.LMUX1
#define _LMUX2 LCDCONbits.LMUX2
#define _CS0 LCDCONbits.CS0
#define _CS1 LCDCONbits.CS1

/* LCDPS */
#define _LP LCDPSbits.LP
#define _WA LCDPSbits.WA
#define _LCDA LCDPSbits.LCDA
#define _BIASMD LCDPSbits.BIASMD
#define _WFT LCDPSbits.WFT
#define _LP0 LCDPSbits.LP0
#define _LP1 LCDPSbits.LP1
#define _LP2 LCDPSbits.LP2
#define _LP3 LCDPSbits.LP3

/* LCDSE0 */
#define _SE00 LCDSE0bits.SE00
#define _SE01 LCDSE0bits.SE01
#define _SE02 LCDSE0bits.SE02
#define _SE03 LCDSE0bits.SE03
#define _SE04 LCDSE0bits.SE04
#define _SE05 LCDSE0bits.SE05
#define _SE06 LCDSE0bits.SE06
#define _SE07 LCDSE0bits.SE07
#define _SE08 LCDSE0bits.SE08
#define _SE09 LCDSE0bits.SE09
#define _SE10 LCDSE0bits.SE10
#define _SE11 LCDSE0bits.SE11
#define _SE12 LCDSE0bits.SE12
#define _SE13 LCDSE0bits.SE13
#define _SE14 LCDSE0bits.SE14
#define _SE15 LCDSE0bits.SE15

/* LCDSE1 */
#define _SE16 LCDSE1bits.SE16
#define _SE17 LCDSE1bits.SE17
#define _SE18 LCDSE1bits.SE18
#define _SE19 LCDSE1bits.SE19
#define _SE20 LCDSE1bits.SE20
#define _SE21 LCDSE1bits.SE21
#define _SE22 LCDSE1bits.SE22
#define _SE23 LCDSE1bits.SE23
#define _SE24 LCDSE1bits.SE24
#define _SE25 LCDSE1bits.SE25
#define _SE26 LCDSE1bits.SE26
#define _SE27 LCDSE1bits.SE27
#define _SE28 LCDSE1bits.SE28
#define _SE29 LCDSE1bits.SE29
#define _SE30 LCDSE1bits.SE30
#define _SE31 LCDSE1bits.SE31

/* LCDSE2 */
#define _SE32 LCDSE2bits.SE32
#define _SE33 LCDSE2bits.SE33
#define _SE34 LCDSE2bits.SE34
#define _SE35 LCDSE2bits.SE35
#define _SE36 LCDSE2bits.SE36
#define _SE37 LCDSE2bits.SE37
#define _SE38 LCDSE2bits.SE38
#define _SE39 LCDSE2bits.SE39
#define _SE40 LCDSE2bits.SE40
#define _SE41 LCDSE2bits.SE41
#define _SE42 LCDSE2bits.SE42
#define _SE43 LCDSE2bits.SE43
#define _SE44 LCDSE2bits.SE44
#define _SE45 LCDSE2bits.SE45
#define _SE46 LCDSE2bits.SE46
#define _SE47 LCDSE2bits.SE47

/* LCDSE3 */
#define _SE48 LCDSE3bits.SE48
#define _SE50 LCDSE3bits.SE50

/* LCDDATA0 */
#define _S00C0 LCDDATA0bits.S00C0
#define _S01C0 LCDDATA0bits.S01C0
#define _S02C0 LCDDATA0bits.S02C0
#define _S03C0 LCDDATA0bits.S03C0
#define _S04C0 LCDDATA0bits.S04C0
#define _S05C0 LCDDATA0bits.S05C0
#define _S06C0 LCDDATA0bits.S06C0
#define _S07C0 LCDDATA0bits.S07C0
#define _S08C0 LCDDATA0bits.S08C0
#define _S09C0 LCDDATA0bits.S09C0
#define _S10C0 LCDDATA0bits.S10C0
#define _S11C0 LCDDATA0bits.S11C0
#define _S12C0 LCDDATA0bits.S12C0
#define _S13C0 LCDDATA0bits.S13C0
#define _S14C0 LCDDATA0bits.S14C0
#define _S15C0 LCDDATA0bits.S15C0

/* LCDDATA1 */
#define _S16C0 LCDDATA1bits.S16C0
#define _S17C0 LCDDATA1bits.S17C0
#define _S18C0 LCDDATA1bits.S18C0
#define _S19C0 LCDDATA1bits.S19C0
#define _S20C0 LCDDATA1bits.S20C0
#define _S21C0 LCDDATA1bits.S21C0
#define _S22C0 LCDDATA1bits.S22C0
#define _S23C0 LCDDATA1bits.S23C0
#define _S24C0 LCDDATA1bits.S24C0
#define _S25C0 LCDDATA1bits.S25C0
#define _S26C0 LCDDATA1bits.S26C0
#define _S27C0 LCDDATA1bits.S27C0
#define _S28C0 LCDDATA1bits.S28C0
#define _S29C0 LCDDATA1bits.S29C0
#define _S30C0 LCDDATA1bits.S30C0
#define _S31C0 LCDDATA1bits.S31C0

/* LCDDATA2 */
#define _S32C0 LCDDATA2bits.S32C0
#define _S33C0 LCDDATA2bits.S33C0
#define _S34C0 LCDDATA2bits.S34C0
#define _S35C0 LCDDATA2bits.S35C0
#define _S36C0 LCDDATA2bits.S36C0
#define _S37C0 LCDDATA2bits.S37C0
#define _S38C0 LCDDATA2bits.S38C0
#define _S39C0 LCDDATA2bits.S39C0
#define _S40C0 LCDDATA2bits.S40C0
#define _S41C0 LCDDATA2bits.S41C0
#define _S42C0 LCDDATA2bits.S42C0
#define _S43C0 LCDDATA2bits.S43C0
#define _S44C0 LCDDATA2bits.S44C0
#define _S45C0 LCDDATA2bits.S45C0
#define _S46C0 LCDDATA2bits.S46C0
#define _S47C0 LCDDATA2bits.S47C0

/* LCDDATA3 */
#define _S48C0 LCDDATA3bits.S48C0
#define _S50C0 LCDDATA3bits.S50C0

/* LCDDATA4 */
#define _S00C1 LCDDATA4bits.S00C1
#define _S01C1 LCDDATA4bits.S01C1
#define _S02C1 LCDDATA4bits.S02C1
#define _S03C1 LCDDATA4bits.S03C1
#define _S04C1 LCDDATA4bits.S04C1
#define _S05C1 LCDDATA4bits.S05C1
#define _S06C1 LCDDATA4bits.S06C1
#define _S07C1 LCDDATA4bits.S07C1
#define _S08C1 LCDDATA4bits.S08C1
#define _S09C1 LCDDATA4bits.S09C1
#define _S10C1 LCDDATA4bits.S10C1
#define _S11C1 LCDDATA4bits.S11C1
#define _S12C1 LCDDATA4bits.S12C1
#define _S13C1 LCDDATA4bits.S13C1
#define _S14C1 LCDDATA4bits.S14C1
#define _S15C1 LCDDATA4bits.S15C1

/* LCDDATA5 */
#define _S16C1 LCDDATA5bits.S16C1
#define _S17C1 LCDDATA5bits.S17C1
#define _S18C1 LCDDATA5bits.S18C1
#define _S19C1 LCDDATA5bits.S19C1
#define _S20C1 LCDDATA5bits.S20C1
#define _S21C1 LCDDATA5bits.S21C1
#define _S22C1 LCDDATA5bits.S22C1
#define _S23C1 LCDDATA5bits.S23C1
#define _S24C1 LCDDATA5bits.S24C1
#define _S25C1 LCDDATA5bits.S25C1
#define _S26C1 LCDDATA5bits.S26C1
#define _S27C1 LCDDATA5bits.S27C1
#define _S28C1 LCDDATA5bits.S28C1
#define _S29C1 LCDDATA5bits.S29C1
#define _S30C1 LCDDATA5bits.S30C1
#define _S31C1 LCDDATA5bits.S31C1

/* LCDDATA6 */
#define _S32C1 LCDDATA6bits.S32C1
#define _S33C1 LCDDATA6bits.S33C1
#define _S34C1 LCDDATA6bits.S34C1
#define _S35C1 LCDDATA6bits.S35C1
#define _S36C1 LCDDATA6bits.S36C1
#define _S37C1 LCDDATA6bits.S37C1
#define _S38C1 LCDDATA6bits.S38C1
#define _S39C1 LCDDATA6bits.S39C1
#define _S40C1 LCDDATA6bits.S40C1
#define _S41C1 LCDDATA6bits.S41C1
#define _S42C1 LCDDATA6bits.S42C1
#define _S43C1 LCDDATA6bits.S43C1
#define _S44C1 LCDDATA6bits.S44C1
#define _S45C1 LCDDATA6bits.S45C1
#define _S46C1 LCDDATA6bits.S46C1
#define _S47C1 LCDDATA6bits.S47C1

/* LCDDATA7 */
#define _S48C1 LCDDATA7bits.S48C1
#define _S50C1 LCDDATA7bits.S50C1

/* LCDDATA8 */
#define _S00C2 LCDDATA8bits.S00C2
#define _S01C2 LCDDATA8bits.S01C2
#define _S02C2 LCDDATA8bits.S02C2
#define _S03C2 LCDDATA8bits.S03C2
#define _S04C2 LCDDATA8bits.S04C2
#define _S05C2 LCDDATA8bits.S05C2
#define _S06C2 LCDDATA8bits.S06C2
#define _S07C2 LCDDATA8bits.S07C2
#define _S08C2 LCDDATA8bits.S08C2
#define _S09C2 LCDDATA8bits.S09C2
#define _S10C2 LCDDATA8bits.S10C2
#define _S11C2 LCDDATA8bits.S11C2
#define _S12C2 LCDDATA8bits.S12C2
#define _S13C2 LCDDATA8bits.S13C2
#define _S14C2 LCDDATA8bits.S14C2
#define _S15C2 LCDDATA8bits.S15C2

/* LCDDATA9 */
#define _S16C2 LCDDATA9bits.S16C2
#define _S17C2 LCDDATA9bits.S17C2
#define _S18C2 LCDDATA9bits.S18C2
#define _S19C2 LCDDATA9bits.S19C2
#define _S20C2 LCDDATA9bits.S20C2
#define _S21C2 LCDDATA9bits.S21C2
#define _S22C2 LCDDATA9bits.S22C2
#define _S23C2 LCDDATA9bits.S23C2
#define _S24C2 LCDDATA9bits.S24C2
#define _S25C2 LCDDATA9bits.S25C2
#define _S26C2 LCDDATA9bits.S26C2
#define _S27C2 LCDDATA9bits.S27C2
#define _S28C2 LCDDATA9bits.S28C2
#define _S29C2 LCDDATA9bits.S29C2
#define _S30C2 LCDDATA9bits.S30C2
#define _S31C2 LCDDATA9bits.S31C2

/* LCDDATA10 */
#define _S32C2 LCDDATA10bits.S32C2
#define _S33C2 LCDDATA10bits.S33C2
#define _S34C2 LCDDATA10bits.S34C2
#define _S35C2 LCDDATA10bits.S35C2
#define _S36C2 LCDDATA10bits.S36C2
#define _S37C2 LCDDATA10bits.S37C2
#define _S38C2 LCDDATA10bits.S38C2
#define _S39C2 LCDDATA10bits.S39C2
#define _S40C2 LCDDATA10bits.S40C2
#define _S41C2 LCDDATA10bits.S41C2
#define _S42C2 LCDDATA10bits.S42C2
#define _S43C2 LCDDATA10bits.S43C2
#define _S44C2 LCDDATA10bits.S44C2
#define _S45C2 LCDDATA10bits.S45C2
#define _S46C2 LCDDATA10bits.S46C2
#define _S47C2 LCDDATA10bits.S47C2

/* LCDDATA11 */
#define _S48C2 LCDDATA11bits.S48C2
#define _S50C2 LCDDATA11bits.S50C2

/* LCDDATA12 */
#define _S00C3 LCDDATA12bits.S00C3
#define _S01C3 LCDDATA12bits.S01C3
#define _S02C3 LCDDATA12bits.S02C3
#define _S03C3 LCDDATA12bits.S03C3
#define _S04C3 LCDDATA12bits.S04C3
#define _S05C3 LCDDATA12bits.S05C3
#define _S06C3 LCDDATA12bits.S06C3
#define _S07C3 LCDDATA12bits.S07C3
#define _S08C3 LCDDATA12bits.S08C3
#define _S09C3 LCDDATA12bits.S09C3
#define _S10C3 LCDDATA12bits.S10C3
#define _S11C3 LCDDATA12bits.S11C3
#define _S12C3 LCDDATA12bits.S12C3
#define _S13C3 LCDDATA12bits.S13C3
#define _S14C3 LCDDATA12bits.S14C3
#define _S15C3 LCDDATA12bits.S15C3

/* LCDDATA13 */
#define _S16C3 LCDDATA13bits.S16C3
#define _S17C3 LCDDATA13bits.S17C3
#define _S18C3 LCDDATA13bits.S18C3
#define _S19C3 LCDDATA13bits.S19C3
#define _S20C3 LCDDATA13bits.S20C3
#define _S21C3 LCDDATA13bits.S21C3
#define _S22C3 LCDDATA13bits.S22C3
#define _S23C3 LCDDATA13bits.S23C3
#define _S24C3 LCDDATA13bits.S24C3
#define _S25C3 LCDDATA13bits.S25C3
#define _S26C3 LCDDATA13bits.S26C3
#define _S27C3 LCDDATA13bits.S27C3
#define _S28C3 LCDDATA13bits.S28C3
#define _S29C3 LCDDATA13bits.S29C3
#define _S30C3 LCDDATA13bits.S30C3
#define _S31C3 LCDDATA13bits.S31C3

/* LCDDATA14 */
#define _S32C3 LCDDATA14bits.S32C3
#define _S33C3 LCDDATA14bits.S33C3
#define _S34C3 LCDDATA14bits.S34C3
#define _S35C3 LCDDATA14bits.S35C3
#define _S36C3 LCDDATA14bits.S36C3
#define _S37C3 LCDDATA14bits.S37C3
#define _S38C3 LCDDATA14bits.S38C3
#define _S39C3 LCDDATA14bits.S39C3
#define _S40C3 LCDDATA14bits.S40C3
#define _S41C3 LCDDATA14bits.S41C3
#define _S42C3 LCDDATA14bits.S42C3
#define _S43C3 LCDDATA14bits.S43C3
#define _S44C3 LCDDATA14bits.S44C3
#define _S45C3 LCDDATA14bits.S45C3
#define _S46C3 LCDDATA14bits.S46C3
#define _S47C3 LCDDATA14bits.S47C3

/* LCDDATA15 */
#define _S48C3 LCDDATA15bits.S48C3
#define _S50C3 LCDDATA15bits.S50C3

/* LCDDATA16 */
#define _S00C4 LCDDATA16bits.S00C4
#define _S01C4 LCDDATA16bits.S01C4
#define _S02C4 LCDDATA16bits.S02C4
#define _S03C4 LCDDATA16bits.S03C4
#define _S04C4 LCDDATA16bits.S04C4
#define _S05C4 LCDDATA16bits.S05C4
#define _S06C4 LCDDATA16bits.S06C4
#define _S07C4 LCDDATA16bits.S07C4
#define _S08C4 LCDDATA16bits.S08C4
#define _S09C4 LCDDATA16bits.S09C4
#define _S10C4 LCDDATA16bits.S10C4
#define _S11C4 LCDDATA16bits.S11C4
#define _S12C4 LCDDATA16bits.S12C4
#define _S13C4 LCDDATA16bits.S13C4
#define _S14C4 LCDDATA16bits.S14C4
#define _S15C4 LCDDATA16bits.S15C4

/* LCDDATA17 */
#define _S16C4 LCDDATA17bits.S16C4
#define _S17C4 LCDDATA17bits.S17C4
#define _S18C4 LCDDATA17bits.S18C4
#define _S19C4 LCDDATA17bits.S19C4
#define _S20C4 LCDDATA17bits.S20C4
#define _S21C4 LCDDATA17bits.S21C4
#define _S22C4 LCDDATA17bits.S22C4
#define _S23C4 LCDDATA17bits.S23C4
#define _S24C4 LCDDATA17bits.S24C4
#define _S25C4 LCDDATA17bits.S25C4
#define _S26C4 LCDDATA17bits.S26C4
#define _S27C4 LCDDATA17bits.S27C4
#define _S28C4 LCDDATA17bits.S28C4
#define _S29C4 LCDDATA17bits.S29C4
#define _S30C4 LCDDATA17bits.S30C4
#define _S31C4 LCDDATA17bits.S31C4

/* LCDDATA18 */
#define _S32C4 LCDDATA18bits.S32C4
#define _S33C4 LCDDATA18bits.S33C4
#define _S34C4 LCDDATA18bits.S34C4
#define _S35C4 LCDDATA18bits.S35C4
#define _S36C4 LCDDATA18bits.S36C4
#define _S37C4 LCDDATA18bits.S37C4
#define _S38C4 LCDDATA18bits.S38C4
#define _S39C4 LCDDATA18bits.S39C4
#define _S40C4 LCDDATA18bits.S40C4
#define _S41C4 LCDDATA18bits.S41C4
#define _S42C4 LCDDATA18bits.S42C4
#define _S43C4 LCDDATA18bits.S43C4
#define _S44C4 LCDDATA18bits.S44C4
#define _S45C4 LCDDATA18bits.S45C4
#define _S46C4 LCDDATA18bits.S46C4
#define _S47C4 LCDDATA18bits.S47C4

/* LCDDATA19 */
#define _S48C4 LCDDATA19bits.S48C4
#define _S50C4 LCDDATA19bits.S50C4

/* LCDDATA20 */
#define _S00C5 LCDDATA20bits.S00C5
#define _S01C5 LCDDATA20bits.S01C5
#define _S02C5 LCDDATA20bits.S02C5
#define _S03C5 LCDDATA20bits.S03C5
#define _S04C5 LCDDATA20bits.S04C5
#define _S05C5 LCDDATA20bits.S05C5
#define _S06C5 LCDDATA20bits.S06C5
#define _S07C5 LCDDATA20bits.S07C5
#define _S08C5 LCDDATA20bits.S08C5
#define _S09C5 LCDDATA20bits.S09C5
#define _S10C5 LCDDATA20bits.S10C5
#define _S11C5 LCDDATA20bits.S11C5
#define _S12C5 LCDDATA20bits.S12C5
#define _S13C5 LCDDATA20bits.S13C5
#define _S14C5 LCDDATA20bits.S14C5
#define _S15C5 LCDDATA20bits.S15C5

/* LCDDATA21 */
#define _S16C5 LCDDATA21bits.S16C5
#define _S17C5 LCDDATA21bits.S17C5
#define _S18C5 LCDDATA21bits.S18C5
#define _S19C5 LCDDATA21bits.S19C5
#define _S20C5 LCDDATA21bits.S20C5
#define _S21C5 LCDDATA21bits.S21C5
#define _S22C5 LCDDATA21bits.S22C5
#define _S23C5 LCDDATA21bits.S23C5
#define _S24C5 LCDDATA21bits.S24C5
#define _S25C5 LCDDATA21bits.S25C5
#define _S26C5 LCDDATA21bits.S26C5
#define _S27C5 LCDDATA21bits.S27C5
#define _S28C5 LCDDATA21bits.S28C5
#define _S29C5 LCDDATA21bits.S29C5
#define _S30C5 LCDDATA21bits.S30C5
#define _S31C5 LCDDATA21bits.S31C5

/* LCDDATA22 */
#define _S32C5 LCDDATA22bits.S32C5
#define _S33C5 LCDDATA22bits.S33C5
#define _S34C5 LCDDATA22bits.S34C5
#define _S35C5 LCDDATA22bits.S35C5
#define _S36C5 LCDDATA22bits.S36C5
#define _S37C5 LCDDATA22bits.S37C5
#define _S38C5 LCDDATA22bits.S38C5
#define _S39C5 LCDDATA22bits.S39C5
#define _S40C5 LCDDATA22bits.S40C5
#define _S41C5 LCDDATA22bits.S41C5
#define _S42C5 LCDDATA22bits.S42C5
#define _S43C5 LCDDATA22bits.S43C5
#define _S44C5 LCDDATA22bits.S44C5
#define _S45C5 LCDDATA22bits.S45C5
#define _S46C5 LCDDATA22bits.S46C5
#define _S47C5 LCDDATA22bits.S47C5

/* LCDDATA23 */
#define _S48C5 LCDDATA23bits.S48C5
#define _S50C5 LCDDATA23bits.S50C5

/* LCDDATA24 */
#define _S00C6 LCDDATA24bits.S00C6
#define _S01C6 LCDDATA24bits.S01C6
#define _S02C6 LCDDATA24bits.S02C6
#define _S03C6 LCDDATA24bits.S03C6
#define _S04C6 LCDDATA24bits.S04C6
#define _S05C6 LCDDATA24bits.S05C6
#define _S06C6 LCDDATA24bits.S06C6
#define _S07C6 LCDDATA24bits.S07C6
#define _S08C6 LCDDATA24bits.S08C6
#define _S09C6 LCDDATA24bits.S09C6
#define _S10C6 LCDDATA24bits.S10C6
#define _S11C6 LCDDATA24bits.S11C6
#define _S12C6 LCDDATA24bits.S12C6
#define _S13C6 LCDDATA24bits.S13C6
#define _S14C6 LCDDATA24bits.S14C6
#define _S15C6 LCDDATA24bits.S15C6

/* LCDDATA25 */
#define _S16C6 LCDDATA25bits.S16C6
#define _S17C6 LCDDATA25bits.S17C6
#define _S18C6 LCDDATA25bits.S18C6
#define _S19C6 LCDDATA25bits.S19C6
#define _S20C6 LCDDATA25bits.S20C6
#define _S21C6 LCDDATA25bits.S21C6
#define _S22C6 LCDDATA25bits.S22C6
#define _S23C6 LCDDATA25bits.S23C6
#define _S24C6 LCDDATA25bits.S24C6
#define _S25C6 LCDDATA25bits.S25C6
#define _S26C6 LCDDATA25bits.S26C6
#define _S27C6 LCDDATA25bits.S27C6
#define _S28C6 LCDDATA25bits.S28C6
#define _S29C6 LCDDATA25bits.S29C6
#define _S30C6 LCDDATA25bits.S30C6
#define _S31C6 LCDDATA25bits.S31C6

/* LCDDATA26 */
#define _S32C6 LCDDATA26bits.S32C6
#define _S33C6 LCDDATA26bits.S33C6
#define _S34C6 LCDDATA26bits.S34C6
#define _S35C6 LCDDATA26bits.S35C6
#define _S36C6 LCDDATA26bits.S36C6
#define _S37C6 LCDDATA26bits.S37C6
#define _S38C6 LCDDATA26bits.S38C6
#define _S39C6 LCDDATA26bits.S39C6
#define _S40C6 LCDDATA26bits.S40C6
#define _S41C6 LCDDATA26bits.S41C6
#define _S42C6 LCDDATA26bits.S42C6
#define _S43C6 LCDDATA26bits.S43C6
#define _S44C6 LCDDATA26bits.S44C6
#define _S45C6 LCDDATA26bits.S45C6
#define _S46C6 LCDDATA26bits.S46C6
#define _S47C6 LCDDATA26bits.S47C6

/* LCDDATA27 */
#define _S48C6 LCDDATA27bits.S48C6
#define _S50C6 LCDDATA27bits.S50C6

/* LCDDATA28 */
#define _S00C7 LCDDATA28bits.S00C7
#define _S01C7 LCDDATA28bits.S01C7
#define _S02C7 LCDDATA28bits.S02C7
#define _S03C7 LCDDATA28bits.S03C7
#define _S04C7 LCDDATA28bits.S04C7
#define _S05C7 LCDDATA28bits.S05C7
#define _S06C7 LCDDATA28bits.S06C7
#define _S07C7 LCDDATA28bits.S07C7
#define _S08C7 LCDDATA28bits.S08C7
#define _S09C7 LCDDATA28bits.S09C7
#define _S10C7 LCDDATA28bits.S10C7
#define _S11C7 LCDDATA28bits.S11C7
#define _S12C7 LCDDATA28bits.S12C7
#define _S13C7 LCDDATA28bits.S13C7
#define _S14C7 LCDDATA28bits.S14C7
#define _S15C7 LCDDATA28bits.S15C7

/* LCDDATA29 */
#define _S16C7 LCDDATA29bits.S16C7
#define _S17C7 LCDDATA29bits.S17C7
#define _S18C7 LCDDATA29bits.S18C7
#define _S19C7 LCDDATA29bits.S19C7
#define _S20C7 LCDDATA29bits.S20C7
#define _S21C7 LCDDATA29bits.S21C7
#define _S22C7 LCDDATA29bits.S22C7
#define _S23C7 LCDDATA29bits.S23C7
#define _S24C7 LCDDATA29bits.S24C7
#define _S25C7 LCDDATA29bits.S25C7
#define _S26C7 LCDDATA29bits.S26C7
#define _S27C7 LCDDATA29bits.S27C7
#define _S28C7 LCDDATA29bits.S28C7
#define _S29C7 LCDDATA29bits.S29C7
#define _S30C7 LCDDATA29bits.S30C7
#define _S31C7 LCDDATA29bits.S31C7

/* LCDDATA30 */
#define _S32C7 LCDDATA30bits.S32C7
#define _S33C7 LCDDATA30bits.S33C7
#define _S34C7 LCDDATA30bits.S34C7
#define _S35C7 LCDDATA30bits.S35C7
#define _S36C7 LCDDATA30bits.S36C7
#define _S37C7 LCDDATA30bits.S37C7
#define _S38C7 LCDDATA30bits.S38C7
#define _S39C7 LCDDATA30bits.S39C7
#define _S40C7 LCDDATA30bits.S40C7
#define _S41C7 LCDDATA30bits.S41C7
#define _S42C7 LCDDATA30bits.S42C7
#define _S43C7 LCDDATA30bits.S43C7
#define _S44C7 LCDDATA30bits.S44C7
#define _S45C7 LCDDATA30bits.S45C7
#define _S46C7 LCDDATA30bits.S46C7
#define _S47C7 LCDDATA30bits.S47C7

/* LCDDATA31 */
#define _S48C7 LCDDATA31bits.S48C7
#define _S50C7 LCDDATA31bits.S50C7

/* PMCON1 */
#define _IRQM PMCON1bits.IRQM
#define _BUSKEEP PMCON1bits.BUSKEEP
#define _ALMODE PMCON1bits.ALMODE
#define _ALP PMCON1bits.ALP
#define _CSF PMCON1bits.CSF
#define _MODE PMCON1bits.MODE
#define _ADRMUX PMCON1bits.ADRMUX
#define _PSIDL PMCON1bits.PSIDL
#define _PMPEN PMCON1bits.PMPEN
#define _IRQM0 PMCON1bits.IRQM0
#define _IRQM1 PMCON1bits.IRQM1
#define _CSF0 PMCON1bits.CSF0
#define _CSF1 PMCON1bits.CSF1
#define _MODE0 PMCON1bits.MODE0
#define _MODE1 PMCON1bits.MODE1
#define _ADRMUX0 PMCON1bits.ADRMUX0
#define _ADRMUX1 PMCON1bits.ADRMUX1

/* PMCON2 */
#define _RADDR PMCON2bits.RADDR
#define _TIMEOUT PMCON2bits.TIMEOUT
#define _ERROR PMCON2bits.ERROR
#define _BUSY PMCON2bits.BUSY
#define _RADDR16 PMCON2bits.RADDR16
#define _RADDR17 PMCON2bits.RADDR17
#define _RADDR18 PMCON2bits.RADDR18
#define _RADDR19 PMCON2bits.RADDR19
#define _RADDR20 PMCON2bits.RADDR20
#define _RADDR21 PMCON2bits.RADDR21
#define _RADDR22 PMCON2bits.RADDR22
#define _RADDR23 PMCON2bits.RADDR23

/* PMCON3 */
#define _PTEN16 PMCON3bits.PTEN16
#define _PTEN17 PMCON3bits.PTEN17
#define _PTEN18 PMCON3bits.PTEN18
#define _PTEN19 PMCON3bits.PTEN19
#define _PTEN20 PMCON3bits.PTEN20
#define _PTEN21 PMCON3bits.PTEN21
#define _PTEN22 PMCON3bits.PTEN22
#define _AWAITE PMCON3bits.AWAITE
#define _AWAITM PMCON3bits.AWAITM
#define _PTBE0EN PMCON3bits.PTBE0EN
#define _PTBE1EN PMCON3bits.PTBE1EN
#define _PTRDEN PMCON3bits.PTRDEN
#define _PTWREN PMCON3bits.PTWREN
#define _AWAITM0 PMCON3bits.AWAITM0
#define _AWAITM1 PMCON3bits.AWAITM1

/* PMCON4 */
#define _PTEN0 PMCON4bits.PTEN0
#define _PTEN1 PMCON4bits.PTEN1
#define _PTEN2 PMCON4bits.PTEN2
#define _PTEN3 PMCON4bits.PTEN3
#define _PTEN4 PMCON4bits.PTEN4
#define _PTEN5 PMCON4bits.PTEN5
#define _PTEN6 PMCON4bits.PTEN6
#define _PTEN7 PMCON4bits.PTEN7
#define _PTEN8 PMCON4bits.PTEN8
#define _PTEN9 PMCON4bits.PTEN9
#define _PTEN10 PMCON4bits.PTEN10
#define _PTEN11 PMCON4bits.PTEN11
#define _PTEN12 PMCON4bits.PTEN12
#define _PTEN13 PMCON4bits.PTEN13
#define _PTEN14 PMCON4bits.PTEN14
#define _PTEN15 PMCON4bits.PTEN15

/* PMCS1CF */
/* Bitname _PTSZ cannot be defined because it is used by more than one SFR */
/* Bitname _ACKP cannot be defined because it is used by more than one SFR */
/* Bitname _SM cannot be defined because it is used by more than one SFR */
/* Bitname _RDSP cannot be defined because it is used by more than one SFR */
/* Bitname _WRSP cannot be defined because it is used by more than one SFR */
/* Bitname _BEP cannot be defined because it is used by more than one SFR */
/* Bitname _CSPTEN cannot be defined because it is used by more than one SFR */
/* Bitname _CSP cannot be defined because it is used by more than one SFR */
/* Bitname _CSDIS cannot be defined because it is used by more than one SFR */
/* Bitname _PTSZ0 cannot be defined because it is used by more than one SFR */
/* Bitname _PTSZ1 cannot be defined because it is used by more than one SFR */

/* PMCS1BS */
/* Bitname _BASE11 cannot be defined because it is used by more than one SFR */
/* Bitname _BASE15 cannot be defined because it is used by more than one SFR */
/* Bitname _BASE16 cannot be defined because it is used by more than one SFR */
/* Bitname _BASE17 cannot be defined because it is used by more than one SFR */
/* Bitname _BASE18 cannot be defined because it is used by more than one SFR */
/* Bitname _BASE19 cannot be defined because it is used by more than one SFR */
/* Bitname _BASE20 cannot be defined because it is used by more than one SFR */
/* Bitname _BASE21 cannot be defined because it is used by more than one SFR */
/* Bitname _BASE22 cannot be defined because it is used by more than one SFR */
/* Bitname _BASE23 cannot be defined because it is used by more than one SFR */

/* PMCS1MD */
/* Bitname _DWAITE cannot be defined because it is used by more than one SFR */
/* Bitname _DWAITM cannot be defined because it is used by more than one SFR */
/* Bitname _DWAITB cannot be defined because it is used by more than one SFR */
/* Bitname _AMWAIT cannot be defined because it is used by more than one SFR */
/* Bitname _ACKM cannot be defined because it is used by more than one SFR */
/* Bitname _DWAITE0 cannot be defined because it is used by more than one SFR */
/* Bitname _DWAITE1 cannot be defined because it is used by more than one SFR */
/* Bitname _DWAITM0 cannot be defined because it is used by more than one SFR */
/* Bitname _DWAITM1 cannot be defined because it is used by more than one SFR */
/* Bitname _DWAITM2 cannot be defined because it is used by more than one SFR */
/* Bitname _DWAITM3 cannot be defined because it is used by more than one SFR */
/* Bitname _DWAITB0 cannot be defined because it is used by more than one SFR */
/* Bitname _DWAITB1 cannot be defined because it is used by more than one SFR */
/* Bitname _AMWAIT0 cannot be defined because it is used by more than one SFR */
/* Bitname _AMWAIT1 cannot be defined because it is used by more than one SFR */
/* Bitname _AMWAIT2 cannot be defined because it is used by more than one SFR */
/* Bitname _ACKM0 cannot be defined because it is used by more than one SFR */
/* Bitname _ACKM1 cannot be defined because it is used by more than one SFR */

/* PMCS2CF */
/* Bitname _PTSZ cannot be defined because it is used by more than one SFR */
/* Bitname _ACKP cannot be defined because it is used by more than one SFR */
/* Bitname _SM cannot be defined because it is used by more than one SFR */
/* Bitname _RDSP cannot be defined because it is used by more than one SFR */
/* Bitname _WRSP cannot be defined because it is used by more than one SFR */
/* Bitname _BEP cannot be defined because it is used by more than one SFR */
/* Bitname _CSPTEN cannot be defined because it is used by more than one SFR */
/* Bitname _CSP cannot be defined because it is used by more than one SFR */
/* Bitname _CSDIS cannot be defined because it is used by more than one SFR */
/* Bitname _PTSZ0 cannot be defined because it is used by more than one SFR */
/* Bitname _PTSZ1 cannot be defined because it is used by more than one SFR */

/* PMCS2BS */
/* Bitname _BASE11 cannot be defined because it is used by more than one SFR */
/* Bitname _BASE15 cannot be defined because it is used by more than one SFR */
/* Bitname _BASE16 cannot be defined because it is used by more than one SFR */
/* Bitname _BASE17 cannot be defined because it is used by more than one SFR */
/* Bitname _BASE18 cannot be defined because it is used by more than one SFR */
/* Bitname _BASE19 cannot be defined because it is used by more than one SFR */
/* Bitname _BASE20 cannot be defined because it is used by more than one SFR */
/* Bitname _BASE21 cannot be defined because it is used by more than one SFR */
/* Bitname _BASE22 cannot be defined because it is used by more than one SFR */
/* Bitname _BASE23 cannot be defined because it is used by more than one SFR */

/* PMCS2MD */
/* Bitname _DWAITE cannot be defined because it is used by more than one SFR */
/* Bitname _DWAITM cannot be defined because it is used by more than one SFR */
/* Bitname _DWAITB cannot be defined because it is used by more than one SFR */
/* Bitname _AMWAIT cannot be defined because it is used by more than one SFR */
/* Bitname _ACKM cannot be defined because it is used by more than one SFR */
/* Bitname _DWAITE0 cannot be defined because it is used by more than one SFR */
/* Bitname _DWAITE1 cannot be defined because it is used by more than one SFR */
/* Bitname _DWAITM0 cannot be defined because it is used by more than one SFR */
/* Bitname _DWAITM1 cannot be defined because it is used by more than one SFR */
/* Bitname _DWAITM2 cannot be defined because it is used by more than one SFR */
/* Bitname _DWAITM3 cannot be defined because it is used by more than one SFR */
/* Bitname _DWAITB0 cannot be defined because it is used by more than one SFR */
/* Bitname _DWAITB1 cannot be defined because it is used by more than one SFR */
/* Bitname _AMWAIT0 cannot be defined because it is used by more than one SFR */
/* Bitname _AMWAIT1 cannot be defined because it is used by more than one SFR */
/* Bitname _AMWAIT2 cannot be defined because it is used by more than one SFR */
/* Bitname _ACKM0 cannot be defined because it is used by more than one SFR */
/* Bitname _ACKM1 cannot be defined because it is used by more than one SFR */

/* PMSTAT */
#define _OB0E PMSTATbits.OB0E
#define _OB1E PMSTATbits.OB1E
#define _OB2E PMSTATbits.OB2E
#define _OB3E PMSTATbits.OB3E
#define _OBUF PMSTATbits.OBUF
#define _OBE PMSTATbits.OBE
#define _IB0F PMSTATbits.IB0F
#define _IB1F PMSTATbits.IB1F
#define _IB2F PMSTATbits.IB2F
#define _IB3F PMSTATbits.IB3F
#define _IBOV PMSTATbits.IBOV
#define _IBF PMSTATbits.IBF

/* ALCFGRPT */
#define _ARPT ALCFGRPTbits.ARPT
#define _ALRMPTR ALCFGRPTbits.ALRMPTR
#define _AMASK ALCFGRPTbits.AMASK
#define _CHIME ALCFGRPTbits.CHIME
#define _ALRMEN ALCFGRPTbits.ALRMEN
#define _ARPT0 ALCFGRPTbits.ARPT0
#define _ARPT1 ALCFGRPTbits.ARPT1
#define _ARPT2 ALCFGRPTbits.ARPT2
#define _ARPT3 ALCFGRPTbits.ARPT3
#define _ARPT4 ALCFGRPTbits.ARPT4
#define _ARPT5 ALCFGRPTbits.ARPT5
#define _ARPT6 ALCFGRPTbits.ARPT6
#define _ARPT7 ALCFGRPTbits.ARPT7
#define _ALRMPTR0 ALCFGRPTbits.ALRMPTR0
#define _ALRMPTR1 ALCFGRPTbits.ALRMPTR1
#define _AMASK0 ALCFGRPTbits.AMASK0
#define _AMASK1 ALCFGRPTbits.AMASK1
#define _AMASK2 ALCFGRPTbits.AMASK2
#define _AMASK3 ALCFGRPTbits.AMASK3

/* RCFGCAL */
#define _CAL RCFGCALbits.CAL
#define _RTCPTR RCFGCALbits.RTCPTR
#define _RTCOE RCFGCALbits.RTCOE
#define _HALFSEC RCFGCALbits.HALFSEC
#define _RTCSYNC RCFGCALbits.RTCSYNC
#define _RTCWREN RCFGCALbits.RTCWREN
#define _RTCEN RCFGCALbits.RTCEN
#define _CAL0 RCFGCALbits.CAL0
#define _CAL1 RCFGCALbits.CAL1
#define _CAL2 RCFGCALbits.CAL2
#define _CAL3 RCFGCALbits.CAL3
#define _CAL4 RCFGCALbits.CAL4
#define _CAL5 RCFGCALbits.CAL5
#define _CAL6 RCFGCALbits.CAL6
#define _CAL7 RCFGCALbits.CAL7
#define _RTCPTR0 RCFGCALbits.RTCPTR0
#define _RTCPTR1 RCFGCALbits.RTCPTR1

/* RTCPWC */
#define _RTCOUT RTCPWCbits.RTCOUT
#define _RTCLK RTCPWCbits.RTCLK
#define _PWSPRE RTCPWCbits.PWSPRE
#define _PWCPRE RTCPWCbits.PWCPRE
#define _PWCPOL RTCPWCbits.PWCPOL
#define _PWCEN RTCPWCbits.PWCEN
#define _RTCOUT0 RTCPWCbits.RTCOUT0
#define _RTCOUT1 RTCPWCbits.RTCOUT1
#define _RTCLK0 RTCPWCbits.RTCLK0
#define _RTCLK1 RTCPWCbits.RTCLK1

/* MDCON */
#define _MDBIT MDCONbits.MDBIT
#define _MDOPOL MDCONbits.MDOPOL
#define _MDSLR MDCONbits.MDSLR
#define _MDOE MDCONbits.MDOE
#define _MDSIDL MDCONbits.MDSIDL
#define _MDEN MDCONbits.MDEN

/* MDSRC */
#define _MS MDSRCbits.MS
#define _SODIS MDSRCbits.SODIS
#define _MS0 MDSRCbits.MS0
#define _MS1 MDSRCbits.MS1
#define _MS2 MDSRCbits.MS2
#define _MS3 MDSRCbits.MS3

/* MDCAR */
#define _CL MDCARbits.CL
#define _CLSYNC MDCARbits.CLSYNC
#define _CLPOL MDCARbits.CLPOL
#define _CLODIS MDCARbits.CLODIS
#define _CH MDCARbits.CH
#define _CHSYNC MDCARbits.CHSYNC
#define _CHPOL MDCARbits.CHPOL
#define _CHODIS MDCARbits.CHODIS
#define _CL0 MDCARbits.CL0
#define _CL1 MDCARbits.CL1
#define _CL2 MDCARbits.CL2
#define _CL3 MDCARbits.CL3
#define _CH0 MDCARbits.CH0
#define _CH1 MDCARbits.CH1
#define _CH2 MDCARbits.CH2
#define _CH3 MDCARbits.CH3

/* CMSTAT */
#define _C1OUT CMSTATbits.C1OUT
#define _C2OUT CMSTATbits.C2OUT
#define _C3OUT CMSTATbits.C3OUT
#define _C1EVT CMSTATbits.C1EVT
#define _C2EVT CMSTATbits.C2EVT
#define _C3EVT CMSTATbits.C3EVT
#define _CMIDL CMSTATbits.CMIDL

/* CVRCON */
#define _CVR CVRCONbits.CVR
#define _CVRSS CVRCONbits.CVRSS
#define _CVRR CVRCONbits.CVRR
#define _CVROE CVRCONbits.CVROE
#define _CVREN CVRCONbits.CVREN
#define _CVREFM CVRCONbits.CVREFM
#define _CVREFP CVRCONbits.CVREFP
#define _CVR0 CVRCONbits.CVR0
#define _CVR1 CVRCONbits.CVR1
#define _CVR2 CVRCONbits.CVR2
#define _CVR3 CVRCONbits.CVR3
#define _CVREFM0 CVRCONbits.CVREFM0
#define _CVREFM1 CVRCONbits.CVREFM1

/* CM1CON */
/* Bitname _CCH cannot be defined because it is used by more than one SFR */
/* Bitname _CREF cannot be defined because it is used by more than one SFR */
/* Bitname _EVPOL cannot be defined because it is used by more than one SFR */
/* Bitname _COUT cannot be defined because it is used by more than one SFR */
/* Bitname _CEVT cannot be defined because it is used by more than one SFR */
/* Bitname _CPOL cannot be defined because it is used by more than one SFR */
/* Bitname _COE cannot be defined because it is used by more than one SFR */
/* Bitname _CON cannot be defined because it is used by more than one SFR */
/* Bitname _CCH0 cannot be defined because it is used by more than one SFR */
/* Bitname _CCH1 cannot be defined because it is used by more than one SFR */
/* Bitname _EVPOL0 cannot be defined because it is used by more than one SFR */
/* Bitname _EVPOL1 cannot be defined because it is used by more than one SFR */
/* Bitname _CEN cannot be defined because it is used by more than one SFR */

/* CM2CON */
/* Bitname _CCH cannot be defined because it is used by more than one SFR */
/* Bitname _CREF cannot be defined because it is used by more than one SFR */
/* Bitname _EVPOL cannot be defined because it is used by more than one SFR */
/* Bitname _COUT cannot be defined because it is used by more than one SFR */
/* Bitname _CEVT cannot be defined because it is used by more than one SFR */
/* Bitname _CPOL cannot be defined because it is used by more than one SFR */
/* Bitname _COE cannot be defined because it is used by more than one SFR */
/* Bitname _CON cannot be defined because it is used by more than one SFR */
/* Bitname _CCH0 cannot be defined because it is used by more than one SFR */
/* Bitname _CCH1 cannot be defined because it is used by more than one SFR */
/* Bitname _EVPOL0 cannot be defined because it is used by more than one SFR */
/* Bitname _EVPOL1 cannot be defined because it is used by more than one SFR */
/* Bitname _CEN cannot be defined because it is used by more than one SFR */

/* CM3CON */
/* Bitname _CCH cannot be defined because it is used by more than one SFR */
/* Bitname _CREF cannot be defined because it is used by more than one SFR */
/* Bitname _EVPOL cannot be defined because it is used by more than one SFR */
/* Bitname _COUT cannot be defined because it is used by more than one SFR */
/* Bitname _CEVT cannot be defined because it is used by more than one SFR */
/* Bitname _CPOL cannot be defined because it is used by more than one SFR */
/* Bitname _COE cannot be defined because it is used by more than one SFR */
/* Bitname _CON cannot be defined because it is used by more than one SFR */
/* Bitname _CCH0 cannot be defined because it is used by more than one SFR */
/* Bitname _CCH1 cannot be defined because it is used by more than one SFR */
/* Bitname _EVPOL0 cannot be defined because it is used by more than one SFR */
/* Bitname _EVPOL1 cannot be defined because it is used by more than one SFR */
/* Bitname _CEN cannot be defined because it is used by more than one SFR */

/* CRCCON1 */
#define _LENDIAN CRCCON1bits.LENDIAN
#define _CRCGO CRCCON1bits.CRCGO
#define _CRCISEL CRCCON1bits.CRCISEL
#define _CRCMPT CRCCON1bits.CRCMPT
#define _CRCFUL CRCCON1bits.CRCFUL
#define _VWORD CRCCON1bits.VWORD
#define _CSIDL CRCCON1bits.CSIDL
#define _CRCEN CRCCON1bits.CRCEN
#define _VWORD0 CRCCON1bits.VWORD0
#define _VWORD1 CRCCON1bits.VWORD1
#define _VWORD2 CRCCON1bits.VWORD2
#define _VWORD3 CRCCON1bits.VWORD3
#define _VWORD4 CRCCON1bits.VWORD4

/* CRCCON2 */
#define _PLEN CRCCON2bits.PLEN
#define _DWIDTH CRCCON2bits.DWIDTH
#define _PLEN0 CRCCON2bits.PLEN0
#define _PLEN1 CRCCON2bits.PLEN1
#define _PLEN2 CRCCON2bits.PLEN2
#define _PLEN3 CRCCON2bits.PLEN3
#define _PLEN4 CRCCON2bits.PLEN4
#define _DWIDTH0 CRCCON2bits.DWIDTH0
#define _DWIDTH1 CRCCON2bits.DWIDTH1
#define _DWIDTH2 CRCCON2bits.DWIDTH2
#define _DWIDTH3 CRCCON2bits.DWIDTH3
#define _DWIDTH4 CRCCON2bits.DWIDTH4

/* CRCXORL */
#define _X1 CRCXORLbits.X1
#define _X2 CRCXORLbits.X2
#define _X3 CRCXORLbits.X3
#define _X4 CRCXORLbits.X4
#define _X5 CRCXORLbits.X5
#define _X6 CRCXORLbits.X6
#define _X7 CRCXORLbits.X7
#define _X8 CRCXORLbits.X8
#define _X9 CRCXORLbits.X9
#define _X10 CRCXORLbits.X10
#define _X11 CRCXORLbits.X11
#define _X12 CRCXORLbits.X12
#define _X13 CRCXORLbits.X13
#define _X14 CRCXORLbits.X14
#define _X15 CRCXORLbits.X15

/* CRCXORH */
#define _X16 CRCXORHbits.X16
#define _X17 CRCXORHbits.X17
#define _X18 CRCXORHbits.X18
#define _X19 CRCXORHbits.X19
#define _X20 CRCXORHbits.X20
#define _X21 CRCXORHbits.X21
#define _X22 CRCXORHbits.X22
#define _X23 CRCXORHbits.X23
#define _X24 CRCXORHbits.X24
#define _X25 CRCXORHbits.X25
#define _X26 CRCXORHbits.X26
#define _X27 CRCXORHbits.X27
#define _X28 CRCXORHbits.X28
#define _X29 CRCXORHbits.X29
#define _X30 CRCXORHbits.X30
#define _X31 CRCXORHbits.X31

/* RPINR0 */
#define _INT1R RPINR0bits.INT1R
#define _INT1R0 RPINR0bits.INT1R0
#define _INT1R1 RPINR0bits.INT1R1
#define _INT1R2 RPINR0bits.INT1R2
#define _INT1R3 RPINR0bits.INT1R3
#define _INT1R4 RPINR0bits.INT1R4
#define _INT1R5 RPINR0bits.INT1R5

/* RPINR1 */
#define _INT2R RPINR1bits.INT2R
#define _INT3R RPINR1bits.INT3R
#define _INT2R0 RPINR1bits.INT2R0
#define _INT2R1 RPINR1bits.INT2R1
#define _INT2R2 RPINR1bits.INT2R2
#define _INT2R3 RPINR1bits.INT2R3
#define _INT2R4 RPINR1bits.INT2R4
#define _INT2R5 RPINR1bits.INT2R5
#define _INT3R0 RPINR1bits.INT3R0
#define _INT3R1 RPINR1bits.INT3R1
#define _INT3R2 RPINR1bits.INT3R2
#define _INT3R3 RPINR1bits.INT3R3
#define _INT3R4 RPINR1bits.INT3R4
#define _INT3R5 RPINR1bits.INT3R5

/* RPINR2 */
#define _INT4R RPINR2bits.INT4R
#define _INT4R0 RPINR2bits.INT4R0
#define _INT4R1 RPINR2bits.INT4R1
#define _INT4R2 RPINR2bits.INT4R2
#define _INT5R3 RPINR2bits.INT5R3
#define _INT4R4 RPINR2bits.INT4R4
#define _INT4R5 RPINR2bits.INT4R5
#define _OC3R0 RPINR2bits.OC3R0
#define _OC3R1 RPINR2bits.OC3R1
#define _OC3R2 RPINR2bits.OC3R2
#define _OC3R3 RPINR2bits.OC3R3
#define _OC3R4 RPINR2bits.OC3R4
#define _OC3R5 RPINR2bits.OC3R5

/* RPINR3 */
#define _T2CKR RPINR3bits.T2CKR
#define _T3CKR RPINR3bits.T3CKR
#define _T2CKR0 RPINR3bits.T2CKR0
#define _T2CKR1 RPINR3bits.T2CKR1
#define _T2CKR2 RPINR3bits.T2CKR2
#define _T2CKR3 RPINR3bits.T2CKR3
#define _T2CKR4 RPINR3bits.T2CKR4
#define _T2CKR5 RPINR3bits.T2CKR5
#define _T3CKR0 RPINR3bits.T3CKR0
#define _T3CKR1 RPINR3bits.T3CKR1
#define _T3CKR2 RPINR3bits.T3CKR2
#define _T3CKR3 RPINR3bits.T3CKR3
#define _T3CKR4 RPINR3bits.T3CKR4
#define _T3CKR5 RPINR3bits.T3CKR5

/* RPINR4 */
#define _T4CKR RPINR4bits.T4CKR
#define _T5CKR RPINR4bits.T5CKR
#define _T4CKR0 RPINR4bits.T4CKR0
#define _T4CKR1 RPINR4bits.T4CKR1
#define _T4CKR2 RPINR4bits.T4CKR2
#define _T4CKR3 RPINR4bits.T4CKR3
#define _T4CKR4 RPINR4bits.T4CKR4
#define _T4CKR5 RPINR4bits.T4CKR5
#define _T5CKR0 RPINR4bits.T5CKR0
#define _T5CKR1 RPINR4bits.T5CKR1
#define _T5CKR2 RPINR4bits.T5CKR2
#define _T5CKR3 RPINR4bits.T5CKR3
#define _T5CKR4 RPINR4bits.T5CKR4
#define _T5CKR5 RPINR4bits.T5CKR5

/* RPINR7 */
#define _IC1R RPINR7bits.IC1R
#define _IC2R RPINR7bits.IC2R
#define _IC1R0 RPINR7bits.IC1R0
#define _IC1R1 RPINR7bits.IC1R1
#define _IC1R2 RPINR7bits.IC1R2
#define _IC1R3 RPINR7bits.IC1R3
#define _IC1R4 RPINR7bits.IC1R4
#define _IC1R5 RPINR7bits.IC1R5
#define _IC2R0 RPINR7bits.IC2R0
#define _IC2R1 RPINR7bits.IC2R1
#define _IC2R2 RPINR7bits.IC2R2
#define _IC2R3 RPINR7bits.IC2R3
#define _IC2R4 RPINR7bits.IC2R4
#define _IC2R5 RPINR7bits.IC2R5

/* RPINR8 */
#define _IC3R RPINR8bits.IC3R
#define _IC4R RPINR8bits.IC4R
#define _IC3R0 RPINR8bits.IC3R0
#define _IC3R1 RPINR8bits.IC3R1
#define _IC3R2 RPINR8bits.IC3R2
#define _IC3R3 RPINR8bits.IC3R3
#define _IC3R4 RPINR8bits.IC3R4
#define _IC3R5 RPINR8bits.IC3R5
#define _IC4R0 RPINR8bits.IC4R0
#define _IC4R1 RPINR8bits.IC4R1
#define _IC4R2 RPINR8bits.IC4R2
#define _IC4R3 RPINR8bits.IC4R3
#define _IC4R4 RPINR8bits.IC4R4
#define _IC4R5 RPINR8bits.IC4R5

/* RPINR9 */
#define _IC5R RPINR9bits.IC5R
#define _IC6R RPINR9bits.IC6R
#define _IC5R0 RPINR9bits.IC5R0
#define _IC5R1 RPINR9bits.IC5R1
#define _IC5R2 RPINR9bits.IC5R2
#define _IC5R3 RPINR9bits.IC5R3
#define _IC5R4 RPINR9bits.IC5R4
#define _IC5R5 RPINR9bits.IC5R5
#define _IC6R0 RPINR9bits.IC6R0
#define _IC6R1 RPINR9bits.IC6R1
#define _IC6R2 RPINR9bits.IC6R2
#define _IC6R3 RPINR9bits.IC6R3
#define _IC6R4 RPINR9bits.IC6R4
#define _IC6R5 RPINR9bits.IC6R5

/* RPINR10 */
#define _IC7R RPINR10bits.IC7R
#define _IC7R0 RPINR10bits.IC7R0
#define _IC7R1 RPINR10bits.IC7R1
#define _IC7R2 RPINR10bits.IC7R2
#define _IC7R3 RPINR10bits.IC7R3
#define _IC7R4 RPINR10bits.IC7R4
#define _IC7R5 RPINR10bits.IC7R5
#define _IC8R0 RPINR10bits.IC8R0
#define _IC8R1 RPINR10bits.IC8R1
#define _IC8R2 RPINR10bits.IC8R2
#define _IC8R3 RPINR10bits.IC8R3
#define _IC8R4 RPINR10bits.IC8R4
#define _IC8R5 RPINR10bits.IC8R5

/* RPINR11 */
#define _OCFAR RPINR11bits.OCFAR
#define _OCFBR RPINR11bits.OCFBR
#define _OCFAR0 RPINR11bits.OCFAR0
#define _OCFAR1 RPINR11bits.OCFAR1
#define _OCFAR2 RPINR11bits.OCFAR2
#define _OCFAR3 RPINR11bits.OCFAR3
#define _OCFAR4 RPINR11bits.OCFAR4
#define _OCFAR5 RPINR11bits.OCFAR5
#define _OCFBR0 RPINR11bits.OCFBR0
#define _OCFBR1 RPINR11bits.OCFBR1
#define _OCFBR2 RPINR11bits.OCFBR2
#define _OCFBR3 RPINR11bits.OCFBR3
#define _OCFBR4 RPINR11bits.OCFBR4
#define _OCFBR5 RPINR11bits.OCFBR5

/* RPINR17 */
#define _U3RXR RPINR17bits.U3RXR
#define _U3RXR0 RPINR17bits.U3RXR0
#define _U3RXR1 RPINR17bits.U3RXR1
#define _U3RXR2 RPINR17bits.U3RXR2
#define _U3RXR3 RPINR17bits.U3RXR3
#define _U3RXR4 RPINR17bits.U3RXR4
#define _U3RXR5 RPINR17bits.U3RXR5

/* RPINR18 */
#define _U1RXR RPINR18bits.U1RXR
#define _U1CTSR RPINR18bits.U1CTSR
#define _U1RXR0 RPINR18bits.U1RXR0
#define _U1RXR1 RPINR18bits.U1RXR1
#define _U1RXR2 RPINR18bits.U1RXR2
#define _U1RXR3 RPINR18bits.U1RXR3
#define _U1RXR4 RPINR18bits.U1RXR4
#define _U1RXR5 RPINR18bits.U1RXR5
#define _U1CTSR0 RPINR18bits.U1CTSR0
#define _U1CTSR1 RPINR18bits.U1CTSR1
#define _U1CTSR2 RPINR18bits.U1CTSR2
#define _U1CTSR3 RPINR18bits.U1CTSR3
#define _U1CTSR4 RPINR18bits.U1CTSR4
#define _U1CTSR5 RPINR18bits.U1CTSR5

/* RPINR19 */
#define _U2RXR RPINR19bits.U2RXR
#define _U2CTSR RPINR19bits.U2CTSR
#define _U2RXR0 RPINR19bits.U2RXR0
#define _U2RXR1 RPINR19bits.U2RXR1
#define _U2RXR2 RPINR19bits.U2RXR2
#define _U2RXR3 RPINR19bits.U2RXR3
#define _U2RXR4 RPINR19bits.U2RXR4
#define _U2RXR5 RPINR19bits.U2RXR5
#define _U2CTSR0 RPINR19bits.U2CTSR0
#define _U2CTSR1 RPINR19bits.U2CTSR1
#define _U2CTSR2 RPINR19bits.U2CTSR2
#define _U2CTSR3 RPINR19bits.U2CTSR3
#define _U2CTSR4 RPINR19bits.U2CTSR4
#define _U2CTSR5 RPINR19bits.U2CTSR5

/* RPINR20 */
#define _SDI1R RPINR20bits.SDI1R
#define _SCK1R RPINR20bits.SCK1R
#define _SDI1R0 RPINR20bits.SDI1R0
#define _SDI1R1 RPINR20bits.SDI1R1
#define _SDI1R2 RPINR20bits.SDI1R2
#define _SDI1R3 RPINR20bits.SDI1R3
#define _SDI1R4 RPINR20bits.SDI1R4
#define _SDI1R5 RPINR20bits.SDI1R5
#define _SCK1R0 RPINR20bits.SCK1R0
#define _SCK1R1 RPINR20bits.SCK1R1
#define _SCK1R2 RPINR20bits.SCK1R2
#define _SCK1R3 RPINR20bits.SCK1R3
#define _SCK1R4 RPINR20bits.SCK1R4
#define _SCK1R5 RPINR20bits.SCK1R5

/* RPINR21 */
#define _SS1R RPINR21bits.SS1R
#define _U3CTSR RPINR21bits.U3CTSR
#define _SS1R0 RPINR21bits.SS1R0
#define _SS1R1 RPINR21bits.SS1R1
#define _SS1R2 RPINR21bits.SS1R2
#define _SS1R3 RPINR21bits.SS1R3
#define _SS1R4 RPINR21bits.SS1R4
#define _SS1R5 RPINR21bits.SS1R5
#define _U3CTSR0 RPINR21bits.U3CTSR0
#define _U3CTSR1 RPINR21bits.U3CTSR1
#define _U3CTSR2 RPINR21bits.U3CTSR2
#define _U3CTSR3 RPINR21bits.U3CTSR3
#define _U3CTSR4 RPINR21bits.U3CTSR4
#define _U3CTSR5 RPINR21bits.U3CTSR5

/* RPINR22 */
#define _SDI2R RPINR22bits.SDI2R
#define _SCK2R RPINR22bits.SCK2R
#define _SDI2R0 RPINR22bits.SDI2R0
#define _SDI2R1 RPINR22bits.SDI2R1
#define _SDI2R2 RPINR22bits.SDI2R2
#define _SDI2R3 RPINR22bits.SDI2R3
#define _SDI2R4 RPINR22bits.SDI2R4
#define _SDI2R5 RPINR22bits.SDI2R5
#define _SCK2R0 RPINR22bits.SCK2R0
#define _SCK2R1 RPINR22bits.SCK2R1
#define _SCK2R2 RPINR22bits.SCK2R2
#define _SCK2R3 RPINR22bits.SCK2R3
#define _SCK2R4 RPINR22bits.SCK2R4
#define _SCK2R5 RPINR22bits.SCK2R5

/* RPINR23 */
#define _SS2R RPINR23bits.SS2R
#define _T1CKR RPINR23bits.T1CKR
#define _SS2R0 RPINR23bits.SS2R0
#define _SS2R1 RPINR23bits.SS2R1
#define _SS2R2 RPINR23bits.SS2R2
#define _SS2R3 RPINR23bits.SS2R3
#define _SS2R4 RPINR23bits.SS2R4
#define _SS2R5 RPINR23bits.SS2R5
#define _T1CKR0 RPINR23bits.T1CKR0
#define _T1CKR1 RPINR23bits.T1CKR1
#define _T1CKR2 RPINR23bits.T1CKR2
#define _T1CKR3 RPINR23bits.T1CKR3
#define _T1CKR4 RPINR23bits.T1CKR4
#define _T1CKR5 RPINR23bits.T1CKR5

/* RPINR27 */
#define _U4RXR RPINR27bits.U4RXR
#define _U4CTSR RPINR27bits.U4CTSR
#define _U4RXR0 RPINR27bits.U4RXR0
#define _U4RXR1 RPINR27bits.U4RXR1
#define _U4RXR2 RPINR27bits.U4RXR2
#define _U4RXR3 RPINR27bits.U4RXR3
#define _U4RXR4 RPINR27bits.U4RXR4
#define _U4RXR5 RPINR27bits.U4RXR5
#define _U4CTSR0 RPINR27bits.U4CTSR0
#define _U4CTSR1 RPINR27bits.U4CTSR1
#define _U4CTSR2 RPINR27bits.U4CTSR2
#define _U4CTSR3 RPINR27bits.U4CTSR3
#define _U4CTSR4 RPINR27bits.U4CTSR4
#define _U4CTSR5 RPINR27bits.U4CTSR5

/* RPINR30 */
#define _MDMIR RPINR30bits.MDMIR
#define _MDMIR0 RPINR30bits.MDMIR0
#define _MDMIR1 RPINR30bits.MDMIR1
#define _MDMIR2 RPINR30bits.MDMIR2
#define _MDMIR3 RPINR30bits.MDMIR3
#define _MDMIR4 RPINR30bits.MDMIR4
#define _MDMIR5 RPINR30bits.MDMIR5

/* RPINR31 */
#define _MDC1R RPINR31bits.MDC1R
#define _MDC2R RPINR31bits.MDC2R
#define _MDC1R0 RPINR31bits.MDC1R0
#define _MDC1R1 RPINR31bits.MDC1R1
#define _MDC1R2 RPINR31bits.MDC1R2
#define _MDC1R3 RPINR31bits.MDC1R3
#define _MDC1R4 RPINR31bits.MDC1R4
#define _MDC1R5 RPINR31bits.MDC1R5
#define _MDC2R0 RPINR31bits.MDC2R0
#define _MDC2R1 RPINR31bits.MDC2R1
#define _MDC2R2 RPINR31bits.MDC2R2
#define _MDC2R3 RPINR31bits.MDC2R3
#define _MDC2R4 RPINR31bits.MDC2R4
#define _MDC2R5 RPINR31bits.MDC2R5

/* RPOR0 */
#define _RP0R RPOR0bits.RP0R
#define _RP1R RPOR0bits.RP1R
#define _RP0R0 RPOR0bits.RP0R0
#define _RP0R1 RPOR0bits.RP0R1
#define _RP0R2 RPOR0bits.RP0R2
#define _RP0R3 RPOR0bits.RP0R3
#define _RP0R4 RPOR0bits.RP0R4
#define _RP0R5 RPOR0bits.RP0R5
#define _RP1R0 RPOR0bits.RP1R0
#define _RP1R1 RPOR0bits.RP1R1
#define _RP1R2 RPOR0bits.RP1R2
#define _RP1R3 RPOR0bits.RP1R3
#define _RP1R4 RPOR0bits.RP1R4
#define _RP1R5 RPOR0bits.RP1R5

/* RPOR1 */
#define _RP2R RPOR1bits.RP2R
#define _RP3R RPOR1bits.RP3R
#define _RP2R0 RPOR1bits.RP2R0
#define _RP2R1 RPOR1bits.RP2R1
#define _RP2R2 RPOR1bits.RP2R2
#define _RP2R3 RPOR1bits.RP2R3
#define _RP2R4 RPOR1bits.RP2R4
#define _RP2R5 RPOR1bits.RP2R5
#define _RP3R0 RPOR1bits.RP3R0
#define _RP3R1 RPOR1bits.RP3R1
#define _RP3R2 RPOR1bits.RP3R2
#define _RP3R3 RPOR1bits.RP3R3
#define _RP3R4 RPOR1bits.RP3R4
#define _RP3R5 RPOR1bits.RP3R5

/* RPOR2 */
#define _RP4R RPOR2bits.RP4R
#define _RP5R RPOR2bits.RP5R
#define _RP4R0 RPOR2bits.RP4R0
#define _RP4R1 RPOR2bits.RP4R1
#define _RP4R2 RPOR2bits.RP4R2
#define _RP4R3 RPOR2bits.RP4R3
#define _RP4R4 RPOR2bits.RP4R4
#define _RP4R5 RPOR2bits.RP4R5
#define _RP5R0 RPOR2bits.RP5R0
#define _RP5R1 RPOR2bits.RP5R1
#define _RP5R2 RPOR2bits.RP5R2
#define _RP5R3 RPOR2bits.RP5R3
#define _RP5R4 RPOR2bits.RP5R4
#define _RP5R5 RPOR2bits.RP5R5

/* RPOR3 */
#define _RP6R RPOR3bits.RP6R
#define _RP7R RPOR3bits.RP7R
#define _RP6R0 RPOR3bits.RP6R0
#define _RP6R1 RPOR3bits.RP6R1
#define _RP6R2 RPOR3bits.RP6R2
#define _RP6R3 RPOR3bits.RP6R3
#define _RP6R4 RPOR3bits.RP6R4
#define _RP6R5 RPOR3bits.RP6R5
#define _RP7R0 RPOR3bits.RP7R0
#define _RP7R1 RPOR3bits.RP7R1
#define _RP7R2 RPOR3bits.RP7R2
#define _RP7R3 RPOR3bits.RP7R3
#define _RP7R4 RPOR3bits.RP7R4
#define _RP7R5 RPOR3bits.RP7R5

/* RPOR4 */
#define _RP8R RPOR4bits.RP8R
#define _RP9R RPOR4bits.RP9R
#define _RP8R0 RPOR4bits.RP8R0
#define _RP8R1 RPOR4bits.RP8R1
#define _RP8R2 RPOR4bits.RP8R2
#define _RP8R3 RPOR4bits.RP8R3
#define _RP8R4 RPOR4bits.RP8R4
#define _RP8R5 RPOR4bits.RP8R5
#define _RP9R0 RPOR4bits.RP9R0
#define _RP9R1 RPOR4bits.RP9R1
#define _RP9R2 RPOR4bits.RP9R2
#define _RP9R3 RPOR4bits.RP9R3
#define _RP9R4 RPOR4bits.RP9R4
#define _RP9R5 RPOR4bits.RP9R5

/* RPOR5 */
#define _RP10R RPOR5bits.RP10R
#define _RP11R RPOR5bits.RP11R
#define _RP10R0 RPOR5bits.RP10R0
#define _RP10R1 RPOR5bits.RP10R1
#define _RP10R2 RPOR5bits.RP10R2
#define _RP10R3 RPOR5bits.RP10R3
#define _RP10R4 RPOR5bits.RP10R4
#define _RP10R5 RPOR5bits.RP10R5
#define _RP11R0 RPOR5bits.RP11R0
#define _RP11R1 RPOR5bits.RP11R1
#define _RP11R2 RPOR5bits.RP11R2
#define _RP11R3 RPOR5bits.RP11R3
#define _RP11R4 RPOR5bits.RP11R4
#define _RP11R5 RPOR5bits.RP11R5

/* RPOR6 */
#define _RP12R RPOR6bits.RP12R
#define _RP13R RPOR6bits.RP13R
#define _RP12R0 RPOR6bits.RP12R0
#define _RP12R1 RPOR6bits.RP12R1
#define _RP12R2 RPOR6bits.RP12R2
#define _RP12R3 RPOR6bits.RP12R3
#define _RP12R4 RPOR6bits.RP12R4
#define _RP12R5 RPOR6bits.RP12R5
#define _RP13R0 RPOR6bits.RP13R0
#define _RP13R1 RPOR6bits.RP13R1
#define _RP13R2 RPOR6bits.RP13R2
#define _RP13R3 RPOR6bits.RP13R3
#define _RP13R4 RPOR6bits.RP13R4
#define _RP13R5 RPOR6bits.RP13R5

/* RPOR7 */
#define _RP14R RPOR7bits.RP14R
#define _RP15R RPOR7bits.RP15R
#define _RP14R0 RPOR7bits.RP14R0
#define _RP14R1 RPOR7bits.RP14R1
#define _RP14R2 RPOR7bits.RP14R2
#define _RP14R3 RPOR7bits.RP14R3
#define _RP14R4 RPOR7bits.RP14R4
#define _RP14R5 RPOR7bits.RP14R5
#define _RP15R0 RPOR7bits.RP15R0
#define _RP15R1 RPOR7bits.RP15R1
#define _RP15R2 RPOR7bits.RP15R2
#define _RP15R3 RPOR7bits.RP15R3
#define _RP15R4 RPOR7bits.RP15R4
#define _RP15R5 RPOR7bits.RP15R5

/* RPOR8 */
#define _RP16R RPOR8bits.RP16R
#define _RP17R RPOR8bits.RP17R
#define _RP16R0 RPOR8bits.RP16R0
#define _RP16R1 RPOR8bits.RP16R1
#define _RP16R2 RPOR8bits.RP16R2
#define _RP16R3 RPOR8bits.RP16R3
#define _RP16R4 RPOR8bits.RP16R4
#define _RP16R5 RPOR8bits.RP16R5
#define _RP17R0 RPOR8bits.RP17R0
#define _RP17R1 RPOR8bits.RP17R1
#define _RP17R2 RPOR8bits.RP17R2
#define _RP17R3 RPOR8bits.RP17R3
#define _RP17R4 RPOR8bits.RP17R4
#define _RP17R5 RPOR8bits.RP17R5

/* RPOR9 */
#define _RP18R RPOR9bits.RP18R
#define _RP19R RPOR9bits.RP19R
#define _RP18R0 RPOR9bits.RP18R0
#define _RP18R1 RPOR9bits.RP18R1
#define _RP18R2 RPOR9bits.RP18R2
#define _RP18R3 RPOR9bits.RP18R3
#define _RP18R4 RPOR9bits.RP18R4
#define _RP18R5 RPOR9bits.RP18R5
#define _RP19R0 RPOR9bits.RP19R0
#define _RP19R1 RPOR9bits.RP19R1
#define _RP19R2 RPOR9bits.RP19R2
#define _RP19R3 RPOR9bits.RP19R3
#define _RP19R4 RPOR9bits.RP19R4
#define _RP19R5 RPOR9bits.RP19R5

/* RPOR10 */
#define _RP20R RPOR10bits.RP20R
#define _RP21R RPOR10bits.RP21R
#define _RP20R0 RPOR10bits.RP20R0
#define _RP20R1 RPOR10bits.RP20R1
#define _RP20R2 RPOR10bits.RP20R2
#define _RP20R3 RPOR10bits.RP20R3
#define _RP20R4 RPOR10bits.RP20R4
#define _RP20R5 RPOR10bits.RP20R5
#define _RP21R0 RPOR10bits.RP21R0
#define _RP21R1 RPOR10bits.RP21R1
#define _RP21R2 RPOR10bits.RP21R2
#define _RP21R3 RPOR10bits.RP21R3
#define _RP21R4 RPOR10bits.RP21R4
#define _RP21R5 RPOR10bits.RP21R5

/* RPOR11 */
#define _RP22R RPOR11bits.RP22R
#define _RP23R RPOR11bits.RP23R
#define _RP22R0 RPOR11bits.RP22R0
#define _RP22R1 RPOR11bits.RP22R1
#define _RP22R2 RPOR11bits.RP22R2
#define _RP22R3 RPOR11bits.RP22R3
#define _RP22R4 RPOR11bits.RP22R4
#define _RP22R5 RPOR11bits.RP22R5
#define _RP23R0 RPOR11bits.RP23R0
#define _RP23R1 RPOR11bits.RP23R1
#define _RP23R2 RPOR11bits.RP23R2
#define _RP23R3 RPOR11bits.RP23R3
#define _RP23R4 RPOR11bits.RP23R4
#define _RP23R5 RPOR11bits.RP23R5

/* RPOR12 */
#define _RP24R RPOR12bits.RP24R
#define _RP25R RPOR12bits.RP25R
#define _RP24R0 RPOR12bits.RP24R0
#define _RP24R1 RPOR12bits.RP24R1
#define _RP24R2 RPOR12bits.RP24R2
#define _RP24R3 RPOR12bits.RP24R3
#define _RP24R4 RPOR12bits.RP24R4
#define _RP24R5 RPOR12bits.RP24R5
#define _RP25R0 RPOR12bits.RP25R0
#define _RP25R1 RPOR12bits.RP25R1
#define _RP25R2 RPOR12bits.RP25R2
#define _RP25R3 RPOR12bits.RP25R3
#define _RP25R4 RPOR12bits.RP25R4
#define _RP25R5 RPOR12bits.RP25R5

/* RPOR13 */
#define _RP26R RPOR13bits.RP26R
#define _RP27R RPOR13bits.RP27R
#define _RP26R0 RPOR13bits.RP26R0
#define _RP26R1 RPOR13bits.RP26R1
#define _RP26R2 RPOR13bits.RP26R2
#define _RP26R3 RPOR13bits.RP26R3
#define _RP26R4 RPOR13bits.RP26R4
#define _RP26R5 RPOR13bits.RP26R5
#define _RP27R0 RPOR13bits.RP27R0
#define _RP27R1 RPOR13bits.RP27R1
#define _RP27R2 RPOR13bits.RP27R2
#define _RP27R3 RPOR13bits.RP27R3
#define _RP27R4 RPOR13bits.RP27R4
#define _RP27R5 RPOR13bits.RP27R5

/* RPOR14 */
#define _RP28R RPOR14bits.RP28R
#define _RP29R RPOR14bits.RP29R
#define _RP28R0 RPOR14bits.RP28R0
#define _RP28R1 RPOR14bits.RP28R1
#define _RP28R2 RPOR14bits.RP28R2
#define _RP28R3 RPOR14bits.RP28R3
#define _RP28R4 RPOR14bits.RP28R4
#define _RP28R5 RPOR14bits.RP28R5
#define _RP29R0 RPOR14bits.RP29R0
#define _RP29R1 RPOR14bits.RP29R1
#define _RP29R2 RPOR14bits.RP29R2
#define _RP29R3 RPOR14bits.RP29R3
#define _RP29R4 RPOR14bits.RP29R4
#define _RP29R5 RPOR14bits.RP29R5

/* RPOR15 */
#define _RP30R RPOR15bits.RP30R
#define _RP30R0 RPOR15bits.RP30R0
#define _RP30R1 RPOR15bits.RP30R1
#define _RP30R2 RPOR15bits.RP30R2
#define _RP30R3 RPOR15bits.RP30R3
#define _RP30R4 RPOR15bits.RP30R4
#define _RP30R5 RPOR15bits.RP30R5

/* RCON */
#define _POR RCONbits.POR
#define _BOR RCONbits.BOR
#define _IDLE RCONbits.IDLE
#define _SLEEP RCONbits.SLEEP
#define _WDTO RCONbits.WDTO
#define _SWDTEN RCONbits.SWDTEN
#define _SWR RCONbits.SWR
#define _EXTR RCONbits.EXTR
#define _VREGS RCONbits.VREGS
/* Bitname _CM cannot be defined because it is used by more than one SFR */
#define _DPSLP RCONbits.DPSLP
#define _RETEN RCONbits.RETEN
#define _IOPUWR RCONbits.IOPUWR
#define _TRAPR RCONbits.TRAPR

/* OSCCON */
#define _OSWEN OSCCONbits.OSWEN
#define _SOSCEN OSCCONbits.SOSCEN
#define _POSCEN OSCCONbits.POSCEN
#define _CF OSCCONbits.CF
#define _LOCK OSCCONbits.LOCK
#define _IOLOCK OSCCONbits.IOLOCK
#define _CLKLOCK OSCCONbits.CLKLOCK
#define _NOSC OSCCONbits.NOSC
#define _COSC OSCCONbits.COSC
#define _NOSC0 OSCCONbits.NOSC0
#define _NOSC1 OSCCONbits.NOSC1
#define _NOSC2 OSCCONbits.NOSC2
#define _COSC0 OSCCONbits.COSC0
#define _COSC1 OSCCONbits.COSC1
#define _COSC2 OSCCONbits.COSC2

/* CLKDIV */
#define _RCDIV CLKDIVbits.RCDIV
#define _DOZEN CLKDIVbits.DOZEN
#define _DOZE CLKDIVbits.DOZE
#define _ROI CLKDIVbits.ROI
#define _RCDIV0 CLKDIVbits.RCDIV0
#define _RCDIV1 CLKDIVbits.RCDIV1
#define _RCDIV2 CLKDIVbits.RCDIV2
#define _DOZE0 CLKDIVbits.DOZE0
#define _DOZE1 CLKDIVbits.DOZE1
#define _DOZE2 CLKDIVbits.DOZE2

/* OSCTUN */
#define _TUN OSCTUNbits.TUN
#define _TUN0 OSCTUNbits.TUN0
#define _TUN1 OSCTUNbits.TUN1
#define _TUN2 OSCTUNbits.TUN2
#define _TUN3 OSCTUNbits.TUN3
#define _TUN4 OSCTUNbits.TUN4
#define _TUN5 OSCTUNbits.TUN5

/* REFOCON */
#define _RODIV REFOCONbits.RODIV
#define _ROSEL REFOCONbits.ROSEL
#define _ROSSLP REFOCONbits.ROSSLP
#define _ROEN REFOCONbits.ROEN
#define _RODIV0 REFOCONbits.RODIV0
#define _RODIV1 REFOCONbits.RODIV1
#define _RODIV2 REFOCONbits.RODIV2
#define _RODIV3 REFOCONbits.RODIV3
#define _ROON REFOCONbits.ROON

/* HLVDCON */
#define _HLVDL HLVDCONbits.HLVDL
#define _IRVST HLVDCONbits.IRVST
#define _BGVST HLVDCONbits.BGVST
#define _VDIR HLVDCONbits.VDIR
#define _LSIDL HLVDCONbits.LSIDL
#define _HLVDEN HLVDCONbits.HLVDEN
#define _HLVDL0 HLVDCONbits.HLVDL0
#define _HLVDL1 HLVDCONbits.HLVDL1
#define _HLVDL2 HLVDCONbits.HLVDL2
#define _HLVDL3 HLVDCONbits.HLVDL3

/* DSCON */
#define _RELEASE DSCONbits.RELEASE
#define _DSBOR DSCONbits.DSBOR
#define _DSEN DSCONbits.DSEN

/* DSWAKE */
#define _DSMCLR DSWAKEbits.DSMCLR
#define _DSRTCC DSWAKEbits.DSRTCC
#define _DSWDT DSWAKEbits.DSWDT
#define _DSFLT DSWAKEbits.DSFLT
#define _DSINT0 DSWAKEbits.DSINT0

/* NVMCON */
#define _NVMOP NVMCONbits.NVMOP
#define _ERASE NVMCONbits.ERASE
#define _WRERR NVMCONbits.WRERR
#define _WREN NVMCONbits.WREN
#define _WR NVMCONbits.WR
#define _NVMOP0 NVMCONbits.NVMOP0
#define _NVMOP1 NVMCONbits.NVMOP1
#define _NVMOP2 NVMCONbits.NVMOP2
#define _NVMOP3 NVMCONbits.NVMOP3
#define _PROGOP0 NVMCONbits.PROGOP0
#define _PROGOP1 NVMCONbits.PROGOP1
#define _PROGOP2 NVMCONbits.PROGOP2
#define _PROGOP3 NVMCONbits.PROGOP3
#define _PROGOP NVMCONbits.PROGOP

/* RCON2 */
#define _VBAT RCON2bits.VBAT
#define _VBPOR RCON2bits.VBPOR
#define _VDDPOR RCON2bits.VDDPOR
#define _VDDBOR RCON2bits.VDDBOR

/* PMD1 */
#define _ADC1MD PMD1bits.ADC1MD
#define _SPI1MD PMD1bits.SPI1MD
#define _SPI2MD PMD1bits.SPI2MD
#define _U1MD PMD1bits.U1MD
#define _U2MD PMD1bits.U2MD
#define _I2C1MD PMD1bits.I2C1MD
#define _T1MD PMD1bits.T1MD
#define _T2MD PMD1bits.T2MD
#define _T3MD PMD1bits.T3MD
#define _T4MD PMD1bits.T4MD
#define _T5MD PMD1bits.T5MD

/* PMD2 */
#define _OC1MD PMD2bits.OC1MD
#define _OC2MD PMD2bits.OC2MD
#define _OC3MD PMD2bits.OC3MD
#define _OC4MD PMD2bits.OC4MD
#define _OC5MD PMD2bits.OC5MD
#define _OC6MD PMD2bits.OC6MD
#define _OC7MD PMD2bits.OC7MD
#define _IC1MD PMD2bits.IC1MD
#define _IC2MD PMD2bits.IC2MD
#define _IC3MD PMD2bits.IC3MD
#define _IC4MD PMD2bits.IC4MD
#define _IC5MD PMD2bits.IC5MD
#define _IC6MD PMD2bits.IC6MD
#define _IC7MD PMD2bits.IC7MD

/* PMD3 */
#define _I2C2MD PMD3bits.I2C2MD
#define _U3MD PMD3bits.U3MD
#define _CRCMD PMD3bits.CRCMD
#define _PMPMD PMD3bits.PMPMD
#define _RTCCMD PMD3bits.RTCCMD
#define _CMPMD PMD3bits.CMPMD
#define _TXMMD PMD3bits.TXMMD
#define _CRCPMD PMD3bits.CRCPMD
#define _DSMMD PMD3bits.DSMMD

/* PMD4 */
#define _LVDMD PMD4bits.LVDMD
#define _CTMUMD PMD4bits.CTMUMD
#define _REFOMD PMD4bits.REFOMD
#define _U4MD PMD4bits.U4MD
#define _UPWMMD PMD4bits.UPWMMD

/* PMD6 */
#define _SPI3MD PMD6bits.SPI3MD
#define _LCDMD PMD6bits.LCDMD

/* PMD7 */
#define _DMA0MD PMD7bits.DMA0MD
#define _DMA1MD PMD7bits.DMA1MD


/* ---------------------------------------------------------- */
/* Some useful macros for inline assembler instructions       */
/* ---------------------------------------------------------- */

#define Nop()    __builtin_nop()
#define ClrWdt() {__asm__ volatile ("clrwdt");}
#define Sleep()  {__asm__ volatile ("pwrsav #0");}
#define Idle()   {__asm__ volatile ("pwrsav #1");}

/*----------------------------------------------------------- */
/* Some useful macros for allocating data memory              */
/*----------------------------------------------------------- */

/* The following macros require an argument N that specifies  */
/* alignment. N must a power of two, minimum value = 2.       */
/* For example, to declare an uninitialized array that is     */
/* aligned to a 32 byte address:                              */
/*                                                            */
/* int _BSS(32) buf[16];                                      */
/*                                                            */
/* To declare an initialized array without special            */
/* alignment:                                                 */
/*                                                            */
/* int _DATA(2) table1[] = {0, 1, 1, 2, 3, 5, 8, 13, 21};     */
/*                                                            */
#define _BSS(N)    __attribute__((aligned(N)))
#define _DATA(N)   __attribute__((aligned(N)))

/* The following macros do not require an argument. They can  */
/* be used to locate a variable in persistent data memory or  */
/* in near data memory. For example, to declare two variables */
/* that retain their values across a device reset:            */
/*                                                            */
/* int _PERSISTENT var1,var2;                                 */
/*                                                            */
#define _PERSISTENT __attribute__((persistent))
#define _NEAR       __attribute__((near))

/* ---------------------------------------------------------- */
/* Some useful macros for declaring functions                 */
/* ---------------------------------------------------------- */

/* The following macros can be used to declare interrupt      */
/* service routines (ISRs). For example, to declare an ISR    */
/* for the timer1 interrupt:                                  */
/*                                                            */
/* void _ISR _T1Interrupt(void);                              */
/*                                                            */
/* To declare an ISR for the SPI1 interrupt with fast         */
/* context save:                                              */
/*                                                            */
/* void _ISRFAST _SPI1Interrupt(void);                        */
/*                                                            */
/* Note: ISRs will be installed into the interrupt vector     */
/* tables automatically if the reserved names listed in the   */
/* MPLAB C30 Compiler User's Guide (DS51284) are used.        */
/*                                                            */
#define _ISR __attribute__((interrupt))
#define _ISRFAST __attribute__((interrupt, shadow))

/* ---------------------------------------------------------- */
/* Some useful macros for changing the CPU IPL                */
/* ---------------------------------------------------------- */

/* The following macros can be used to modify the current CPU */
/* IPL. The definition of the macro may vary from device to   */
/* device.                                                    */
/*                                                            */
/* To safely set the CPU IPL, use SET_CPU_IPL(ipl); the       */
/* valid range of ipl is 0-7, it may be any expression.       */
/*                                                            */
/* SET_CPU_IPL(7);                                            */
/*                                                            */
/* To preserve the current IPL and save it use                */
/* SET_AND_SAVE_CPU_IPL(save_to, ipl); the valid range of ipl */
/* is 0-7 and may be any expression, save_to should denote    */
/* some temporary storage.                                    */
/*                                                            */
/* int old_ipl;                                               */
/*                                                            */
/* SET_AND_SAVE_CPU_IPL(old_ipl, 7);                          */
/*                                                            */
/* The IPL can be restored with RESTORE_CPU_IPL(saved_to)     */
/*                                                            */
/* RESTORE_CPU_IPL(old_ipl);                                  */

#define SET_CPU_IPL(ipl) {       \
  int DISI_save;                 \
                                 \
  DISI_save = DISICNT;           \
  asm volatile ("disi #0x3FFF"); \
  SRbits.IPL = ipl;              \
  DISICNT = DISI_save; } (void) 0;

#define SET_AND_SAVE_CPU_IPL(save_to, ipl) { \
  save_to = SRbits.IPL; \
  SET_CPU_IPL(ipl); } (void) 0;

#define RESTORE_CPU_IPL(saved_to) SET_CPU_IPL(saved_to)



/* -------------------------------------------------------- */
/* Macros for setting device configuration registers        */
/* -------------------------------------------------------- */

/* Register CONFIG4 (0x157f8)                               */

extern __attribute__((space(prog))) int _CONFIG4;
#define _CONFIG4(x) __attribute__((section("__CONFIG4.sec"),space(prog))) int _CONFIG4 = (x);

/*
** Only one invocation of CONFIG4 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set CONFIG4.
** Multiple options may be combined, as shown:
**
** _CONFIG4( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Deep Sleep Watchdog Timer Postscale Select bits:
**     DSWDTPS_DSWDTPS0     1:32 (1 mS)
**     DSWDTPS_DSWDTPS1     1:64 (2.1 mS)
**     DSWDTPS_DSWDTPS2     1:128 (4.1 mS)
**     DSWDTPS_DSWDTPS3     1: 256 (8.3 mS)
**     DSWDTPS_DSWDTPS4     1:512 (16.5 mS)
**     DSWDTPS_DSWDTPS5     1:1024 (33 mS)
**     DSWDTPS_DSWDTPS6     1:2048 (66.1 mS)
**     DSWDTPS_DSWDTPS7     1:4096 (132.1 mS)
**     DSWDTPS_DSWDTPS8     1:8192 (264.3 mS)
**     DSWDTPS_DSWDTPS9     1:16384 (528.5 mS)
**     DSWDTPS_DSWDTPSA     1:32768 (1.057 Secs)
**     DSWDTPS_DSWDTPSB     1:65536 (2.114 Secs)
**     DSWDTPS_DSWDTPSC     1:131072 (4.228 Secs)
**     DSWDTPS_DSWDTPSD     1:262114 (8.456 Secs)
**     DSWDTPS_DSWDTPSE     1:524288 (16.912 Secs)
**     DSWDTPS_DSWDTPSF     1:1048576 (33.825 Secs)
**     DSWDTPS_DSWDTPS10    1:2097152 (67.7 Secs)
**     DSWDTPS_DSWDTPS11    1:4194304 (135.3 Secs)
**     DSWDTPS_DSWDTPS12    1:8388608 (4.5 Minutes)
**     DSWDTPS_DSWDTPS13    1:16777216 (9 Minutes)
**     DSWDTPS_DSWDTPS14    1:33554432 (18 Minutes)
**     DSWDTPS_DSWDTPS15    1:67108864 (36.1 Minutes)
**     DSWDTPS_DSWDTPS16    1:134217728 (72.2 Minutes)
**     DSWDTPS_DSWDTPS17    1:268435456 (2.4 Hours)
**     DSWDTPS_DSWDTPS18    1:536870912 (4.8 Hours)
**     DSWDTPS_DSWDTPS19    1:1073741824 (9.6 Hours)
**     DSWDTPS_DSWDTPS1A    1:2147483648 (19.2 Hours)
**     DSWDTPS_DSWDTPS1B    1:4294967296 (38.5 Hours)
**     DSWDTPS_DSWDTPS1C    1:8589934592 (77 Hours)
**     DSWDTPS_DSWDTPS1D    1:17179869184 (6.4 Days)
**     DSWDTPS_DSWDTPS1E    1:34359738368 (12.8  Days)
**     DSWDTPS_DSWDTPS1F    1:68719476736 (25.7 Days)
**
**   DSWDT Reference Clock Select:
**     DSWDTOSC_SOSC        DSWDT uses SOSC as reference clock
**     DSWDTOSC_LPRC        DSWDT uses LPRC as reference clock
**
**   Deep Sleep BOR Enable bit:
**     DSBOREN_OFF          DSBOR Disabled
**     DSBOREN_ON           DSBOR Enabled
**
**   Deep Sleep Watchdog Timer Enable:
**     DSWDTEN_OFF          DSWDT Disabled
**     DSWDTEN_ON           DSWDT Enabled
**
**   DSEN Bit Enable:
**     DSSWEN_OFF           Deep Sleep operation is always disabled
**     DSSWEN_ON            Deep Sleep is controlled by the register bit DSEN
**
*/

#define DSWDTPS_DSWDTPS0     0xFFE0
#define DSWDTPS_DSWDTPS1     0xFFE1
#define DSWDTPS_DSWDTPS2     0xFFE2
#define DSWDTPS_DSWDTPS3     0xFFE3
#define DSWDTPS_DSWDTPS4     0xFFE4
#define DSWDTPS_DSWDTPS5     0xFFE5
#define DSWDTPS_DSWDTPS6     0xFFE6
#define DSWDTPS_DSWDTPS7     0xFFE7
#define DSWDTPS_DSWDTPS8     0xFFE8
#define DSWDTPS_DSWDTPS9     0xFFE9
#define DSWDTPS_DSWDTPSA     0xFFEA
#define DSWDTPS_DSWDTPSB     0xFFEB
#define DSWDTPS_DSWDTPSC     0xFFEC
#define DSWDTPS_DSWDTPSD     0xFFED
#define DSWDTPS_DSWDTPSE     0xFFEE
#define DSWDTPS_DSWDTPSF     0xFFEF
#define DSWDTPS_DSWDTPS10    0xFFF0
#define DSWDTPS_DSWDTPS11    0xFFF1
#define DSWDTPS_DSWDTPS12    0xFFF2
#define DSWDTPS_DSWDTPS13    0xFFF3
#define DSWDTPS_DSWDTPS14    0xFFF4
#define DSWDTPS_DSWDTPS15    0xFFF5
#define DSWDTPS_DSWDTPS16    0xFFF6
#define DSWDTPS_DSWDTPS17    0xFFF7
#define DSWDTPS_DSWDTPS18    0xFFF8
#define DSWDTPS_DSWDTPS19    0xFFF9
#define DSWDTPS_DSWDTPS1A    0xFFFA
#define DSWDTPS_DSWDTPS1B    0xFFFB
#define DSWDTPS_DSWDTPS1C    0xFFFC
#define DSWDTPS_DSWDTPS1D    0xFFFD
#define DSWDTPS_DSWDTPS1E    0xFFFE
#define DSWDTPS_DSWDTPS1F    0xFFFF

#define DSWDTOSC_SOSC        0xFFDF
#define DSWDTOSC_LPRC        0xFFFF

#define DSBOREN_OFF          0xFFBF
#define DSBOREN_ON           0xFFFF

#define DSWDTEN_OFF          0xFF7F
#define DSWDTEN_ON           0xFFFF

#define DSSWEN_OFF           0xFEFF
#define DSSWEN_ON            0xFFFF

/* Register CONFIG3 (0x157fa)                               */

extern __attribute__((space(prog))) int _CONFIG3;
#define _CONFIG3(x) __attribute__((section("__CONFIG3.sec"),space(prog))) int _CONFIG3 = (x);

/*
** Only one invocation of CONFIG3 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set CONFIG3.
** Multiple options may be combined, as shown:
**
** _CONFIG3( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Write Protection Flash Page Segment Boundary:
**     WPFP_WPFP0           Page 0 (0x00)
**     WPFP_WPFP1           Page 1 (0x400)
**     WPFP_WPFP2           Page 2 (0x800)
**     WPFP_WPFP3           Page 3 (0xC00)
**     WPFP_WPFP4           Page 4 (0x1000)
**     WPFP_WPFP5           Page 5 (0x1400)
**     WPFP_WPFP6           Page 6 (0x1800)
**     WPFP_WPFP7           Page 7 (0x1C00)
**     WPFP_WPFP8           Page 8 (0x2000)
**     WPFP_WPFP9           Page 9 (0x2400)
**     WPFP_WPFP10          Page 10 (0x2800)
**     WPFP_WPFP11          Page 11 (0x2C00)
**     WPFP_WPFP12          Page 12 (0x3000)
**     WPFP_WPFP13          Page 13 (0x3400)
**     WPFP_WPFP14          Page 14 (0x3800)
**     WPFP_WPFP15          Page 15 (0x3C00)
**     WPFP_WPFP16          Page 16 (0x4000)
**     WPFP_WPFP17          Page 17 (0x4400)
**     WPFP_WPFP18          Page 18 (0x4800)
**     WPFP_WPFP19          Page 19 (0x4C00)
**     WPFP_WPFP20          Page 20 (0x5000)
**     WPFP_WPFP21          Page 21 (0x5400)
**     WPFP_WPFP22          Page 22 (0x5800)
**     WPFP_WPFP23          Page 23 (0x5C00)
**     WPFP_WPFP24          Page 24 (0x6000)
**     WPFP_WPFP25          Page 25 (0x6400)
**     WPFP_WPFP26          Page 26 (0x6800)
**     WPFP_WPFP27          Page 27 (0x6C00)
**     WPFP_WPFP28          Page 28 (0x7000)
**     WPFP_WPFP29          Page 29 (0x7400)
**     WPFP_WPFP30          Page 30 (0x7800)
**     WPFP_WPFP31          Page 31 (0x7C00)
**     WPFP_WPFP32          Page 32 (0x8000)
**     WPFP_WPFP33          Page 33 (0x8400)
**     WPFP_WPFP34          Page 34 (0x8800)
**     WPFP_WPFP35          Page 35 (0x8C00)
**     WPFP_WPFP36          Page 36 (0x9000)
**     WPFP_WPFP37          Page 37 (0x9400)
**     WPFP_WPFP38          Page 38 (0x9800)
**     WPFP_WPFP39          Page 39 (0x9C00)
**     WPFP_WPFP40          Page 40 (0xA000)
**     WPFP_WPFP41          Page 41 (0xA400)
**     WPFP_WPFP42          Page 42 (0xA800)
**     WPFP_WPFP43          Page 43 (0xAC00)
**     WPFP_WPFP44          Page 44 (0xB000)
**     WPFP_WPFP45          Page 45 (0xB400)
**     WPFP_WPFP46          Page 46 (0xB800)
**     WPFP_WPFP47          Page 47 (0xBC00)
**     WPFP_WPFP48          Page 48 (0xC000)
**     WPFP_WPFP49          Page 49 (0xC400)
**     WPFP_WPFP50          Page 50 (0xC800)
**     WPFP_WPFP51          Page 51 (0xCC00)
**     WPFP_WPFP52          Page 52 (0xD000)
**     WPFP_WPFP53          Page 53 (0xD400)
**     WPFP_WPFP54          Page 54 (0xD800)
**     WPFP_WPFP55          Page 55 (0xDC00)
**     WPFP_WPFP56          Page 56 (0xE000)
**     WPFP_WPFP57          Page 57 (0xE400)
**     WPFP_WPFP58          Page 58 (0xE800)
**     WPFP_WPFP59          Page 59 (0xEC00)
**     WPFP_WPFP60          Page 60 (0xF000)
**     WPFP_WPFP61          Page 61 (0xF400)
**     WPFP_WPFP62          Page 62 (0xF800)
**     WPFP_WPFP63          Page 63 (0xFC00)
**     WPFP_WPFP64          Page 64 (0x10000)
**     WPFP_WPFP65          Page 65 (0x10400)
**     WPFP_WPFP66          Page 66 (0x10800)
**     WPFP_WPFP67          Page 67 (0x10C00)
**     WPFP_WPFP68          Page 68 (0x11000)
**     WPFP_WPFP69          Page 69 (0x11400)
**     WPFP_WPFP70          Page 70 (0x11800)
**     WPFP_WPFP71          Page 71 (0x11C00)
**     WPFP_WPFP72          Page 72 (0x12000)
**     WPFP_WPFP73          Page 73 (0x12400)
**     WPFP_WPFP74          Page 74 (0x12800)
**     WPFP_WPFP75          Page 75 (0x12C00)
**     WPFP_WPFP76          Page 76 (0x13000)
**     WPFP_WPFP77          Page 77 (0x13400)
**     WPFP_WPFP78          Page 78 (0x13800)
**     WPFP_WPFP79          Page 79 (0x13C00)
**     WPFP_WPFP80          Page 80 (0x14000)
**     WPFP_WPFP81          Page 81 (0x14400)
**     WPFP_WPFP82          Page 82 (0x14800)
**     WPFP_WPFP83          Page 83 (0x14C00)
**     WPFP_WPFP84          Page 84 (0x15000)
**     WPFP_WPFP85          Page 85 (0x15400)
**     WPFP_WPFP86          Page 86 (0x15800)
**     WPFP_WPFP87          Page 87 (0x15C00)
**     WPFP_WPFP88          Page 88 (0x16000)
**     WPFP_WPFP89          Page 89 (0x16400)
**     WPFP_WPFP90          Page 90 (0x16800)
**     WPFP_WPFP91          Page 91 (0x16C00)
**     WPFP_WPFP92          Page 92 (0x17000)
**     WPFP_WPFP93          Page 93 (0x17400)
**     WPFP_WPFP94          Page 94 (0x17800)
**     WPFP_WPFP95          Page 95 (0x17C00)
**     WPFP_WPFP96          Page 96 (0x18000)
**     WPFP_WPFP97          Page 97 (0x18400)
**     WPFP_WPFP98          Page 98 (0x18800)
**     WPFP_WPFP99          Page 99 (0x18C00)
**     WPFP_WPFP100         Page 100 (0x19000)
**     WPFP_WPFP101         Page 101 (0x19400)
**     WPFP_WPFP102         Page 102 (0x19800)
**     WPFP_WPFP103         Page 103 (0x19C00)
**     WPFP_WPFP104         Page 104 (0x1A000)
**     WPFP_WPFP105         Page 105 (0x1A400)
**     WPFP_WPFP106         Page 106 (0x1A800)
**     WPFP_WPFP107         Page 107 (0x1AC00)
**     WPFP_WPFP108         Page 108 (0x1B000)
**     WPFP_WPFP109         Page 109 (0x1B400)
**     WPFP_WPFP110         Page 110 (0x1B800)
**     WPFP_WPFP111         Page 111 (0x1BC00)
**     WPFP_WPFP112         Page 112 (0x1C000)
**     WPFP_WPFP113         Page 113 (0x1C400)
**     WPFP_WPFP114         Page 114 (0x1C800)
**     WPFP_WPFP115         Page 115 (0x1CC00)
**     WPFP_WPFP116         Page 116 (0x1D000)
**     WPFP_WPFP117         Page 117 (0x1D400)
**     WPFP_WPFP118         Page 118 (0x1D800)
**     WPFP_WPFP119         Page 119 (0x1DC00)
**     WPFP_WPFP120         Page 120 (0x1E000)
**     WPFP_WPFP121         Page 121 (0x1E400)
**     WPFP_WPFP122         Page 122 (0x1E800)
**     WPFP_WPFP123         Page 123 (0x1EC00)
**     WPFP_WPFP124         Page 124 (0x1F000)
**     WPFP_WPFP125         Page 125 (0x1F400)
**     WPFP_WPFP126         Page 126 (0x1F800)
**     WPFP_WPFP127         Page 127 (0x1FC00)
**
**   VBAT BOR enable bit:
**     VBTBOR_OFF           VBAT BOR disabled
**     VBTBOR_ON            VBAT BOR enabled
**
**   SOSC Selection bits:
**     SOSCSEL_OFF          Digital (SCLKI) mode
**     SOSCSEL_ON           SOSC circuit selected
**
**   Watch Dog Timer Window Width:
**     WDTWIN_PS75_0        Watch Dog Timer Window Width is 75 percent
**     WDTWIN_PS50_0        Watch Dog Timer Window Width is 50 percent
**     WDTWIN_PS37_5        Watch Dog Timer Window Width is 37.5 percent 
**     WDTWIN_PS25_0        Watch Dog Timer Window Width is 25 percent
**
**   Brown-out Reset Enable:
**     BOREN_OFF            Brown-out Reset Disabled
**     BOREN_ON             Brown-out Reset Enable
**
**   Segment Write Protection Disable:
**     WPDIS_WPEN           Enabled
**     WPDIS_WPDIS          Disabled
**
**   Write Protect Configuration Page Select:
**     WPCFG_WPCFGEN        Enabled
**     WPCFG_WPCFGDIS       Disabled
**
**   Segment Write Protection End Page Select:
**     WPEND_WPSTARTMEM     Write Protect from page 0 to WPFP
**     WPEND_WPENDMEM       Write Protect from WPFP to the last page of memory
**
*/

#define WPFP_WPFP0           0xFF80
#define WPFP_WPFP1           0xFF81
#define WPFP_WPFP2           0xFF82
#define WPFP_WPFP3           0xFF83
#define WPFP_WPFP4           0xFF84
#define WPFP_WPFP5           0xFF85
#define WPFP_WPFP6           0xFF86
#define WPFP_WPFP7           0xFF87
#define WPFP_WPFP8           0xFF88
#define WPFP_WPFP9           0xFF89
#define WPFP_WPFP10          0xFF8A
#define WPFP_WPFP11          0xFF8B
#define WPFP_WPFP12          0xFF8C
#define WPFP_WPFP13          0xFF8D
#define WPFP_WPFP14          0xFF8E
#define WPFP_WPFP15          0xFF8F
#define WPFP_WPFP16          0xFF90
#define WPFP_WPFP17          0xFF91
#define WPFP_WPFP18          0xFF92
#define WPFP_WPFP19          0xFF93
#define WPFP_WPFP20          0xFF94
#define WPFP_WPFP21          0xFF95
#define WPFP_WPFP22          0xFF96
#define WPFP_WPFP23          0xFF97
#define WPFP_WPFP24          0xFF98
#define WPFP_WPFP25          0xFF99
#define WPFP_WPFP26          0xFF9A
#define WPFP_WPFP27          0xFF9B
#define WPFP_WPFP28          0xFF9C
#define WPFP_WPFP29          0xFF9D
#define WPFP_WPFP30          0xFF9E
#define WPFP_WPFP31          0xFF9F
#define WPFP_WPFP32          0xFFA0
#define WPFP_WPFP33          0xFFA1
#define WPFP_WPFP34          0xFFA2
#define WPFP_WPFP35          0xFFA3
#define WPFP_WPFP36          0xFFA4
#define WPFP_WPFP37          0xFFA5
#define WPFP_WPFP38          0xFFA6
#define WPFP_WPFP39          0xFFA7
#define WPFP_WPFP40          0xFFA8
#define WPFP_WPFP41          0xFFA9
#define WPFP_WPFP42          0xFFAA
#define WPFP_WPFP43          0xFFAB
#define WPFP_WPFP44          0xFFAC
#define WPFP_WPFP45          0xFFAD
#define WPFP_WPFP46          0xFFAE
#define WPFP_WPFP47          0xFFAF
#define WPFP_WPFP48          0xFFB0
#define WPFP_WPFP49          0xFFB1
#define WPFP_WPFP50          0xFFB2
#define WPFP_WPFP51          0xFFB3
#define WPFP_WPFP52          0xFFB4
#define WPFP_WPFP53          0xFFB5
#define WPFP_WPFP54          0xFFB6
#define WPFP_WPFP55          0xFFB7
#define WPFP_WPFP56          0xFFB8
#define WPFP_WPFP57          0xFFB9
#define WPFP_WPFP58          0xFFBA
#define WPFP_WPFP59          0xFFBB
#define WPFP_WPFP60          0xFFBC
#define WPFP_WPFP61          0xFFBD
#define WPFP_WPFP62          0xFFBE
#define WPFP_WPFP63          0xFFBF
#define WPFP_WPFP64          0xFFC0
#define WPFP_WPFP65          0xFFC1
#define WPFP_WPFP66          0xFFC2
#define WPFP_WPFP67          0xFFC3
#define WPFP_WPFP68          0xFFC4
#define WPFP_WPFP69          0xFFC5
#define WPFP_WPFP70          0xFFC6
#define WPFP_WPFP71          0xFFC7
#define WPFP_WPFP72          0xFFC8
#define WPFP_WPFP73          0xFFC9
#define WPFP_WPFP74          0xFFCA
#define WPFP_WPFP75          0xFFCB
#define WPFP_WPFP76          0xFFCC
#define WPFP_WPFP77          0xFFCD
#define WPFP_WPFP78          0xFFCE
#define WPFP_WPFP79          0xFFCF
#define WPFP_WPFP80          0xFFD0
#define WPFP_WPFP81          0xFFD1
#define WPFP_WPFP82          0xFFD2
#define WPFP_WPFP83          0xFFD3
#define WPFP_WPFP84          0xFFD4
#define WPFP_WPFP85          0xFFD5
#define WPFP_WPFP86          0xFFD6
#define WPFP_WPFP87          0xFFD7
#define WPFP_WPFP88          0xFFD8
#define WPFP_WPFP89          0xFFD9
#define WPFP_WPFP90          0xFFDA
#define WPFP_WPFP91          0xFFDB
#define WPFP_WPFP92          0xFFDC
#define WPFP_WPFP93          0xFFDD
#define WPFP_WPFP94          0xFFDE
#define WPFP_WPFP95          0xFFDF
#define WPFP_WPFP96          0xFFE0
#define WPFP_WPFP97          0xFFE1
#define WPFP_WPFP98          0xFFE2
#define WPFP_WPFP99          0xFFE3
#define WPFP_WPFP100         0xFFE4
#define WPFP_WPFP101         0xFFE5
#define WPFP_WPFP102         0xFFE6
#define WPFP_WPFP103         0xFFE7
#define WPFP_WPFP104         0xFFE8
#define WPFP_WPFP105         0xFFE9
#define WPFP_WPFP106         0xFFEA
#define WPFP_WPFP107         0xFFEB
#define WPFP_WPFP108         0xFFEC
#define WPFP_WPFP109         0xFFED
#define WPFP_WPFP110         0xFFEE
#define WPFP_WPFP111         0xFFEF
#define WPFP_WPFP112         0xFFF0
#define WPFP_WPFP113         0xFFF1
#define WPFP_WPFP114         0xFFF2
#define WPFP_WPFP115         0xFFF3
#define WPFP_WPFP116         0xFFF4
#define WPFP_WPFP117         0xFFF5
#define WPFP_WPFP118         0xFFF6
#define WPFP_WPFP119         0xFFF7
#define WPFP_WPFP120         0xFFF8
#define WPFP_WPFP121         0xFFF9
#define WPFP_WPFP122         0xFFFA
#define WPFP_WPFP123         0xFFFB
#define WPFP_WPFP124         0xFFFC
#define WPFP_WPFP125         0xFFFD
#define WPFP_WPFP126         0xFFFE
#define WPFP_WPFP127         0xFFFF

#define VBTBOR_OFF           0xFF7F
#define VBTBOR_ON            0xFFFF

#define SOSCSEL_OFF          0xFEFF
#define SOSCSEL_ON           0xFFFF

#define WDTWIN_PS75_0        0xF3FF
#define WDTWIN_PS50_0        0xF7FF
#define WDTWIN_PS37_5        0xFBFF
#define WDTWIN_PS25_0        0xFFFF

#define BOREN_OFF            0xEFFF
#define BOREN_ON             0xFFFF

#define WPDIS_WPEN           0xDFFF
#define WPDIS_WPDIS          0xFFFF

#define WPCFG_WPCFGEN        0xBFFF
#define WPCFG_WPCFGDIS       0xFFFF

#define WPEND_WPSTARTMEM     0x7FFF
#define WPEND_WPENDMEM       0xFFFF

/* Register CONFIG2 (0x157fc)                               */

extern __attribute__((space(prog))) int _CONFIG2;
#define _CONFIG2(x) __attribute__((section("__CONFIG2.sec"),space(prog))) int _CONFIG2 = (x);

/*
** Only one invocation of CONFIG2 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set CONFIG2.
** Multiple options may be combined, as shown:
**
** _CONFIG2( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Primary Oscillator Select:
**     POSCMD_EC            External-Clock Mode Enabled
**     POSCMD_XT            XT Oscillator Enabled
**     POSCMD_HS            HS Oscillator Enabled
**     POSCMD_NONE          Primary Oscillator Disabled
**
**   IOLOCK One-Way Set Enable bit:
**     IOL1WAY_OFF          The IOLOCK bit can be set and cleared using the unlock sequence
**     IOL1WAY_ON           Once set, the IOLOCK bit cannot be cleared
**
**   OSCO Pin Configuration:
**     OSCIOFCN_ON          OSCO/CLKO/RC15 functions as port I/O (RC15)
**     OSCIOFCN_OFF         OSCO/CLKO/RC15 functions as CLKO (FOSC/2)
**
**   Clock Switching and Fail-Safe Clock Monitor Configuration bits:
**     FCKSM_CSECME         Clock switching is enabled, Fail-Safe Clock Monitor is enabled
**     FCKSM_CSECMD         Clock switching is enabled, Fail-Safe Clock Monitor is disabled
**     FCKSM_CSDCMD         Clock switching and Fail-Safe Clock Monitor are disabled
**
**   Initial Oscillator Select:
**     FNOSC_FRC            Fast RC Oscillator (FRC)
**     FNOSC_FRCPLL         Fast RC Oscillator with PLL module (FRCPLL)
**     FNOSC_PRI            Primary Oscillator (XT, HS, EC)
**     FNOSC_PRIPLL         Primary Oscillator with PLL module (XTPLL,HSPLL, ECPLL)
**     FNOSC_SOSC           Secondary Oscillator (SOSC)
**     FNOSC_LPRC           Low-Power RC Oscillator (LPRC)
**     FNOSC_FRCDIV         Fast RC Oscillator with Postscaler (FRCDIV)
**
**   Alternate VREF/CVREF Pins Selection bit:
**     ALTVREF_ALT_AV_ALT_CVVoltage reference input, ADC =RB0/RB1   Comparator =RB0/RB1
**     ALTVREF_ALT_AV_DLT_CVVoltage reference input, ADC =RB0/RB1   Comparator =RA9,RA10
**     ALTVREF_DLT_AV_ALT_CVVoltage reference input, ADC =RA9/RA10 Comparator =RB0,RB1
**     ALTVREF_DLT_AV_DLT_CVVoltage reference input, ADC =RA9/RA10 Comparator =RA9,RA10
**
**   Internal External Switchover:
**     IESO_OFF             Disabled
**     IESO_ON              Enabled
**
*/

#define POSCMD_EC            0xFFFC
#define POSCMD_XT            0xFFFD
#define POSCMD_HS            0xFFFE
#define POSCMD_NONE          0xFFFF

#define IOL1WAY_OFF          0xFFEF
#define IOL1WAY_ON           0xFFFF

#define OSCIOFCN_ON          0xFFDF
#define OSCIOFCN_OFF         0xFFFF

#define FCKSM_CSECME         0xFF3F
#define FCKSM_CSECMD         0xFF7F
#define FCKSM_CSDCMD         0xFFBF

#define FNOSC_FRC            0xF8FF
#define FNOSC_FRCPLL         0xF9FF
#define FNOSC_PRI            0xFAFF
#define FNOSC_PRIPLL         0xFBFF
#define FNOSC_SOSC           0xFCFF
#define FNOSC_LPRC           0xFDFF
#define FNOSC_FRCDIV         0xFFFF

#define ALTVREF_ALT_AV_ALT_CV 0xE7FF
#define ALTVREF_ALT_AV_DLT_CV 0xEFFF
#define ALTVREF_DLT_AV_ALT_CV 0xF7FF
#define ALTVREF_DLT_AV_DLT_CV 0xFFFF

#define IESO_OFF             0x7FFF
#define IESO_ON              0xFFFF

/* Register CONFIG1 (0x157fe)                               */

extern __attribute__((space(prog))) int _CONFIG1;
#define _CONFIG1(x) __attribute__((section("__CONFIG1.sec"),space(prog))) int _CONFIG1 = (x);

/*
** Only one invocation of CONFIG1 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set CONFIG1.
** Multiple options may be combined, as shown:
**
** _CONFIG1( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Watchdog Timer Postscaler Select:
**     WDTPS_PS1            1:1
**     WDTPS_PS2            1:2
**     WDTPS_PS4            1:4
**     WDTPS_PS8            1:8
**     WDTPS_PS16           1:16
**     WDTPS_PS32           1:32
**     WDTPS_PS64           1:64
**     WDTPS_PS128          1:128
**     WDTPS_PS256          1:256
**     WDTPS_PS512          1:512
**     WDTPS_PS1024         1:1,024
**     WDTPS_PS2048         1:2,048
**     WDTPS_PS4096         1:4,096
**     WDTPS_PS8192         1:8,192
**     WDTPS_PS16384        1:16,384
**     WDTPS_PS32768        1:32,768
**
**   WDT Prescaler Ratio Select:
**     FWPSA_PR32           1:32
**     FWPSA_PR128          1:128
**
**   Watchdog Timer Enable:
**     FWDTEN_WDT_DIS       WDT disabled in hardware; SWDTEN bit disabled
**     FWDTEN_WDT_ACT       WDT enabled only while device active and disabled in Sleep
**     FWDTEN_WDT_SW        WDT controlled with the SWDTEN bit
**     FWDTEN_WDT_HW        WDT enabled in hardware
**
**   Windowed WDT Disable:
**     WINDIS_ON            Windowed Watchdog Timer
**     WINDIS_OFF           Standard Watchdog Timer
**
**   Emulator Pin Placement Select bits:
**     ICS_PGx3             Emulator functions are shared with PGEC3/PGED3
**     ICS_PGx2             Emulator functions are shared with PGEC2/PGED2
**     ICS_PGx1             Emulator functions are shared with PGEC1/PGED1
**
**   Low power regulator control:
**     LPCFG_ON             Enabled
**     LPCFG_OFF            Disabled
**
**   General Segment Write Protect:
**     GWRP_ON              Enabled
**     GWRP_OFF             Disabled
**
**   General Segment Code Protect:
**     GCP_ON               Code protection is enabled
**     GCP_OFF              Code protection is disabled
**
**   JTAG Port Enable:
**     JTAGEN_OFF           Disabled
**     JTAGEN_ON            Enabled
**
*/

#define WDTPS_PS1            0x7FF0
#define WDTPS_PS2            0x7FF1
#define WDTPS_PS4            0x7FF2
#define WDTPS_PS8            0x7FF3
#define WDTPS_PS16           0x7FF4
#define WDTPS_PS32           0x7FF5
#define WDTPS_PS64           0x7FF6
#define WDTPS_PS128          0x7FF7
#define WDTPS_PS256          0x7FF8
#define WDTPS_PS512          0x7FF9
#define WDTPS_PS1024         0x7FFA
#define WDTPS_PS2048         0x7FFB
#define WDTPS_PS4096         0x7FFC
#define WDTPS_PS8192         0x7FFD
#define WDTPS_PS16384        0x7FFE
#define WDTPS_PS32768        0x7FFF

#define FWPSA_PR32           0x7FEF
#define FWPSA_PR128          0x7FFF

#define FWDTEN_WDT_DIS       0x7F9F
#define FWDTEN_WDT_ACT       0x7FBF
#define FWDTEN_WDT_SW        0x7FDF
#define FWDTEN_WDT_HW        0x7FFF

#define WINDIS_ON            0x7F7F
#define WINDIS_OFF           0x7FFF

#define ICS_PGx3             0x7DFF
#define ICS_PGx2             0x7EFF
#define ICS_PGx1             0x7FFF

#define LPCFG_ON             0x7BFF
#define LPCFG_OFF            0x7FFF

#define GWRP_ON              0x6FFF
#define GWRP_OFF             0x7FFF

#define GCP_ON               0x5FFF
#define GCP_OFF              0x7FFF

#define JTAGEN_OFF           0x3FFF
#define JTAGEN_ON            0x7FFF


#endif
