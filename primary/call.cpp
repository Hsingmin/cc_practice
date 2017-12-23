#include<iostream>
using std::cin;
using std::cout;
using std::endl;

void Letterhead()
{
  cout<<"             World Wide Widgets           "<<endl;
  cout<<"              198 Easy Street             "<<endl;
  cout<<"               New York, NY               "<<endl;          
}

void Letter()
{
  cout<<"Dear Sir or Madam"<<endl;
  cout<<"Your account is passed due.We appreciate"<<endl;
  cout<<"prompt payment for service."<<endl;
}

void Closing()
{
  cout<<"Sincerely,"<<endl<<endl<<endl;
  cout<<"Monty B.Jones,Pres."<<endl;
}

int main()
{
  Letterhead();
  Letter();
  Closing();
}

