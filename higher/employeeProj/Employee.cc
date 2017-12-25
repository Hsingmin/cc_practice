//Employee.cpp

#include<iostream>
using namespace std;

Employee::Employee()
{
mFirstName="";
mLastName="";
mEmployeeNumber=-1;
mSalary=kDefaultStartingSalary;
fHired=false;
}

void Employee::promote(int inRaiseAmount)
{
  setSalary(getSalary()+inRaiseAmount);
}

void Employee::demote(int inDemeritAmount)
{
  setSalary(getSalary()-inDemeritAmount);
}

void Employee::hire()
{
  fHired=true;
}

void Employee::fire()
{
  fHired=false;
}

void Employee::display()
{
  cout<<"Employee: "<<getLastName()<<", "<<getFirstName()<<endl;
  cout<<"------------------------------------"<<endl;
  cout<<(fHired? "Current Employee": "Former Employee")<<endl;
  cout<<"Employee number: "<<getEmployeeNumber()<<endl;
  cout<<"Salary: $"<<getSalary()<<endl;
  cout<<endl;
}

void Employee::setFirstName(string inFirstName)
{
  mFirstName=inFirstName;
}

string Employee::getFirstName()
{
  return mFirstName;
}

void Employee::setLastName(string inLastName)
{
  mLastName=inLastName;
}

string Employee::getLastName()
{
  return mLastName;
}

void Employee::setEmployeeNumber(int inEmployeeNumber)
{
  mEmployeeNumber=inEmployeeNumber;
} 

int Employee::getEmployeeNumber()
{
  return mEmployeeNumber;
}

void Employee::setSalary(int inSalary)
{
  mSalary=inSalary;
}

int Employee::getSalary()
{
  return mSalary;
}

bool Employee::getIsHired()
{
  return fHired;
}
