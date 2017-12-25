//超类方法不同的访问级别
class Gregarious
{
  public:
         virtual void talk() {cout<<"Gregarious say hello ! "<<endl;}      
} ;

class Shy : public Gregarious
{
  protected:
            virtual void talk() {cout<<"Shy reluctantly say hello ! "<<endl;}
};

Shy myShy;
myShy.talk();//Bug，直接访问protected

//正确的访问方法

Shy myShy;
Gregarious& ref=myShy;//一个Gregarious引用 
ref.talk(); 
