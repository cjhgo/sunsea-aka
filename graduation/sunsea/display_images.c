/*
 * =====================================================================================
 *
 *       Filename:  display_images.c
 *
 *    Description:  显示图片合集
 *
 *        Version:  1.0
 *        Created:  2011年03月25日 17时03分49秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  sunsea1026@gmail.com
 *
 * =====================================================================================
 */

#include "common.h"
#include <time.h>

//BMP的内容
typedef struct bmp_file_header
{
	char cfType[2];				//文件类型，必须为“BM”（0x4D42）
	char cfSize[4];				//文件的大小（字节）
	char cfReserved[4];			//保留，必须为0
	char cfoffBits[4];			//位图阵列相对与文件头的偏移量（字节）
}__attribute__((packed)) BITMAPFILEHEADER;	//文件头结构

typedef struct bmp_info_header
{
	char ciSize[4];				//sizeof of BITMAPINFOHEADER
	char ciWidth[4];			//位图宽度（像素）
	char ciHeight[4];			//位图高度（像素）
	char ciPlanes[2];			//目标设备的位平面数，必须置为1
	char ciBitCount[2];			//每个像素的位数，1，4，8或24
	char ciCompress[4];			//位图阵列的压缩方法，0=不压缩
	char ciSizeImage[4];			//图像大小（字节）
	char ciXPelsPerMeter[4];		//目标设备水平每米像素个数
	char ciYPelsPerMeter[4];		//目标设备垂直每米像素个数
	char ciClrUsed[4];			//位图实际使用的颜色表的颜色数
	char ciClrImportant[4];			//重要颜色索引的个数
}__attribute__((packed)) BITMAPINFOHEADER;	//位图信息头结构

//显示jpg/jpeg格式图片
void display_jpeg()
{
	int i, j, x, y;
	int effect_ret;

	fbp = (PIXEL_T **)malloc(sizeof(PIXEL_T *) * screen_w);
	//x, y 代表图片的起始坐标
	for(i = 0, x = 0 * screen_bits / 8, y = 0; i < screen_w; i++)
	{
		fbp[i] = (PIXEL_T *)(fbmem + (y + i) * screen_w * screen_bits / 8 + x);
	}
	cinfo.err = jpeg_std_error(&jerr);
	jpeg_create_decompress(&cinfo);

	//指定要解压缩的图像文件
	jpeg_stdio_src(&cinfo, infile);

	//获取图像信息
 	jpeg_read_header(&cinfo, TRUE);

	//开始解压
	jpeg_start_decompress(&cinfo);

	picture_w = cinfo.output_width;
	picture_h = cinfo.output_height;
	picture_bits = cinfo.output_components;
/* 
	printf("picture info:\n");
	printf("width  = %d\n", picture_w);
	printf("height = %d\n", picture_h); 
	printf("bits   = %d\n", picture_bits); 
*/
	if((picture_w > screen_w) || (picture_h > screen_h))
	{
		printf("%s\n", ERR_BIG); 
		exit(1);
	}

	//用一个随机数确定使用哪种特效显示一张图片
	srand((unsigned)time(NULL));
	effect_ret = (rand() % 10) % 7;
	effect_ret = EFFECT_JPEG_WINDMILL;
	switch(effect_ret)
	{
		/* 普通效果 */
		case EFFECT_JPEG_NORMAL:
			effect_jpeg_normal();
			break;
		/* 自上向下覆盖效果 */
		case EFFECT_JPEG_U_D_COVER:
			effect_jpeg_u_d_cover();
			break;
		/* 自左向右覆盖效果 */
		case EFFECT_JPEG_L_R_COVER:
			effect_jpeg_l_r_cover();
			break;
		/* 上下百页窗效果 */
		case EFFECT_JPEG_U_D_SHUTTER:
			effect_jpeg_u_d_shutter();
			break;
		/* 左右百页窗效果 */
		case EFFECT_JPEG_L_R_SHUTTER:
			effect_jpeg_l_r_shutter();
			break;
		/* 圆形效果 */	
		case EFFECT_JPEG_CIRCLE:
			effect_jpeg_circle();
			break;
		/* 风车效果 */
		case EFFECT_JPEG_WINDMILL:
			effect_jpeg_windmill();
			break;
		/* 卷轴效果 */
		case EFFECT_JPEG_SCROLL:
			effect_jpeg_scroll();
			break;
		/* 扇形展开效果 */
		case EFFECT_JPEG_SECTOR:
			effect_jpeg_sector();
			break;
		/* 一侧展开效果 */
		case EFFECT_JPEG_ONE_SIDE:
			effect_jpeg_one_side();
			break;
		default:
			break;
	}

	//完成解压
	jpeg_finish_decompress(&cinfo);

	//释放解压对象
	jpeg_destroy_decompress(&cinfo);

	free(fbp);

	return;
}

//chartolong
long chartolong(char *string, int length)
{
	long number;

	if(length <= 4)
	{
		memset(&number, 0, sizeof(long));
		memcpy(&number, string, length);
	}

	return number;
}

//显示bmp格式图片
void display_bmp()
{
	BITMAPFILEHEADER FileHead;
	BITMAPINFOHEADER InfoHead;
	int rc ,i ,j, x, y;
	int ciWidth, ciHeight, ciBitCount;
	long int BytesPerLine = 0;
	COLOR picture_color;
	PIXEL_T **fbp;
	unsigned char *buffer, *tmpbuf;
 
	//读位图文件头
	rc = fread(&FileHead, sizeof(BITMAPFILEHEADER), 1, infile);
	if(rc != 1)
	{
		printf("%s\n", ERR_BIG); 
		fclose(infile);
		exit(1);
	}
  
	//判断位图的类型
	if(memcmp(FileHead.cfType, "BM", 2) != 0)
	{
		printf("This is not a bmp picture!\n"); 
		fclose(infile);
		exit(1);
	}
  
 	//读取位图信息头
	rc = fread((char *)&InfoHead, sizeof(BITMAPINFOHEADER), 1, infile);
	if(rc != 1)
	{
		printf("Error:read bmp infoheader error!\n"); 
		fclose(infile);
		exit(1);
	}

	ciWidth		= (int)chartolong(InfoHead.ciWidth,	4);
	ciHeight 	= (int)chartolong(InfoHead.ciHeight, 	4);
	ciBitCount	= (int)chartolong(InfoHead.ciBitCount, 	4);

	fseek(infile, (int)chartolong(FileHead.cfoffBits, 4), SEEK_SET);
	BytesPerLine = (ciWidth * ciBitCount + 31) / 32 * 4;

/* 	printf("bmp info\n"); 
	printf("width = %d\n", ciWidth); 
	printf("height = %d\n", ciHeight); 
	printf("bit = %d\n", ciBitCount); 
*/
	if((ciWidth > screen_w) || (ciHeight > screen_h))
	{
		printf("%s\n", ERR_BIG); 
		exit(1);
	}
	fbp = (PIXEL_T **)malloc(sizeof(PIXEL_T *) * screen_w);
	for(i = 0, x = 0 * screen_bits / 8, y = 0; i < screen_w; i++)
	{
		fbp[i] = (PIXEL_T *)(fbmem + (y + i) * screen_w * screen_bits / 8 + x);
	}

 	buffer = (unsigned char *)malloc(BytesPerLine);
	memset(buffer, 0, BytesPerLine);

	for(i = ciHeight - 1; i >= 0; i--)
	{
		tmpbuf = buffer;
		rc = fread(tmpbuf, BytesPerLine, 1, infile);
		
		for(j = 0; j < ciWidth; j++)
		{
			memcpy(&picture_color, tmpbuf, ciBitCount / 8);
		
			fbp[i][j].r = picture_color.r;
			fbp[i][j].g = picture_color.g;
			fbp[i][j].b = picture_color.b;

			tmpbuf += ciBitCount / 8;
		}
	}

	free(buffer);
	free(fbp);

	return;
}
/* end of file*/
