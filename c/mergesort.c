#include<stdio.h>
void merge_sort_c(int a[],int p,int r);
void finish_merge(int a[],int p,int q,int r);

void merge_sort(int a[],int n){
  merge_sort_c(a,0,n-1);
}
// 递归调用函数
void merge_sort_c(int a[],int p,int r){
  // 递归终止条件
  if (p >= r)
  {
    return ;
  }
  int q = (p + r) / 2;   
  
  merge_sort_c(a,p,q);
  merge_sort_c(a,q+1,r);
  finish_merge(a,p,q,r);
}
//合并成有序数组
void finish_merge(int a[],int p,int q,int r){
  int i = p;
  int j = q + 1;
  int k = 0;
  int length = r-p+1;
  int temp[length];
  for(int n = 0;n < length;n++){
    temp[n] = a[i];
  }

  while (i <= q && j <= r)
  { 
    if (a[i] <= a[j])
    { 
      temp[k++] = a[i++];
    }else
    { 
      temp[k++] = a[j++];
    }
  }
  int start = i,end = q;
  if (r >= j)
  {
    start = j;
    end = r;
  }
  
  while (start <= end)
  {
    temp[k++] = a[start++];
  }
  for (int m = 0; m <= r-p; m++)
  {
    a[p+m] = temp[m];
  }

}
int main()
{
  int a[] = {8,3,12,6,9,16,7,5,2,3,4,1};
  int a_length = 12;

  merge_sort(a,a_length);

  for (int i = 0; i < a_length;i++)
  {
    printf("%d\t",a[i]);
  }
}