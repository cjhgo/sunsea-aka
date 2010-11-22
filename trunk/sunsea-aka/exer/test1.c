#include <stdio.h>

int main(int argc, char* argv[])
{
	enum num 
	{ a, b = 3, c};
	enum num aa = a;
	enum num bb = b;
	enum num cc = c;

	 
	printf("%d\n",aa); 
	printf("%d\n",bb); 
	printf("%d\n",cc); 

	return 0; 

}
