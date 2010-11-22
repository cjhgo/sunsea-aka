/************************************************************
*  名称：五子棋小游戏
*
*  版本：v1.0
*
*  作者：张双喜
*
*  日期：2010年11月14日
*
*  模块功能：对鼠标的所有操作，画鼠标，移动鼠标，确定鼠标单击位置
* 
 ***********************************************************/

#include "common.h"

static int cursor_pixel[C_WIDTH * C_HEIGHT] = {
	BORD, T___,  T___, T___, T___, T___, T___, T___, T___, T___,
	BORD, BORD,  T___, T___, T___, T___, T___, T___, T___, T___,
	BORD, X___,  BORD, T___, T___, T___, T___, T___, T___, T___,
	BORD, X___,  X___, BORD, T___, T___, T___, T___, T___, T___,
	BORD, X___,  X___, X___, BORD, T___, T___, T___, T___, T___,
	BORD, X___,  X___, X___, X___, BORD, T___, T___, T___, T___,
	BORD, X___,  X___, X___, X___, X___, BORD, T___, T___, T___,
	BORD, X___,  X___, X___, X___, X___, X___, BORD, T___, T___,
	BORD, X___,  X___, X___, X___, X___, X___, X___, BORD, T___,
	BORD, X___,  X___, X___, X___, X___, X___, X___, X___, BORD,
	BORD, X___,  X___, X___, X___, X___, BORD, BORD, BORD, BORD,
	BORD, X___,  X___, BORD, X___, X___, BORD, T___, T___, T___,
	BORD, X___,  BORD, T___, BORD, X___, X___, BORD, T___, T___,
	BORD, BORD,  T___, T___, BORD, X___, X___, BORD, T___, T___,
	T___, T___,  T___, T___, T___, BORD, X___, X___, BORD, T___,
	T___, T___,  T___, T___, T___, BORD, X___, X___, BORD, T___,
	T___, T___,  T___, T___, T___, T___, BORD, BORD, T___, T___
};

//open mouse dev mice
int open_mouse(void)
{
	int fd;
	
	fd = open("/dev/input/mice", O_RDONLY);
	if(fd < 0)
	{
		printf("open /dev/input/mice error!\n"); 
		return -1;
	}

	return fd;
}

//read mouse get cx cy buf[0]
void read_mouse(int *fd)
{
	int dx, dy;
	int ret = -1;

	memset(buf_mouse, 0, 8);
	read(*fd, buf_mouse, 8);
	dx = buf_mouse[1];
	dy = -buf_mouse[2];

	cx += dx;
	cy += dy;

	if(cx < 0)
	{
		cx = 0;
	}
	if(cx > w - C_WIDTH)
	{
		cx = w - C_WIDTH;
	}

	if(cy < 0)
	{
		cy = 0;
	}
	if(cy > h - C_HEIGHT)
	{
		cy = h - C_HEIGHT;
	}

	return;
}

//draw mouse
void fb_mouse(int x, int y)
{
	int i = 0;
	int j = 0;
	int color;

	for(j = 0; j < C_HEIGHT; j++)
	{

		for(i = 0; i < C_WIDTH; i++)
		{
			color = cursor_pixel[j * C_WIDTH + i];
			if(T___ != color)
			{
//				color16 = bit32to16(color);
				*(fbmem + y * w + x + i) = color;
			}
		}

		y = y++;
	}

	return;
}

//move mouse
void move_mouse(int *fd_mouse)
{
	int i, j;
	int k = 0;

	old_cx = cx;
	old_cy = cy;

	k = 0;
	for(j = 0; j < C_HEIGHT; j++)
	{
		for(i = 0; i < C_WIDTH; i++)
		{
			buf[k++] = *(fbmem + cy * w + cx + i);
		}
		cy++;
	}
	cx = old_cx;
	cy = old_cy;

	fb_mouse(cx, cy);
	read_mouse(fd_mouse);

	k = 0;
	for(j = 0; j < C_HEIGHT; j++)
	{
		for(i = 0; i < C_WIDTH; i++)
		{
			*(fbmem + old_cy * w + old_cx + i) = buf[k++];
		}
		old_cy++;
	}

	return;
}

//judge mouse pos
void click_pos(void)
{
	int x_, y_;
	int x_old, y_old;

	x_old = cx;
	y_old = cy;

	x_ = (cx - X) % SPACE;
	y_ = (cy - Y) % SPACE;
	
	if(x_ <= 20)
	{
		cx = x_old - x_;
	}
	else
	{
		cx = x_old - x_ + SPACE;
	}

	if(y_ <= 20)
	{
		cy = y_old - y_;
	}
	else
	{
		cy = y_old - y_ + SPACE;
	}

	return;
}
