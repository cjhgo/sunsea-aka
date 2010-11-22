#include <stdio.h>

//冒泡排序
void bubble_sort(int a[], int n)
{
	int i, j;
	int min;
	int tmp;

	for(i = 0; i < n; i++)				//进行比较多少趟
	{
		for(j = 0; j < n-i-1; j++)
		{
			if(a[j] > a[j+1])
			{
				tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}
		}
	}

	return;
}

//选择排序
void select_sort(int b[], int n)
{
	 int i, j, min, k;
	 int tmp;

	 for(i = 0; i < n-1; i++)
	 {
		min = i;
		for(j = i+1; j < n; j++)
		{
			if(b[min] > b[j])
			{
				min = j;
			}
			tmp = b[min];
			b[min] = b[i];
			b[i] = tmp;
		}
	 }

	 return;
}

int partition(int c[], int i, int j)
{
	int pivotkey = c[i];

	while(i < j)
	{
		while(i < j && c[j] > pivotkey)
		{
			j--;
		}
		c[i] = c[j];
		while(i < j && c[i] <= pivotkey)
		{
			i++;
		}
		c[j] = c[i];
	}
	c[i] = pivotkey;

	return i;
}

void quick_sort(int c[], int left, int right)
{
	int pivottag;

	if(left < right)
	{
		pivottag = partition(c, left, right);

		quick_sort(c, left, pivottag-1);
		quick_sort(c, pivottag+1, right);
	}

	return;

}

int main(int argc, char* argv[])
{
	int i;
	int a[10] = {3, 4, 1, 7, 9, 2, 5, 6, 8, 0};
	int b[10] = {3, 4, 1, 7, 9, 2, 5, 6, 8, 0};
	int c[10] = {3, 4, 1, 7, 9, 2, 5, 6, 8, 0};

	printf("after bubble_sort:\n"); 
	bubble_sort(a, 10);
	for(i = 0; i < 10; i++)
	{
		printf("%d  \n", a[i]); 
	}

	printf("after select_sort:\n"); 
	select_sort(b, 10);
	for(i = 0; i < 10; i++)
	{
		printf("%d  \n", b[i]); 
	}

	printf("after quick_sort:\n"); 
	quick_sort(c, 0, 9);
	for(i = 0; i < 10; i++)
	{
		printf("%d  \n", b[i]); 
	}

	return 0; 
}
