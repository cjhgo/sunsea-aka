/************************************************************
*  名称：五子棋小游戏
*
*  版本：v1.0
*
*  作者：张双喜
*
*  日期：2010年11月14日
*
*  模块功能：声明每个模块可能涉及的公共内容 
* 
 ***********************************************************/

#ifndef __COMMON_H_
#define __COMMON_H_

#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <math.h>
#include <unistd.h>

#define NUM 15
#define SPACE 40
#define X 650			//draw from X
#define Y 100			//draw from Y

#define C_WIDTH 10		//mouse width
#define C_HEIGHT 17		//mouse height
#define T___ 0xff0000
#define X___ 0xffffff
#define BORD 0x0

extern int *fbmem;		//use 32
//short *fbmem;		//use 16
extern int w, h;
extern int cx, cy;
extern int old_cx, old_cy;
extern int buf[C_WIDTH * C_HEIGHT];		//use 32
//short buf[C_WIDTH * C_HEIGHT];	//use 16
extern int pos_flag[NUM][NUM];			//0:not exist chess	1:exist player chess	 2:exist computer chess
extern int chess_num;

//mouse buf[8]
extern char buf_mouse[8];

//two win table
extern int player_win_table[NUM][NUM];
extern int computer_win_table[NUM][NUM];

//two chess table
//extern int player_chess[NUM][NUM];
//extern int computer_chess[NUM][NUM];

//player max
extern int player_max_x;
extern int player_max_y;
extern int player_max;

//computer max
extern int computer_max_x;
extern int computer_max_y;
extern int computer_max;

//score standard
extern int F[2][5];
extern int L[2][5];

//number 0--9
extern unsigned char num[10][16];

#endif
