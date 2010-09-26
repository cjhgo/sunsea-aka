#include <stdio.h> 
#include <stdlib.h>



void swap(int i, int j)
{
	  int temp;
  	  temp = i;
  	  i = j;
  	  j = temp;
	  printf("%d,%d\n",i,j);
}
int main(void)
{
	  int a=2, b=3;
	  printf("a=%d,b=%d\n", a, b);
	  swap(a,b);
	 //printf("a=%d,b=%d\n", a, b);
	  return 0;
}

