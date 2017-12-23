#include"finance.h"
#include"finance.cpp"
#include<iostream>
using namespace std;

const float MONTHS=12.0;

int main()
{
  float rate,principal,num_payments,accum;
  float yearly_rate,balance,payment,month=1.0;
  cout<<"Enter loan principal,rate,and number of payments: "<<endl;
  cin>>principal>>yearly_rate>>num_payments;
  
  rate=yearly_rate;
  payment=Payment(principal,rate,num_payments);
  cout<<"payment: "<<payment<<endl;
  cout<<"Amortization of "<<principal<<" over "<<num_payments<<" at rate of "<<rate<<endl;
  cout<<" Month   Banlance   Accumulated   Interest "<<endl;
  cout<<" ------------------------------------------"<<endl;

  while(month<num_payments)
  {
    Amortize(accum,balance,rate,payment,principal,month);
    cout<<month<<"  "<<balance<<"  "<<accum<<endl;
    month=month+1;
  }
 
}
