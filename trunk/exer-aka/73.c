#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum weekdays
{Monday = 1, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};

int main(int argc, char* argv[])
{
	enum weekdays weekday;
	int i;
	printf("please input ....\n"); 
	scanf("%d",&i);

	switch(i)
	{
	case 1:
		printf("Monday\n");
		break;
	case 2:
		printf("Tuesday\n");
		break;
	case 3:
		printf("Wednesday\n");
		break;
	case 4:
		printf("Thursday\n");
		break;
	case 5:
		printf("Friday\n");
		break;
	case 6:
		printf("Saturday\n");
		break;
	case 7:
		printf("Sunday\n");
		break;
	default:
		printf("wrong num!\n");
		break;
	}



	return 0; 
}
