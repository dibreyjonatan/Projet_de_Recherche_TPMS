/*
  Copyright (c) 2009 - 2013 Freescale Semiconductor

  \file       "Interrupts.c"
  \brief      User interrupt routines.
  \author     Freescale Semiconductor
 
*/
#include "derivative.h" /* For register names                            */
#include "common.h"     /* For backwards compatibility, type declaration */
#include "main.h"       /* To link to main.                              */

/* SWI Interrupt */
void interrupt USER_1_INTERRUPT(void)
{
}

/* RESERVED - Don't use */
void interrupt USER_2_INTERRUPT(void)
{
}

/* LVD Interrupt */
void interrupt USER_3_INTERRUPT(void)
{
}

/* PWU Interrupt */
void interrupt USER_4_INTERRUPT(void)
{
  /* Clear all PWU Interrupt flags */
  PWUCS0_WUFACK = SET;
  PWUCS1_PRFACK = SET;           
}

/* TPM1CH0 Interrupt */
void interrupt USER_5_INTERRUPT(void)
{
}

/* TPM1CH1 Interrupt */
void interrupt USER_6_INTERRUPT(void)
{
}

/* TPM1 Interrupt */
void interrupt USER_7_INTERRUPT(void)
{
}

/* SMI Interrupt - Don't use */
void interrupt USER_8_INTERRUPT(void)
{
}

/* RFM Interrupt */
void interrupt USER_9_INTERRUPT(void)
{
}

/* ADC Interrupt - Don't use */
void interrupt USER_10_INTERRUPT(void)
{ 
}

/* LFR Interrupt */
void interrupt USER_11_INTERRUPT(void)
{
}

/* RTI Interrupt */
void interrupt USER_12_INTERRUPT(void)
{   
}

/* RESERVED - Don't use */
void interrupt USER_13_INTERRUPT(void)
{
}

/* RESERVED - Don't use */
void interrupt USER_14_INTERRUPT(void)
{
}

/* KBI Interrupt */
void interrupt USER_15_INTERRUPT(void)
{
}

void(* const USER_INTERRUPT_TABLE[])() @ 0xDFE0 =
{
  USER_15_INTERRUPT,
  USER_14_INTERRUPT,
  USER_13_INTERRUPT,
  USER_12_INTERRUPT,
  USER_11_INTERRUPT,
  USER_10_INTERRUPT,
  USER_9_INTERRUPT,
  USER_8_INTERRUPT,
  USER_7_INTERRUPT,
  USER_6_INTERRUPT,
  USER_5_INTERRUPT,
  USER_4_INTERRUPT,
  USER_3_INTERRUPT,
  USER_2_INTERRUPT,
  USER_1_INTERRUPT,
  main
};
/*
******************************************************************************
*
* End of file.
*
******************************************************************************
*/
