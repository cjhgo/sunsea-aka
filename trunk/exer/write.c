#include <stdio.h>
#include <string.h>


typedef struct  
{
	int   NO;
	char   name[10];
}ST;

ST st1;


int main(void)
{
	FILE   *fp1;
	   
	st1.NO=1;
	strcpy(st1.name, "Name ");
	      
	if((fp1=fopen( "file1.c ", "wb "))==NULL)
		return;	
	fseek(fp1,21,SEEK_SET);
	fwrite(&st1,sizeof(ST),1,fp1);
	
	fclose(fp1);
} 
