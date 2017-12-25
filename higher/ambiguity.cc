//菱形机制消除二义性
class Animal
{
  public:
         virtual void eat()=0;       
} 

class Dog : public Animal
{
  public:
         virtual void bark() {cout<<"Woof ! "<<endl;}
         virtual void eat()  {cout<<"The dog has eaten! "<<endl;}
};

class Bird : public Animal
{
  public:
         virtual void chirp() {cout<<"Chirp! "<<endl; }
         virtual void eat()   {cout<<"The bird has eaten! "<<endl;}   
};

class Birdog ：public Dog,public Bird
{
  public:
         virtual void eat() {Dog::eat();}      
} ;
