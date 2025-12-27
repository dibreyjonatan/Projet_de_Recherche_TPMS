#ifndef _TPMSDATA_H
#define _TPMSDATA_H


//轮胎位置定义
typedef enum{
  LF  = 0,
  RF  = 1,
  LB  = 2,
  RB  = 3,
  Unknown,
}E_Tyre_Position;

//由于在main.c中使用PT_TPMS_RF_DATA pt_TPMSData = (PT_TPMS_RF_DATA)TDA5235_FIFO;
//结构体指针直接指向TDA5235_FIFO数组空间
//所以下面结构体顺序和大小,需要与"发射的数据包结构"相匹配
typedef struct TPMS_RF_DATA {
  u8 DeviceID[4];
  u8 TyrePos;
  u8 Pressure[2];
  u8 Temperature;
  u8 Voltage;
  u8 AccelerationX[2];
  u8 AccelerationZ[2];
  u8 CRC8;
  u8 RESERVED[16];
}T_TPMS_RF_DATA,*PT_TPMS_RF_DATA;


float TPMS_Cal_Pressure(u8 *rawVal);
float TPMS_Cal_Temperature(u8 rawVal);
float TPMS_Cal_AccelerationX(u8 *rawVal);
float TPMS_Cal_AccelerationZ(u8 *rawVal);
float TPMS_Cal_Voltage(u8 rawVal);


#endif


