/*
 * =====================================================================================
 *
 *       Filename:  common.h
 *
 *    Description:  公共内容
 *
 *        Version:  1.0
 *        Created:  2011年03月25日 09时16分19秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  sunsea1026@gmail.com
 *
 * =====================================================================================
 */

#ifndef __COMMON_H
#define __COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <linux/fb.h>
#include <unistd.h>
#include <jpeglib.h>

/* 公共宏定义 */
#define FB_DEV 			"/dev/fb0"
#define JPEG 			0x001
#define PNG			0x010
#define BMP			0x100
#define UNKNOWN			0x111
#define ERR_BIG			"Error:The picture is too big, can not display!"
#define IMAGES_NAME_SIZE	100
#define IMAGES_NAME_PATH_SIZE	150

/* JPEG效果的宏定义 */
#define EFFECT_JPEG_NORMAL	0x000
#define EFFECT_JPEG_U_D_COVER	0x001
#define EFFECT_JPEG_L_R_COVER	0x002
#define EFFECT_JPEG_U_D_SHUTTER	0x003
#define EFFECT_JPEG_L_R_SHUTTER	0x004
#define EFFECT_JPEG_CIRCLE	0x005
#define EFFECT_JPEG_WINDMILL	0x006
#define EFFECT_JPEG_SCROLL	0x007
#define EFFECT_JPEG_SECTOR	0x008
#define EFFECT_JPEG_ONE_SIDE	0x009


/* 鼠标的操作 */
#define C_WIDTH 10		//mouse width
#define C_HEIGHT 17		//mouse height
#define T___ 0xff0000
#define X___ 0xffffff
#define BORD 0x0


typedef struct images_list
{
	int images_id;
	char images_name[IMAGES_NAME_SIZE];

	struct images_list *next;
}IMAGES_LIST;

typedef struct color
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

}__attribute__((packed)) COLOR;

typedef struct pixel_t
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;
}__attribute__((packed)) PIXEL_T;

//mouse.c
int		cx, cy;
char 		buf_mouse[8];
int 		old_cx, old_cy;
int 		buf[C_WIDTH * C_HEIGHT];

int 		click_switch;					//0：已经单击，1：没有单击


//公共内容
int 		fb_dev;
struct 		fb_var_screeninfo fb_var;
int 		screen_w, screen_h, screen_bits;
void		*fbmem, *data;
FILE 		*infile;
IMAGES_LIST	*images_head;
int 		picture_w_prior, picture_h_prior;		//记录上衣个图片的宽、高

int 		mouse_control_switch;				//鼠标开关，0：使用鼠标控制，1：不使用鼠标控制，即，自动播放

//JPEG图片格式的所需要的变量
int	picture_w, picture_h, picture_bits;
struct	jpeg_decompress_struct cinfo;
struct 	jpeg_error_mgr jerr;
unsigned char *buffer, *tmpbuf;
COLOR 	picture_color;
PIXEL_T 	**fbp;

#endif
/* end of file*/
