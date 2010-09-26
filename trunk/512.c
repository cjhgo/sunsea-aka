//用结构体数组实现学生学籍管理
//记录的信息包括学生ID、年龄、性别
//姓名、数学、英语成绩并以ID位关键字进行排序

#include <stdio.h>
#include <string.h>

typedef struct student
{
	int ID;
	int age;
	char sex;
	char name[10];
	int math;
	int english;
}stu;

void sort(stu *ps, int n);

int main(int argc, char* argv[])
{
	int num, i;
	char tmp;
	printf("请输入学生的人数： \n"); 
	scanf("%d",&num);
	stu s[num];
	for(i = 0; i < num; i++)
	{	printf("请输入第%d个学生的信息：\n",i+1); 
		printf("ID = ");
		scanf("%d", &s[i].ID);
		printf("age = "); 
		scanf("%d", &s[i].age);
		scanf("%c", &tmp);    //临时变量接受回车字符，不然会导致这种情况 sex = name = 
		printf("sex = ");
		scanf("%c", &s[i].sex);
//		scanf("%c", &tmp);
		printf("name = ");
		scanf("%s", s[i].name);
		printf("math = ");
		scanf("%d", &s[i].math);
		printf("english = ");
		scanf("%d", &s[i].english);
		printf("\n"); 
	}

	sort(s, num);  //按ID升序排列

	for(i = 0; i < num; i++)
	{
		printf("ID = %d\t,age = %d\t,sex =  %c\t,name = %s\t,math = %d\t,english = %d\t\n",\
			s[i].ID,s[i].age,s[i].sex,s[i].name,s[i].math,s[i].english); 
	}

	return 0; 
}

void sort(stu *ps, int n)
{
	int i, j;
	stu tmp;

	for(i = 0; i < n-1; i++)
	{
		for(j = 0; j < n-1-i; j++)
		{
			if(ps[j].ID > ps[j+1].ID)
			{
				tmp = ps[j];
				ps[j] = ps[j+1];
				ps[j+1] = tmp;
			}
		}
	}
}
