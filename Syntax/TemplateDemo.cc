
// TemplateDemo.cc

#include <iostream>
#include <vector>
#include <cassert>
#include <list>
#include "ctemplate.h"


using namespace std;

template<typename T>
struct EqualFunctor{
    bool operator()(const T& v1, const T& v2){
        return v1 == v2;
    }
};

template<typename T>
int find(const T nList[], const int nLen, const T nTarget, EqualFunctor<T> equals){
    if(!nList || nLen <= 0)
        return -1;
    int nIndex = -1;
    for(int i=0; i<nLen; ++i){
        if(equals(nTarget, nList[i])){
            nIndex = i;
            break;
        }
    }
    return nIndex;
}

struct DemoStruct{
    int nVal;
    float fVal;
    double dVal;

    DemoStruct(int _nVal, float _fVal, double _dVal):
        nVal(_nVal),
        fVal(_fVal),
        dVal(_dVal){}
};

// equals functor adapted for DemoStruct
template<>
struct EqualFunctor<DemoStruct>{
    bool operator()(const DemoStruct& v1, const DemoStruct& v2){
        return (v1.nVal == v2.nVal) && (v1.fVal == v2.fVal) && (v1.dVal == v2.dVal);
    }
};

void test(){
    cout<<"TemplateDemo Test Start......"<<endl;
    int nTestCase = 0;

    // int list test
    const int intList[] = {4,5,2,3,8,10,43,15,24};
    const int intLen = sizeof(intList)/sizeof(int);
    assert(-1 == find<int>(NULL, 4, 10, EqualFunctor<int>()));
    cout<<"Test Case "<<(nTestCase++)<<" OK ..."<<endl;

    assert(-1 == find<int>(intList, 0, 10, EqualFunctor<int>()));
    cout<<"Test Case "<<(nTestCase++)<<" OK ..."<<endl;
    
    assert(-1 == find<int>(intList, 4, 10, EqualFunctor<int>()));
    cout<<"Test Case "<<(nTestCase++)<<" OK ..."<<endl;

    assert(5 == find<int>(intList, intLen, 10, EqualFunctor<int>()));
    cout<<"Test Case "<<(nTestCase++)<<" OK ..."<<endl;

    // DemoStruct test
    const DemoStruct structList[] = {DemoStruct(4,5.0f,2.0f),
                                     DemoStruct(3,8.0f,10.0f),
                                     DemoStruct(43,15.0f,24.0f)};
    const int structLen = sizeof(structList)/sizeof(DemoStruct);
    assert(-1 == find<DemoStruct>(NULL, 4, DemoStruct(3,8.0f, 10.0f), EqualFunctor<DemoStruct>()));
    cout<<"Test Case "<<(nTestCase++)<<" OK ..."<<endl;

    assert(-1 == find<DemoStruct>(structList, 0, DemoStruct(3,8.0f, 10.0f), EqualFunctor<DemoStruct>()));
    cout<<"Test Case "<<(nTestCase++)<<" OK ..."<<endl;

    assert(-1 == find<DemoStruct>(structList, 1, DemoStruct(3,8.0f, 10.0f), EqualFunctor<DemoStruct>()));
    cout<<"Test Case "<<(nTestCase++)<<" OK ..."<<endl;
    
    assert(1 == find<DemoStruct>(structList, structLen, DemoStruct(3,8.0f, 10.0f), EqualFunctor<DemoStruct>()));
    cout<<"Test Case "<<(nTestCase++)<<" OK ..."<<endl;
    
    cout<<"Test Done!"<<endl;
}

template<class T>
T getMinNumber(T x, T y){
    return (x<y)? x:y;
}

void TemplateFuncTest(){
    int n1 = 2, n2 = 10;
    double d1 = 1.5, d2 = 5.6;
    cout<<"Minumum Integer : "<<getMinNumber(n1, n2)<<endl;
    cout<<"Minumum Real : "<<getMinNumber(d1, d2)<<endl;
}

using namespace ctemplate;

void ClassTemplateTest(){
    TClass<int, int> c1(3, 5);
    c1.show();

    TClass<int, char> c2(6, 'c');
    c2.show();

    TClass<double, int> c3(2.9f, 10);
    c3.show();
}

template<typename T>
void print(T t){
    typename T::iterator itor;
    for(itor=t.begin(); itor!=t.end(); ++itor){
        cout<<(*itor)<<" ";
    }
    cout<<endl;
}
void TemplateTypeTest(){
    list<int> l;
    l.push_back(1);
    l.push_front(2);
    if(!l.empty())
        print(l);

    vector<int> v;
    v.push_back(1);
    v.push_back(6);
    if(!v.empty())
        print(v);
}

class DoSome{
    public:
        void operator()(int i);
};

void DoSome::operator()(int i){
    cout<<i<<endl;
}

void DoSomeTest(){
    DoSome doSome;
    doSome(10);
}

int main(int args, char **argv){
    // test();
    
    // TemplateFuncTest();

    // ClassTemplateTest();

    // TemplateTypeTest();

    DoSomeTest();

    return 0;
}
