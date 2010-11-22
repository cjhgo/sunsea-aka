#include <stdio.h>

struct Array
{
	int data;
	int mark;
};

void bubble_sort(struct Array *,int );
int search(struct Array *,int ,int );

int main(int argc, char* argv[])
{
	int a[] = {5, -9, 32, 77, 63, -24, 14, 0, 21, 45};
	struct Array array[10],tmp;
	int i, j;
	int num,x;

	//把题目数组赋值于结构体；
	for(i = 0; i < 10; i++ )
	{
		array[i].mark = i;
		array[i].data = a[i];
		printf("%d ",array[i].data); 
	}
	printf("\n"); 


	printf("请输入要查询的数字： \n"); 
	scanf("%d", &num);

	bubble_sort(array, 10);//排序
	x = search(array, 10, num);//查找给定的数字

	if(x == -1)
		printf("该数组中不存在 %d ！\n",num); 
	else
		printf("%d 是该数组的第 %d 个元素！\n",num ,x+1); 
		
	return 0; 
}

//查找函数
int search(struct Array *p, int n, int num)
{
	int start = 0, end = n - 1, mid;

	while(start <= end)
	{
		mid = (start + end) / 2;
		if(p[mid].data < num)
			start = mid +1;
		else if(p[mid].data > num)
			end = mid - 1;
		else 
			return p[mid].mark;
	}
	return -1; 

}

//排序函数
void bubble_sort(struct Array *p,int n)
{
	int i, j;
	struct Array tmp;

	for(i = 0; i < n-1; i++)
	{
		for(j = 0; j < n-1-i;j++)
		{
			if(p[j].data > p[j+1].data)
			{
				tmp = p[j];
				p[j] = p[j+1];
				p[j+1] = tmp;			 
			}
		}
	}
}

