/* Based on CPU DB FXTH870000, version 3.00.000 (RegistersPrg V2.33) */
/*
** ###################################################################
**     Filename  : fxth870000.h
**     Processor : FXTH870000
**     FileFormat: V2.33
**     DataSheet : Rev. 1.0 06/2013
**     Compiler  : CodeWarrior compiler
**     Date/Time : 12/20/2013, 2:02 PM
**     Abstract  :
**         This header implements the mapping of I/O devices.
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
**
**     CPU Registers Revisions:
**               - none
**
**     File-Format-Revisions:
**      - 10.9.2009, V2.30 :
**               - Fixed generation of registers arrays.
**      - 15.10.2009, V2.31 :
**               - HCS08 family: Bits and bit-groups are published for 16-bit registers: 8-bit overlay registers are required.
**      - 18.05.2010, V2.32 :
**               - MISRA compliance: U/UL suffixes added to all numbers (_MASK,_BITNUM and addresses)
**      - 15.09.2010, V2.33 :
**               - Empty union is not generated for data overlapping registers, cause there is no bit access
**
**     Not all general-purpose I/O pins are available on all packages or on all mask sets of a specific
**     derivative device. To avoid extra current drain from floating input pins, the user’s reset
**     initialization routine in the application program must either enable on-chip pull-up devices
**     or change the direction of unconnected pins to outputs so the pins do not float.
** ###################################################################
*/

#ifndef _FXTH870000_H
#define _FXTH870000_H

/*lint -save  -e950 -esym(960,18.4) -e46 -esym(961,19.7) Disable MISRA rule (1.1,18.4,6.4,19.7) checking. */
/* Types definition */
typedef unsigned char byte;
typedef unsigned int word;
typedef unsigned long dword;
typedef unsigned long dlong[2];

/* Watchdog reset macro */
#ifndef __RESET_WATCHDOG
#ifdef _lint
  #define __RESET_WATCHDOG()  /* empty */
#else
  #define __RESET_WATCHDOG() {asm sta SRS;}
#endif
#endif /* __RESET_WATCHDOG */

#define REG_BASE 0x0000                /* Base address for the I/O register block */


#pragma MESSAGE DISABLE C1106 /* WARNING C1106: Non-standard bitfield type */

/**************** interrupt vector numbers ****************/
#define VectorNumber_Vkbi               15U
#define VectorNumber_VReserved14        14U
#define VectorNumber_VReserved13        13U
#define VectorNumber_Vrti               12U
#define VectorNumber_Vlfrcvr            11U
#define VectorNumber_Vadc1              10U
#define VectorNumber_Vrfm               9U
#define VectorNumber_Vsmi               8U
#define VectorNumber_Vtpm1ovf           7U
#define VectorNumber_Vtpm1ch1           6U
#define VectorNumber_Vtpm1ch0           5U
#define VectorNumber_Vwuktmr            4U
#define VectorNumber_Vlvd               3U
#define VectorNumber_VReserved2         2U
#define VectorNumber_Vswi               1U
#define VectorNumber_Vreset             0U

/**************** interrupt vector table ****************/
#define Vkbi                            0xDFE0U
#define VReserved14                     0xDFE2U
#define VReserved13                     0xDFE4U
#define Vrti                            0xDFE6U
#define Vlfrcvr                         0xDFE8U
#define Vadc1                           0xDFEAU
#define Vrfm                            0xDFECU
#define Vsmi                            0xDFEEU
#define Vtpm1ovf                        0xDFF0U
#define Vtpm1ch1                        0xDFF2U
#define Vtpm1ch0                        0xDFF4U
#define Vwuktmr                         0xDFF6U
#define Vlvd                            0xDFF8U
#define VReserved2                      0xDFFAU
#define Vswi                            0xDFFCU
#define Vreset                          0xDFFEU

/**************** registers I/O map ****************/

/*** PTAD - Port A Data Register; 0x00000000 ***/
typedef union {
  byte Byte;
  struct {
    byte PTAD0       :1;                                       /* Port A Data Register Bit 0 */
    byte PTAD1       :1;                                       /* Port A Data Register Bit 1 */
    byte PTAD2       :1;                                       /* Port A Data Register Bit 2 */
    byte PTAD3       :1;                                       /* Port A Data Register Bit 3 */
    byte PTAD4       :1;                                       /* Port A Data Register Bit 4 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTAD :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTADSTR;
extern volatile PTADSTR _PTAD @0x00000000;
#define PTAD                            _PTAD.Byte
#define PTAD_PTAD0                      _PTAD.Bits.PTAD0
#define PTAD_PTAD1                      _PTAD.Bits.PTAD1
#define PTAD_PTAD2                      _PTAD.Bits.PTAD2
#define PTAD_PTAD3                      _PTAD.Bits.PTAD3
#define PTAD_PTAD4                      _PTAD.Bits.PTAD4
#define PTAD_PTAD                       _PTAD.MergedBits.grpPTAD

#define PTAD_PTAD0_MASK                 1U
#define PTAD_PTAD1_MASK                 2U
#define PTAD_PTAD2_MASK                 4U
#define PTAD_PTAD3_MASK                 8U
#define PTAD_PTAD4_MASK                 16U
#define PTAD_PTAD_MASK                  31U
#define PTAD_PTAD_BITNUM                0U


/*** PTAPE - Port A Pull Enable Register; 0x00000001 ***/
typedef union {
  byte Byte;
  struct {
    byte PTAPE0      :1;                                       /* Internal Pull Enable for Port A Bit 0 */
    byte PTAPE1      :1;                                       /* Internal Pull Enable for Port A Bit 1 */
    byte PTAPE2      :1;                                       /* Internal Pull Enable for Port A Bit 2 */
    byte PTAPE3      :1;                                       /* Internal Pull Enable for Port A Bit 3 */
    byte PTAPE4      :1;                                       /* Internal Pull Enable for Port A Bit 4 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTAPE :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTAPESTR;
extern volatile PTAPESTR _PTAPE @0x00000001;
#define PTAPE                           _PTAPE.Byte
#define PTAPE_PTAPE0                    _PTAPE.Bits.PTAPE0
#define PTAPE_PTAPE1                    _PTAPE.Bits.PTAPE1
#define PTAPE_PTAPE2                    _PTAPE.Bits.PTAPE2
#define PTAPE_PTAPE3                    _PTAPE.Bits.PTAPE3
#define PTAPE_PTAPE4                    _PTAPE.Bits.PTAPE4
#define PTAPE_PTAPE                     _PTAPE.MergedBits.grpPTAPE

#define PTAPE_PTAPE0_MASK               1U
#define PTAPE_PTAPE1_MASK               2U
#define PTAPE_PTAPE2_MASK               4U
#define PTAPE_PTAPE3_MASK               8U
#define PTAPE_PTAPE4_MASK               16U
#define PTAPE_PTAPE_MASK                31U
#define PTAPE_PTAPE_BITNUM              0U


/*** PTADD - Port A Data Direction Register; 0x00000003 ***/
typedef union {
  byte Byte;
  struct {
    byte PTADD0      :1;                                       /* Data Direction for Port A Bit 0 */
    byte PTADD1      :1;                                       /* Data Direction for Port A Bit 1 */
    byte PTADD2      :1;                                       /* Data Direction for Port A Bit 2 */
    byte PTADD3      :1;                                       /* Data Direction for Port A Bit 3 */
    byte PTADD4      :1;                                       /* Data Direction for Port A Bit 4 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTADD :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTADDSTR;
extern volatile PTADDSTR _PTADD @0x00000003;
#define PTADD                           _PTADD.Byte
#define PTADD_PTADD0                    _PTADD.Bits.PTADD0
#define PTADD_PTADD1                    _PTADD.Bits.PTADD1
#define PTADD_PTADD2                    _PTADD.Bits.PTADD2
#define PTADD_PTADD3                    _PTADD.Bits.PTADD3
#define PTADD_PTADD4                    _PTADD.Bits.PTADD4
#define PTADD_PTADD                     _PTADD.MergedBits.grpPTADD

#define PTADD_PTADD0_MASK               1U
#define PTADD_PTADD1_MASK               2U
#define PTADD_PTADD2_MASK               4U
#define PTADD_PTADD3_MASK               8U
#define PTADD_PTADD4_MASK               16U
#define PTADD_PTADD_MASK                31U
#define PTADD_PTADD_BITNUM              0U


/*** PTBD - Port B Data Register; 0x00000004 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBD0       :1;                                       /* Port B Data Register Bit 0 */
    byte PTBD1       :1;                                       /* Port B Data Register Bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTBD :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTBDSTR;
extern volatile PTBDSTR _PTBD @0x00000004;
#define PTBD                            _PTBD.Byte
#define PTBD_PTBD0                      _PTBD.Bits.PTBD0
#define PTBD_PTBD1                      _PTBD.Bits.PTBD1
#define PTBD_PTBD                       _PTBD.MergedBits.grpPTBD

#define PTBD_PTBD0_MASK                 1U
#define PTBD_PTBD1_MASK                 2U
#define PTBD_PTBD_MASK                  3U
#define PTBD_PTBD_BITNUM                0U


/*** PTBPE - Port B Pull Enable Register; 0x00000005 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBPE0      :1;                                       /* Internal Pull Enable for Port B Bit 0 */
    byte PTBPE1      :1;                                       /* Internal Pull Enable for Port B Bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTBPE :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTBPESTR;
extern volatile PTBPESTR _PTBPE @0x00000005;
#define PTBPE                           _PTBPE.Byte
#define PTBPE_PTBPE0                    _PTBPE.Bits.PTBPE0
#define PTBPE_PTBPE1                    _PTBPE.Bits.PTBPE1
#define PTBPE_PTBPE                     _PTBPE.MergedBits.grpPTBPE

#define PTBPE_PTBPE0_MASK               1U
#define PTBPE_PTBPE1_MASK               2U
#define PTBPE_PTBPE_MASK                3U
#define PTBPE_PTBPE_BITNUM              0U


/*** PTBDD - Port B Data Direction Register; 0x00000007 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBDD0      :1;                                       /* Data Direction for Port B Bit 0 */
    byte PTBDD1      :1;                                       /* Data Direction for Port B Bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTBDD :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTBDDSTR;
extern volatile PTBDDSTR _PTBDD @0x00000007;
#define PTBDD                           _PTBDD.Byte
#define PTBDD_PTBDD0                    _PTBDD.Bits.PTBDD0
#define PTBDD_PTBDD1                    _PTBDD.Bits.PTBDD1
#define PTBDD_PTBDD                     _PTBDD.MergedBits.grpPTBDD

#define PTBDD_PTBDD0_MASK               1U
#define PTBDD_PTBDD1_MASK               2U
#define PTBDD_PTBDD_MASK                3U
#define PTBDD_PTBDD_BITNUM              0U


/*** KBISC - KBI Status and Control Register; 0x0000000C ***/
typedef union {
  byte Byte;
  struct {
    byte KBMOD       :1;                                       /* Keyboard Detection Mode */
    byte KBIE        :1;                                       /* Keyboard Interrupt Enable */
    byte KBACK       :1;                                       /* Keyboard Interrupt Acknowledge */
    byte KBF         :1;                                       /* Keyboard Interrupt Flag */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} KBISCSTR;
extern volatile KBISCSTR _KBISC @0x0000000C;
#define KBISC                           _KBISC.Byte
#define KBISC_KBMOD                     _KBISC.Bits.KBMOD
#define KBISC_KBIE                      _KBISC.Bits.KBIE
#define KBISC_KBACK                     _KBISC.Bits.KBACK
#define KBISC_KBF                       _KBISC.Bits.KBF

#define KBISC_KBMOD_MASK                1U
#define KBISC_KBIE_MASK                 2U
#define KBISC_KBACK_MASK                4U
#define KBISC_KBF_MASK                  8U


/*** KBIPE - KBI Pin Enable Register; 0x0000000D ***/
typedef union {
  byte Byte;
  struct {
    byte KBIPE0      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 0 */
    byte KBIPE1      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 1 */
    byte KBIPE2      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 2 */
    byte KBIPE3      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpKBIPE :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} KBIPESTR;
extern volatile KBIPESTR _KBIPE @0x0000000D;
#define KBIPE                           _KBIPE.Byte
#define KBIPE_KBIPE0                    _KBIPE.Bits.KBIPE0
#define KBIPE_KBIPE1                    _KBIPE.Bits.KBIPE1
#define KBIPE_KBIPE2                    _KBIPE.Bits.KBIPE2
#define KBIPE_KBIPE3                    _KBIPE.Bits.KBIPE3
#define KBIPE_KBIPE                     _KBIPE.MergedBits.grpKBIPE

#define KBIPE_KBIPE0_MASK               1U
#define KBIPE_KBIPE1_MASK               2U
#define KBIPE_KBIPE2_MASK               4U
#define KBIPE_KBIPE3_MASK               8U
#define KBIPE_KBIPE_MASK                15U
#define KBIPE_KBIPE_BITNUM              0U


/*** KBIES - KBI Edge Select Register; 0x0000000E ***/
typedef union {
  byte Byte;
  struct {
    byte KBEDG0      :1;                                       /* Keyboard Edge Select Bit 0 */
    byte KBEDG1      :1;                                       /* Keyboard Edge Select Bit 1 */
    byte KBEDG2      :1;                                       /* Keyboard Edge Select Bit 2 */
    byte KBEDG3      :1;                                       /* Keyboard Edge Select Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpKBEDG :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} KBIESSTR;
extern volatile KBIESSTR _KBIES @0x0000000E;
#define KBIES                           _KBIES.Byte
#define KBIES_KBEDG0                    _KBIES.Bits.KBEDG0
#define KBIES_KBEDG1                    _KBIES.Bits.KBEDG1
#define KBIES_KBEDG2                    _KBIES.Bits.KBEDG2
#define KBIES_KBEDG3                    _KBIES.Bits.KBEDG3
#define KBIES_KBEDG                     _KBIES.MergedBits.grpKBEDG

#define KBIES_KBEDG0_MASK               1U
#define KBIES_KBEDG1_MASK               2U
#define KBIES_KBEDG2_MASK               4U
#define KBIES_KBEDG3_MASK               8U
#define KBIES_KBEDG_MASK                15U
#define KBIES_KBEDG_BITNUM              0U


/*** TPM1SC - TPM1 Status and Control Register; 0x00000010 ***/
typedef union {
  byte Byte;
  struct {
    byte PS0         :1;                                       /* Prescale Divisor Select Bit 0 */
    byte PS1         :1;                                       /* Prescale Divisor Select Bit 1 */
    byte PS2         :1;                                       /* Prescale Divisor Select Bit 2 */
    byte CLKSA       :1;                                       /* Clock Source Select A */
    byte CLKSB       :1;                                       /* Clock Source Select B */
    byte CPWMS       :1;                                       /* Center-Aligned PWM Select */
    byte TOIE        :1;                                       /* Timer Overflow Interrupt Enable */
    byte TOF         :1;                                       /* Timer Overflow Flag */
  } Bits;
  struct {
    byte grpPS   :3;
    byte grpCLKSx :2;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM1SCSTR;
extern volatile TPM1SCSTR _TPM1SC @0x00000010;
#define TPM1SC                          _TPM1SC.Byte
#define TPM1SC_PS0                      _TPM1SC.Bits.PS0
#define TPM1SC_PS1                      _TPM1SC.Bits.PS1
#define TPM1SC_PS2                      _TPM1SC.Bits.PS2
#define TPM1SC_CLKSA                    _TPM1SC.Bits.CLKSA
#define TPM1SC_CLKSB                    _TPM1SC.Bits.CLKSB
#define TPM1SC_CPWMS                    _TPM1SC.Bits.CPWMS
#define TPM1SC_TOIE                     _TPM1SC.Bits.TOIE
#define TPM1SC_TOF                      _TPM1SC.Bits.TOF
#define TPM1SC_PS                       _TPM1SC.MergedBits.grpPS
#define TPM1SC_CLKSx                    _TPM1SC.MergedBits.grpCLKSx

#define TPM1SC_PS0_MASK                 1U
#define TPM1SC_PS1_MASK                 2U
#define TPM1SC_PS2_MASK                 4U
#define TPM1SC_CLKSA_MASK               8U
#define TPM1SC_CLKSB_MASK               16U
#define TPM1SC_CPWMS_MASK               32U
#define TPM1SC_TOIE_MASK                64U
#define TPM1SC_TOF_MASK                 128U
#define TPM1SC_PS_MASK                  7U
#define TPM1SC_PS_BITNUM                0U
#define TPM1SC_CLKSx_MASK               24U
#define TPM1SC_CLKSx_BITNUM             3U


/*** TPM1CNT - TPM1 Timer Counter Register; 0x00000011 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM1CNTH - TPM1 Timer Counter Register High; 0x00000011 ***/
    union {
      byte Byte;
    } TPM1CNTHSTR;
    #define TPM1CNTH                    _TPM1CNT.Overlap_STR.TPM1CNTHSTR.Byte
    

    /*** TPM1CNTL - TPM1 Timer Counter Register Low; 0x00000012 ***/
    union {
      byte Byte;
    } TPM1CNTLSTR;
    #define TPM1CNTL                    _TPM1CNT.Overlap_STR.TPM1CNTLSTR.Byte
    
  } Overlap_STR;

} TPM1CNTSTR;
extern volatile TPM1CNTSTR _TPM1CNT @0x00000011;
#define TPM1CNT                         _TPM1CNT.Word


/*** TPM1MOD - TPM1 Timer Counter Modulo Register; 0x00000013 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM1MODH - TPM1 Timer Counter Modulo Register High; 0x00000013 ***/
    union {
      byte Byte;
    } TPM1MODHSTR;
    #define TPM1MODH                    _TPM1MOD.Overlap_STR.TPM1MODHSTR.Byte
    

    /*** TPM1MODL - TPM1 Timer Counter Modulo Register Low; 0x00000014 ***/
    union {
      byte Byte;
    } TPM1MODLSTR;
    #define TPM1MODL                    _TPM1MOD.Overlap_STR.TPM1MODLSTR.Byte
    
  } Overlap_STR;

} TPM1MODSTR;
extern volatile TPM1MODSTR _TPM1MOD @0x00000013;
#define TPM1MOD                         _TPM1MOD.Word


/*** TPM1C0SC - TPM1 Timer Channel 0 Status and Control Register; 0x00000015 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS0A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS0B       :1;                                       /* Edge/Level Select Bit B */
    byte MS0A        :1;                                       /* Mode Select A for TPM Channel 0 */
    byte MS0B        :1;                                       /* Mode Select B for TPM Channel 0 */
    byte CH0IE       :1;                                       /* Channel 0 Interrupt Enable */
    byte CH0F        :1;                                       /* Channel 0 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS0x :2;
    byte grpMS0x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM1C0SCSTR;
extern volatile TPM1C0SCSTR _TPM1C0SC @0x00000015;
#define TPM1C0SC                        _TPM1C0SC.Byte
#define TPM1C0SC_ELS0A                  _TPM1C0SC.Bits.ELS0A
#define TPM1C0SC_ELS0B                  _TPM1C0SC.Bits.ELS0B
#define TPM1C0SC_MS0A                   _TPM1C0SC.Bits.MS0A
#define TPM1C0SC_MS0B                   _TPM1C0SC.Bits.MS0B
#define TPM1C0SC_CH0IE                  _TPM1C0SC.Bits.CH0IE
#define TPM1C0SC_CH0F                   _TPM1C0SC.Bits.CH0F
#define TPM1C0SC_ELS0x                  _TPM1C0SC.MergedBits.grpELS0x
#define TPM1C0SC_MS0x                   _TPM1C0SC.MergedBits.grpMS0x

#define TPM1C0SC_ELS0A_MASK             4U
#define TPM1C0SC_ELS0B_MASK             8U
#define TPM1C0SC_MS0A_MASK              16U
#define TPM1C0SC_MS0B_MASK              32U
#define TPM1C0SC_CH0IE_MASK             64U
#define TPM1C0SC_CH0F_MASK              128U
#define TPM1C0SC_ELS0x_MASK             12U
#define TPM1C0SC_ELS0x_BITNUM           2U
#define TPM1C0SC_MS0x_MASK              48U
#define TPM1C0SC_MS0x_BITNUM            4U


/*** TPM1C0V - TPM1 Timer Channel 0 Value Register; 0x00000016 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM1C0VH - TPM1 Timer Channel 0 Value Register High; 0x00000016 ***/
    union {
      byte Byte;
    } TPM1C0VHSTR;
    #define TPM1C0VH                    _TPM1C0V.Overlap_STR.TPM1C0VHSTR.Byte
    

    /*** TPM1C0VL - TPM1 Timer Channel 0 Value Register Low; 0x00000017 ***/
    union {
      byte Byte;
    } TPM1C0VLSTR;
    #define TPM1C0VL                    _TPM1C0V.Overlap_STR.TPM1C0VLSTR.Byte
    
  } Overlap_STR;

} TPM1C0VSTR;
extern volatile TPM1C0VSTR _TPM1C0V @0x00000016;
#define TPM1C0V                         _TPM1C0V.Word


/*** TPM1C1SC - TPM1 Timer Channel 1 Status and Control Register; 0x00000018 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS1A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS1B       :1;                                       /* Edge/Level Select Bit B */
    byte MS1A        :1;                                       /* Mode Select A for TPM Channel 1 */
    byte MS1B        :1;                                       /* Mode Select B for TPM Channel 1 */
    byte CH1IE       :1;                                       /* Channel 1 Interrupt Enable */
    byte CH1F        :1;                                       /* Channel 1 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS1x :2;
    byte grpMS1x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM1C1SCSTR;
extern volatile TPM1C1SCSTR _TPM1C1SC @0x00000018;
#define TPM1C1SC                        _TPM1C1SC.Byte
#define TPM1C1SC_ELS1A                  _TPM1C1SC.Bits.ELS1A
#define TPM1C1SC_ELS1B                  _TPM1C1SC.Bits.ELS1B
#define TPM1C1SC_MS1A                   _TPM1C1SC.Bits.MS1A
#define TPM1C1SC_MS1B                   _TPM1C1SC.Bits.MS1B
#define TPM1C1SC_CH1IE                  _TPM1C1SC.Bits.CH1IE
#define TPM1C1SC_CH1F                   _TPM1C1SC.Bits.CH1F
#define TPM1C1SC_ELS1x                  _TPM1C1SC.MergedBits.grpELS1x
#define TPM1C1SC_MS1x                   _TPM1C1SC.MergedBits.grpMS1x

#define TPM1C1SC_ELS1A_MASK             4U
#define TPM1C1SC_ELS1B_MASK             8U
#define TPM1C1SC_MS1A_MASK              16U
#define TPM1C1SC_MS1B_MASK              32U
#define TPM1C1SC_CH1IE_MASK             64U
#define TPM1C1SC_CH1F_MASK              128U
#define TPM1C1SC_ELS1x_MASK             12U
#define TPM1C1SC_ELS1x_BITNUM           2U
#define TPM1C1SC_MS1x_MASK              48U
#define TPM1C1SC_MS1x_BITNUM            4U


/*** TPM1C1V - TPM1 Timer Channel 1 Value Register; 0x00000019 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM1C1VH - TPM1 Timer Channel 1 Value Register High; 0x00000019 ***/
    union {
      byte Byte;
    } TPM1C1VHSTR;
    #define TPM1C1VH                    _TPM1C1V.Overlap_STR.TPM1C1VHSTR.Byte
    

    /*** TPM1C1VL - TPM1 Timer Channel 1 Value Register Low; 0x0000001A ***/
    union {
      byte Byte;
    } TPM1C1VLSTR;
    #define TPM1C1VL                    _TPM1C1V.Overlap_STR.TPM1C1VLSTR.Byte
    
  } Overlap_STR;

} TPM1C1VSTR;
extern volatile TPM1C1VSTR _TPM1C1V @0x00000019;
#define TPM1C1V                         _TPM1C1V.Word


/*** PWUDIV - PWU Divider Register; 0x0000001C ***/
typedef union {
  byte Byte;
  struct {
    byte WDIV0       :1;                                       /* Wake Up Divider Value, bit 0 */
    byte WDIV1       :1;                                       /* Wake Up Divider Value, bit 1 */
    byte WDIV2       :1;                                       /* Wake Up Divider Value, bit 2 */
    byte WDIV3       :1;                                       /* Wake Up Divider Value, bit 3 */
    byte WDIV4       :1;                                       /* Wake Up Divider Value, bit 4 */
    byte WDIV5       :1;                                       /* Wake Up Divider Value, bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpWDIV :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PWUDIVSTR;
extern volatile PWUDIVSTR _PWUDIV @0x0000001C;
#define PWUDIV                          _PWUDIV.Byte
#define PWUDIV_WDIV0                    _PWUDIV.Bits.WDIV0
#define PWUDIV_WDIV1                    _PWUDIV.Bits.WDIV1
#define PWUDIV_WDIV2                    _PWUDIV.Bits.WDIV2
#define PWUDIV_WDIV3                    _PWUDIV.Bits.WDIV3
#define PWUDIV_WDIV4                    _PWUDIV.Bits.WDIV4
#define PWUDIV_WDIV5                    _PWUDIV.Bits.WDIV5
#define PWUDIV_WDIV                     _PWUDIV.MergedBits.grpWDIV

#define PWUDIV_WDIV0_MASK               1U
#define PWUDIV_WDIV1_MASK               2U
#define PWUDIV_WDIV2_MASK               4U
#define PWUDIV_WDIV3_MASK               8U
#define PWUDIV_WDIV4_MASK               16U
#define PWUDIV_WDIV5_MASK               32U
#define PWUDIV_WDIV_MASK                63U
#define PWUDIV_WDIV_BITNUM              0U


/*** PWUCS0 - PWU Control/Status Regsiter 0; 0x0000001D ***/
typedef union {
  byte Byte;
  struct {
    byte WUT0        :1;                                       /* Wake Up Time Interval, bit 0 */
    byte WUT1        :1;                                       /* Wake Up Time Interval, bit 1 */
    byte WUT2        :1;                                       /* Wake Up Time Interval, bit 2 */
    byte WUT3        :1;                                       /* Wake Up Time Interval, bit 3 */
    byte WUT4        :1;                                       /* Wake Up Time Interval, bit 4 */
    byte WUT5        :1;                                       /* Wake Up Time Interval, bit 5 */
    byte WUFAK       :1;                                       /* Acknowledge WUF Interrupt Flag */
    byte WUF         :1;                                       /* Wake Up Interrupt Flag */
  } Bits;
  struct {
    byte grpWUT  :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PWUCS0STR;
extern volatile PWUCS0STR _PWUCS0 @0x0000001D;
#define PWUCS0                          _PWUCS0.Byte
#define PWUCS0_WUT0                     _PWUCS0.Bits.WUT0
#define PWUCS0_WUT1                     _PWUCS0.Bits.WUT1
#define PWUCS0_WUT2                     _PWUCS0.Bits.WUT2
#define PWUCS0_WUT3                     _PWUCS0.Bits.WUT3
#define PWUCS0_WUT4                     _PWUCS0.Bits.WUT4
#define PWUCS0_WUT5                     _PWUCS0.Bits.WUT5
#define PWUCS0_WUFAK                    _PWUCS0.Bits.WUFAK
#define PWUCS0_WUF                      _PWUCS0.Bits.WUF
/* PWUCS_ARR: Access 2 PWUCSx registers in an array */
#define PWUCS_ARR                       ((volatile byte * __far) &PWUCS0)
#define PWUCS0_WUT                      _PWUCS0.MergedBits.grpWUT

#define PWUCS0_WUT0_MASK                1U
#define PWUCS0_WUT1_MASK                2U
#define PWUCS0_WUT2_MASK                4U
#define PWUCS0_WUT3_MASK                8U
#define PWUCS0_WUT4_MASK                16U
#define PWUCS0_WUT5_MASK                32U
#define PWUCS0_WUFAK_MASK               64U
#define PWUCS0_WUF_MASK                 128U
#define PWUCS0_WUT_MASK                 63U
#define PWUCS0_WUT_BITNUM               0U


/*** PWUCS1 - PWU Control/Status Register 1; 0x0000001E ***/
typedef union {
  byte Byte;
  struct {
    byte PRST0       :1;                                       /* Periodic Reset Time Interval, Bit 0 */
    byte PRST1       :1;                                       /* Periodic Reset Time Interval, Bit 1 */
    byte PRST2       :1;                                       /* Periodic Reset Time Interval, Bit 2 */
    byte PRST3       :1;                                       /* Periodic Reset Time Interval, Bit 3 */
    byte PRST4       :1;                                       /* Periodic Reset Time Interval, Bit 4 */
    byte PRST5       :1;                                       /* Periodic Reset Time Interval, Bit 5 */
    byte PRFAK       :1;                                       /* Acknowledge PRF Reset Flag */
    byte PRF         :1;                                       /* Periodic Reset Flag */
  } Bits;
  struct {
    byte grpPRST :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PWUCS1STR;
extern volatile PWUCS1STR _PWUCS1 @0x0000001E;
#define PWUCS1                          _PWUCS1.Byte
#define PWUCS1_PRST0                    _PWUCS1.Bits.PRST0
#define PWUCS1_PRST1                    _PWUCS1.Bits.PRST1
#define PWUCS1_PRST2                    _PWUCS1.Bits.PRST2
#define PWUCS1_PRST3                    _PWUCS1.Bits.PRST3
#define PWUCS1_PRST4                    _PWUCS1.Bits.PRST4
#define PWUCS1_PRST5                    _PWUCS1.Bits.PRST5
#define PWUCS1_PRFAK                    _PWUCS1.Bits.PRFAK
#define PWUCS1_PRF                      _PWUCS1.Bits.PRF
#define PWUCS1_PRST                     _PWUCS1.MergedBits.grpPRST

#define PWUCS1_PRST0_MASK               1U
#define PWUCS1_PRST1_MASK               2U
#define PWUCS1_PRST2_MASK               4U
#define PWUCS1_PRST3_MASK               8U
#define PWUCS1_PRST4_MASK               16U
#define PWUCS1_PRST5_MASK               32U
#define PWUCS1_PRFAK_MASK               64U
#define PWUCS1_PRF_MASK                 128U
#define PWUCS1_PRST_MASK                63U
#define PWUCS1_PRST_BITNUM              0U


/*** PWUS - PWU Wake-Up Status Register; 0x0000001F ***/
typedef union {
  byte Byte;
  struct {
    byte CSTAT0      :1;                                       /* Counter Status - These read-only bits show the status of the counter selected by the PSEL bit, bit 0 */
    byte CSTAT1      :1;                                       /* Counter Status - These read-only bits show the status of the counter selected by the PSEL bit, bit 1 */
    byte CSTAT2      :1;                                       /* Counter Status - These read-only bits show the status of the counter selected by the PSEL bit, bit 2 */
    byte CSTAT3      :1;                                       /* Counter Status - These read-only bits show the status of the counter selected by the PSEL bit, bit 3 */
    byte CSTAT4      :1;                                       /* Counter Status - These read-only bits show the status of the counter selected by the PSEL bit, bit 4 */
    byte CSTAT5      :1;                                       /* Counter Status - These read-only bits show the status of the counter selected by the PSEL bit, bit 5 */
    byte             :1; 
    byte PSEL        :1;                                       /* Page Selection - The PSEL read/write bit selects whether the other bits are read from the WUT or PRST counters */
  } Bits;
  struct {
    byte grpCSTAT :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PWUSSTR;
extern volatile PWUSSTR _PWUS @0x0000001F;
#define PWUS                            _PWUS.Byte
#define PWUS_CSTAT0                     _PWUS.Bits.CSTAT0
#define PWUS_CSTAT1                     _PWUS.Bits.CSTAT1
#define PWUS_CSTAT2                     _PWUS.Bits.CSTAT2
#define PWUS_CSTAT3                     _PWUS.Bits.CSTAT3
#define PWUS_CSTAT4                     _PWUS.Bits.CSTAT4
#define PWUS_CSTAT5                     _PWUS.Bits.CSTAT5
#define PWUS_PSEL                       _PWUS.Bits.PSEL
#define PWUS_CSTAT                      _PWUS.MergedBits.grpCSTAT

#define PWUS_CSTAT0_MASK                1U
#define PWUS_CSTAT1_MASK                2U
#define PWUS_CSTAT2_MASK                4U
#define PWUS_CSTAT3_MASK                8U
#define PWUS_CSTAT4_MASK                16U
#define PWUS_CSTAT5_MASK                32U
#define PWUS_PSEL_MASK                  128U
#define PWUS_CSTAT_MASK                 63U
#define PWUS_CSTAT_BITNUM               0U


/*** LFCTL1 - LF Control Register 1; 0x00000020 ***/
typedef union {
  byte Byte;
  struct {
    byte SENS0       :1;                                       /* Sensitivity Control, bit 0 */
    byte SENS1       :1;                                       /* Sensitivity Control, bit 1 */
    byte IDSEL0      :1;                                       /* Wake Up ID Selection, bit 0 */
    byte IDSEL1      :1;                                       /* Wake Up ID Selection, bit 1 */
    byte LPAGE       :1;                                       /* Page Select */
    byte CARMOD      :1;                                       /* Carrier Mode */
    byte SRES        :1;                                       /* Soft Reset */
    byte LFEN        :1;                                       /* LF Enable */
  } Bits;
  struct {
    byte grpSENS :2;
    byte grpIDSEL :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} LFCTL1STR;
extern volatile LFCTL1STR _LFCTL1 @0x00000020;
#define LFCTL1                          _LFCTL1.Byte
#define LFCTL1_SENS0                    _LFCTL1.Bits.SENS0
#define LFCTL1_SENS1                    _LFCTL1.Bits.SENS1
#define LFCTL1_IDSEL0                   _LFCTL1.Bits.IDSEL0
#define LFCTL1_IDSEL1                   _LFCTL1.Bits.IDSEL1
#define LFCTL1_LPAGE                    _LFCTL1.Bits.LPAGE
#define LFCTL1_CARMOD                   _LFCTL1.Bits.CARMOD
#define LFCTL1_SRES                     _LFCTL1.Bits.SRES
#define LFCTL1_LFEN                     _LFCTL1.Bits.LFEN
#define LFCTL1_SENS                     _LFCTL1.MergedBits.grpSENS
#define LFCTL1_IDSEL                    _LFCTL1.MergedBits.grpIDSEL

#define LFCTL1_SENS0_MASK               1U
#define LFCTL1_SENS1_MASK               2U
#define LFCTL1_IDSEL0_MASK              4U
#define LFCTL1_IDSEL1_MASK              8U
#define LFCTL1_LPAGE_MASK               16U
#define LFCTL1_CARMOD_MASK              32U
#define LFCTL1_SRES_MASK                64U
#define LFCTL1_LFEN_MASK                128U
#define LFCTL1_SENS_MASK                3U
#define LFCTL1_SENS_BITNUM              0U
#define LFCTL1_IDSEL_MASK               12U
#define LFCTL1_IDSEL_BITNUM             2U


/*** LFCTRLE - LF Control Register E (LPAGE = 1); 0x00000021 ***/
typedef union {
  byte Byte;
  union { /* Several registers at the same address */
    /*** LFCTRLE - LF Control Register E (LPAGE = 1); Several registers at the same address ***/
    union {
      struct {
        byte AZSC0       :1;                                       /* LOGAMP AZ Sequencer Control, bit 0 */
        byte AZSC1       :1;                                       /* LOGAMP AZ Sequencer Control, bit 1 */
        byte AZSC2       :1;                                       /* LOGAMP AZ Sequencer Control, bit 2 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpAZSC :3;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } LFCTRLESTR;
    #define LFCTRLE                     _LFCTRLE.Byte
    #define LFCTRLE_AZSC0               _LFCTRLE.SameAddr_STR.LFCTRLESTR.Bits.AZSC0
    #define LFCTRLE_AZSC1               _LFCTRLE.SameAddr_STR.LFCTRLESTR.Bits.AZSC1
    #define LFCTRLE_AZSC2               _LFCTRLE.SameAddr_STR.LFCTRLESTR.Bits.AZSC2
    #define LFCTRLE_AZSC                _LFCTRLE.SameAddr_STR.LFCTRLESTR.MergedBits.grpAZSC
    
    #define LFCTRLE_AZSC0_MASK          1U
    #define LFCTRLE_AZSC1_MASK          2U
    #define LFCTRLE_AZSC2_MASK          4U
    #define LFCTRLE_AZSC_MASK           7U
    #define LFCTRLE_AZSC_BITNUM         0U
    
    /*** LFCTL2 - LF Control Register 2 (LPAGE = 0); Several registers at the same address ***/
    union {
      struct {
        byte LFONTM0     :1;                                       /* LF Sampling ON Time Select, bit 0 */
        byte LFONTM1     :1;                                       /* LF Sampling ON Time Select, bit 1 */
        byte LFONTM2     :1;                                       /* LF Sampling ON Time Select, bit 2 */
        byte LFONTM3     :1;                                       /* LF Sampling ON Time Select, bit 3 */
        byte LFSTM0      :1;                                       /* LF Sampling Time Interval Select, bit 0 */
        byte LFSTM1      :1;                                       /* LF Sampling Time Interval Select, bit 1 */
        byte LFSTM2      :1;                                       /* LF Sampling Time Interval Select, bit 2 */
        byte LFSTM3      :1;                                       /* LF Sampling Time Interval Select, bit 3 */
      } Bits;
      struct {
        byte grpLFONTM :4;
        byte grpLFSTM :4;
      } MergedBits;
    } LFCTL2STR;
    #define LFCTL2                      _LFCTRLE.Byte
    #define LFCTL2_LFONTM0              _LFCTRLE.SameAddr_STR.LFCTL2STR.Bits.LFONTM0
    #define LFCTL2_LFONTM1              _LFCTRLE.SameAddr_STR.LFCTL2STR.Bits.LFONTM1
    #define LFCTL2_LFONTM2              _LFCTRLE.SameAddr_STR.LFCTL2STR.Bits.LFONTM2
    #define LFCTL2_LFONTM3              _LFCTRLE.SameAddr_STR.LFCTL2STR.Bits.LFONTM3
    #define LFCTL2_LFSTM0               _LFCTRLE.SameAddr_STR.LFCTL2STR.Bits.LFSTM0
    #define LFCTL2_LFSTM1               _LFCTRLE.SameAddr_STR.LFCTL2STR.Bits.LFSTM1
    #define LFCTL2_LFSTM2               _LFCTRLE.SameAddr_STR.LFCTL2STR.Bits.LFSTM2
    #define LFCTL2_LFSTM3               _LFCTRLE.SameAddr_STR.LFCTL2STR.Bits.LFSTM3
    #define LFCTL2_LFONTM               _LFCTRLE.SameAddr_STR.LFCTL2STR.MergedBits.grpLFONTM
    #define LFCTL2_LFSTM                _LFCTRLE.SameAddr_STR.LFCTL2STR.MergedBits.grpLFSTM
    
    #define LFCTL2_LFONTM0_MASK         1U
    #define LFCTL2_LFONTM1_MASK         2U
    #define LFCTL2_LFONTM2_MASK         4U
    #define LFCTL2_LFONTM3_MASK         8U
    #define LFCTL2_LFSTM0_MASK          16U
    #define LFCTL2_LFSTM1_MASK          32U
    #define LFCTL2_LFSTM2_MASK          64U
    #define LFCTL2_LFSTM3_MASK          128U
    #define LFCTL2_LFONTM_MASK          15U
    #define LFCTL2_LFONTM_BITNUM        0U
    #define LFCTL2_LFSTM_MASK           240U
    #define LFCTL2_LFSTM_BITNUM         4U
    
  } SameAddr_STR; /*Several registers at the same address */

} LFCTRLESTR;
extern volatile LFCTRLESTR _LFCTRLE @0x00000021;


/*** LFCTRLD - LF Control Register D (LPAGE = 1); 0x00000022 ***/
typedef union {
  byte Byte;
  union { /* Several registers at the same address */
    /*** LFCTRLD - LF Control Register D (LPAGE = 1); Several registers at the same address ***/
    union {
      struct {
        byte CHK1250     :1;                                       /* Accurate 125 kHz Check, bit 0 */
        byte CHK1251     :1;                                       /* Accurate 125 kHz Check, bit 1 */
        byte ONMODE      :1;                                       /* ON Behavior Mode */
        byte AZDC0       :1;                                       /* AZ Digital Control of AZ triggering, bit 0 */
        byte AZDC1       :1;                                       /* AZ Digital Control of AZ triggering, bit 1 */
        byte DEQS        :1;                                       /* DEQing status register */
        byte AVFOF0      :1;                                       /* SUM AZ release delay, bit 0 */
        byte AVFOF1      :1;                                       /* SUM AZ release delay, bit 1 */
      } Bits;
      struct {
        byte grpCHK125 :2;
        byte     :1;
        byte grpAZDC :2;
        byte     :1;
        byte grpAVFOF :2;
      } MergedBits;
    } LFCTRLDSTR;
    #define LFCTRLD                     _LFCTRLD.Byte
    #define LFCTRLD_CHK1250             _LFCTRLD.SameAddr_STR.LFCTRLDSTR.Bits.CHK1250
    #define LFCTRLD_CHK1251             _LFCTRLD.SameAddr_STR.LFCTRLDSTR.Bits.CHK1251
    #define LFCTRLD_ONMODE              _LFCTRLD.SameAddr_STR.LFCTRLDSTR.Bits.ONMODE
    #define LFCTRLD_AZDC0               _LFCTRLD.SameAddr_STR.LFCTRLDSTR.Bits.AZDC0
    #define LFCTRLD_AZDC1               _LFCTRLD.SameAddr_STR.LFCTRLDSTR.Bits.AZDC1
    #define LFCTRLD_DEQS                _LFCTRLD.SameAddr_STR.LFCTRLDSTR.Bits.DEQS
    #define LFCTRLD_AVFOF0              _LFCTRLD.SameAddr_STR.LFCTRLDSTR.Bits.AVFOF0
    #define LFCTRLD_AVFOF1              _LFCTRLD.SameAddr_STR.LFCTRLDSTR.Bits.AVFOF1
    #define LFCTRLD_CHK125              _LFCTRLD.SameAddr_STR.LFCTRLDSTR.MergedBits.grpCHK125
    #define LFCTRLD_AZDC                _LFCTRLD.SameAddr_STR.LFCTRLDSTR.MergedBits.grpAZDC
    #define LFCTRLD_AVFOF               _LFCTRLD.SameAddr_STR.LFCTRLDSTR.MergedBits.grpAVFOF
    
    #define LFCTRLD_CHK1250_MASK        1U
    #define LFCTRLD_CHK1251_MASK        2U
    #define LFCTRLD_ONMODE_MASK         4U
    #define LFCTRLD_AZDC0_MASK          8U
    #define LFCTRLD_AZDC1_MASK          16U
    #define LFCTRLD_DEQS_MASK           32U
    #define LFCTRLD_AVFOF0_MASK         64U
    #define LFCTRLD_AVFOF1_MASK         128U
    #define LFCTRLD_CHK125_MASK         3U
    #define LFCTRLD_CHK125_BITNUM       0U
    #define LFCTRLD_AZDC_MASK           24U
    #define LFCTRLD_AZDC_BITNUM         3U
    #define LFCTRLD_AVFOF_MASK          192U
    #define LFCTRLD_AVFOF_BITNUM        6U
    
    /*** LFCTL3 - LF Control Register 3 (LPAGE = 0); Several registers at the same address ***/
    union {
      struct {
        byte LFCDTM0     :1;                                       /* LF Carrier Detect Time, bit 0 */
        byte LFCDTM1     :1;                                       /* LF Carrier Detect Time, bit 1 */
        byte LFCDTM2     :1;                                       /* LF Carrier Detect Time, bit 2 */
        byte LFCDTM3     :1;                                       /* LF Carrier Detect Time, bit 3 */
        byte SYNC0       :1;                                       /* LF SYNC Selection, bit 0 */
        byte SYNC1       :1;                                       /* LF SYNC Selection, bit 1 */
        byte TOGMOD      :1;                                       /* LFR Mode Toggle */
        byte LFDO        :1;                                       /* LF Detector Output */
      } Bits;
      struct {
        byte grpLFCDTM :4;
        byte grpSYNC :2;
        byte     :1;
        byte     :1;
      } MergedBits;
    } LFCTL3STR;
    #define LFCTL3                      _LFCTRLD.Byte
    #define LFCTL3_LFCDTM0              _LFCTRLD.SameAddr_STR.LFCTL3STR.Bits.LFCDTM0
    #define LFCTL3_LFCDTM1              _LFCTRLD.SameAddr_STR.LFCTL3STR.Bits.LFCDTM1
    #define LFCTL3_LFCDTM2              _LFCTRLD.SameAddr_STR.LFCTL3STR.Bits.LFCDTM2
    #define LFCTL3_LFCDTM3              _LFCTRLD.SameAddr_STR.LFCTL3STR.Bits.LFCDTM3
    #define LFCTL3_SYNC0                _LFCTRLD.SameAddr_STR.LFCTL3STR.Bits.SYNC0
    #define LFCTL3_SYNC1                _LFCTRLD.SameAddr_STR.LFCTL3STR.Bits.SYNC1
    #define LFCTL3_TOGMOD               _LFCTRLD.SameAddr_STR.LFCTL3STR.Bits.TOGMOD
    #define LFCTL3_LFDO                 _LFCTRLD.SameAddr_STR.LFCTL3STR.Bits.LFDO
    #define LFCTL3_LFCDTM               _LFCTRLD.SameAddr_STR.LFCTL3STR.MergedBits.grpLFCDTM
    #define LFCTL3_SYNC                 _LFCTRLD.SameAddr_STR.LFCTL3STR.MergedBits.grpSYNC
    
    #define LFCTL3_LFCDTM0_MASK         1U
    #define LFCTL3_LFCDTM1_MASK         2U
    #define LFCTL3_LFCDTM2_MASK         4U
    #define LFCTL3_LFCDTM3_MASK         8U
    #define LFCTL3_SYNC0_MASK           16U
    #define LFCTL3_SYNC1_MASK           32U
    #define LFCTL3_TOGMOD_MASK          64U
    #define LFCTL3_LFDO_MASK            128U
    #define LFCTL3_LFCDTM_MASK          15U
    #define LFCTL3_LFCDTM_BITNUM        0U
    #define LFCTL3_SYNC_MASK            48U
    #define LFCTL3_SYNC_BITNUM          4U
    
  } SameAddr_STR; /*Several registers at the same address */

} LFCTRLDSTR;
extern volatile LFCTRLDSTR _LFCTRLD @0x00000022;


/*** LFCTRLC - LF Control Register C (LPAGE = 1); 0x00000023 ***/
typedef union {
  byte Byte;
  union { /* Several registers at the same address */
    /*** LFCTRLC - LF Control Register C (LPAGE = 1); Several registers at the same address ***/
    union {
      struct {
        byte DEQEN       :1;                                       /* DEQing System enable */
        byte LOWQ0       :1;                                       /* DEQing Resistor, bit 0 */
        byte LOWQ1       :1;                                       /* DEQing Resistor, bit 1 */
        byte AZEN        :1;                                       /* Data AZ enable */
        byte FINSEL0     :1;                                       /* Final stage select, bit 0 */
        byte FINSEL1     :1;                                       /* Final stage select, bit 1 */
        byte AMPGAIN0    :1;                                       /* 3rd Amplifier gain, bit 0 */
        byte AMPGAIN1    :1;                                       /* 3rd Amplifier gain, bit 1 */
      } Bits;
      struct {
        byte     :1;
        byte grpLOWQ :2;
        byte     :1;
        byte grpFINSEL :2;
        byte grpAMPGAIN :2;
      } MergedBits;
    } LFCTRLCSTR;
    #define LFCTRLC                     _LFCTRLC.Byte
    #define LFCTRLC_DEQEN               _LFCTRLC.SameAddr_STR.LFCTRLCSTR.Bits.DEQEN
    #define LFCTRLC_LOWQ0               _LFCTRLC.SameAddr_STR.LFCTRLCSTR.Bits.LOWQ0
    #define LFCTRLC_LOWQ1               _LFCTRLC.SameAddr_STR.LFCTRLCSTR.Bits.LOWQ1
    #define LFCTRLC_AZEN                _LFCTRLC.SameAddr_STR.LFCTRLCSTR.Bits.AZEN
    #define LFCTRLC_FINSEL0             _LFCTRLC.SameAddr_STR.LFCTRLCSTR.Bits.FINSEL0
    #define LFCTRLC_FINSEL1             _LFCTRLC.SameAddr_STR.LFCTRLCSTR.Bits.FINSEL1
    #define LFCTRLC_AMPGAIN0            _LFCTRLC.SameAddr_STR.LFCTRLCSTR.Bits.AMPGAIN0
    #define LFCTRLC_AMPGAIN1            _LFCTRLC.SameAddr_STR.LFCTRLCSTR.Bits.AMPGAIN1
    #define LFCTRLC_LOWQ                _LFCTRLC.SameAddr_STR.LFCTRLCSTR.MergedBits.grpLOWQ
    #define LFCTRLC_FINSEL              _LFCTRLC.SameAddr_STR.LFCTRLCSTR.MergedBits.grpFINSEL
    #define LFCTRLC_AMPGAIN             _LFCTRLC.SameAddr_STR.LFCTRLCSTR.MergedBits.grpAMPGAIN
    
    #define LFCTRLC_DEQEN_MASK          1U
    #define LFCTRLC_LOWQ0_MASK          2U
    #define LFCTRLC_LOWQ1_MASK          4U
    #define LFCTRLC_AZEN_MASK           8U
    #define LFCTRLC_FINSEL0_MASK        16U
    #define LFCTRLC_FINSEL1_MASK        32U
    #define LFCTRLC_AMPGAIN0_MASK       64U
    #define LFCTRLC_AMPGAIN1_MASK       128U
    #define LFCTRLC_LOWQ_MASK           6U
    #define LFCTRLC_LOWQ_BITNUM         1U
    #define LFCTRLC_FINSEL_MASK         48U
    #define LFCTRLC_FINSEL_BITNUM       4U
    #define LFCTRLC_AMPGAIN_MASK        192U
    #define LFCTRLC_AMPGAIN_BITNUM      6U
    
    /*** LFCTL4 - LFR Control Register 4 (LPAGE = 0); Several registers at the same address ***/
    union {
      struct {
        byte TIMOUT0     :1;                                       /* SYNC Time Out Select, bit 0, bit 0 */
        byte TIMOUT1     :1;                                       /* SYNC Time Out Select, bit 0, bit 1 */
        byte VALEN       :1;                                       /* LF carrier validation enable */
        byte DECEN       :1;                                       /* LF Digital Decoder Enable */
        byte LFIDIE      :1;                                       /* LFR ID Detect Interrupt Enable */
        byte LFCDIE      :1;                                       /* LFR Carrier Detect Interrupt Enable */
        byte LFERIE      :1;                                       /* LFR Error Interrupt Enable */
        byte LFDRIE      :1;                                       /* LFR Data Register Full Interrupt Enable */
      } Bits;
      struct {
        byte grpTIMOUT :2;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } LFCTL4STR;
    #define LFCTL4                      _LFCTRLC.Byte
    #define LFCTL4_TIMOUT0              _LFCTRLC.SameAddr_STR.LFCTL4STR.Bits.TIMOUT0
    #define LFCTL4_TIMOUT1              _LFCTRLC.SameAddr_STR.LFCTL4STR.Bits.TIMOUT1
    #define LFCTL4_VALEN                _LFCTRLC.SameAddr_STR.LFCTL4STR.Bits.VALEN
    #define LFCTL4_DECEN                _LFCTRLC.SameAddr_STR.LFCTL4STR.Bits.DECEN
    #define LFCTL4_LFIDIE               _LFCTRLC.SameAddr_STR.LFCTL4STR.Bits.LFIDIE
    #define LFCTL4_LFCDIE               _LFCTRLC.SameAddr_STR.LFCTL4STR.Bits.LFCDIE
    #define LFCTL4_LFERIE               _LFCTRLC.SameAddr_STR.LFCTL4STR.Bits.LFERIE
    #define LFCTL4_LFDRIE               _LFCTRLC.SameAddr_STR.LFCTL4STR.Bits.LFDRIE
    #define LFCTL4_TIMOUT               _LFCTRLC.SameAddr_STR.LFCTL4STR.MergedBits.grpTIMOUT
    
    #define LFCTL4_TIMOUT0_MASK         1U
    #define LFCTL4_TIMOUT1_MASK         2U
    #define LFCTL4_VALEN_MASK           4U
    #define LFCTL4_DECEN_MASK           8U
    #define LFCTL4_LFIDIE_MASK          16U
    #define LFCTL4_LFCDIE_MASK          32U
    #define LFCTL4_LFERIE_MASK          64U
    #define LFCTL4_LFDRIE_MASK          128U
    #define LFCTL4_TIMOUT_MASK          3U
    #define LFCTL4_TIMOUT_BITNUM        0U
    
  } SameAddr_STR; /*Several registers at the same address */

} LFCTRLCSTR;
extern volatile LFCTRLCSTR _LFCTRLC @0x00000023;


/*** LFCTRLB - LF Control Register B (LPAGE = 1); 0x00000024 ***/
typedef union {
  byte Byte;
  union { /* Several registers at the same address */
    /*** LFCTRLB - LF Control Register B (LPAGE = 1); Several registers at the same address ***/
    union {
      struct {
        byte LFCPTAZ0    :1;                                       /* LF auto zero counter, bit 0 */
        byte LFCPTAZ1    :1;                                       /* LF auto zero counter, bit 1 */
        byte LFCPTAZ2    :1;                                       /* LF auto zero counter, bit 2 */
        byte LFPOL       :1;                                       /* LF Manchester Polarity Select */
        byte LFFAF_LFCAF0 :1;                                      /* Average filter biphase filtering control, bit 0 */
        byte LFFAF_LFCAF1 :1;                                      /* Average filter biphase filtering control, bit 1 */
        byte HYST0       :1;                                       /* Control slicer hysteresis, bit 0 */
        byte HYST1       :1;                                       /* Control slicer hysteresis, bit 1 */
      } Bits;
      struct {
        byte grpLFCPTAZ :3;
        byte     :1;
        byte grpLFFAF_LFCAF :2;
        byte grpHYST :2;
      } MergedBits;
    } LFCTRLBSTR;
    #define LFCTRLB                     _LFCTRLB.Byte
    #define LFCTRLB_LFCPTAZ0            _LFCTRLB.SameAddr_STR.LFCTRLBSTR.Bits.LFCPTAZ0
    #define LFCTRLB_LFCPTAZ1            _LFCTRLB.SameAddr_STR.LFCTRLBSTR.Bits.LFCPTAZ1
    #define LFCTRLB_LFCPTAZ2            _LFCTRLB.SameAddr_STR.LFCTRLBSTR.Bits.LFCPTAZ2
    #define LFCTRLB_LFPOL               _LFCTRLB.SameAddr_STR.LFCTRLBSTR.Bits.LFPOL
    #define LFCTRLB_LFFAF_LFCAF0        _LFCTRLB.SameAddr_STR.LFCTRLBSTR.Bits.LFFAF_LFCAF0
    #define LFCTRLB_LFFAF_LFCAF1        _LFCTRLB.SameAddr_STR.LFCTRLBSTR.Bits.LFFAF_LFCAF1
    #define LFCTRLB_HYST0               _LFCTRLB.SameAddr_STR.LFCTRLBSTR.Bits.HYST0
    #define LFCTRLB_HYST1               _LFCTRLB.SameAddr_STR.LFCTRLBSTR.Bits.HYST1
    #define LFCTRLB_LFCPTAZ             _LFCTRLB.SameAddr_STR.LFCTRLBSTR.MergedBits.grpLFCPTAZ
    #define LFCTRLB_LFFAF_LFCAF         _LFCTRLB.SameAddr_STR.LFCTRLBSTR.MergedBits.grpLFFAF_LFCAF
    #define LFCTRLB_HYST                _LFCTRLB.SameAddr_STR.LFCTRLBSTR.MergedBits.grpHYST
    
    #define LFCTRLB_LFCPTAZ0_MASK       1U
    #define LFCTRLB_LFCPTAZ1_MASK       2U
    #define LFCTRLB_LFCPTAZ2_MASK       4U
    #define LFCTRLB_LFPOL_MASK          8U
    #define LFCTRLB_LFFAF_LFCAF0_MASK   16U
    #define LFCTRLB_LFFAF_LFCAF1_MASK   32U
    #define LFCTRLB_HYST0_MASK          64U
    #define LFCTRLB_HYST1_MASK          128U
    #define LFCTRLB_LFCPTAZ_MASK        7U
    #define LFCTRLB_LFCPTAZ_BITNUM      0U
    #define LFCTRLB_LFFAF_LFCAF_MASK    48U
    #define LFCTRLB_LFFAF_LFCAF_BITNUM  4U
    #define LFCTRLB_HYST_MASK           192U
    #define LFCTRLB_HYST_BITNUM         6U
    
    /*** LFS - LFR Status Register (LPAGE = 0); Several registers at the same address ***/
    union {
      struct {
        byte LFIACK      :1;                                       /* LF Interrupt Acknowledge */
        byte LPSM        :1;                                       /* Low Power Sniff Mode */
        byte LFEOMF      :1;                                       /* LF Receive Data EOM Flag */
        byte LFOVF       :1;                                       /* LF Receive Data Overflow Flag */
        byte LFIDF       :1;                                       /* LF ID Detect Flag */
        byte LFCDF       :1;                                       /* LF Carrier Pulse Detect Flag */
        byte LFERF       :1;                                       /* LF Receive Error Flag */
        byte LFDRF       :1;                                       /* LF Data Ready Flag */
      } Bits;
    } LFSSTR;
    #define LFS                         _LFCTRLB.Byte
    #define LFS_LFIACK                  _LFCTRLB.SameAddr_STR.LFSSTR.Bits.LFIACK
    #define LFS_LPSM                    _LFCTRLB.SameAddr_STR.LFSSTR.Bits.LPSM
    #define LFS_LFEOMF                  _LFCTRLB.SameAddr_STR.LFSSTR.Bits.LFEOMF
    #define LFS_LFOVF                   _LFCTRLB.SameAddr_STR.LFSSTR.Bits.LFOVF
    #define LFS_LFIDF                   _LFCTRLB.SameAddr_STR.LFSSTR.Bits.LFIDF
    #define LFS_LFCDF                   _LFCTRLB.SameAddr_STR.LFSSTR.Bits.LFCDF
    #define LFS_LFERF                   _LFCTRLB.SameAddr_STR.LFSSTR.Bits.LFERF
    #define LFS_LFDRF                   _LFCTRLB.SameAddr_STR.LFSSTR.Bits.LFDRF
    
    #define LFS_LFIACK_MASK             1U
    #define LFS_LPSM_MASK               2U
    #define LFS_LFEOMF_MASK             4U
    #define LFS_LFOVF_MASK              8U
    #define LFS_LFIDF_MASK              16U
    #define LFS_LFCDF_MASK              32U
    #define LFS_LFERF_MASK              64U
    #define LFS_LFDRF_MASK              128U
    
  } SameAddr_STR; /*Several registers at the same address */

} LFCTRLBSTR;
extern volatile LFCTRLBSTR _LFCTRLB @0x00000024;


/*** LFCTRLA - LF Control Register A (LPAGE = 1); 0x00000025 ***/
typedef union {
  byte Byte;
  union { /* Several registers at the same address */
    /*** LFCTRLA - LF Control Register A (LPAGE = 1); Several registers at the same address ***/
    union {
      struct {
        byte LFCC0       :1;                                       /* LF Successive Carrier Validations Counter, bit 0 */
        byte LFCC1       :1;                                       /* LF Successive Carrier Validations Counter, bit 1 */
        byte LFCC2       :1;                                       /* LF Successive Carrier Validations Counter, bit 2 */
        byte LFCC3       :1;                                       /* LF Successive Carrier Validations Counter, bit 3 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpLFCC :4;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } LFCTRLASTR;
    #define LFCTRLA                     _LFCTRLA.Byte
    #define LFCTRLA_LFCC0               _LFCTRLA.SameAddr_STR.LFCTRLASTR.Bits.LFCC0
    #define LFCTRLA_LFCC1               _LFCTRLA.SameAddr_STR.LFCTRLASTR.Bits.LFCC1
    #define LFCTRLA_LFCC2               _LFCTRLA.SameAddr_STR.LFCTRLASTR.Bits.LFCC2
    #define LFCTRLA_LFCC3               _LFCTRLA.SameAddr_STR.LFCTRLASTR.Bits.LFCC3
    #define LFCTRLA_LFCC                _LFCTRLA.SameAddr_STR.LFCTRLASTR.MergedBits.grpLFCC
    
    #define LFCTRLA_LFCC0_MASK          1U
    #define LFCTRLA_LFCC1_MASK          2U
    #define LFCTRLA_LFCC2_MASK          4U
    #define LFCTRLA_LFCC3_MASK          8U
    #define LFCTRLA_LFCC_MASK           15U
    #define LFCTRLA_LFCC_BITNUM         0U
    
    /*** LFDATA - LFR Data Register (LPAGE = 0); Several registers at the same address ***/
    union {
      struct {
        byte RXDATA0     :1;                                       /* Receive Data. LFR in data mode, bit 0 */
        byte RXDATA1     :1;                                       /* Receive Data. LFR in data mode, bit 1 */
        byte RXDATA2     :1;                                       /* Receive Data. LFR in data mode, bit 2 */
        byte RXDATA3     :1;                                       /* Receive Data. LFR in data mode, bit 3 */
        byte RXDATA4     :1;                                       /* Receive Data. LFR in data mode, bit 4 */
        byte RXDATA5     :1;                                       /* Receive Data. LFR in data mode, bit 5 */
        byte RXDATA6     :1;                                       /* Receive Data. LFR in data mode, bit 6 */
        byte RXDATA7     :1;                                       /* Receive Data. LFR in data mode, bit 7 */
      } Bits;
    } LFDATASTR;
    #define LFDATA                      _LFCTRLA.Byte
    #define LFDATA_RXDATA0              _LFCTRLA.SameAddr_STR.LFDATASTR.Bits.RXDATA0
    #define LFDATA_RXDATA1              _LFCTRLA.SameAddr_STR.LFDATASTR.Bits.RXDATA1
    #define LFDATA_RXDATA2              _LFCTRLA.SameAddr_STR.LFDATASTR.Bits.RXDATA2
    #define LFDATA_RXDATA3              _LFCTRLA.SameAddr_STR.LFDATASTR.Bits.RXDATA3
    #define LFDATA_RXDATA4              _LFCTRLA.SameAddr_STR.LFDATASTR.Bits.RXDATA4
    #define LFDATA_RXDATA5              _LFCTRLA.SameAddr_STR.LFDATASTR.Bits.RXDATA5
    #define LFDATA_RXDATA6              _LFCTRLA.SameAddr_STR.LFDATASTR.Bits.RXDATA6
    #define LFDATA_RXDATA7              _LFCTRLA.SameAddr_STR.LFDATASTR.Bits.RXDATA7
    
    #define LFDATA_RXDATA0_MASK         1U
    #define LFDATA_RXDATA1_MASK         2U
    #define LFDATA_RXDATA2_MASK         4U
    #define LFDATA_RXDATA3_MASK         8U
    #define LFDATA_RXDATA4_MASK         16U
    #define LFDATA_RXDATA5_MASK         32U
    #define LFDATA_RXDATA6_MASK         64U
    #define LFDATA_RXDATA7_MASK         128U
    
  } SameAddr_STR; /*Several registers at the same address */

} LFCTRLASTR;
extern volatile LFCTRLASTR _LFCTRLA @0x00000025;


/*** LFID - LFR ID Register; 0x00000026 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** LFIDL - LFR ID Low Byte; 0x00000026 ***/
    union {
      byte Byte;
      struct {
        byte ID0         :1;                                       /* LFR ID Bits, bit 0 */
        byte ID1         :1;                                       /* LFR ID Bits, bit 1 */
        byte ID2         :1;                                       /* LFR ID Bits, bit 2 */
        byte ID3         :1;                                       /* LFR ID Bits, bit 3 */
        byte ID4         :1;                                       /* LFR ID Bits, bit 4 */
        byte ID5         :1;                                       /* LFR ID Bits, bit 5 */
        byte ID6         :1;                                       /* LFR ID Bits, bit 6 */
        byte ID7         :1;                                       /* LFR ID Bits, bit 7 */
      } Bits;
    } LFIDLSTR;
    #define LFIDL                       _LFID.Overlap_STR.LFIDLSTR.Byte
    #define LFIDL_ID0                   _LFID.Overlap_STR.LFIDLSTR.Bits.ID0
    #define LFIDL_ID1                   _LFID.Overlap_STR.LFIDLSTR.Bits.ID1
    #define LFIDL_ID2                   _LFID.Overlap_STR.LFIDLSTR.Bits.ID2
    #define LFIDL_ID3                   _LFID.Overlap_STR.LFIDLSTR.Bits.ID3
    #define LFIDL_ID4                   _LFID.Overlap_STR.LFIDLSTR.Bits.ID4
    #define LFIDL_ID5                   _LFID.Overlap_STR.LFIDLSTR.Bits.ID5
    #define LFIDL_ID6                   _LFID.Overlap_STR.LFIDLSTR.Bits.ID6
    #define LFIDL_ID7                   _LFID.Overlap_STR.LFIDLSTR.Bits.ID7
    
    #define LFIDL_ID0_MASK              1U
    #define LFIDL_ID1_MASK              2U
    #define LFIDL_ID2_MASK              4U
    #define LFIDL_ID3_MASK              8U
    #define LFIDL_ID4_MASK              16U
    #define LFIDL_ID5_MASK              32U
    #define LFIDL_ID6_MASK              64U
    #define LFIDL_ID7_MASK              128U
    

    /*** LFIDH - LFR ID High Byte; 0x00000027 ***/
    union {
      byte Byte;
      struct {
        byte ID8         :1;                                       /* LFR ID, bit 8 */
        byte ID9         :1;                                       /* LFR ID, bit 9 */
        byte ID10        :1;                                       /* LFR ID, bit 10 */
        byte ID11        :1;                                       /* LFR ID, bit 11 */
        byte ID12        :1;                                       /* LFR ID, bit 12 */
        byte ID13        :1;                                       /* LFR ID, bit 13 */
        byte ID14        :1;                                       /* LFR ID, bit 14 */
        byte ID15        :1;                                       /* LFR ID, bit 15 */
      } Bits;
    } LFIDHSTR;
    #define LFIDH                       _LFID.Overlap_STR.LFIDHSTR.Byte
    #define LFIDH_ID8                   _LFID.Overlap_STR.LFIDHSTR.Bits.ID8
    #define LFIDH_ID9                   _LFID.Overlap_STR.LFIDHSTR.Bits.ID9
    #define LFIDH_ID10                  _LFID.Overlap_STR.LFIDHSTR.Bits.ID10
    #define LFIDH_ID11                  _LFID.Overlap_STR.LFIDHSTR.Bits.ID11
    #define LFIDH_ID12                  _LFID.Overlap_STR.LFIDHSTR.Bits.ID12
    #define LFIDH_ID13                  _LFID.Overlap_STR.LFIDHSTR.Bits.ID13
    #define LFIDH_ID14                  _LFID.Overlap_STR.LFIDHSTR.Bits.ID14
    #define LFIDH_ID15                  _LFID.Overlap_STR.LFIDHSTR.Bits.ID15
    
    #define LFIDH_ID8_MASK              1U
    #define LFIDH_ID9_MASK              2U
    #define LFIDH_ID10_MASK             4U
    #define LFIDH_ID11_MASK             8U
    #define LFIDH_ID12_MASK             16U
    #define LFIDH_ID13_MASK             32U
    #define LFIDH_ID14_MASK             64U
    #define LFIDH_ID15_MASK             128U
    
  } Overlap_STR;

} LFIDSTR;
extern volatile LFIDSTR _LFID @0x00000026;
#define LFID                            _LFID.Word


/*** RFCR0 - RFM Control Register 0; 0x00000030 ***/
typedef union {
  byte Byte;
  struct {
    byte BPS0        :1;                                       /* Output Data Rate, bit 0 */
    byte BPS1        :1;                                       /* Output Data Rate, bit 1 */
    byte BPS2        :1;                                       /* Output Data Rate, bit 2 */
    byte BPS3        :1;                                       /* Output Data Rate, bit 3 */
    byte BPS4        :1;                                       /* Output Data Rate, bit 4 */
    byte BPS5        :1;                                       /* Output Data Rate, bit 5 */
    byte BPS6        :1;                                       /* Output Data Rate, bit 6 */
    byte BPS7        :1;                                       /* Output Data Rate, bit 7 */
  } Bits;
} RFCR0STR;
extern volatile RFCR0STR _RFCR0 @0x00000030;
#define RFCR0                           _RFCR0.Byte
#define RFCR0_BPS0                      _RFCR0.Bits.BPS0
#define RFCR0_BPS1                      _RFCR0.Bits.BPS1
#define RFCR0_BPS2                      _RFCR0.Bits.BPS2
#define RFCR0_BPS3                      _RFCR0.Bits.BPS3
#define RFCR0_BPS4                      _RFCR0.Bits.BPS4
#define RFCR0_BPS5                      _RFCR0.Bits.BPS5
#define RFCR0_BPS6                      _RFCR0.Bits.BPS6
#define RFCR0_BPS7                      _RFCR0.Bits.BPS7
/* RFCR_ARR: Access 8 RFCRx registers in an array */
#define RFCR_ARR                        ((volatile byte * __far) &RFCR0)

#define RFCR0_BPS0_MASK                 1U
#define RFCR0_BPS1_MASK                 2U
#define RFCR0_BPS2_MASK                 4U
#define RFCR0_BPS3_MASK                 8U
#define RFCR0_BPS4_MASK                 16U
#define RFCR0_BPS5_MASK                 32U
#define RFCR0_BPS6_MASK                 64U
#define RFCR0_BPS7_MASK                 128U


/*** RFCR1 - RFM Control Register 1; 0x00000031 ***/
typedef union {
  byte Byte;
  struct {
    byte FRM0        :1;                                       /* Frame Bit Length, bit 0 */
    byte FRM1        :1;                                       /* Frame Bit Length, bit 1 */
    byte FRM2        :1;                                       /* Frame Bit Length, bit 2 */
    byte FRM3        :1;                                       /* Frame Bit Length, bit 3 */
    byte FRM4        :1;                                       /* Frame Bit Length, bit 4 */
    byte FRM5        :1;                                       /* Frame Bit Length, bit 5 */
    byte FRM6        :1;                                       /* Frame Bit Length, bit 6 */
    byte FRM7        :1;                                       /* Frame Bit Length, bit 7 */
  } Bits;
} RFCR1STR;
extern volatile RFCR1STR _RFCR1 @0x00000031;
#define RFCR1                           _RFCR1.Byte
#define RFCR1_FRM0                      _RFCR1.Bits.FRM0
#define RFCR1_FRM1                      _RFCR1.Bits.FRM1
#define RFCR1_FRM2                      _RFCR1.Bits.FRM2
#define RFCR1_FRM3                      _RFCR1.Bits.FRM3
#define RFCR1_FRM4                      _RFCR1.Bits.FRM4
#define RFCR1_FRM5                      _RFCR1.Bits.FRM5
#define RFCR1_FRM6                      _RFCR1.Bits.FRM6
#define RFCR1_FRM7                      _RFCR1.Bits.FRM7

#define RFCR1_FRM0_MASK                 1U
#define RFCR1_FRM1_MASK                 2U
#define RFCR1_FRM2_MASK                 4U
#define RFCR1_FRM3_MASK                 8U
#define RFCR1_FRM4_MASK                 16U
#define RFCR1_FRM5_MASK                 32U
#define RFCR1_FRM6_MASK                 64U
#define RFCR1_FRM7_MASK                 128U


/*** RFCR2 - RFM Control Register 2; 0x00000032 ***/
typedef union {
  byte Byte;
  struct {
    byte PWR0        :1;                                       /* RF Amplifier Power Level, bit 0 */
    byte PWR1        :1;                                       /* RF Amplifier Power Level, bit 1 */
    byte PWR2        :1;                                       /* RF Amplifier Power Level, bit 2 */
    byte PWR3        :1;                                       /* RF Amplifier Power Level, bit 3 */
    byte PWR4        :1;                                       /* RF Amplifier Power Level, bit 4 */
    byte EOM         :1;                                       /* End Of Message */
    byte RPAGE       :1;                                       /* Buffer Page Select */
    byte SEND        :1;                                       /* Transmission Start Control */
  } Bits;
  struct {
    byte grpPWR  :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} RFCR2STR;
extern volatile RFCR2STR _RFCR2 @0x00000032;
#define RFCR2                           _RFCR2.Byte
#define RFCR2_PWR0                      _RFCR2.Bits.PWR0
#define RFCR2_PWR1                      _RFCR2.Bits.PWR1
#define RFCR2_PWR2                      _RFCR2.Bits.PWR2
#define RFCR2_PWR3                      _RFCR2.Bits.PWR3
#define RFCR2_PWR4                      _RFCR2.Bits.PWR4
#define RFCR2_EOM                       _RFCR2.Bits.EOM
#define RFCR2_RPAGE                     _RFCR2.Bits.RPAGE
#define RFCR2_SEND                      _RFCR2.Bits.SEND
#define RFCR2_PWR                       _RFCR2.MergedBits.grpPWR

#define RFCR2_PWR0_MASK                 1U
#define RFCR2_PWR1_MASK                 2U
#define RFCR2_PWR2_MASK                 4U
#define RFCR2_PWR3_MASK                 8U
#define RFCR2_PWR4_MASK                 16U
#define RFCR2_EOM_MASK                  32U
#define RFCR2_RPAGE_MASK                64U
#define RFCR2_SEND_MASK                 128U
#define RFCR2_PWR_MASK                  31U
#define RFCR2_PWR_BITNUM                0U


/*** RFCR3 - RFM Control Register 3; 0x00000033 ***/
typedef union {
  byte Byte;
  struct {
    byte FNUM0       :1;                                       /* Number of Transmitted Frames, bit 0 */
    byte FNUM1       :1;                                       /* Number of Transmitted Frames, bit 1 */
    byte FNUM2       :1;                                       /* Number of Transmitted Frames, bit 2 */
    byte FNUM3       :1;                                       /* Number of Transmitted Frames, bit 3 */
    byte IFID        :1;                                       /* Interframe Interrupt Delay */
    byte ISPC        :1;                                       /* Initial Random Space */
    byte IFPD        :1;                                       /* Interframe Power Down */
    byte DATA        :1;                                       /* Data State */
  } Bits;
  struct {
    byte grpFNUM :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpDATx :1;
  } MergedBits;
} RFCR3STR;
extern volatile RFCR3STR _RFCR3 @0x00000033;
#define RFCR3                           _RFCR3.Byte
#define RFCR3_FNUM0                     _RFCR3.Bits.FNUM0
#define RFCR3_FNUM1                     _RFCR3.Bits.FNUM1
#define RFCR3_FNUM2                     _RFCR3.Bits.FNUM2
#define RFCR3_FNUM3                     _RFCR3.Bits.FNUM3
#define RFCR3_IFID                      _RFCR3.Bits.IFID
#define RFCR3_ISPC                      _RFCR3.Bits.ISPC
#define RFCR3_IFPD                      _RFCR3.Bits.IFPD
#define RFCR3_DATA                      _RFCR3.Bits.DATA
#define RFCR3_FNUM                      _RFCR3.MergedBits.grpFNUM

#define RFCR3_FNUM0_MASK                1U
#define RFCR3_FNUM1_MASK                2U
#define RFCR3_FNUM2_MASK                4U
#define RFCR3_FNUM3_MASK                8U
#define RFCR3_IFID_MASK                 16U
#define RFCR3_ISPC_MASK                 32U
#define RFCR3_IFPD_MASK                 64U
#define RFCR3_DATA_MASK                 128U
#define RFCR3_FNUM_MASK                 15U
#define RFCR3_FNUM_BITNUM               0U


/*** RFCR4 - RFM Control Register 4; 0x00000034 ***/
typedef union {
  byte Byte;
  struct {
    byte RFBT0       :1;                                       /* Base Timer, bit 0 */
    byte RFBT1       :1;                                       /* Base Timer, bit 1 */
    byte RFBT2       :1;                                       /* Base Timer, bit 2 */
    byte RFBT3       :1;                                       /* Base Timer, bit 3 */
    byte RFBT4       :1;                                       /* Base Timer, bit 4 */
    byte RFBT5       :1;                                       /* Base Timer, bit 5 */
    byte RFBT6       :1;                                       /* Base Timer, bit 6 */
    byte RFBT7       :1;                                       /* Base Timer, bit 7 */
  } Bits;
} RFCR4STR;
extern volatile RFCR4STR _RFCR4 @0x00000034;
#define RFCR4                           _RFCR4.Byte
#define RFCR4_RFBT0                     _RFCR4.Bits.RFBT0
#define RFCR4_RFBT1                     _RFCR4.Bits.RFBT1
#define RFCR4_RFBT2                     _RFCR4.Bits.RFBT2
#define RFCR4_RFBT3                     _RFCR4.Bits.RFBT3
#define RFCR4_RFBT4                     _RFCR4.Bits.RFBT4
#define RFCR4_RFBT5                     _RFCR4.Bits.RFBT5
#define RFCR4_RFBT6                     _RFCR4.Bits.RFBT6
#define RFCR4_RFBT7                     _RFCR4.Bits.RFBT7

#define RFCR4_RFBT0_MASK                1U
#define RFCR4_RFBT1_MASK                2U
#define RFCR4_RFBT2_MASK                4U
#define RFCR4_RFBT3_MASK                8U
#define RFCR4_RFBT4_MASK                16U
#define RFCR4_RFBT5_MASK                32U
#define RFCR4_RFBT6_MASK                64U
#define RFCR4_RFBT7_MASK                128U


/*** RFCR5 - RFM Control Register 5; 0x00000035 ***/
typedef union {
  byte Byte;
  struct {
    byte LFSR0       :1;                                       /* Pseudo-Random Timer, bit 0 */
    byte LFSR1       :1;                                       /* Pseudo-Random Timer, bit 1 */
    byte LFSR2       :1;                                       /* Pseudo-Random Timer, bit 2 */
    byte LFSR3       :1;                                       /* Pseudo-Random Timer, bit 3 */
    byte LFSR4       :1;                                       /* Pseudo-Random Timer, bit 4 */
    byte LFSR5       :1;                                       /* Pseudo-Random Timer, bit 5 */
    byte LFSR6       :1;                                       /* Pseudo-Random Timer, bit 6 */
    byte BOOST       :1;                                       /* BOOST */
  } Bits;
  struct {
    byte grpLFSR :7;
    byte         :1;
  } MergedBits;
} RFCR5STR;
extern volatile RFCR5STR _RFCR5 @0x00000035;
#define RFCR5                           _RFCR5.Byte
#define RFCR5_LFSR0                     _RFCR5.Bits.LFSR0
#define RFCR5_LFSR1                     _RFCR5.Bits.LFSR1
#define RFCR5_LFSR2                     _RFCR5.Bits.LFSR2
#define RFCR5_LFSR3                     _RFCR5.Bits.LFSR3
#define RFCR5_LFSR4                     _RFCR5.Bits.LFSR4
#define RFCR5_LFSR5                     _RFCR5.Bits.LFSR5
#define RFCR5_LFSR6                     _RFCR5.Bits.LFSR6
#define RFCR5_BOOST                     _RFCR5.Bits.BOOST
#define RFCR5_LFSR                      _RFCR5.MergedBits.grpLFSR

#define RFCR5_LFSR0_MASK                1U
#define RFCR5_LFSR1_MASK                2U
#define RFCR5_LFSR2_MASK                4U
#define RFCR5_LFSR3_MASK                8U
#define RFCR5_LFSR4_MASK                16U
#define RFCR5_LFSR5_MASK                32U
#define RFCR5_LFSR6_MASK                64U
#define RFCR5_BOOST_MASK                128U
#define RFCR5_LFSR_MASK                 127U
#define RFCR5_LFSR_BITNUM               0U


/*** RFCR6 - RFM Control Register 6; 0x00000036 ***/
typedef union {
  byte Byte;
  struct {
    byte RFFT0       :1;                                       /* Frame Number Timer, bit 0 */
    byte RFFT1       :1;                                       /* Frame Number Timer, bit 1 */
    byte RFFT2       :1;                                       /* Frame Number Timer, bit 2 */
    byte RFFT3       :1;                                       /* Frame Number Timer, bit 3 */
    byte RFFT4       :1;                                       /* Frame Number Timer, bit 4 */
    byte RFFT5       :1;                                       /* Frame Number Timer, bit 5 */
    byte VCO_GAIN0   :1;                                       /* VCO Gain Selection, bit 0 */
    byte VCO_GAIN1   :1;                                       /* VCO Gain Selection, bit 1 */
  } Bits;
  struct {
    byte grpRFFT :6;
    byte grpVCO_GAIN :2;
  } MergedBits;
} RFCR6STR;
extern volatile RFCR6STR _RFCR6 @0x00000036;
#define RFCR6                           _RFCR6.Byte
#define RFCR6_RFFT0                     _RFCR6.Bits.RFFT0
#define RFCR6_RFFT1                     _RFCR6.Bits.RFFT1
#define RFCR6_RFFT2                     _RFCR6.Bits.RFFT2
#define RFCR6_RFFT3                     _RFCR6.Bits.RFFT3
#define RFCR6_RFFT4                     _RFCR6.Bits.RFFT4
#define RFCR6_RFFT5                     _RFCR6.Bits.RFFT5
#define RFCR6_VCO_GAIN0                 _RFCR6.Bits.VCO_GAIN0
#define RFCR6_VCO_GAIN1                 _RFCR6.Bits.VCO_GAIN1
#define RFCR6_RFFT                      _RFCR6.MergedBits.grpRFFT
#define RFCR6_VCO_GAIN                  _RFCR6.MergedBits.grpVCO_GAIN

#define RFCR6_RFFT0_MASK                1U
#define RFCR6_RFFT1_MASK                2U
#define RFCR6_RFFT2_MASK                4U
#define RFCR6_RFFT3_MASK                8U
#define RFCR6_RFFT4_MASK                16U
#define RFCR6_RFFT5_MASK                32U
#define RFCR6_VCO_GAIN0_MASK            64U
#define RFCR6_VCO_GAIN1_MASK            128U
#define RFCR6_RFFT_MASK                 63U
#define RFCR6_RFFT_BITNUM               0U
#define RFCR6_VCO_GAIN_MASK             192U
#define RFCR6_VCO_GAIN_BITNUM           6U


/*** RFCR7 - RFM Control Register 7; 0x00000037 ***/
typedef union {
  byte Byte;
  struct {
    byte RFMRST      :1;                                       /* RFM Reset */
    byte RCTS        :1;                                       /* RF Clear To Send Status */
    byte RFLVDEN     :1;                                       /* RF LVD Enable */
    byte RFIEN       :1;                                       /* RF Interrupt Enable */
    byte RFIAK       :1;                                       /* Acknowledge RF Interrupt Flags */
    byte RFVF        :1;                                       /* RF LVD Trigger Flag */
    byte RFEF        :1;                                       /* RF Transmission Error Flag */
    byte RFIF        :1;                                       /* RF Interrupt Flag */
  } Bits;
} RFCR7STR;
extern volatile RFCR7STR _RFCR7 @0x00000037;
#define RFCR7                           _RFCR7.Byte
#define RFCR7_RFMRST                    _RFCR7.Bits.RFMRST
#define RFCR7_RCTS                      _RFCR7.Bits.RCTS
#define RFCR7_RFLVDEN                   _RFCR7.Bits.RFLVDEN
#define RFCR7_RFIEN                     _RFCR7.Bits.RFIEN
#define RFCR7_RFIAK                     _RFCR7.Bits.RFIAK
#define RFCR7_RFVF                      _RFCR7.Bits.RFVF
#define RFCR7_RFEF                      _RFCR7.Bits.RFEF
#define RFCR7_RFIF                      _RFCR7.Bits.RFIF

#define RFCR7_RFMRST_MASK               1U
#define RFCR7_RCTS_MASK                 2U
#define RFCR7_RFLVDEN_MASK              4U
#define RFCR7_RFIEN_MASK                8U
#define RFCR7_RFIAK_MASK                16U
#define RFCR7_RFVF_MASK                 32U
#define RFCR7_RFEF_MASK                 64U
#define RFCR7_RFIF_MASK                 128U


/*** EPR_PLL_LPF - EPR Register (RPAGE = 1, VCD_EN = 0); 0x00000038 ***/
typedef union {
  byte Byte;
  union { /* Several registers at the same address */
    /*** EPR_PLL_LPF - EPR Register (RPAGE = 1, VCD_EN = 0); Several registers at the same address ***/
    union {
      struct {
        byte             :1; 
        byte PA_SLOPE    :1;                                       /* PA Output Slope Selection */
        byte             :1; 
        byte             :1; 
        byte PLL_LPF0    :1;                                       /* Low Pass Filter Selection, bit 0 */
        byte PLL_LPF1    :1;                                       /* Low Pass Filter Selection, bit 1 */
        byte PLL_LPF2    :1;                                       /* Low Pass Filter Selection, bit 2 */
        byte             :1; 
      } Bits;
      struct {
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte grpPLL_LPF :3;
        byte     :1;
      } MergedBits;
    } EPR_PLL_LPFSTR;
    #define EPR_PLL_LPF                 _EPR_PLL_LPF.Byte
    #define EPR_PLL_LPF_PA_SLOPE        _EPR_PLL_LPF.SameAddr_STR.EPR_PLL_LPFSTR.Bits.PA_SLOPE
    #define EPR_PLL_LPF_PLL_LPF0        _EPR_PLL_LPF.SameAddr_STR.EPR_PLL_LPFSTR.Bits.PLL_LPF0
    #define EPR_PLL_LPF_PLL_LPF1        _EPR_PLL_LPF.SameAddr_STR.EPR_PLL_LPFSTR.Bits.PLL_LPF1
    #define EPR_PLL_LPF_PLL_LPF2        _EPR_PLL_LPF.SameAddr_STR.EPR_PLL_LPFSTR.Bits.PLL_LPF2
    #define EPR_PLL_LPF_PLL_LPF         _EPR_PLL_LPF.SameAddr_STR.EPR_PLL_LPFSTR.MergedBits.grpPLL_LPF
    
    #define EPR_PLL_LPF_PA_SLOPE_MASK   2U
    #define EPR_PLL_LPF_PLL_LPF0_MASK   16U
    #define EPR_PLL_LPF_PLL_LPF1_MASK   32U
    #define EPR_PLL_LPF_PLL_LPF2_MASK   64U
    #define EPR_PLL_LPF_PLL_LPF_MASK    112U
    #define EPR_PLL_LPF_PLL_LPF_BITNUM  4U
    
    /*** EPR_VCD - EPR Register (RPAGE = 1, VCD_EN = 1); Several registers at the same address ***/
    union {
      struct {
        byte VCD_EN      :1;                                       /* VCD Enable bit */
        byte PA_SLOPE    :1;                                       /* PA Output Slope Selection */
        byte             :1; 
        byte             :1; 
        byte VCD0        :1;                                       /* VCO Calibration Count Difference, bit 0 */
        byte VCD1        :1;                                       /* VCO Calibration Count Difference, bit 1 */
        byte VCD2        :1;                                       /* VCO Calibration Count Difference, bit 2 */
        byte VCD3        :1;                                       /* VCO Calibration Count Difference, bit 3 */
      } Bits;
      struct {
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte grpVCD :4;
      } MergedBits;
    } EPR_VCDSTR;
    #define EPR_VCD                     _EPR_PLL_LPF.Byte
    #define EPR_VCD_VCD_EN              _EPR_PLL_LPF.SameAddr_STR.EPR_VCDSTR.Bits.VCD_EN
    #define EPR_VCD_PA_SLOPE            _EPR_PLL_LPF.SameAddr_STR.EPR_VCDSTR.Bits.PA_SLOPE
    #define EPR_VCD_VCD0                _EPR_PLL_LPF.SameAddr_STR.EPR_VCDSTR.Bits.VCD0
    #define EPR_VCD_VCD1                _EPR_PLL_LPF.SameAddr_STR.EPR_VCDSTR.Bits.VCD1
    #define EPR_VCD_VCD2                _EPR_PLL_LPF.SameAddr_STR.EPR_VCDSTR.Bits.VCD2
    #define EPR_VCD_VCD3                _EPR_PLL_LPF.SameAddr_STR.EPR_VCDSTR.Bits.VCD3
    #define EPR_VCD_VCD                 _EPR_PLL_LPF.SameAddr_STR.EPR_VCDSTR.MergedBits.grpVCD
    
    #define EPR_VCD_VCD_EN_MASK         1U
    #define EPR_VCD_PA_SLOPE_MASK       2U
    #define EPR_VCD_VCD0_MASK           16U
    #define EPR_VCD_VCD1_MASK           32U
    #define EPR_VCD_VCD2_MASK           64U
    #define EPR_VCD_VCD3_MASK           128U
    #define EPR_VCD_VCD_MASK            240U
    #define EPR_VCD_VCD_BITNUM          4U
    
    /*** PLLCR0 - PLL Control Register 0 (RPAGE = 0); Several registers at the same address ***/
    union {
      struct {
        byte AFREQ5      :1;                                       /* PLL Divider Ratio A, bit 5 */
        byte AFREQ6      :1;                                       /* PLL Divider Ratio A, bit 6 */
        byte AFREQ7      :1;                                       /* PLL Divider Ratio A, bit 7 */
        byte AFREQ8      :1;                                       /* PLL Divider Ratio A, bit 8 */
        byte AFREQ9      :1;                                       /* PLL Divider Ratio A, bit 9 */
        byte AFREQ10     :1;                                       /* PLL Divider Ratio A, bit 10 */
        byte AFREQ11     :1;                                       /* PLL Divider Ratio A, bit 11 */
        byte AFREQ12     :1;                                       /* PLL Divider Ratio A, bit 12 */
      } Bits;
    } PLLCR0STR;
    #define PLLCR0                      _EPR_PLL_LPF.Byte
    #define PLLCR0_AFREQ5               _EPR_PLL_LPF.SameAddr_STR.PLLCR0STR.Bits.AFREQ5
    #define PLLCR0_AFREQ6               _EPR_PLL_LPF.SameAddr_STR.PLLCR0STR.Bits.AFREQ6
    #define PLLCR0_AFREQ7               _EPR_PLL_LPF.SameAddr_STR.PLLCR0STR.Bits.AFREQ7
    #define PLLCR0_AFREQ8               _EPR_PLL_LPF.SameAddr_STR.PLLCR0STR.Bits.AFREQ8
    #define PLLCR0_AFREQ9               _EPR_PLL_LPF.SameAddr_STR.PLLCR0STR.Bits.AFREQ9
    #define PLLCR0_AFREQ10              _EPR_PLL_LPF.SameAddr_STR.PLLCR0STR.Bits.AFREQ10
    #define PLLCR0_AFREQ11              _EPR_PLL_LPF.SameAddr_STR.PLLCR0STR.Bits.AFREQ11
    #define PLLCR0_AFREQ12              _EPR_PLL_LPF.SameAddr_STR.PLLCR0STR.Bits.AFREQ12
    /* PLLCR_ARR: Access 4 PLLCRx registers in an array */
    #define PLLCR_ARR                   ((volatile byte * __far) &PLLCR0)
    
    #define PLLCR0_AFREQ5_MASK          1U
    #define PLLCR0_AFREQ6_MASK          2U
    #define PLLCR0_AFREQ7_MASK          4U
    #define PLLCR0_AFREQ8_MASK          8U
    #define PLLCR0_AFREQ9_MASK          16U
    #define PLLCR0_AFREQ10_MASK         32U
    #define PLLCR0_AFREQ11_MASK         64U
    #define PLLCR0_AFREQ12_MASK         128U
    
  } SameAddr_STR; /*Several registers at the same address */

} EPR_PLL_LPFSTR;
extern volatile EPR_PLL_LPFSTR _EPR_PLL_LPF @0x00000038;


/*** PLLCR1 - PLL Control Register 1 (RPAGE = 0); 0x00000039 ***/
typedef union {
  byte Byte;
  struct {
    byte CODE0       :1;                                       /* Data Encoding and Source, bit 0 */
    byte CODE1       :1;                                       /* Data Encoding and Source, bit 1 */
    byte POL         :1;                                       /* Data Polarity */
    byte AFREQ0      :1;                                       /* PLL Divider Ratio A, bit 0 */
    byte AFREQ1      :1;                                       /* PLL Divider Ratio A, bit 1 */
    byte AFREQ2      :1;                                       /* PLL Divider Ratio A, bit 2 */
    byte AFREQ3      :1;                                       /* PLL Divider Ratio A, bit 3 */
    byte AFREQ4      :1;                                       /* PLL Divider Ratio A, bit 4 */
  } Bits;
  struct {
    byte grpCODE :2;
    byte         :1;
    byte grpAFREQ :5;
  } MergedBits;
} PLLCR1STR;
extern volatile PLLCR1STR _PLLCR1 @0x00000039;
#define PLLCR1                          _PLLCR1.Byte
#define PLLCR1_CODE0                    _PLLCR1.Bits.CODE0
#define PLLCR1_CODE1                    _PLLCR1.Bits.CODE1
#define PLLCR1_POL                      _PLLCR1.Bits.POL
#define PLLCR1_AFREQ0                   _PLLCR1.Bits.AFREQ0
#define PLLCR1_AFREQ1                   _PLLCR1.Bits.AFREQ1
#define PLLCR1_AFREQ2                   _PLLCR1.Bits.AFREQ2
#define PLLCR1_AFREQ3                   _PLLCR1.Bits.AFREQ3
#define PLLCR1_AFREQ4                   _PLLCR1.Bits.AFREQ4
#define PLLCR1_CODE                     _PLLCR1.MergedBits.grpCODE
#define PLLCR1_AFREQ                    _PLLCR1.MergedBits.grpAFREQ

#define PLLCR1_CODE0_MASK               1U
#define PLLCR1_CODE1_MASK               2U
#define PLLCR1_POL_MASK                 4U
#define PLLCR1_AFREQ0_MASK              8U
#define PLLCR1_AFREQ1_MASK              16U
#define PLLCR1_AFREQ2_MASK              32U
#define PLLCR1_AFREQ3_MASK              64U
#define PLLCR1_AFREQ4_MASK              128U
#define PLLCR1_CODE_MASK                3U
#define PLLCR1_CODE_BITNUM              0U
#define PLLCR1_AFREQ_MASK               248U
#define PLLCR1_AFREQ_BITNUM             3U


/*** PLLCR2 - PLL Control Register 2 (RPAGE = 0); 0x0000003A ***/
typedef union {
  byte Byte;
  struct {
    byte BFREQ5      :1;                                       /* PLL Divider Ratio B, bit 5 */
    byte BFREQ6      :1;                                       /* PLL Divider Ratio B, bit 6 */
    byte BFREQ7      :1;                                       /* PLL Divider Ratio B, bit 7 */
    byte BFREQ8      :1;                                       /* PLL Divider Ratio B, bit 8 */
    byte BFREQ9      :1;                                       /* PLL Divider Ratio B, bit 9 */
    byte BFREQ10     :1;                                       /* PLL Divider Ratio B, bit 10 */
    byte BFREQ11     :1;                                       /* PLL Divider Ratio B, bit 11 */
    byte BFREQ12     :1;                                       /* PLL Divider Ratio B, bit 12 */
  } Bits;
} PLLCR2STR;
extern volatile PLLCR2STR _PLLCR2 @0x0000003A;
#define PLLCR2                          _PLLCR2.Byte
#define PLLCR2_BFREQ5                   _PLLCR2.Bits.BFREQ5
#define PLLCR2_BFREQ6                   _PLLCR2.Bits.BFREQ6
#define PLLCR2_BFREQ7                   _PLLCR2.Bits.BFREQ7
#define PLLCR2_BFREQ8                   _PLLCR2.Bits.BFREQ8
#define PLLCR2_BFREQ9                   _PLLCR2.Bits.BFREQ9
#define PLLCR2_BFREQ10                  _PLLCR2.Bits.BFREQ10
#define PLLCR2_BFREQ11                  _PLLCR2.Bits.BFREQ11
#define PLLCR2_BFREQ12                  _PLLCR2.Bits.BFREQ12

#define PLLCR2_BFREQ5_MASK              1U
#define PLLCR2_BFREQ6_MASK              2U
#define PLLCR2_BFREQ7_MASK              4U
#define PLLCR2_BFREQ8_MASK              8U
#define PLLCR2_BFREQ9_MASK              16U
#define PLLCR2_BFREQ10_MASK             32U
#define PLLCR2_BFREQ11_MASK             64U
#define PLLCR2_BFREQ12_MASK             128U


/*** PLLCR3 - PLL Control Register 3 (RPAGE = 0); 0x0000003B ***/
typedef union {
  byte Byte;
  struct {
    byte CKREF       :1;                                       /* Generated Clock Reference */
    byte MOD         :1;                                       /* RF Modulation Method */
    byte CF          :1;                                       /* Carrier Frequency */
    byte BFREQ0      :1;                                       /* PLL Divider Ratio B, bit 0 */
    byte BFREQ1      :1;                                       /* PLL Divider Ratio B, bit 1 */
    byte BFREQ2      :1;                                       /* PLL Divider Ratio B, bit 2 */
    byte BFREQ3      :1;                                       /* PLL Divider Ratio B, bit 3 */
    byte BFREQ4      :1;                                       /* PLL Divider Ratio B, bit 4 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpBFREQ :5;
  } MergedBits;
} PLLCR3STR;
extern volatile PLLCR3STR _PLLCR3 @0x0000003B;
#define PLLCR3                          _PLLCR3.Byte
#define PLLCR3_CKREF                    _PLLCR3.Bits.CKREF
#define PLLCR3_MOD                      _PLLCR3.Bits.MOD
#define PLLCR3_CF                       _PLLCR3.Bits.CF
#define PLLCR3_BFREQ0                   _PLLCR3.Bits.BFREQ0
#define PLLCR3_BFREQ1                   _PLLCR3.Bits.BFREQ1
#define PLLCR3_BFREQ2                   _PLLCR3.Bits.BFREQ2
#define PLLCR3_BFREQ3                   _PLLCR3.Bits.BFREQ3
#define PLLCR3_BFREQ4                   _PLLCR3.Bits.BFREQ4
#define PLLCR3_BFREQ                    _PLLCR3.MergedBits.grpBFREQ

#define PLLCR3_CKREF_MASK               1U
#define PLLCR3_MOD_MASK                 2U
#define PLLCR3_CF_MASK                  4U
#define PLLCR3_BFREQ0_MASK              8U
#define PLLCR3_BFREQ1_MASK              16U
#define PLLCR3_BFREQ2_MASK              32U
#define PLLCR3_BFREQ3_MASK              64U
#define PLLCR3_BFREQ4_MASK              128U
#define PLLCR3_BFREQ_MASK               248U
#define PLLCR3_BFREQ_BITNUM             3U


/*** RFD0 - RFD Register 0; 0x0000003C ***/
typedef union {
  byte Byte;
  struct {
    byte RFD0_bit    :1;                                       /* RFD, bit 0 */ /*Warning: bit name is duplicated with register name*/
    byte RFD1_bit    :1;                                       /* RFD, bit 1 */ /*Warning: bit name is duplicated with register name*/
    byte RFD2_bit    :1;                                       /* RFD, bit 2 */ /*Warning: bit name is duplicated with register name*/
    byte RFD3_bit    :1;                                       /* RFD, bit 3 */ /*Warning: bit name is duplicated with register name*/
    byte RFD4_bit    :1;                                       /* RFD, bit 4 */ /*Warning: bit name is duplicated with register name*/
    byte RFD5_bit    :1;                                       /* RFD, bit 5 */ /*Warning: bit name is duplicated with register name*/
    byte RFD6_bit    :1;                                       /* RFD, bit 6 */ /*Warning: bit name is duplicated with register name*/
    byte RFD7_bit    :1;                                       /* RFD, bit 7 */ /*Warning: bit name is duplicated with register name*/
  } Bits;
} RFD0STR;
extern volatile RFD0STR _RFD0 @0x0000003C;
#define RFD0                            _RFD0.Byte
#define RFD0_RFD0                       _RFD0.Bits.RFD0_bit
#define RFD0_RFD1                       _RFD0.Bits.RFD1_bit
#define RFD0_RFD2                       _RFD0.Bits.RFD2_bit
#define RFD0_RFD3                       _RFD0.Bits.RFD3_bit
#define RFD0_RFD4                       _RFD0.Bits.RFD4_bit
#define RFD0_RFD5                       _RFD0.Bits.RFD5_bit
#define RFD0_RFD6                       _RFD0.Bits.RFD6_bit
#define RFD0_RFD7                       _RFD0.Bits.RFD7_bit
/* RFD_ARR: Access 16 RFDx registers in an array */
#define RFD_ARR                         ((volatile byte * __far) &RFD0)

#define RFD0_RFD0_MASK                  1U
#define RFD0_RFD1_MASK                  2U
#define RFD0_RFD2_MASK                  4U
#define RFD0_RFD3_MASK                  8U
#define RFD0_RFD4_MASK                  16U
#define RFD0_RFD5_MASK                  32U
#define RFD0_RFD6_MASK                  64U
#define RFD0_RFD7_MASK                  128U


/*** RFD1 - RFD Register 1; 0x0000003D ***/
typedef union {
  byte Byte;
  struct {
    byte RFD8_bit    :1;                                       /* RFD, bit 8 */ /*Warning: bit name is duplicated with register name*/
    byte RFD9_bit    :1;                                       /* RFD, bit 9 */ /*Warning: bit name is duplicated with register name*/
    byte RFD10_bit   :1;                                       /* RFD, bit 10 */ /*Warning: bit name is duplicated with register name*/
    byte RFD11_bit   :1;                                       /* RFD, bit 11 */ /*Warning: bit name is duplicated with register name*/
    byte RFD12_bit   :1;                                       /* RFD, bit 12 */ /*Warning: bit name is duplicated with register name*/
    byte RFD13_bit   :1;                                       /* RFD, bit 13 */ /*Warning: bit name is duplicated with register name*/
    byte RFD14_bit   :1;                                       /* RFD, bit 14 */ /*Warning: bit name is duplicated with register name*/
    byte RFD15_bit   :1;                                       /* RFD, bit 15 */ /*Warning: bit name is duplicated with register name*/
  } Bits;
} RFD1STR;
extern volatile RFD1STR _RFD1 @0x0000003D;
#define RFD1                            _RFD1.Byte
#define RFD1_RFD8                       _RFD1.Bits.RFD8_bit
#define RFD1_RFD9                       _RFD1.Bits.RFD9_bit
#define RFD1_RFD10                      _RFD1.Bits.RFD10_bit
#define RFD1_RFD11                      _RFD1.Bits.RFD11_bit
#define RFD1_RFD12                      _RFD1.Bits.RFD12_bit
#define RFD1_RFD13                      _RFD1.Bits.RFD13_bit
#define RFD1_RFD14                      _RFD1.Bits.RFD14_bit
#define RFD1_RFD15                      _RFD1.Bits.RFD15_bit

#define RFD1_RFD8_MASK                  1U
#define RFD1_RFD9_MASK                  2U
#define RFD1_RFD10_MASK                 4U
#define RFD1_RFD11_MASK                 8U
#define RFD1_RFD12_MASK                 16U
#define RFD1_RFD13_MASK                 32U
#define RFD1_RFD14_MASK                 64U
#define RFD1_RFD15_MASK                 128U


/*** RFD2 - RFD Register 2; 0x0000003E ***/
typedef union {
  byte Byte;
  struct {
    byte RFD16       :1;                                       /* RFD, bit 16 */
    byte RFD17       :1;                                       /* RFD, bit 17 */
    byte RFD18       :1;                                       /* RFD, bit 18 */
    byte RFD19       :1;                                       /* RFD, bit 19 */
    byte RFD20       :1;                                       /* RFD, bit 20 */
    byte RFD21       :1;                                       /* RFD, bit 21 */
    byte RFD22       :1;                                       /* RFD, bit 22 */
    byte RFD23       :1;                                       /* RFD, bit 23 */
  } Bits;
} RFD2STR;
extern volatile RFD2STR _RFD2 @0x0000003E;
#define RFD2                            _RFD2.Byte
#define RFD2_RFD16                      _RFD2.Bits.RFD16
#define RFD2_RFD17                      _RFD2.Bits.RFD17
#define RFD2_RFD18                      _RFD2.Bits.RFD18
#define RFD2_RFD19                      _RFD2.Bits.RFD19
#define RFD2_RFD20                      _RFD2.Bits.RFD20
#define RFD2_RFD21                      _RFD2.Bits.RFD21
#define RFD2_RFD22                      _RFD2.Bits.RFD22
#define RFD2_RFD23                      _RFD2.Bits.RFD23

#define RFD2_RFD16_MASK                 1U
#define RFD2_RFD17_MASK                 2U
#define RFD2_RFD18_MASK                 4U
#define RFD2_RFD19_MASK                 8U
#define RFD2_RFD20_MASK                 16U
#define RFD2_RFD21_MASK                 32U
#define RFD2_RFD22_MASK                 64U
#define RFD2_RFD23_MASK                 128U


/*** RFD3 - RFD Register 3; 0x0000003F ***/
typedef union {
  byte Byte;
  struct {
    byte RFD24       :1;                                       /* RFD, bit 24 */
    byte RFD25       :1;                                       /* RFD, bit 25 */
    byte RFD26       :1;                                       /* RFD, bit 26 */
    byte RFD27       :1;                                       /* RFD, bit 27 */
    byte RFD28       :1;                                       /* RFD, bit 28 */
    byte RFD29       :1;                                       /* RFD, bit 29 */
    byte RFD30       :1;                                       /* RFD, bit 30 */
    byte RFD31       :1;                                       /* RFD, bit 31 */
  } Bits;
} RFD3STR;
extern volatile RFD3STR _RFD3 @0x0000003F;
#define RFD3                            _RFD3.Byte
#define RFD3_RFD24                      _RFD3.Bits.RFD24
#define RFD3_RFD25                      _RFD3.Bits.RFD25
#define RFD3_RFD26                      _RFD3.Bits.RFD26
#define RFD3_RFD27                      _RFD3.Bits.RFD27
#define RFD3_RFD28                      _RFD3.Bits.RFD28
#define RFD3_RFD29                      _RFD3.Bits.RFD29
#define RFD3_RFD30                      _RFD3.Bits.RFD30
#define RFD3_RFD31                      _RFD3.Bits.RFD31

#define RFD3_RFD24_MASK                 1U
#define RFD3_RFD25_MASK                 2U
#define RFD3_RFD26_MASK                 4U
#define RFD3_RFD27_MASK                 8U
#define RFD3_RFD28_MASK                 16U
#define RFD3_RFD29_MASK                 32U
#define RFD3_RFD30_MASK                 64U
#define RFD3_RFD31_MASK                 128U


/*** RFD4 - RFD Register 4; 0x00000040 ***/
typedef union {
  byte Byte;
  struct {
    byte RFD32       :1;                                       /* RFD, bit 32 */
    byte RFD33       :1;                                       /* RFD, bit 33 */
    byte RFD34       :1;                                       /* RFD, bit 34 */
    byte RFD35       :1;                                       /* RFD, bit 35 */
    byte RFD36       :1;                                       /* RFD, bit 36 */
    byte RFD37       :1;                                       /* RFD, bit 37 */
    byte RFD38       :1;                                       /* RFD, bit 38 */
    byte RFD39       :1;                                       /* RFD, bit 39 */
  } Bits;
} RFD4STR;
extern volatile RFD4STR _RFD4 @0x00000040;
#define RFD4                            _RFD4.Byte
#define RFD4_RFD32                      _RFD4.Bits.RFD32
#define RFD4_RFD33                      _RFD4.Bits.RFD33
#define RFD4_RFD34                      _RFD4.Bits.RFD34
#define RFD4_RFD35                      _RFD4.Bits.RFD35
#define RFD4_RFD36                      _RFD4.Bits.RFD36
#define RFD4_RFD37                      _RFD4.Bits.RFD37
#define RFD4_RFD38                      _RFD4.Bits.RFD38
#define RFD4_RFD39                      _RFD4.Bits.RFD39

#define RFD4_RFD32_MASK                 1U
#define RFD4_RFD33_MASK                 2U
#define RFD4_RFD34_MASK                 4U
#define RFD4_RFD35_MASK                 8U
#define RFD4_RFD36_MASK                 16U
#define RFD4_RFD37_MASK                 32U
#define RFD4_RFD38_MASK                 64U
#define RFD4_RFD39_MASK                 128U


/*** RFD5 - RFD Register 5; 0x00000041 ***/
typedef union {
  byte Byte;
  struct {
    byte RFD40       :1;                                       /* RFD, bit 40 */
    byte RFD41       :1;                                       /* RFD, bit 41 */
    byte RFD42       :1;                                       /* RFD, bit 42 */
    byte RFD43       :1;                                       /* RFD, bit 43 */
    byte RFD44       :1;                                       /* RFD, bit 44 */
    byte RFD45       :1;                                       /* RFD, bit 45 */
    byte RFD46       :1;                                       /* RFD, bit 46 */
    byte RFD47       :1;                                       /* RFD, bit 47 */
  } Bits;
} RFD5STR;
extern volatile RFD5STR _RFD5 @0x00000041;
#define RFD5                            _RFD5.Byte
#define RFD5_RFD40                      _RFD5.Bits.RFD40
#define RFD5_RFD41                      _RFD5.Bits.RFD41
#define RFD5_RFD42                      _RFD5.Bits.RFD42
#define RFD5_RFD43                      _RFD5.Bits.RFD43
#define RFD5_RFD44                      _RFD5.Bits.RFD44
#define RFD5_RFD45                      _RFD5.Bits.RFD45
#define RFD5_RFD46                      _RFD5.Bits.RFD46
#define RFD5_RFD47                      _RFD5.Bits.RFD47

#define RFD5_RFD40_MASK                 1U
#define RFD5_RFD41_MASK                 2U
#define RFD5_RFD42_MASK                 4U
#define RFD5_RFD43_MASK                 8U
#define RFD5_RFD44_MASK                 16U
#define RFD5_RFD45_MASK                 32U
#define RFD5_RFD46_MASK                 64U
#define RFD5_RFD47_MASK                 128U


/*** RFD6 - RFD Register 6; 0x00000042 ***/
typedef union {
  byte Byte;
  struct {
    byte RFD48       :1;                                       /* RFD, bit 48 */
    byte RFD49       :1;                                       /* RFD, bit 49 */
    byte RFD50       :1;                                       /* RFD, bit 50 */
    byte RFD51       :1;                                       /* RFD, bit 51 */
    byte RFD52       :1;                                       /* RFD, bit 52 */
    byte RFD53       :1;                                       /* RFD, bit 53 */
    byte RFD54       :1;                                       /* RFD, bit 54 */
    byte RFD55       :1;                                       /* RFD, bit 55 */
  } Bits;
} RFD6STR;
extern volatile RFD6STR _RFD6 @0x00000042;
#define RFD6                            _RFD6.Byte
#define RFD6_RFD48                      _RFD6.Bits.RFD48
#define RFD6_RFD49                      _RFD6.Bits.RFD49
#define RFD6_RFD50                      _RFD6.Bits.RFD50
#define RFD6_RFD51                      _RFD6.Bits.RFD51
#define RFD6_RFD52                      _RFD6.Bits.RFD52
#define RFD6_RFD53                      _RFD6.Bits.RFD53
#define RFD6_RFD54                      _RFD6.Bits.RFD54
#define RFD6_RFD55                      _RFD6.Bits.RFD55

#define RFD6_RFD48_MASK                 1U
#define RFD6_RFD49_MASK                 2U
#define RFD6_RFD50_MASK                 4U
#define RFD6_RFD51_MASK                 8U
#define RFD6_RFD52_MASK                 16U
#define RFD6_RFD53_MASK                 32U
#define RFD6_RFD54_MASK                 64U
#define RFD6_RFD55_MASK                 128U


/*** RFD7 - RFD Register 7; 0x00000043 ***/
typedef union {
  byte Byte;
  struct {
    byte RFD56       :1;                                       /* RFD, bit 56 */
    byte RFD57       :1;                                       /* RFD, bit 57 */
    byte RFD58       :1;                                       /* RFD, bit 58 */
    byte RFD59       :1;                                       /* RFD, bit 59 */
    byte RFD60       :1;                                       /* RFD, bit 60 */
    byte RFD61       :1;                                       /* RFD, bit 61 */
    byte RFD62       :1;                                       /* RFD, bit 62 */
    byte RFD63       :1;                                       /* RFD, bit 63 */
  } Bits;
} RFD7STR;
extern volatile RFD7STR _RFD7 @0x00000043;
#define RFD7                            _RFD7.Byte
#define RFD7_RFD56                      _RFD7.Bits.RFD56
#define RFD7_RFD57                      _RFD7.Bits.RFD57
#define RFD7_RFD58                      _RFD7.Bits.RFD58
#define RFD7_RFD59                      _RFD7.Bits.RFD59
#define RFD7_RFD60                      _RFD7.Bits.RFD60
#define RFD7_RFD61                      _RFD7.Bits.RFD61
#define RFD7_RFD62                      _RFD7.Bits.RFD62
#define RFD7_RFD63                      _RFD7.Bits.RFD63

#define RFD7_RFD56_MASK                 1U
#define RFD7_RFD57_MASK                 2U
#define RFD7_RFD58_MASK                 4U
#define RFD7_RFD59_MASK                 8U
#define RFD7_RFD60_MASK                 16U
#define RFD7_RFD61_MASK                 32U
#define RFD7_RFD62_MASK                 64U
#define RFD7_RFD63_MASK                 128U


/*** RFD8 - RFD Register 8; 0x00000044 ***/
typedef union {
  byte Byte;
  struct {
    byte RFD64       :1;                                       /* RFD, bit 64 */
    byte RFD65       :1;                                       /* RFD, bit 65 */
    byte RFD66       :1;                                       /* RFD, bit 66 */
    byte RFD67       :1;                                       /* RFD, bit 67 */
    byte RFD68       :1;                                       /* RFD, bit 68 */
    byte RFD69       :1;                                       /* RFD, bit 69 */
    byte RFD70       :1;                                       /* RFD, bit 70 */
    byte RFD71       :1;                                       /* RFD, bit 71 */
  } Bits;
} RFD8STR;
extern volatile RFD8STR _RFD8 @0x00000044;
#define RFD8                            _RFD8.Byte
#define RFD8_RFD64                      _RFD8.Bits.RFD64
#define RFD8_RFD65                      _RFD8.Bits.RFD65
#define RFD8_RFD66                      _RFD8.Bits.RFD66
#define RFD8_RFD67                      _RFD8.Bits.RFD67
#define RFD8_RFD68                      _RFD8.Bits.RFD68
#define RFD8_RFD69                      _RFD8.Bits.RFD69
#define RFD8_RFD70                      _RFD8.Bits.RFD70
#define RFD8_RFD71                      _RFD8.Bits.RFD71

#define RFD8_RFD64_MASK                 1U
#define RFD8_RFD65_MASK                 2U
#define RFD8_RFD66_MASK                 4U
#define RFD8_RFD67_MASK                 8U
#define RFD8_RFD68_MASK                 16U
#define RFD8_RFD69_MASK                 32U
#define RFD8_RFD70_MASK                 64U
#define RFD8_RFD71_MASK                 128U


/*** RFD9 - RFD Register 9; 0x00000045 ***/
typedef union {
  byte Byte;
  struct {
    byte RFD72       :1;                                       /* RFD, bit 72 */
    byte RFD73       :1;                                       /* RFD, bit 73 */
    byte RFD74       :1;                                       /* RFD, bit 74 */
    byte RFD75       :1;                                       /* RFD, bit 75 */
    byte RFD76       :1;                                       /* RFD, bit 76 */
    byte RFD77       :1;                                       /* RFD, bit 77 */
    byte RFD78       :1;                                       /* RFD, bit 78 */
    byte RFD79       :1;                                       /* RFD, bit 79 */
  } Bits;
} RFD9STR;
extern volatile RFD9STR _RFD9 @0x00000045;
#define RFD9                            _RFD9.Byte
#define RFD9_RFD72                      _RFD9.Bits.RFD72
#define RFD9_RFD73                      _RFD9.Bits.RFD73
#define RFD9_RFD74                      _RFD9.Bits.RFD74
#define RFD9_RFD75                      _RFD9.Bits.RFD75
#define RFD9_RFD76                      _RFD9.Bits.RFD76
#define RFD9_RFD77                      _RFD9.Bits.RFD77
#define RFD9_RFD78                      _RFD9.Bits.RFD78
#define RFD9_RFD79                      _RFD9.Bits.RFD79

#define RFD9_RFD72_MASK                 1U
#define RFD9_RFD73_MASK                 2U
#define RFD9_RFD74_MASK                 4U
#define RFD9_RFD75_MASK                 8U
#define RFD9_RFD76_MASK                 16U
#define RFD9_RFD77_MASK                 32U
#define RFD9_RFD78_MASK                 64U
#define RFD9_RFD79_MASK                 128U


/*** RFD10 - RFD Register 10; 0x00000046 ***/
typedef union {
  byte Byte;
  struct {
    byte RFD80       :1;                                       /* RFD, bit 80 */
    byte RFD81       :1;                                       /* RFD, bit 81 */
    byte RFD82       :1;                                       /* RFD, bit 82 */
    byte RFD83       :1;                                       /* RFD, bit 83 */
    byte RFD84       :1;                                       /* RFD, bit 84 */
    byte RFD85       :1;                                       /* RFD, bit 85 */
    byte RFD86       :1;                                       /* RFD, bit 86 */
    byte RFD87       :1;                                       /* RFD, bit 87 */
  } Bits;
} RFD10STR;
extern volatile RFD10STR _RFD10 @0x00000046;
#define RFD10                           _RFD10.Byte
#define RFD10_RFD80                     _RFD10.Bits.RFD80
#define RFD10_RFD81                     _RFD10.Bits.RFD81
#define RFD10_RFD82                     _RFD10.Bits.RFD82
#define RFD10_RFD83                     _RFD10.Bits.RFD83
#define RFD10_RFD84                     _RFD10.Bits.RFD84
#define RFD10_RFD85                     _RFD10.Bits.RFD85
#define RFD10_RFD86                     _RFD10.Bits.RFD86
#define RFD10_RFD87                     _RFD10.Bits.RFD87

#define RFD10_RFD80_MASK                1U
#define RFD10_RFD81_MASK                2U
#define RFD10_RFD82_MASK                4U
#define RFD10_RFD83_MASK                8U
#define RFD10_RFD84_MASK                16U
#define RFD10_RFD85_MASK                32U
#define RFD10_RFD86_MASK                64U
#define RFD10_RFD87_MASK                128U


/*** RFD11 - RFD Register 11; 0x00000047 ***/
typedef union {
  byte Byte;
  struct {
    byte RFD88       :1;                                       /* RFD, bit 88 */
    byte RFD89       :1;                                       /* RFD, bit 89 */
    byte RFD90       :1;                                       /* RFD, bit 90 */
    byte RFD91       :1;                                       /* RFD, bit 91 */
    byte RFD92       :1;                                       /* RFD, bit 92 */
    byte RFD93       :1;                                       /* RFD, bit 93 */
    byte RFD94       :1;                                       /* RFD, bit 94 */
    byte RFD95       :1;                                       /* RFD, bit 95 */
  } Bits;
} RFD11STR;
extern volatile RFD11STR _RFD11 @0x00000047;
#define RFD11                           _RFD11.Byte
#define RFD11_RFD88                     _RFD11.Bits.RFD88
#define RFD11_RFD89                     _RFD11.Bits.RFD89
#define RFD11_RFD90                     _RFD11.Bits.RFD90
#define RFD11_RFD91                     _RFD11.Bits.RFD91
#define RFD11_RFD92                     _RFD11.Bits.RFD92
#define RFD11_RFD93                     _RFD11.Bits.RFD93
#define RFD11_RFD94                     _RFD11.Bits.RFD94
#define RFD11_RFD95                     _RFD11.Bits.RFD95

#define RFD11_RFD88_MASK                1U
#define RFD11_RFD89_MASK                2U
#define RFD11_RFD90_MASK                4U
#define RFD11_RFD91_MASK                8U
#define RFD11_RFD92_MASK                16U
#define RFD11_RFD93_MASK                32U
#define RFD11_RFD94_MASK                64U
#define RFD11_RFD95_MASK                128U


/*** RFD12 - RFD Register 12; 0x00000048 ***/
typedef union {
  byte Byte;
  struct {
    byte RFD96       :1;                                       /* RFD, bit 96 */
    byte RFD97       :1;                                       /* RFD, bit 97 */
    byte RFD98       :1;                                       /* RFD, bit 98 */
    byte RFD99       :1;                                       /* RFD, bit 99 */
    byte RFD100      :1;                                       /* RFD, bit 100 */
    byte RFD101      :1;                                       /* RFD, bit 101 */
    byte RFD102      :1;                                       /* RFD, bit 102 */
    byte RFD103      :1;                                       /* RFD, bit 103 */
  } Bits;
} RFD12STR;
extern volatile RFD12STR _RFD12 @0x00000048;
#define RFD12                           _RFD12.Byte
#define RFD12_RFD96                     _RFD12.Bits.RFD96
#define RFD12_RFD97                     _RFD12.Bits.RFD97
#define RFD12_RFD98                     _RFD12.Bits.RFD98
#define RFD12_RFD99                     _RFD12.Bits.RFD99
#define RFD12_RFD100                    _RFD12.Bits.RFD100
#define RFD12_RFD101                    _RFD12.Bits.RFD101
#define RFD12_RFD102                    _RFD12.Bits.RFD102
#define RFD12_RFD103                    _RFD12.Bits.RFD103

#define RFD12_RFD96_MASK                1U
#define RFD12_RFD97_MASK                2U
#define RFD12_RFD98_MASK                4U
#define RFD12_RFD99_MASK                8U
#define RFD12_RFD100_MASK               16U
#define RFD12_RFD101_MASK               32U
#define RFD12_RFD102_MASK               64U
#define RFD12_RFD103_MASK               128U


/*** RFD13 - RFD Register 13; 0x00000049 ***/
typedef union {
  byte Byte;
  struct {
    byte RFD104      :1;                                       /* RFD, bit 104 */
    byte RFD105      :1;                                       /* RFD, bit 105 */
    byte RFD106      :1;                                       /* RFD, bit 106 */
    byte RFD107      :1;                                       /* RFD, bit 107 */
    byte RFD108      :1;                                       /* RFD, bit 108 */
    byte RFD109      :1;                                       /* RFD, bit 109 */
    byte RFD110      :1;                                       /* RFD, bit 110 */
    byte RFD111      :1;                                       /* RFD, bit 111 */
  } Bits;
  struct {
    byte grpRFD10_4 :6;
    byte grpRFD1_10 :2;
  } MergedBits;
} RFD13STR;
extern volatile RFD13STR _RFD13 @0x00000049;
#define RFD13                           _RFD13.Byte
#define RFD13_RFD104                    _RFD13.Bits.RFD104
#define RFD13_RFD105                    _RFD13.Bits.RFD105
#define RFD13_RFD106                    _RFD13.Bits.RFD106
#define RFD13_RFD107                    _RFD13.Bits.RFD107
#define RFD13_RFD108                    _RFD13.Bits.RFD108
#define RFD13_RFD109                    _RFD13.Bits.RFD109
#define RFD13_RFD110                    _RFD13.Bits.RFD110
#define RFD13_RFD111                    _RFD13.Bits.RFD111
#define RFD13_RFD10_4                   _RFD13.MergedBits.grpRFD10_4
#define RFD13_RFD1_10                   _RFD13.MergedBits.grpRFD1_10
#define RFD13_RFD10                     RFD13_RFD10_4
#define RFD13_RFD1                      RFD13_RFD1_10

#define RFD13_RFD104_MASK               1U
#define RFD13_RFD105_MASK               2U
#define RFD13_RFD106_MASK               4U
#define RFD13_RFD107_MASK               8U
#define RFD13_RFD108_MASK               16U
#define RFD13_RFD109_MASK               32U
#define RFD13_RFD110_MASK               64U
#define RFD13_RFD111_MASK               128U
#define RFD13_RFD10_4_MASK              63U
#define RFD13_RFD10_4_BITNUM            0U
#define RFD13_RFD1_10_MASK              192U
#define RFD13_RFD1_10_BITNUM            6U


/*** RFD14 - RFD Register 14; 0x0000004A ***/
typedef union {
  byte Byte;
  struct {
    byte RFD112      :1;                                       /* RFD, bit 112 */
    byte RFD113      :1;                                       /* RFD, bit 113 */
    byte RFD114      :1;                                       /* RFD, bit 114 */
    byte RFD115      :1;                                       /* RFD, bit 115 */
    byte RFD116      :1;                                       /* RFD, bit 116 */
    byte RFD117      :1;                                       /* RFD, bit 117 */
    byte RFD118      :1;                                       /* RFD, bit 118 */
    byte RFD119      :1;                                       /* RFD, bit 119 */
  } Bits;
} RFD14STR;
extern volatile RFD14STR _RFD14 @0x0000004A;
#define RFD14                           _RFD14.Byte
#define RFD14_RFD112                    _RFD14.Bits.RFD112
#define RFD14_RFD113                    _RFD14.Bits.RFD113
#define RFD14_RFD114                    _RFD14.Bits.RFD114
#define RFD14_RFD115                    _RFD14.Bits.RFD115
#define RFD14_RFD116                    _RFD14.Bits.RFD116
#define RFD14_RFD117                    _RFD14.Bits.RFD117
#define RFD14_RFD118                    _RFD14.Bits.RFD118
#define RFD14_RFD119                    _RFD14.Bits.RFD119

#define RFD14_RFD112_MASK               1U
#define RFD14_RFD113_MASK               2U
#define RFD14_RFD114_MASK               4U
#define RFD14_RFD115_MASK               8U
#define RFD14_RFD116_MASK               16U
#define RFD14_RFD117_MASK               32U
#define RFD14_RFD118_MASK               64U
#define RFD14_RFD119_MASK               128U


/*** RFD15 - RFD Register 15; 0x0000004B ***/
typedef union {
  byte Byte;
  struct {
    byte RFD120      :1;                                       /* RFD, bit 120 */
    byte RFD121      :1;                                       /* RFD, bit 121 */
    byte RFD122      :1;                                       /* RFD, bit 122 */
    byte RFD123      :1;                                       /* RFD, bit 123 */
    byte RFD124      :1;                                       /* RFD, bit 124 */
    byte RFD125      :1;                                       /* RFD, bit 125 */
    byte RFD126      :1;                                       /* RFD, bit 126 */
    byte RFD127      :1;                                       /* RFD, bit 127 */
  } Bits;
} RFD15STR;
extern volatile RFD15STR _RFD15 @0x0000004B;
#define RFD15                           _RFD15.Byte
#define RFD15_RFD120                    _RFD15.Bits.RFD120
#define RFD15_RFD121                    _RFD15.Bits.RFD121
#define RFD15_RFD122                    _RFD15.Bits.RFD122
#define RFD15_RFD123                    _RFD15.Bits.RFD123
#define RFD15_RFD124                    _RFD15.Bits.RFD124
#define RFD15_RFD125                    _RFD15.Bits.RFD125
#define RFD15_RFD126                    _RFD15.Bits.RFD126
#define RFD15_RFD127                    _RFD15.Bits.RFD127

#define RFD15_RFD120_MASK               1U
#define RFD15_RFD121_MASK               2U
#define RFD15_RFD122_MASK               4U
#define RFD15_RFD123_MASK               8U
#define RFD15_RFD124_MASK               16U
#define RFD15_RFD125_MASK               32U
#define RFD15_RFD126_MASK               64U
#define RFD15_RFD127_MASK               128U


/*** PARAM0 - Parameter Register 0; 0x00000050 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM0STR;
extern volatile PARAM0STR _PARAM0 @0x00000050;
#define PARAM0                          _PARAM0.Byte
#define PARAM0_BIT0                     _PARAM0.Bits.BIT0
#define PARAM0_BIT1                     _PARAM0.Bits.BIT1
#define PARAM0_BIT2                     _PARAM0.Bits.BIT2
#define PARAM0_BIT3                     _PARAM0.Bits.BIT3
#define PARAM0_BIT4                     _PARAM0.Bits.BIT4
#define PARAM0_BIT5                     _PARAM0.Bits.BIT5
#define PARAM0_BIT6                     _PARAM0.Bits.BIT6
#define PARAM0_BIT7                     _PARAM0.Bits.BIT7
/* PARAM_ARR: Access 64 PARAMx registers in an array */
#define PARAM_ARR                       ((volatile byte * __far) &PARAM0)

#define PARAM0_BIT0_MASK                1U
#define PARAM0_BIT1_MASK                2U
#define PARAM0_BIT2_MASK                4U
#define PARAM0_BIT3_MASK                8U
#define PARAM0_BIT4_MASK                16U
#define PARAM0_BIT5_MASK                32U
#define PARAM0_BIT6_MASK                64U
#define PARAM0_BIT7_MASK                128U


/*** PARAM1 - Parameter Register 1; 0x00000051 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM1STR;
extern volatile PARAM1STR _PARAM1 @0x00000051;
#define PARAM1                          _PARAM1.Byte
#define PARAM1_BIT0                     _PARAM1.Bits.BIT0
#define PARAM1_BIT1                     _PARAM1.Bits.BIT1
#define PARAM1_BIT2                     _PARAM1.Bits.BIT2
#define PARAM1_BIT3                     _PARAM1.Bits.BIT3
#define PARAM1_BIT4                     _PARAM1.Bits.BIT4
#define PARAM1_BIT5                     _PARAM1.Bits.BIT5
#define PARAM1_BIT6                     _PARAM1.Bits.BIT6
#define PARAM1_BIT7                     _PARAM1.Bits.BIT7

#define PARAM1_BIT0_MASK                1U
#define PARAM1_BIT1_MASK                2U
#define PARAM1_BIT2_MASK                4U
#define PARAM1_BIT3_MASK                8U
#define PARAM1_BIT4_MASK                16U
#define PARAM1_BIT5_MASK                32U
#define PARAM1_BIT6_MASK                64U
#define PARAM1_BIT7_MASK                128U


/*** PARAM2 - Parameter Register 2; 0x00000052 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM2STR;
extern volatile PARAM2STR _PARAM2 @0x00000052;
#define PARAM2                          _PARAM2.Byte
#define PARAM2_BIT0                     _PARAM2.Bits.BIT0
#define PARAM2_BIT1                     _PARAM2.Bits.BIT1
#define PARAM2_BIT2                     _PARAM2.Bits.BIT2
#define PARAM2_BIT3                     _PARAM2.Bits.BIT3
#define PARAM2_BIT4                     _PARAM2.Bits.BIT4
#define PARAM2_BIT5                     _PARAM2.Bits.BIT5
#define PARAM2_BIT6                     _PARAM2.Bits.BIT6
#define PARAM2_BIT7                     _PARAM2.Bits.BIT7

#define PARAM2_BIT0_MASK                1U
#define PARAM2_BIT1_MASK                2U
#define PARAM2_BIT2_MASK                4U
#define PARAM2_BIT3_MASK                8U
#define PARAM2_BIT4_MASK                16U
#define PARAM2_BIT5_MASK                32U
#define PARAM2_BIT6_MASK                64U
#define PARAM2_BIT7_MASK                128U


/*** PARAM3 - Parameter Register 3; 0x00000053 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM3STR;
extern volatile PARAM3STR _PARAM3 @0x00000053;
#define PARAM3                          _PARAM3.Byte
#define PARAM3_BIT0                     _PARAM3.Bits.BIT0
#define PARAM3_BIT1                     _PARAM3.Bits.BIT1
#define PARAM3_BIT2                     _PARAM3.Bits.BIT2
#define PARAM3_BIT3                     _PARAM3.Bits.BIT3
#define PARAM3_BIT4                     _PARAM3.Bits.BIT4
#define PARAM3_BIT5                     _PARAM3.Bits.BIT5
#define PARAM3_BIT6                     _PARAM3.Bits.BIT6
#define PARAM3_BIT7                     _PARAM3.Bits.BIT7

#define PARAM3_BIT0_MASK                1U
#define PARAM3_BIT1_MASK                2U
#define PARAM3_BIT2_MASK                4U
#define PARAM3_BIT3_MASK                8U
#define PARAM3_BIT4_MASK                16U
#define PARAM3_BIT5_MASK                32U
#define PARAM3_BIT6_MASK                64U
#define PARAM3_BIT7_MASK                128U


/*** PARAM4 - Parameter Register 4; 0x00000054 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM4STR;
extern volatile PARAM4STR _PARAM4 @0x00000054;
#define PARAM4                          _PARAM4.Byte
#define PARAM4_BIT0                     _PARAM4.Bits.BIT0
#define PARAM4_BIT1                     _PARAM4.Bits.BIT1
#define PARAM4_BIT2                     _PARAM4.Bits.BIT2
#define PARAM4_BIT3                     _PARAM4.Bits.BIT3
#define PARAM4_BIT4                     _PARAM4.Bits.BIT4
#define PARAM4_BIT5                     _PARAM4.Bits.BIT5
#define PARAM4_BIT6                     _PARAM4.Bits.BIT6
#define PARAM4_BIT7                     _PARAM4.Bits.BIT7

#define PARAM4_BIT0_MASK                1U
#define PARAM4_BIT1_MASK                2U
#define PARAM4_BIT2_MASK                4U
#define PARAM4_BIT3_MASK                8U
#define PARAM4_BIT4_MASK                16U
#define PARAM4_BIT5_MASK                32U
#define PARAM4_BIT6_MASK                64U
#define PARAM4_BIT7_MASK                128U


/*** PARAM5 - Parameter Register 5; 0x00000055 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM5STR;
extern volatile PARAM5STR _PARAM5 @0x00000055;
#define PARAM5                          _PARAM5.Byte
#define PARAM5_BIT0                     _PARAM5.Bits.BIT0
#define PARAM5_BIT1                     _PARAM5.Bits.BIT1
#define PARAM5_BIT2                     _PARAM5.Bits.BIT2
#define PARAM5_BIT3                     _PARAM5.Bits.BIT3
#define PARAM5_BIT4                     _PARAM5.Bits.BIT4
#define PARAM5_BIT5                     _PARAM5.Bits.BIT5
#define PARAM5_BIT6                     _PARAM5.Bits.BIT6
#define PARAM5_BIT7                     _PARAM5.Bits.BIT7

#define PARAM5_BIT0_MASK                1U
#define PARAM5_BIT1_MASK                2U
#define PARAM5_BIT2_MASK                4U
#define PARAM5_BIT3_MASK                8U
#define PARAM5_BIT4_MASK                16U
#define PARAM5_BIT5_MASK                32U
#define PARAM5_BIT6_MASK                64U
#define PARAM5_BIT7_MASK                128U


/*** PARAM6 - Parameter Register 6; 0x00000056 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM6STR;
extern volatile PARAM6STR _PARAM6 @0x00000056;
#define PARAM6                          _PARAM6.Byte
#define PARAM6_BIT0                     _PARAM6.Bits.BIT0
#define PARAM6_BIT1                     _PARAM6.Bits.BIT1
#define PARAM6_BIT2                     _PARAM6.Bits.BIT2
#define PARAM6_BIT3                     _PARAM6.Bits.BIT3
#define PARAM6_BIT4                     _PARAM6.Bits.BIT4
#define PARAM6_BIT5                     _PARAM6.Bits.BIT5
#define PARAM6_BIT6                     _PARAM6.Bits.BIT6
#define PARAM6_BIT7                     _PARAM6.Bits.BIT7

#define PARAM6_BIT0_MASK                1U
#define PARAM6_BIT1_MASK                2U
#define PARAM6_BIT2_MASK                4U
#define PARAM6_BIT3_MASK                8U
#define PARAM6_BIT4_MASK                16U
#define PARAM6_BIT5_MASK                32U
#define PARAM6_BIT6_MASK                64U
#define PARAM6_BIT7_MASK                128U


/*** PARAM7 - Parameter Register 7; 0x00000057 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM7STR;
extern volatile PARAM7STR _PARAM7 @0x00000057;
#define PARAM7                          _PARAM7.Byte
#define PARAM7_BIT0                     _PARAM7.Bits.BIT0
#define PARAM7_BIT1                     _PARAM7.Bits.BIT1
#define PARAM7_BIT2                     _PARAM7.Bits.BIT2
#define PARAM7_BIT3                     _PARAM7.Bits.BIT3
#define PARAM7_BIT4                     _PARAM7.Bits.BIT4
#define PARAM7_BIT5                     _PARAM7.Bits.BIT5
#define PARAM7_BIT6                     _PARAM7.Bits.BIT6
#define PARAM7_BIT7                     _PARAM7.Bits.BIT7

#define PARAM7_BIT0_MASK                1U
#define PARAM7_BIT1_MASK                2U
#define PARAM7_BIT2_MASK                4U
#define PARAM7_BIT3_MASK                8U
#define PARAM7_BIT4_MASK                16U
#define PARAM7_BIT5_MASK                32U
#define PARAM7_BIT6_MASK                64U
#define PARAM7_BIT7_MASK                128U


/*** PARAM8 - Parameter Register 8; 0x00000058 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM8STR;
extern volatile PARAM8STR _PARAM8 @0x00000058;
#define PARAM8                          _PARAM8.Byte
#define PARAM8_BIT0                     _PARAM8.Bits.BIT0
#define PARAM8_BIT1                     _PARAM8.Bits.BIT1
#define PARAM8_BIT2                     _PARAM8.Bits.BIT2
#define PARAM8_BIT3                     _PARAM8.Bits.BIT3
#define PARAM8_BIT4                     _PARAM8.Bits.BIT4
#define PARAM8_BIT5                     _PARAM8.Bits.BIT5
#define PARAM8_BIT6                     _PARAM8.Bits.BIT6
#define PARAM8_BIT7                     _PARAM8.Bits.BIT7

#define PARAM8_BIT0_MASK                1U
#define PARAM8_BIT1_MASK                2U
#define PARAM8_BIT2_MASK                4U
#define PARAM8_BIT3_MASK                8U
#define PARAM8_BIT4_MASK                16U
#define PARAM8_BIT5_MASK                32U
#define PARAM8_BIT6_MASK                64U
#define PARAM8_BIT7_MASK                128U


/*** PARAM9 - Parameter Register 9; 0x00000059 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM9STR;
extern volatile PARAM9STR _PARAM9 @0x00000059;
#define PARAM9                          _PARAM9.Byte
#define PARAM9_BIT0                     _PARAM9.Bits.BIT0
#define PARAM9_BIT1                     _PARAM9.Bits.BIT1
#define PARAM9_BIT2                     _PARAM9.Bits.BIT2
#define PARAM9_BIT3                     _PARAM9.Bits.BIT3
#define PARAM9_BIT4                     _PARAM9.Bits.BIT4
#define PARAM9_BIT5                     _PARAM9.Bits.BIT5
#define PARAM9_BIT6                     _PARAM9.Bits.BIT6
#define PARAM9_BIT7                     _PARAM9.Bits.BIT7

#define PARAM9_BIT0_MASK                1U
#define PARAM9_BIT1_MASK                2U
#define PARAM9_BIT2_MASK                4U
#define PARAM9_BIT3_MASK                8U
#define PARAM9_BIT4_MASK                16U
#define PARAM9_BIT5_MASK                32U
#define PARAM9_BIT6_MASK                64U
#define PARAM9_BIT7_MASK                128U


/*** PARAM10 - Parameter Register 10; 0x0000005A ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM10STR;
extern volatile PARAM10STR _PARAM10 @0x0000005A;
#define PARAM10                         _PARAM10.Byte
#define PARAM10_BIT0                    _PARAM10.Bits.BIT0
#define PARAM10_BIT1                    _PARAM10.Bits.BIT1
#define PARAM10_BIT2                    _PARAM10.Bits.BIT2
#define PARAM10_BIT3                    _PARAM10.Bits.BIT3
#define PARAM10_BIT4                    _PARAM10.Bits.BIT4
#define PARAM10_BIT5                    _PARAM10.Bits.BIT5
#define PARAM10_BIT6                    _PARAM10.Bits.BIT6
#define PARAM10_BIT7                    _PARAM10.Bits.BIT7

#define PARAM10_BIT0_MASK               1U
#define PARAM10_BIT1_MASK               2U
#define PARAM10_BIT2_MASK               4U
#define PARAM10_BIT3_MASK               8U
#define PARAM10_BIT4_MASK               16U
#define PARAM10_BIT5_MASK               32U
#define PARAM10_BIT6_MASK               64U
#define PARAM10_BIT7_MASK               128U


/*** PARAM11 - Parameter Register 11; 0x0000005B ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM11STR;
extern volatile PARAM11STR _PARAM11 @0x0000005B;
#define PARAM11                         _PARAM11.Byte
#define PARAM11_BIT0                    _PARAM11.Bits.BIT0
#define PARAM11_BIT1                    _PARAM11.Bits.BIT1
#define PARAM11_BIT2                    _PARAM11.Bits.BIT2
#define PARAM11_BIT3                    _PARAM11.Bits.BIT3
#define PARAM11_BIT4                    _PARAM11.Bits.BIT4
#define PARAM11_BIT5                    _PARAM11.Bits.BIT5
#define PARAM11_BIT6                    _PARAM11.Bits.BIT6
#define PARAM11_BIT7                    _PARAM11.Bits.BIT7

#define PARAM11_BIT0_MASK               1U
#define PARAM11_BIT1_MASK               2U
#define PARAM11_BIT2_MASK               4U
#define PARAM11_BIT3_MASK               8U
#define PARAM11_BIT4_MASK               16U
#define PARAM11_BIT5_MASK               32U
#define PARAM11_BIT6_MASK               64U
#define PARAM11_BIT7_MASK               128U


/*** PARAM12 - Parameter Register 12; 0x0000005C ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM12STR;
extern volatile PARAM12STR _PARAM12 @0x0000005C;
#define PARAM12                         _PARAM12.Byte
#define PARAM12_BIT0                    _PARAM12.Bits.BIT0
#define PARAM12_BIT1                    _PARAM12.Bits.BIT1
#define PARAM12_BIT2                    _PARAM12.Bits.BIT2
#define PARAM12_BIT3                    _PARAM12.Bits.BIT3
#define PARAM12_BIT4                    _PARAM12.Bits.BIT4
#define PARAM12_BIT5                    _PARAM12.Bits.BIT5
#define PARAM12_BIT6                    _PARAM12.Bits.BIT6
#define PARAM12_BIT7                    _PARAM12.Bits.BIT7

#define PARAM12_BIT0_MASK               1U
#define PARAM12_BIT1_MASK               2U
#define PARAM12_BIT2_MASK               4U
#define PARAM12_BIT3_MASK               8U
#define PARAM12_BIT4_MASK               16U
#define PARAM12_BIT5_MASK               32U
#define PARAM12_BIT6_MASK               64U
#define PARAM12_BIT7_MASK               128U


/*** PARAM13 - Parameter Register 13; 0x0000005D ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM13STR;
extern volatile PARAM13STR _PARAM13 @0x0000005D;
#define PARAM13                         _PARAM13.Byte
#define PARAM13_BIT0                    _PARAM13.Bits.BIT0
#define PARAM13_BIT1                    _PARAM13.Bits.BIT1
#define PARAM13_BIT2                    _PARAM13.Bits.BIT2
#define PARAM13_BIT3                    _PARAM13.Bits.BIT3
#define PARAM13_BIT4                    _PARAM13.Bits.BIT4
#define PARAM13_BIT5                    _PARAM13.Bits.BIT5
#define PARAM13_BIT6                    _PARAM13.Bits.BIT6
#define PARAM13_BIT7                    _PARAM13.Bits.BIT7

#define PARAM13_BIT0_MASK               1U
#define PARAM13_BIT1_MASK               2U
#define PARAM13_BIT2_MASK               4U
#define PARAM13_BIT3_MASK               8U
#define PARAM13_BIT4_MASK               16U
#define PARAM13_BIT5_MASK               32U
#define PARAM13_BIT6_MASK               64U
#define PARAM13_BIT7_MASK               128U


/*** PARAM14 - Parameter Register 14; 0x0000005E ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM14STR;
extern volatile PARAM14STR _PARAM14 @0x0000005E;
#define PARAM14                         _PARAM14.Byte
#define PARAM14_BIT0                    _PARAM14.Bits.BIT0
#define PARAM14_BIT1                    _PARAM14.Bits.BIT1
#define PARAM14_BIT2                    _PARAM14.Bits.BIT2
#define PARAM14_BIT3                    _PARAM14.Bits.BIT3
#define PARAM14_BIT4                    _PARAM14.Bits.BIT4
#define PARAM14_BIT5                    _PARAM14.Bits.BIT5
#define PARAM14_BIT6                    _PARAM14.Bits.BIT6
#define PARAM14_BIT7                    _PARAM14.Bits.BIT7

#define PARAM14_BIT0_MASK               1U
#define PARAM14_BIT1_MASK               2U
#define PARAM14_BIT2_MASK               4U
#define PARAM14_BIT3_MASK               8U
#define PARAM14_BIT4_MASK               16U
#define PARAM14_BIT5_MASK               32U
#define PARAM14_BIT6_MASK               64U
#define PARAM14_BIT7_MASK               128U


/*** PARAM15 - Parameter Register 15; 0x0000005F ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM15STR;
extern volatile PARAM15STR _PARAM15 @0x0000005F;
#define PARAM15                         _PARAM15.Byte
#define PARAM15_BIT0                    _PARAM15.Bits.BIT0
#define PARAM15_BIT1                    _PARAM15.Bits.BIT1
#define PARAM15_BIT2                    _PARAM15.Bits.BIT2
#define PARAM15_BIT3                    _PARAM15.Bits.BIT3
#define PARAM15_BIT4                    _PARAM15.Bits.BIT4
#define PARAM15_BIT5                    _PARAM15.Bits.BIT5
#define PARAM15_BIT6                    _PARAM15.Bits.BIT6
#define PARAM15_BIT7                    _PARAM15.Bits.BIT7

#define PARAM15_BIT0_MASK               1U
#define PARAM15_BIT1_MASK               2U
#define PARAM15_BIT2_MASK               4U
#define PARAM15_BIT3_MASK               8U
#define PARAM15_BIT4_MASK               16U
#define PARAM15_BIT5_MASK               32U
#define PARAM15_BIT6_MASK               64U
#define PARAM15_BIT7_MASK               128U


/*** PARAM16 - Parameter Register 16; 0x00000060 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM16STR;
extern volatile PARAM16STR _PARAM16 @0x00000060;
#define PARAM16                         _PARAM16.Byte
#define PARAM16_BIT0                    _PARAM16.Bits.BIT0
#define PARAM16_BIT1                    _PARAM16.Bits.BIT1
#define PARAM16_BIT2                    _PARAM16.Bits.BIT2
#define PARAM16_BIT3                    _PARAM16.Bits.BIT3
#define PARAM16_BIT4                    _PARAM16.Bits.BIT4
#define PARAM16_BIT5                    _PARAM16.Bits.BIT5
#define PARAM16_BIT6                    _PARAM16.Bits.BIT6
#define PARAM16_BIT7                    _PARAM16.Bits.BIT7

#define PARAM16_BIT0_MASK               1U
#define PARAM16_BIT1_MASK               2U
#define PARAM16_BIT2_MASK               4U
#define PARAM16_BIT3_MASK               8U
#define PARAM16_BIT4_MASK               16U
#define PARAM16_BIT5_MASK               32U
#define PARAM16_BIT6_MASK               64U
#define PARAM16_BIT7_MASK               128U


/*** PARAM17 - Parameter Register 17; 0x00000061 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM17STR;
extern volatile PARAM17STR _PARAM17 @0x00000061;
#define PARAM17                         _PARAM17.Byte
#define PARAM17_BIT0                    _PARAM17.Bits.BIT0
#define PARAM17_BIT1                    _PARAM17.Bits.BIT1
#define PARAM17_BIT2                    _PARAM17.Bits.BIT2
#define PARAM17_BIT3                    _PARAM17.Bits.BIT3
#define PARAM17_BIT4                    _PARAM17.Bits.BIT4
#define PARAM17_BIT5                    _PARAM17.Bits.BIT5
#define PARAM17_BIT6                    _PARAM17.Bits.BIT6
#define PARAM17_BIT7                    _PARAM17.Bits.BIT7

#define PARAM17_BIT0_MASK               1U
#define PARAM17_BIT1_MASK               2U
#define PARAM17_BIT2_MASK               4U
#define PARAM17_BIT3_MASK               8U
#define PARAM17_BIT4_MASK               16U
#define PARAM17_BIT5_MASK               32U
#define PARAM17_BIT6_MASK               64U
#define PARAM17_BIT7_MASK               128U


/*** PARAM18 - Parameter Register 18; 0x00000062 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM18STR;
extern volatile PARAM18STR _PARAM18 @0x00000062;
#define PARAM18                         _PARAM18.Byte
#define PARAM18_BIT0                    _PARAM18.Bits.BIT0
#define PARAM18_BIT1                    _PARAM18.Bits.BIT1
#define PARAM18_BIT2                    _PARAM18.Bits.BIT2
#define PARAM18_BIT3                    _PARAM18.Bits.BIT3
#define PARAM18_BIT4                    _PARAM18.Bits.BIT4
#define PARAM18_BIT5                    _PARAM18.Bits.BIT5
#define PARAM18_BIT6                    _PARAM18.Bits.BIT6
#define PARAM18_BIT7                    _PARAM18.Bits.BIT7

#define PARAM18_BIT0_MASK               1U
#define PARAM18_BIT1_MASK               2U
#define PARAM18_BIT2_MASK               4U
#define PARAM18_BIT3_MASK               8U
#define PARAM18_BIT4_MASK               16U
#define PARAM18_BIT5_MASK               32U
#define PARAM18_BIT6_MASK               64U
#define PARAM18_BIT7_MASK               128U


/*** PARAM19 - Parameter Register 19; 0x00000063 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM19STR;
extern volatile PARAM19STR _PARAM19 @0x00000063;
#define PARAM19                         _PARAM19.Byte
#define PARAM19_BIT0                    _PARAM19.Bits.BIT0
#define PARAM19_BIT1                    _PARAM19.Bits.BIT1
#define PARAM19_BIT2                    _PARAM19.Bits.BIT2
#define PARAM19_BIT3                    _PARAM19.Bits.BIT3
#define PARAM19_BIT4                    _PARAM19.Bits.BIT4
#define PARAM19_BIT5                    _PARAM19.Bits.BIT5
#define PARAM19_BIT6                    _PARAM19.Bits.BIT6
#define PARAM19_BIT7                    _PARAM19.Bits.BIT7

#define PARAM19_BIT0_MASK               1U
#define PARAM19_BIT1_MASK               2U
#define PARAM19_BIT2_MASK               4U
#define PARAM19_BIT3_MASK               8U
#define PARAM19_BIT4_MASK               16U
#define PARAM19_BIT5_MASK               32U
#define PARAM19_BIT6_MASK               64U
#define PARAM19_BIT7_MASK               128U


/*** PARAM20 - Parameter Register 20; 0x00000064 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM20STR;
extern volatile PARAM20STR _PARAM20 @0x00000064;
#define PARAM20                         _PARAM20.Byte
#define PARAM20_BIT0                    _PARAM20.Bits.BIT0
#define PARAM20_BIT1                    _PARAM20.Bits.BIT1
#define PARAM20_BIT2                    _PARAM20.Bits.BIT2
#define PARAM20_BIT3                    _PARAM20.Bits.BIT3
#define PARAM20_BIT4                    _PARAM20.Bits.BIT4
#define PARAM20_BIT5                    _PARAM20.Bits.BIT5
#define PARAM20_BIT6                    _PARAM20.Bits.BIT6
#define PARAM20_BIT7                    _PARAM20.Bits.BIT7

#define PARAM20_BIT0_MASK               1U
#define PARAM20_BIT1_MASK               2U
#define PARAM20_BIT2_MASK               4U
#define PARAM20_BIT3_MASK               8U
#define PARAM20_BIT4_MASK               16U
#define PARAM20_BIT5_MASK               32U
#define PARAM20_BIT6_MASK               64U
#define PARAM20_BIT7_MASK               128U


/*** PARAM21 - Parameter Register 21; 0x00000065 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM21STR;
extern volatile PARAM21STR _PARAM21 @0x00000065;
#define PARAM21                         _PARAM21.Byte
#define PARAM21_BIT0                    _PARAM21.Bits.BIT0
#define PARAM21_BIT1                    _PARAM21.Bits.BIT1
#define PARAM21_BIT2                    _PARAM21.Bits.BIT2
#define PARAM21_BIT3                    _PARAM21.Bits.BIT3
#define PARAM21_BIT4                    _PARAM21.Bits.BIT4
#define PARAM21_BIT5                    _PARAM21.Bits.BIT5
#define PARAM21_BIT6                    _PARAM21.Bits.BIT6
#define PARAM21_BIT7                    _PARAM21.Bits.BIT7

#define PARAM21_BIT0_MASK               1U
#define PARAM21_BIT1_MASK               2U
#define PARAM21_BIT2_MASK               4U
#define PARAM21_BIT3_MASK               8U
#define PARAM21_BIT4_MASK               16U
#define PARAM21_BIT5_MASK               32U
#define PARAM21_BIT6_MASK               64U
#define PARAM21_BIT7_MASK               128U


/*** PARAM22 - Parameter Register 22; 0x00000066 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM22STR;
extern volatile PARAM22STR _PARAM22 @0x00000066;
#define PARAM22                         _PARAM22.Byte
#define PARAM22_BIT0                    _PARAM22.Bits.BIT0
#define PARAM22_BIT1                    _PARAM22.Bits.BIT1
#define PARAM22_BIT2                    _PARAM22.Bits.BIT2
#define PARAM22_BIT3                    _PARAM22.Bits.BIT3
#define PARAM22_BIT4                    _PARAM22.Bits.BIT4
#define PARAM22_BIT5                    _PARAM22.Bits.BIT5
#define PARAM22_BIT6                    _PARAM22.Bits.BIT6
#define PARAM22_BIT7                    _PARAM22.Bits.BIT7

#define PARAM22_BIT0_MASK               1U
#define PARAM22_BIT1_MASK               2U
#define PARAM22_BIT2_MASK               4U
#define PARAM22_BIT3_MASK               8U
#define PARAM22_BIT4_MASK               16U
#define PARAM22_BIT5_MASK               32U
#define PARAM22_BIT6_MASK               64U
#define PARAM22_BIT7_MASK               128U


/*** PARAM23 - Parameter Register 23; 0x00000067 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM23STR;
extern volatile PARAM23STR _PARAM23 @0x00000067;
#define PARAM23                         _PARAM23.Byte
#define PARAM23_BIT0                    _PARAM23.Bits.BIT0
#define PARAM23_BIT1                    _PARAM23.Bits.BIT1
#define PARAM23_BIT2                    _PARAM23.Bits.BIT2
#define PARAM23_BIT3                    _PARAM23.Bits.BIT3
#define PARAM23_BIT4                    _PARAM23.Bits.BIT4
#define PARAM23_BIT5                    _PARAM23.Bits.BIT5
#define PARAM23_BIT6                    _PARAM23.Bits.BIT6
#define PARAM23_BIT7                    _PARAM23.Bits.BIT7

#define PARAM23_BIT0_MASK               1U
#define PARAM23_BIT1_MASK               2U
#define PARAM23_BIT2_MASK               4U
#define PARAM23_BIT3_MASK               8U
#define PARAM23_BIT4_MASK               16U
#define PARAM23_BIT5_MASK               32U
#define PARAM23_BIT6_MASK               64U
#define PARAM23_BIT7_MASK               128U


/*** PARAM24 - Parameter Register 24; 0x00000068 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM24STR;
extern volatile PARAM24STR _PARAM24 @0x00000068;
#define PARAM24                         _PARAM24.Byte
#define PARAM24_BIT0                    _PARAM24.Bits.BIT0
#define PARAM24_BIT1                    _PARAM24.Bits.BIT1
#define PARAM24_BIT2                    _PARAM24.Bits.BIT2
#define PARAM24_BIT3                    _PARAM24.Bits.BIT3
#define PARAM24_BIT4                    _PARAM24.Bits.BIT4
#define PARAM24_BIT5                    _PARAM24.Bits.BIT5
#define PARAM24_BIT6                    _PARAM24.Bits.BIT6
#define PARAM24_BIT7                    _PARAM24.Bits.BIT7

#define PARAM24_BIT0_MASK               1U
#define PARAM24_BIT1_MASK               2U
#define PARAM24_BIT2_MASK               4U
#define PARAM24_BIT3_MASK               8U
#define PARAM24_BIT4_MASK               16U
#define PARAM24_BIT5_MASK               32U
#define PARAM24_BIT6_MASK               64U
#define PARAM24_BIT7_MASK               128U


/*** PARAM25 - Parameter Register 25; 0x00000069 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM25STR;
extern volatile PARAM25STR _PARAM25 @0x00000069;
#define PARAM25                         _PARAM25.Byte
#define PARAM25_BIT0                    _PARAM25.Bits.BIT0
#define PARAM25_BIT1                    _PARAM25.Bits.BIT1
#define PARAM25_BIT2                    _PARAM25.Bits.BIT2
#define PARAM25_BIT3                    _PARAM25.Bits.BIT3
#define PARAM25_BIT4                    _PARAM25.Bits.BIT4
#define PARAM25_BIT5                    _PARAM25.Bits.BIT5
#define PARAM25_BIT6                    _PARAM25.Bits.BIT6
#define PARAM25_BIT7                    _PARAM25.Bits.BIT7

#define PARAM25_BIT0_MASK               1U
#define PARAM25_BIT1_MASK               2U
#define PARAM25_BIT2_MASK               4U
#define PARAM25_BIT3_MASK               8U
#define PARAM25_BIT4_MASK               16U
#define PARAM25_BIT5_MASK               32U
#define PARAM25_BIT6_MASK               64U
#define PARAM25_BIT7_MASK               128U


/*** PARAM26 - Parameter Register 26; 0x0000006A ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM26STR;
extern volatile PARAM26STR _PARAM26 @0x0000006A;
#define PARAM26                         _PARAM26.Byte
#define PARAM26_BIT0                    _PARAM26.Bits.BIT0
#define PARAM26_BIT1                    _PARAM26.Bits.BIT1
#define PARAM26_BIT2                    _PARAM26.Bits.BIT2
#define PARAM26_BIT3                    _PARAM26.Bits.BIT3
#define PARAM26_BIT4                    _PARAM26.Bits.BIT4
#define PARAM26_BIT5                    _PARAM26.Bits.BIT5
#define PARAM26_BIT6                    _PARAM26.Bits.BIT6
#define PARAM26_BIT7                    _PARAM26.Bits.BIT7

#define PARAM26_BIT0_MASK               1U
#define PARAM26_BIT1_MASK               2U
#define PARAM26_BIT2_MASK               4U
#define PARAM26_BIT3_MASK               8U
#define PARAM26_BIT4_MASK               16U
#define PARAM26_BIT5_MASK               32U
#define PARAM26_BIT6_MASK               64U
#define PARAM26_BIT7_MASK               128U


/*** PARAM27 - Parameter Register 27; 0x0000006B ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM27STR;
extern volatile PARAM27STR _PARAM27 @0x0000006B;
#define PARAM27                         _PARAM27.Byte
#define PARAM27_BIT0                    _PARAM27.Bits.BIT0
#define PARAM27_BIT1                    _PARAM27.Bits.BIT1
#define PARAM27_BIT2                    _PARAM27.Bits.BIT2
#define PARAM27_BIT3                    _PARAM27.Bits.BIT3
#define PARAM27_BIT4                    _PARAM27.Bits.BIT4
#define PARAM27_BIT5                    _PARAM27.Bits.BIT5
#define PARAM27_BIT6                    _PARAM27.Bits.BIT6
#define PARAM27_BIT7                    _PARAM27.Bits.BIT7

#define PARAM27_BIT0_MASK               1U
#define PARAM27_BIT1_MASK               2U
#define PARAM27_BIT2_MASK               4U
#define PARAM27_BIT3_MASK               8U
#define PARAM27_BIT4_MASK               16U
#define PARAM27_BIT5_MASK               32U
#define PARAM27_BIT6_MASK               64U
#define PARAM27_BIT7_MASK               128U


/*** PARAM28 - Parameter Register 28; 0x0000006C ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM28STR;
extern volatile PARAM28STR _PARAM28 @0x0000006C;
#define PARAM28                         _PARAM28.Byte
#define PARAM28_BIT0                    _PARAM28.Bits.BIT0
#define PARAM28_BIT1                    _PARAM28.Bits.BIT1
#define PARAM28_BIT2                    _PARAM28.Bits.BIT2
#define PARAM28_BIT3                    _PARAM28.Bits.BIT3
#define PARAM28_BIT4                    _PARAM28.Bits.BIT4
#define PARAM28_BIT5                    _PARAM28.Bits.BIT5
#define PARAM28_BIT6                    _PARAM28.Bits.BIT6
#define PARAM28_BIT7                    _PARAM28.Bits.BIT7

#define PARAM28_BIT0_MASK               1U
#define PARAM28_BIT1_MASK               2U
#define PARAM28_BIT2_MASK               4U
#define PARAM28_BIT3_MASK               8U
#define PARAM28_BIT4_MASK               16U
#define PARAM28_BIT5_MASK               32U
#define PARAM28_BIT6_MASK               64U
#define PARAM28_BIT7_MASK               128U


/*** PARAM29 - Parameter Register 29; 0x0000006D ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM29STR;
extern volatile PARAM29STR _PARAM29 @0x0000006D;
#define PARAM29                         _PARAM29.Byte
#define PARAM29_BIT0                    _PARAM29.Bits.BIT0
#define PARAM29_BIT1                    _PARAM29.Bits.BIT1
#define PARAM29_BIT2                    _PARAM29.Bits.BIT2
#define PARAM29_BIT3                    _PARAM29.Bits.BIT3
#define PARAM29_BIT4                    _PARAM29.Bits.BIT4
#define PARAM29_BIT5                    _PARAM29.Bits.BIT5
#define PARAM29_BIT6                    _PARAM29.Bits.BIT6
#define PARAM29_BIT7                    _PARAM29.Bits.BIT7

#define PARAM29_BIT0_MASK               1U
#define PARAM29_BIT1_MASK               2U
#define PARAM29_BIT2_MASK               4U
#define PARAM29_BIT3_MASK               8U
#define PARAM29_BIT4_MASK               16U
#define PARAM29_BIT5_MASK               32U
#define PARAM29_BIT6_MASK               64U
#define PARAM29_BIT7_MASK               128U


/*** PARAM30 - Parameter Register 30; 0x0000006E ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM30STR;
extern volatile PARAM30STR _PARAM30 @0x0000006E;
#define PARAM30                         _PARAM30.Byte
#define PARAM30_BIT0                    _PARAM30.Bits.BIT0
#define PARAM30_BIT1                    _PARAM30.Bits.BIT1
#define PARAM30_BIT2                    _PARAM30.Bits.BIT2
#define PARAM30_BIT3                    _PARAM30.Bits.BIT3
#define PARAM30_BIT4                    _PARAM30.Bits.BIT4
#define PARAM30_BIT5                    _PARAM30.Bits.BIT5
#define PARAM30_BIT6                    _PARAM30.Bits.BIT6
#define PARAM30_BIT7                    _PARAM30.Bits.BIT7

#define PARAM30_BIT0_MASK               1U
#define PARAM30_BIT1_MASK               2U
#define PARAM30_BIT2_MASK               4U
#define PARAM30_BIT3_MASK               8U
#define PARAM30_BIT4_MASK               16U
#define PARAM30_BIT5_MASK               32U
#define PARAM30_BIT6_MASK               64U
#define PARAM30_BIT7_MASK               128U


/*** PARAM31 - Parameter Register 31; 0x0000006F ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM31STR;
extern volatile PARAM31STR _PARAM31 @0x0000006F;
#define PARAM31                         _PARAM31.Byte
#define PARAM31_BIT0                    _PARAM31.Bits.BIT0
#define PARAM31_BIT1                    _PARAM31.Bits.BIT1
#define PARAM31_BIT2                    _PARAM31.Bits.BIT2
#define PARAM31_BIT3                    _PARAM31.Bits.BIT3
#define PARAM31_BIT4                    _PARAM31.Bits.BIT4
#define PARAM31_BIT5                    _PARAM31.Bits.BIT5
#define PARAM31_BIT6                    _PARAM31.Bits.BIT6
#define PARAM31_BIT7                    _PARAM31.Bits.BIT7

#define PARAM31_BIT0_MASK               1U
#define PARAM31_BIT1_MASK               2U
#define PARAM31_BIT2_MASK               4U
#define PARAM31_BIT3_MASK               8U
#define PARAM31_BIT4_MASK               16U
#define PARAM31_BIT5_MASK               32U
#define PARAM31_BIT6_MASK               64U
#define PARAM31_BIT7_MASK               128U


/*** PARAM32 - Parameter Register 32; 0x00000070 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM32STR;
extern volatile PARAM32STR _PARAM32 @0x00000070;
#define PARAM32                         _PARAM32.Byte
#define PARAM32_BIT0                    _PARAM32.Bits.BIT0
#define PARAM32_BIT1                    _PARAM32.Bits.BIT1
#define PARAM32_BIT2                    _PARAM32.Bits.BIT2
#define PARAM32_BIT3                    _PARAM32.Bits.BIT3
#define PARAM32_BIT4                    _PARAM32.Bits.BIT4
#define PARAM32_BIT5                    _PARAM32.Bits.BIT5
#define PARAM32_BIT6                    _PARAM32.Bits.BIT6
#define PARAM32_BIT7                    _PARAM32.Bits.BIT7

#define PARAM32_BIT0_MASK               1U
#define PARAM32_BIT1_MASK               2U
#define PARAM32_BIT2_MASK               4U
#define PARAM32_BIT3_MASK               8U
#define PARAM32_BIT4_MASK               16U
#define PARAM32_BIT5_MASK               32U
#define PARAM32_BIT6_MASK               64U
#define PARAM32_BIT7_MASK               128U


/*** PARAM33 - Parameter Register 33; 0x00000071 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM33STR;
extern volatile PARAM33STR _PARAM33 @0x00000071;
#define PARAM33                         _PARAM33.Byte
#define PARAM33_BIT0                    _PARAM33.Bits.BIT0
#define PARAM33_BIT1                    _PARAM33.Bits.BIT1
#define PARAM33_BIT2                    _PARAM33.Bits.BIT2
#define PARAM33_BIT3                    _PARAM33.Bits.BIT3
#define PARAM33_BIT4                    _PARAM33.Bits.BIT4
#define PARAM33_BIT5                    _PARAM33.Bits.BIT5
#define PARAM33_BIT6                    _PARAM33.Bits.BIT6
#define PARAM33_BIT7                    _PARAM33.Bits.BIT7

#define PARAM33_BIT0_MASK               1U
#define PARAM33_BIT1_MASK               2U
#define PARAM33_BIT2_MASK               4U
#define PARAM33_BIT3_MASK               8U
#define PARAM33_BIT4_MASK               16U
#define PARAM33_BIT5_MASK               32U
#define PARAM33_BIT6_MASK               64U
#define PARAM33_BIT7_MASK               128U


/*** PARAM34 - Parameter Register 34; 0x00000072 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM34STR;
extern volatile PARAM34STR _PARAM34 @0x00000072;
#define PARAM34                         _PARAM34.Byte
#define PARAM34_BIT0                    _PARAM34.Bits.BIT0
#define PARAM34_BIT1                    _PARAM34.Bits.BIT1
#define PARAM34_BIT2                    _PARAM34.Bits.BIT2
#define PARAM34_BIT3                    _PARAM34.Bits.BIT3
#define PARAM34_BIT4                    _PARAM34.Bits.BIT4
#define PARAM34_BIT5                    _PARAM34.Bits.BIT5
#define PARAM34_BIT6                    _PARAM34.Bits.BIT6
#define PARAM34_BIT7                    _PARAM34.Bits.BIT7

#define PARAM34_BIT0_MASK               1U
#define PARAM34_BIT1_MASK               2U
#define PARAM34_BIT2_MASK               4U
#define PARAM34_BIT3_MASK               8U
#define PARAM34_BIT4_MASK               16U
#define PARAM34_BIT5_MASK               32U
#define PARAM34_BIT6_MASK               64U
#define PARAM34_BIT7_MASK               128U


/*** PARAM35 - Parameter Register 35; 0x00000073 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM35STR;
extern volatile PARAM35STR _PARAM35 @0x00000073;
#define PARAM35                         _PARAM35.Byte
#define PARAM35_BIT0                    _PARAM35.Bits.BIT0
#define PARAM35_BIT1                    _PARAM35.Bits.BIT1
#define PARAM35_BIT2                    _PARAM35.Bits.BIT2
#define PARAM35_BIT3                    _PARAM35.Bits.BIT3
#define PARAM35_BIT4                    _PARAM35.Bits.BIT4
#define PARAM35_BIT5                    _PARAM35.Bits.BIT5
#define PARAM35_BIT6                    _PARAM35.Bits.BIT6
#define PARAM35_BIT7                    _PARAM35.Bits.BIT7

#define PARAM35_BIT0_MASK               1U
#define PARAM35_BIT1_MASK               2U
#define PARAM35_BIT2_MASK               4U
#define PARAM35_BIT3_MASK               8U
#define PARAM35_BIT4_MASK               16U
#define PARAM35_BIT5_MASK               32U
#define PARAM35_BIT6_MASK               64U
#define PARAM35_BIT7_MASK               128U


/*** PARAM36 - Parameter Register 36; 0x00000074 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM36STR;
extern volatile PARAM36STR _PARAM36 @0x00000074;
#define PARAM36                         _PARAM36.Byte
#define PARAM36_BIT0                    _PARAM36.Bits.BIT0
#define PARAM36_BIT1                    _PARAM36.Bits.BIT1
#define PARAM36_BIT2                    _PARAM36.Bits.BIT2
#define PARAM36_BIT3                    _PARAM36.Bits.BIT3
#define PARAM36_BIT4                    _PARAM36.Bits.BIT4
#define PARAM36_BIT5                    _PARAM36.Bits.BIT5
#define PARAM36_BIT6                    _PARAM36.Bits.BIT6
#define PARAM36_BIT7                    _PARAM36.Bits.BIT7

#define PARAM36_BIT0_MASK               1U
#define PARAM36_BIT1_MASK               2U
#define PARAM36_BIT2_MASK               4U
#define PARAM36_BIT3_MASK               8U
#define PARAM36_BIT4_MASK               16U
#define PARAM36_BIT5_MASK               32U
#define PARAM36_BIT6_MASK               64U
#define PARAM36_BIT7_MASK               128U


/*** PARAM37 - Parameter Register 37; 0x00000075 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM37STR;
extern volatile PARAM37STR _PARAM37 @0x00000075;
#define PARAM37                         _PARAM37.Byte
#define PARAM37_BIT0                    _PARAM37.Bits.BIT0
#define PARAM37_BIT1                    _PARAM37.Bits.BIT1
#define PARAM37_BIT2                    _PARAM37.Bits.BIT2
#define PARAM37_BIT3                    _PARAM37.Bits.BIT3
#define PARAM37_BIT4                    _PARAM37.Bits.BIT4
#define PARAM37_BIT5                    _PARAM37.Bits.BIT5
#define PARAM37_BIT6                    _PARAM37.Bits.BIT6
#define PARAM37_BIT7                    _PARAM37.Bits.BIT7

#define PARAM37_BIT0_MASK               1U
#define PARAM37_BIT1_MASK               2U
#define PARAM37_BIT2_MASK               4U
#define PARAM37_BIT3_MASK               8U
#define PARAM37_BIT4_MASK               16U
#define PARAM37_BIT5_MASK               32U
#define PARAM37_BIT6_MASK               64U
#define PARAM37_BIT7_MASK               128U


/*** PARAM38 - Parameter Register 38; 0x00000076 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM38STR;
extern volatile PARAM38STR _PARAM38 @0x00000076;
#define PARAM38                         _PARAM38.Byte
#define PARAM38_BIT0                    _PARAM38.Bits.BIT0
#define PARAM38_BIT1                    _PARAM38.Bits.BIT1
#define PARAM38_BIT2                    _PARAM38.Bits.BIT2
#define PARAM38_BIT3                    _PARAM38.Bits.BIT3
#define PARAM38_BIT4                    _PARAM38.Bits.BIT4
#define PARAM38_BIT5                    _PARAM38.Bits.BIT5
#define PARAM38_BIT6                    _PARAM38.Bits.BIT6
#define PARAM38_BIT7                    _PARAM38.Bits.BIT7

#define PARAM38_BIT0_MASK               1U
#define PARAM38_BIT1_MASK               2U
#define PARAM38_BIT2_MASK               4U
#define PARAM38_BIT3_MASK               8U
#define PARAM38_BIT4_MASK               16U
#define PARAM38_BIT5_MASK               32U
#define PARAM38_BIT6_MASK               64U
#define PARAM38_BIT7_MASK               128U


/*** PARAM39 - Parameter Register 39; 0x00000077 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM39STR;
extern volatile PARAM39STR _PARAM39 @0x00000077;
#define PARAM39                         _PARAM39.Byte
#define PARAM39_BIT0                    _PARAM39.Bits.BIT0
#define PARAM39_BIT1                    _PARAM39.Bits.BIT1
#define PARAM39_BIT2                    _PARAM39.Bits.BIT2
#define PARAM39_BIT3                    _PARAM39.Bits.BIT3
#define PARAM39_BIT4                    _PARAM39.Bits.BIT4
#define PARAM39_BIT5                    _PARAM39.Bits.BIT5
#define PARAM39_BIT6                    _PARAM39.Bits.BIT6
#define PARAM39_BIT7                    _PARAM39.Bits.BIT7

#define PARAM39_BIT0_MASK               1U
#define PARAM39_BIT1_MASK               2U
#define PARAM39_BIT2_MASK               4U
#define PARAM39_BIT3_MASK               8U
#define PARAM39_BIT4_MASK               16U
#define PARAM39_BIT5_MASK               32U
#define PARAM39_BIT6_MASK               64U
#define PARAM39_BIT7_MASK               128U


/*** PARAM40 - Parameter Register 40; 0x00000078 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM40STR;
extern volatile PARAM40STR _PARAM40 @0x00000078;
#define PARAM40                         _PARAM40.Byte
#define PARAM40_BIT0                    _PARAM40.Bits.BIT0
#define PARAM40_BIT1                    _PARAM40.Bits.BIT1
#define PARAM40_BIT2                    _PARAM40.Bits.BIT2
#define PARAM40_BIT3                    _PARAM40.Bits.BIT3
#define PARAM40_BIT4                    _PARAM40.Bits.BIT4
#define PARAM40_BIT5                    _PARAM40.Bits.BIT5
#define PARAM40_BIT6                    _PARAM40.Bits.BIT6
#define PARAM40_BIT7                    _PARAM40.Bits.BIT7

#define PARAM40_BIT0_MASK               1U
#define PARAM40_BIT1_MASK               2U
#define PARAM40_BIT2_MASK               4U
#define PARAM40_BIT3_MASK               8U
#define PARAM40_BIT4_MASK               16U
#define PARAM40_BIT5_MASK               32U
#define PARAM40_BIT6_MASK               64U
#define PARAM40_BIT7_MASK               128U


/*** PARAM41 - Parameter Register 41; 0x00000079 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM41STR;
extern volatile PARAM41STR _PARAM41 @0x00000079;
#define PARAM41                         _PARAM41.Byte
#define PARAM41_BIT0                    _PARAM41.Bits.BIT0
#define PARAM41_BIT1                    _PARAM41.Bits.BIT1
#define PARAM41_BIT2                    _PARAM41.Bits.BIT2
#define PARAM41_BIT3                    _PARAM41.Bits.BIT3
#define PARAM41_BIT4                    _PARAM41.Bits.BIT4
#define PARAM41_BIT5                    _PARAM41.Bits.BIT5
#define PARAM41_BIT6                    _PARAM41.Bits.BIT6
#define PARAM41_BIT7                    _PARAM41.Bits.BIT7

#define PARAM41_BIT0_MASK               1U
#define PARAM41_BIT1_MASK               2U
#define PARAM41_BIT2_MASK               4U
#define PARAM41_BIT3_MASK               8U
#define PARAM41_BIT4_MASK               16U
#define PARAM41_BIT5_MASK               32U
#define PARAM41_BIT6_MASK               64U
#define PARAM41_BIT7_MASK               128U


/*** PARAM42 - Parameter Register 42; 0x0000007A ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM42STR;
extern volatile PARAM42STR _PARAM42 @0x0000007A;
#define PARAM42                         _PARAM42.Byte
#define PARAM42_BIT0                    _PARAM42.Bits.BIT0
#define PARAM42_BIT1                    _PARAM42.Bits.BIT1
#define PARAM42_BIT2                    _PARAM42.Bits.BIT2
#define PARAM42_BIT3                    _PARAM42.Bits.BIT3
#define PARAM42_BIT4                    _PARAM42.Bits.BIT4
#define PARAM42_BIT5                    _PARAM42.Bits.BIT5
#define PARAM42_BIT6                    _PARAM42.Bits.BIT6
#define PARAM42_BIT7                    _PARAM42.Bits.BIT7

#define PARAM42_BIT0_MASK               1U
#define PARAM42_BIT1_MASK               2U
#define PARAM42_BIT2_MASK               4U
#define PARAM42_BIT3_MASK               8U
#define PARAM42_BIT4_MASK               16U
#define PARAM42_BIT5_MASK               32U
#define PARAM42_BIT6_MASK               64U
#define PARAM42_BIT7_MASK               128U


/*** PARAM43 - Parameter Register 43; 0x0000007B ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM43STR;
extern volatile PARAM43STR _PARAM43 @0x0000007B;
#define PARAM43                         _PARAM43.Byte
#define PARAM43_BIT0                    _PARAM43.Bits.BIT0
#define PARAM43_BIT1                    _PARAM43.Bits.BIT1
#define PARAM43_BIT2                    _PARAM43.Bits.BIT2
#define PARAM43_BIT3                    _PARAM43.Bits.BIT3
#define PARAM43_BIT4                    _PARAM43.Bits.BIT4
#define PARAM43_BIT5                    _PARAM43.Bits.BIT5
#define PARAM43_BIT6                    _PARAM43.Bits.BIT6
#define PARAM43_BIT7                    _PARAM43.Bits.BIT7

#define PARAM43_BIT0_MASK               1U
#define PARAM43_BIT1_MASK               2U
#define PARAM43_BIT2_MASK               4U
#define PARAM43_BIT3_MASK               8U
#define PARAM43_BIT4_MASK               16U
#define PARAM43_BIT5_MASK               32U
#define PARAM43_BIT6_MASK               64U
#define PARAM43_BIT7_MASK               128U


/*** PARAM44 - Parameter Register 44; 0x0000007C ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM44STR;
extern volatile PARAM44STR _PARAM44 @0x0000007C;
#define PARAM44                         _PARAM44.Byte
#define PARAM44_BIT0                    _PARAM44.Bits.BIT0
#define PARAM44_BIT1                    _PARAM44.Bits.BIT1
#define PARAM44_BIT2                    _PARAM44.Bits.BIT2
#define PARAM44_BIT3                    _PARAM44.Bits.BIT3
#define PARAM44_BIT4                    _PARAM44.Bits.BIT4
#define PARAM44_BIT5                    _PARAM44.Bits.BIT5
#define PARAM44_BIT6                    _PARAM44.Bits.BIT6
#define PARAM44_BIT7                    _PARAM44.Bits.BIT7

#define PARAM44_BIT0_MASK               1U
#define PARAM44_BIT1_MASK               2U
#define PARAM44_BIT2_MASK               4U
#define PARAM44_BIT3_MASK               8U
#define PARAM44_BIT4_MASK               16U
#define PARAM44_BIT5_MASK               32U
#define PARAM44_BIT6_MASK               64U
#define PARAM44_BIT7_MASK               128U


/*** PARAM45 - Parameter Register 45; 0x0000007D ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM45STR;
extern volatile PARAM45STR _PARAM45 @0x0000007D;
#define PARAM45                         _PARAM45.Byte
#define PARAM45_BIT0                    _PARAM45.Bits.BIT0
#define PARAM45_BIT1                    _PARAM45.Bits.BIT1
#define PARAM45_BIT2                    _PARAM45.Bits.BIT2
#define PARAM45_BIT3                    _PARAM45.Bits.BIT3
#define PARAM45_BIT4                    _PARAM45.Bits.BIT4
#define PARAM45_BIT5                    _PARAM45.Bits.BIT5
#define PARAM45_BIT6                    _PARAM45.Bits.BIT6
#define PARAM45_BIT7                    _PARAM45.Bits.BIT7

#define PARAM45_BIT0_MASK               1U
#define PARAM45_BIT1_MASK               2U
#define PARAM45_BIT2_MASK               4U
#define PARAM45_BIT3_MASK               8U
#define PARAM45_BIT4_MASK               16U
#define PARAM45_BIT5_MASK               32U
#define PARAM45_BIT6_MASK               64U
#define PARAM45_BIT7_MASK               128U


/*** PARAM46 - Parameter Register 46; 0x0000007E ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM46STR;
extern volatile PARAM46STR _PARAM46 @0x0000007E;
#define PARAM46                         _PARAM46.Byte
#define PARAM46_BIT0                    _PARAM46.Bits.BIT0
#define PARAM46_BIT1                    _PARAM46.Bits.BIT1
#define PARAM46_BIT2                    _PARAM46.Bits.BIT2
#define PARAM46_BIT3                    _PARAM46.Bits.BIT3
#define PARAM46_BIT4                    _PARAM46.Bits.BIT4
#define PARAM46_BIT5                    _PARAM46.Bits.BIT5
#define PARAM46_BIT6                    _PARAM46.Bits.BIT6
#define PARAM46_BIT7                    _PARAM46.Bits.BIT7

#define PARAM46_BIT0_MASK               1U
#define PARAM46_BIT1_MASK               2U
#define PARAM46_BIT2_MASK               4U
#define PARAM46_BIT3_MASK               8U
#define PARAM46_BIT4_MASK               16U
#define PARAM46_BIT5_MASK               32U
#define PARAM46_BIT6_MASK               64U
#define PARAM46_BIT7_MASK               128U


/*** PARAM47 - Parameter Register 47; 0x0000007F ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM47STR;
extern volatile PARAM47STR _PARAM47 @0x0000007F;
#define PARAM47                         _PARAM47.Byte
#define PARAM47_BIT0                    _PARAM47.Bits.BIT0
#define PARAM47_BIT1                    _PARAM47.Bits.BIT1
#define PARAM47_BIT2                    _PARAM47.Bits.BIT2
#define PARAM47_BIT3                    _PARAM47.Bits.BIT3
#define PARAM47_BIT4                    _PARAM47.Bits.BIT4
#define PARAM47_BIT5                    _PARAM47.Bits.BIT5
#define PARAM47_BIT6                    _PARAM47.Bits.BIT6
#define PARAM47_BIT7                    _PARAM47.Bits.BIT7

#define PARAM47_BIT0_MASK               1U
#define PARAM47_BIT1_MASK               2U
#define PARAM47_BIT2_MASK               4U
#define PARAM47_BIT3_MASK               8U
#define PARAM47_BIT4_MASK               16U
#define PARAM47_BIT5_MASK               32U
#define PARAM47_BIT6_MASK               64U
#define PARAM47_BIT7_MASK               128U


/*** PARAM48 - Parameter Register 48; 0x00000080 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM48STR;
extern volatile PARAM48STR _PARAM48 @0x00000080;
#define PARAM48                         _PARAM48.Byte
#define PARAM48_BIT0                    _PARAM48.Bits.BIT0
#define PARAM48_BIT1                    _PARAM48.Bits.BIT1
#define PARAM48_BIT2                    _PARAM48.Bits.BIT2
#define PARAM48_BIT3                    _PARAM48.Bits.BIT3
#define PARAM48_BIT4                    _PARAM48.Bits.BIT4
#define PARAM48_BIT5                    _PARAM48.Bits.BIT5
#define PARAM48_BIT6                    _PARAM48.Bits.BIT6
#define PARAM48_BIT7                    _PARAM48.Bits.BIT7

#define PARAM48_BIT0_MASK               1U
#define PARAM48_BIT1_MASK               2U
#define PARAM48_BIT2_MASK               4U
#define PARAM48_BIT3_MASK               8U
#define PARAM48_BIT4_MASK               16U
#define PARAM48_BIT5_MASK               32U
#define PARAM48_BIT6_MASK               64U
#define PARAM48_BIT7_MASK               128U


/*** PARAM49 - Parameter Register 49; 0x00000081 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM49STR;
extern volatile PARAM49STR _PARAM49 @0x00000081;
#define PARAM49                         _PARAM49.Byte
#define PARAM49_BIT0                    _PARAM49.Bits.BIT0
#define PARAM49_BIT1                    _PARAM49.Bits.BIT1
#define PARAM49_BIT2                    _PARAM49.Bits.BIT2
#define PARAM49_BIT3                    _PARAM49.Bits.BIT3
#define PARAM49_BIT4                    _PARAM49.Bits.BIT4
#define PARAM49_BIT5                    _PARAM49.Bits.BIT5
#define PARAM49_BIT6                    _PARAM49.Bits.BIT6
#define PARAM49_BIT7                    _PARAM49.Bits.BIT7

#define PARAM49_BIT0_MASK               1U
#define PARAM49_BIT1_MASK               2U
#define PARAM49_BIT2_MASK               4U
#define PARAM49_BIT3_MASK               8U
#define PARAM49_BIT4_MASK               16U
#define PARAM49_BIT5_MASK               32U
#define PARAM49_BIT6_MASK               64U
#define PARAM49_BIT7_MASK               128U


/*** PARAM50 - Parameter Register 50; 0x00000082 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM50STR;
extern volatile PARAM50STR _PARAM50 @0x00000082;
#define PARAM50                         _PARAM50.Byte
#define PARAM50_BIT0                    _PARAM50.Bits.BIT0
#define PARAM50_BIT1                    _PARAM50.Bits.BIT1
#define PARAM50_BIT2                    _PARAM50.Bits.BIT2
#define PARAM50_BIT3                    _PARAM50.Bits.BIT3
#define PARAM50_BIT4                    _PARAM50.Bits.BIT4
#define PARAM50_BIT5                    _PARAM50.Bits.BIT5
#define PARAM50_BIT6                    _PARAM50.Bits.BIT6
#define PARAM50_BIT7                    _PARAM50.Bits.BIT7

#define PARAM50_BIT0_MASK               1U
#define PARAM50_BIT1_MASK               2U
#define PARAM50_BIT2_MASK               4U
#define PARAM50_BIT3_MASK               8U
#define PARAM50_BIT4_MASK               16U
#define PARAM50_BIT5_MASK               32U
#define PARAM50_BIT6_MASK               64U
#define PARAM50_BIT7_MASK               128U


/*** PARAM51 - Parameter Register 51; 0x00000083 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM51STR;
extern volatile PARAM51STR _PARAM51 @0x00000083;
#define PARAM51                         _PARAM51.Byte
#define PARAM51_BIT0                    _PARAM51.Bits.BIT0
#define PARAM51_BIT1                    _PARAM51.Bits.BIT1
#define PARAM51_BIT2                    _PARAM51.Bits.BIT2
#define PARAM51_BIT3                    _PARAM51.Bits.BIT3
#define PARAM51_BIT4                    _PARAM51.Bits.BIT4
#define PARAM51_BIT5                    _PARAM51.Bits.BIT5
#define PARAM51_BIT6                    _PARAM51.Bits.BIT6
#define PARAM51_BIT7                    _PARAM51.Bits.BIT7

#define PARAM51_BIT0_MASK               1U
#define PARAM51_BIT1_MASK               2U
#define PARAM51_BIT2_MASK               4U
#define PARAM51_BIT3_MASK               8U
#define PARAM51_BIT4_MASK               16U
#define PARAM51_BIT5_MASK               32U
#define PARAM51_BIT6_MASK               64U
#define PARAM51_BIT7_MASK               128U


/*** PARAM52 - Parameter Register 52; 0x00000084 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM52STR;
extern volatile PARAM52STR _PARAM52 @0x00000084;
#define PARAM52                         _PARAM52.Byte
#define PARAM52_BIT0                    _PARAM52.Bits.BIT0
#define PARAM52_BIT1                    _PARAM52.Bits.BIT1
#define PARAM52_BIT2                    _PARAM52.Bits.BIT2
#define PARAM52_BIT3                    _PARAM52.Bits.BIT3
#define PARAM52_BIT4                    _PARAM52.Bits.BIT4
#define PARAM52_BIT5                    _PARAM52.Bits.BIT5
#define PARAM52_BIT6                    _PARAM52.Bits.BIT6
#define PARAM52_BIT7                    _PARAM52.Bits.BIT7

#define PARAM52_BIT0_MASK               1U
#define PARAM52_BIT1_MASK               2U
#define PARAM52_BIT2_MASK               4U
#define PARAM52_BIT3_MASK               8U
#define PARAM52_BIT4_MASK               16U
#define PARAM52_BIT5_MASK               32U
#define PARAM52_BIT6_MASK               64U
#define PARAM52_BIT7_MASK               128U


/*** PARAM53 - Parameter Register 53; 0x00000085 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM53STR;
extern volatile PARAM53STR _PARAM53 @0x00000085;
#define PARAM53                         _PARAM53.Byte
#define PARAM53_BIT0                    _PARAM53.Bits.BIT0
#define PARAM53_BIT1                    _PARAM53.Bits.BIT1
#define PARAM53_BIT2                    _PARAM53.Bits.BIT2
#define PARAM53_BIT3                    _PARAM53.Bits.BIT3
#define PARAM53_BIT4                    _PARAM53.Bits.BIT4
#define PARAM53_BIT5                    _PARAM53.Bits.BIT5
#define PARAM53_BIT6                    _PARAM53.Bits.BIT6
#define PARAM53_BIT7                    _PARAM53.Bits.BIT7

#define PARAM53_BIT0_MASK               1U
#define PARAM53_BIT1_MASK               2U
#define PARAM53_BIT2_MASK               4U
#define PARAM53_BIT3_MASK               8U
#define PARAM53_BIT4_MASK               16U
#define PARAM53_BIT5_MASK               32U
#define PARAM53_BIT6_MASK               64U
#define PARAM53_BIT7_MASK               128U


/*** PARAM54 - Parameter Register 54; 0x00000086 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM54STR;
extern volatile PARAM54STR _PARAM54 @0x00000086;
#define PARAM54                         _PARAM54.Byte
#define PARAM54_BIT0                    _PARAM54.Bits.BIT0
#define PARAM54_BIT1                    _PARAM54.Bits.BIT1
#define PARAM54_BIT2                    _PARAM54.Bits.BIT2
#define PARAM54_BIT3                    _PARAM54.Bits.BIT3
#define PARAM54_BIT4                    _PARAM54.Bits.BIT4
#define PARAM54_BIT5                    _PARAM54.Bits.BIT5
#define PARAM54_BIT6                    _PARAM54.Bits.BIT6
#define PARAM54_BIT7                    _PARAM54.Bits.BIT7

#define PARAM54_BIT0_MASK               1U
#define PARAM54_BIT1_MASK               2U
#define PARAM54_BIT2_MASK               4U
#define PARAM54_BIT3_MASK               8U
#define PARAM54_BIT4_MASK               16U
#define PARAM54_BIT5_MASK               32U
#define PARAM54_BIT6_MASK               64U
#define PARAM54_BIT7_MASK               128U


/*** PARAM55 - Parameter Register 55; 0x00000087 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM55STR;
extern volatile PARAM55STR _PARAM55 @0x00000087;
#define PARAM55                         _PARAM55.Byte
#define PARAM55_BIT0                    _PARAM55.Bits.BIT0
#define PARAM55_BIT1                    _PARAM55.Bits.BIT1
#define PARAM55_BIT2                    _PARAM55.Bits.BIT2
#define PARAM55_BIT3                    _PARAM55.Bits.BIT3
#define PARAM55_BIT4                    _PARAM55.Bits.BIT4
#define PARAM55_BIT5                    _PARAM55.Bits.BIT5
#define PARAM55_BIT6                    _PARAM55.Bits.BIT6
#define PARAM55_BIT7                    _PARAM55.Bits.BIT7

#define PARAM55_BIT0_MASK               1U
#define PARAM55_BIT1_MASK               2U
#define PARAM55_BIT2_MASK               4U
#define PARAM55_BIT3_MASK               8U
#define PARAM55_BIT4_MASK               16U
#define PARAM55_BIT5_MASK               32U
#define PARAM55_BIT6_MASK               64U
#define PARAM55_BIT7_MASK               128U


/*** PARAM56 - Parameter Register 56; 0x00000088 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM56STR;
extern volatile PARAM56STR _PARAM56 @0x00000088;
#define PARAM56                         _PARAM56.Byte
#define PARAM56_BIT0                    _PARAM56.Bits.BIT0
#define PARAM56_BIT1                    _PARAM56.Bits.BIT1
#define PARAM56_BIT2                    _PARAM56.Bits.BIT2
#define PARAM56_BIT3                    _PARAM56.Bits.BIT3
#define PARAM56_BIT4                    _PARAM56.Bits.BIT4
#define PARAM56_BIT5                    _PARAM56.Bits.BIT5
#define PARAM56_BIT6                    _PARAM56.Bits.BIT6
#define PARAM56_BIT7                    _PARAM56.Bits.BIT7

#define PARAM56_BIT0_MASK               1U
#define PARAM56_BIT1_MASK               2U
#define PARAM56_BIT2_MASK               4U
#define PARAM56_BIT3_MASK               8U
#define PARAM56_BIT4_MASK               16U
#define PARAM56_BIT5_MASK               32U
#define PARAM56_BIT6_MASK               64U
#define PARAM56_BIT7_MASK               128U


/*** PARAM57 - Parameter Register 57; 0x00000089 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM57STR;
extern volatile PARAM57STR _PARAM57 @0x00000089;
#define PARAM57                         _PARAM57.Byte
#define PARAM57_BIT0                    _PARAM57.Bits.BIT0
#define PARAM57_BIT1                    _PARAM57.Bits.BIT1
#define PARAM57_BIT2                    _PARAM57.Bits.BIT2
#define PARAM57_BIT3                    _PARAM57.Bits.BIT3
#define PARAM57_BIT4                    _PARAM57.Bits.BIT4
#define PARAM57_BIT5                    _PARAM57.Bits.BIT5
#define PARAM57_BIT6                    _PARAM57.Bits.BIT6
#define PARAM57_BIT7                    _PARAM57.Bits.BIT7

#define PARAM57_BIT0_MASK               1U
#define PARAM57_BIT1_MASK               2U
#define PARAM57_BIT2_MASK               4U
#define PARAM57_BIT3_MASK               8U
#define PARAM57_BIT4_MASK               16U
#define PARAM57_BIT5_MASK               32U
#define PARAM57_BIT6_MASK               64U
#define PARAM57_BIT7_MASK               128U


/*** PARAM58 - Parameter Register 58; 0x0000008A ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM58STR;
extern volatile PARAM58STR _PARAM58 @0x0000008A;
#define PARAM58                         _PARAM58.Byte
#define PARAM58_BIT0                    _PARAM58.Bits.BIT0
#define PARAM58_BIT1                    _PARAM58.Bits.BIT1
#define PARAM58_BIT2                    _PARAM58.Bits.BIT2
#define PARAM58_BIT3                    _PARAM58.Bits.BIT3
#define PARAM58_BIT4                    _PARAM58.Bits.BIT4
#define PARAM58_BIT5                    _PARAM58.Bits.BIT5
#define PARAM58_BIT6                    _PARAM58.Bits.BIT6
#define PARAM58_BIT7                    _PARAM58.Bits.BIT7

#define PARAM58_BIT0_MASK               1U
#define PARAM58_BIT1_MASK               2U
#define PARAM58_BIT2_MASK               4U
#define PARAM58_BIT3_MASK               8U
#define PARAM58_BIT4_MASK               16U
#define PARAM58_BIT5_MASK               32U
#define PARAM58_BIT6_MASK               64U
#define PARAM58_BIT7_MASK               128U


/*** PARAM59 - Parameter Register 59; 0x0000008B ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM59STR;
extern volatile PARAM59STR _PARAM59 @0x0000008B;
#define PARAM59                         _PARAM59.Byte
#define PARAM59_BIT0                    _PARAM59.Bits.BIT0
#define PARAM59_BIT1                    _PARAM59.Bits.BIT1
#define PARAM59_BIT2                    _PARAM59.Bits.BIT2
#define PARAM59_BIT3                    _PARAM59.Bits.BIT3
#define PARAM59_BIT4                    _PARAM59.Bits.BIT4
#define PARAM59_BIT5                    _PARAM59.Bits.BIT5
#define PARAM59_BIT6                    _PARAM59.Bits.BIT6
#define PARAM59_BIT7                    _PARAM59.Bits.BIT7

#define PARAM59_BIT0_MASK               1U
#define PARAM59_BIT1_MASK               2U
#define PARAM59_BIT2_MASK               4U
#define PARAM59_BIT3_MASK               8U
#define PARAM59_BIT4_MASK               16U
#define PARAM59_BIT5_MASK               32U
#define PARAM59_BIT6_MASK               64U
#define PARAM59_BIT7_MASK               128U


/*** PARAM60 - Parameter Register 60; 0x0000008C ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM60STR;
extern volatile PARAM60STR _PARAM60 @0x0000008C;
#define PARAM60                         _PARAM60.Byte
#define PARAM60_BIT0                    _PARAM60.Bits.BIT0
#define PARAM60_BIT1                    _PARAM60.Bits.BIT1
#define PARAM60_BIT2                    _PARAM60.Bits.BIT2
#define PARAM60_BIT3                    _PARAM60.Bits.BIT3
#define PARAM60_BIT4                    _PARAM60.Bits.BIT4
#define PARAM60_BIT5                    _PARAM60.Bits.BIT5
#define PARAM60_BIT6                    _PARAM60.Bits.BIT6
#define PARAM60_BIT7                    _PARAM60.Bits.BIT7

#define PARAM60_BIT0_MASK               1U
#define PARAM60_BIT1_MASK               2U
#define PARAM60_BIT2_MASK               4U
#define PARAM60_BIT3_MASK               8U
#define PARAM60_BIT4_MASK               16U
#define PARAM60_BIT5_MASK               32U
#define PARAM60_BIT6_MASK               64U
#define PARAM60_BIT7_MASK               128U


/*** PARAM61 - Parameter Register 61; 0x0000008D ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM61STR;
extern volatile PARAM61STR _PARAM61 @0x0000008D;
#define PARAM61                         _PARAM61.Byte
#define PARAM61_BIT0                    _PARAM61.Bits.BIT0
#define PARAM61_BIT1                    _PARAM61.Bits.BIT1
#define PARAM61_BIT2                    _PARAM61.Bits.BIT2
#define PARAM61_BIT3                    _PARAM61.Bits.BIT3
#define PARAM61_BIT4                    _PARAM61.Bits.BIT4
#define PARAM61_BIT5                    _PARAM61.Bits.BIT5
#define PARAM61_BIT6                    _PARAM61.Bits.BIT6
#define PARAM61_BIT7                    _PARAM61.Bits.BIT7

#define PARAM61_BIT0_MASK               1U
#define PARAM61_BIT1_MASK               2U
#define PARAM61_BIT2_MASK               4U
#define PARAM61_BIT3_MASK               8U
#define PARAM61_BIT4_MASK               16U
#define PARAM61_BIT5_MASK               32U
#define PARAM61_BIT6_MASK               64U
#define PARAM61_BIT7_MASK               128U


/*** PARAM62 - Parameter Register 62; 0x0000008E ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM62STR;
extern volatile PARAM62STR _PARAM62 @0x0000008E;
#define PARAM62                         _PARAM62.Byte
#define PARAM62_BIT0                    _PARAM62.Bits.BIT0
#define PARAM62_BIT1                    _PARAM62.Bits.BIT1
#define PARAM62_BIT2                    _PARAM62.Bits.BIT2
#define PARAM62_BIT3                    _PARAM62.Bits.BIT3
#define PARAM62_BIT4                    _PARAM62.Bits.BIT4
#define PARAM62_BIT5                    _PARAM62.Bits.BIT5
#define PARAM62_BIT6                    _PARAM62.Bits.BIT6
#define PARAM62_BIT7                    _PARAM62.Bits.BIT7

#define PARAM62_BIT0_MASK               1U
#define PARAM62_BIT1_MASK               2U
#define PARAM62_BIT2_MASK               4U
#define PARAM62_BIT3_MASK               8U
#define PARAM62_BIT4_MASK               16U
#define PARAM62_BIT5_MASK               32U
#define PARAM62_BIT6_MASK               64U
#define PARAM62_BIT7_MASK               128U


/*** PARAM63 - Parameter Register 63; 0x0000008F ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
} PARAM63STR;
extern volatile PARAM63STR _PARAM63 @0x0000008F;
#define PARAM63                         _PARAM63.Byte
#define PARAM63_BIT0                    _PARAM63.Bits.BIT0
#define PARAM63_BIT1                    _PARAM63.Bits.BIT1
#define PARAM63_BIT2                    _PARAM63.Bits.BIT2
#define PARAM63_BIT3                    _PARAM63.Bits.BIT3
#define PARAM63_BIT4                    _PARAM63.Bits.BIT4
#define PARAM63_BIT5                    _PARAM63.Bits.BIT5
#define PARAM63_BIT6                    _PARAM63.Bits.BIT6
#define PARAM63_BIT7                    _PARAM63.Bits.BIT7

#define PARAM63_BIT0_MASK               1U
#define PARAM63_BIT1_MASK               2U
#define PARAM63_BIT2_MASK               4U
#define PARAM63_BIT3_MASK               8U
#define PARAM63_BIT4_MASK               16U
#define PARAM63_BIT5_MASK               32U
#define PARAM63_BIT6_MASK               64U
#define PARAM63_BIT7_MASK               128U


/*** SRS - System Reset Status Register; 0x00001800 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte LVD         :1;                                       /* Low Voltage Detect */
    byte PWU         :1;                                       /* Programmable Wakeup */
    byte ILAD        :1;                                       /* Illegal Address */
    byte ILOP        :1;                                       /* Illegal Opcode */
    byte COP         :1;                                       /* Computer Operating Properly (COP) Watchdog */
    byte PIN         :1;                                       /* External Reset Pin */
    byte POR         :1;                                       /* Power-On Reset */
  } Bits;
} SRSSTR;
extern volatile SRSSTR _SRS @0x00001800;
#define SRS                             _SRS.Byte
#define SRS_LVD                         _SRS.Bits.LVD
#define SRS_PWU                         _SRS.Bits.PWU
#define SRS_ILAD                        _SRS.Bits.ILAD
#define SRS_ILOP                        _SRS.Bits.ILOP
#define SRS_COP                         _SRS.Bits.COP
#define SRS_PIN                         _SRS.Bits.PIN
#define SRS_POR                         _SRS.Bits.POR

#define SRS_LVD_MASK                    2U
#define SRS_PWU_MASK                    4U
#define SRS_ILAD_MASK                   8U
#define SRS_ILOP_MASK                   16U
#define SRS_COP_MASK                    32U
#define SRS_PIN_MASK                    64U
#define SRS_POR_MASK                    128U


/*** SBDFR - System Background Debug Force Reset Register; 0x00001801 ***/
typedef union {
  byte Byte;
  struct {
    byte BDFR        :1;                                       /* Background Debug Force Reset */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} SBDFRSTR;
extern volatile SBDFRSTR _SBDFR @0x00001801;
#define SBDFR                           _SBDFR.Byte
#define SBDFR_BDFR                      _SBDFR.Bits.BDFR

#define SBDFR_BDFR_MASK                 1U


/*** SIMOPT1 - System Options Register 1; 0x00001802 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte BKGDPE      :1;                                       /* Background Debug Mode Pin Enable */
    byte TRH         :1;                                       /* Temperature Restart Level */
    byte TRE         :1;                                       /* Temperature Restart Wakeup Enable */
    byte RFEN        :1;                                       /* RF Module Enable */
    byte STOPE       :1;                                       /* Stop Mode Enable */
    byte COPCLKS     :1;                                       /* COP Clock Selection */
    byte COPE        :1;                                       /* COP Watchdog Enable */
  } Bits;
} SIMOPT1STR;
extern volatile SIMOPT1STR _SIMOPT1 @0x00001802;
#define SIMOPT1                         _SIMOPT1.Byte
#define SIMOPT1_BKGDPE                  _SIMOPT1.Bits.BKGDPE
#define SIMOPT1_TRH                     _SIMOPT1.Bits.TRH
#define SIMOPT1_TRE                     _SIMOPT1.Bits.TRE
#define SIMOPT1_RFEN                    _SIMOPT1.Bits.RFEN
#define SIMOPT1_STOPE                   _SIMOPT1.Bits.STOPE
#define SIMOPT1_COPCLKS                 _SIMOPT1.Bits.COPCLKS
#define SIMOPT1_COPE                    _SIMOPT1.Bits.COPE

#define SIMOPT1_BKGDPE_MASK             2U
#define SIMOPT1_TRH_MASK                4U
#define SIMOPT1_TRE_MASK                8U
#define SIMOPT1_RFEN_MASK               16U
#define SIMOPT1_STOPE_MASK              32U
#define SIMOPT1_COPCLKS_MASK            64U
#define SIMOPT1_COPE_MASK               128U


/*** SIMOPT2 - System Options Register 2; 0x00001803 ***/
typedef union {
  byte Byte;
  struct {
    byte BUSCLKS0    :1;                                       /* Bus Clock Select - HFO divide by, bit 0 */
    byte BUSCLKS1    :1;                                       /* Bus Clock Select - HFO divide by, bit 1 */
    byte TCLKDIV     :1;                                       /* Timer Clock Divider */
    byte LFOSEL      :1;                                       /* LFO Selected */
    byte COPT0       :1;                                       /* COP Watchdog Timeout, bit 0 */
    byte COPT1       :1;                                       /* COP Watchdog Timeout, bit 1 */
    byte COPT2       :1;                                       /* COP Watchdog Timeout, bit 2 */
    byte             :1; 
  } Bits;
  struct {
    byte grpBUSCLKS :2;
    byte         :1;
    byte         :1;
    byte grpCOPT :3;
    byte         :1;
  } MergedBits;
} SIMOPT2STR;
extern volatile SIMOPT2STR _SIMOPT2 @0x00001803;
#define SIMOPT2                         _SIMOPT2.Byte
#define SIMOPT2_BUSCLKS0                _SIMOPT2.Bits.BUSCLKS0
#define SIMOPT2_BUSCLKS1                _SIMOPT2.Bits.BUSCLKS1
#define SIMOPT2_TCLKDIV                 _SIMOPT2.Bits.TCLKDIV
#define SIMOPT2_LFOSEL                  _SIMOPT2.Bits.LFOSEL
#define SIMOPT2_COPT0                   _SIMOPT2.Bits.COPT0
#define SIMOPT2_COPT1                   _SIMOPT2.Bits.COPT1
#define SIMOPT2_COPT2                   _SIMOPT2.Bits.COPT2
#define SIMOPT2_BUSCLKS                 _SIMOPT2.MergedBits.grpBUSCLKS
#define SIMOPT2_COPT                    _SIMOPT2.MergedBits.grpCOPT

#define SIMOPT2_BUSCLKS0_MASK           1U
#define SIMOPT2_BUSCLKS1_MASK           2U
#define SIMOPT2_TCLKDIV_MASK            4U
#define SIMOPT2_LFOSEL_MASK             8U
#define SIMOPT2_COPT0_MASK              16U
#define SIMOPT2_COPT1_MASK              32U
#define SIMOPT2_COPT2_MASK              64U
#define SIMOPT2_BUSCLKS_MASK            3U
#define SIMOPT2_BUSCLKS_BITNUM          0U
#define SIMOPT2_COPT_MASK               112U
#define SIMOPT2_COPT_BITNUM             4U


/*** SDID - System Device Identification Register; 0x00001806 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SDIDH - System Device Identification Register High; 0x00001806 ***/
    union {
      byte Byte;
      struct {
        byte ID8         :1;                                       /* Part Identification Number, bit 8 */
        byte ID9         :1;                                       /* Part Identification Number, bit 9 */
        byte ID10        :1;                                       /* Part Identification Number, bit 10 */
        byte ID11        :1;                                       /* Part Identification Number, bit 11 */
        byte REV0        :1;                                       /* Revision Number, bit 0 */
        byte REV1        :1;                                       /* Revision Number, bit 1 */
        byte REV2        :1;                                       /* Revision Number, bit 2 */
        byte REV3        :1;                                       /* Revision Number, bit 3 */
      } Bits;
      struct {
        byte grpID_8 :4;
        byte grpREV :4;
      } MergedBits;
    } SDIDHSTR;
    #define SDIDH                       _SDID.Overlap_STR.SDIDHSTR.Byte
    #define SDIDH_ID8                   _SDID.Overlap_STR.SDIDHSTR.Bits.ID8
    #define SDIDH_ID9                   _SDID.Overlap_STR.SDIDHSTR.Bits.ID9
    #define SDIDH_ID10                  _SDID.Overlap_STR.SDIDHSTR.Bits.ID10
    #define SDIDH_ID11                  _SDID.Overlap_STR.SDIDHSTR.Bits.ID11
    #define SDIDH_REV0                  _SDID.Overlap_STR.SDIDHSTR.Bits.REV0
    #define SDIDH_REV1                  _SDID.Overlap_STR.SDIDHSTR.Bits.REV1
    #define SDIDH_REV2                  _SDID.Overlap_STR.SDIDHSTR.Bits.REV2
    #define SDIDH_REV3                  _SDID.Overlap_STR.SDIDHSTR.Bits.REV3
    #define SDIDH_ID_8                  _SDID.Overlap_STR.SDIDHSTR.MergedBits.grpID_8
    #define SDIDH_REV                   _SDID.Overlap_STR.SDIDHSTR.MergedBits.grpREV
    #define SDIDH_ID                    SDIDH_ID_8
    
    #define SDIDH_ID8_MASK              1U
    #define SDIDH_ID9_MASK              2U
    #define SDIDH_ID10_MASK             4U
    #define SDIDH_ID11_MASK             8U
    #define SDIDH_REV0_MASK             16U
    #define SDIDH_REV1_MASK             32U
    #define SDIDH_REV2_MASK             64U
    #define SDIDH_REV3_MASK             128U
    #define SDIDH_ID_8_MASK             15U
    #define SDIDH_ID_8_BITNUM           0U
    #define SDIDH_REV_MASK              240U
    #define SDIDH_REV_BITNUM            4U
    

    /*** SDIDL - System Device Identification Register Low; 0x00001807 ***/
    union {
      byte Byte;
      struct {
        byte ID0         :1;                                       /* Part Identification Number, bit 0 */
        byte ID1         :1;                                       /* Part Identification Number, bit 1 */
        byte ID2         :1;                                       /* Part Identification Number, bit 2 */
        byte ID3         :1;                                       /* Part Identification Number, bit 3 */
        byte ID4         :1;                                       /* Part Identification Number, bit 4 */
        byte ID5         :1;                                       /* Part Identification Number, bit 5 */
        byte ID6         :1;                                       /* Part Identification Number, bit 6 */
        byte ID7         :1;                                       /* Part Identification Number, bit 7 */
      } Bits;
    } SDIDLSTR;
    #define SDIDL                       _SDID.Overlap_STR.SDIDLSTR.Byte
    #define SDIDL_ID0                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID0
    #define SDIDL_ID1                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID1
    #define SDIDL_ID2                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID2
    #define SDIDL_ID3                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID3
    #define SDIDL_ID4                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID4
    #define SDIDL_ID5                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID5
    #define SDIDL_ID6                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID6
    #define SDIDL_ID7                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID7
    
    #define SDIDL_ID0_MASK              1U
    #define SDIDL_ID1_MASK              2U
    #define SDIDL_ID2_MASK              4U
    #define SDIDL_ID3_MASK              8U
    #define SDIDL_ID4_MASK              16U
    #define SDIDL_ID5_MASK              32U
    #define SDIDL_ID6_MASK              64U
    #define SDIDL_ID7_MASK              128U
    
  } Overlap_STR;

} SDIDSTR;
extern volatile SDIDSTR _SDID @0x00001806;
#define SDID                            _SDID.Word


/*** SRTISC - System Real-Time Interrupt Status and Control Register; 0x00001808 ***/
typedef union {
  byte Byte;
  struct {
    byte RTIS0       :1;                                       /* Real-Time Interrupt Delay Selects, bit 0 */
    byte RTIS1       :1;                                       /* Real-Time Interrupt Delay Selects, bit 1 */
    byte RTIS2       :1;                                       /* Real-Time Interrupt Delay Selects, bit 2 */
    byte             :1; 
    byte RTIE        :1;                                       /* Real-Time Interrupt Enable */
    byte RTICLKS     :1;                                       /* Real-Time Interrupt Clock Select */
    byte RTIACK      :1;                                       /* Real-Time Interrupt Acknowledge */
    byte RTIF        :1;                                       /* Real-Time Interrupt Flag */
  } Bits;
  struct {
    byte grpRTIS :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} SRTISCSTR;
extern volatile SRTISCSTR _SRTISC @0x00001808;
#define SRTISC                          _SRTISC.Byte
#define SRTISC_RTIS0                    _SRTISC.Bits.RTIS0
#define SRTISC_RTIS1                    _SRTISC.Bits.RTIS1
#define SRTISC_RTIS2                    _SRTISC.Bits.RTIS2
#define SRTISC_RTIE                     _SRTISC.Bits.RTIE
#define SRTISC_RTICLKS                  _SRTISC.Bits.RTICLKS
#define SRTISC_RTIACK                   _SRTISC.Bits.RTIACK
#define SRTISC_RTIF                     _SRTISC.Bits.RTIF
#define SRTISC_RTIS                     _SRTISC.MergedBits.grpRTIS

#define SRTISC_RTIS0_MASK               1U
#define SRTISC_RTIS1_MASK               2U
#define SRTISC_RTIS2_MASK               4U
#define SRTISC_RTIE_MASK                16U
#define SRTISC_RTICLKS_MASK             32U
#define SRTISC_RTIACK_MASK              64U
#define SRTISC_RTIF_MASK                128U
#define SRTISC_RTIS_MASK                7U
#define SRTISC_RTIS_BITNUM              0U


/*** SPMSC1 - System Power Management Status and Control 1 Register; 0x00001809 ***/
typedef union {
  byte Byte;
  struct {
    byte BGBE        :1;                                       /* Bandgap Buffer Enable */
    byte             :1; 
    byte LVDE        :1;                                       /* Low-Voltage Detect Enable */
    byte LVDSE       :1;                                       /* Low-Voltage Detect Stop Enable */
    byte LVDRE       :1;                                       /* Low-Voltage Detect Reset Enable */
    byte LVDIE       :1;                                       /* Low-Voltage Detect Interrupt Enable */
    byte LVDACK      :1;                                       /* Low-Voltage Detect Acknowledge */
    byte LVDF        :1;                                       /* Low-Voltage Detect Flag */
  } Bits;
} SPMSC1STR;
extern volatile SPMSC1STR _SPMSC1 @0x00001809;
#define SPMSC1                          _SPMSC1.Byte
#define SPMSC1_BGBE                     _SPMSC1.Bits.BGBE
#define SPMSC1_LVDE                     _SPMSC1.Bits.LVDE
#define SPMSC1_LVDSE                    _SPMSC1.Bits.LVDSE
#define SPMSC1_LVDRE                    _SPMSC1.Bits.LVDRE
#define SPMSC1_LVDIE                    _SPMSC1.Bits.LVDIE
#define SPMSC1_LVDACK                   _SPMSC1.Bits.LVDACK
#define SPMSC1_LVDF                     _SPMSC1.Bits.LVDF

#define SPMSC1_BGBE_MASK                1U
#define SPMSC1_LVDE_MASK                4U
#define SPMSC1_LVDSE_MASK               8U
#define SPMSC1_LVDRE_MASK               16U
#define SPMSC1_LVDIE_MASK               32U
#define SPMSC1_LVDACK_MASK              64U
#define SPMSC1_LVDF_MASK                128U


/*** SPMSC2 - System Power Management Status and Control 2 Register; 0x0000180A ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte PDC         :1;                                       /* Power Down Control */
    byte PPDACK      :1;                                       /* Partial Power Down Acknowledge */
    byte             :1; 
    byte PDF         :1;                                       /* Power Down Flag */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} SPMSC2STR;
extern volatile SPMSC2STR _SPMSC2 @0x0000180A;
#define SPMSC2                          _SPMSC2.Byte
#define SPMSC2_PDC                      _SPMSC2.Bits.PDC
#define SPMSC2_PPDACK                   _SPMSC2.Bits.PPDACK
#define SPMSC2_PDF                      _SPMSC2.Bits.PDF

#define SPMSC2_PDC_MASK                 2U
#define SPMSC2_PPDACK_MASK              4U
#define SPMSC2_PDF_MASK                 16U


/*** SPMSC3 - System Power Management Status and Control 3 Register; 0x0000180C ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte LVWV        :1;                                       /* Low-Voltage Warning Voltage Select */
    byte LVDV        :1;                                       /* Low-Voltage Detect Voltage Select */
    byte LVWACK      :1;                                       /* Low-Voltage Warning Acknowledge */
    byte LVWF        :1;                                       /* Low-Voltage Warning Flag */
  } Bits;
} SPMSC3STR;
extern volatile SPMSC3STR _SPMSC3 @0x0000180C;
#define SPMSC3                          _SPMSC3.Byte
#define SPMSC3_LVWV                     _SPMSC3.Bits.LVWV
#define SPMSC3_LVDV                     _SPMSC3.Bits.LVDV
#define SPMSC3_LVWACK                   _SPMSC3.Bits.LVWACK
#define SPMSC3_LVWF                     _SPMSC3.Bits.LVWF

#define SPMSC3_LVWV_MASK                16U
#define SPMSC3_LVDV_MASK                32U
#define SPMSC3_LVWACK_MASK              64U
#define SPMSC3_LVWF_MASK                128U


/*** SIMSES - SIM Stop Exit Status; 0x0000180D ***/
typedef union {
  byte Byte;
  struct {
    byte RFF         :1;                                       /* RFM Flag */
    byte LFF         :1;                                       /* LFR Flag */
    byte PWUF        :1;                                       /* PWU Flag */
    byte TRF         :1;                                       /* Temperature Restart Flag */
    byte IRQF        :1;                                       /* IRQ Flag */
    byte KBF         :1;                                       /* Keyboard Flag */
    byte             :1; 
    byte             :1; 
  } Bits;
} SIMSESSTR;
extern volatile SIMSESSTR _SIMSES @0x0000180D;
#define SIMSES                          _SIMSES.Byte
#define SIMSES_RFF                      _SIMSES.Bits.RFF
#define SIMSES_LFF                      _SIMSES.Bits.LFF
#define SIMSES_PWUF                     _SIMSES.Bits.PWUF
#define SIMSES_TRF                      _SIMSES.Bits.TRF
#define SIMSES_IRQF                     _SIMSES.Bits.IRQF
#define SIMSES_KBF                      _SIMSES.Bits.KBF

#define SIMSES_RFF_MASK                 1U
#define SIMSES_LFF_MASK                 2U
#define SIMSES_PWUF_MASK                4U
#define SIMSES_TRF_MASK                 8U
#define SIMSES_IRQF_MASK                16U
#define SIMSES_KBF_MASK                 32U


/*** SOTRM - System Oscillator Trim Register; 0x0000180E ***/
typedef union {
  byte Byte;
} SOTRMSTR;
extern volatile SOTRMSTR _SOTRM @0x0000180E;
#define SOTRM                           _SOTRM.Byte


/*** SIMTST - SIM Test Register; 0x0000180F ***/
typedef union {
  byte Byte;
  struct {
    byte TRO         :1;                                       /* Temperature Restart */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte TRH0        :1;                                       /* , bit 0 */
    byte TRH1        :1;                                       /* , bit 1 */
    byte TRH2        :1;                                       /* , bit 2 */
    byte             :1; 
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpTRH  :3;
    byte         :1;
  } MergedBits;
} SIMTSTSTR;
extern volatile SIMTSTSTR _SIMTST @0x0000180F;
#define SIMTST                          _SIMTST.Byte
#define SIMTST_TRO                      _SIMTST.Bits.TRO
#define SIMTST_TRH0                     _SIMTST.Bits.TRH0
#define SIMTST_TRH1                     _SIMTST.Bits.TRH1
#define SIMTST_TRH2                     _SIMTST.Bits.TRH2
#define SIMTST_TRH                      _SIMTST.MergedBits.grpTRH

#define SIMTST_TRO_MASK                 1U
#define SIMTST_TRH0_MASK                16U
#define SIMTST_TRH1_MASK                32U
#define SIMTST_TRH2_MASK                64U
#define SIMTST_TRH_MASK                 112U
#define SIMTST_TRH_BITNUM               4U


/*** FCDIV - FLASH Clock Divider Register; 0x00001820 ***/
typedef union {
  byte Byte;
  struct {
    byte DIV0        :1;                                       /* Divisor for FLASH Clock Divider, bit 0 */
    byte DIV1        :1;                                       /* Divisor for FLASH Clock Divider, bit 1 */
    byte DIV2        :1;                                       /* Divisor for FLASH Clock Divider, bit 2 */
    byte DIV3        :1;                                       /* Divisor for FLASH Clock Divider, bit 3 */
    byte DIV4        :1;                                       /* Divisor for FLASH Clock Divider, bit 4 */
    byte DIV5        :1;                                       /* Divisor for FLASH Clock Divider, bit 5 */
    byte PRDIV8      :1;                                       /* Prescale (Divide) FLASH Clock by 8 */
    byte DIVLD       :1;                                       /* Divisor Loaded Status Flag */
  } Bits;
  struct {
    byte grpDIV  :6;
    byte grpPRDIV_8 :1;
    byte         :1;
  } MergedBits;
} FCDIVSTR;
extern volatile FCDIVSTR _FCDIV @0x00001820;
#define FCDIV                           _FCDIV.Byte
#define FCDIV_DIV0                      _FCDIV.Bits.DIV0
#define FCDIV_DIV1                      _FCDIV.Bits.DIV1
#define FCDIV_DIV2                      _FCDIV.Bits.DIV2
#define FCDIV_DIV3                      _FCDIV.Bits.DIV3
#define FCDIV_DIV4                      _FCDIV.Bits.DIV4
#define FCDIV_DIV5                      _FCDIV.Bits.DIV5
#define FCDIV_PRDIV8                    _FCDIV.Bits.PRDIV8
#define FCDIV_DIVLD                     _FCDIV.Bits.DIVLD
#define FCDIV_DIV                       _FCDIV.MergedBits.grpDIV

#define FCDIV_DIV0_MASK                 1U
#define FCDIV_DIV1_MASK                 2U
#define FCDIV_DIV2_MASK                 4U
#define FCDIV_DIV3_MASK                 8U
#define FCDIV_DIV4_MASK                 16U
#define FCDIV_DIV5_MASK                 32U
#define FCDIV_PRDIV8_MASK               64U
#define FCDIV_DIVLD_MASK                128U
#define FCDIV_DIV_MASK                  63U
#define FCDIV_DIV_BITNUM                0U


/*** FOPT - FLASH Options Register; 0x00001821 ***/
typedef union {
  byte Byte;
  struct {
    byte SEC00       :1;                                       /* Security State Code, bit 0 */
    byte SEC01       :1;                                       /* Security State Code, bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte FNORED      :1;                                       /* Vector Redirection Disable */
    byte KEYEN       :1;                                       /* Backdoor Key Mechanism Enable */
  } Bits;
  struct {
    byte grpSEC0 :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} FOPTSTR;
extern volatile FOPTSTR _FOPT @0x00001821;
#define FOPT                            _FOPT.Byte
#define FOPT_SEC00                      _FOPT.Bits.SEC00
#define FOPT_SEC01                      _FOPT.Bits.SEC01
#define FOPT_FNORED                     _FOPT.Bits.FNORED
#define FOPT_KEYEN                      _FOPT.Bits.KEYEN
#define FOPT_SEC0                       _FOPT.MergedBits.grpSEC0

#define FOPT_SEC00_MASK                 1U
#define FOPT_SEC01_MASK                 2U
#define FOPT_FNORED_MASK                64U
#define FOPT_KEYEN_MASK                 128U
#define FOPT_SEC0_MASK                  3U
#define FOPT_SEC0_BITNUM                0U


/*** FCNFG - FLASH Configuration Register; 0x00001823 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte KEYACC      :1;                                       /* Enable Writing of Access Key */
    byte             :1; 
    byte             :1; 
  } Bits;
} FCNFGSTR;
extern volatile FCNFGSTR _FCNFG @0x00001823;
#define FCNFG                           _FCNFG.Byte
#define FCNFG_KEYACC                    _FCNFG.Bits.KEYACC

#define FCNFG_KEYACC_MASK               32U


/*** FPROT - FLASH Protection Register; 0x00001824 ***/
typedef union {
  byte Byte;
  struct {
    byte FPDIS       :1;                                       /* FLASH Protection Disable */
    byte FPS1        :1;                                       /* FLASH Protect Select Bit 1 */
    byte FPS2        :1;                                       /* FLASH Protect Select Bit 2 */
    byte FPS3        :1;                                       /* FLASH Protect Select Bit 3 */
    byte FPS4        :1;                                       /* FLASH Protect Select Bit 4 */
    byte FPS5        :1;                                       /* FLASH Protect Select Bit 5 */
    byte FPS6        :1;                                       /* FLASH Protect Select Bit 6 */
    byte FPS7        :1;                                       /* FLASH Protect Select Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte grpFPS_1 :7;
  } MergedBits;
} FPROTSTR;
extern volatile FPROTSTR _FPROT @0x00001824;
#define FPROT                           _FPROT.Byte
#define FPROT_FPDIS                     _FPROT.Bits.FPDIS
#define FPROT_FPS1                      _FPROT.Bits.FPS1
#define FPROT_FPS2                      _FPROT.Bits.FPS2
#define FPROT_FPS3                      _FPROT.Bits.FPS3
#define FPROT_FPS4                      _FPROT.Bits.FPS4
#define FPROT_FPS5                      _FPROT.Bits.FPS5
#define FPROT_FPS6                      _FPROT.Bits.FPS6
#define FPROT_FPS7                      _FPROT.Bits.FPS7
#define FPROT_FPS_1                     _FPROT.MergedBits.grpFPS_1
#define FPROT_FPS                       FPROT_FPS_1

#define FPROT_FPDIS_MASK                1U
#define FPROT_FPS1_MASK                 2U
#define FPROT_FPS2_MASK                 4U
#define FPROT_FPS3_MASK                 8U
#define FPROT_FPS4_MASK                 16U
#define FPROT_FPS5_MASK                 32U
#define FPROT_FPS6_MASK                 64U
#define FPROT_FPS7_MASK                 128U
#define FPROT_FPS_1_MASK                254U
#define FPROT_FPS_1_BITNUM              1U


/*** FSTAT - Flash Status Register; 0x00001825 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte FBLANK      :1;                                       /* FLASH Flag Indicating the Erase Verify Operation Status */
    byte             :1; 
    byte FACCERR     :1;                                       /* FLASH Access Error Flag */
    byte FPVIOL      :1;                                       /* FLASH Protection Violation Flag */
    byte FCCF        :1;                                       /* FLASH Command Complete Interrupt Flag */
    byte FCBEF       :1;                                       /* FLASH Command Buffer Empty Flag */
  } Bits;
} FSTATSTR;
extern volatile FSTATSTR _FSTAT @0x00001825;
#define FSTAT                           _FSTAT.Byte
#define FSTAT_FBLANK                    _FSTAT.Bits.FBLANK
#define FSTAT_FACCERR                   _FSTAT.Bits.FACCERR
#define FSTAT_FPVIOL                    _FSTAT.Bits.FPVIOL
#define FSTAT_FCCF                      _FSTAT.Bits.FCCF
#define FSTAT_FCBEF                     _FSTAT.Bits.FCBEF

#define FSTAT_FBLANK_MASK               4U
#define FSTAT_FACCERR_MASK              16U
#define FSTAT_FPVIOL_MASK               32U
#define FSTAT_FCCF_MASK                 64U
#define FSTAT_FCBEF_MASK                128U


/*** FCMD - FLASH Command Register; 0x00001826 ***/
typedef union {
  byte Byte;
  struct {
    byte FCMD0       :1;                                       /* FLASH Command Bit 0 */
    byte FCMD1       :1;                                       /* FLASH Command Bit 1 */
    byte FCMD2       :1;                                       /* FLASH Command Bit 2 */
    byte FCMD3       :1;                                       /* FLASH Command Bit 3 */
    byte FCMD4       :1;                                       /* FLASH Command Bit 4 */
    byte FCMD5       :1;                                       /* FLASH Command Bit 5 */
    byte FCMD6       :1;                                       /* FLASH Command Bit 6 */
    byte FCMD7       :1;                                       /* FLASH Command Bit 7 */
  } Bits;
} FCMDSTR;
extern volatile FCMDSTR _FCMD @0x00001826;
#define FCMD                            _FCMD.Byte
#define FCMD_FCMD0                      _FCMD.Bits.FCMD0
#define FCMD_FCMD1                      _FCMD.Bits.FCMD1
#define FCMD_FCMD2                      _FCMD.Bits.FCMD2
#define FCMD_FCMD3                      _FCMD.Bits.FCMD3
#define FCMD_FCMD4                      _FCMD.Bits.FCMD4
#define FCMD_FCMD5                      _FCMD.Bits.FCMD5
#define FCMD_FCMD6                      _FCMD.Bits.FCMD6
#define FCMD_FCMD7                      _FCMD.Bits.FCMD7

#define FCMD_FCMD0_MASK                 1U
#define FCMD_FCMD1_MASK                 2U
#define FCMD_FCMD2_MASK                 4U
#define FCMD_FCMD3_MASK                 8U
#define FCMD_FCMD4_MASK                 16U
#define FCMD_FCMD5_MASK                 32U
#define FCMD_FCMD6_MASK                 64U
#define FCMD_FCMD7_MASK                 128U


/*** NVBACKKEY0 - Backdoor Comparison Key 0; 0x0000FFB0 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 7 */
  } Bits;
} NVBACKKEY0STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY0_INIT @0x0000FFB0 = <NVBACKKEY0_INITVAL>; */
#define _NVBACKKEY0 (*(const NVBACKKEY0STR * __far)0x0000FFB0)
#define NVBACKKEY0                      _NVBACKKEY0.Byte
#define NVBACKKEY0_KEY0                 _NVBACKKEY0.Bits.KEY0
#define NVBACKKEY0_KEY1                 _NVBACKKEY0.Bits.KEY1
#define NVBACKKEY0_KEY2                 _NVBACKKEY0.Bits.KEY2
#define NVBACKKEY0_KEY3                 _NVBACKKEY0.Bits.KEY3
#define NVBACKKEY0_KEY4                 _NVBACKKEY0.Bits.KEY4
#define NVBACKKEY0_KEY5                 _NVBACKKEY0.Bits.KEY5
#define NVBACKKEY0_KEY6                 _NVBACKKEY0.Bits.KEY6
#define NVBACKKEY0_KEY7                 _NVBACKKEY0.Bits.KEY7
/* NVBACKKEY_ARR: Access 8 NVBACKKEYx registers in an array */
#define NVBACKKEY_ARR                   ((volatile byte * __far) &NVBACKKEY0)

#define NVBACKKEY0_KEY0_MASK            1U
#define NVBACKKEY0_KEY1_MASK            2U
#define NVBACKKEY0_KEY2_MASK            4U
#define NVBACKKEY0_KEY3_MASK            8U
#define NVBACKKEY0_KEY4_MASK            16U
#define NVBACKKEY0_KEY5_MASK            32U
#define NVBACKKEY0_KEY6_MASK            64U
#define NVBACKKEY0_KEY7_MASK            128U


/*** NVBACKKEY1 - Backdoor Comparison Key 1; 0x0000FFB1 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 7 */
  } Bits;
} NVBACKKEY1STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY1_INIT @0x0000FFB1 = <NVBACKKEY1_INITVAL>; */
#define _NVBACKKEY1 (*(const NVBACKKEY1STR * __far)0x0000FFB1)
#define NVBACKKEY1                      _NVBACKKEY1.Byte
#define NVBACKKEY1_KEY0                 _NVBACKKEY1.Bits.KEY0
#define NVBACKKEY1_KEY1                 _NVBACKKEY1.Bits.KEY1
#define NVBACKKEY1_KEY2                 _NVBACKKEY1.Bits.KEY2
#define NVBACKKEY1_KEY3                 _NVBACKKEY1.Bits.KEY3
#define NVBACKKEY1_KEY4                 _NVBACKKEY1.Bits.KEY4
#define NVBACKKEY1_KEY5                 _NVBACKKEY1.Bits.KEY5
#define NVBACKKEY1_KEY6                 _NVBACKKEY1.Bits.KEY6
#define NVBACKKEY1_KEY7                 _NVBACKKEY1.Bits.KEY7

#define NVBACKKEY1_KEY0_MASK            1U
#define NVBACKKEY1_KEY1_MASK            2U
#define NVBACKKEY1_KEY2_MASK            4U
#define NVBACKKEY1_KEY3_MASK            8U
#define NVBACKKEY1_KEY4_MASK            16U
#define NVBACKKEY1_KEY5_MASK            32U
#define NVBACKKEY1_KEY6_MASK            64U
#define NVBACKKEY1_KEY7_MASK            128U


/*** NVBACKKEY2 - Backdoor Comparison Key 2; 0x0000FFB2 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 7 */
  } Bits;
} NVBACKKEY2STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY2_INIT @0x0000FFB2 = <NVBACKKEY2_INITVAL>; */
#define _NVBACKKEY2 (*(const NVBACKKEY2STR * __far)0x0000FFB2)
#define NVBACKKEY2                      _NVBACKKEY2.Byte
#define NVBACKKEY2_KEY0                 _NVBACKKEY2.Bits.KEY0
#define NVBACKKEY2_KEY1                 _NVBACKKEY2.Bits.KEY1
#define NVBACKKEY2_KEY2                 _NVBACKKEY2.Bits.KEY2
#define NVBACKKEY2_KEY3                 _NVBACKKEY2.Bits.KEY3
#define NVBACKKEY2_KEY4                 _NVBACKKEY2.Bits.KEY4
#define NVBACKKEY2_KEY5                 _NVBACKKEY2.Bits.KEY5
#define NVBACKKEY2_KEY6                 _NVBACKKEY2.Bits.KEY6
#define NVBACKKEY2_KEY7                 _NVBACKKEY2.Bits.KEY7

#define NVBACKKEY2_KEY0_MASK            1U
#define NVBACKKEY2_KEY1_MASK            2U
#define NVBACKKEY2_KEY2_MASK            4U
#define NVBACKKEY2_KEY3_MASK            8U
#define NVBACKKEY2_KEY4_MASK            16U
#define NVBACKKEY2_KEY5_MASK            32U
#define NVBACKKEY2_KEY6_MASK            64U
#define NVBACKKEY2_KEY7_MASK            128U


/*** NVBACKKEY3 - Backdoor Comparison Key 3; 0x0000FFB3 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 7 */
  } Bits;
} NVBACKKEY3STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY3_INIT @0x0000FFB3 = <NVBACKKEY3_INITVAL>; */
#define _NVBACKKEY3 (*(const NVBACKKEY3STR * __far)0x0000FFB3)
#define NVBACKKEY3                      _NVBACKKEY3.Byte
#define NVBACKKEY3_KEY0                 _NVBACKKEY3.Bits.KEY0
#define NVBACKKEY3_KEY1                 _NVBACKKEY3.Bits.KEY1
#define NVBACKKEY3_KEY2                 _NVBACKKEY3.Bits.KEY2
#define NVBACKKEY3_KEY3                 _NVBACKKEY3.Bits.KEY3
#define NVBACKKEY3_KEY4                 _NVBACKKEY3.Bits.KEY4
#define NVBACKKEY3_KEY5                 _NVBACKKEY3.Bits.KEY5
#define NVBACKKEY3_KEY6                 _NVBACKKEY3.Bits.KEY6
#define NVBACKKEY3_KEY7                 _NVBACKKEY3.Bits.KEY7

#define NVBACKKEY3_KEY0_MASK            1U
#define NVBACKKEY3_KEY1_MASK            2U
#define NVBACKKEY3_KEY2_MASK            4U
#define NVBACKKEY3_KEY3_MASK            8U
#define NVBACKKEY3_KEY4_MASK            16U
#define NVBACKKEY3_KEY5_MASK            32U
#define NVBACKKEY3_KEY6_MASK            64U
#define NVBACKKEY3_KEY7_MASK            128U


/*** NVBACKKEY4 - Backdoor Comparison Key 4; 0x0000FFB4 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 7 */
  } Bits;
} NVBACKKEY4STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY4_INIT @0x0000FFB4 = <NVBACKKEY4_INITVAL>; */
#define _NVBACKKEY4 (*(const NVBACKKEY4STR * __far)0x0000FFB4)
#define NVBACKKEY4                      _NVBACKKEY4.Byte
#define NVBACKKEY4_KEY0                 _NVBACKKEY4.Bits.KEY0
#define NVBACKKEY4_KEY1                 _NVBACKKEY4.Bits.KEY1
#define NVBACKKEY4_KEY2                 _NVBACKKEY4.Bits.KEY2
#define NVBACKKEY4_KEY3                 _NVBACKKEY4.Bits.KEY3
#define NVBACKKEY4_KEY4                 _NVBACKKEY4.Bits.KEY4
#define NVBACKKEY4_KEY5                 _NVBACKKEY4.Bits.KEY5
#define NVBACKKEY4_KEY6                 _NVBACKKEY4.Bits.KEY6
#define NVBACKKEY4_KEY7                 _NVBACKKEY4.Bits.KEY7

#define NVBACKKEY4_KEY0_MASK            1U
#define NVBACKKEY4_KEY1_MASK            2U
#define NVBACKKEY4_KEY2_MASK            4U
#define NVBACKKEY4_KEY3_MASK            8U
#define NVBACKKEY4_KEY4_MASK            16U
#define NVBACKKEY4_KEY5_MASK            32U
#define NVBACKKEY4_KEY6_MASK            64U
#define NVBACKKEY4_KEY7_MASK            128U


/*** NVBACKKEY5 - Backdoor Comparison Key 5; 0x0000FFB5 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 7 */
  } Bits;
} NVBACKKEY5STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY5_INIT @0x0000FFB5 = <NVBACKKEY5_INITVAL>; */
#define _NVBACKKEY5 (*(const NVBACKKEY5STR * __far)0x0000FFB5)
#define NVBACKKEY5                      _NVBACKKEY5.Byte
#define NVBACKKEY5_KEY0                 _NVBACKKEY5.Bits.KEY0
#define NVBACKKEY5_KEY1                 _NVBACKKEY5.Bits.KEY1
#define NVBACKKEY5_KEY2                 _NVBACKKEY5.Bits.KEY2
#define NVBACKKEY5_KEY3                 _NVBACKKEY5.Bits.KEY3
#define NVBACKKEY5_KEY4                 _NVBACKKEY5.Bits.KEY4
#define NVBACKKEY5_KEY5                 _NVBACKKEY5.Bits.KEY5
#define NVBACKKEY5_KEY6                 _NVBACKKEY5.Bits.KEY6
#define NVBACKKEY5_KEY7                 _NVBACKKEY5.Bits.KEY7

#define NVBACKKEY5_KEY0_MASK            1U
#define NVBACKKEY5_KEY1_MASK            2U
#define NVBACKKEY5_KEY2_MASK            4U
#define NVBACKKEY5_KEY3_MASK            8U
#define NVBACKKEY5_KEY4_MASK            16U
#define NVBACKKEY5_KEY5_MASK            32U
#define NVBACKKEY5_KEY6_MASK            64U
#define NVBACKKEY5_KEY7_MASK            128U


/*** NVBACKKEY6 - Backdoor Comparison Key 6; 0x0000FFB6 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 7 */
  } Bits;
} NVBACKKEY6STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY6_INIT @0x0000FFB6 = <NVBACKKEY6_INITVAL>; */
#define _NVBACKKEY6 (*(const NVBACKKEY6STR * __far)0x0000FFB6)
#define NVBACKKEY6                      _NVBACKKEY6.Byte
#define NVBACKKEY6_KEY0                 _NVBACKKEY6.Bits.KEY0
#define NVBACKKEY6_KEY1                 _NVBACKKEY6.Bits.KEY1
#define NVBACKKEY6_KEY2                 _NVBACKKEY6.Bits.KEY2
#define NVBACKKEY6_KEY3                 _NVBACKKEY6.Bits.KEY3
#define NVBACKKEY6_KEY4                 _NVBACKKEY6.Bits.KEY4
#define NVBACKKEY6_KEY5                 _NVBACKKEY6.Bits.KEY5
#define NVBACKKEY6_KEY6                 _NVBACKKEY6.Bits.KEY6
#define NVBACKKEY6_KEY7                 _NVBACKKEY6.Bits.KEY7

#define NVBACKKEY6_KEY0_MASK            1U
#define NVBACKKEY6_KEY1_MASK            2U
#define NVBACKKEY6_KEY2_MASK            4U
#define NVBACKKEY6_KEY3_MASK            8U
#define NVBACKKEY6_KEY4_MASK            16U
#define NVBACKKEY6_KEY5_MASK            32U
#define NVBACKKEY6_KEY6_MASK            64U
#define NVBACKKEY6_KEY7_MASK            128U


/*** NVBACKKEY7 - Backdoor Comparison Key 7; 0x0000FFB7 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 7 */
  } Bits;
} NVBACKKEY7STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY7_INIT @0x0000FFB7 = <NVBACKKEY7_INITVAL>; */
#define _NVBACKKEY7 (*(const NVBACKKEY7STR * __far)0x0000FFB7)
#define NVBACKKEY7                      _NVBACKKEY7.Byte
#define NVBACKKEY7_KEY0                 _NVBACKKEY7.Bits.KEY0
#define NVBACKKEY7_KEY1                 _NVBACKKEY7.Bits.KEY1
#define NVBACKKEY7_KEY2                 _NVBACKKEY7.Bits.KEY2
#define NVBACKKEY7_KEY3                 _NVBACKKEY7.Bits.KEY3
#define NVBACKKEY7_KEY4                 _NVBACKKEY7.Bits.KEY4
#define NVBACKKEY7_KEY5                 _NVBACKKEY7.Bits.KEY5
#define NVBACKKEY7_KEY6                 _NVBACKKEY7.Bits.KEY6
#define NVBACKKEY7_KEY7                 _NVBACKKEY7.Bits.KEY7

#define NVBACKKEY7_KEY0_MASK            1U
#define NVBACKKEY7_KEY1_MASK            2U
#define NVBACKKEY7_KEY2_MASK            4U
#define NVBACKKEY7_KEY3_MASK            8U
#define NVBACKKEY7_KEY4_MASK            16U
#define NVBACKKEY7_KEY5_MASK            32U
#define NVBACKKEY7_KEY6_MASK            64U
#define NVBACKKEY7_KEY7_MASK            128U


/*** NVPROT - Nonvolatile FLASH Protection Register; 0x0000FFBD ***/
typedef union {
  byte Byte;
  struct {
    byte FPDIS       :1;                                       /* FLASH Protection Disable */
    byte FPS1        :1;                                       /* FLASH Protect Select Bit 1 */
    byte FPS2        :1;                                       /* FLASH Protect Select Bit 2 */
    byte FPS3        :1;                                       /* FLASH Protect Select Bit 3 */
    byte FPS4        :1;                                       /* FLASH Protect Select Bit 4 */
    byte FPS5        :1;                                       /* FLASH Protect Select Bit 5 */
    byte FPS6        :1;                                       /* FLASH Protect Select Bit 6 */
    byte FPS7        :1;                                       /* FLASH Protect Select Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte grpFPS_1 :7;
  } MergedBits;
} NVPROTSTR;
/* Tip for register initialization in the user code:  const byte NVPROT_INIT @0x0000FFBD = <NVPROT_INITVAL>; */
#define _NVPROT (*(const NVPROTSTR * __far)0x0000FFBD)
#define NVPROT                          _NVPROT.Byte
#define NVPROT_FPDIS                    _NVPROT.Bits.FPDIS
#define NVPROT_FPS1                     _NVPROT.Bits.FPS1
#define NVPROT_FPS2                     _NVPROT.Bits.FPS2
#define NVPROT_FPS3                     _NVPROT.Bits.FPS3
#define NVPROT_FPS4                     _NVPROT.Bits.FPS4
#define NVPROT_FPS5                     _NVPROT.Bits.FPS5
#define NVPROT_FPS6                     _NVPROT.Bits.FPS6
#define NVPROT_FPS7                     _NVPROT.Bits.FPS7
#define NVPROT_FPS_1                    _NVPROT.MergedBits.grpFPS_1
#define NVPROT_FPS                      NVPROT_FPS_1

#define NVPROT_FPDIS_MASK               1U
#define NVPROT_FPS1_MASK                2U
#define NVPROT_FPS2_MASK                4U
#define NVPROT_FPS3_MASK                8U
#define NVPROT_FPS4_MASK                16U
#define NVPROT_FPS5_MASK                32U
#define NVPROT_FPS6_MASK                64U
#define NVPROT_FPS7_MASK                128U
#define NVPROT_FPS_1_MASK               254U
#define NVPROT_FPS_1_BITNUM             1U


/*** NVOPT - Nonvolatile Flash Options Register; 0x0000FFBF ***/
typedef union {
  byte Byte;
  struct {
    byte SEC00       :1;                                       /* Security State Code, bit 0 */
    byte SEC01       :1;                                       /* Security State Code, bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte FNORED      :1;                                       /* Vector Redirection Disable */
    byte KEYEN       :1;                                       /* Backdoor Key Mechanism Enable */
  } Bits;
  struct {
    byte grpSEC0 :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} NVOPTSTR;
/* Tip for register initialization in the user code:  const byte NVOPT_INIT @0x0000FFBF = <NVOPT_INITVAL>; */
#define _NVOPT (*(const NVOPTSTR * __far)0x0000FFBF)
#define NVOPT                           _NVOPT.Byte
#define NVOPT_SEC00                     _NVOPT.Bits.SEC00
#define NVOPT_SEC01                     _NVOPT.Bits.SEC01
#define NVOPT_FNORED                    _NVOPT.Bits.FNORED
#define NVOPT_KEYEN                     _NVOPT.Bits.KEYEN
#define NVOPT_SEC0                      _NVOPT.MergedBits.grpSEC0

#define NVOPT_SEC00_MASK                1U
#define NVOPT_SEC01_MASK                2U
#define NVOPT_FNORED_MASK               64U
#define NVOPT_KEYEN_MASK                128U
#define NVOPT_SEC0_MASK                 3U
#define NVOPT_SEC0_BITNUM               0U



/* Flash commands */
#define mBlank                          0x05
#define mBurstProg                      0x25
#define mByteProg                       0x20
#define mMassErase                      0x41
#define mPageErase                      0x40


/***********************************************/
/**   D E P R E C I A T E D   S Y M B O L S   **/
/***********************************************/
/* --------------------------------------------------------------------------- */
/* The following symbols were removed, because they were invalid or irrelevant */
/* --------------------------------------------------------------------------- */

/* **** 20.12.2013 13:32:00 */
#define SPMSC3_HVWE                     This_symb_has_been_depreciated
#define SPMSC3_HVWIE                    This_symb_has_been_depreciated
#define SPMSC3_HVWACK                   This_symb_has_been_depreciated
#define SPMSC3_HVWF                     This_symb_has_been_depreciated
#define SPMSC3_HVWE_MASK                This_symb_has_been_depreciated
#define SPMSC3_HVWIE_MASK               This_symb_has_been_depreciated
#define SPMSC3_HVWACK_MASK              This_symb_has_been_depreciated
#define SPMSC3_HVWF_MASK                This_symb_has_been_depreciated
#define KBISC_KBIMOD                    KBISC_KBMOD
#define KBISC_KBIMOD_MASK               KBISC_KBMOD_MASK
#define PWUCS0_WUFACK                   PWUCS0_WUFAK
#define PWUCS0_WUFACK_MASK              PWUCS0_WUFAK_MASK
#define PWUCS1_PRFACK                   PWUCS1_PRFAK
#define PWUCS1_PRFACK_MASK              PWUCS1_PRFAK_MASK
#define RFCR7_RFIACK                    RFCR7_RFIAK
#define RFCR7_RFIACK_MASK               RFCR7_RFIAK_MASK
#endif
/*lint -restore  +esym(960,18.4) +esym(961,19.7) Enable MISRA rule (1.1,18.4,6.4,19.7) checking. */
