#include<LPC21XX.H>
#include "delay.h"
#define LCD 0XFF << 10
#define RS 1<<19
#define EN 1<<20 
void LCD_INIT(void);
void LCD_COMMAND(unsigned char);
void LCD_DATA(unsigned char);
void LCD_INTEGER(int);
void LCD_STR(unsigned char *);

void LCD_INIT()
{
	IODIR0 = LCD | RS | EN ;
	LCD_COMMAND(0X01);
	LCD_COMMAND(0X02);
	LCD_COMMAND(0X0C);
	LCD_COMMAND(0X38);
}
void LCD_COMMAND(unsigned char var)
{
	IOCLR0 = LCD;
	IOSET0 = var<<10;
	IOCLR0 = RS;
	IOSET0 = EN;
	delay_ms(2);
	IOCLR0 = EN;
}
void LCD_DATA(unsigned char data)
{
	IOCLR0 = LCD;
	IOSET0 = data<<10;
	IOSET0 = RS;
	IOSET0 = EN;
	delay_ms(2);
	IOCLR0 = EN;
}
void LCD_INTEGER(int n)
{
    signed char i=0;
	unsigned char arr[5];
	if(n==0)
	LCD_DATA('0');
	else
	{
	if(n<0)
	{
	LCD_DATA('_');
	n=-n;
	}
	while(n>0)
	{
	arr[i++]=n%10;
	n=n/10;
	}
	for(--i;i>0;i--)
	LCD_DATA(arr[i]+48);
	}
}
void LCD_STR(unsigned char *s)
{
   while(*s)
   {
   LCD_DATA(*s++);
   }
}


