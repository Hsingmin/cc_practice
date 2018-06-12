
// ExceptionMean.cc

#include <iostream>
#include <cmath>
#include "exceptmean.h"

double HMean(double a, double b);
double GMean(double a, double b);

int main(int args, char **argv){
    using std::cout;
    using std::cin;
    using std::endl;

    double x, y, z;
    cout<<"Enter Two Numbers: ";

    while(cin>>x>>y){
        try{
            z = HMean(x, y);
            cout<<"Harmonic mean of "<<x<<" and "<<y
                <<" is "<<z<<endl;
            cout<<"Geometric mean of "<<x<<" and "<<y
                <<" is "<<GMean(x, y)<<endl;
            cout<<"Enter the next set of numbers <q to quit> : ";
        }
        catch(BadHMean &bh){
            bh.Mesg();
            cout<<"Try it again.\n";
            continue;
        }
        catch(BadGMean &bg){
            cout<<bg.Mesg();
            cout<<"Values used: "<<bg.v1<<", "<<bg.v2<<endl;
            cout<<"Sorry, you don't get to play any more.\n";
            break;
        }
    }
    cout<<"End...\n";
    return 0;
}

double HMean(double a, double b){
    if(a == b)
        throw BadHMean(a, b);
    return 2.0*a*b/(a+b);
}

double GMean(double a, double b){
    if(a<0 || b<0)
        throw BadGMean(a, b);
    return std::sqrt(a*b);
}
