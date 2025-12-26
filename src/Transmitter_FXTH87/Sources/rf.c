#include "derivative.h" /* include peripheral declarations */
#include "common.h"
#include "FXTH87xx11_Firmware_lnk.h"
#include "delay.h"

#define RF_DATA_LENGTH  (18)    //14Byte Data + 1Byte Sync + 3Byte Preamble

void RfInit(void)
{
  TPMS_RF_ENABLE(SET);

  //…Ë÷√≤®Ãÿ¬ 9600
  //Set Baudrate:9600
  RFCR0 = 51;

  //set to 80 for 128 bits - largest frame
  RFCR1=0x78;

  //Start data transmission or transmission in progress
  //Select the lower 16 bytes of the RFM data buffer
  //EOM bit times added
  //01110 set output power level to 5.0 dBm
  RFCR2 = 0x2E;

  // RF Output Low - RF Power UP - 5 Frame Transmitted
  RFCR3 = 0x05;
  

  //Base Timer = 50ms	
  RFCR4 = 0x32;

  //Pseudo-random number used(50ms)
  RFCR5 = 127;
  
  //VCO highest Power
  RFCR6 = 0x00;

  // RF Interrupt Disable - LVD Disable - RFM Not reset
  RFCR7 = 0x00;

  // fDATA0=fXTAL x ((12 + 4 x CF) + AFREQ/8192)
  //       = 26MHz x((12 + 4 x 1) + 5633(10110000 00001) /8192)
  //       = 433.8782

  // fDATA1=fXTAL x ((12 + 4 x CF) + BFREQ/8192)
  //       = 26MHz x((12 + 4 x 1) + 5659(10110000 11011) /8192)
  //       = 433.9607
  
  // 433.9607 - 433.8782 = 82.5kHz

  /* 434MHz */
  PLLCR0=0xB0;    // 1011 0000
                  //  AFREQ[12:5]

  PLLCR1=0x08;    //  00001      0   00     data non-inverted,Manchester encoded
                  //  AFREQ[4:0] POL CODE[1:0]                 

  PLLCR2=0xB0;    // 10110000

  PLLCR3=0xDE;    // 11011 110  CF=1 434MHz   MOD=1 FSK   CKREF=0 DX signal not generated
}

void RfSendMeg(UINT8 *u8RfData)
{
  UINT8 i=0;
  // Maximum length is 32 bytes; size of the RF buffer (in bytes)
  UINT8 u8RFDataForCS[32];
  
  RFCR7_RFIACK = SET;  // Clear all Flags

  u8RFDataForCS[i++] = (UINT8) (0x00);           // Preamble
  u8RFDataForCS[i++] = (UINT8) (0x00);           // Preamble
  u8RFDataForCS[i++] = (UINT8) (0x00);           // Preamble
  u8RFDataForCS[i++] = (UINT8) (0x15);           // Sync

  for(;i<RF_DATA_LENGTH;i++){
    u8RFDataForCS[i] = *u8RfData;
    u8RfData ++;
  }

  TPMS_RF_WRITE_DATA_REVERSE(RF_DATA_LENGTH, &(u8RFDataForCS[0]), 0u);

  TPMS_RF_SET_TX(RF_DATA_LENGTH*8);
}

