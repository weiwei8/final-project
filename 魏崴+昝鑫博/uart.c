#include "uart.h"


void UART_Init (void)
{
    uint16_t usFdiv;

    LPC_SYSCON->SYSAHBCLKCTRL |= (1 << 16);//��ʱ��
    LPC_IOCON->PIO1_6  &= ~0x07;
    LPC_IOCON->PIO1_6  |= (1<<0);	  //����λRXD ����    
    LPC_IOCON->PIO1_7  &= ~0x07;
    LPC_IOCON->PIO1_7  |= (1<<0);	   //����ΪTXD ����
    
    LPC_SYSCON->SYSAHBCLKCTRL |= (1<<12);	 //��ʱ��
    LPC_SYSCON->UARTCLKDIV     = 0x01;	   //ʱ�ӷ�ƵΪ1    
    
    LPC_UART->LCR  = 0x83;	//8λ����  1λֹͣλ��0λ��żУ��λ��ʹ�ܶԳ����������ķ���     
    usFdiv = (SystemCoreClock/LPC_SYSCON->UARTCLKDIV/16)/UART_BPS;    //���������������ֵ     
    LPC_UART->DLM  = usFdiv / 256; //�����������߰�λ��ֵ
    LPC_UART->DLL  = usFdiv % 256; //�����������ڰ�λ��ֵ
    LPC_UART->LCR  = 0x03;	    //��ֹ�Գ����������ķ���     
    LPC_UART->FCR  = 0x07;//����FIFO
}

void UART_SendByte (uint8_t ucDat)
{
    LPC_UART->THR = ucDat;	//��������       
    while ((LPC_UART->LSR & 0x40) == 0);	//�ȴ�������
}

void UART_SendStr (char *pucStr)
{
    while (1){
        if (*pucStr == '\0') break;	//�������������˳�
        UART_SendByte(*pucStr++);
    }
}

