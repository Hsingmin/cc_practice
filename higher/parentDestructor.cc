#include<iostream>
using namespace std;

class Something
{
  public:
    Something()
    {
      cout<<"2"<<endl;
    }
    virtual ~Something() {cout<<"2"<<endl;}
};

class Parent
{
  public:
    Parent()
    {
      cout<<"1"<<endl;
    }
    virtual ~Parent() {cout<<"1"<<endl;}
};

class Child : public Parent
{
  public:
    Child()
    {
      cout<<"3"<<endl;
    }
    virtual ~Child() {cout<<"3"<<endl;}
 
  protected:
    Something mDataMember;
};

int main(int argc,char** argv)
{
  Child myChild;
}

//调用父类中的方法
Sub::doSomthing()
{
  cout<<"Dosomething in Sub's version. "<<endl;
  Super::Dosomething();                 
} 
