//#ifndef __BUZZER_H_
//#define __BUZZER_H




#include  "LPC11xx.h" //LPC11xx???
#define BUZZER_ON() (LPC_GPIO0->DATA &=~(1<<1))
#define BUZZER_OFF() (LPC_GPIO0->DATA |=(1<<1))

extern void BuzzerInit(void);
extern void BuzzerAlarm(uint32_t temp);

//#endif


