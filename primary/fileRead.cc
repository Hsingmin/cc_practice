#include<iostream>
#include<fstream>
using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::ios;

int main()
{
  int acntnum;
  float balance;
  int n;
  float sum=0.0;
  ifstream infile("accnts.dat",ios::in);


  for(n=0;n<3;n++)
  {
    infile>>acntnum>>balance;
    sum+=balance;
  }
  cout<<"The total of all accounts is: "<<sum<<endl;
}
