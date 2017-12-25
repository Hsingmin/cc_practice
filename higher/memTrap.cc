#include<iostream>
using namespace std;

class Simple
{
  public:
    Simple() {mIntPtr=new int();}
    ~Simple() {delete mIntPtr;}

    void setIntPtr(int inInt) {*mIntPtr=inInt;}
    void go() {cout<<"Hello there "<<endl;}

  protected:
    int* mInPtr;
};

void doSomething(Simple*& outSimplePtr)
{
  outSimplePtr=new Simple();//Bug,doesn't delete .
}

int main(int argc,char** argv)
{
  Simple* simplePtr=new Simple();
  doSomething(simplePtr);
  delete simplePtr;//Only cleans up the second object.
}
