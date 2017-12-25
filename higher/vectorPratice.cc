
//默认构造函数创建一个含有0个元素的vector
#include<vector>
using namespace std;

int main(int argc,char** argv)
{
   vector<int> intVector;
   return (0); 
} 

//创建内置类的向量
#include<vector>
#include<string>
using namespace std;

int main(int argc,char** argv)
{
  vector<string> stringVector(10,"hello");
  return (0);    
} 

//使用对象的向量
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
