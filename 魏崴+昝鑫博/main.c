#include "LPC11xx.h"	//LPC11xx?????
#include <stdio.h>
#include <string.h>
#include "adc.h"
#include "LED.h"
#include "uart.h"
#include "buzzer.h"
#include "Time.h"
#include "key.h"

char     	GcRcvBuf[20];





int main(void)                                                  
{   
    	
    uint32_t  i = 0;                                            

	  GPIOLedInit();    //GPIO初始化                                 
    UART_Init();	//UART初始化   
    BuzzerInit();//蜂鸣器初始化	
    ADC_Init();	//ADC初始化
	  Timer0Init ();//通用定时器初始化
	  KEYInit();  //按键初始化
    ADCFlag   = 0;                                              
    LPC_ADC->CR |= 1 << 24;	//??AD??   

    while (1)                                                   
			{                                                        
		  

				if(mFlag==0)
				{
				  if(nFlag==0)
				    Display(temp);
			  	else
				  	Display(tempF);
				}
				else
					display(counter);//显示报警值


        BuzzerAlarm(temp);


     }  
}

