#ifndef _FXTH87_H
#define _FXTH87_H

typedef struct{
  UINT32 DeviceID;
  UINT8 TyrePos;
  UINT16 Pressure;
  UINT8 Temperature;
  UINT8 Voltage;
  UINT16 AccelerationX;
  UINT16 AccelerationZ;
  UINT8 CRC;
}tFXTH87; 


UINT8 GetDeviceID(UINT32 *u32Id);
UINT8 GetTyrePosition(UINT8 *eTyrePos);
UINT8 GetVoltage(UINT8 *u8CompVolt);
UINT8 GetTemperature(UINT8 *u8CompTemp);
UINT8 GetPressure(UINT16 *u16CompPressure);
UINT8 GetAccelerationX(UINT16 *u16CompAccelX);
UINT8 GetAccelerationZ(UINT16 *u16CompAccelZ);


#endif

