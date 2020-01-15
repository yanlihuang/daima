#include <stdio.h>
#include <stdlib.h>
//快速排序
void quick_sort(int a[],int left,int right) //直接排序数组，返回值为void
{
	//定义左右指针指向数组的下标
	int i = left;
	int j = right;
	//递归出口
	if(i>j)
		return;
	int key=a[i];//记录标杆值
	//一次循环可以得到：标杆的左侧都比标杆小，标杆的右侧都比标杆大
	while(i<j)
	{
		while(i<j && a[j]>=key)//从right开始找比标杆小的为止
			j--;
		a[i]=a[j];//将较小的数赋值到left上
		while(i<j && a[i]<=key)//从left开始找比标杆大的为止
			i++;
		a[j]=a[i];//将较大的数赋值到right上
	}
	a[i]=key;//将标杆值补到数组中
	//一次循环完成

	//进行左侧和右侧的递归
	quick_sort(a,left,i-1);
	quick_sort(a,i+1,right);
}
//调用快速排序
void quick_sort(int a[],int len)
{
	quick_sort(a,0,len-1);
}
void show(int a[],int len)
{
	for(int i=0;i<len;i++)
		printf("%d ",a[i]);
	printf("\n");

}
int main()
{
	int arr[10]={1,3,5,7,9,-4,-2,-6,0,-9};
	printf("原序列为：") ;
	show(arr,10);
	printf("排序后的序列为：") ;
	quick_sort(arr,10);
	show(arr,10);
}
