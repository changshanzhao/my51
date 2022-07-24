#include "reg52.h"
sbit LED1=P2^0;
sbit LED2=P2^1;
sbit LED3=P2^2;
sbit LED4=P2^3;
sbit LED5=P2^4;
sbit LED6=P2^5;
sbit LED7=P2^6;
sbit LED8=P2^7;
void delay_10us(unsigned int ten_us)
{
   while(ten_us--);

}
void main()
{

	while(1)
	{
		LED1=0;
		delay_10us(50000);
		LED1=1;
		LED2=0;
		delay_10us(50000);
		LED2=1;
		LED3=0;
		delay_10us(50000);
		LED3=1;
		LED4=0;
		delay_10us(50000);
		LED4=1;
		LED5=0;
		delay_10us(50000);
		LED5=1;
		LED6=0;
		delay_10us(50000);
		LED6=1;
		LED7=0;
		delay_10us(50000);
		LED7=1;
		LED8=0;
		delay_10us(50000);
		LED8=1;
	}
}