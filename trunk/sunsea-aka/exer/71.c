#include <stdio.h>
typedef struct 
{
	char name[3];
	int  age;
	double record;
}stu;

int main(int argc, char * argv[])
{
	stu s = {"jk", 20, 98.9};
	stu *ps;
	ps = &s;
	
	printf("stu = %d\n", sizeof(stu));
	printf("name = %s\n", ps->name);
	printf("age = %d\n", ps->age);
	printf("record = %lf\n", ps->record);


	return 0; 

}

