#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <math.h>
#include "number.h"

#define NUM 15
#define SPACE 40
#define X 650			//draw from X
#define Y 100			//draw from Y

#define C_WIDTH 10		//mouse width
#define C_HEIGHT 17		//mouse height
#define T___ 0xff0000
#define X___ 0xffffff
#define BORD 0x0

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
//int L[2][5] = {{0, 1, 5, 50, 3750}, {0, 10, 30, 150, 4000}};
int L[2][5] = {{0, 1, 5, 50, 16000}, {0, 10, 30, 150, 16000}};


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
//					printf("1"); 
					*(fbmem + (y - dy) * w + x + k - n * 8 - dx) = color;
				}
				else
				{
//					printf(" "); 
				}
			}
//			printf("\n"); 
			y++;
		}
		chess_num_old = chess_num_old / 10;
		n++;
	}
	return;
}

//32 bits to 16 bits
short bit32to16(int color32)
{
	short color16;

	int red32, green32, blue32;
	int red16, green16, blue16;
	
	blue32 = color32 & 0xff;
	green32 = (color32 >> 8) & 0xff;
	red32 = (color32 >> 16) & 0xff;

	blue16 = blue32 * 0x1f / 0xff;
	green16 = green32 * 0x3f / 0xff;
	red16 = red32 * 0x1f / 0xff;

	color16 = red16 << 11 | green16 << 5 | blue16;

	return color16;
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
/*
//get player win table
void get_player_chess(void)
{
	int i, j;

	for(i = 0; i < NUM; i++)
	{
		for(j = 0; j < NUM; j++)
		{
			if(pos_flag[i][j] == 1)
			{
				player_chess[i][j] = 1;		//1:white chess
			}
			else
			{
				player_chess[i][j] = 0;		//0:no chess
			}
		}
	}
	
	return;
}

//get computer win table
void get_computer_chess(void)
{
	int i, j;

	for(i = 0; i < NUM; i++)
	{
		for(j = 0; j < NUM; j++)
		{
			if(pos_flag[i][j] == 2)
			{
				computer_chess[i][j] = 2;		//1:white chess
			}
			else
			{
				computer_chess[i][j] = 0;		//0:no chess
			}
		}
	}
	
	return;
}
*/
//judge player chess a pos score and save to player win table
void get_player_win_table_max(void)
{
	int i = 0, j = 0, k, p, m, n;
	int left_score, right_score, up_score, down_score, left_up_score, right_up_score, left_down_score, right_down_score;

	for(i = 0; i < NUM; i++)
	{
		for(j = 0; j < NUM; j++)
		{
			player_win_table[i][j] = 0;
		}
	}

	for( i = 0; i < NUM; i++)
	{
		for(j = 0; j < NUM; j++)
		{
			if(pos_flag[i][j] == 0)
			{
				//judge left
				k = j - 1;
				m = 0;
				n = 0;
				for(; k >= 0; k--)
				{
					if(pos_flag[i][k] == 1)
						n++;
					else if(pos_flag[i][k] == 2)
					{
						m = 0;
						break;
					}
					else if(pos_flag[i][k] == 0)
					{
						m = 1;
						break;
					}
				}
				if(n == 5)
				{
					printf("white win!\n"); 
					exit(0);
				}
				left_score = F[m][n];

				//judge right
				k = j + 1;
				m = 0;
				n = 0;
				for(; k < NUM; k++)
				{
					if(pos_flag[i][k] == 1)
						n++;
					else if(pos_flag[i][k] == 2)
					{
						m = 0;
						break;
					}
					else if(pos_flag[i][k] == 0)
					{
						m = 1;
						break;
					}
				}
				if(n == 5)
				{
					printf("white win!\n"); 
					exit(0);
				}
				right_score = F[m][n];

				//judge up
				k = i - 1;
				m = 0;
				n = 0;
				for(; k >= 0; k--)
				{
					if(pos_flag[k][j] == 1)
						n++;
					else if(pos_flag[k][j] == 2)
					{
						m = 0;
						break;
					}
					else if(pos_flag[k][j] == 0)
					{
						m = 1;
						break;
					}
				}
				if(n == 5)
				{
					printf("white win!\n"); 
					exit(0);
				}
				up_score = F[m][n];

				//judge down
				k = i + 1;
				m = 0;
				n = 0;
				for(; k < NUM; k++)
				{
					if(pos_flag[k][j] == 1)
						n++;
					else if(pos_flag[k][j] == 2)
					{
						m = 0;
						break;
					}
					else if(pos_flag[k][j] == 0)
					{
						m = 1;
						break;
					}
				}
				if(n == 5)
				{
					printf("white win!\n"); 
					exit(0);
				}
				down_score = F[m][n];

				//judge left up
				k = i - 1;
				p = j - 1;
				m = 0;
				n = 0;
				for(; k >= 0, p >=0; k--, p--)
				{
					if(pos_flag[k][p] == 1)
						n++;
					else if(pos_flag[k][p] == 2)
					{
						m = 0;
						break;
					}
					else if(pos_flag[k][p] == 0)
					{
						m = 1;
						break;
					}
				}
				if(n == 5)
				{
					printf("white win!\n"); 
					exit(0);
				}
				left_up_score = F[m][n];

				//judge right up
				k = i - 1;
				p = j + 1;
				m = 0;
				n = 0;
				for(; k >= 0, p < NUM; k--, p++)
				{
					if(pos_flag[k][p] == 1)
						n++;
					else if(pos_flag[k][p] == 2)
					{
						m = 0;
						break;
					}
					else if(pos_flag[k][p] == 0)
					{
						m = 1;
						break;
					}
				}
				if(n == 5)
				{
					printf("white win!\n"); 
					exit(0);
				}
				right_up_score = F[m][n];

				//judge left down
				k = i - 1;
				p = j + 1;
				m = 0;
				n = 0;
				for(; k >= 0, p < NUM; k--, p++)
				{
					if(pos_flag[k][p] == 1)
						n++;
					else if(pos_flag[k][p] == 2)
					{
						m = 0;
						break;
					}
					else if(pos_flag[k][p] == 0)
					{
						m = 1;
						break;
					}
				}
				if(n == 5)
				{
					printf("white win!\n"); 
					exit(0);
				}
				left_down_score = F[m][n];

				//judge right down
				k = i + 1;
				p = j + 1;
				m = 0;
				n = 0;
				for(; k < NUM, p < NUM; k++, p++)
				{
					if(pos_flag[k][p] == 1)
						n++;
					else if(pos_flag[k][p] == 2)
					{
						m = 0;
						break;
					}
					else if(pos_flag[k][p] == 0)
					{
						m = 1;
						break;
					}
				}
				if(n == 5)
				{
					printf("white win!\n"); 
					exit(0);
				}
				right_down_score = F[m][n];

				player_win_table[i][j] = left_score + right_score + up_score + down_score + left_up_score + right_up_score + 
					left_down_score + right_down_score;
			}
		}
	}

	//printf win_table
	printf("---------------------------\n"); 
	for(i = 0; i < NUM; i++)
	{
		for(j = 0; j < NUM; j++)
		{
			printf("%d  ", player_win_table[i][j]); 
		}
		printf("\n"); 
	}

	player_max = player_win_table[0][0];
	for(i = 0; i < NUM; i++)
	{
		for(j = 0; j < NUM; j++)
		{
			if(player_win_table[i][j] > player_max)
			{
				player_max_x = i;
				player_max_y = j;
				player_max = player_win_table[i][j];
			}
		}
	}

	return;
}

//judge computer chess a pos score and save to player win table
void get_computer_win_table_max(void)
{
	int i = 0, j = 0, k, p, m, n;
	int left_score, right_score, up_score, down_score, left_up_score, right_up_score, left_down_score, right_down_score;

	for(i = 0; i < NUM; i++)
	{
		for(j = 0; j < NUM; j++)
		{
			computer_win_table[i][j] = 0;
		}
	}

	for(i = 0; i < NUM; i++)
	{
		for(j = 0; j < NUM; j++)
		{
			if(pos_flag[i][j] == 0)
			{
				//judge left
				k = j - 1;
				m = 0;
				n = 0;
				for(; k >= 0; k--)
				{
					if(pos_flag[i][k] == 2)
						n++;
					else if(pos_flag[i][k] == 1)
					{
						m = 0;
						break;
					}
					else if(pos_flag[i][k] == 0)
					{
						m = 1;
						break;
					}
				}
				if(n == 5)
				{
					printf("black win!\n"); 
					exit(0);
				}
				left_score = L[m][n];

				//judge right
				k = j + 1;
				m = 0;
				n = 0;
				for(; k < NUM; k++)
				{
					if(pos_flag[i][k] == 2)
						n++;
					else if(pos_flag[i][k] == 1)
					{
						m = 0;
						break;
					}
					else if(pos_flag[i][k] == 0)
					{
						m = 1;
						break;
					}
				}
				if(n == 5)
				{
					printf("balck win!\n"); 
					exit(0);
				}
				right_score = L[m][n];

				//judge up
				k = i - 1;
				m = 0;
				n = 0;
				for(; k >= 0; k--)
				{
					if(pos_flag[k][j] == 2)
						n++;
					else if(pos_flag[k][j] == 1)
					{
						m = 0;
						break;
					}
					else if(pos_flag[k][j] == 0)
					{
						m = 1;
						break;
					}
				}
				if(n == 5)
				{
					printf("balck win!\n"); 
					exit(0);
				}
				up_score = L[m][n];

				//judge down
				k = i + 1;
				m = 0;
				n = 0;
				for(; k < NUM; k++)
				{
					if(pos_flag[k][j] == 2)
						n++;
					else if(pos_flag[k][j] == 1)
					{
						m = 0;
						break;
					}
					else if(pos_flag[k][j] == 0)
					{
						m = 1;
						break;
					}
				}
				if(n == 5)
				{
					printf("balck win!\n"); 
					exit(0);
				}
				down_score = L[m][n];

				//judge left up
				k = i - 1;
				p = j - 1;
				m = 0;
				n = 0;
				for(; k >= 0, p >=0; k--, p--)
				{
					if(pos_flag[k][p] == 2)
						n++;
					else if(pos_flag[k][p] == 1)
					{
						m = 0;
						break;
					}
					else if(pos_flag[k][p] == 0)
					{
						m = 1;
						break;
					}
				}
				if(n == 5)
				{
					printf("balck win!\n"); 
					exit(0);
				}
				left_up_score = L[m][n];

				//judge right up
				k = i - 1;
				p = j + 1;
				m = 0;
				n = 0;
				for(; k >= 0, p < NUM; k--, p++)
				{
					if(pos_flag[k][p] == 2)
						n++;
					else if(pos_flag[k][p] == 1)
					{
						m = 0;
						break;
					}
					else if(pos_flag[k][p] == 0)
					{
						m = 1;
						break;
					}
				}
				if(n == 5)
				{
					printf("balck win!\n"); 
					exit(0);
				}
				right_up_score = L[m][n];

				//judge left down
				k = i - 1;
				p = j + 1;
				m = 0;
				n = 0;
				for(; k >= 0, p < NUM; k--, p++)
				{
					if(pos_flag[k][p] == 2)
						n++;
					else if(pos_flag[k][p] == 1)
					{
						m = 0;
						break;
					}
					else if(pos_flag[k][p] == 0)
					{
						m = 1;
						break;
					}
				}
				if(n == 5)
				{
					printf("balcke win!\n"); 
					exit(0);
				}
				left_down_score = L[m][n];

				//judge right down
				k = i + 1;
				p = j + 1;
				m = 0;
				n = 0;
				for(; k < NUM, p < NUM; k++, p++)
				{
					if(pos_flag[k][p] == 2)
						n++;
					else if(pos_flag[k][p] == 1)
					{
						m = 0;
						break;
					}
					else if(pos_flag[k][p] == 0)
					{
						m = 1;
						break;
					}
				}
				if(n == 5)
				{
					printf("black win!\n"); 
					exit(0);
				}
				right_down_score = L[m][n];

				computer_win_table[i][j] = left_score + right_score + up_score + down_score + left_up_score + right_up_score + 
					left_down_score + right_down_score;
			}
		}
	}

	//printf win_table
	printf("--------------------------------\n"); 
	for(i = 0; i < NUM; i++)
	{
		for(j = 0; j < NUM; j++)
		{
			printf("%d  ", computer_win_table[i][j]); 
		}
		printf("\n"); 
	}

	computer_max = computer_win_table[0][0];
	for(i = 0; i < NUM; i++)
	{
		for(j = 0; j < NUM; j++)
		{
			if(computer_win_table[i][j] > computer_max)
			{
				computer_max_x = i;
				computer_max_y = j;
				computer_max = computer_win_table[i][j];
			}
		}
	}

	return;
}

//people play chess
void player(int *fd_mouse, int *player_flag)
{
	int x_old, y_old;
	int i, j;

	if(buf_mouse[0] & 0x1)
	{
		memset(buf_mouse, 0, 8);
		move_mouse(fd_mouse);
		if((buf_mouse[0] & 0x1) == 0)
		{
			x_old = cx;
			y_old = cy;

			click_pos();
			if((cx > X - 20) && (cy > Y - 20) && (cx < X + NUM * SPACE - 30) && (cy < Y + NUM * SPACE - 30) &&
					(pos_flag[(cx-X) / SPACE][(cy-Y) / SPACE] == 0))
			{
				fb_white_point(cx, cy);
				fb_num(chess_num++, cx, cy, 0x0);
				pos_flag[(cx - X) / SPACE][(cy - Y) / SPACE] = 1;
				*player_flag = 0;
			}
			cx = x_old;
			cy = y_old;
/*			printf("==========================================\n"); 
			for(i = 0; i < NUM; i++)
			{
				for(j = 0; j < NUM; j++)
				{
					printf("%d  ", pos_flag[i][j]); 
				}
				printf("\n"); 
			}*/
		}
	}


	return;
}

//computer play chess
void computer(void)
{
	int x, y;

	get_player_win_table_max();
	get_computer_win_table_max();

	if(computer_max > player_max)
	{
		printf("computer\n"); 
		x = computer_max_x;
		y = computer_max_y;
		
		pos_flag[x][y] = 2;
		printf("x = %d, y = %d\n", x, y); 
	
		x = X + x * SPACE;
		y = Y + y * SPACE;

		fb_black_point(x, y);
		fb_num(chess_num++, x, y, 0xffffff);
	}
	else
	{
		printf("player\n"); 
		x = player_max_x;
		y = player_max_y;

		pos_flag[x][y] = 2;
		printf("x = %d, y = %d\n", x, y); 

		x = X + x * SPACE;
		y = Y + y * SPACE;

		fb_black_point(x, y);
		fb_num(chess_num++, x, y, 0xffffff);
	}
	
	get_player_win_table_max();
	get_computer_win_table_max();

	return;
}

//main
int main(int argc, char* argv[])
{
	int fd, fd_mouse;
	struct fb_var_screeninfo fb_var;
	int bits;
//	int ret_read_mouse = -1;		//-1:no click	0:click
	int player_flag = -1;
	int i, j ;

	//open fb0
	fd = open("/dev/fb0", O_RDWR);
	if(fd < 0)
	{
		printf("open fb0 error!\n"); 
		exit(0);
	}

	ioctl(fd, FBIOGET_VSCREENINFO, &fb_var);
	w = fb_var.xres;
	h = fb_var.yres;
	bits = fb_var.bits_per_pixel;
	printf("Framebuffer:%d * %d\n", w ,h);
	printf("Bits:%d\n", bits); 
	fbmem = mmap(0, w*h*sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0); 		//use 32
//	fbmem = mmap(0, w*h*sizeof(short), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);		//use 16

	//draw background
	fb_bg(X - 30, Y - 30,  0xeedc82);
	fb_grid(X, Y,  0x000000);

	fb_small_black_point(7 * SPACE + X, 7 * SPACE + Y);
	fb_small_black_point(3 * SPACE + X, 3 * SPACE + Y);
	fb_small_black_point(11 * SPACE + X, 3 * SPACE + Y);
	fb_small_black_point(3 * SPACE + X, 11 * SPACE + Y);
	fb_small_black_point(11 * SPACE + X, 11 * SPACE + Y);

	fb_black_point(7 * SPACE + X, 7 * SPACE + Y);
	pos_flag[7][7] = 2;
	fb_num(chess_num++, 7 * SPACE + X, 7 * SPACE + Y, 0xffffff);

	//mouse
	fd_mouse = open_mouse();
	cx = w / 2;
	cy = h / 2;

	while(1)
	{
		move_mouse(&fd_mouse);
		player(&fd_mouse, &player_flag);
	
		if(player_flag == 0)
		{
			computer();						//computer
			player_flag = -1;
		}
		
	}

	close(fd_mouse);
	close(fd);

	return 0; 
}
