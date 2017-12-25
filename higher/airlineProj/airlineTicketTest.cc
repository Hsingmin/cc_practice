#include<iostream>
#include"airlineTicket.h"
using namespace std;

int main(int argc,char** argv)
{
  airlineTicket myTicket; //Stack-based 
  
  myTicket.setPassengerName("Sheldon T.Cooper");
  myTicket.setNumberOfMiles(700);
  int cost=myTicket.calculatePrinceInDollars();
  cout<<"This ticket will cost $ "<<cost<<endl;

  airlineTicket* myTicket2;//Heap-based
  
  myTicket2=new airlineTicket();
  myTicket2->setPassengerName("Laudimore M.Hallidue");
  myTicket2->setNumberOfMiles(2000);
  myTicket2->setHasEliteSuperRewardsStatus(true);
  int cost2=myTicket2->calculatePrinceInDollars();
  cout<<"This other ticket will cost $ "<<cost2<<endl;
  delete myTicket2;

  return 0;


}
