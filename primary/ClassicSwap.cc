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

int main()
{
  
  float *pointer1,*pointer2;
  float m,n;
  cout<<"Enter two numbers: "<<endl;
  cin>>m>>n;
  pointer1=&m;
  pointer2=&n;
  
  Swap(pointer1,pointer2);
 
  cout<<m<<" "<<n<<endl;
  getch();
  
  
}
