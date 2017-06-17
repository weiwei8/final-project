#include "buzzer.h"
#include "Delay.h"
#include "key.h"

void BuzzerInit(void)	
{
	 LPC_SYSCON->SYSAHBCLKCTRL |= (1<<16);  
    LPC_IOCON->PIO0_1 &= ~0x07;
	  LPC_IOCON->PIO0_1 |= 0x00;
	  LPC_SYSCON->SYSAHBCLKCTRL &= ~(1<<16); 
  
    LPC_GPIO0->DIR |= (1<<1); 
    LPC_GPIO0->DATA |= (1<<1); 
}	



void BuzzerAlarm(uint32_t temp)
{
		if(temp >= counter)
		{
			Delayus(500);
		  BUZZER_ON() ;
		  Delayus(500);
		  BUZZER_OFF() ;
		  Delayus(500);
//			Delayus(500);
//		  BUZZER_ON() ;
//		  Delayus(500);
//		  BUZZER_OFF() ;
//		  Delayus(500);
//			Delayus(500);
//		  BUZZER_ON() ;
//		  Delayus(500);
//		  BUZZER_OFF() ;
//		  Delayus(500);
//			Delayus(500);
//		  BUZZER_ON() ;
//		  Delayus(500);
//		  BUZZER_OFF() ;
//		  Delayus(500);
		}
	 	
}
