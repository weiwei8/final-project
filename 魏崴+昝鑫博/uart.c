#include "uart.h"


void UART_Init (void)
{
    uint16_t usFdiv;

    LPC_SYSCON->SYSAHBCLKCTRL |= (1 << 16);//打开时钟
    LPC_IOCON->PIO1_6  &= ~0x07;
    LPC_IOCON->PIO1_6  |= (1<<0);	  //配置位RXD 接收    
    LPC_IOCON->PIO1_7  &= ~0x07;
    LPC_IOCON->PIO1_7  |= (1<<0);	   //配置为TXD 发送
    
    LPC_SYSCON->SYSAHBCLKCTRL |= (1<<12);	 //打开时钟
    LPC_SYSCON->UARTCLKDIV     = 0x01;	   //时钟分频为1    
    
    LPC_UART->LCR  = 0x83;	//8位传输  1位停止位，0位奇偶校验位，使能对除数锁存器的访问     
    usFdiv = (SystemCoreClock/LPC_SYSCON->UARTCLKDIV/16)/UART_BPS;    //计算除数锁存器的值     
    LPC_UART->DLM  = usFdiv / 256; //除数锁存器高八位的值
    LPC_UART->DLL  = usFdiv % 256; //除数锁存器第八位的值
    LPC_UART->LCR  = 0x03;	    //禁止对除数锁存器的访问     
    LPC_UART->FCR  = 0x07;//允许FIFO
}

void UART_SendByte (uint8_t ucDat)
{
    LPC_UART->THR = ucDat;	//发送数据       
    while ((LPC_UART->LSR & 0x40) == 0);	//等待发送完
}

void UART_SendStr (char *pucStr)
{
    while (1){
        if (*pucStr == '\0') break;	//遇到结束符号退出
        UART_SendByte(*pucStr++);
    }
}

