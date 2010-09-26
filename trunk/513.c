#include <stdio.h>
#include <string.h>

typedef struct student
{
	int id;
	char name[20];
	int chinese_grade;
	int math_grade;
	float average;
}stu;

int main(int argc, char* argv[])
{
	FILE *fp;
	stu s1,s2,*p,*q;

	p = &s1;
	q = &s2;

	if((fp = fopen("cj.txt","wb+")) == NULL)
	{
		printf("error!\n"); 
		return;	
	}

	printf("please input data:\nid,name,chinese_grade,math_grade\n");
	scanf("%d %s %d %d",&p->id,p->name,&p->chinese_grade,&p->math_grade);	//初始化数据

//	fwrite(p,sizeof(stu),1,fp);	//向fp文件写数据
//	rewind(fp);	//使fp指向文件开始位置
//	fread(q,sizeof(stu),1,fp);	//把fp中的内容读入到q中；q ＝ ＆s2；
//	printf("ID\tname\tchinese_grade\tmath_grade\t\n"); 
//	printf("%d\t%s\t%d\t\t%d\t\n\n",q->id,q->name,q->chinese_grade,q->math_grade);		//输出到屏幕 

	p->average = (p->chinese_grade + p->math_grade) / 2.0;

//	rewind(fp);
//	fwrite(p,sizeof(stu),1,fp);	//向fp文件写数据
	fprintf(fp,"%d %s %d %d %f",p->id,p->name,p->chinese_grade,p->math_grade,p->average);	//把含有平均成绩的结构体写入fp文件
	
	rewind(fp);
	fscanf(fp,"%d %s %d %d %f",&q->id,q->name,&q->chinese_grade,&q->math_grade,&q->average);//把fp中的内容写入的q结构体中，q ＝ ＆s2
//	fread(q,sizeof(stu),1,fp);	//把fp中的内容读入到q中；q ＝ ＆s2；

	printf("id\tname\tchinese_grade\tmath_grade\taverage_grade\n"); 
	printf("%d\t%s\t%d\t\t%d\t\t%f\t\n",q->id,q->name,q->chinese_grade,q->math_grade,q->average); 
	
	fclose(fp);

	return 0; 
}
