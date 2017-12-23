#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void Generate_Letter(string letter[],int num_lines,string thisname)
{
  unsigned long max,pos;
  max=letter[0].max_size();
  for(int n=0;n<num_lines;n++)
  {
    if((pos=letter[n].find("CUSTOMER",0))<max)
    {
      letter[n].replace(pos,8,"");
      letter[n].insert(pos,thisname);
    }
    cout<<letter[n]<<endl;
  }
}

int main()
{
  string letter[100];
  string title,lastname,customer;
  int number_lines,number_customers;
  ifstream letter_in;
  ifstream customer_in;

  letter_in.open("letter.txt");
  customer_in.open("customer.txt");
  number_lines=0;
  while(getline(letter_in,letter[number_lines]))
    number_lines++;
  number_customers=0;
  while(customer_in>>title)
  {
    customer_in>>lastname;
    customer=title+" "+lastname;
    Generate_Letter(letter,number_lines,customer);
      number_customers++;
  }
}

