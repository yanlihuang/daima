#include<stdio.h>
int max(int a, int b);
int value[100][100];//value[i][j]ǰi����Ʒװ���������Ϊj�ı���������ֵ
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
	//�����Ž�
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

	//�ж���Ʒ���״̬
	j=c;
	for(i=n;i>=1;i--)
	{
		if(value[i][j] > value[i-1][j])
		{
			x[i]=1;
			j = j - w[i-1];//����һ����Ʒ��ı����������
		}
		else
		{
			x[i]=0;
		}
	}
	printf("ѡ�е���Ʒ�ǣ�");
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
	int n; //��Ʒ����
	int c; //�����������
	int s;//�������ֵ
	int w[20];//��Ʒ����
	int v[20];//��Ʒ��ֵ
	int x[20];//��Ʒ���״̬
	printf("���뱳�����������");
	scanf("%d",&c);
	printf("������Ʒ������������20������");
	scanf("%d",&n);
	printf("������Ʒ��������\n");
	for(i=0;i<n;i++)
	{
		scanf("%d", &w[i]);
	}
	printf("������Ʒ����ֵ��\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&v[i]);
	}
	s=package(n,w,v,x,c);
	printf("�����Ʒ��ֵΪ��%d\n",s);
}
