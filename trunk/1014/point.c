#include <stdio.h>

void swap_int(int *p, int *q)
{
	int tmp;

	tmp = *p;
	*p = *q;
	*q = tmp;

	return;
}

void swap_char(char **p, char **q)
{
	char *tmp;

	tmp = *p;
	*p = *q;
	*q = tmp;

	return;
}

int main(int argc, char* argv[])
{
	int a = 5;
	int b = 6;
	char *pa = "abcdefgh";
	char *pb = "12345678";
	
	printf("a = %d, b = %d\n", a, b); 
	printf("pa = %s, pb = %s\n", pa, pb); 

	swap_int(&a, &b);
	swap_char(&pa, &pb);

	printf("============================\n"); 
	printf("a = %d, b = %d\n", a, b); 
	printf("pa = %s, pb = %s\n", pa, pb); 
	
	return 0;
}
