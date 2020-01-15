#include <stdio.h>
void merge(int *a, int b, int m, int e)

{       
        int l = m-b+1, r = e-m, i;
        int L[l+1], R[r+1];
        for(i=0; i< l; i++)
        {
            L[i] = a[b+i];
        }
        for (i=0; i< r; i++)
        {
            R[i] =a[m+i+1];
        }
        L[l] = 32767;
        R[r] = 32767;
        l = 0;
        r = 0;
        for(i=0; i< e-b+1; i++)
       {
            if(L[l] < R[r])
            {
                a[b+i] = L[l];
                l ++;
            }
            else            {
               a[b+i] = R[r];
                r ++;
            }
        }
}
void merge_sort(int *a, int b, int e)
{
        if(b < e)
        {
            int m = (b + e) / 2;
            merge_sort(a, b, m);
            merge_sort(a, m+1, e);
            merge(a, b, m, e);
        }
}
int main()
{
        int a[500];
        int len, i;
        printf("请输入数组长度:");
        scanf("%d", &len);
        printf("请输入数组元素:");
        for(i=0; i< len; i++)
           scanf("%d", &a[i]);
        merge_sort(a, 0, len-1); 
        printf("归并排序后的结果为:\n");
        for(i=0; i< len; i++)
        {
           printf("%d ", a[i]);
        }
}
