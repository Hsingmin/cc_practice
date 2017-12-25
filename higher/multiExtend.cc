//BirDog.h
class dog
{
  public:
    virtual void bark()
    {
      cout<<"Woof! "<<endl;        
    }      
} ;
class bird
{
  public:
         virtual void chirp()
         {
           cout<<"Chirp! "<<endl;        
         }       
};

class birdog: public bird,public dog
{
};

int main(int argc,char** argv)
{
  birdog confusedAnimal;
  confusedAnimal.bark();
  confusedAnimal.chirp();    
} 
