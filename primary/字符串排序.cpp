#include<iostream>
#include<fstream>
#include<string>
using namespace std;

const int SIZE=10;

void Swap(string& word1,string& word2)
{
  string temp;
  temp=word1;
  word1=word2;
  word2=temp;
}

void Sort(string words[],int size)
{
  int n,k,small_pos;
  string smallest;
  for(k=0;k<SIZE-1;k++)
  {
    smallest=words[k];
    for(n=k;n<size;n++)
      if(words[n]<=smallest)
      {
        small_pos=n;
        smallest=words[n];
      }
      Swap(words[k],words[small_pos]);
  }
}

int main()
{
  string words[SIZE];
  int n;
  cout<<"Enter "<<SIZE<<" words: "<<endl;
  for(n=0;n<SIZE;n++)
    cin>>words[n];
  Sort(words,SIZE);
  cout<<"Sorted words are: "<<endl;
  for(n=0;n<SIZE;n++)
    cout<<words[n]<<endl;
}

