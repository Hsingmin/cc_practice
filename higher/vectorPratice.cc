
//Ĭ�Ϲ��캯������һ������0��Ԫ�ص�vector
#include<vector>
using namespace std;

int main(int argc,char** argv)
{
   vector<int> intVector;
   return (0); 
} 

//���������������
#include<vector>
#include<string>
using namespace std;

int main(int argc,char** argv)
{
  vector<string> stringVector(10,"hello");
  return (0);    
} 

//ʹ�ö��������
#include<vector>
using namespace std;

class Element
{
  public:
         Element() {}
         ~Element() {}     
} ;
int main(int argc,char** argv)
{
  vector<Element> elementVector;
  return (0);    
}
