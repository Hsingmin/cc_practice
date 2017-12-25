//取类成员和方法的指针
SpreadsheetCell myCell;
double (SpreadsheetCell::*methodPtr) () const=&SpreadsheetCell::getValue;
cout<<(myCell.*methodPtr)()<<endl;

//简化第二行
SpreadsheetCell myCell;
double (SpreadsheetCell::*PtrToGet) () const;
PtrToGet methodPtr=&SpreadsheetCell::getValue;
cout<<(myCell.*methodPtr)()<<endl;

//派生类

class Super
{
  public:
         Super();
         virtual void SomeMethod();//可以被子类覆盖 
         
  protected:
            int protectInt;
  private:
          int privateInt;      
} ;
//派生类
class Sub : public Super
{
        public:
               Sub();
               void SomeOtherMethod();
} ;

//对于客户代码，父类和子类都是可调用的
Sub mySub;
mySub.SomeMethod();
mySub.SomeOtherMethod(); 
