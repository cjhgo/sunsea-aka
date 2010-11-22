/************************************************************
*  名称：五子棋小游戏
*
*  版本：v1.0
*
*  作者：张双喜
*
*  日期：2010年11月14日
*
*  模块功能：在每个棋子上画数字 
* 
 ***********************************************************/

#include "common.h"

//display number
void fb_num(int chess_num, int x, int y, int color)
{
	int i, j, k, n;
	int bit;
	int chess_num_old;
	int y_old;
	int dx, dy, bit_num;

	chess_num_old = chess_num;
	n = 0;
	y_old = y;
	if(chess_num >= 0 && chess_num <= 9)
	{
		bit_num = 1;
		dx = 3;
		dy = 7;
	}
	else if(chess_num >= 10 && chess_num <= 99)
	{
		bit_num = 2;
		dx = 1;
		dy = 7;
	}
	else if(chess_num >= 100 && chess_num <= 999)
	{
		bit_num = 3;
		dx = -4;
		dy = 7 ;
	}

	while(chess_num_old != 0)
	{
		y = y_old;
		for(j = 0; j < 16; j++)
		{
			for(i = 7, k = 0; i >= 0; i--, k++)
			{
				bit = chess_num_old % 10;
				if(num[bit][j] & (1 << i))
				{
					*(fbmem + (y - dy) * w + x + k - n * 8 - dx) = color;
				}
			}
			y++;
		}
		chess_num_old = chess_num_old / 10;
		n++;
	}
	return;
}	
