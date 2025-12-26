#include "derivative.h" /* include peripheral declarations */
#include "common.h"
#include "printf.h"

static void UartDelayABit(void);

void PrintfInit(void)
{
  TX_PE = 1;
  TX_DD = 1;
  TX_DAT = 1;
}

void PrintfDeInit(void)
{
  TX_PE = 0;
  TX_DD = 0;
  TX_DAT = 0;
}

//模拟发送串口波形
//simulation to send serial waveform
void PrintfChar(char data)
{
  UINT8 i;

  TX_DAT = 1;  

  //发送起始位(Send a start bit)
  TX_DAT = 0;
  UartDelayABit();

  //发送数据,低位优先(Send datas LSB)
  for(i=0;i<8;i++)
  {
    if(data & 0x01) TX_DAT = 1;
    else TX_DAT = 0;
    data >>= 1;
    
    UartDelayABit();
  }

  //发送停止位(Send a stop bit)
  TX_DAT = 1;
  UartDelayABit();

}

//依据波特率计算等待一个Bit的时间
//Calculate a bit time according to Baudrate
static void UartDelayABit(void)
{
  /* Divide counter by 8 to have an effective 500kHz clock coming into TPM */
  TPM1SC_PS = ((UINT8)TPM1SC_CLKSx_BITNUM);
  
  /* Make the Modulo 250 so that it triggers every MSec */
  /* The explicit cast to word is to make MISRA happy - TPM1MOD is declared */
  /* as word in the header file                                             */
  TPM1MOD = (word)(BAUDRATE_TIME);
  
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
}

//实现printf的底层函数
//Use printf,the function is necessary
void TERMIO_PutChar(char c)
{
	PrintfChar(c);
}

