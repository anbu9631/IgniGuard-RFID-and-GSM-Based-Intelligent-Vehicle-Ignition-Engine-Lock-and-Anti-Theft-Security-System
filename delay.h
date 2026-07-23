#include<lpc21xx.h>

void delay_ms(unsigned int ms)
{
T0PR=15000-1;
T0TCR=0X01;
while(T0TC<ms);
T0TCR=0X03;
T0TCR=0X00;
}
void delay(unsigned int delay)
{
T0PR=15000000-1;
T0TCR=0X01;
while(T0TC<delay);
T0TCR=0X03;
T0TCR=0X00;
}

