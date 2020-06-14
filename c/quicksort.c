#include<stdio.h>

void quick_sort_c(int a[],int p,int r);
int partition(int a[],int p,int r);

// a接收数组地址，n是数组长度
void quick_sort(int a[],int n){
  quick_sort_c(a,0,n-1);
}

// 递归函数，p为左下标，r为右下标
void quick_sort_c(int a[],int p,int r){
  if (p >= r)
  {
    return ;
  }
  // 获取分区点，即进行比较的数字下标，选数组最后一个相对方便
  int q = partition(a,p,r);
  quick_sort_c(a,p,q-1);
  quick_sort_c(a,q+1,r);
}

int partition(int a[],int p,int r){
  // int pivot = a[r];
  int i = p;
  int temp;
  for(int j = p;j < r;j++){
    if (a[j] < a[r])
    {
      temp = a[i];
      a[i] = a[j];
      a[j] = temp;
      i++;
    }
  }
  temp = a[i];
  a[i] = a[r];
  a[r] = temp;
  return i;
}

int main()
{
  int a[] = {2,5,1,9,6,4,7};
  quick_sort(a,7);
  for(int i = 0;i < 7;i++){
    printf("%d\t",a[i]);
  }
}