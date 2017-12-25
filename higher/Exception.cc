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
    throw exception();//�׳����쳣��Ϣ 
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
  
  //try{} catch{}�����л���������if ��catch����try�����׳�������exception���͵��쳣������Ӧ�� 
  //���Ҵ�ӡ������Ϣ���˳��� 
  // ���û���쳣�������������ִ�С� 
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
