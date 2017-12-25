//flow.cpp
#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;

int main()
{
  int sum=0;
  if(!cin.good())
  {
    cout<<"Standard input is in a bad state!"<<endl;
    exit(1);
  }

  int number;
  while(true)
  {
    cin>>number;
    if(cin.good())
    {
      sum+=number;
    }
    else if(cin.eof())
    {
      break;  //Reach the end of the file.
    }
    else
    {
      //Error!
      cin.clear();//Clear the error state.
      string badToken;
      cin>>badToken;//Consume the bad input.
      cerr<<"Warning: Bad input encouraged: "<<badToken<<endl;
    }
  }
  
  cout<<"The sum is: "<<sum<<endl;
  return 0;
}
