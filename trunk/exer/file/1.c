#include<stdio.h>
main()
{
	FILE *fp;
	char ch;
	if((fp=fopen("e10_1.c","rt"))==NULL)
	{
		printf("Cannot open file strike any key exit!");
//		getch();
//		exit(1);
		return;
	}
	ch=fgetc(fp);
	while (ch!=EOF)
	{
		putchar(ch);
		ch=fgetc(fp);
	}
	fclose(fp);
}

