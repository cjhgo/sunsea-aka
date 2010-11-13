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

int *fbmem;
int w, h;
int cx, cy;
unsigned short cursor_x;
unsigned short cursor_y;
int buf[C_WIDTH * C_HEIGHT];
/*
struct mousevent
{
	int x;
	int y;
	int button;
};
*/

//static mouseevent sys_mevent;

static long cursor_pixel[C_WIDTH * C_HEIGHT] = {
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

void fb_mouse(int x, int y)
{
	int i = 0;
	int j = 0;
	long color;

	for(j = 0; j < C_HEIGHT; j++)
	{

		for(i = 0; i < C_WIDTH; i++)
		{
			color = cursor_pixel[j * C_WIDTH + i];
			if(T___ != color)
			{
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
			*(fbmem+ y*w + x + j++) = color;
		}
		else
		{
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

/*
//circle
void fb_circle(int x, int y, int r, int color)
{
	double m, n, degree;
	int p, q;

	for(degree = 0; degree <= 2*3.14; degree = degree + 3.14/180)
	{
		m = r * cos(degree);
		n = r * sin(degree);

		p = x + (int)m;
		q = y + (int)n;

		*(fbmem + (w * q + p)) = color;
	}

	return;
}

//black
void fb_white(int x, int y)
{
	int r = 18;
	int color = 0xbebebe;

	for(; r >= 0; r--)
	{
		color = color + 0x030303;
		fb_circle(x, y, r, color);
	}

	return;
}

//white
void fb_black(int x, int y)
{
	int r = 18;
	int color = 0x151515;

	for(; r >= 0; r--)
	{
		color = color + 0x080808;
		fb_circle(x, y, r, color);
	}

	return;
}
*/
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
	if(cx > w - 100)
	{
		cx = w;
	}

	if(cy < 0)
	{
		cy = 0;
	}
	if(cy > h - 170)
	{
		cy = h;
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
	int old_cx, old_cy;

	read_mouse(fd_mouse);
	old_cx = cx;
	old_cy = cy;

	k = 0;
	for(j = 0; j < 17; j++)
	{
		for(i = 0; i < 10; i++)
		{
			buf[k++] = *(fbmem + cy * w + cx + i);
		}
		cy++;
	}

	fb_mouse(cx, cy);

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

int main(int argc, char* argv[])
{
	int fd, fd_mouse;
	struct fb_var_screeninfo fb_var;
	int x, y, num, space;
	int bits;

	x = 650;
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
	fbmem = mmap(0, w*h*sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

	//background
	fb_bg(600,50);

	//black
//	fb_black(700, 300);
	
	//white
	fb_white(700, 100);

	//black
	fb_black(800, 200);
/*

	//mouse
	fd_mouse = open_mouse();
	printf("fd_mouse = %d\n", fd_mouse); 
	cx = w / 2;
	cy = h / 2;
	printf("cx = %d, cy = %d\n", cx, cy);
	fb_mouse(cx, cy);
	while(1)
	{
//		read_mouse(fd_mouse);
		move_mouse(fd_mouse);
		x = cx + 10;
		y = cy - 300;
		printf("cx = %d, cy = %d\n", cx, cy);
		printf("x = %d, y = %d\n", x, y); 
	}
*/

	close(fd);

	return 0; 
}
