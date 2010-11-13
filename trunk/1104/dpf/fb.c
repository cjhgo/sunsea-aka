#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include "image.h"

void fb_pixel(unsigned short *fbmem,int w,
		int x,int y,int color)
{
	unsigned short *pos;
	pos  = fbmem + y*w + x;
	*pos = color;
}

void fb_hline(unsigned short *fbmem,int w,
		int x1,int y,int x2,int color)
{
	int i;
	for (i = x1; i < x2; i++)
		fb_pixel(fbmem,w,i,y,color);
}

int main (void)
{
	int fd;
	unsigned short * fbmem;
	int w,h,bpp;
	struct fb_var_screeninfo fb_var;
	unsigned char *buf;

	//1.) open fb
	fd = open ("/dev/fb0",O_RDWR);
	if (fd <0)
	{
		printf ("open /dev/fb0 error!\n");
		return -1;
	}
	//2. get framebuffer information
	ioctl(fd,FBIOGET_VSCREENINFO, &fb_var);
	
	w   = fb_var.xres;
	h   = fb_var.yres;
	bpp = fb_var.bits_per_pixel;

	//3. mmap framebuffer;
	fbmem = mmap (0,w * h * bpp/8,PROT_READ|PROT_WRITE,
			MAP_SHARED,fd,0);
	
	if(fbmem <0)
	{
		printf ("mmap fb error!\n");
		return 0;
	}

	//4. draw pixel
	fb_pixel (fbmem,w,100,200,0xF800);
	fb_hline (fbmem,w,150,260,300,0x07E0);

	//5. display image
	{
		int i,j;
		unsigned short pixel;
		for (j= 0 ;j<IMAGEW;j++)
		{
			for (i=0; i <IMAGEH;i++)
			{
				pixel = image[j*IMAGEW*2+i*2] | (image[j*IMAGEW*2+ i*2 +1]<<8);	
				fb_pixel(fbmem,w,i,j,pixel);
			}
		}
	}
	
	close (fd);
	return 0;
}
