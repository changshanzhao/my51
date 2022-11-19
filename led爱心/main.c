#include "reg51.h"
typedef unsigned int u16; //对系统默认数据类型进行重定义
typedef unsigned char u8;
//定义 74HC595 控制管脚
sbit SRCLK=P3^6; //移位寄存器时钟输入
sbit RCLK=P3^5; //存储寄存器时钟输入
sbit SER=P3^4; //串行数据输入
#define LEDDZ_COL_PORT P0 //点阵列控制端口
u8 gled_row[8]={0x30,0x48,0x44,0x22,0x22,0x44,0x48,0x30};//LED 点阵显示
u8 gled_col[8]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};//LED 点阵显示
void delay_10us(u16 ten_us)
{
while(ten_us--);
}
void hc595_write_data(u8 dat)
{
u8 i=0;
for(i=0;i<8;i++)//循环 8 次即可将一个字节写入寄存器中
{
SER=dat>>7;//优先传输一个字节中的高位
dat<<=1;//将低位移动到高位
SRCLK=0;
delay_10us(1);
SRCLK=1;
delay_10us(1);//移位寄存器时钟上升沿将端口数据送入寄存器中
}
RCLK=0;
delay_10us(1);
RCLK=1;//存储寄存器时钟上升沿将前面写入到寄存器的数据输出
}
void main()
{
u8 i=0;
while(1)
{
for(i=0;i<8;i++)//循环 8 次扫描 8 行、列
{
LEDDZ_COL_PORT=gled_col[i];//传送列选数据
hc595_write_data(gled_row[i]);//传送行选数据
delay_10us(100);//延时一段时间，等待显示稳定
hc595_write_data(0x00);//消影
}
}
}