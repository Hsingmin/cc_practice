//airlineTicket.cpp

#include<iostream>
#include"airlineTicket.h"

using namespace std;

airlineTicket::airlineTicket()
{
  //Initialize data members

  fHasEliteSuperRewardsStatus=false;
  mPassengerName="Unkown Passenger";
  mNumberOfMiles=0;
}

airlineTicket::~airlineTicket()
{
  //Nothing need do
}

int airlineTicket::calculatePrinceInDollars()
{
  if(getHasEliteSuperRewardsStatus())
  {
    //Elite Super Rewards customers fly for free.
    return 0;
  }

  return static_cast<int>((getNumberOfMiles()*0.1));
}

string airlineTicket::getPassengerName()
{
  return mPassengerName;
}

void airlineTicket::setPassengerName(string inName)
{
  mPassengerName=inName;
}

int airlineTicket::getNumberOfMiles()
{
  return mNumberOfMiles;
}

void airlineTicket::setNumberOfMiles(int inMiles)
{
  mNumberOfMiles=inMiles;
}

bool airlineTicket::getHasEliteSuperRewardsStatus()
{
  return (fHasEliteSuperRewardsStatus);
}

void airlineTicket::setHasEliteSuperRewardsStatus(bool inStatus)
{
  fHasEliteSuperRewardsStatus=inStatus;
}
