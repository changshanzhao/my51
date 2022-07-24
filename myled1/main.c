#include "reg52.h"
sbit LED1=P2^0;
sbit LED2=P2^1;
void delay_10us(unsigned int ten_us)
{
   while(ten_us--);

}
void main()
{
	LED1=0;

	while(1)
	{
		LED2=1;
		delay_10us(50000);
		LED2=0;
		delay_10us(50000);

	}
}