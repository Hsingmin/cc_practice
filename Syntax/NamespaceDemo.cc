
// NamespaceDemo.cc

/*
 * namespace identifier{
 *  entries;
 * }
 *
 * identifiers::entries;
 */

#include <iostream>

using namespace std;

namespace first{
    int x = 5;
    int y = 10;
}

namespace second{
    double x = 3.1416;
    double y = 1.7183;
}

int main(int args, char **argv){
    {
        using first::x;
        using second::y;
        cout<<"Using first::x and second::y"<<endl;
        cout<<x<<endl;
        cout<<y<<endl;

        cout<<"Print first:y and second::x"<<endl;
        cout<<first::y<<endl;
        cout<<second::x<<endl;
    }

    {
        using namespace first;
        cout<<"Using namespace first: "<<endl;
        cout<<x<<endl;
        cout<<y<<endl;

        cout<<"Print second::x and second::y"<<endl;
        cout<<second::x<<endl;
        cout<<second::y<<endl;
    }

    return 0;
}
