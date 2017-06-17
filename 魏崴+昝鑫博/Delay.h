#ifndef __DELAY_H
#define __DELAY_H

#include "LPC11xx.h"

static volatile unsigned int ticks = 0;
void Delayms(uint16_t ms);
void Delayus(uint16_t us);
void SysTick_Handler(void);

#endif







