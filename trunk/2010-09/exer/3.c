 #include <stdio.h> 
 #include <stdlib.h>

 int main(int argc, char* argv[])
 {
 	int a;
	float b;

 	printf("please input a number:\n");
	scanf("%d",&a);
	printf("%d的平方= %d\n",a,a*a);
	
	b = 25/2;
	printf("25/2 = %d,25/2 = %f\n",25/2,b);

	return 0;
 }
