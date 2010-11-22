#include <stdio.h>
#include <stdlib.h>

int is_leep_year(int year);

int main(int argc, char* argv[])
{
	int year;

	printf("please input a year: \n");

	scanf("%d",&year);

	is_leep_year(year);

	return 1;
	 
}

int is_leep_year(int year)
{

	if(0 == (year % 400))
		printf("闰年\n");
	else if(0 ==(year % 4)&&(0 ==(year % 100)))
	printf("闰年\n");
	else
		printf("不是闰年\n");

}
