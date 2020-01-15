#include<stdio.h>
int Find(int a[],int size,int to_find)
{
	int left=0;
	int right=size-1;
	while(left<=right)
	{
		int mid=(left+right)/2;
		if(to_find<a[mid])
			right=mid-1;		
		else if(to_find>a[mid])
			left=mid+1;
 		else
			return mid;
	}
}
int main()
{
	int a[]={1,2,3,4,5,6,7,8,9,10}; 
	int to_find;
	printf("请输入要查找的数：");
	scanf("%d",&to_find);
	int size=sizeof(a)/sizeof(a[0]);
	int i=Find(a,size,to_find);
	if(i==-1)
		printf("没找到！\n");
	else
		printf("找到了！下标为：%d\n",i);
	
}
