#include<stdio.h>

void countingSort(int a[],int n)
{
  int max = a[0];
  // 找到数组中最大的元素
  for(int i = 1; i < n; i++){
    if (a[i] > max)
    {
      max = a[i];
    }
  }
  // c数组用来计数
  int c[max+1];
  for(int i = 0; i <= max; i++){
    c[i] = 0;
  }
  // 遍历数组进行计数
  for(int i = 0; i < n; i++){
    c[a[i]]++;
  }
  // 对数组c顺序求和
  for(int i = 1; i <= max; i++){
    c[i] += c[i-1];
  }
  // 暂时存放数据的数组
  int temp[n];
  // 从后往前遍历数据数组
  for(int i = n-1; i >= 0; i--){
    //需要-1是因为数组的下标从0开始
    int index = c[a[i]] - 1;
    temp[index] = a[i];
    c[a[i]]--;
  }
  //将排序的temp数组复制回a数组
  for(int i = 0; i < n; i++){
    a[i] = temp[i];
  }
}

int main()
{
  int a[] = {4,2,5,3,0,8,10,7,2,3,0,3};
  int length = 12;
  countingSort(a,length);
  for(int i = 0; i < length; i++){
    printf("%d\t",a[i]);
  }
}