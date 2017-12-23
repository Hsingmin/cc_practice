#include<iostream>
using std::cin;
using std::cout;
using std::endl;

float GetPosAmount()
{
  float temp;
  cout<<"Enter a positive value:";
  cin>>temp;
  while(temp<0.0)
  {
    cout<<"**Negative value,enter a positive value:"<<endl;
    cin>>temp;
  }
  return (temp);
}

main()
{
  GetPosAmount();
}
