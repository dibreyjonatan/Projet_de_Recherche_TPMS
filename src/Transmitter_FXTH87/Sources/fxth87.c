#include "derivative.h" /* include peripheral declarations */
#include "common.h"
#include "FXTH87xx11_Firmware_lnk.h"
#include "delay.h"
#include "fxth87.h"

#define TYRE_POSITION (* (volatile UINT8 *) (0x0000DFC4))

UINT16 gu16UUMA[5]={0};

UINT8 GetDeviceID(UINT32 *u32Id)
{
  UINT8 u8Code[6];
  *u32Id = 0;  
  
  TPMS_READ_ID(u8Code);

  *u32Id |= (UINT32)u8Code[2] << 24;
  *u32Id |= (UINT32)u8Code[3] << 16;
  *u32Id |= (UINT32)u8Code[4] << 8;
  *u32Id |= (UINT32)u8Code[5];
  
  return 0;
}

UINT8 GetTyrePosition(UINT8 *u8TyrePos)
{
  *u8TyrePos = TYRE_POSITION;
  return 0;
}


UINT8 GetVoltage(UINT8 *u8CompVolt)
{
  UINT8 u8Res = 0;
  
  u8Res |= TPMS_READ_VOLTAGE(gu16UUMA);
  u8Res |= TPMS_COMP_VOLTAGE(u8CompVolt,gu16UUMA);
  

  return u8Res;
}

UINT8 GetTemperature(UINT8 *u8CompTemp)
{
  UINT8 u8Res = 0;
  
  u8Res |= TPMS_READ_TEMPERATURE(gu16UUMA);
  u8Res |= TPMS_COMP_TEMPERATURE(u8CompTemp,gu16UUMA);
 

  return u8Res;
}

UINT8 GetPressure(UINT16 *u16CompPressure)
{
  UINT8 u8Res = 0;
  
  // ( Measurement Pressure For 4 samples)
  u8Res |= TPMS_READ_PRESSURE(gu16UUMA,4);
  u8Res |= TPMS_COMP_PRESSURE(u16CompPressure,gu16UUMA);

  return u8Res;
}

UINT8 GetAccelerationX(UINT16 *u16CompAccelX)
{
  UINT8 u8Res = 0;

  u8Res |= TPMS_READ_ACCEL_X (gu16UUMA, 1u, CLEAR, 7u); // Offset 7    
  u8Res |= TPMS_COMP_ACCEL_X (u16CompAccelX, gu16UUMA);
 
  return u8Res;
}

UINT8 GetAccelerationZ(UINT16 *u16CompAccelZ)
{
  UINT8 u8Res = 0;
  
  u8Res |= TPMS_READ_ACCEL_Z (gu16UUMA, 1u, CLEAR, 6u); // Offset 6    
  u8Res |= TPMS_COMP_ACCEL_Z (u16CompAccelZ, gu16UUMA); 
 

  return u8Res;
}


