#include<stdio.h>
int a[10]={1,2,3,4,5,6,7,8,9,10};    //����������飻
int Find(int left,int right,int number)  //left��ʾ���  right��ʾ�յ㣻
{
	while(left<right)
	{	
		int mid=(left+right)/2;     //�����м�ֵ�����м�ֵ��number�Ƚϣ�
		if(a[mid]==number)       //���ڵĻ���˵���ҵ������Ԫ�أ�
			return mid;
		else if(a[mid]>number)     //Ҫ�ҵ�ֵ��mid����ߣ�
			return Find(left,mid-1,number);   //���¶������䳤�ȣ�����Find������
		else                            //Ҫ�ҵ�ֵ��mid���ұߣ�
			return Find(mid+1,right,number);   //���¶������䳤�ȣ�����Find������
	}
}
int main()
{
	int number;
	printf("������Ҫ���ҵ���: ");
	scanf("%d",&number);
	int pos=Find(0,9,number);
	printf("ԭ���ݱ�:  ");
	for(int i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	if(pos>=0)
		printf("���ҳɹ�!Ҫ���ҵ���λ�������±�Ϊ%d\n",pos);    
	else
		printf("����ʧ��!!!\n");
}

