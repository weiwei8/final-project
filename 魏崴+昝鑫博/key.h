#include "LPC11xx.h"	
#include <stdio.h>
#include <string.h>


extern uint8_t counter;//报警值

extern int8_t nFlag;//摄氏华氏标志位
extern int8_t mFlag;//设置报警值标志位
extern void KEYInit(void);
extern void PIOINT3_IRQHandler(void);
void Delay(uint32_t ulTime);