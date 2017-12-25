
//Á÷Á´½Ó 
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(int argc,char** argv)
{
  ifstream inFile("input.txt");
  ofstream outFile("output.txt");

  //Set up a link between inFile and outFile.
  inFile.tie(&outFile);

  //Output some text to outFile. Normally,this would not 
  //flush because std::endl was not sent.
  outFile<<"Hello there!"<<endl;

  //outFile has not been flushed.
  //Read some text from inFile. This will trigger flush()
  //on outFile.
  string nextToken;
  cout<<"NextToken: "<<endl;
  cin>>nextToken;
  inFile>>nextToken;
  //outFile has been flushed.
}
