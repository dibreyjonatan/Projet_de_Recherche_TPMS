/* Based on CPU DB FXTH870000, version 3.00.000 (RegistersPrg V2.33) */
/* DataSheet : Rev. 1.0 06/2013 */

#include <fxth870000.h>

/*lint -save -esym(765, *) */


/* * * * *  8-BIT REGISTERS  * * * * * * * * * * * * * * * */
volatile PTADSTR _PTAD;                                    /* Port A Data Register; 0x00000000 */
volatile PTAPESTR _PTAPE;                                  /* Port A Pull Enable Register; 0x00000001 */
volatile PTADDSTR _PTADD;                                  /* Port A Data Direction Register; 0x00000003 */
volatile PTBDSTR _PTBD;                                    /* Port B Data Register; 0x00000004 */
volatile PTBPESTR _PTBPE;                                  /* Port B Pull Enable Register; 0x00000005 */
volatile PTBDDSTR _PTBDD;                                  /* Port B Data Direction Register; 0x00000007 */
volatile KBISCSTR _KBISC;                                  /* KBI Status and Control Register; 0x0000000C */
volatile KBIPESTR _KBIPE;                                  /* KBI Pin Enable Register; 0x0000000D */
volatile KBIESSTR _KBIES;                                  /* KBI Edge Select Register; 0x0000000E */
volatile TPM1SCSTR _TPM1SC;                                /* TPM1 Status and Control Register; 0x00000010 */
volatile TPM1C0SCSTR _TPM1C0SC;                            /* TPM1 Timer Channel 0 Status and Control Register; 0x00000015 */
volatile TPM1C1SCSTR _TPM1C1SC;                            /* TPM1 Timer Channel 1 Status and Control Register; 0x00000018 */
volatile PWUDIVSTR _PWUDIV;                                /* PWU Divider Register; 0x0000001C */
volatile PWUCS0STR _PWUCS0;                                /* PWU Control/Status Regsiter 0; 0x0000001D */
volatile PWUCS1STR _PWUCS1;                                /* PWU Control/Status Register 1; 0x0000001E */
volatile PWUSSTR _PWUS;                                    /* PWU Wake-Up Status Register; 0x0000001F */
volatile LFCTL1STR _LFCTL1;                                /* LF Control Register 1; 0x00000020 */
volatile LFCTRLESTR _LFCTRLE;                              /* LF Control Register E (LPAGE = 1); 0x00000021 */
volatile LFCTRLDSTR _LFCTRLD;                              /* LF Control Register D (LPAGE = 1); 0x00000022 */
volatile LFCTRLCSTR _LFCTRLC;                              /* LF Control Register C (LPAGE = 1); 0x00000023 */
volatile LFCTRLBSTR _LFCTRLB;                              /* LF Control Register B (LPAGE = 1); 0x00000024 */
volatile LFCTRLASTR _LFCTRLA;                              /* LF Control Register A (LPAGE = 1); 0x00000025 */
volatile RFCR0STR _RFCR0;                                  /* RFM Control Register 0; 0x00000030 */
volatile RFCR1STR _RFCR1;                                  /* RFM Control Register 1; 0x00000031 */
volatile RFCR2STR _RFCR2;                                  /* RFM Control Register 2; 0x00000032 */
volatile RFCR3STR _RFCR3;                                  /* RFM Control Register 3; 0x00000033 */
volatile RFCR4STR _RFCR4;                                  /* RFM Control Register 4; 0x00000034 */
volatile RFCR5STR _RFCR5;                                  /* RFM Control Register 5; 0x00000035 */
volatile RFCR6STR _RFCR6;                                  /* RFM Control Register 6; 0x00000036 */
volatile RFCR7STR _RFCR7;                                  /* RFM Control Register 7; 0x00000037 */
volatile EPR_PLL_LPFSTR _EPR_PLL_LPF;                      /* EPR Register (RPAGE = 1, VCD_EN = 0); 0x00000038 */
volatile PLLCR1STR _PLLCR1;                                /* PLL Control Register 1 (RPAGE = 0); 0x00000039 */
volatile PLLCR2STR _PLLCR2;                                /* PLL Control Register 2 (RPAGE = 0); 0x0000003A */
volatile PLLCR3STR _PLLCR3;                                /* PLL Control Register 3 (RPAGE = 0); 0x0000003B */
volatile RFD0STR _RFD0;                                    /* RFD Register 0; 0x0000003C */
volatile RFD1STR _RFD1;                                    /* RFD Register 1; 0x0000003D */
volatile RFD2STR _RFD2;                                    /* RFD Register 2; 0x0000003E */
volatile RFD3STR _RFD3;                                    /* RFD Register 3; 0x0000003F */
volatile RFD4STR _RFD4;                                    /* RFD Register 4; 0x00000040 */
volatile RFD5STR _RFD5;                                    /* RFD Register 5; 0x00000041 */
volatile RFD6STR _RFD6;                                    /* RFD Register 6; 0x00000042 */
volatile RFD7STR _RFD7;                                    /* RFD Register 7; 0x00000043 */
volatile RFD8STR _RFD8;                                    /* RFD Register 8; 0x00000044 */
volatile RFD9STR _RFD9;                                    /* RFD Register 9; 0x00000045 */
volatile RFD10STR _RFD10;                                  /* RFD Register 10; 0x00000046 */
volatile RFD11STR _RFD11;                                  /* RFD Register 11; 0x00000047 */
volatile RFD12STR _RFD12;                                  /* RFD Register 12; 0x00000048 */
volatile RFD13STR _RFD13;                                  /* RFD Register 13; 0x00000049 */
volatile RFD14STR _RFD14;                                  /* RFD Register 14; 0x0000004A */
volatile RFD15STR _RFD15;                                  /* RFD Register 15; 0x0000004B */
volatile PARAM0STR _PARAM0;                                /* Parameter Register 0; 0x00000050 */
volatile PARAM1STR _PARAM1;                                /* Parameter Register 1; 0x00000051 */
volatile PARAM2STR _PARAM2;                                /* Parameter Register 2; 0x00000052 */
volatile PARAM3STR _PARAM3;                                /* Parameter Register 3; 0x00000053 */
volatile PARAM4STR _PARAM4;                                /* Parameter Register 4; 0x00000054 */
volatile PARAM5STR _PARAM5;                                /* Parameter Register 5; 0x00000055 */
volatile PARAM6STR _PARAM6;                                /* Parameter Register 6; 0x00000056 */
volatile PARAM7STR _PARAM7;                                /* Parameter Register 7; 0x00000057 */
volatile PARAM8STR _PARAM8;                                /* Parameter Register 8; 0x00000058 */
volatile PARAM9STR _PARAM9;                                /* Parameter Register 9; 0x00000059 */
volatile PARAM10STR _PARAM10;                              /* Parameter Register 10; 0x0000005A */
volatile PARAM11STR _PARAM11;                              /* Parameter Register 11; 0x0000005B */
volatile PARAM12STR _PARAM12;                              /* Parameter Register 12; 0x0000005C */
volatile PARAM13STR _PARAM13;                              /* Parameter Register 13; 0x0000005D */
volatile PARAM14STR _PARAM14;                              /* Parameter Register 14; 0x0000005E */
volatile PARAM15STR _PARAM15;                              /* Parameter Register 15; 0x0000005F */
volatile PARAM16STR _PARAM16;                              /* Parameter Register 16; 0x00000060 */
volatile PARAM17STR _PARAM17;                              /* Parameter Register 17; 0x00000061 */
volatile PARAM18STR _PARAM18;                              /* Parameter Register 18; 0x00000062 */
volatile PARAM19STR _PARAM19;                              /* Parameter Register 19; 0x00000063 */
volatile PARAM20STR _PARAM20;                              /* Parameter Register 20; 0x00000064 */
volatile PARAM21STR _PARAM21;                              /* Parameter Register 21; 0x00000065 */
volatile PARAM22STR _PARAM22;                              /* Parameter Register 22; 0x00000066 */
volatile PARAM23STR _PARAM23;                              /* Parameter Register 23; 0x00000067 */
volatile PARAM24STR _PARAM24;                              /* Parameter Register 24; 0x00000068 */
volatile PARAM25STR _PARAM25;                              /* Parameter Register 25; 0x00000069 */
volatile PARAM26STR _PARAM26;                              /* Parameter Register 26; 0x0000006A */
volatile PARAM27STR _PARAM27;                              /* Parameter Register 27; 0x0000006B */
volatile PARAM28STR _PARAM28;                              /* Parameter Register 28; 0x0000006C */
volatile PARAM29STR _PARAM29;                              /* Parameter Register 29; 0x0000006D */
volatile PARAM30STR _PARAM30;                              /* Parameter Register 30; 0x0000006E */
volatile PARAM31STR _PARAM31;                              /* Parameter Register 31; 0x0000006F */
volatile PARAM32STR _PARAM32;                              /* Parameter Register 32; 0x00000070 */
volatile PARAM33STR _PARAM33;                              /* Parameter Register 33; 0x00000071 */
volatile PARAM34STR _PARAM34;                              /* Parameter Register 34; 0x00000072 */
volatile PARAM35STR _PARAM35;                              /* Parameter Register 35; 0x00000073 */
volatile PARAM36STR _PARAM36;                              /* Parameter Register 36; 0x00000074 */
volatile PARAM37STR _PARAM37;                              /* Parameter Register 37; 0x00000075 */
volatile PARAM38STR _PARAM38;                              /* Parameter Register 38; 0x00000076 */
volatile PARAM39STR _PARAM39;                              /* Parameter Register 39; 0x00000077 */
volatile PARAM40STR _PARAM40;                              /* Parameter Register 40; 0x00000078 */
volatile PARAM41STR _PARAM41;                              /* Parameter Register 41; 0x00000079 */
volatile PARAM42STR _PARAM42;                              /* Parameter Register 42; 0x0000007A */
volatile PARAM43STR _PARAM43;                              /* Parameter Register 43; 0x0000007B */
volatile PARAM44STR _PARAM44;                              /* Parameter Register 44; 0x0000007C */
volatile PARAM45STR _PARAM45;                              /* Parameter Register 45; 0x0000007D */
volatile PARAM46STR _PARAM46;                              /* Parameter Register 46; 0x0000007E */
volatile PARAM47STR _PARAM47;                              /* Parameter Register 47; 0x0000007F */
volatile PARAM48STR _PARAM48;                              /* Parameter Register 48; 0x00000080 */
volatile PARAM49STR _PARAM49;                              /* Parameter Register 49; 0x00000081 */
volatile PARAM50STR _PARAM50;                              /* Parameter Register 50; 0x00000082 */
volatile PARAM51STR _PARAM51;                              /* Parameter Register 51; 0x00000083 */
volatile PARAM52STR _PARAM52;                              /* Parameter Register 52; 0x00000084 */
volatile PARAM53STR _PARAM53;                              /* Parameter Register 53; 0x00000085 */
volatile PARAM54STR _PARAM54;                              /* Parameter Register 54; 0x00000086 */
volatile PARAM55STR _PARAM55;                              /* Parameter Register 55; 0x00000087 */
volatile PARAM56STR _PARAM56;                              /* Parameter Register 56; 0x00000088 */
volatile PARAM57STR _PARAM57;                              /* Parameter Register 57; 0x00000089 */
volatile PARAM58STR _PARAM58;                              /* Parameter Register 58; 0x0000008A */
volatile PARAM59STR _PARAM59;                              /* Parameter Register 59; 0x0000008B */
volatile PARAM60STR _PARAM60;                              /* Parameter Register 60; 0x0000008C */
volatile PARAM61STR _PARAM61;                              /* Parameter Register 61; 0x0000008D */
volatile PARAM62STR _PARAM62;                              /* Parameter Register 62; 0x0000008E */
volatile PARAM63STR _PARAM63;                              /* Parameter Register 63; 0x0000008F */
volatile SRSSTR _SRS;                                      /* System Reset Status Register; 0x00001800 */
volatile SBDFRSTR _SBDFR;                                  /* System Background Debug Force Reset Register; 0x00001801 */
volatile SIMOPT1STR _SIMOPT1;                              /* System Options Register 1; 0x00001802 */
volatile SIMOPT2STR _SIMOPT2;                              /* System Options Register 2; 0x00001803 */
volatile SRTISCSTR _SRTISC;                                /* System Real-Time Interrupt Status and Control Register; 0x00001808 */
volatile SPMSC1STR _SPMSC1;                                /* System Power Management Status and Control 1 Register; 0x00001809 */
volatile SPMSC2STR _SPMSC2;                                /* System Power Management Status and Control 2 Register; 0x0000180A */
volatile SPMSC3STR _SPMSC3;                                /* System Power Management Status and Control 3 Register; 0x0000180C */
volatile SIMSESSTR _SIMSES;                                /* SIM Stop Exit Status; 0x0000180D */
volatile SOTRMSTR _SOTRM;                                  /* System Oscillator Trim Register; 0x0000180E */
volatile SIMTSTSTR _SIMTST;                                /* SIM Test Register; 0x0000180F */
volatile FCDIVSTR _FCDIV;                                  /* FLASH Clock Divider Register; 0x00001820 */
volatile FOPTSTR _FOPT;                                    /* FLASH Options Register; 0x00001821 */
volatile FCNFGSTR _FCNFG;                                  /* FLASH Configuration Register; 0x00001823 */
volatile FPROTSTR _FPROT;                                  /* FLASH Protection Register; 0x00001824 */
volatile FSTATSTR _FSTAT;                                  /* Flash Status Register; 0x00001825 */
volatile FCMDSTR _FCMD;                                    /* FLASH Command Register; 0x00001826 */
/* NVBACKKEY0 - macro for reading non volatile register    Backdoor Comparison Key 0; 0x0000FFB0 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY0_INIT @0x0000FFB0 = <NVBACKKEY0_INITVAL>; */
/* NVBACKKEY1 - macro for reading non volatile register    Backdoor Comparison Key 1; 0x0000FFB1 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY1_INIT @0x0000FFB1 = <NVBACKKEY1_INITVAL>; */
/* NVBACKKEY2 - macro for reading non volatile register    Backdoor Comparison Key 2; 0x0000FFB2 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY2_INIT @0x0000FFB2 = <NVBACKKEY2_INITVAL>; */
/* NVBACKKEY3 - macro for reading non volatile register    Backdoor Comparison Key 3; 0x0000FFB3 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY3_INIT @0x0000FFB3 = <NVBACKKEY3_INITVAL>; */
/* NVBACKKEY4 - macro for reading non volatile register    Backdoor Comparison Key 4; 0x0000FFB4 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY4_INIT @0x0000FFB4 = <NVBACKKEY4_INITVAL>; */
/* NVBACKKEY5 - macro for reading non volatile register    Backdoor Comparison Key 5; 0x0000FFB5 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY5_INIT @0x0000FFB5 = <NVBACKKEY5_INITVAL>; */
/* NVBACKKEY6 - macro for reading non volatile register    Backdoor Comparison Key 6; 0x0000FFB6 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY6_INIT @0x0000FFB6 = <NVBACKKEY6_INITVAL>; */
/* NVBACKKEY7 - macro for reading non volatile register    Backdoor Comparison Key 7; 0x0000FFB7 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY7_INIT @0x0000FFB7 = <NVBACKKEY7_INITVAL>; */
/* NVPROT - macro for reading non volatile register        Nonvolatile FLASH Protection Register; 0x0000FFBD */
/* Tip for register initialization in the user code:  const byte NVPROT_INIT @0x0000FFBD = <NVPROT_INITVAL>; */
/* NVOPT - macro for reading non volatile register         Nonvolatile Flash Options Register; 0x0000FFBF */
/* Tip for register initialization in the user code:  const byte NVOPT_INIT @0x0000FFBF = <NVOPT_INITVAL>; */


/* * * * *  16-BIT REGISTERS  * * * * * * * * * * * * * * * */
volatile TPM1CNTSTR _TPM1CNT;                              /* TPM1 Timer Counter Register; 0x00000011 */
volatile TPM1MODSTR _TPM1MOD;                              /* TPM1 Timer Counter Modulo Register; 0x00000013 */
volatile TPM1C0VSTR _TPM1C0V;                              /* TPM1 Timer Channel 0 Value Register; 0x00000016 */
volatile TPM1C1VSTR _TPM1C1V;                              /* TPM1 Timer Channel 1 Value Register; 0x00000019 */
volatile LFIDSTR _LFID;                                    /* LFR ID Register; 0x00000026 */
volatile SDIDSTR _SDID;                                    /* System Device Identification Register; 0x00001806 */

/*lint -restore */

/* EOF */
