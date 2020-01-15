#include<stdio.h>
int max(int a, int b);
int value[100][100];//value[i][j]前i个物品装入最大容量为j的背包中最大价值
int package(int n, int w[], int v[], int x[], int c)
{
	int i,j;
	for(i=0;i<=n;i++)
	{
		value[i][0]=0;
	}
	for(j=0;j<=c;j++)
	{
		value[0][j]=0;
	}
	//找最优解
	for(i=1;i<=n;i++)
	{
		printf("%d %d %d ",i,w[i-1],v[i-1]);
		for(j=1;j<=c;j++)
		{
			if(j < w[i-1])
			{
				value[i][j]=value[i-1][j];
				printf("[%d][%d]=%2d",i,j,value[i][j]);
			}
			else
			{
				value[i][j]=max(value[i-1][j], value[i-1][j-w[i-1]]+v[i-1]);
				printf("[%d][%d]=%2d",i,j,value[i][j]);
			}
		}
		printf("\n");
	}

	//判断物品标记状态
	j=c;
	for(i=n;i>=1;i--)
	{
		if(value[i][j] > value[i-1][j])
		{
			x[i]=1;
			j = j - w[i-1];//放入一个物品后的背包最大容量
		}
		else
		{
			x[i]=0;
		}
	}
	printf("选中的物品是：");
	for(i=1;i<=n;i++)
	{
		printf("%2d",x[i]);
	}
	printf("\n");
	return(value[n][c]);
}

int max(int a, int b)
{
	if(a >= b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int  main()
{
	int i;
	int n; //物品数量
	int c; //背包最大容量
	int s;//获得最大价值
	int w[20];//物品质量
	int v[20];//物品价值
	int x[20];//物品标记状态
	printf("输入背包最大容量：");
	scanf("%d",&c);
	printf("输入物品数量（不超过20件）：");
	scanf("%d",&n);
	printf("输入物品各质量：\n");
	for(i=0;i<n;i++)
	{
		scanf("%d", &w[i]);
	}
	printf("输入物品各价值：\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&v[i]);
	}
	s=package(n,w,v,x,c);
	printf("最大物品价值为：%d\n",s);
}
