#ifndef __DELAY_H__
#define __DELAY_H__

#include <reg52.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 延时1ms		 用于一般延时
void delay(uint z)
{
	uint x;
	while (z--)
	{
		for (x = 125; x > 0; x--)
			;
	}
}

//延时100ms	控制音乐节拍

void delay_M()
{
	uint i, j;
	for (i = 0; i < velocity; i++)
		for (j = 0; j < 125; j++)
			;
}


#enedif
