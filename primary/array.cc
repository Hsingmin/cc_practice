
#include<iostream>
#include<fstream>
using namespace std;

// global constant
const int SIZE=5;

int main()
{
  // file in stream
  ifstream keyfile_in("key.txt",ios::in);
  ifstream studentfile_in("students.txt",ios::in);
  char answer[SIZE],thisanswer;
  // summary[SIZE] initialize
  int ans,summary[SIZE]={0,0,0,0,0},id,n,score;

  // get in keyfile
  for(n=0;n<SIZE;n++)
    keyfile_in>>answer[n];
  
  // get in studentfile ids
  while(studentfile_in>>id)
  {
    score=0;
    for(ans=0;ans<SIZE;ans++)
    {
      studentfile_in>>thisanswer;
      if(thisanswer==answer[ans])
      {
        score++;
        summary[ans]++;
      }
    }
    cout<<"student: "<<id<<" score :"<<score<<endl;
  }

  cout<<"  correct answer sumary for each questions: "<<endl;
  for(n=0;n<SIZE;n++)
    cout<<summary[n]<<" ";
  cout<<endl;
}
