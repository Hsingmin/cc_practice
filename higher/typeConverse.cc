//要使用dynamic_cast，要求类中必须有一个虚函数virtual。 

#include<typeinfo>
#include<iostream>
using namespace std;

class Base
{
  public:
    Base() {};
    virtual ~Base() {};
};

class Derived : public Base
{
  public:
    Derived() {};
    virtual ~Derived() {};
};

int main(int argc,char** argv)
{
  Base* b;
  Derived* d=new Derived();
  
  b=d;
  d=dynamic_cast<Derived*>(b);

  Base base;
  Derived derived;

  Base& br=base;
  
  try {
      Derived& dr=dynamic_cast<Derived&>(br);
} catch (bad_cast&) {
    cout<<"Bad cast!\n";
}
return (0);
}
