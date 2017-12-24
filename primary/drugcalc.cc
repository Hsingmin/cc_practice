#include<iostream>
using std::cin;
using std::cout;
using std::endl;

const char WEIGHT='W';
const char AGE='A';
const char MALE='M';
const char FEMALE='F';

void ReadItem(char& sex,int& age,float& weight)
{
  char prefix;
  cin>>prefix;
  if(prefix==WEIGHT)
    cin>>weight;
  if(prefix==AGE)
    cin>>age;
  if(prefix==MALE)
    sex=prefix;
  if(prefix==FEMALE)
    sex=prefix;
  else 
    cout<<" **Illegal data item in patient input** "<<endl;
}

void ReadPatient(char& sex,int& age,float& weight)
{
  ReadItem(sex,age,weight);
  ReadItem(sex,age,weight);
  ReadItem(sex,age,weight);
}

const float F_INC=0.3;
const float M_INC=0.5;
const int F_DOSE=8;
const int M_DOSE=10;

float RecomDose(char sex,float wt)
{
  int size;
  float dose;
 
  if(sex='M')
  {
    size=wt/M_DOSE;
    dose=size*M_INC;
  }
  else
  {
    size=wt/F_DOSE;
    dose=size*F_INC;
  }
  return (dose);
}

int IsEven(int x)
{
  if((x/2)*2==x)
    return (1);
  else
    return (0);
}

int ActualDose(float recommend)
{
  int intdose;
  intdose=recommend;
  if(IsEven(intdose))
    return (intdose);
  else
    return (intdose);
}
