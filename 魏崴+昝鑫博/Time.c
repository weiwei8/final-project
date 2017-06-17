#include "Time.h"
#include "adc.h"
#include "uart.h"
#include "LED.h"
#include "buzzer.h"
#include "key.h"

uint32_t res_value;//����
uint32_t temp = 0;  //	�¶�
uint32_t tempF;

void TIMER32_0_IRQHandler (void)
{
	  
	   LPC_TMR32B0->IR = 0x01; 

     ulADCBuf = LPC_ADC->DR[7];	//��ȡͨ��1��ֵ   
     ulADCBuf = (ulADCBuf >> 6) & 0x3FF;	//���λ�ڵ�6λ��ʼ����10λ��0x3FFȡ10λ
     ADCFlag  = 1;	//�ñ�־λ  


			if (ADCFlag == 1)                                       
				{                                               
            ADCFlag = 0;	//????            
                                             
            ulADCData = ulADCBuf;                             
                                       
                                   
                                       

                ulADCData = (ulADCData * 3300) / 1024;	//����ʵ��ѹ
                res_value = ADC_To_Res(ulADCData);
                temp = Res_To_Temp(res_value);
                tempF = TempC_To_TempF(temp);					
                sprintf(GcRcvBuf,"wendu = %d ��\r\n",temp);
                UART_SendStr(GcRcvBuf);	//�����ݷ��͵�������ʾ 
							  
                ulADCData = 0;
                //Delay(200);
            
            LPC_ADC->CR |= 1 << 24;	//����ADת��
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
  NVIC_SetPriority(TIMER_32_0_IRQn,0);	//���ö�ʱ���ж����ȼ�Ϊ2	
}

