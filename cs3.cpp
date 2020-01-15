#include <stdio.h>
#include <stdlib.h>
/* 产生start到end的随机数*/
int randomInRange(int start, int end)
{
	int ret = start + rand()%(end - start + 1);
	return ret;
}
/* 交换两个数字的位置*/
void swap(int *num1, int *num2)
{
	int tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

 /* 返回选中数字位置，并使得选中的数字的左边的数都小于data[index],选中数字右边的数都大于data[index]*/
int partition(int *data, int length, int start, int end)
{
	int ret = 0;
	int index = randomInRange(start, end);
	int small = start - 1;
 	swap(&data[index], &data[end]);
	if (data == NULL || length < 0 ||start < 0 || end >= length)
	{
		ret = -1;
		printf("error:%d\n", ret);
		return ret;
	}
	for (index = start; index < end; index++)
	{
		if(data[index] < data[end])
		{
			++small;
			if (small != index)
			{
				swap(&data[index], &data[small]);
			}
 
		}
	}
	++small;
	swap(&data[small],&data[end]);
	return small;
} 
void GetLeastNum(int *input, int n, int *output, int k)
{
	int start = 0;
	int end = n - 1;
	int i = 0;
	int index = partition(input, n, start, end);
	if (input == NULL || output == NULL ||k > n||k <= 0)
	{
		return ;
	}
	while (index != k-1)
	{
		if (index > k-1)
		{
			end = index - 1;
			index = partition(input, n, start, end);
		}
		else
		{
			start = index + 1;
			index = partition(input, n, start, end);
		}
	}
	for (i = 0; i < k; i++)
	{
		output[i] = input[i];
	}
}
int main()
{
	int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
	int outdata[10] = {0};
	GetLeastNum(data, 8, outdata, 4);
	int i = 0;
	for (i = 0; i < 4; i++)
		printf("%d ", outdata[i]);
	return 0;
}
