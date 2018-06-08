
// EnumDemo.cc

// compiled by g++ -std=c++11 EnumDemo.cc -o EnumDemo

#include <iostream>
using namespace std;

int main(int args, char **argv){

    enum class egg{
        Small,
        Medium,
        Large,
        Jumbo
    };

    enum class tshirt{
        Small,
        Medium,
        Large,
        XLarge
    };
    
    egg e = egg::Small;
    tshirt t = tshirt::Small;
    
    cout<<"value of e = "<<int(e)<<endl;
    cout<<"value of t = "<<int(t)<<endl;
    
}
