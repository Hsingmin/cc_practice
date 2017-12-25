//airlineTicket.h

#include<string>
using namespace std;

class airlineTicket
{
  public:
    airlineTicket();
    ~airlineTicket();

    int calculatePrinceInDollars();
    string getPassengerName();
    void setPassengerName(string inName);
    int getNumberOfMiles();
    void setNumberOfMiles(int inMiles);
    bool getHasEliteSuperRewardsStatus();
    void setHasEliteSuperRewardsStatus(bool inStatus);

  private:
    string mPassengerName;
    int mNumberOfMiles;
    bool fHasEliteSuperRewardsStatus;
    
};
