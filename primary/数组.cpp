
#include<iostream>
#include<fstream>
using namespace std;

const int SIZE=5;

int main()
{
  ifstream keyfile_in("key.txt",ios::in);
  ifstream studentfile_in("students.txt",ios::in);
  char answer[SIZE],thisanswer;
  int ans,summary[SIZE]={0,0,0,0,0},id,n,score;

  for(n=0;n<SIZE;n++)
    keyfile_in>>answer[n];

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
}
