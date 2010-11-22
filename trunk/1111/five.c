#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
//#include <sys/ioctl.h>
#include <linux/fb.h>
//#include <sys/types.h>
//#include <sys/stat.h>
#include <math.h>


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
int pos_flag[NUM][NUM] = {0};			//0:not exist chess	1:exist player chess	2:exist computer chess
//int computer[NUM][NUM][4] = {0};
//int player[NUM][NUM][4] = {0};
int com_x, com_y;
int h_x, h_y, h_score;
int s_x, s_y, s_score;
int z_x_x, z_x_y, z_x_score;
int y_x_x, y_x_y, y_x_score;


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

//seat and flag
typedef struct computer_choose_pos
{
	int x;
	int y;
	int direction;		/*1: -		2: |		3: /		4: \	*/
	int score;
}POS;

POS pos_h[NUM];
POS pos_s[NUM];
POS pos_z_x[NUM];
POS pos_y_x[NUM];



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
int read_mouse(int *fd)
{
	char buf[8];
	int dx, dy;
	int ret = -1;

	memset(buf, 0, 8);
	read(*fd, buf, 8);
	dx = buf[1];
	dy = -buf[2];

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

	printf("buf[0] = %d\n", buf[0]); 
	if(buf[0] & 0x1)
	{
		return 0; 
	}

	return ret;

}

//move mouse
int move_mouse(int *fd_mouse)
{
	int i, j;
	int k = 0;
	int ret_read_mouse = -1;

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
	ret_read_mouse = read_mouse(fd_mouse);

	k = 0;
	for(j = 0; j < C_HEIGHT; j++)
	{
		for(i = 0; i < C_WIDTH; i++)
		{
			*(fbmem + old_cy * w + old_cx + i) = buf[k++];
		}
		old_cy++;
	}

	return ret_read_mouse;
}

//judge mouse pos
void chess_pos(void)
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

//people play chess
void player(int ret_read_mouse, int *player_flag)
{
	int x_old, y_old;

	if(ret_read_mouse == 0)
	{
		x_old = cx;
		y_old = cy;

		chess_pos();
		if(cx > X - 20 && cy > Y - 20 && cx < X + NUM * SPACE - 30 && cy < Y + NUM * SPACE - 30 && pos_flag[(cx-X) / SPACE][(cy-Y) / SPACE] == 0)
		{
			fb_white_point(cx, cy);
			pos_flag[(cx - X) / SPACE][(cy - Y) / SPACE] = 1;
			*player_flag = 0;
		}
		cx = x_old;
		cy = y_old;
	}

	return;
}

//get max_score
void max_score(POS pos[])
{
	int max;
	int i;

	max = pos[0].score;
	
	for(i = 0; i < NUM; i++)
	{
		if(pos[i].score >= max )
		{
			h_x = pos[i].x;
			h_y = pos[i].y;
			h_score = pos[i].score;
			max = pos[i].score;
		}
	}

	return;
}

//h_score
void get_h_score(void)
{
	int i, j;
	int h_x, h_y, h_score;

	j = 0;

	for(i = 0; i < NUM; i++)
	{
		pos_h[i].score = 0;
		if(pos_flag[i][j] == 0)
		{
			for(; j < NUM; j++)
			{
				if(pos_flag[i][j+1] == 1)
				{
					pos_h[i].score++;
					pos_h[i].x = i;
					pos_h[i].y = j;
					pos_h[i].direction = 1;		//1: h -
				}
				else
				{
					break;
				}
			}
			j++;
		}
	}

	max_score(pos_h);

	return;
}

//s_score
void get_s_score(void)
{
	int i, j;

	j = 0;

	for(i = 0; i < NUM; i++)
	{
		pos_s[i].score = 0;
		if(pos_flag[i][j] == 0)
		{
			for(; j < NUM; j++)
			{
				if(pos_flag[j+1][i] == 1)
				{
					pos_s[i].score++;
					pos_s[i].x = i;
					pos_s[i].y = j;
					pos_s[i].direction = 2;		//2: s |
				}
				else
				{
					break;
				}
			}
			j++;
		}
	}

	max_score(pos_s);

	return;
}

//z_x_score
void get_y_x_score(void)
{
	int i, j;

	j = 0;

	for(i = 0; i < NUM; i++)
	{
		pos_y_x[i].score = 0;
		if(pos_flag[j][j] == 0)
		{
			for(; j < NUM; j++)
			{
				if(pos_flag[j+1][j+1] == 1)
				{
					pos_y_x[i].score++;
					pos_y_x[i].x = j;
					pos_y_x[i].y = j;
					pos_y_x[i].direction = 3;	/*	3: z_x \	*/
				}
				else
				{
					break;
				}
			}
			j++;
		}
	}

	max_score(pos_y_x);

	return;
}

//y_x_score
void get_z_x_score(void)
{
	int i, j;

	j = 0;

	for(i = NUM; i >= 0; i--)
	{
		pos_z_x[i].score = 0;
		if(pos_flag[i][j] == 0)
		{
			for(; j < NUM; j++)
			{
				if(pos_flag[i][j+1] == 1)
				{
					pos_z_x[i].score++;
					pos_z_x[i].x = i;
					pos_z_x[i].y = j;
					pos_z_x[i].direction = 4;	/*	4: y_x /	*/
				}
				else
				{
					break;
				}
			}
			j++;
		}
	}

	max_score(pos_z_x);

	return;
}

//computer choose pos
void computer_choose_pos(void)
{
	int i;
	int max;
	POS choose_pos[4];

	max = choose_pos[0].score;

	get_h_score();
	get_s_score();
	get_z_x_score();
	get_y_x_score();

	choose_pos[0].x = h_x;
	choose_pos[0].y = h_y;
	choose_pos[0].score = h_score;
	
	choose_pos[1].x = s_x;
	choose_pos[1].y = s_y;
	choose_pos[1].score = s_score;

	choose_pos[2].x = z_x_x;
	choose_pos[2].y = z_x_y;
	choose_pos[2].score = z_x_score;

	choose_pos[3].x = y_x_x;
	choose_pos[3].y = y_x_y;
	choose_pos[3].score = y_x_score;

	for(i = 0; i < 4; i++)
	{
		if(max >= choose_pos[i].score)
		{
			com_x = choose_pos[i].x;
			com_y = choose_pos[i].y;
			max = choose_pos[i].score;
		}
	}

	return;
}

//computer play chess
void computer(void)
{
	printf("---------------------------------------\n"); 
	printf("com_x = %d, com_y = %d\n", com_x, com_y); 
	printf("com_x = %d, com_y = %d\n", com_x, com_y); 

	com_x = com_x * SPACE + X;
	com_y = com_y * SPACE + Y;

	fb_black_point(com_x, com_y);

	return;	
}

int main(int argc, char* argv[])
{
	int fd, fd_mouse;
	struct fb_var_screeninfo fb_var;
	int bits;
	int ret_read_mouse = -1;		//-1:no click	0:click
	int player_flag = -1;

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

	//first black
	fb_black_point(7 * SPACE + X, 7 * SPACE + Y);
	pos_flag[7][7] = 2;

	//mouse
	fd_mouse = open_mouse();
	cx = w / 2;
	cy = h / 2;

	while(1)
	{
		ret_read_mouse = move_mouse(&fd_mouse);
		printf("player_flag = %d\n", player_flag); 
		player(ret_read_mouse, &player_flag);					//player
		printf("player_flag = %d\n", player_flag); 
		if(player_flag == 0)
		{
			computer();							//computer
			player_flag = -1;
		}
	}

	close(fd_mouse);
	close(fd);

	return 0; 
}
