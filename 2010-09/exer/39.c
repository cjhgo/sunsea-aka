//给定某年某月某日，将其转换成这一年的第几天并输出

#include <stdio.h>

int day_of_year(int daytab[][12],int y,int m,int d)
{
	int i,j;
	 
	i = ((y % 4 ==0)&&(y % 100 != 0))||(y % 400 == 0);
	
	for(j = 0; j < m-1; j++)
	{ 
		d = d + *(*(daytab+i)+j);
	}

	return d;
}

int main(int argc, char* argv[])
{
	int y,m,d;
	int val;

	int daytab[2][12] = {
		{31,28,31,30,31,30,31,31,30,31,30,31},
		{31,29,31,30,31,30,31,31,30,31,30,31}};
	
	printf("please input y,m,d:\n"); 
	scanf("%d%d%d",&y,&m,&d);

	val = day_of_year(daytab,y,m,d);
	printf("%d\n",val); 
	return 0; 
}

/*
   以下代码已经调试成功
int main(int argc, char* argv[])
{

	int y,m,d;
	int i,j;

	int daytab[2][12] = {
		{31,28,31,30,31,30,31,31,30,31,30,31},
		{31,29,31,30,31,30,31,31,30,31,30,31}};
	
	printf("please input y,m,d:\n"); 
	scanf("%d%d%d",&y,&m,&d);
	
	i = ((y % 4 ==0)&&(y % 100 != 0))||(y % 400 == 0);
	
	for(j = 0; j < m-1; j++)
	{
		d = d + *(*(daytab+i)+j);
	}

	printf("%d\n",d); 
	return d;

}
*/
