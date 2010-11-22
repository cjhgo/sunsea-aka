#include   <stdio.h>
#include   <stdlib.h>
#include   <string.h>
typedef   struct  
{
	        int   NO;
		        char   name[10];
}   ST;
int   main()
{
	ST   test;
	ST   read;
	FILE   *pFile;
	test.NO   =   10;
	pFile   =   fopen(   "file1.dat ", "wb ");
	strcpy(test.name, "dog ");  
	char   buffer[]   =   "假设已有文件file1,如何将以上结构变量从文件的第21个字节起写入？在另一段程序中，又如何将它从file1中的第21个字节读出？要完整代码段。 ";
	fwrite(buffer,strlen(   buffer),1,pFile   );
	fclose(   pFile   );//上面是测试数据
	pFile=   fopen(   "file1.dat ", "rb+ ");
	if(   pFile   ==   NULL   )
	{
		exit(   1   );
	}
	fseek(   pFile,21,SEEK_SET);
	fwrite(   &test,sizeof(   ST),1,pFile   );
	fclose(   pFile   );
	pFile=   fopen(   "file1.dat ", "rb ");
	fseek(   pFile,21,SEEK_SET);
	fread(   &read,sizeof(ST),1,pFile   );
	printf(   "%d   %s ",read.NO,read.name   );
	fclose(   pFile   );


}
