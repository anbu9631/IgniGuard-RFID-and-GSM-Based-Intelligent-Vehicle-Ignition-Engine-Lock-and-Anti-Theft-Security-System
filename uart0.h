#include<lpc21xx.h>
void UART0_INIT(void);
void UART0_TX(unsigned char);
unsigned char UART0_RX(void);
void UART0_STR(unsigned char *);

void UART0_INIT(void)
{
   PINSEL0=0X50005;
   U0LCR=0X83;
   U0DLL=97;
   U0DLM=0;
   U0LCR=0X03;
}
void UART0_TX(unsigned char txbyte)
{
   while(((U0LSR>>5)&1)==0);
   U0THR=txbyte;
}
unsigned char UART0_RX(void)
{
   while((U0LSR & 1)==0);
   return U0RBR;
}
void UART0_STR(unsigned char *s)
{
  while(*s)
  {
  UART0_TX(*s++);
  }
}
