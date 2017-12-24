#include<string>
#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;

const string filename="dict.txt";

string InDictionary(string& infile,string dic_word)
{
  infile>>dic_word;
  return (dic_word);
}

int main()
{
  ifstream infile(filename,ios::in);
  string usr_word,fin_word;
 
  usr_word=InDictionary(infile,fin_word);
  cout<<usr_word<<endl;
  getch();

}
