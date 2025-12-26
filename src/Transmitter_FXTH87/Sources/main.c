#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "common.h"
#include "FXTH87xx11_Firmware_lnk.h"
#include "main.h"

#include "delay.h"
#include "rf.h"
#include "printf.h"
#include "fxth87.h"

#include <stdio.h>

void main(void) 
{
  UINT8 u8Res = 0;
  tFXTH87 tFxth87Data;

  vfnSetupMCU();
  EnableInterrupts;

  PrintfInit();
  (void)printf("System reboot\r\n");

  RfInit();

  for(;;) 
  {
    __RESET_WATCHDOG();
    
    (void)printf("**************************************\r\n");
    (void)printf("FXTH87xx RF TPMS Data Test\r\n");

    u8Res = GetDeviceID(&tFxth87Data.DeviceID);
    u8Res = GetTyrePosition(&tFxth87Data.TyrePos);
    u8Res = GetPressure(&tFxth87Data.Pressure);
    u8Res = GetTemperature(&tFxth87Data.Temperature);    
    u8Res = GetVoltage(&tFxth87Data.Voltage);
    u8Res = GetAccelerationX(&tFxth87Data.AccelerationX);
    u8Res = GetAccelerationZ(&tFxth87Data.AccelerationZ);
    tFxth87Data.CRC = TPMS_CRC8((UINT8 *)&tFxth87Data,sizeof(tFxth87Data)-1,0xAA);
    
    RfSendMeg((UINT8 *)&tFxth87Data);
    
    (void)printf("Affichage de la donnee transmise\r\n");
    (void)printf("ID : %d\r\n",tFxth87Data.DeviceID );
    (void)printf("Position pneu : %d\r\n",tFxth87Data.TyrePos);
    (void)printf("Pressure comp value : %d\r\n",tFxth87Data.Pressure);
    (void)printf("Temperature comp value : %d\r\n",tFxth87Data.Temperature);
    (void)printf("Voltage comp value : %d\r\n",tFxth87Data.Voltage);
    (void)printf("Acceleration X comp value : %d\r\n",tFxth87Data.AccelerationX);
    (void)printf("Acceleration Z comp value : %d\r\n",tFxth87Data.AccelerationZ);
    (void)printf("CRC calculee : %d\r\n",tFxth87Data.CRC);
    
    (void)printf("**************************************\r\n\r\n");
    // attente de 1s
    DelayMSec(250);
    DelayMSec(250);
    DelayMSec(250);
    DelayMSec(250);
    DelayMSec(250);
   
  } /* loop forever */
}


/*
 ******************************************************************************
 *
 *                        vfnSetupMCU
 *
 ******************************************************************************
 */
void vfnSetupMCU(void)
{
   /* enable bandgap for V, T measurements, enable stop4 mode */   
  SPMSC1  = (SPMSC1_BGBE_MASK | SPMSC1_LVDE_MASK | SPMSC1_LVDSE_MASK);
  
  /* enable STOP mode, Enable RFM, disable COP */
  SIMOPT1 = ((SIMOPT1_STOPE_MASK | SIMOPT1_RFEN_MASK | SIMOPT1_BKGDPE_MASK) \
            & (~((UINT8)SIMOPT1_COPE_MASK)));
}



