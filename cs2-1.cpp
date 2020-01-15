#include <stdio.h>
#include <stdlib.h>
//��������
void quick_sort(int a[],int left,int right) //ֱ���������飬����ֵΪvoid
{
	//��������ָ��ָ��������±�
	int i = left;
	int j = right;
	//�ݹ����
	if(i>j)
		return;
	int key=a[i];//��¼���ֵ
	//һ��ѭ�����Եõ�����˵���඼�ȱ��С����˵��Ҳ඼�ȱ�˴�
	while(i<j)
	{
		while(i<j && a[j]>=key)//��right��ʼ�ұȱ��С��Ϊֹ
			j--;
		a[i]=a[j];//����С������ֵ��left��
		while(i<j && a[i]<=key)//��left��ʼ�ұȱ�˴��Ϊֹ
			i++;
		a[j]=a[i];//���ϴ������ֵ��right��
	}
	a[i]=key;//�����ֵ����������
	//һ��ѭ�����

	//���������Ҳ�ĵݹ�
	quick_sort(a,left,i-1);
	quick_sort(a,i+1,right);
}
//���ÿ�������
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
	printf("ԭ����Ϊ��") ;
	show(arr,10);
	printf("����������Ϊ��") ;
	quick_sort(arr,10);
	show(arr,10);
}
