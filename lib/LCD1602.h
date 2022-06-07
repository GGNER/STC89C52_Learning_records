#ifndef __LCD1602_H__
#define __LCD1602_H__

#include <reg52.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
LCD_init();
LCD_write_str(1,1,"2223123");
*/

sbit lcd_rs=P1^0;
sbit lcd_rw=P1^1;
sbit lcd_en=P1^5;

#define DataPort P0

#define RS_CLR lcd_rs=0
#define RS_SET lcd_rs=1

#define RW_CLR lcd_rw=0

#define EN_CLR lcd_en=0
#define EN_SET lcd_en=1



void delay_lcd_ms(unsigned int xms) {
	unsigned int i, j;
	for (i = xms; i > 0; i--)
		for (j = 100; j > 0; j--)
			;
}

//	显示屏命令写入函数
void LCD_write_com(unsigned char com) 
{	
	RS_CLR;
	RW_CLR;
	EN_SET;
	DataPort = com;                 //命令写入端口
	delay_lcd_ms(5);
	EN_CLR;
}

//	显示屏数据写入函数
void LCD_write_data(unsigned char dataa) 
{
	RS_SET;
	RW_CLR;
	EN_SET;
	DataPort = dataa;                //数据写入端口
	delay_lcd_ms(5);
	EN_CLR;
}

//	显示屏单字符写入函数
void LCD_write_char(unsigned char x,unsigned char y,unsigned char dataa) 
{
	
    if (y == 0) 
    {
    	LCD_write_com(0x80 + x);        //第一行显示
    }
    else 
    {
    	LCD_write_com(0xC0 + x);        //第二行显示
    }
    
    LCD_write_data( dataa);  
}

//	显示屏字符串写入函数
void LCD_write_str(unsigned char x,unsigned char y,unsigned char *s) 
{
	EA=0;
    if (y == 0) 
    {
    	LCD_write_com(0x80 + x);        //第一行显示
    }
    else 
    {
    	LCD_write_com(0xC0 + x);        //第二行显示
    }
    
    while (*s) 
    {
    	LCD_write_data( *s);
    	s ++;
    }
 EA=1;
}

//	显示屏初始化函数

void LCD_init(void) 
{
	 LCD_write_com(0x38);		//显示模式设置  
    delay_lcd_ms(5);
	 LCD_write_com(0x38);		//显示模式设置  
    delay_lcd_ms(5);
	 LCD_write_com(0x38);		//显示模式设置  
    delay_lcd_ms(5);
	
	
    LCD_write_com(0x38);		//显示模式设置  
    delay_lcd_ms(5);
    LCD_write_com(0x08);		//显示关闭
    delay_lcd_ms(5);
    LCD_write_com(0x01);		//显示清屏
    delay_lcd_ms(5);
    LCD_write_com(0x06);		//显示光标移动设置
    delay_lcd_ms(5);
    LCD_write_com(0x0C);		//显示开及光标设置
    delay_lcd_ms(5);
}


#enedif
