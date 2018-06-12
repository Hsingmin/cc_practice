
// TFUtils.cc

#include <iostream>
#include "timefriend.h"

int main(int args, char **argv){
    using std::cout;
    using std::endl;
    
    Time aida(4, 35);
    Time tosca(2, 47);
    Time temp;

    cout<<"aida and tosca :\n ";
    cout<<aida<<"; "<<tosca<<endl;

    temp = aida + tosca;
    cout<<"aida + tosca = "<<temp<<endl;
    temp = aida * 1.17;
    cout<<"aida * 1.17 = "<<temp<<endl;
    cout<<"10 * tosca = "<<(10.0*tosca)<<endl;

    return 0;
}
