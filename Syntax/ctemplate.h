
// ctemplate.h

#ifndef _CLASS_TEMPLATE_H_
#define _CLASS_TEMPLATE_H_

#include <iostream>

using namespace std;

namespace ctemplate{
    template<typename T1, typename T2>
        class TClass{
            public:
                TClass(T1 a, T2 b);
                ~TClass();
                void show();
            private:
                T1 Q;
                T2 R;
        };

    template<typename T1, typename T2>
        TClass<T1, T2>::TClass(T1 a, T2 b): Q(a), R(b){
            cout<<"create TClass ... "<<endl;
        }

    template<typename T1, typename T2>
        TClass<T1, T2>::~TClass(){
            cout<<"delete TClass ... "<<endl;
        }

    template<typename T1, typename T2>
        void TClass<T1, T2>::show(){
            cout<<"Q = "<<Q<<" , R = "<<R<<endl;
        }
}

#endif




