/*
  Copyright (c) 2008 - 2013 Freescale Semiconductor

  \file     	"main.h"
  \brief    	Sample project for FXTH87xxxx TPMS.
  \author   	Freescale Semiconductor
  \version    
  \date     	
  
*/
#ifndef _MAIN_H
#define _MAIN_H  /* MAIN_INCLUDED  */
/*****************************************************************************
 *
 * DEFINES 
 *
 ****************************************************************************/
/*
 ******************************************************************************
 *
 * Global Variables
 *
 ******************************************************************************
 */
#pragma DATA_SEG BATTERY_BACKED_RAM
extern UINT16 gu16UUMA[];
extern T_RDE tRDEData;
/*
 ******************************************************************************
 *
 * Function Prototypes
 *
 ******************************************************************************
 */
#pragma CODE_SEG DEFAULT
/*
 *******************************************************************************
 *
 * Function:          main()
 *
 */
/*!
 * \internal
 * \brief    main function.
 * \param    Nothing
 * \return   Void
 *
 *****************************************************************************/
void main(void);
/*
 *******************************************************************************
 *
 * Function:          vfnSetupMCU()
 *
 */
/*!
 * \brief    This function disables the COP and enables STOP.
 * \param    Nothing
 * \return   Void
 *
 *****************************************************************************/
void vfnSetupMCU(void);
/*
 *******************************************************************************
 *
 * Function:          vfnSetSTOPMode()
 *
 */
/*!
 * \brief    This function configures the MCU for either STOP1 or STOP4.
 * \param    UINT8 u8Mode: 1 for STOP1, 4 for STOP4.
 * \return   Void
 *
 *****************************************************************************/
void vfnSetSTOPMode(UINT8 u8Mode);
/*
 *******************************************************************************
 *
 * Function:          vfnSetPWU()
 *
 */
/*!
 * \brief    This function configures the PWU for a periodic wake-up.
 * \param    Nothing
 * \return   Void
 *
 *****************************************************************************/
void vfnSetPWU(void);
/*
 *******************************************************************************
 *
 * Function:          vfnSetRDE()
 *
 */
/*!
 * \brief    This function initializes the RDE array.
 * \param    tRDE* ptRDE: Pointer to global RDE data array
 * \return   Void
 *
 *****************************************************************************/
void vfnSetRDE(T_RDE* tRDE);

#pragma CODE_SEG DEFAULT
#endif /* MAIN_INCLUDED */
