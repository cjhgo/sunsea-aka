/*
   自定义一个文件，从终端输入文件内容，
   该文件每行的内容形如：1 name1 66 77（ID, 姓名， 语文成绩，数学成绩）
   定义一个结构体类型student形如：
   struct student{ int ID; cha *name; int chiese_grade; int math_grade; float average}。
   读取文件内容，存入struct student类型数组元素对应域中
   计算chinese_grade和math_grade平均值存入average域。
   将新构造的包含平均成绩的student变量内容再存入该文件中
*/

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
	
	if((fp = fopen("cj.txt","w")) == NULL)
	{
		printf("can not open this file!\n");
		return;	
	}
	for(i = 0; i < SIZE ; i++)
	{
		if(fwrite(&stu[i],sizeof(stu),1,fp) != 1)
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
