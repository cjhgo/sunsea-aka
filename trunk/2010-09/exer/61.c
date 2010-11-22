#include <stdio.h>

int main(int argc, char * argv[])
{
	char a = 'A', b = 'X';
	char *p = NULL;
					
	printf("addr a = 0x%x, a = %c\n", &a, a);
	printf("addr b = 0x%x, b = %c\n", &b, b);
	p = &a;				/*¿¿¿¿¿¿¿*/
	*p = 'Y';
	printf("p(a) = 0x%x, *p = %c\n", p, *p);
	p = &b;
	*p = 'B';
	printf("p(b) = 0x%x, *p = %c\n", p, *p);

	return 0;
}
