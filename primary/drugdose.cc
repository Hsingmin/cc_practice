#include"drugcalc.h"
#include"drugcalc.cpp"
#include<iostream>
using namespace std;

const int NUMPATS=100;

int main()
{
  int count=0;
  float recommend;
  int actual;
  char sex;
  int age;
  float weight;
  
  cout<<"Patient Drug Dose Report"<<endl;
  cout<<"Sex      Age      Weight     Dose      Pill"<<endl;

  while(count<NUMPATS)
{
  ReadPatient(sex,age,weight);
  recommend=RecomDose(sex,weight);
  actual=ActualDose(recommend);
  cout<<sex<<" "<<age<<" "<<weight<<" "<<recommend<<" "<<actual<<endl;
  count=count+1;
}
 
}
