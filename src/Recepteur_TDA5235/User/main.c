#include "sys.h"
#include "clock.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "tim.h"

#include "oled.h"
#include "display.h"

#include "TDA5235.h"
#include "TDA5235_SFR.h"

#include "tpmsdata.h"


int main(void)
{

  Clock_Init();
  NVIC_Configuration();     
  delay_init();
  LED_Init();
  USART1_Init(115200);      

  Tim3_Init(1000,64);       
  TIM3_Cmd(ENABLE);


  OLED_Init(); 

  Display_Logo();  
  Display_Http();
  Display_Version();  

  //Display_User_ID_NULL();
  Display_Unique_ID_NULL();
  Display_RF_Receive_Mark();

  Display_Pressure(0); 
  Display_Temperature(0);
  Display_Acceleration(0);
  Display_Voltage(0);

  TDA5235_Init();
  TDA5235_SFR_Init();

  while(1)
  {
    if(TDA5235_FIFO_NUM){
      PT_TPMS_RF_DATA pt_TPMSData = (PT_TPMS_RF_DATA)TDA5235_FIFO;

      LED_ReceiveReverse();   
      Display_RF_Receive_Count_Plus();
      Display_Logo_Move();

      Display_Unique_ID(pt_TPMSData->DeviceID);
      Display_Tyre_Position(pt_TPMSData->TyrePos);
      Display_Pressure(TPMS_Cal_Pressure(pt_TPMSData->Pressure));
      Display_Temperature(TPMS_Cal_Temperature(pt_TPMSData->Temperature));
      Display_Acceleration(TPMS_Cal_AccelerationZ(pt_TPMSData->AccelerationZ));
      Display_Voltage(TPMS_Cal_Voltage(pt_TPMSData->Voltage));

      printf("*****************************\r\n");
      printf("Get a message:\r\n");
      printf("UniqueID     :%02X%02X%02X%02X\r\n",  pt_TPMSData->DeviceID[0],
                                                    pt_TPMSData->DeviceID[1],
                                                    pt_TPMSData->DeviceID[2],
                                                    pt_TPMSData->DeviceID[3]);
      printf("TyrePosition :%02X\r\n",pt_TPMSData->TyrePos);
      printf("Pressure     :%fkPa\r\n",TPMS_Cal_Pressure(pt_TPMSData->Pressure));
      printf("Temperature  :%f\r\n",TPMS_Cal_Temperature(pt_TPMSData->Temperature));
      printf("AccelerationX:%fg\r\n",TPMS_Cal_AccelerationX(pt_TPMSData->AccelerationX));
      printf("AccelerationZ:%fg\r\n",TPMS_Cal_AccelerationZ(pt_TPMSData->AccelerationZ));
      printf("Voltage      :%fv\r\n",TPMS_Cal_Voltage(pt_TPMSData->Voltage));
      printf("*****************************\r\n");
      TDA5235_FIFO_NUM = 0; 
    }
  }


}
