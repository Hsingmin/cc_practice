#include<conio.h>
#include<stdlib.h>
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

float Swap(float *p1,float *p2)
{
  float temp;
  temp=*p1;
  *p1=*p2;
  *p2=temp;
}

float Sort3(float *x,float *y,float *z)
{
  if(*x>*y) Swap(x,y);
  else ;
  if(*y>*z) Swap(y,z);
  else ;
  if(*x>*y) Swap(x,y);
  else ;
}

int main()
{
  float a,b,c;
  float *x,*y,*z;
  cout<<"Enter tree values: "<<endl;
  cin>>a>>b>>c;
  x=&a;
  y=&b;
  z=&c;
  Sort3(x,y,z);
  cout<<a<<" "<<b<<" "<<c<<endl;
  getch();
}
