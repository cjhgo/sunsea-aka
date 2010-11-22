#include "stdio.h"

void ConvertTo2(int);
void ConvertTo8(int);
void ConvertTo16(int);

main()
{
	int x;
	scanf("%d",&x);
	ConvertTo2(x);
	ConvertTo8(x);
	ConvertTo16(x);
}
void ConvertTo2(int x)
{
	char a[100];
	int i=0,j=0,k=x;
	do{
		j=x%2;
		x=x/2;
		a[i]='0'+j;
		i++;
	}while(x!=0);
	printf("%d 的二进制是：",k);
	while(i>0) 
	        printf("%c",a[--i]);
		printf("\n");
}

void ConvertTo8(int x)
{
	char a[100];
	int i=0,j=0,k=x;
	do{
		j=x%8;
		x=x/8;
		a[i]='0'+j;
		i++;
	}while(x!=0);
	printf("%d 的八进制是：",k);
	while(i>0) 
        printf("%c",a[--i]);
	printf("\n");
}

void ConvertTo16(int x)
{
	char a[100];
	int i=0,j=0,k=x;
	do{
		j=x%16;
		x=x/16;
		if(j<10)
			a[i]='0'+j;
		else
			a[i]='A'+(j-10);
		i++;
	}while(x!=0);
	printf("%d 的十六进制是：",k);
	while(i>0) 
        printf("%c",a[--i]);
	printf("\n");
}
