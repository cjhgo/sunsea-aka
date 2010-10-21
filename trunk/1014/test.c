#include <stdio.h>

typedef struct student
{
	char name[2];
	int id;
}stu, *pStu;

int main(int argc, char* argv[])
{
	char str[] = "123456";
	stu s;

	printf("%d\n", sizeof(stu));
	printf("%d\n", sizeof(s.name)); 
	printf("%d\n", sizeof(s.id)); 

	return 0; 
}
