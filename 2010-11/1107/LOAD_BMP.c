#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

unsigned char *main()
{
	FILE *file;
 	unsigned char *buf,*p,num=0,tmp=0;
	unsigned int colornum;
	char aaa[]="0123456789abcdef";
	char bbb1[4]={'0','x'},bbb2[4]={'0','x'},bbb3[4]={'0','x'};
	char filename[]="test.bmp";
	char dataname[30]={"bmp_data"},platename[30]={"bmp_plate"};
	unsigned int width,height,i,j=0;
	int offset,k;


	if((file=fopen(filename,"rb"))==NULL)
		printf("open error!\n");
	fseek(file, 10, SEEK_SET); 
	if(fread(&offset,4,1,file)==0)
		printf("read offset error!\n");
	printf("offset: %d\n",offset);


	fseek(file,18,SEEK_SET);
	if(fread(&width,4,1,file)==0)
		printf("width error!\n");
	printf("width: %d\n",width);


	fseek(file,22,SEEK_SET);
	if(fread(&height,4,1,file)==0)
		printf("height error!\n");
	printf("height: %d\n",height);


	fseek(file,46,SEEK_SET);
	if(fread(&colornum,4,1,file)==0)
		printf("colornum error!\n");
	printf("colornum: %d\n",colornum);


	fseek(file,54,SEEK_SET);
	p=buf=(unsigned char *)malloc((colornum+1)*4);
	fread(buf,(colornum+1)*4,1,file);
	fclose(file);
	file=fopen("color plate.txt","wa+");
	fwrite("static stGFX_PaletteEntry_t ",28,1,file);
	fwrite(platename,strlen(platename),1,file);
	fwrite("[]=\n{\n",6,1,file);
	for(i=0;i<colornum*3;++i)
	{
		++j;
		num=*buf;
		tmp=num>>4;
		if(j==1)
		{
			bbb1[2]=aaa[tmp];
			tmp=(num & 0xf);
			bbb1[3]=aaa[tmp];
		}
		if(j==2)
		{
			bbb2[2]=aaa[tmp];
			tmp=(num & 0xf);
			bbb2[3]=aaa[tmp];
		}
		if(j==3)
		{
			bbb3[2]=aaa[tmp];
			tmp=(num & 0xf);
			bbb3[3]=aaa[tmp];
			fwrite("	{0x80,",7,1,file);
			fwrite(bbb3,4,1,file);
			fwrite(",",1,1,file);
			fwrite(bbb2,4,1,file);
			fwrite(",",1,1,file);
			fwrite(bbb1,4,1,file);
			if(i<(colornum+1)*3-1)
				fwrite("},\n",3,1,file);
			else
				fwrite("}\n",2,1,file);
			j=0;
			++buf;
		}
		++buf;
	}
	fwrite("};",2,1,file);
	fclose(file);
	free(p);
/*static stGFX_Palette_t  stUI_PalDa = 
				{
					GFX_PALETTE_TYPE_ARGB_8888,
					256,
					bmp_plate,      
				};*/



	file=fopen(filename,"rb");
	fseek(file,54+(colornum+1)*4,SEEK_SET);
	p=buf=(unsigned char *)malloc(width*height*3);
	fread(buf,1,width*height*3,file);
	fclose(file);
	file=fopen("color data.txt","wa+");
	fwrite("static unsigned char ",21,1,file);
	fwrite(dataname,strlen(dataname),1,file);
	fwrite("[]=\n{",5,1,file);
	for(k=height-1;k>=0;--k)
	{
		for(i=1;i<=width;++i)
		{
			if(i==1||i%17==0)
				fwrite("\n	",2,1,file);
			++j;
			num=*(buf+k*width+i);
			tmp=num>>4;
			bbb1[2]=aaa[tmp];
			tmp=(num & 0xf);
			bbb1[3]=aaa[tmp];
			fwrite(bbb1,4,1,file);
			if(k!=0 || i<width)
				fwrite(", ",2,1,file);
		}	
	}
	fwrite("\n};",3,1,file);
	fclose(file);
	free(p);
}
