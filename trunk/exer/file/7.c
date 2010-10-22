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
	if((fp=fopen("stu_list","wb+"))==NULL)
	{
		printf("Cannot open file strike any key exit!");
//		getch();
//		exit(1);
		return;
	}
	printf("\ninput data:name num age addr\n");
	for(i=0;i<2;i++,pp++)
		scanf("%s%d%d%s",pp->name,&pp->num,&pp->age,pp->addr);
	pp=boya;
	for(i=0;i<2;i++,pp++)
		fprintf(fp,"%s %d %d %s\n",pp->name,pp->num,pp->age,pp->
			addr);
	rewind(fp);
	for(i=0;i<2;i++,qq++)
		fscanf(fp,"%s %d %d %s\n",qq->name,&qq->num,&qq->age,qq->addr);
	printf("\n\nname\tnumber\tage\taddr\n");
	qq=boyb;
	for(i=0;i<2;i++,qq++)
		printf("%s\t%d\t%d\t%s\t\n",qq->name,qq->num, qq->age,
			qq->addr);
	fclose(fp);
}

