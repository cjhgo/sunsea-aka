/*
   读取framebuffer信息
 */
#include "common.h"

#include <stdio.h> 
#include <sys/stat.h>
#include <fcntl.h>

#include <linux/fb.h> //FBIOGET_VSCREENINFO
#include <sys/mman.h>
#include <sys/ioctl.h>

#define filename "/dev/fb0"

int w,h,bpp;//宽，高，色深
struct fb_var_screeninfo fb_var; //framebuffer屏幕信息的结构体
int  *fbmem;//指向到framebuffer 映射到内存后的内存区域
//short int *fbmem;//指向到framebuffer 映射到内存后的内存区域

int init_fb (void)
{
		int fd;
		fd = open(filename,O_RDWR);//读写方式

		if( fd < 0) //出错判断
		{
				printf("Open %s error!\n",filename);
				return -1;
		}
		ioctl(fd,FBIOGET_VSCREENINFO,&fb_var);//文件描述符,设备信息,设备结构体
		w = fb_var.xres;//宽
		h = fb_var.yres;//高
		bpp = fb_var.bits_per_pixel;//色深
		printf("Framebuffer:%dx%d-%dbpp\n",w,h,bpp);//分辨率,色深(位)
		fbmem = mmap(0,w*h*bpp/8, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);//将framebuffer映射到内存，通过读写这块内存区域控制framebuffer
		return 0;
}

// 16位 色深 颜色格式
//5 6 5
// 00000 000000 00000
//         32   16  8  4  2 1
// 红(5位) 绿(6位)  蓝(5位)

// 32位 色深  颜色格式
// 8 8 8 8
// 00000000 00000000 00000000 00000000
// 灰度(8位) 红(8位) 绿(8位) 蓝(8位)

// 00000000 00011111

//<<11  11111000 00000000

// 00000000 00111111

//<<05 00000111 11100000


// 11111000 00000000
// 00000000 00011111
// 00000111 11100000
// 11111111111111111

#if 0
int main(int argc ,char *argv[]) 
{
		int i,k;
		init_fb();
		/*for(i =0;i < w*h ;i++)
		{
			fbmem[i] = 31 << 11 | 63 << 5 | 31;
		}*/

		for(i = 0 ; i < 100; i++)
		{
			for(k = 0; k < 100; k++)
			{
				fbmem[i * 1024 + k ] = 63 << 5;
			}
		}


		
		return 0; 
}
#endif
