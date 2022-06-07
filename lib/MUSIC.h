#ifndef __MUSIC_H__
#define __MUSIC_H__

#include <reg52.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//以下是C调低音的音频宏定义
#define L1  262    //将"L1"宏定义为低音"1"的频率262Hz         时间是1/262=3826/2 us    取半周期
#define L2  286    //将"L2"宏定义为低音"2"的频率286Hz
#define L3  311    //将"L3"宏定义为低音"3"的频率311Hz
#define L4  349    //将"L4"宏定义为低音"4"的频率349Hz
#define L5  392    //将"L5"宏定义为低音"5"的频率392Hz
#define L6  440    //将"l_a"宏定义为低音"6"的频率440Hz
#define L7  494    //将"L7"宏定义为低音"7"的频率494Hz
//以下是C调中音的音频宏定义
#define Z1    523     //将"Z1"宏定义为中音"1"的频率523Hz
#define Z2    587     //将"Z2"宏定义为中音"2"的频率587Hz
#define Z3    659     //将"Z3"宏定义为中音"3"的频率659Hz
#define Z4    698     //将"Z4"宏定义为中音"4"的频率698Hz
#define Z5    784     //将"Z5"宏定义为中音"5"的频率784Hz
#define Z6    880     //将"Z6"宏定义为中音"6"的频率880Hz
#define Z7    987     //将"Z7"宏定义为中音"7"的频率523H      
//以下是C调高音的音频宏定义
#define H1  1046    //将"H1"宏定义为高音"1"的频率1046Hz
#define H2  1174    //将"H2"宏定义为高音"2"的频率1174Hz
#define H3  1318    //将"H3"宏定义为高音"3"的频率1318Hz
#define H4  1396    //将"H4"宏定义为高音"4"的频率1396Hz
#define H5  1567    //将"H5"宏定义为高音"5"的频率1567Hz
#define H6  1760    //将"H6"宏定义为高音"6"的频率1760Hz
#define H7  1975    //将"H7"宏定义为高音"7"的频率1975Hz

//天空之城
//每行对应一小节音符
unsigned int code music0[]=
{	L6,L7,Z1,L7,Z1,Z3,L7,L3,L3,L6,L5,L6,Z1,L5,L3,L3,L4,L3,L4,Z1,
    L3,Z1,Z1,Z1,L7,L4,L4,L7,L7,L6,L7,Z1,L7,Z1,Z3,L7,L3,L3,L6,L5,L6,Z1,
    L5, L3,L4,Z1,L7,Z1,Z2,Z2,Z2,Z1,Z1,L6,L7,L5,L6,Z1,Z2, Z3,Z2,Z3,Z5,
    Z2,L5,L5,Z1,L7,Z1,Z3,Z3,L6,Z1,L7,Z2,Z1,L5,L5,Z4,Z3,Z2,Z1,
    Z3,L3,Z3,Z6,Z5,Z5,Z3,Z2,Z1,Z1,Z2,Z1,Z2,Z5,Z3,Z3,
    Z6,Z5,Z3,Z2,Z1,Z1,Z2,Z1,Z2,L7,L6,L6,L7,L6,,0xff}; //以0xff作为音符的结束标志      

//以下是简谱中每个音符的节拍
//"4"对应4个延时单位，"2"对应2个延时单位，"1"对应1个延时单位 
unsigned char code music0_JP[ ]=
{	4,4,12,4,8,8,20,4,4,12,4,8,8,20,4,4,12,4,4,12,
	20,4,4,4,12,4,8,8,20,4,4,12,4,8,8,20,4,4,12,4,8,8,
	32,4,8,4,6,8,4,4,4,16,8,4,6,8,24,4,4,12,4,8,8,
	24,4,4,4,4,8,8,32,4,8,8,6,12,4,16,8,8,8,8,
	30,20,8,16,8,8,4,4,16,8,8,4,4,8,20,8,
	16,16,4,20,8,8,4,4,8,20,4,4,8,8,8};

//告白气球
unsigned int code music1[]=
{	Z1,L7,L7,H1,H1,Z7,H1,Z7,H1,Z1,H1,H2,
    H3,Z7,Z7,Z6,Z7,Z6,Z7,Z6,Z7,H1,
    Z6,H1,H3,H2,H1,H3,H3,H3,H3,H2,H1,H1,H1,Z7,H1,Z7,H1,
    Z7,H1,H2,H3,Z7,Z7,Z6,Z7,Z6,Z7,Z6,Z7,H1,Z6,H1,H3,H2,H1,H1,H1,Z6,Z7,
    H1,H1,H1,H1,Z6,Z6,Z7,H1,H1,H1,H2,H2,H5,H6,Z7,Z7,Z7,Z7,Z5,Z5,Z6,Z7,Z7,
    Z7,H1,H1,H1,H1,H2,H3,H3,H3,Z6,H1,H1,H2,H3,H3,H6,H3,H2,H1,H1,H2,H3,H3,
    H3,H3,H1,H3,H2,H2,Z5,H4,H3,H3,H4,H3,H2,H2,H1,H2,H3,H6,H6,H5,Z7,H1,H2,H2,H1,
	H2,Z5,H4,H3,H3,H4,H3,H2,H2,H1,H2,H3,H6,H6,H5,Z7,H1,H2,H2,H1,H3,Z5,H4,H3,
    H3,H4,H3,H2,H2,H1,H2,H3,H6,H6,H5,Z7,H1,H2,H2,H1,0xff};  

unsigned char code music1_JP[ ]=
{	8,4,16,2,2,2,4,2,2,4,2,2,2,
	2,2,4,2,2,2,4,4,4,4,4,4,4,16,4,4,2,
	2,2,2,2,4,2,2,2,4,4,4,2,2,2,4,2,2,2,
	4,4,4,4,4,4,4,4,32,4,4,4,4,4,4,8,4,4,
	4,4,4,4,8,4,4,4,4,4,4,8,
	4,4,4,4,4,4,8,
	2,4,4,4,4,4,4,8,4,4,4,4,4,2,
	2,8,4,4,4,4,4,8,4,4,4,16,4,4,4,8,4,8,
	4,8,8,4,8,4,8,8,4,8,4,4,4,16,4,4,4,8,4,8,4,8,8,
	4,8,4,8,8,4,8,4,4,4,16,4,4,4,8,4,8,4,8,8,4,8,4,
	8,8,4,8,4,4,4,};

//随意曲目
unsigned int code music2[]=
{	H3,H3,H3,H2,H1,H2,H5,H5,H1,H1,H1,H1,Z6,
	Z7,H3,H3,Z5,Z6,H6,H5,H4,H3,H2,H1,H1,
	Z6,H1,H2,H5,H5,H2,H1,H2,H2,Z1,H3,H3,
	H3,H2,H1,H2,H5,H5,H1,H1,H1,H1,Z6,Z7,
	H3,H3,Z5,Z6,H6,H5,H4,
	H3,H2,H1,H1,Z6,H1,H2,H5,H5,Z5,H2,H1,

	0xff};     

unsigned char code music2_JP[ ]=
{	8,2,2,2,2,4,4,8, 8,2,2,2,2,
	4,4,4,4,8,4,2,2,4,2,2,8,
	2,2,2,2,2,2,2,2,8,8,8,2,2,2,2,4,4,8,8,2,2,2,2,4,4,4,4,8,4,2,2,
	8,2,2,4,2,2,2,2,2,2,4,12,8,8

};


#enedif