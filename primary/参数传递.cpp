#include<iostream>
using std::cin;
using std::cout;
using std::endl;

float Factorial(float n)
{
  float product=1.0;
  while(n>1.0)
  {
    product=product*n;
    n=n-1;
  }
  return (product);
}

float Combi(float group,float commitee)
{
  float combinations;
  combinations=Factorial(group)/(Factorial(group-commitee)*Factorial(commitee));
  return (combinations); 
}

int main()
{
  float group_size,commitee_size,combinations;
  char done='Y';
  while(done=='Y')
  {
    cout<<"Enter the size of the group and commitee: "<<endl;
    cin>>group_size>>commitee_size;
    if(group_size>commitee_size)
    {
      combinations=Combi(group_size,commitee_size);
      cout<<"For "<<group_size<<" people and "<<commitee_size<<"sized commitees,the ";
      cout<<"number of commitees is "<<
           combinations<<endl;
    }
    else
      cout<<"**Illegal values;Group must be larger"<<endl;
    cout<<"Do you need another calculation?";
    cout<<"Enter Y for yes,N for no:";
    cin>>done;
  }
}

