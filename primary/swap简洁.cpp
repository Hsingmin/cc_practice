#include<iostream>
using namespace std;

void Swap(float& a,float& b)
{
  float temp;
  temp=a;
  a=b;
  b=temp;
}

int main()
{
  float x,y;
  cout<<"Enter two numbers: "<<endl;
  cin>>x>>y;
  Swap(x,y);
  cout<<x<<" "<<y<<endl;
}
