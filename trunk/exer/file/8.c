#include<stdio.h>
struct stu
{
	char name[10];
	int num;
	int age;
	char addr[15];
}boy,*qq;
main()
{
	FILE *fp;
	char ch;
	int i=1;
	qq=&boy;
	if((fp=fopen("stu_list","rb"))==NULL)
	{
		printf("Cannot open file strike any key exit!");
//		getch();
//		exit(1);
		return;
	}
	rewind(fp);
	fseek(fp,i*sizeof(struct stu),0);
	fread(qq,sizeof(struct stu),1,fp);
	printf("\n\nname\tnumber\tage\taddr\n");
	printf("%s\t%d\t%d\t%s\t\n",qq->name,qq->num,qq->age,qq->addr);
}

