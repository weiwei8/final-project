#include "LPC11xx.h"	
#include <stdio.h>
#include <string.h>


extern uint8_t counter;//����ֵ

extern int8_t nFlag;//���ϻ��ϱ�־λ
extern int8_t mFlag;//���ñ���ֵ��־λ
extern void KEYInit(void);
extern void PIOINT3_IRQHandler(void);
void Delay(uint32_t ulTime);