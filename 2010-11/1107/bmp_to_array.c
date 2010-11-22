#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/fb.h>

typedef struct tagBITMAPFILEHEADER
{
	short bfType;
	int bfSize;
	short bfReserved1;
	short bfReserved2;
	int bfOffBits;
}BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER
{
	int biSize;
	long biWidth;
	long biHeight;
	short biPlanes;
	short biBitCount;
	int biCompression;
	int biSizeImage;
	long biXPelsPerMeter;
	long biYPelsPerMeter;
	int biClrUsed;
	int biClrImortant;
}BITMAPINFOHEADER;


int main(int argc, char* argv[])
{
	FILE *fp_bmp, *fp_h;
	int ret_fread;
	int ret_fwrite;
//	char *h_head = "char bmp_data[] = {\n\t";
	char *h_head = "int bmp_data[] = {\n\t";
	char buf[1025];
	int fd_bmp;
	long bmp_width;
	long bmp_height;
	short bmp_bits;
	unsigned short red, green, blue;
	int size;
	char tmp[4];
	int head_to_data;
	int bmp_line_byte_cnt;
	int bmp_data_size;
	int bmp_data[222912];
	int i, x, y, ret;
	int byte;
	int bmp_bfOffBits;
	
	BITMAPFILEHEADER header;
	BITMAPINFOHEADER info_header;	//bmp头信息结构体
	struct fb_cmap cmap;		//描述设备无关的颜色映射信息

	//打开位图文件
	fp_bmp = fopen("bmp.bmp", "rb");
	if(fp_bmp == NULL)
	{
		printf("open bmp.bmp error!\n"); 
		return -1;
	}

	//打开存放图片二进制的.h文件
	fp_h = fopen("bmp.h", "wb");
	if(NULL == fp_h)
	{
		printf("open bmp.h error!\n"); 
		return -1;
	}
	fwrite(h_head, strlen(h_head), 1, fp_h);	//写入开头内容：char bmp_data[] = {
//	fseek(fp_h, strlen(h_head), 2);


	//加载文件信息头
	memset(&header, 0, sizeof(header));
	fread(&header, sizeof(header), 1, fp_bmp);
	if(header.bfType != 0x4d42)
	{
		printf("load bmp error!\n");
		return -1;
	}
	bmp_bfOffBits = header.bfOffBits;
	printf("bmp_bfOffBits = %d\n", bmp_bfOffBits); 

	//加载位图信息头			//需要跳过文件信息头14个字节，但是不能用sizeof(header), 因为它占16字节
	fseek(fp_bmp, 14, 0);
	fread(&info_header, sizeof(info_header), 1, fp_bmp);
	bmp_width = info_header.biWidth;
	bmp_height = info_header.biHeight;
	bmp_bits = info_header.biBitCount;
	printf("bmp_width = %ld\n", bmp_width);
	printf("bmp_height = %ld\n", bmp_height);  
	printf("bmp_bits = %d\n", bmp_bits); 

	//处理行对齐
	bmp_line_byte_cnt = (((bmp_width * bmp_bits) + 31) >> 5) << 2;
	bmp_data_size = bmp_line_byte_cnt * bmp_height;
	printf("bmp_data_size = %d\n", bmp_data_size); 

	//处理图片数据 
	fseek(fp_bmp, 54, 0);

	for(y = 0; y < bmp_height; y++)
	{
		for(x = 0; x < bmp_width; x++)
		{
			if(!(y == 0 && x == 0))
			{
				fprintf(fp_h, ", ");
			}

			if(i % 16 == 0)
			{
				fprintf(fp_h, "\n\t");
			}
			i++;

			ret = fread(&byte, 1, 1, fp_bmp);
			if(ret == 0)
			{
				break;
			}
			fprintf(fp_h, "0x%x", byte);

		}
	}
	fprintf(fp_h, " };");



	//加载图片数据


/*
	//给fb_cmap结构体中的red,green,blue分配空间
	cmap.red = calloc(256, sizeof(short));
	if(cmap.red == NULL)
	{
		printf("cmap.red calloc error!\n");
		return -1;
	}

	cmap.green = calloc(256, sizeof(short));
	if(cmap.green == NULL)
	{
		printf("cmap.green calloc error!\n");
		return -1;
	}

	cmap.blue = calloc(256, sizeof(short));
	if(cmap.blue == NULL)
	{
		printf("cmap.blue calloc error!\n"); 
		return -1;
	}

//	ioctl(fd_bmp, FBIOPUTCMAP, &cmap);

	for(size = 0; size < 256; size++)
	{
	//	printf("----------------------------------------\n"); 
		read(fd_bmp, &tmp, 4);
		cmap.blue[size] = tmp[0] << 8;
//		fwrite(cmap.blue[size], strlen(*cmap.blue[size]), 1, fp_h);
	//	printf("blue = 0x%x\n", *cmap.blue); 

		cmap.green[size] = tmp[1] << 8;
	//	printf("green = 0x%x\n", *cmap.green); 

		cmap.red[size] = tmp[2] << 8;
	//	printf("red = 0x%x\n", *cmap.red); 
	}





*/


	fclose(fp_bmp);
	
	fclose(fp_h);


	return 0; 
}
