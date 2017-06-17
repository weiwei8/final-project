#ifndef __UART_H_
#define __UART_H_
#include "LPC11xx.h"	
#include <stdio.h>
#include <string.h>
#define 	UART_BPS    9600	//²¨ÌØÂÊ9600
extern char     	GcRcvBuf[20];	//AD?????????

extern void UART_Init (void);
extern void UART_SendByte (uint8_t ucDat);
extern void UART_SendStr (char *pucStr);

#endif


