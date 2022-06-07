#include<reg52.h>
#include<intrins.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "LCD1602.h"
#include "DELAY.h"
#include "MUSIC.h"
#include "TIMER.h"
#include "KEY.h"

#define uchar unsigned char 
#define uint unsigned int
#define u8 unsigned char 
#define u16 unsigned int

sbit BUZZ = P1 ^ 6;    //蜂鸣器

unsigned int C;     //储存定时器的定时常数
unsigned char u, t;	 //音乐所用的变量
unsigned char velocity = 60;	//控制节拍使用的 这里100表示一个拍子100ms

char number = 0;    /* 计数 */
uint length = 0;
void main()
{
    LCD_init();
    LCD_write_str(0,0,"   WELCOME!");
    delay(1000);
    LCD_write_str(0,0,"  MUSIC:    ");
    LCD_write_char(9,0,'1');    
    init_timer();
    TR1 = 0;     //关闭定时器
    BUZZ = 0;   //关闭蜂鸣器
    open_flag = 0; //关闭音乐
    TR0 = 0;     //关闭定时器

    while (1)
    {
        press_key = ScanKey();    //获取按下的键
        delay_key();      //将按下的键值传入处理函数 改变状态变量
        if (music_crr == 0 && open_flag == 1)
        {
            u = 0;   //从第1个音符f[0]开始播放
            length = sizeof(music0);
            while (music0[u] != 0xff)            //只要没有读到结束标志就继续播放
            {
                press_key = ScanKey();    //获取按下的键
                delay_key();      //将按下的键值传入处理函数 改变状态变量
                if (music_crr != 0)    //切换音乐
                {
                    init_timer();
                    TR1 = 0;     //关闭定时器
                    BUZZ = 1;   //关闭蜂鸣器
                    break;
                }
                if (open_flag == 0) //如果暂停音乐
                {
                    while (open_flag == 0)
                    {
                        press_key = ScanKey();    //获取按下的键
                        delay_key();      //将按下的键值传入处理函数 改变状态变量
                    }
                }
                C = 460830 / music0[u];
                TH1 = (8192 - C) / 32;   //可证明这是13位计数器TH0高8位的赋初值方法     5
                TL1 = (8192 - C) % 32;   //可证明这是13位计数器TL0低5位的赋初值方法
                TR1 = 1;             //启动定时器T0
                length--;
                for (t = 0; t < music0_JP[u]; t++)  //控制节拍数
                    delay1();          //延时1个节拍单位
                TR1 = 0;                   //关闭定时器T1
                u++;                        //播放下一个音符
            }
            init_timer();
            TR1 = 0;     //关闭定时器
            BUZZ = 1;   //关闭蜂鸣器
        }
        if (music_crr == 1 && open_flag == 1)
        {
            u = 0;   //从第1个音符f[0]开始播放
            length = sizeof(music1);
            
            while (music1[u] != 0xff)            //只要没有读到结束标志就继续播放
            {
                press_key = ScanKey();    //获取按下的键
                delay_key();      //将按下的键值传入处理函数 改变状态变量
                if (music_crr != 1)    //切换音乐
                {
                    init_timer();
                    TR1 = 0;     //关闭定时器
                    BUZZ = 1;   //关闭蜂鸣器
                    break;
                }
                if (open_flag == 0) //如果暂停音乐
                {
                    while (open_flag == 0)
                    {
                        press_key = ScanKey();    //获取按下的键
                        delay_key();      //将按下的键值传入处理函数 改变状态变量
                    }
                }
                C = 460830 / music1[u];
                TH1 = (8192 - C) / 32;   //可证明这是13位计数器TH0高8位的赋初值方法     5
                TL1 = (8192 - C) % 32;   //可证明这是13位计数器TL0低5位的赋初值方法
                TR1 = 1;             //启动定时器T0
                length--;
                for (t = 0; t < music1_JP[u]; t++)  //控制节拍数
                    delay1();          //延时1个节拍单位
                TR1 = 0;                   //关闭定时器T1
                u++;                        //播放下一个音符
            }
            init_timer();
            TR1 = 0;     //关闭定时器
            BUZZ = 1;   //关闭蜂鸣器
        }
        if (music_crr == 2 && open_flag == 1)
        {
            u = 0;   //从第1个音符f[0]开始播放
            length = sizeof(music2);
            
            while (music2[u] != 0xff)            //只要没有读到结束标志就继续播放
            {
                press_key = ScanKey();    //获取按下的键
                delay_key();      //将按下的键值传入处理函数 改变状态变量
                if (music_crr != 2)    //切换音乐
                {
                    init_timer();
                    TR1 = 0;     //关闭定时器
                    BUZZ = 1;   //关闭蜂鸣器
                    break;
                }
                if (open_flag == 0) //如果暂停音乐
                {
                    while (open_flag == 0)
                    {
                        press_key = ScanKey();    //获取按下的键
                        delay_key();      //将按下的键值传入处理函数 改变状态变量
                    }
                }
                C = 460830 / music2[u];
                TH1 = (8192 - C) / 32;   //可证明这是13位计数器TH0高8位的赋初值方法     5
                TL1 = (8192 - C) % 32;   //可证明这是13位计数器TL0低5位的赋初值方法
                TR1 = 1;             //启动定时器T0
                length--;
                for (t = 0; t < music2_JP[u] / 2; t++)  //控制节拍数
                    delay1();          //延时1个节拍单位
                TR1 = 0;                   //关闭定时器T1
                u++;                        //播放下一个音符
            }

            init_timer();
            TR1 = 0;     //关闭定时器
            BUZZ = 1;   //关闭蜂鸣器
        }
    }
}

//定时器中断加入中断等级
void Time1(void) interrupt 3   //T1定时器的中断等级要注意  是3
{
    BUZZ=!BUZZ;      //将P1.6引脚输出电平取反，形成方波  
    TH1=(8192-C)/32;//可证明这是13位计数器TH0高8位的赋初值方法
    TL1=(8192-C)%32;//可证明这是13位计数器TL0低5位的赋初值方法 
}