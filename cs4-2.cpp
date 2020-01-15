#include "stdio.h"
#define C  10  //背包容量数 
#define N  5  //物品总数
void Knapsack(int *w, int *v, int n, int c, int (*m)[C+1])  
{  
    //先处理记录表格中的最后一行，也即完成对m[n][j]的“填空” 
	int j,i; 
    int lowc = w[n]-1 > c ? c : w[n]-1; //判断 只有一个物品时，背包容量和 这个物品的重量的相对大小
	//可以避免在数组赋值中防止越界 
    for (j = 0; j <= lowc; j++)  
        m[n][j] = 0;  
    for (j = lowc+1; j <= c; j++)  /*lowc+1等价于w[n]*/
        m[n][j] = v[n];  
    //循环处理记录表格中的其他行，也即完成对m[i][j]的“填空”  
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
    //处理记录表格中的第一行，也即完成对m[1][c]的“填空”  
    m[1][c] = m[2][c]; //背包容量c不足,物品1舍去  
    if(c >= w[1] && m[2][c-w[1]] + v[1] > m[2][c]) //背包容量c足够,并且选取物品1的情况价值较大  
        m[1][c] = m[2][c-w[1]] +v[1];  
}  
 
 
/*
该函数用来确定最终装入背包的商品是哪些 
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
    int w[N+1] ={-1,2,2,6,5,4};  //各物品的质量 
    int v[N+1] ={-1,6,3,5,4,6};  //各物品的价值 
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

