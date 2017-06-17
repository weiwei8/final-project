
#include "Delay.h"



void Delayms(uint16_t ms)					
{
	SysTick->CTRL &= ~(1<<2);
	SysTick->LOAD = 25000*ms-1;			
	SysTick->VAL = 0;						
	SysTick->CTRL = ((1<<1)|(1<<0));       
	while(!ticks);						    
	ticks = 0;							    
	SysTick->CTRL = 0;					
}

void Delayus(uint16_t us)					
{
	SysTick->CTRL &= ~(1<<2);
	SysTick->LOAD = 25*us-1;			
	SysTick->VAL = 0;						
	SysTick->CTRL = ((1<<1)|(1<<0));       
	while(!ticks);						    
	ticks = 0;							    
	SysTick->CTRL = 0;					
}

void SysTick_Handler(void)
{
	ticks++;
}




