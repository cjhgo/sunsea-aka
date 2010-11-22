#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
//#include <sys/ioctl.h>
#include <linux/fb.h>
//#include <sys/types.h>
//#include <sys/stat.h>
#include <math.h>
//#include "bg.h"
//#include "black.h"
//#include "white.h"


#define C_WIDTH 10
#define C_HEIGHT 17
#define T___ 0xff0000
#define X___ 0xffffff
#define BORD 0x0

//int *fbmem;	//use 32
short *fbmem;
int w, h;
int cx, cy;
int old_cx, old_cy;
//unsigned short cursor_x;
//unsigned short cursor_y;
//int buf[C_WIDTH * C_HEIGHT];		//use 32
short buf[C_WIDTH * C_HEIGHT];
/*
struct mousevent
{
	int x;
	int y;
	int button;
};
*/

//static mouseevent sys_mevent;

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
				color = bit32to16(color);
				*(fbmem + y * w + x + i) = color;
			}
		}

		y = y++;
	}

	return;
}


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

		color16 = bit32to16(color);
		*(fbmem + (w * q + p)) = color16;
	}

	return;
}

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

void fb_grid(int x, int y, int num, int space, int color)
{
	int i = 0;
	int grid_len;
	int tmp = 0;
	int y_tmp;
	short color16;

	y_tmp = y;

	grid_len = (num - 1) * space;

	//draw h_line
	for(tmp = 0; tmp <= grid_len; tmp = tmp + space)
	{
		for(i= 0; i < grid_len; i++)
		{
			color16 = bit32to16(color);
			*(fbmem + (y * w + x + i)) = color16;
		}
		y = y + space;
	}

	//draw s_line
	y = y_tmp;
	for(tmp = 0; tmp <= grid_len; tmp = tmp + space)
	{
		for(i = 0; i < grid_len; i++)
		{
			color16 = bit32to16(color);
			*(fbmem + (y * w + x + i * w)) = color16;
		}
		x = x + space;
	}

	return;
}

//draw bg
void fb_bg(int x, int y, int num, int space, int color)
{
	int bg_len;
	int i = 0;
	int j = 0;
	short color16;

	bg_len = (num - 1) * space + 60;

	for(i = 0; i < bg_len; i++)
	{
		for(j = 0; j < bg_len; j++)
		{
			color16 = bit32to16(color);
			*(fbmem + (y * w + x + j)) = color;
		}
		y = y + 1;
	}
}

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

int read_mouse(int fd)
{
	char buf[8];
	int dx, dy;
	int ret = -1;

	read(fd, buf, 8);
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
	int ret_read_mouse;

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
	ret_read_mouse = read_mouse(*fd_mouse);

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
void click_pos(int x, int y, int space)
{
	int x_, y_;
	int x_old, y_old;

	x_old = cx;
	y_old = cy;

	x_ = (cx - x) % space;
	y_ = (cy - y) % space;
	
	if(x_ <= 20)
	{
		cx = x_old - x_;
	}
	else
	{
		cx = x_old - x_ + space;
	}

	if(y_ <= 20)
	{
		cy = y_old - y_;
	}
	else
	{
		cy = y_old - y_ + space;
	}

	return;
}

int main(int argc, char* argv[])
{
	int fd, fd_mouse;
	struct fb_var_screeninfo fb_var;
	int x, y, num, space;
	int bits;
	int ret_read_mouse = -1;		//-1:no click	0:click
	int x_old, y_old;

	x = 350;
	y = 100;
	num = 15;
	space = 40;

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
//	fbmem = mmap(0, w*h*sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0); 		//use 32
	fbmem = mmap(0, w*h*sizeof(short), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

	//draw background
	fb_bg(x - 30, y - 30, num, space, 0xeedc82);
	fb_grid(x, y, num, space, 0x000000);

	fb_small_black_point(7 * space + x, 7 * space + y);
	fb_small_black_point(3 * space + x, 3 * space + y);
	fb_small_black_point(11 * space + x, 3 * space + y);
	fb_small_black_point(3 * space + x, 11 * space + y);
	fb_small_black_point(11 * space + x, 11 * space + y);

	fb_white_point(8 * space + x, 8 * space + y);
	fb_black_point(7 * space + x, 7 * space + y);

	//mouse
	fd_mouse = open_mouse();
//	printf("fd_mouse = %d\n", fd_mouse); 
	cx = w / 2;
	cy = h / 2;
	while(1)
	{
		ret_read_mouse = move_mouse(&fd_mouse);
		if(ret_read_mouse == 0)
		{
			x_old = cx;
			y_old = cy;

			click_pos(x, y, space);
			if(cx > x - 20 && cy > y - 20 && cx < x + num * space - 30 && cy < y + num * space - 30)
			{
				fb_white_point(cx, cy);
			}
			cx = x_old;
			cy = y_old;
		}
	}

	close(fd_mouse);
	close(fd);

	return 0; 
}
