/* 项目名称：双向链表的基本操作
 * 
 * 项目成员：张双喜
 *
 * 项目开始时间：2010年9月23日  16：00
 * 预计完成时间：2010年9月25日  18：00
 * 实际完成时间：2010年9月24日  00：20
 * 项目修改时间：2010年9月24日  09：00
 *
 * 项目功能：
 * 创建链表、正向遍历、反向遍历、求长度、排序、插入、删除、查找
 *
 * 项目总结：		2010年9月24日 14：00
 * 	1、对于malloc分配的节点，删除后不要忘记用free释放掉。
 * 	2、验证双链表创建时候成功，可用正向遍历和反向遍历链表检验，如果均能正确遍历即可说明双链表创建成功。
 *	3、学习的vim快捷键：
 *			1、shift + k			查找库函数
 *			2、shift + 3			一个程序内查找指定函数的位置
 *	4、存在问题：
 *			对于排序后，无法实现反向遍历
 * */

#include <stdio.h> 
#include <stdlib.h> 

typedef struct Node
{
	int data;
	struct Node * next;
	struct Node * prior;
}NODE, *PNODE;

PNODE create_list(void);	//创建节点
void traverse_list_right(PNODE pHead);	//遍历链表（打印）
void traverse_list_left(PNODE pHead);	//遍历链表（打印）
int length_list(PNODE pHead);		//求链表长度
void sort_list(PNODE pHead);		//排序
void insert_list(PNODE pHead, int pos, int val);		//插入节点
void delect_list(PNODE pHead, int pos, int *val);	//删除节点
int find_list(PNODE pHead, int val,int *pos);		//查找元素

int main(int argc, char* argv[])
{
	int pos_insert;
	int val_insert;
	int pos_delect;
	int val_delect;
	int pos_find;
	int val_find;

	PNODE pHead = NULL;

	//初始化链表
	pHead = create_list();
	printf("\n原来链表：\n"); 

	//正向遍历
	traverse_list_right(pHead);
	printf("链表的长度是：%d\n",length_list(pHead)); 
	printf("\n");

	//反向遍历
	traverse_list_left(pHead);
	printf("链表的长度是：%d\n",length_list(pHead)); 
	printf("\n"); 

	//插入元素
	printf("请输入您要插入的元素位置：pos = "); 
	scanf("%d",&pos_insert);
	printf("请输入您要插入的元素值：val = "); 
	scanf("%d",&val_insert);
	printf("插入元素后：\n"); 
	insert_list(pHead, pos_insert, val_insert);
	traverse_list_right(pHead);
	printf("链表的长度是：%d\n",length_list(pHead)); 
	printf("\n"); 
	traverse_list_left(pHead);
	printf("链表的长度是：%d\n",length_list(pHead)); 
	printf("\n"); 

	//删除元素
	printf("请输入您要删除的元素位置：pos = "); 
	scanf("%d",&pos_delect);
	printf("删除元素后：\n"); 
	delect_list(pHead, pos_delect, &val_delect);
	traverse_list_right(pHead);
	printf("链表的长度是：%d\n",length_list(pHead)); 
	traverse_list_left(pHead);
	printf("链表的长度是：%d\n",length_list(pHead)); 
	printf("您删除的节点元素是：%d\n",val_delect); 
	printf("\n"); 

	//查找元素
	printf("请输入您要查找的元素的值：val = ");
	scanf("%d",&val_find);
	printf("查找元素：\n"); 
	if(find_list(pHead, val_find, &pos_find) == 0)
	{
		printf("您要查找的元素位置是：%d\n", pos_find); 
		printf("\n"); 
	}
	else
		printf("您要查找的元素不存在！\n"); 
	printf("\n"); 

	//排序
	printf("排序后：\n"); 
	sort_list(pHead);
	traverse_list_right(pHead);
	traverse_list_left(pHead);
	printf("链表的长度是：%d\n",length_list(pHead)); 
	printf("\n"); 

	return 0; 
}

//创建链表
PNODE create_list(void)
{
	int len;
	int i, val;
	PNODE pTail;

	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if(NULL == pHead)
	{
		printf("动态内存分配失败，程序终止！\n"); 
		exit(-1);
	}
	pTail = pHead;
	pTail->next = NULL;

	printf("请输入您要创建链表的长度：\nlen = "); 
	scanf("%d",&len);

	for(i = 0; i < len; i++)
	{
		printf("请输入第%d个节点的值：val = ", i+1); 
		scanf("%d",&val);

		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if(NULL == pNew)
		{
			printf("新节点动态内存分配失败，程序终止！\n"); 
			exit(-1);
		}
		pNew->data = val;
		pTail->next = pNew;
		pNew->prior = pTail;
		pNew->next = NULL;
		pTail = pNew;
	}

	return pHead;
}

//正向遍历链表（打印）
void traverse_list_right(PNODE pHead)
{
	PNODE p;

	p = pHead->next;
	printf("正向遍历链表\n"); 
	if(NULL == p)
	{
		printf("链表为空！\n"); 
	}
	while(NULL != p)
	{
		printf("%d  ",p->data); 
		p = p->next;
	}
	printf("\n"); 

	return;
}

//反向遍历链表（打印）
void traverse_list_left(PNODE pHead)
{
	PNODE p, last;

	p = pHead->next;
	last->next = NULL;

	printf("反向遍历链表\n"); 
	if( NULL == p)
	{
		printf("链表为空！\n"); 
	}
	while(NULL != p)
	{
		last = p;
		p = p->next;
	}

	while(NULL != last->prior)
	{
		printf("%d  ",last->data); 
		last = last->prior;
	}
	printf("\n"); 

	return;
}

//求链表长度
int length_list(PNODE pHead)
{
	int len = 0;
	PNODE p;
	p = pHead;

	while(NULL != p)
	{
		len++;
		p = p->next;
	}
	return len-1;

}

//链表排序
void sort_list(PNODE pHead)
{
	int len, i, j, temp;
	PNODE p, q, t;

	len = length_list(pHead);

	for(i = 0,p = pHead->next; i < len; i++,p = p->next)
	{
		for(j = i+1, q = p->next; j < len; j++, q = q->next)
		{
			if(p->data > q->data)
			{
				t = p;
				p = q;
				q = t;
			//	t = p;
			//	printf("%d\n",t->data); 
			//	p->prior = q;
			//	p->next = q->next;
			//	q->prior = t->prior;
			//	q->next = p;
			}
		}
	}

	return;
}

//插入元素
void insert_list(PNODE pHead, int pos, int val)
{
	int i;
	PNODE pNew, p;
	p = pHead;

	pNew = (PNODE)malloc(sizeof(NODE));
	if(NULL == pNew)
	{
		printf("新节点动态内存分配失败，程序终止！\n"); 
		exit(-1);
	}
	pNew->data = val;

	if((pos > (length_list(pHead)+1)) || (pos <= 0))
	{
		printf("插入失败，插入位置不正确！\n"); 
		exit(-1);
	}
	for(i = 0; i < pos-1; i++)
	{
		p = p->next;
	}
	if(NULL == p->next)
	{
		p->next = pNew;
		pNew->prior = p;
		pNew->next = NULL;
	}
	else
	{
		pNew->next = p->next;
		p->next->prior = pNew;
		p->next = pNew;
		pNew->prior = p;
	}

	return;
}

//删除元素
void delect_list(PNODE pHead, int pos, int *val)
{
	int i;
	PNODE p = pHead;
	PNODE q;

	if(length_list(pHead) == 0)
	{
		printf("链表为空，没有内容可以删除！\n"); 
		exit(-1);
	}
	if((pos > length_list(pHead)) || (pos <= 0))
	{
		printf("删除元素的位置不是合法位置，删除失败！\n"); 
		exit(-1);
	}
	for(i = 0; i < pos-1; i++)
	{
		p = p->next;
	}
	q = p->next;
	printf("%d\n",q->data); 

	if(NULL == p->next->next)
	{
		*val = p->next->data;
		p->next = NULL;
		
	}
	else
	{
		*val = p->next->data;

		p->next->next->prior = p;
		p->next = q->next;
	}
	
	free(q);

	return;
}

//查找元素
int find_list(PNODE pHead, int val,int *pos)
{
	PNODE p = pHead;
	int i = 0;

	while(p != NULL)
	{
		i++;
		if(p->data == val)
		{
			*pos = i-1;
			return 0;
		}
		p = p->next;
	}

	return 1;
}
