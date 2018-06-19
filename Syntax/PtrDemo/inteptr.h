
// inteptr.h

#include <iostream>
#include <string>

using namespace std;

class Ptr{
    public:
        Ptr(string s){
            str = s;
            cout<<"auto pointer created."<<endl;
        }

        ~Ptr(){
            cout<<"auto pointer delete:"<<str<<endl;
        }

        string& getString(){
            return str;
        }

        void setString(string s){
            str = s;
        }

        void print(){
            cout<<str<<endl;
        }

    private:
        string str;
};
