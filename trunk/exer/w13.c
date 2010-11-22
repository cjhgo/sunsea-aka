#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1

struct student
{
	int ID;
	char * name;
	int chinese;
	int math_grade;
	float average;
};

struct student stu[SIZE];
void save()
{
	FILE *fp;
	int i;
	
	if((fp = fopen("cj.txt","a")) == NULL)
	{
		printf("can not open this file!\n");
		return;	
	}
	for(i = 0; i <SIZE ; i++)
	{
		if(fwrite(&stu,sizeof(stu),1,fp) != 1)
			printf("file write error!\n");
	//	if(fprintf(fp, "%d\r\n%s\r\n%d\r\n%d\t\n%f\r\n",stu[i].ID, stu[i].name, stu[i].chinese, stu[i].math_grade, stu[i].average) == 0)
	//		printf("file write error!\n");
	}
	fclose(fp);
}
int main(void)
{
	int i;
	for(i = 0;i < SIZE; i++)
	{
		scanf("%d %s %d %d %f", &stu[i].ID, stu[i].name, &stu[i].chinese, &stu[i].math_grade, &stu[i].average);
	}

	save();

}
