#include<stdio.h>
int a[10]={1,2,3,4,5,6,7,8,9,10};    //定义查找数组；
int Find(int left,int right,int number)  //left表示起点  right表示终点；
{
	while(left<right)
	{	
		int mid=(left+right)/2;     //设置中间值，用中间值与number比较；
		if(a[mid]==number)       //等于的话，说明找到了这个元素；
			return mid;
		else if(a[mid]>number)     //要找的值在mid的左边；
			return Find(left,mid-1,number);   //重新定义区间长度，调用Find函数；
		else                            //要找的值在mid的右边；
			return Find(mid+1,right,number);   //重新定义区间长度，调用Find函数；
	}
}
int main()
{
	int number;
	printf("请输入要查找的数: ");
	scanf("%d",&number);
	int pos=Find(0,9,number);
	printf("原数据表:  ");
	for(int i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	if(pos>=0)
		printf("查找成功!要查找的数位于数组下表为%d\n",pos);    
	else
		printf("查找失败!!!\n");
}

