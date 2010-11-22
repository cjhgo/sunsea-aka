#include <stdio.h> 
#include <stdlib.h>
#include <fcntl.h>
//#include <sys/ioctl.h>
#include <sys/mman.h>
#include <linux/fb.h>
#include <sys/types.h>
#include <sys/stat.h>

int *fbmem;
int w, h;

//draw a point at(x, y)
void fb_point(int x, int y, int color)
{
	*(fbmem + (y*w+x)) = color;

	return;
}

//draw -line at(x, y)
void fb_hline(int x, int y, int color)
{
	int i = 0;

	for(i = 0; i < w; i++)
	{
		*(fbmem + (y*w+i)) = color;
	}

	return;	
}

//draw |line at(x, y)
void fb_sline(int x, int y, int color)
{
	int i = 0;

	for(i = 0; i < h; i++)
	{
		*(fbmem + x+i*w) = color;
	}

	return;
}

//draw circle at(x, y)
void circle(int x, int y, int r, int color)
{
	
}

/*
//24 bit to 16 bit
short rgb24to16(int color)
{
	short rgb16;
	int r24, g24, b24;
	int r16, g16, b16;

	b24 = color & 0xff;
	g24 = (color >> 8) & 0xff;
	r24 = (color >> 16) & 0xff;

	b16 = b24 * 0x1f/0xff;
	g16 = g24 * 0x3f/0xff;
	r16 = r24 * 0x1f/0xff;

	rgb16 = b16 | (g16 << 5) | (r16 << 11);

	return rgb16;
}
*/

int main(int argc, char* argv[])
{
	int x, y;
	int fd;
	struct fb_var_screeninfo fb_var;

	fd = open("/dev/fb0", O_RDWR);
	printf("fd = %d\n", fd);
	if(fd < 0)
	{
		printf("open framebuffer error!\n"); 
		exit(0);
	}

	ioctl(fd, FBIOGET_VSCREENINFO, &fb_var);
	w = fb_var.xres;
	h = fb_var.yres;
	printf("Framebuffer:%d * %d\n", w, h); 
	fbmem = mmap(0, w*h*sizeof(int), PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);

//	fb_point(x, y, 0xff00ff);

	fb_hline(500, 100, 0xffffff);

	fb_sline(500, 100, 0xffff00);

	return 0; 
}
