#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
//#include <sys/ioctl.h>
#include <linux/fb.h>
//#include <sys/types.h>
//#include <sys/stat.h>
#include <math.h>

int *fbmem;
int w, h;

void fb_circle(int x, int y, int r, int color)
{
	double m, n, degree;
	int p, q;

//	for(; r >= 0; r = r -1)
//	{
//		color = 
		for(degree = 0; degree <= 2*3.14; degree = degree + 3.14/180)
		{
			m = r * cos(degree);
			n = r * sin(degree);

			p = x + (int)m;
			q = y + (int)n;

			*(fbmem + (w * q + p)) = color;
		}
//	}

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
		color = color + 0x080808;
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

	y_tmp = y;

	grid_len = (num - 1) * space;

	//draw h_line
	for(tmp = 0; tmp <= grid_len; tmp = tmp + space)
	{
		for(i= 0; i < grid_len; i++)
		{
			*(fbmem + (y * w + x + i)) = color;
		}
		y = y + space;
	}

	//draw s_line
	y = y_tmp;
	for(tmp = 0; tmp <= grid_len; tmp = tmp + space)
	{
		for(i = 0; i < grid_len; i++)
		{
			*(fbmem + (y * w + x + i * w)) = color;
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

	bg_len = (num - 1) * space + 60;

	for(i = 0; i < bg_len; i++)
	{
		for(j = 0; j < bg_len; j++)
		{
			*(fbmem + (y * w + x + j)) = color;
		}
		y = y + 1;
	}
}

int main(int argc, char* argv[])
{
	int fd;
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
/*
	fb_point(500, 100, 0xffffff);
	fb_hline(500, 100, 0xff0000);
	fb_sline(500, 100, 0x00ff00);
	fb_circle(500, 400, 20, 0x00ff00);
*/
	fb_bg(x - 30, y - 30, num, space, 0xeedc82);
	fb_grid(x, y, num, space, 0x000000);

	fb_small_black_point(7 * space + x, 7 * space + y);
	fb_small_black_point(3 * space + x, 3 * space + y);
	fb_small_black_point(11 * space + x, 3 * space + y);
	fb_small_black_point(3 * space + x, 11 * space + y);
	fb_small_black_point(11 * space + x, 11 * space + y);

	fb_white_point(8 * space + x, 8 * space + y);
	fb_black_point(7 * space + x, 7 * space + y);

	close(fd);
	return 0; 
}
