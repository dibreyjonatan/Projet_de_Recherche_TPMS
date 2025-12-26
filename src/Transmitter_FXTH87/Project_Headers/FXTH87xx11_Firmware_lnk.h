/*
  Copyright (c) 2008 - 2014 Freescale Semiconductor

  \file     	"FXTH87xx11_Firmware_lnk.h"
  \brief    	This file links user code with firmware found within the 
                2-axis TPMS devices.
  \author   	Freescale Semiconductor
  \version      1.0
  \date     	19 Dec 2013
  
*/

#ifndef FXTH87XX22_FIRMWARE_LNK_H_
#define FXTH87XX22_FIRMWARE_LNK_H_
/*
 ******************************************************************************
 *
 * User's firmware wrappers. Refer to corresponding firmware function 
 * definitions for explanations.
 *
 ******************************************************************************
 */
/* Jump table */
#define JMP_RESET              ((UINT16)0xE000) 
#define JMP_READ_VOLT          ((UINT16)0xE003) 
#define JMP_COMP_VOLT          ((UINT16)0xE006) 
#define JMP_READ_TEMP          ((UINT16)0xE009) 
#define JMP_COMP_TEMP          ((UINT16)0xE00C) 
#define JMP_READ_PRESSURE      ((UINT16)0xE00F) 
#define JMP_COMP_PRESSURE      ((UINT16)0xE012) 
#define JMP_READ_ACCEL_X       ((UINT16)0xE015)
#define JMP_READ_DYN_X         ((UINT16)0xE018) 
#define JMP_COMP_X             ((UINT16)0xE01B)
#define JMP_READ_ACCEL_Z       ((UINT16)0xE01E) 
#define JMP_READ_DYN_Z         ((UINT16)0xE021) 
#define JMP_COMP_Z             ((UINT16)0xE024) 
#define JMP_READ_ACCEL_XZ      ((UINT16)0xE027) 
#define JMP_READ_DYN_XZ        ((UINT16)0xE02A) 
#define JMP_COMP_XZ            ((UINT16)0xE02D) 
#define JMP_READ_V0            ((UINT16)0xE030) 
#define JMP_READ_V1            ((UINT16)0xE033) 
#define JMP_LFOCAL             ((UINT16)0xE036) 
#define JMP_MFOCAL             ((UINT16)0xE039)
#define JMP_RF_ENABLE          ((UINT16)0xE03C)
#define JMP_RF_RESET           ((UINT16)0xE03F) 
#define JMP_RF_READ_DATA       ((UINT16)0xE042) 
#define JMP_RF_READ_DATA_R     ((UINT16)0xE045) 
#define JMP_RF_WRITE_DATA      ((UINT16)0xE048) 
#define JMP_RF_WRITE_DATA_R    ((UINT16)0xE04B) 
#define JMP_RF_CONFIG_DATA     ((UINT16)0xE04E)
/* Reserved */
#define JMP_RF_SET_TX          ((UINT16)0xE054) 
#define JMP_RF_DYN_POWER       ((UINT16)0xE057)
#define JMP_MSG_INIT           ((UINT16)0xE05A) 
#define JMP_MSG_READ           ((UINT16)0xE05D) 
#define JMP_MSG_WRITE          ((UINT16)0xE060) 
#define JMP_CHECKSUM_XOR       ((UINT16)0xE063) 
#define JMP_CRC8               ((UINT16)0xE066) 
#define JMP_CRC16              ((UINT16)0xE069) 
#define JMP_SQRT               ((UINT16)0xE06C) 
#define JMP_READ_ID            ((UINT16)0xE06F) 
#define JMP_LF_ENABLE          ((UINT16)0xE072) 
#define JMP_LF_READ_DATA       ((UINT16)0xE075) 
#define JMP_WIRE_AND_ADC_CHECK ((UINT16)0xE078) 
#define JMP_FLASH_WRITE        ((UINT16)0xE07B) 
#define JMP_FLASH_CHECK        ((UINT16)0xE07E) 
#define JMP_FLASH_ERASE        ((UINT16)0xE081) 
#define JMP_FLASH_PROTECT      ((UINT16)0xE084)
/* Reserved */
#define JMP_MULT_SIGN_INT16    ((UINT16)0xE08A)
#define JMP_WAVG               ((UINT16)0xE08D) 
#define JMP_RDE                ((UINT16)0xE090)

/* Fn definitions */

/* void TPMS_RESET(void) */
#define TPMS_RESET                  ((void(*)(void))(JMP_RESET))

/* UINT8 TPMS_READ_VOLTAGE(UINT16 *u16UUMA) */
#define  TPMS_READ_VOLTAGE           ((UINT8(*)(UINT16*))(JMP_READ_VOLT))   

/* UINT8 TPMS_COMP_VOLTAGE(UINT8 *u8CompVoltage, *UINT16 u16UUMA) */
#define  TPMS_COMP_VOLTAGE           ((UINT8(*)(UINT8*, UINT16*))(JMP_COMP_VOLT))

/* UINT8 TPMS_READ_TEMPERATURE(UINT16 *u16UUMA) */
#define  TPMS_READ_TEMPERATURE       ((UINT8(*)(UINT16*))(JMP_READ_TEMP))

/* UINT8 TPMS_COMP_TEMPERATURE(UINT8 *u8Temp, UINT16 *u16UUMA) */
#define  TPMS_COMP_TEMPERATURE       ((UINT8(*)(UINT8*, UINT16*))(JMP_COMP_TEMP))

/* UINT8 TPMS_READ_PRESSURE(UINT16 *u16UUMA, UINT8 u8Avg) */
#define  TPMS_READ_PRESSURE          ((UINT8(*)(UINT16*, UINT8))(JMP_READ_PRESSURE))

/* UINT8 TPMS_COMP_PRESSURE(UINT16 *u16CompPressure, UINT16 *u16UUMA) */
#define  TPMS_COMP_PRESSURE          ((UINT8(*)(UINT16*, UINT16*))(JMP_COMP_PRESSURE))  

/* UINT8 TPMS_READ_ACCEL_X(UINT16 *u16UUMA, UINT8 u8Avg, UINT8 u8FiltSelect, UINT8 u8DynamicOffset) */
#define  TPMS_READ_ACCEL_X           ((UINT8(*)(UINT16*, UINT8, UINT8, UINT8))(JMP_READ_ACCEL_X))

/* UINT8 TPMS_READ_DYNAMIC_ACCEL_X(UINT8 u8Filter, UINT8* u8Offset, UINT16* u16UUMA) */
#define  TPMS_READ_DYNAMIC_ACCEL_X     ((UINT8(*)(UINT8, UINT8*, UINT16*))(JMP_READ_DYN_X))

/* UINT8 TPMS_COMP_ACCEL_X(UINT16 *u16CompAccelX, UINT16* u16UUMA) */
#define  TPMS_COMP_ACCEL_X             ((UINT8(*)(UINT16*, UINT16*))(JMP_COMP_X))

/* UINT8 TPMS_READ_ACCEL_Z(UINT16 *u16UUMA, UINT8 u8Avg, UINT8 u8FiltSelect, UINT8 u8DynamicOffset) */
#define  TPMS_READ_ACCEL_Z           ((UINT8(*)(UINT16*, UINT8, UINT8, UINT8))(JMP_READ_ACCEL_Z))

/* UINT8 TPMS_READ_DYNAMIC_ACCEL_Z(UINT8 u8Filter, UINT8* u8Offset, UINT16* u16UUMA) */
#define  TPMS_READ_DYNAMIC_ACCEL_Z     ((UINT8(*)(UINT8, UINT8*, UINT16*))(JMP_READ_DYN_Z))

/* UINT8 TPMS_COMP_ACCEL_Z(UINT16 *u16CompAccelX, UINT16* u16UUMA) */
#define  TPMS_COMP_ACCEL_Z             ((UINT8(*)(UINT16*, UINT16*))(JMP_COMP_Z))

/* UINT8 TPMS_READ_ACCEL_XZ(UINT16 *u16UUMA, UINT8 u8Avg, UINT8 u8FiltSelect, UINT8 u8DynamicOffsetX, UINT8 u8DynamicOffsetZ) */
#define  TPMS_READ_ACCEL_XZ           ((UINT8(*)(UINT16*, UINT8, UINT8, UINT8, UINT8))(JMP_READ_ACCEL_XZ))

/* UINT8 TPMS_READ_DYNAMIC_ACCEL_XZ(UINT8 u8Filter, UINT8* u8OffsetX, UINT8* u8OffsetZ, UINT16* u16UUMA) */
#define  TPMS_READ_DYNAMIC_ACCEL_XZ     ((UINT8(*)(UINT8, UINT8*, UINT8*, UINT16*))(JMP_READ_DYN_XZ))

/* UINT8 TPMS_COMP_ACCEL_XZ(UINT16 *u16CompAccelX, UINT16* u16UUMA) */
#define  TPMS_COMP_ACCEL_XZ             ((UINT8(*)(UINT16*, UINT16*))(JMP_COMP_XZ))

/* UINT8 TPMS_READ_V0(UINT16 *u16Result, UINT8 u8Avg) */
#define  TPMS_READ_V0                ((UINT8(*)(UINT16*, UINT8))(JMP_READ_V0))

/* UINT8 TPMS_READ_V1(UINT16 *u16Result, UINT8 u8Avg) */
#define  TPMS_READ_V1                ((UINT8(*)(UINT16*, UINT8))(JMP_READ_V1))

/* UINT8 TPMS_LFOCAL(void) */
#define  TPMS_LFOCAL		             ((UINT8(*)(void))(JMP_LFOCAL))	

/* UINT8 TPMS_MFOCAL(void) */
#define  TPMS_MFOCAL		             ((UINT8(*)(void))(JMP_MFOCAL))

/* UINT8 TPMS_RF_ENABLE(UINT8 u8Switch) */
#define  TPMS_RF_ENABLE              ((void(*)(UINT8))(JMP_RF_ENABLE))

/* void  TPMS_RF_RESET(void) */
#define  TPMS_RF_RESET               ((void(*)(void))(JMP_RF_RESET))

/* void  TPMS_RF_READ_DATA(UINT8 u8Size, UINT8 *u8RAMBuffer, UINT8 u8RFMBuffer) */
#define  TPMS_RF_READ_DATA			     ((void(*)(UINT8, UINT8*, UINT8))(JMP_RF_READ_DATA))

/* void  TPMS_RF_READ_DATA_REVERSE(UINT8 u8Size, UINT8 *u8RAMBuffer, UINT8 u8RFMBuffer) */
#define  TPMS_RF_READ_DATA_REVERSE   ((void(*)(UINT8, UINT8*, UINT8))(JMP_RF_READ_DATA_R))

/* void  TPMS_RF_WRITE_DATA(UINT8 u8Size, UINT8 *u8RAMBuffer, UINT8 u8RFMBuffer) */
#define  TPMS_RF_WRITE_DATA          ((void(*)(UINT8, UINT8*, UINT8))(JMP_RF_WRITE_DATA))

/* void  TPMS_RF_WRITE_DATA_REVERSE(UINT8 u8Size, UINT8 *u8RAMBuffer, UINT8 u8RFMBuffer) */
#define  TPMS_RF_WRITE_DATA_REVERSE  ((void(*)(UINT8, UINT8*, UINT8))(JMP_RF_WRITE_DATA_R))

/* void  TPMS_RF_CONFIG_DATA(UINT16 *u16RFParam) */
#define  TPMS_RF_CONFIG_DATA         ((void(*)(UINT16*))(JMP_RF_CONFIG_DATA))

/* void  TPMS_RF_SET_TX(UINT8 u8BufferSize) */
#define  TPMS_RF_SET_TX	             ((void(*)(UINT8))(JMP_RF_SET_TX))

/* void  TPMS_RF_DYNAMIC_POWER(UINT8 u8CompT, UINT8 u8CompV, UINT8* pu8PowerManagement) */
#define  TPMS_RF_DYNAMIC_POWER       ((void(*)(UINT8, UINT8, UINT8*))(JMP_RF_DYN_POWER))

/* void  TPMS_MSG_INIT(void) */
#define  TPMS_MSG_INIT               ((void(*)(void))(JMP_MSG_INIT))

/* UINT8 TPMS_MSG_WRITE(UINT8 u8SendByte) */
#define  TPMS_MSG_WRITE		           ((UINT8(*)(UINT8))(JMP_MSG_WRITE))

/* UINT8 TPMS_MSG_READ(void) */ 
#define  TPMS_MSG_READ		           ((UINT8(*)(void))(JMP_MSG_READ))

/* UINT8 TPMS_CHECKSUM_XOR(UINT8 *u8Buffer, UINT8 u8Size, UINT8 u8Checksum) */
#define  TPMS_CHECKSUM_XOR           ((UINT8(*)(UINT8*, UINT8, UINT8))(JMP_CHECKSUM_XOR))

/* UINT8 TPMS_CRC8(UINT8 *u8Buffer, UINT16 u16BufferSize, UINT8 u8Remainder) */
#define  TPMS_CRC8				           ((UINT8(*)(UINT8*, UINT16, UINT8))(JMP_CRC8))

/* UINT16 TPMS_CRC16(UINT8 *u8Buffer, UINT16 u16MByteSize, UINT16 u16Remainder) */
#define  TPMS_CRC16				           ((UINT16(*)(UINT16*, UINT16, UINT16))(JMP_CRC16))

/* UINT16 TPMS_SQUARE_ROOT(UINT16 u16Process) */
#define  TPMS_SQUARE_ROOT	           ((UINT16(*)(UINT16))(JMP_SQRT))

/* void  TPMS_READ_ID(UINT8 *u8Code) */
#define  TPMS_READ_ID		             ((void(*)(UINT8*))(JMP_READ_ID))

/* void  TPMS_LF_ENABLE(UINT8 u8Switch) */
#define  TPMS_LF_ENABLE		           ((void(*)(UINT8))(JMP_LF_ENABLE))

/* UINT8 TPMS_LF_READ_DATA(UINT8 *u8Buffer, UINT8 u8Count) */
#define  TPMS_LF_READ_DATA           ((UINT8(*)(UINT8*, UINT8))(JMP_LF_READ_DATA))

/* UINT8 TPMS_WIRE_AND_ADC_CHECK(UINT8 u8TestMask) */
#define  TPMS_WIRE_AND_ADC_CHECK     ((UINT8(*)(UINT8))(JMP_WIRE_AND_ADC_CHECK))

/* void  TPMS_FLASH_WRITE(UINT16 u16Address, UINT8* u8Buffer, UINT8 u8Size) */
#define  TPMS_FLASH_WRITE            ((void(*)(UINT16, UINT8*, UINT8))(JMP_FLASH_WRITE))

/* UINT16 TPMS_FLASH_CHECK(void) */
#define  TPMS_FLASH_CHECK            ((UINT16(*)(void))(JMP_FLASH_CHECK))

/* UINT8 TPMS_FLASH_ERASE(UINT16 u16Address) */
#define  TPMS_FLASH_ERASE            ((UINT8(*)(UINT16))(JMP_FLASH_ERASE))

/* UINT8 TPMS_FLASH_PROTECTION(UINT8 u8Range, UINT16 u16Key) */
#define  TPMS_FLASH_PROTECTION       ((UINT8(*)(UINT8, UINT16))(JMP_FLASH_PROTECT))

/* void  TPMS_MULT_SIGN_INT16(INT16 i16Mult1, INT16 i16Mult2, INT32* pi32Result) */
#define  TPMS_MULT_SIGN_INT16        ((void(*)(INT16, INT16, INT32*))(JMP_MULT_SIGN_INT16))

/* UINT16 TPMS_WAVG(UINT8 u8Avg, UINT16 u16POld, UINT8 u8PNew) */
#define  TPMS_WAVG                   ((UINT16(*)(UINT8, UINT16, UINT8))(JMP_WAVG))

/* UINT8 TPMS_RDE_ADJUST_PRESSURE(UINT16* pu16UUMA, T_RDE* ptRDEValues) */
#define  TPMS_RDE_ADJUST_PRESSURE  ((UINT8(*)(UINT16*, T_RDE*))(JMP_RDE))
         

/* Universal Uncompensated Measurement Array Index */
enum
{
  UUMA_VOLT = 0u, UUMA_TEMP, UUMA_PRESSURE, UUMA_X, UUMA_Z
};

/* Dynamic acceleration G-level offset index */
enum
{
  Z_LEVEL_OFFSET_N210 = 0u,
  Z_LEVEL_OFFSET_N180,
  Z_LEVEL_OFFSET_N150,
  Z_LEVEL_OFFSET_N120,
  Z_LEVEL_OFFSET_N90,
  Z_LEVEL_OFFSET_N60,
  Z_LEVEL_OFFSET_N30,
  Z_LEVEL_OFFSET_0,
  Z_LEVEL_OFFSET_30,
  Z_LEVEL_OFFSET_60,
  Z_LEVEL_OFFSET_90,
  Z_LEVEL_OFFSET_120,
  Z_LEVEL_OFFSET_150,
  Z_LEVEL_OFFSET_180,
  Z_LEVEL_OFFSET_210,
  Z_LEVEL_OFFSET_240
};

enum
{
  X_LEVEL_OFFSET_N70 = 0u,
  X_LEVEL_OFFSET_N60,
  X_LEVEL_OFFSET_N50,
  X_LEVEL_OFFSET_N40,
  X_LEVEL_OFFSET_N30,
  X_LEVEL_OFFSET_N20,
  X_LEVEL_OFFSET_N10,
  X_LEVEL_OFFSET_0,
  X_LEVEL_OFFSET_10,
  X_LEVEL_OFFSET_20,
  X_LEVEL_OFFSET_30,
  X_LEVEL_OFFSET_40,
  X_LEVEL_OFFSET_50,
  X_LEVEL_OFFSET_60,
  X_LEVEL_OFFSET_70,
  X_LEVEL_OFFSET_80
};
#endif /* FXTH87XX11_FIRMWARE_LNK_H_ */
