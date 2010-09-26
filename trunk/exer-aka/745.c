/*创建一个有5个结点的单链表
 * struct student
 *{
 * 	unsigned ID;
 *	char name[20];
 *	struct student *next;
 *};
 * 按ID升序输入内容构建单链表并实现新数据的插入
 */

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef struct student
{
	unsigned ID;
	char name[20];
	struct student * next;
}ST, * PST;

PST create_list(void);
void traverse_list(PST pHead);
void sort_list(PST pHead);
int length_list(PST pHead);
int insert_list(PST pHead,int pos,int valID,char valName[20]);
int delect_list(PST pHead,int pos,int *valID,char valName[20]);

int main(int argc, char* argv[])
{
	int length;
	PST pHead = NULL;
	char val[20];
	int valID;
	char valName[20];

	pHead = create_list();
	printf("原始链表:\n\n"); 

	length = length_list(pHead);
	if(length <= 0)
	{
		printf("链表的长度为0。\n"); 
	}
	else
	{
		printf("链表的长度是：%d\n",length); 
	}
	traverse_list(pHead);

	printf("排序后：\n\n"); 
	sort_list(pHead);
	traverse_list(pHead);

	printf("插入元素后:\n\n"); 
	if(insert_list(pHead,5,99,"zsx") == 0)
	{
		printf("插入元素成功！\n"); 
	}
	else
		printf("插入元素失败！\n"); 
	traverse_list(pHead);
	
	printf("删除元素后:\n\n"); 
	if(delect_list(pHead, 3,&valID,valName))
	{
		printf("删除失败！\n"); 
	}
	else
		printf("删除成功，ID ＝ %d ,name = %s\n",valID,valName); 
	traverse_list(pHead);
	
	return 0; 
}

PST create_list(void)
{
	int len;
	int i;
	char valName[20];
	unsigned valID;

	PST pHead = (PST)malloc(sizeof(ST));
	if(NULL == pHead)
	{
		printf("动态内存分配失败，程序终止！\n"); 
		exit(-1);	
	}
	PST pTail = pHead;
	pTail->next = NULL;

	printf("请输入你要建立的链表长度：\n"); 
	scanf("%d",&len);
	printf("\n"); 
	for(i = 0; i < len; i++)
	{
		printf("请输入第%d个节点的ID,name：\n",i+1);
		scanf("%d %s",&valID,valName);
		printf("\n"); 
		PST pNew = (PST)malloc(sizeof(ST));
		if(NULL == pNew)
		{
			printf("动态内存分配失败，程序终止！\n"); 
			exit(-1);
		}
		pNew->ID = valID;
		strcpy(pNew->name,valName);
		pTail->next = pNew;
		pNew->next = NULL;
		pTail = pNew;	
	}

	return pHead;
}

void traverse_list(PST pHead)
{
	printf("ID\tname\n"); 
	PST p = pHead->next;
	while(NULL != p)
	{
		printf("%d\t%s\n",p->ID,p->name);
		p = p->next;
	}
	printf("\n"); 
	return;
}

int length_list(PST pHead)
{
	int len = 0;
	PST p;
	p = pHead->next;

	while(p !=NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}

void sort_list(PST pHead)
{
	int i, j, length;
	int ID;
	char name[20];
	
	PST p,q,tmp;
	length = length_list(pHead);
	for(i = 0, p = pHead->next; i < length-1; i++, p = p->next)
	{
		for(j = i+1, q = p->next;j < length; j++, q = q->next)
		{
			if(p->ID > q->ID)
			{
				ID = p->ID;
				p->ID = q->ID;
				q->ID = ID;

				strcpy(name,p->name);
				strcpy(p->name,q->name);
				strcpy(q->name,name);
			}
		}
	}
	return;
}

int insert_list(PST pHead,int pos,int valID,char valName[20])
{
	int i = 0;
	PST p = pHead;
	PST q;

	while(NULL != p && i < pos -1)
	{
		 p = p->next;
		 i++;	 
	}
	if(i > pos-1 || NULL == p)
		return 1;
	PST pNew = (PST)malloc(sizeof(PST));
	if(NULL == pNew)
	{
		printf("动态内存分配失败，程序终止！\n");
		exit(-1);
	}
	pNew->ID = valID;
	strcpy(pNew->name, valName);
	q = p->next;
	p->next = pNew;
	pNew->next = q;

	return 0;

}

int delect_list(PST pHead,int pos, int *valID, char valName[20])
{
	int i = 0;
	PST p,q;

	p = pHead;
	while(NULL != p && i < pos -1)
	{
		p = p->next;
		i++;
	}
	if(i > pos-1 || NULL == p)
		return 1;
	q = p->next;
	*valID = q->ID;
	strcpy(valName,q->name);
	p->next = p->next->next;
	free(q);
	q = NULL;	//为什么置空
	
	return 0; 
}
