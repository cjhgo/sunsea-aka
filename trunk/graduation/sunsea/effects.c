/*
 * =====================================================================================
 *
 *       Filename:  effects.c
 *
 *    Description:  数码相框的特效
 *
 *        Version:  1.0
 *        Created:  2011年03月25日 09时15分17秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  sunsea1026@gmail.com 
 *
 *      interface: picture_h, picture_w, picture_bits, buffer, tmpbuf, fbp
 *
 * =====================================================================================
 */

#include "common.h"
#include <math.h>

#define U_D_BLOCK_NUM		6
#define L_R_BLOCK_NUM		10
#define SPEED			20000		/* 百页窗效果 单位：微秒 */
#define PI			3.14
#define WINDMILL_PART_NUM	6		/* 风车效果被分为几部分 */
#define ELLIPSE_A		24
#define ELLIPSE_B		18

//JPEG格式的图片普通效果
void effect_jpeg_normal()
{
	int i, j;

	system("clear");
	//获取颜色值
	buffer = (unsigned char *)malloc(picture_w * picture_bits);
	memset(buffer, 0, picture_w * picture_bits);
	for(i = 0; i < picture_h; i++)
	{
		tmpbuf = buffer;
		jpeg_read_scanlines(&cinfo, &tmpbuf, 1);

		for(j = 0; j < picture_w; j++)
		{
			memcpy(&picture_color, tmpbuf, sizeof(picture_color));

 			fbp[i][j].b = picture_color.r;
			fbp[i][j].g = picture_color.g;
			fbp[i][j].r = picture_color.b;

			tmpbuf += picture_bits;
		}
	}

	sleep(1);

	free(buffer);

	return;
}
//JPEG格式的图片自上向下覆盖效果
void effect_jpeg_u_d_cover()
{
	int i, j;

	//获取颜色值
	buffer = (unsigned char *)malloc(picture_w * picture_bits);
	memset(buffer, 0, picture_w * picture_bits);
	for(i = 0; i < picture_h; i++)
	{
		tmpbuf = buffer;
		jpeg_read_scanlines(&cinfo, &tmpbuf, 1);

		for(j = 0; j < picture_w; j++)
		{
			memcpy(&picture_color, tmpbuf, sizeof(picture_color));

 			fbp[i][j].b = picture_color.r;
			fbp[i][j].g = picture_color.g;
			fbp[i][j].r = picture_color.b;

			tmpbuf += picture_bits;
		}
		usleep(10000);
	}

	free(buffer);

	return;
}

/* JPEF格式图片的自左向右覆盖效果 */
void effect_jpeg_l_r_cover()
{
	unsigned char *buf_line, *tmp_buf_line;
	int i, j;

	buf_line = (unsigned char *)malloc(picture_w * picture_bits);
	buffer = (unsigned char *)malloc(picture_w * picture_h * picture_bits);
	memset(buffer, 0, picture_w * picture_h * picture_bits);

	/* 把图片每个像素的rgb值存入buffer中 */
	tmpbuf = buffer;
	for(i = 0; i < picture_h; i++)
	{
		tmp_buf_line = buf_line;
		memset(tmp_buf_line, 0, picture_w * picture_bits);
		jpeg_read_scanlines(&cinfo, &tmp_buf_line, 1);
		memcpy(tmpbuf + i * picture_w * picture_bits, tmp_buf_line, picture_w * picture_bits);
	}
	
	for(j = 0; j < picture_w; j++)
	{
		tmpbuf = buffer;
		for(i = 0; i < picture_h; i++)
		{
			memcpy(&picture_color, tmpbuf + (i * picture_w + j) * picture_bits, sizeof(picture_color));
			fbp[i][j].b = picture_color.r;
			fbp[i][j].g = picture_color.g;
			fbp[i][j].r = picture_color.b;
		}
		usleep(1000);
	}

	free(buf_line);
	free(buffer);

	return;
}

//JPEG格式的图片上下百页窗特效
void effect_jpeg_u_d_shutter()
{
	int i, j, k;
	int block;

	unsigned char *buf_line, *tmp_buf_line;

	buf_line = (unsigned char *)malloc(picture_w * picture_bits);

	buffer = (unsigned char *)malloc(picture_w * picture_h * picture_bits);
	memset(buffer, 0, picture_w * picture_h * picture_bits);
	tmpbuf = buffer;
	for(i = 0; i < picture_h; i++)
	{
		tmp_buf_line = buf_line;
		memset(tmp_buf_line, 0, picture_w * picture_bits);
		jpeg_read_scanlines(&cinfo, &tmp_buf_line, 1);
		memcpy(tmpbuf + i * picture_w * picture_bits, tmp_buf_line, picture_w * picture_bits);
	}

	system("clear");
	for(i = 0; i < picture_h / U_D_BLOCK_NUM; i++)
	{
		for(k = 0; k < picture_h - U_D_BLOCK_NUM; k = k + picture_h / U_D_BLOCK_NUM)
		{
			tmp_buf_line = buffer;
			for(j = 0; j < picture_w; j++)
			{
				memcpy(&picture_color, tmp_buf_line + (i + k) * picture_w * picture_bits, sizeof(picture_color));
			
				fbp[i + k][j].b = picture_color.r;
				fbp[i + k][j].g = picture_color.g;
				fbp[i + k][j].r = picture_color.b;

				tmp_buf_line += picture_bits;			
			}
		}
		usleep(SPEED);
	}

	free(buf_line);
	free(buffer);

	return;
}

/* JPEF格式图片的左右百页窗效果 */
void effect_jpeg_l_r_shutter()
{
	unsigned char *buf_line, *tmp_buf_line;
	int i, j, k;

	buf_line = (unsigned char *)malloc(picture_w * picture_bits);
	buffer = (unsigned char *)malloc(picture_w * picture_h * picture_bits);
	memset(buffer, 0, picture_w * picture_h * picture_bits);

	/* 把图片每个像素的rgb值存入buffer中 */
	tmpbuf = buffer;
	for(i = 0; i < picture_h; i++)
	{
		tmp_buf_line = buf_line;
		memset(tmp_buf_line, 0, picture_w * picture_bits);
		jpeg_read_scanlines(&cinfo, &tmp_buf_line, 1);
		memcpy(tmpbuf + i * picture_w * picture_bits, tmp_buf_line, picture_w * picture_bits);
	}
	
	system("clear");
	for(j = 0; j < picture_w / L_R_BLOCK_NUM; j++)
	{
		/* 说明：减去L_R_BLOCK是因为有时宽度除以块数除不尽，会使得每一块变小，如果不减块数，则会多画出一块来 */
		for(k = 0; k < picture_w - L_R_BLOCK_NUM; k = k + picture_w / L_R_BLOCK_NUM)
		{
			tmpbuf = buffer;
			for(i = 0; i < picture_h; i++)
			{
				memcpy(&picture_color, tmpbuf + (i * picture_w + j + k)* picture_bits, sizeof(picture_color));

				fbp[i][j + k].b = picture_color.r;
				fbp[i][j + k].g = picture_color.g;
				fbp[i][j + k].r = picture_color.b;
			}
		}
		usleep(SPEED);
	}

	free(buf_line);
	free(buffer);

	return;
}

//JPEG格式的图片圆形效果
void effect_jpeg_circle()
{
	int i, x, y, fbp_x, fbp_y, buf_x, buf_y, pos_x, pos_y;
	long int r, r_max;
	double degree;
	unsigned char *buf_line, *tmp_buf_line;

	system("clear");

	buf_line = (unsigned char *)malloc(picture_w * picture_bits);
	buffer = (unsigned char *)malloc(picture_w * picture_h * picture_bits);
	memset(buffer, 0, picture_w * picture_h * picture_bits);

	/* 把图片每个像素的rgb值存入buffer中 */
	tmpbuf = buffer;
	for(i = 0; i < picture_h; i++)
	{
		tmp_buf_line = buf_line;
		memset(tmp_buf_line, 0, picture_w * picture_bits);
		jpeg_read_scanlines(&cinfo, &tmp_buf_line, 1);
		memcpy(tmpbuf + i * picture_w * picture_bits, tmp_buf_line, picture_w * picture_bits);
	}
	
	/* 从中心想边沿画图像 */
	r_max = sqrt(picture_h * picture_h + picture_w * picture_w) / 2;
	x = 0;
	y = 0;
	for(r = 0; r <= r_max; r += 1)
	{
		for(degree = 0 ; degree <= 2 * PI; degree += PI / 180 / 25)
		{
			tmpbuf = buffer;
			x = (int)(r * cos(degree));
			y = (int)(r * sin(degree));
	 
			buf_x = picture_w / 2 + x;
			buf_y = picture_h / 2 - y;

			/* pos_x, pos_y 代表开始画点的其实坐标*/
			pos_x = 0;
			pos_y = 0;
			fbp_x = picture_w / 2 + x + pos_x;
			fbp_y = picture_h / 2 - y + pos_y;
			if ((buf_x < picture_w) && (buf_x >= 0)	&& (buf_y < picture_h) && (buf_y >= 0))
			{
				memcpy(&picture_color, tmpbuf + (buf_y * picture_w + buf_x) * picture_bits, sizeof(picture_color));
				fbp[fbp_y][fbp_x].b = picture_color.r;
				fbp[fbp_y][fbp_x].g = picture_color.g;
				fbp[fbp_y][fbp_x].r = picture_color.b;
			}
		}
	}

	free(buf_line);
	free(buffer);
	
	return;
}

/* 风车效果，函数graw_part()是画一部分的内容，比如画四分之一的一块 */
void draw_part(long r_max, double degree)
{
	int x, y, buf_x, buf_y, pos_x, pos_y, fbp_x, fbp_y;
	long r;
	for(r = 0; r <= r_max; r += 1)
	{
		tmpbuf = buffer;
		x = (int)(r * cos(degree));
		y = (int)(r * sin(degree));
 
		buf_x = picture_w / 2 + x;
		buf_y = picture_h / 2 - y;

		/* pos_x, pos_y 代表开始画点的其实坐标*/
		pos_x = 0;
		pos_y = 0;
		fbp_x = picture_w / 2 + x + pos_x;
		fbp_y = picture_h / 2 - y + pos_y;
		if ((buf_x < picture_w) && (buf_x >= 0)	&& (buf_y < picture_h) && (buf_y >= 0))
		{
			memcpy(&picture_color, tmpbuf + (buf_y * picture_w + buf_x) * picture_bits, sizeof(picture_color));
			fbp[fbp_y][fbp_x].b = picture_color.r;
			fbp[fbp_y][fbp_x].g = picture_color.g;
			fbp[fbp_y][fbp_x].r = picture_color.b;
		}
	}

	return;
}

/* JPEG格式图片的风车效果 */
void effect_jpeg_windmill()
{
	int i, x, y;
	long r_max;
	double degree, degree_part;
	unsigned char *buf_line, *tmp_buf_line;

	system("clear");

	buf_line = (unsigned char *)malloc(picture_w * picture_bits);
	buffer = (unsigned char *)malloc(picture_w * picture_h * picture_bits);
	memset(buffer, 0, picture_w * picture_h * picture_bits);

	/* 把图片每个像素的rgb值存入buffer中 */
	tmpbuf = buffer;
	for(i = 0; i < picture_h; i++)
	{
		tmp_buf_line = buf_line;
		memset(tmp_buf_line, 0, picture_w * picture_bits);
		jpeg_read_scanlines(&cinfo, &tmp_buf_line, 1);
		memcpy(tmpbuf + i * picture_w * picture_bits, tmp_buf_line, picture_w * picture_bits);
	}
	
	/* 从中心想边沿画图像 */
	r_max = sqrt(picture_h * picture_h + picture_w * picture_w) / 2;
	for(degree = 0 ; degree <= PI / 2; degree += PI / 180 / 25)
	{
		for(degree_part = 0; degree_part < 2 * PI; degree_part += 2 * PI / WINDMILL_PART_NUM)
		{
			draw_part(r_max, degree + degree_part);
		}
	
		usleep(1000);
	}
	
	free(buf_line);
	free(buffer);

	return;
}


/* JPEG格式图片的扇形展开效果 */
void effect_jpeg_sector()
{
	int i, x, y;
	long r_max;
	double degree, degree_part, degree_part_tmp;
	unsigned char *buf_line, *tmp_buf_line;

	system("clear");

	buf_line = (unsigned char *)malloc(picture_w * picture_bits);
	buffer = (unsigned char *)malloc(picture_w * picture_h * picture_bits);
	memset(buffer, 0, picture_w * picture_h * picture_bits);

	/* 把图片每个像素的rgb值存入buffer中 */
	tmpbuf = buffer;
	for(i = 0; i < picture_h; i++)
	{
		tmp_buf_line = buf_line;
		memset(tmp_buf_line, 0, picture_w * picture_bits);
		jpeg_read_scanlines(&cinfo, &tmp_buf_line, 1);
		memcpy(tmpbuf + i * picture_w * picture_bits, tmp_buf_line, picture_w * picture_bits);
	}
	
	/* 从中心想边沿画图像 */
	r_max = sqrt(picture_h * picture_h + picture_w * picture_w) / 2;
	for(degree = 0 ; degree <= PI * 2; degree += PI / 180 / 25)
	{
		degree_part_tmp = PI / 2;
		for(degree_part = PI / 2; degree_part < PI * 3 / 2; degree_part += PI / 180 / 25)
		{
			draw_part(r_max, degree + degree_part);
			
			degree_part_tmp -= PI / 180 / 25;
			draw_part(r_max, degree + degree_part_tmp);
			
			usleep(100);
		}
		break;
	}
	
	free(buf_line);
	free(buffer);

	return;
}

/* JPEG格式图片的一侧展开效果 */
void effect_jpeg_one_side()
{
	int i, x, y;
	long r_max;
	double degree, degree_part;
	unsigned char *buf_line, *tmp_buf_line;

	system("clear");

	buf_line = (unsigned char *)malloc(picture_w * picture_bits);
	buffer = (unsigned char *)malloc(picture_w * picture_h * picture_bits);
	memset(buffer, 0, picture_w * picture_h * picture_bits);

	/* 把图片每个像素的rgb值存入buffer中 */
	tmpbuf = buffer;
	for(i = 0; i < picture_h; i++)
	{
		tmp_buf_line = buf_line;
		memset(tmp_buf_line, 0, picture_w * picture_bits);
		jpeg_read_scanlines(&cinfo, &tmp_buf_line, 1);
		memcpy(tmpbuf + i * picture_w * picture_bits, tmp_buf_line, picture_w * picture_bits);
	}
	
	/* 从中心向边沿画图像 */
	r_max = sqrt(picture_h * picture_h + picture_w * picture_w) / 2;
	for(degree = 0 ; degree <= PI * 2; degree += PI / 180 / 25)
	{
		for(degree_part = 0; degree_part <= PI * 2; degree_part += PI / 180 / 25)
		{
			draw_part(r_max, degree + degree_part);
			
			usleep(100);
		}
		break;
	}
	
	free(buf_line);
	free(buffer);

	return;
}





































/* JPEG格式图片的卷轴效果 */
void effect_jpeg_scroll()
{
	unsigned char *buf_line, *tmp_buf_line;
	int i, j, k;
	double degree;
	int x, y;
	int ellipse_l, ellipse_flag, m, n, buf_i, buf_j;

	system("clear");

	buf_line = (unsigned char *)malloc(picture_w * picture_bits);
	buffer = (unsigned char *)malloc(picture_w * picture_h * picture_bits);
	memset(buffer, 0, picture_w * picture_h * picture_bits);

	/* 把图片每个像素的rgb值存入buffer中 */
	tmpbuf = buffer;
	for(i = 0; i < picture_h; i++)
	{
		tmp_buf_line = buf_line;
		memset(tmp_buf_line, 0, picture_w * picture_bits);
		jpeg_read_scanlines(&cinfo, &tmp_buf_line, 1);
		memcpy(tmpbuf + i * picture_w * picture_bits, tmp_buf_line, picture_w * picture_bits);
	}
	j = 0;
	/* 计算椭圆的周长 */
	ellipse_l = 2 * PI * ELLIPSE_B + 4 * (ELLIPSE_A - ELLIPSE_B);

	for(j = 0; j < picture_w; j++)
	{
		tmpbuf = buffer;
		for(i = 0; i < picture_h; i++)
		{
			for(k = 1; k < ELLIPSE_A * 2; k++)
      			{
				ellipse_flag = 0;
				buf_i = i - ELLIPSE_B;
			
				if((j + k < picture_w) && (buf_i >= 0))
				{
					ellipse_flag = 1;
					memset(&picture_color, 0, sizeof(picture_color));
				//	memcpy(&picture_color, tmpbuf + (i * picture_w + j + k + ellipse_l / 2) * picture_bits, sizeof(picture_color));
					memcpy(&picture_color, tmpbuf + (i * picture_w + j + k - ELLIPSE_A) * picture_bits, sizeof(picture_color));
					fbp[buf_i][j + k - ELLIPSE_A].b = picture_color.r;
					fbp[buf_i][j + k - ELLIPSE_A].g = picture_color.g;
					fbp[buf_i][j + k - ELLIPSE_A].r = picture_color.b;
				}
			}
			memcpy(&picture_color, tmpbuf + (i * picture_w + j) * picture_bits, sizeof(picture_color));
			fbp[i][j].b = picture_color.r;
			fbp[i][j].g = picture_color.g;
			fbp[i][j].r = picture_color.b;
		}

		/* 画椭圆 */
//		for(m = 0, n = 0; m < ELLIPSE_A; m++, n++)
//		{
//			for(degree = 0; degree < PI * 2 ; degree += PI / 60)
//			{
//				if(n > ELLIPSE_B)
//				{
//					n = ELLIPSE_B;
//				}
//				x = m * cos(degree) + 1 + ELLIPSE_A;
//				y = picture_h - ELLIPSE_B - n * sin(degree);
//				
//				if(1 == ellipse_flag)
//				{
//					fbp[y][j + x].b = 0xff;
//					fbp[y][j + x].g = 0xff;
//					fbp[y][j + x].r = 0xe0;
//				}
//			}
//		}
//		for(m = picture_h - ELLIPSE_B; m < picture_h; m++)
//		{
//			for(n = 1 + ELLIPSE_A; n < ELLIPSE_A * 2; n++)
//			{
//					fbp[m][j + n].b = 0xff;
//					fbp[m][j + n].g = 0xff;
//					fbp[m][j + n].r = 0xe0;
//			}
//		}

//		sleep(1);
		usleep(10000);
	}

	free(buf_line);
	free(buffer);

	return;
}
/* end of file*/
