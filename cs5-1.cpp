#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int LCSLength(char* str1, char* str2, int **b)
{
	int i,j,length1,length2,len;
	length1 = strlen(str1);
	length2 = strlen(str2);
 
	//˫ָ��ķ������붯̬��ά����
	int **c = new int*[length1+1]; //����length1+1��
	for(i = 0; i < length1+1; i++)
		c[i] = new int[length2+1];//����length2+1��
 
	for(i = 0; i < length1+1; i++)
		c[i][0]=0;        //��0�ж���ʼ��Ϊ0
	for(j = 0; j < length2+1; j++)
		c[0][j]=0;        //��0�ж���ʼ��Ϊ0
 
	for(i = 1; i < length1+1; i++)
	{
		for(j = 1; j < length2+1; j++)
		{
			if(str1[i-1]==str2[j-1])//����c[][]��0��0��û��ʹ�ã�c[][]�ĵ�i��Ԫ�ض�Ӧstr1�ĵ�i-1��Ԫ��
			{
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]=0;          //��������Ӵ�ʱ����������
			}
			else if(c[i-1][j]>c[i][j-1])
			{
				c[i][j]=c[i-1][j];
				b[i][j]=1;
			}
			else
			{
				c[i][j]=c[i][j-1];
				b[i][j]=-1;
			}
		}
	}
	len=c[length1][length2];
	for(i = 0; i < length1+1; i++)    //�ͷŶ�̬����Ķ�ά����
		delete[] c[i];
	delete[] c;
	return len;
}
void PrintLCS(int **b, char *str1, int i, int j)
{
	if(i==0 || j==0)
		return ;
	if(b[i][j]==0)
	{
		PrintLCS(b, str1, i-1, j-1);//�Ӻ��濪ʼ�ݹ飬����Ҫ�ȵݹ鵽�Ӵ���ǰ�棬Ȼ���ǰ����ʼ����Ӵ�
		printf("%c",str1[i-1]);//c[][]�ĵ�i��Ԫ�ض�Ӧstr1�ĵ�i-1��Ԫ��
	}
	else if(b[i][j]==1)
		PrintLCS(b, str1, i-1, j);
	else
		PrintLCS(b, str1, i, j-1);
}
 
int main(void)
{
	char str1[100],str2[100];
	int i,length1,length2,len;
	printf("�������һ���ַ�����");
	gets(str1);
	printf("������ڶ����ַ�����");
	gets(str2);
	length1 = strlen(str1);
	length2 = strlen(str2);
	//˫ָ��ķ������붯̬��ά����
	int **b = new int*[length1+1];
	for(i= 0; i < length1+1; i++)
		b[i] = new int[length2+1];
	len=LCSLength(str1,str2,b);
	printf("����������еĳ���Ϊ��%d\n",len);
	printf("�����������Ϊ��");
	PrintLCS(b,str1,length1,length2);
	printf("\n");
	for(i = 0; i < length1+1; i++)//�ͷŶ�̬����Ķ�ά����
		delete[] b[i];
	delete[] b;
	system("pause");
	return 0;
}

