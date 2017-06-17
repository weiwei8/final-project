#include "Time.h"
#include "adc.h"
#include "uart.h"
#include "LED.h"
#include "buzzer.h"
#include "key.h"

uint32_t res_value;//电阻
uint32_t temp = 0;  //	温度
uint32_t tempF;

void TIMER32_0_IRQHandler (void)
{
	  
	   LPC_TMR32B0->IR = 0x01; 

     ulADCBuf = LPC_ADC->DR[7];	//读取通道1的值   
     ulADCBuf = (ulADCBuf >> 6) & 0x3FF;	//结果位于第6位开始，共10位，0x3FF取10位
     ADCFlag  = 1;	//置标志位  


			if (ADCFlag == 1)                                       
				{                                               
            ADCFlag = 0;	//????            
                                             
            ulADCData = ulADCBuf;                             
                                       
                                   
                                       

                ulADCData = (ulADCData * 3300) / 1024;	//求真实电压
                res_value = ADC_To_Res(ulADCData);
                temp = Res_To_Temp(res_value);
                tempF = TempC_To_TempF(temp);					
                sprintf(GcRcvBuf,"wendu = %d ℃\r\n",temp);
                UART_SendStr(GcRcvBuf);	//将数据发送到串口显示 
							  
                ulADCData = 0;
                //Delay(200);
            
            LPC_ADC->CR |= 1 << 24;	//启动AD转换
        }

				
				
      return;

}
void Timer0Init (void)
{
	LPC_SYSCON->SYSAHBCLKCTRL |= (1 << 9); 
	LPC_TMR32B0->IR      = 0x01;						
	LPC_TMR32B0->PR      = 0; 							
	LPC_TMR32B0->MCR     = 0x03;  				
	LPC_TMR32B0->MR0     = SystemCoreClock; 
	LPC_TMR32B0->TCR     = 0x01;  					
	NVIC_EnableIRQ(TIMER_32_0_IRQn);
  NVIC_SetPriority(TIMER_32_0_IRQn,0);	//设置定时器中断优先级为2	
}

