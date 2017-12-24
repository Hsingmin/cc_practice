#include<iostream>
#include<fstream>
#include<string>
using namespace std;

const string KEYFILE="key.txt";
const string STUDENTFILE="students.txt";
const int SIZE=5;
void InputAnswerKey(string,char[],int);
void GradeStudents(string,char[],int[],int);
void ReportSummary(int[],int);

int main()
{
  char answers[SIZE];
  int summary[SIZE]={0,0,0,0,0};
  InputAnswerKey(KEYFILE,answers,SIZE);
  GradeStudents(STUDENTFILE,answers,summary,SIZE);
  ReportSummary(summary,SIZE);

}

void InputAnswerKey(string key,char ans[],int size)
{
  ifstream infile(keyfile,ios::in);
  for(int n=0;n<size;n++)
    infile>>ans[n];
}

void GradeStudents(string studfile,char answers[],int summary[],int size)
{
  ifstream studentfile_in(studfile,ios::in);
  int id,score,ans;
  char thisanswer;
  while(studentfile_in>>id)
  {
    score=0;
    for(ans=0;ans<size;ans++)
    {
      studentfile_in>>thisanswer;
      if(thisanswer==answers[ans])
      {
        score++;
        summary[ans]++;
      }
    }
    cout<<"student: "<<id<<" score: "<<score<<endl;
  }
}

void ReportSummary(int summary[],int size)
{
  cout<<"correct answers summary for each question: "<<endl;
  for(int n=0;n<size;n++)
    cout<<summary[n]<<" ";
}
