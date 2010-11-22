/************************************************************
*  名称：五子棋小游戏
*
*  版本：v1.0
*
*  作者：张双喜
*
*  日期：2010年11月14日
*
*  模块功能：主函数，包含：画黑白棋子，画网格，画背景，画五个小黑点，画鼠标
* 
 ***********************************************************/

#include "common.h"

//main
int main(int argc, char* argv[])
{
	int fd, fd_mouse;
	struct fb_var_screeninfo fb_var;
	int bits;
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
