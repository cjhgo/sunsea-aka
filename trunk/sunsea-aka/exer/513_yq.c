#include <stdio.h> 
#include <stdlib.h>
#include <errno.h>
#include <string.h>

typedef struct{
	int ID;
	char *name;
	int chinese_grade;
	int math_grade;
	int eng_grade;
	float average;
}student;

int main(int argc, char *argv[])
{
	FILE *fp;
	char buf[100] = {'1'};
	int n;
	student std[3];

	if(argc != 2)
	{
		printf("Usage argc!\n");
		exit(1);	
	}
	fp = fopen(argv[1],"w+");
	if(!fp)
	{
		perror("open file");
		exit(1);	
	}
	printf("please input ID name chinese_grade math_grade eng_grade:\n");
	for(n = 0; n < 3; n++)
	{
		fgets(buf,100,stdin);
		fputs(buf,fp);	
	}

	rewind(fp);
	n = 0;
	printf("display:\n");
	while(fgets(buf,100,fp))
	{
		std[n].ID = atoi(strtok(buf," "));
		std[n].name = strtok(NULL," ");
		std[n].chinese_grade = atoi(strtok(NULL, " "));
		std[n].math_grade = atoi(strtok(NULL, " "));
		std[n].eng_grade = atoi(strtok(NULL, " "));
		
		printf("%d:id:%d,name:%s,chinese:%d,",n+1,std[n].ID,std[n].name,std[n].chinese_grade);
		printf("math:%d,eng:%d\n",std[n].math_grade,std[n].eng_grade);

		std[n].average = (std[n].chinese_grade + std[n].math_grade + std[n].eng_grade) / 3;
		n++;
	}

	rewind(fp);
	for(n = 0; n < 3; n++)
	{
		fprintf(fp, "%d %s %d %d %d %6.2f\n",std[n].ID, std[n].name, std[n].chinese_grade, std[n].math_grade,std[n].eng_grade,std[n].average);
	}
	fclose(fp);

	return 0;

}
