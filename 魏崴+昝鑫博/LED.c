#include "LED.h"
#include "Delay.h"
uint32_t table[10] = {0xfc0,0xff9,0xfa4,0xfb0,0xf99,0xf92,0xf82,0xff8,0xf80,0xf90};
void GPIOLedInit(void)
{
	LPC_GPIO2 ->DIR |= 0xFFF;				//ÉèÖÃP2_0~P2_11ÎªÊä³ö
	LPC_GPIO2 ->DATA |= 0xFFF;
}
void Display(uint32_t value)
{
//	if(value/1000 != 0)
//	LPC_GPIO2->DATA	= 0xeff & table[value/1000];	
//	Delayms(2);
//	LPC_GPIO2->DATA = 0xFFF;
//	
//	if(value%1000/100 != 0)
//	LPC_GPIO2->DATA	= 0xdff & table[value%1000/100];	
//	Delayms(2);
//	LPC_GPIO2->DATA = 0xFFF;
	
	
	if(value%1000%100/10 != 0)
	LPC_GPIO2->DATA = 0xbff & table[value%1000%100/10];	
	Delayms(2);
	LPC_GPIO2->DATA = 0xFFF;
	
	LPC_GPIO2->DATA = 0x7ff & table[value%1000%100%10];	
	Delayms(2);
	LPC_GPIO2->DATA = 0xFFF;

}

void display(uint32_t value)
{
	if(value/10 != 0)
	LPC_GPIO2->DATA	= 0xeff & table[value/10];	
	Delayms(2);
	LPC_GPIO2->DATA = 0xFFF;
	
//	if(value%10 != 0)
	LPC_GPIO2->DATA	= 0xdff & table[value%10];	
	Delayms(2);
	LPC_GPIO2->DATA = 0xFFF;
	
//	if(value%1000%100/10 != 0)
//	LPC_GPIO2->DATA = 0xbff & table[value%1000%100/10];	
//	Delayms(2);
//	LPC_GPIO2->DATA = 0xFFF;
//	
//	LPC_GPIO2->DATA = 0x7ff & table[value%1000%1000%10];	
//	Delayms(2);
//	LPC_GPIO2->DATA = 0xFFF;

}