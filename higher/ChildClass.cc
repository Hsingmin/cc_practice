//ȡ���Ա�ͷ�����ָ��
SpreadsheetCell myCell;
double (SpreadsheetCell::*methodPtr) () const=&SpreadsheetCell::getValue;
cout<<(myCell.*methodPtr)()<<endl;

//�򻯵ڶ���
SpreadsheetCell myCell;
double (SpreadsheetCell::*PtrToGet) () const;
PtrToGet methodPtr=&SpreadsheetCell::getValue;
cout<<(myCell.*methodPtr)()<<endl;

//������

class Super
{
  public:
         Super();
         virtual void SomeMethod();//���Ա����า�� 
         
  protected:
            int protectInt;
  private:
          int privateInt;      
} ;
//������
class Sub : public Super
{
        public:
               Sub();
               void SomeOtherMethod();
} ;

//���ڿͻ����룬��������඼�ǿɵ��õ�
Sub mySub;
mySub.SomeMethod();
mySub.SomeOtherMethod(); 
