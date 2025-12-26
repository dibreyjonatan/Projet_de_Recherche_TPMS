/*
  Copyright (c) 2008 - 2013 Freescale Semiconductor

  \file     	"main.h"
  \brief    	Common defines and typedefs to be used in project
                development.
  \author   	Freescale Semiconductor
  \version    
  \date     	
  
*/

#ifndef COMMON_H_
#define COMMON_H_
/*
 ******************************************************************************
 *
 *  General bit positions.
 *
 ******************************************************************************
 */
#define BIT0	((UINT8)1u)
#define BIT1	((UINT8)2u)
#define BIT2	((UINT8)4u)
#define BIT3	((UINT8)8u)
#define BIT4	((UINT8)16u)
#define BIT5	((UINT8)32u)
#define BIT6	((UINT8)64u)
#define BIT7	((UINT8)128u)
/*
 ******************************************************************************
 *
 *  Define SET and CLEAR.
 *
 ******************************************************************************
 */
#ifndef CLEAR
#define CLEAR 0u
#endif
#ifndef SET
#define SET   1u
#endif
/*
 ******************************************************************************
 *
 * The following defines bits in the STATUS byte.
 *
 ******************************************************************************
 */
#define OVERFLOWERROR BIT0
#define BONDINGERROR  BIT1
#define PCELLERROR    BIT2
#define XGCELLERROR   BIT3
#define ZGCELLERROR   BIT4
#define VOLTERROR     BIT5
#define TEMPERROR     BIT6
#define ADCERROR      BIT7
/*
 ******************************************************************************
 *
 * The following define STOP mode entries.
 *
 ******************************************************************************
 */  
#define STOP1 ((UINT8)1u) 
#define STOP4 ((UINT8)4u)
/*
 ******************************************************************************
 *
 * Next defines are used for backwards compatibility with MXPY8500/MPXY8600
 * projects.
 *
 ******************************************************************************
 */
#define KBISC_KBMIOD       KBISC_KBMOD
#define KBISC_KBIMOD_MASK  KBISC_KBMOD_MASK
#define RFCR7_RFIACK       RFCR7_RFIAK
#define RFCR7_RFIACK_MASK  RFCR7_RFIAK_MASK
#define PWUCS0_WUFACK      PWUCS0_WUFAK
#define PWUCS0_WUFACK_MASK PWUCS0_WUFAK_MASK
#define PWUCS1_PRFACK      PWUCS1_PRFAK
#define PWUCS1_PRFACK_MASK PWUCS1_PRFAK_MASK
         
/*
 ******************************************************************************
 *
 *  General typedefs.
 *
 ******************************************************************************
 */
typedef unsigned char  UINT8;
typedef   signed char   INT8;
typedef unsigned short UINT16;
typedef   signed short  INT16;
typedef unsigned long  UINT32;
typedef   signed long   INT32;

typedef struct 
{    
  UINT8 Prescaler     : 8; /* RFCR0 */
  UINT8 Modulation    : 1;
  UINT8 Frequency     : 1; 
  UINT8 Encoding      : 2; /* CODE - Manchester, BiPhase, NRZ or Direct */
  UINT8               : 2; 
  UINT8 Polarity      : 1; 
  UINT8 EndOfMessage  : 1; 
  UINT16 PllA; 
  UINT16 PllB;
} T_RFDATA;

typedef struct 
{
  UINT16 u16CompPress;      /* I/O 9-bit Compensated pressure reading   */
  UINT8  u8ElapsedTime;     /* I Elapsed time from previous reading     */
  UINT16 u16WAvg;           /* O Weighed average for running pressure   */
  UINT8  u8PRes;            /* O 8-bit pressure reserve value           */
  UINT8  u8PMin;            /* O 8-bit minimum pressure value           */
  UINT8  u8RDEStatusFlags;  /* O Contains flags for Plock and RDE Event */
  UINT16 u16RDEBailTimeOut; /* O Seconds to 60 mins bail-out            */
  UINT8  u8RDETimeToAvg;    /* O Seconds to next averaging event        */
} T_RDE;

/*
 ******************************************************************************
 *
 *  Global variables used by firmware. Must be declared somewhere in the code.
 *
 ******************************************************************************
 */
#pragma DATA_SEG FMW_BATTERY_BACKED_RAM
extern UINT8 TPMS_CONT_ACCEL_GV  @ 0x008Eu; /* Embedded Firmware maps this location */
extern UINT8 TPMS_INTERRUPT_FLAG @ 0x008Fu; /* Embedded Firmware maps this location */
#pragma DATA_SEG DEFAULT

#endif /* COMMON_H_ */
