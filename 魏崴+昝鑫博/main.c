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

	  GPIOLedInit();    //GPIO��ʼ��                                 
    UART_Init();	//UART��ʼ��   
    BuzzerInit();//��������ʼ��	
    ADC_Init();	//ADC��ʼ��
	  Timer0Init ();//ͨ�ö�ʱ����ʼ��
	  KEYInit();  //������ʼ��
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
					display(counter);//��ʾ����ֵ


        BuzzerAlarm(temp);


     }  
}

