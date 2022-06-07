#ifndef  __KEY_H__
#define  __KEY_H__

#include <reg52.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

sbit BEGIN = P2 ^ 0;        //开始
sbit PAUSE = P2 ^ 1;        //暂停

sbit PRE_KEY = P2 ^ 2;        //上一首
sbit NEXT_KEY = P2 ^ 3;        //下一首

sbit Use_1 = P2 ^ 5;        //1
sbit Use_2 = P2 ^ 6;        //1
sbit Use_3 = P2 ^ 7;        //1

unsigned char press_key = 0;	//按键  按下后会改变数值  初始值为0
unsigned char open_flag = 1; //暂停时为0  播放时为1
unsigned char music_crr = 0; //当前是播放哪一首音乐  可以为0  1  2  分别是是三首歌

unsigned char ScanKey(void)
{
    if (BEGIN == 0)  //是否按下
    {
        delay(1);     //延时防止电平抖动
        if (BEGIN == 0)
        {
            while (BEGIN == 0)
                ; //等待松开
            return 1;
        }
    }
    if (PAUSE == 0)
    {
        delay(1);
        if (PAUSE == 0)
        {
            while (PAUSE == 0)
                ;
            return 2;
        }
    }
    if (PRE_KEY == 0)
    {
        delay(1);
        if (PRE_KEY == 0)
        {
            while (PRE_KEY == 0)
                ;
            return 3;
        }
    }
    if (NEXT_KEY == 0)
    {
        delay(1);
        if (NEXT_KEY == 0)
        {
            while (NEXT_KEY == 0)
                ;
            return 4;
        }
    }
    if (Use_1 == 0)//选择第1首歌的按键按下
    {
        delay(1);
        if (Use_1 == 0)
        {
            while (Use_1 == 0)
                ;
            return 5;
        }
    }
    if (Use_2 == 0) //选择第二首歌的按键按下
    {
        delay(1);
        if (Use_2 == 0)
        {
            while (Use_2 == 0)
                ;
            return 6;
        }
    }
    if (Use_3 == 0)//选择第3首歌的按键按下
    {
        delay(1);
        if (Use_3 == 0)
        {
            while (Use_3 == 0)
                ;
            return 7;
        }
    }
    return 0;
}

void delay_key(void)
{
    if (press_key == 1)     //开始
    {
        open_flag = 1;    //开始
        press_key = 0;
    }
    if (press_key == 2)     //暂停
    {
        open_flag = 0;    //暂停
        press_key = 0;      
    }
    if (press_key == 3)      //上一首
    {
        press_key = 0;
        if (music_crr > 0)
        {
            music_crr = (music_crr - 1) % 3;
        } else
        {
            music_crr = 2;    //如果是第0首歌  那么按上一首就是第2首
        }
        LCD_write_char(9,0,music_crr+'1');//显示歌曲号
    }
    if (press_key == 4)      //下一首
    {
        press_key = 0;
        music_crr = (music_crr + 1) % 3;
        LCD_write_char(9,0,music_crr+'1'); //显示歌曲号
    }
    if (press_key == 5)       //1
    {
        press_key = 0;
        music_crr=0;
        LCD_write_char(9,0,music_crr+'1'); //显示歌曲号
        open_flag = 1;    //开始
        
    }
    if (press_key == 6)       //2
    {
        press_key = 0;
        music_crr=1;
        LCD_write_char(9,0,music_crr+'1'); //显示歌曲号
        open_flag = 1;    //开始
    }
    if (press_key == 7)       //3
    {
        press_key = 0;
        music_crr=2;
        LCD_write_char(9,0,music_crr+'1'); //显示歌曲号
        open_flag = 1;    //开始
    }
    if (open_flag == 1)
        {
TR0=1;
        }else
        {
             TR0=0;
        }
}

#endif