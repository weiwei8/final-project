#include "key.h"
#include "LED.h"
#include "Delay.h"
#define KEY1_DOWN() ((LPC_GPIO3->DATA&(1<<0))!=(1<<0))  //P3.0引脚按键按下
#define KEY2_DOWN() ((LPC_GPIO3->DATA&(1<<1))!=(1<<1))  //P3.1引脚按键按下
uint8_t counter = 27;
int8_t nFlag = 0;
int8_t mFlag = 0;



void KEYInit(void)
{
  LPC_IOCON->PIO3_0 &=~(0x07);//上
	LPC_GPIO3->DIR    &=~(1<<0);
	LPC_IOCON->PIO3_1 &=~(0x07);//右
	LPC_GPIO3->DIR    &=~(1<<1);
	LPC_IOCON->PIO3_2 &=~(0x07);//左
	LPC_GPIO3->DIR    &=~(1<<2);
	LPC_IOCON->PIO3_3 &=~(0x07);//下
	LPC_GPIO3->DIR    &=~(1<<3);
	LPC_IOCON->PIO3_4 &=~(0x07);//中
	LPC_GPIO3->DIR    &=~(1<<4);
	
	  LPC_GPIO3->IE|=(1<<0);
	  LPC_GPIO3->IE|=(1<<1);
	  LPC_GPIO3->IE|=(1<<2);
	  LPC_GPIO3->IE|=(1<<3);
	  LPC_GPIO3->IE|=(1<<4);
	  LPC_GPIO3->IS&=~(1<<0);
	  LPC_GPIO3->IS&=~(1<<1);
	  LPC_GPIO3->IS&=~(1<<2);
	  LPC_GPIO3->IS&=~(1<<3);
	  LPC_GPIO3->IS&=~(1<<4);
	  LPC_GPIO3->IEV&=~(1<<0);
		LPC_GPIO3->IEV&=~(1<<1);
		LPC_GPIO3->IEV&=~(1<<2);
		LPC_GPIO3->IEV&=~(1<<3);
		LPC_GPIO3->IEV&=~(1<<4);
		NVIC_EnableIRQ(EINT3_IRQn);
		NVIC_SetPriority(EINT3_IRQn,1);
}


void Delay(uint32_t ulTime)
{
    uint32_t i;
    
    while (ulTime--) {
      for (i = 0; i < 5000; i++);
    }
}

void PIOINT3_IRQHandler()
{  

//		NVIC_DisableIRQ(EINT3_IRQn);
	
	
//	 if((LPC_GPIO3->MIS&(1<<0))==(1<<0))
//	 {
//			Delay(10);
      	if((LPC_GPIO3->MIS&(1<<0))==(1<<0))
				{
				 counter++;     //报警值加一
				 LPC_GPIO3->IC = 0xff;			 				 
   //		 return;	 
				}					

			  
//		}
     if((LPC_GPIO3->MIS&(1<<1))==(1<<1))
		{	
		  nFlag = 1;           //显示华氏度
			LPC_GPIO3->IC = 0xff;
	//		return;
		}
     if((LPC_GPIO3->MIS&(1<<2))==(1<<2))
		{
			nFlag = 0;           //显示摄氏度
			LPC_GPIO3->IC = (1<<2);
	//		return;
		}
		 if((LPC_GPIO3->MIS&(1<<3))==(1<<3))
		{
			 	counter--;        //报警值减一
			
			LPC_GPIO3->IC = (1<<3);
	//		return;
		}
		 if((LPC_GPIO3->MIS&(1<<4))==(1<<4))
		{
			if(mFlag++ != 0)    //显示温度、报警值切换
				mFlag = 0;
			LPC_GPIO3->IC = (1<<4);
	//		return;
		}
	//	return;
//		NVIC_EnableIRQ(EINT3_IRQn);
	}
