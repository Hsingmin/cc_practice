#include<iostream>
#include<fstream>
using std::cin;
using std::cout;
using std::endl;
using std::ofstream;

int main()
{
  char done='y';
  int acntnum;
  float balance;
  ofstream outfile;

  outfile.open("accnts.dat");
  
  while(done !='n')
  {
    cout<<"Enter an account number and balance: ";
    cin>>acntnum>>balance;
    outfile<<acntnum<<" "<<balance<<endl;
    cout<<"Another account? Enter 'y' or 'n':"<<endl;
    cin>>done;
  }
}
