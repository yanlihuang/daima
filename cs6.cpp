#include<stdio.h>
#define maxnumber 20
typedef struct node{
	int w;
	int v;
	int i;
}Object;
float find(Object wp[],int n,float M)
{
	int x[maxnumber];
	int i;
	int maxprice=0;
	for(i=1;i<=n;i++)
	{
		x[i]=0.0;
	}	
	i=0;
	while(wp[i].w<M)
	{
		x[wp[i].i]=1;
		M=M-wp[i].w;
		i++;
	}
	x[wp[i].i]=M/wp[i].w;
	printf("�������ǣ�\n");
	for(i=1;i<=n;i++)
	{
		printf("x[%d]=%f",i,x[i]);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		maxprice=maxprice+wp[i].v*x[wp[i].i];
	}
	return maxprice;
}
int  main()
{
	Object wp[maxnumber];
	int i,j,n;
	int C;
	int flag;
	int maxprice,temp;
	printf("��������Ʒ������:");
	scanf("%d",&n);
	printf("�����뱳����������");
	scanf("%d",&C);
	printf("\n��������Ʒ����š������ͼ�ֵ:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&wp[i].i);
		scanf("%d",&wp[i].w);
		scanf("%d",&wp[i].v);
	}
	maxprice=find(wp,n,C);
	printf("\n��Ʒ�ļ�ֵΪ:%d",maxprice);
}

