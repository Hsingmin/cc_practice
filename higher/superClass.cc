//���෽����ͬ�ķ��ʼ���
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
myShy.talk();//Bug��ֱ�ӷ���protected

//��ȷ�ķ��ʷ���

Shy myShy;
Gregarious& ref=myShy;//һ��Gregarious���� 
ref.talk(); 
