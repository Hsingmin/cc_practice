
// InlineDemo.cc

#include <iostream>

#define SQUARE(x) x*x

inline double square(double x) { return x*x; }

int main(int args, char **argv){
        using namespace std;
        double a, b;
        double c = 13.0;

        a = square(5.0);
        b = square(4.5+7.5);
        cout<<"a = "<<a<<" , b = "<<b<<"\n";
        cout<<"c = "<<c;
        cout<<", c squared = "<<square(c++)<<"\n";
        cout<<"Now c = "<<c<<"\n";

        cout<<"=================================\n";

        a = SQUARE(5.0);
        b = SQUARE(4.5+7.5);
        cout<<"a = "<<a<<" , b = "<<b<<"\n";
        cout<<"c = "<<c;
        cout<<", c SQUARED = "<<SQUARE(c++)<<"\n";
        cout<<"Now c = "<<c<<"\n";

        return 0;
}

