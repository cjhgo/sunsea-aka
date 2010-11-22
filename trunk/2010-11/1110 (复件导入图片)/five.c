#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
//#include <sys/ioctl.h>
#include <linux/fb.h>
//#include <sys/types.h>
//#include <sys/stat.h>
#include <math.h>
#include "bg.h"
#include "black.h"
#include "white.h"


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

//background
void fb_bg(int x, int y)
{
	int i = 0;
	int j = 0;
	int color;

	for(i = 0; i < 1382400; i = i + 4)
	{
		color = bg_rgb_data[i];
		color = (bg_rgb_data[i + 1] << 8) | color;
		color = (bg_rgb_data[i + 2] << 16) | color;

		if(j == 600)
		{
			y++;
			j = 0;
			color = bit32to16(color);
			*(fbmem+ y*w + x + j++) = color;
		}
		else
		{
			color = bit32to16(color);
			*(fbmem+ y*w + x + j++) = color;
		}
	}

	return;
}

//white
void fb_white(int x, int y)
{
	int i = 0;
	int j = 0;
	int color;

	for(i = 0; i < 6400; i = i + 4)
	{
		color = white_rgb_data[i];
		color = (white_rgb_data[i + 1] << 8) | color;
		color = (white_rgb_data[i + 2] << 16) | color;
//		printf("color = 0x%x\n", color); 

		if(j == 40)
		{
			y++;
			j = 0;
			if(color != 0xff0000)
			{
				color = bit32to16(color);
				*(fbmem+ y*w + x + j++) = color;
			}
			else
			{
				j++;
			}
		}
		else
		{
			if(color != 0xff0000)
			{
				color = bit32to16(color);
				*(fbmem+ y*w + x + j++) = color;
			}
			else
			{
				j++;
			}
		}
	}

	return;
}

//black
void fb_black(int x, int y)
{
	int i = 0;
	int j = 0;
	int color;

	for(i = 0; i < 6400; i = i + 4)
	{
		color = black_rgb_data[i];
		color = (black_rgb_data[i + 1] << 8) | color;
		color = (black_rgb_data[i + 2] << 16) | color;

		if(j == 40)
		{
			y++;
			j = 0;
			if(color != 0xff0000)
			{
				color = bit32to16(color);
				*(fbmem+ y*w + x + j++) = color;
			}
			else
			{
				j++;
			}
		}
		else
		{
			if(color != 0xff0000)
			{
				color = bit32to16(color);
				*(fbmem+ y*w + x + j++) = color;
			}
			else
			{
				j++;
			}
		}
	}

	return;
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
void move_mouse(int fd_mouse)
{
	int i, j;
	int k = 0;

//	printf("cx = %d, cy = %d\n", cx, cy);
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

void point(int x, int y)
{
	*(fbmem + y * w + x) = bit32to16(0xffff);
}

int main(int argc, char* argv[])
{
	int fd, fd_mouse;
	struct fb_var_screeninfo fb_var;
	int x, y, num, space;
	int bits;

	x = 400;
	y = 50;
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

	//background
	fb_bg(x - 20, y - 19);
//	point(x, y);
//	point(x + 40, y + 37);

	//white
	fb_white(700, 100);

	//black
	fb_black(800, 200);

	//mouse
	fd_mouse = open_mouse();
	printf("fd_mouse = %d\n", fd_mouse); 
	cx = w / 2;
	cy = h / 2;
//	fb_mouse(cx, cy);
	while(1)
	{
		move_mouse(fd_mouse);
//		printf("cx = %d, cy = %d\n", cx, cy);
	}


	close(fd_mouse);
	close(fd);

	return 0; 
}
