#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct man
{
	char name[20];
	int age;
	char gender[7];
};

int main(int argc, char* argv[])
{
	struct man m[3];
	int i;

	printf("please input name, age, gender.\n");
	for(i = 0; i < 3; i++)
	{
		scanf("%s %d %s",&m[i].name, &m[i].age, &m[i].gender);	
	}
	
	for(i = 0; i < 3; i++)
	{
		printf("%s %d %s\n",m[i].name, m[i].age, m[i].gender);	
	}

	return 0;
}
