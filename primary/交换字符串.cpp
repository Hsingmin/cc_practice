#include<iostream>
#include<string>
using namespace std;

void Swap(string& word1,string& word2)
{
  string temp;
  temp=word1;
  word1=word2;
  word2=temp;
}

int main()
{
  string buf1,buf2;
  cout<<"Please Enter two Words: "<<endl;
  cin>>buf1>>buf2;
  Swap(buf1,buf2);
  cout<<buf1<<" "<<buf2<<endl;
}
