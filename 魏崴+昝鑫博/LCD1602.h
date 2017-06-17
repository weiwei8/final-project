#include "LPC11xx.h"	//LPC11xx?????
#include <stdio.h>
#include <string.h>

#define LCD_RS_LOW     LPC_GPIO2->DATA &= ~(1<<0)
#define LCD_RS_HIGH    LPC_GPIO2->DATA |=  (1<<0)
#define LCD_RW_LOW     LPC_GPIO2->DATA &= ~(1<<1)
#define LCD_RW_HIGH    LPC_GPIO2->DATA |=  (1<<1)
#define LCD_E_LOW      LPC_GPIO2->DATA &= ~(1<<2)
#define LCD_E_HIGH     LPC_GPIO2->DATA |= ~(1<<2)
#define LCD_DATAPORT   LPC_GPIO2->DATA
#define LCD_DATA_IN    LPC_GPIO2->DIR &= ~0xFF
#define LCD_DATA_OUT   LPC_GPIO2->DIR |= ~0xFF
static volatile unsigned int ticks = 0;