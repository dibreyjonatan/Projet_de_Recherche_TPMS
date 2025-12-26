#include "derivative.h" /* include peripheral declarations */
#include "common.h"


/*
 ******************************************************************************
 * vfnWaitMSec
 ******************************************************************************
 */
void DelayMSec(UINT8 u8MSec)
{
  /* Divide counter by 16 to have an effective 250kHz clock coming into TPM */
  TPM1SC_PS = ((UINT8)TPM1SC_PS2_MASK);
  
  /* Make the Modulo 250 so that it triggers every MSec */
  /* The explicit cast to word is to make MISRA happy - TPM1MOD is declared */
  /* as word in the header file                                             */
  TPM1MOD = (word)((UINT16)250u * (UINT16)u8MSec);
  
  /* Clear the last count */
  (void)TPM1CNTL; // does not seem to work
  TPM1CNT = 0; // this works

  /* Ensure no interrupts */
  TPM1SC_TOIE = CLEAR;

  /* Trigger by connecting the clock to the module */
  TPM1SC_CLKSA = SET;
  
  while((UINT8)CLEAR == TPM1SC_TOF)
  {
    /* Wait */
  }
  
  /* Remove the clock source */
  TPM1SC = CLEAR;
  
  return;
}


