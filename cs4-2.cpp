#include "stdio.h"
#define C  10  //���������� 
#define N  5  //��Ʒ����
void Knapsack(int *w, int *v, int n, int c, int (*m)[C+1])  
{  
    //�ȴ����¼����е����һ�У�Ҳ����ɶ�m[n][j]�ġ���ա� 
	int j,i; 
    int lowc = w[n]-1 > c ? c : w[n]-1; //�ж� ֻ��һ����Ʒʱ������������ �����Ʒ����������Դ�С
	//���Ա��������鸳ֵ�з�ֹԽ�� 
    for (j = 0; j <= lowc; j++)  
        m[n][j] = 0;  
    for (j = lowc+1; j <= c; j++)  /*lowc+1�ȼ���w[n]*/
        m[n][j] = v[n];  
    //ѭ�������¼����е������У�Ҳ����ɶ�m[i][j]�ġ���ա�  
    for ( i = n-1; i > 1; i--)  
    {  
        lowc = w[i]-1 > c ? c : w[i]-1;  
        for ( j = 0; j <=lowc; j++)  
            m[i][j] = m[i+1][j];  
        for ( j = w[i]; j <= c; j++)  
        {  
            int t1 = m[i+1][j];  
            int t2 = m[i+1][j - w[i]] + v[i];  
            m[i][j] = t1 > t2 ? t1 : t2;  
        }  
    }  
    //�����¼����еĵ�һ�У�Ҳ����ɶ�m[1][c]�ġ���ա�  
    m[1][c] = m[2][c]; //��������c����,��Ʒ1��ȥ  
    if(c >= w[1] && m[2][c-w[1]] + v[1] > m[2][c]) //��������c�㹻,����ѡȡ��Ʒ1�������ֵ�ϴ�  
        m[1][c] = m[2][c-w[1]] +v[1];  
}  
 
 
/*
�ú�������ȷ������װ�뱳������Ʒ����Щ 
*/  
void Traceback(int (*m)[C+1],int *w, int *x,int n, int c)  
{  
	int i;
    for (i = 1; i < n; i++)  
    {  
        if(m[i][c] == m[i+1][c])  
            x[i] = 0;  
        else  
        {  
            x[i] = 1;  
            c -= w[i];  
        }  
    }  
    x[n] = (m[n][c])?1:0;
}  
  
int main(void)  
{  
	int i ;
    int x[N+1];  
    int w[N+1] ={-1,2,2,6,5,4};  //����Ʒ������ 
    int v[N+1] ={-1,6,3,5,4,6};  //����Ʒ�ļ�ֵ 
    int m[N+1][C+1];  
    Knapsack(w,v,N,C,m); 
	printf("%d\n",m[1][C]); 
    Traceback(m, w, x, N, C);  
    for (i= 1; i <= N; i++)  
    {  
       printf("%d ",x[i]);
    }  
    printf("\n");
    return 0;  
}  

