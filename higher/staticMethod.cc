//Static方法

class SuperStatic
{
  public:
         static void beStatic() {cout<<"SuperStatic being static,yo! "<<endl;}
        
} ;

class SubStatic
{
  public:
         static void beStatic() {cout<<"SubStatic keepin' it static! "<<endl;}      
};

//Call the Static
SuperStatic.beStatic();
SubStatic.beStatic();

//重载超类
class Foo
{
  public:
         virtual void overload() {cout<<"Foo's overload(). "<<endl;}
         virtual void overload(int i) {cout<<"Foo's overload(int i). "<<endl;}      
} ;
class Bar : public Foo 
{
  public:
         virtual void overload() {cout<<"Bar's overload(). "<<endl;}      
};
//从Bar访问overload（int）
Bar myBar;
Foo* ptr=&myBar;

ptr->overload(7); 

