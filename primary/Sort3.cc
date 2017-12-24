#include"Sort3.h"

void Swap(float& a,float& b)
{
  float temp;
  temp=a;
  a=b;
  b=temp;
}

void Sort3(float& x,float& y,float& z)
{
  if(x>y) Swap(x,y);
  else ;
  if(y>z) Swap(y,z);
  else ;
  if(x>y) Swap(x,y);
  else ;
}
