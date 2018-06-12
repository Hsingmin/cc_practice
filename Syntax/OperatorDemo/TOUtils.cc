
// TOUtils.cc

#include <iostream>
#include "timeoperator.h"

int main(int args, char **argv){
    using std::cout;
    using std::endl;
    
    Time wedding(4, 35);
    Time waxing(2, 47);
    Time diff;
    Time total;
    Time adjusted;

    cout<<"wedding time = ";
    wedding.Show();
    cout<<endl;

    cout<<"waxing time = ";
    waxing.Show();
    cout<<endl;
    
    cout<<"total work time = ";
    total = wedding + waxing;  // use operator+()
    total.Show();
    cout<<endl;

    diff = wedding - waxing;
    cout<<"wedding time - waxing time = ";
    diff.Show();
    cout<<endl;

    adjusted = total * 1.5;
    cout<<"adjusted work time = ";
    adjusted.Show();
    cout<<endl;

    return 0;
}
