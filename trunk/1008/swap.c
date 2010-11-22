#include <stdio.h>

void swap(int *pa, int *pb)
{
	int tmp;

	tmp = *pa;
	*pa = *pb;
	*pb = tmp;

	return;
}

int main(int argc, char* argv[])
{
	int a = 3;
	int b = 2;
	char *p = "hello";
	char *q = "abdc";

	printf("a = %d\n", a); 
	printf("b = %d\n", b); 

	printf("%s\n", p);
	printf("%s\n", q); 
	
	swap(&a, &b);
	swap(&p, &q);

	printf("a = %d\n", a); 
	printf("b = %d\n", b);

	printf("%s\n", p);
	printf("%s\n", q); 

	return 0;
}

