#ifndef  __TIMER1_H__
#define  __TIMER1_H__

#include <reg52.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//定时器1
void init_timer(void)
{
	EA = 1;         //开总中断
	ET1 = 1;        //定时器T1中断允许
	TMOD &= 0x0f;
	TMOD |= 0x00;    // 使用定时器T1的模式1（13位计数器）
	TR1 = 1;

	TMOD |= 0x01;    // 使用定时器T1的模式1（13位计数器）
	TR0 = 1;
	ET0 = 1;        //定时器T1中断允许
}

#endif