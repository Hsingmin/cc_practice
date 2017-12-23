#include<conio.h>
#include<iostream>
using namespace std;

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

int main()
{
  float m,n,g;
  cout<<"Enter tree numbers: "<<endl;
  cin>>m>>n>>g;
  Sort3(m,n,g);
  cout<<m<<" "<<n<<" "<<g<<endl;
  getch();
}
