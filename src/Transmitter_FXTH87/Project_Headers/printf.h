#ifndef _PRINTF_H
#define _PRINTF_H

#define BAUDRATE  4800
#define BAUDRATE_THEORY_TIME (500000/BAUDRATE)
#define CALIBRAT_TIME (12)
//Attention:  BAUDRATE_TIME <=255
#define BAUDRATE_TIME (BAUDRATE_THEORY_TIME - CALIBRAT_TIME)

//PTA2用作Printf的输出(TX)
#define TX_PE   PTADD_PTADD2    //Internal pullup device enabled(配置上拉)
#define TX_DD   PTADD_PTADD2    //Output driver enabled(输出模式)
#define TX_DAT  PTAD_PTAD2


void PrintfInit(void);
void PrintfChar(char data);
void TERMIO_PutChar(char C);

#endif



