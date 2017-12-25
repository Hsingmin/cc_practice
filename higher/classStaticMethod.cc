
//访问类的静态方法，用类名加作用域操作符作为方法名的前缀 
class Demo
{
  public:
         static void method() {}      
};

int main(int argc,char** argv)
{
  Demo::method();
  
  return (0);    
}
