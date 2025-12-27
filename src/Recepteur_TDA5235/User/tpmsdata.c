#include "sys.h"
#include "CRC.h"
#include "tpmsdata.h"

//T = ¡÷P900 * Pcode + (100 - ¡÷P900) = (Pcode - 1) * ¡÷P900 + 100
//¡÷P900 = 1.572 kPa/count (@100-900 kPa range)
float TPMS_Cal_Pressure(u8 *rawVal)
{
  s16 rawValTemp = ((s16)rawVal[0] << 8) | rawVal[1];

  return (rawValTemp-1) * 1.572 + 100;
}

//T = ¡÷T  * TCODE ¨C 55
//¡÷T = 1¡ãC/count
float TPMS_Cal_Temperature(u8 rawVal)
{
  return rawVal * 1.0 - 55;
}

//VINT = ¡÷VINT  * VCODE + 1.22(V)
//¡÷VINT = 10mV/count
float TPMS_Cal_Voltage(u8 rawVal)
{
  return rawVal * 0.010 + 1.22;
}

//¡÷Ax-7 = (10 - (-10)) / 510 = 0.0392 Per Axcode integer
//Ax = ¡÷Ax-7 * Axcode + (-10) - ¡÷Ax-7 = ¡÷Ax-7 * (Axcode - 1) - 10
float TPMS_Cal_AccelerationX(u8 *rawVal)
{
  s16 rawValTemp = ((s16)rawVal[0] << 8) | rawVal[1];

  return 0.0392 * (rawValTemp - 1) - 10;
}

//¡÷Az-6 = (30 - (-30)) / 510 = 0.1176 Per Azcode integer
//Az = ¡÷Az-6 * Azcode + (-30) - ¡÷Az-6 = ¡÷Az-6 * (Azcode - 1) - 30
float TPMS_Cal_AccelerationZ(u8 *rawVal)
{
  s16 rawValTemp = ((s16)rawVal[0] << 8) | rawVal[1];

  return 0.1176 * (rawValTemp - 1) - 30;
}




