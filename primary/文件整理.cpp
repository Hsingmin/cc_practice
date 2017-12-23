#include<math.h>
#include<iostream>
#include<fstream>
using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::ios;

const int PRECISION=4;
const int WIDTH1=10;
const int WIDTH2=15; 
 
int main()
{
  float value,root;
  ifstream infile("accnts.dat",ios::in);
  
  cout<<" value            square root "<<endl;
  
  cout.precision(PRECISION);
  while(infile>>value)
  {
    root=sqrt(value);
    cout.width(WIDTH1);
    cout<<value;
    cout.width(WIDTH2);
    cout<<root<<endl;

  }
}
