#include<fstream>
#include<iostream>
#include<stdexcept>
using namespace std;

void funcOne() throw(exception);
void funcTwo() throw(exception);

int main(int argc,char** argv)
{
  try {
       funcOne();
  } catch(exception& e) {
     cerr<<"Exception caught!\n";
     exit(1);
  }

  return (0);
}

void funcOne() throw(exception)
{
  string str1;
  string* str2=new string();
  try {
       funcTwo();
  } catch (...) {
     delete str2;
     throw ;//Rethrow the exception.
  }
  delete str2;
}

void funcTwo() throw(excepion)
{
  ifstream istr;
  istr.open("filename");
  throw exception();
  istr.close();
}
