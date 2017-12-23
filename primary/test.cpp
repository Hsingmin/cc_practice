#include"string.h"
#include"conio.h"
#include"stdio.h"

struct person
{
  char name[20];
  int count;       
}leader[3]={"wang",0,"li",0,"liu",0};

main()
{
  char leader_name[20];
  int i,j;
  for(i=1;i<=100;i++)
  {
    scanf("%s",leader_name);
    for(j=1;j<=3;j++)
    {
      if(strcmp(leader_name,leader[j].name)==0)
      leader[j].count++;                 
    }    
    printf("\n");
    for(i=1;i<=3;i++)
    {
      printf("\n%15s%5d",leader[i].name,leader[i].count);                 
    }               
  }  
  getch();    
}
