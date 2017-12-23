#include <stdio.h>
#include<windows.h>
int main(void)
{
 int n, min, i, a[100] ;
 printf("要求几个数的最小数？请输入\n") ;
 scanf("%d", &n) ;
 printf("输入%d个数，按回车结束", n) ;
 for(i=0; i<n; i++)
  scanf("%d", &a[i]) ;
 min = a[0] ;
 for(i=0; i<n; i++)
  if(a[i]<min)
   min = a[i] ;
 printf("最小的值为%d,是第%d个数\n", min,i+1) ; 
 system("pause") ;
 return 0 ;
} 
