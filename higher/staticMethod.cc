//Static����

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

//���س���
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
//��Bar����overload��int��
Bar myBar;
Foo* ptr=&myBar;

ptr->overload(7); 

