#include <stdio.h>
#include<windows.h>
int main(void)
{
 int n, min, i, a[100] ;
 printf("Ҫ�󼸸�������С����������\n") ;
 scanf("%d", &n) ;
 printf("����%d���������س�����", n) ;
 for(i=0; i<n; i++)
  scanf("%d", &a[i]) ;
 min = a[0] ;
 for(i=0; i<n; i++)
  if(a[i]<min)
   min = a[i] ;
 printf("��С��ֵΪ%d,�ǵ�%d����\n", min,i+1) ; 
 system("pause") ;
 return 0 ;
} 
