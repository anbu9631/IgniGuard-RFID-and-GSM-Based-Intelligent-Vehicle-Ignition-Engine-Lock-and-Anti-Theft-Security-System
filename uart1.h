#include<lpc21xx.h>
void UART1_INIT(void);
void UART1_TX(unsigned char);
unsigned char UART1_RX(void);
void UART1_STR(unsigned char *);

void UART1_INIT(void)
{
   PINSEL0=0X050005;
   U1LCR=0X83;
   U1DLL=97;
   U1DLM=0;
   U1LCR=0X03;
}
void UART1_TX(unsigned char txbyte)
{
   while(((U1LSR>>5)&1)==0);
   U1THR=txbyte;
}
unsigned char UART1_RX(void)
{
   while((U1LSR & 1)==0);
   return U1RBR;
}
void UART1_STR(unsigned char *s)
{
  while(*s)
  {
  UART1_TX(*s++);
  }
}
