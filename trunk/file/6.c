#include<stdio.h>
struct stu
{
	char name[10];
	int num;
	int age;
	char addr[15];
}boya[2],boyb[2],*pp,*qq;
main()
{
	FILE *fp;
	char ch;
	int i;
	pp=boya;
	qq=boyb;
	if((fp=fopen("stu_list","wt+"))==NULL)
	{
		printf("Cannot open file strike any key exit!");
	//	getch();
	//	exit(1);
	return;
	}
	printf("\ninput data:name,num age,addr\n");
	for(i=0;i<2;i++,pp++)
		scanf("%s%d%d%s",pp->name,&pp->num,&pp->age,pp->addr);
	pp=boya;
	fwrite(pp,sizeof(struct stu),2,fp);
	rewind(fp);
	fread(qq,sizeof(struct stu),2,fp);
	printf("\n\nname\tnumber\tage\taddr\t\n");
	for(i=0;i<2;i++,qq++)
		printf("%s\t%d\t%d\t%s\t\n",qq->name,qq->num,qq->age,qq->addr);
	fclose(fp);
}

