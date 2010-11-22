#include "common.h"

//draw circle
void fb_circle(int x, int y, int r, int color)
{
	double m, n, degree;
	int p, q;
	short color16;

	for(degree = 0; degree <= 2*3.14; degree = degree + 3.14/180)
	{
		m = r * cos(degree);
		n = r * sin(degree);

		p = x + (int)m;
		q = y + (int)n;

//		color16 = bit32to16(color);
		*(fbmem + (w * q + p)) = color;
	}

	return;
}

//draw small point
void fb_small_black_point(int x, int y)
{
	int r = 4;
	int color = 0x000000;

	for(; r >= 0; r--)
	{
		fb_circle(x, y, r, color);
	}

	return;
}

//draw white point
void fb_white_point(int x, int y)
{
	int r = 18;
	int color = 0xbebebe;

	for(; r>= 0; r--)
	{
		color = color + 0x030303;
		fb_circle(x, y, r, color);
	}

	return;
}

//draw black point
void fb_black_point(int x, int y)
{
	int r = 18;
	int color = 0x151515;

	for(; r >= 0; r--)
	{
		color = color + 0x040404;
		fb_circle(x, y, r, color);
	}

	return;
}

//draw grid
void fb_grid(int x, int y,  int color)
{
	int i = 0;
	int grid_len;
	int tmp = 0;
	int y_tmp;
	short color16;

	y_tmp = y;

	grid_len = (NUM - 1) * SPACE;

	//draw h_line
	for(tmp = 0; tmp <= grid_len; tmp = tmp + SPACE)
	{
		for(i= 0; i < grid_len; i++)
		{
//			color16 = bit32to16(color);
			*(fbmem + (y * w + x + i)) = color;
		}
		y = y + SPACE;
	}

	//draw s_line
	y = y_tmp;
	for(tmp = 0; tmp <= grid_len; tmp = tmp + SPACE)
	{
		for(i = 0; i < grid_len; i++)
		{
//			color16 = bit32to16(color);
			*(fbmem + (y * w + x + i * w)) = color;
		}
		x = x + SPACE;
	}

	return;
}

//draw bg
void fb_bg(int x, int y, int color)
{
	int bg_len;
	int i = 0;
	int j = 0;
	short color16;

	bg_len = (NUM - 1) * SPACE + 60;

	for(i = 0; i < bg_len; i++)
	{
		for(j = 0; j < bg_len; j++)
		{
//			color16 = bit32to16(color);
			*(fbmem + (y * w + x + j)) = color;
		}
		y = y + 1;
	}
}

