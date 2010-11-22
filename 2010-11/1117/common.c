/************************************************************
*  名称：五子棋小游戏
*
*  版本：v1.0
*
*  作者：张双喜
*
*  日期：2010年11月14日
*
*  模块功能： 定义每个模块可能涉及的公共内容 
* 
 ***********************************************************/

#include "common.h"

int *fbmem;		//use 32
//short *fbmem;		//use 16
int w, h;
int cx, cy;
int old_cx, old_cy;
int buf[C_WIDTH * C_HEIGHT];		//use 32
//short buf[C_WIDTH * C_HEIGHT];	//use 16
int pos_flag[NUM][NUM] = {0};			//0:not exist chess	1:exist player chess	 2:exist computer chess
int chess_num = 1;

//mouse buf[8]
char buf_mouse[8] = {0};

//two win table
int player_win_table[NUM][NUM] = {0};
int computer_win_table[NUM][NUM] = {0};

//two chess table
int player_chess[NUM][NUM] = {0};
int computer_chess[NUM][NUM] = {0};

//player max
int player_max_x = 0;
int player_max_y = 0;
int player_max;

//computer max
int computer_max_x = 0;
int computer_max_y = 0;
int computer_max;

//score standard
int F[2][5] = {{0, 2, 5, 50, 16000}, {0, 10, 30, 750, 16000}};
int L[2][5] = {{0, 1, 5, 50, 3750}, {0, 10, 30, 150, 4000}};
