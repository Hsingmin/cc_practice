#include<iostream>
#include<stdexcept>

#include"Database.cpp"
#include"Employee.cpp"

using namespace std;

int displayMenu();
void doHire(Database& inDB);
void doFire(Database& inDB);
void doPromote(Database& inDB);
void doDemote(Database& inDB);

int displayMenu()
{
  int selection;
  cout<<endl;
  cout<<"Employee Database "<<endl;
  cout<<"------------------"<<endl;
  cout<<"1)Hire a new employee "<<endl;
  cout<<"2)Fire a new employee "<<endl;
  cout<<"3)Promote an employee "<<endl;
  cout<<"0)Quit "<<endl;
  cout<<endl;
  cout<<"----->";

  cin>>selection;
  return selection;
}

void doHire(Database& inDB)
{
  string firstName;
  string lastName;
 
  cout<<"First name? "<<endl;
  cin>>firstName;
  cout<<"Last name? "<<endl;
  cin>>lastName;

  try
  {
    inDB.addEmployee(firstName,lastName);
  }

  catch(std::exception ex)
  {
    cerr<<"Unable to add "<<endl;
  }
 
}

void doFire(Database& inDB)
{
  int employeeNumber;
  
  cout<<"Employee number?"<<endl;
  cin>>employeeNumber;
  
  try {
      Employee& emp=inDB.getEmployee(employeeNumber);
      emp.fire();
      cout<<"Employee "<<employeeNumber<<" has been terminated. "<<endl;
  }
  catch(std::exception ex) {
  cerr<<"Unable to terminate employee !"<<endl;
  }
}

void doPromote(Database& inDB)
{
  int employeeNumber;
  int raiseAmount;

  cout<<"Employee number? "<<endl;
  cin>>employeeNumber;
  
  cout<<"How much of a raise? "<<endl;
  cin>>raiseAmount;

  try {
      Employee& emp=inDB.getEmployee(employeeNumber);
      emp.promote(raiseAmount);
  }
  catch (std::exception ex) {
    cerr<<"Unable to promote employee! "<<endl;
  }
  
}


int main(int argc,char** argv)
{
  Database employeeDB;
  bool done=false;

  while(!done)
  {
    int selection=displayMenu();

    switch(selection)
    {
      case 1:
        doHire(employeeDB);
        break;
      case 2:
        doFire(employeeDB);
        break;
      case 3:
        doPromote(employeeDB);
        break;
      case 0:
        done=true;
        break;
      default:
        cerr<<"Unkown command. "<<endl;  
        
    }
  }
  return 0;
}
