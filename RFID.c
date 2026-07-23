#include<lpc21xx.h>
#include"string.h"
#include"uart0.h"
#include"uart1.h"
#include"lcd.h"
 /*int main()
 {
 LCD_INIT();
 LCD_COMMAND(0X80);
 LCD_DATA('A');
 }
*/
int main()
{
unsigned char i;
unsigned char id[20];
unsigned char valid_id[]="060067A55296";
LCD_INIT();
UART0_INIT();
UART1_INIT();
IODIR0|=1<<6|1<<7;
while(1)
{
LCD_COMMAND(0x01);
LCD_COMMAND(0x80);
LCD_STR("SCAN RFID");
delay(2);

for(i=0;i<12;i++)
{
id[i] = UART0_RX();

}
id[i] = '\0';
 UART0_STR(id);   
	if(strcmp((char*)id,(char*)valid_id)==0)
	{
	LCD_COMMAND(0X01);
	LCD_COMMAND(0X80);
	LCD_STR("ACCESS GRANTED");
	delay(2);
	LCD_COMMAND(0X01);
	LCD_COMMAND(0X80);
	LCD_STR("Engine Start");
	while(1)
	{
	IOSET0=1<<6;
	IOCLR0=1<<7;
	}
	 
	}
	else
	{
	LCD_COMMAND(0X01);
	LCD_COMMAND(0X80);
	LCD_STR("ACCESS DENIED");
	delay(2);
	// gsm code
UART1_STR("at\r\n");
delay_ms(200);
UART1_STR("at+cmgf=1\r\n");
delay_ms(200);
UART1_STR("at+cmgs=\"+918608186394\"\r\n");
delay_ms(200);
UART1_STR("WARNING ALEART\r\n");		
UART1_TX(0X1A);		
} 
}	 
}
