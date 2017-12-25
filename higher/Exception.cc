#include<fstream>
#include<iostream>
#include<vector>
#include<string>
#include<exception>
using namespace std;

void readIntegerFile(const string& filename,vector<int>& dest)
{
  ifstream istr;
  int temp;

  istr.open(filename.c_str());
  if(istr.fail())
  {
    throw exception();//抛出的异常信息 
  }

  //Read the integers one by one and add them to the vector.
  while(istr>>temp)
  {
    dest.push_back(temp);
  }
}

int main(int argc,char** argv)
{
  vector<int> myInts;
  const string filename="IntegerFile.txt";
  
  //try{} catch{}的运行机制类似于if ，catch语句对try块中抛出的所有exception类型的异常做出反应， 
  //并且打印错误信息，退出。 
  // 如果没有异常则会跳过，继续执行。 
  try {
       readIntegerFile(filename,myInts);
  } catch (const exception& e) {
      cerr<<"Unable to open file. "<<filename<<endl;
      exit(1);
  }
  for(size_t i=0;i<myInts.size();i++)
    cout<<myInts[i]<<" ";

  cout<<endl;
  return (0);

}
