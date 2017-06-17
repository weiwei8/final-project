#include "adc.h"
uint32_t  ulADCBuf;
uint32_t  ADCFlag;
uint32_t  ulADCData; 

/********************************************************************************
* FunctionName   : ADCInit()
* Description    : ADC��ʼ����ADCͨ��һ��P1.0���ţ������ж�
* EntryParameter : None
* ReturnValue    : None
********************************************************************************/
void ADC_Init( void )
{                                                             
    LPC_SYSCON->SYSAHBCLKCTRL |= (1 << 16);                   
    LPC_IOCON->PIO1_11 &= ~0xBF;	//����PIO1_0Ϊģ������ģʽ 
    LPC_IOCON->PIO1_11 |=  0x01;	//PIO1_11ģ������ͨ��7      
    LPC_SYSCON->PDRUNCFG &= ~(0x01 << 4);	//ADCģ���ϵ�             
    LPC_SYSCON->SYSAHBCLKCTRL |=  (0x01 << 13);	//ʹ��ADCģ��ʱ��          
    LPC_ADC->CR = ( 0x01 << 7) |	//ѡ��ADC7         
                  (( SystemCoreClock / 1000000 - 1 ) << 8 ) | //ת��ʱ��1MHz             
                  ( 0 << 16 ) |	//BURST=1,ʹ��Burstģʽ   
                  ( 0 << 17 ) |	//ʹ��11 clocksת��         
                  ( 0 << 24 ) |	//ADCת��ֹͣ              
                  ( 0 << 27 );	//ֱ������ADCת������λ��Ч
  
}



uint32_t ADC_To_Res(uint32_t adc_value)
{

  uint32_t res_value;//����

	res_value = (ulADCData*10000)/(3300-ulADCData);

	return res_value;
}


uint32_t Res_To_Temp(uint32_t res_value)
{
	uint32_t k;   // б��

  int32_t temp = 0;  //	�¶�
	
	if( (res_value<29371)&&(res_value>18680) ) // 0~10???
	{
	 	k = 1069;
		temp = ((29370-res_value)/k)+0;
	}
	else if( (res_value<18681)&&(res_value>12240) )	// 10~20???
	{
	  	k = 644;
		temp = ((18680-res_value)/k)+10;
	}
	else if( (res_value<12241)&&(res_value>8221) )	// 20~30???
	{
	  	k = 402;
		temp = ((12240-res_value)/k)+20;
	}
	else if( (res_value<8222)&&(res_value>5648) )	// 30~40???
	{
	  	k = 257;
		temp = ((8221-res_value)/k)+30;
	}
	else if( (res_value<5649)&&(res_value>3958) )	// 40~50???
	{
	  	k = 169;
		temp = ((5648-res_value)/k)+40;
	}
	else if( (res_value<47731)&&(res_value>29370) )	// -10~0???
	{
	  	k = 1836;
		temp = ((47730-res_value)/k)-10;
	}
	else if( (res_value<80361)&&(res_value>47730) )	// -20~-10???
	{
	  	k = 3263;
		temp = ((80360-res_value)/k)-20;
	}
	else if( (res_value<140001)&&(res_value>80360) )	// -30~-20???
	{
	  	k = 5964;
		temp = ((140000-res_value)/k)-30;
	}
	else if( (res_value<249600)&&(res_value>140000) )	// -40~-30???
	{
	  	k = 10960;
		temp = ((249600-res_value)/k)-40;
	}

	return(temp);   //
}

uint32_t TempC_To_TempF(uint32_t temp)
{
	int32_t tempF;
	tempF = temp*18/10+32;
	return tempF;
}




