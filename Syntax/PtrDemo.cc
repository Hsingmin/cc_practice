
// PtrDemo.cc

#include <iostream>
#include <memory>
#include <string>

using namespace std;

class AutoPtr{
    public:
        AutoPtr(string s){
            str = s;
            cout<<"auto pointer created."<<endl;
        }

        ~AutoPtr(){
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

int AutoPtrTest(){
    
    auto_ptr<AutoPtr> pAuto(new AutoPtr("abcd"));
    pAuto->setString("hello");
    pAuto->print();  // hello
    pAuto.get()->print();  //hello
    pAuto->getString() += "world!";
    (*pAuto).print();  // helloworld!
    pAuto.reset(new AutoPtr("abcd"));  // auto pointer deleted:helloworld!
    pAuto->print();  // abcd

    auto_ptr<AutoPtr> ptr1(new AutoPtr("123"));
    auto_ptr<AutoPtr> ptr2(new AutoPtr("456"));
    ptr2 = ptr1;  // ptr2 take charge
    ptr2->print();  // 123
    if(NULL == ptr1.get())
        cout<<"ptr1 = NULL"<<endl;
    pAuto.release();
    pAuto.reset();

    return 0;  // auto pointer deleted:abcd
}

int SharedPtrTest(){
    shared_ptr<AutoPtr> ptr1(new AutoPtr("123"));
    shared_ptr<AutoPtr> ptr2(new AutoPtr("456"));

    cout<<(ptr2->getString())<<endl;  // 456
    cout<<ptr2.use_count()<<endl;  //1
    ptr1 = ptr2;  // ptr1 deleted
    ptr1->print();  // 456
    cout<<ptr2.use_count()<<endl;  // 2
    cout<<ptr1.use_count()<<endl;  // 2
    ptr1.reset();  // ptr2 deleted
    ptr2.reset();
    cout<<"done!"<<endl;
    return 0;
}

class B;
class A{
    public:
        // shared_ptr<B> pb_;
        weak_ptr<B> pb_;
        ~A(){
            cout<<"A delete"<<endl;
        }
};

class B{
    public:
        shared_ptr<A> pa_;
        ~B(){
            cout<<"B delete"<<endl;
        }
};

void WeakPtrTest(){
    shared_ptr<B> pb(new B());
    shared_ptr<A> pa(new A());

    pb->pa_ = pa;
    pa->pb_ = pb;

    cout<<pb.use_count()<<endl;
    cout<<pa.use_count()<<endl;
}

int main(int args, char **argv){
    // SharedPtrTest();

    WeakPtrTest();
    return 0;
}
