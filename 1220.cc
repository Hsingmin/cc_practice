
/* 1220.cc */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class A{
	public:
		A(){
			cout<<"class A created."<<endl;
		}
		~A(){
			cout<<"class A deleted."<<endl;
		}
};

class B: public A{
	public:
		B(){
			cout<<"class B created."<<endl;
		}
		~B(){
			cout<<"class B deleted."<<endl;
		}
};

class C: public B{
	public:
		C(){
			cout<<"class C created."<<endl;
		}
		~C(){
			cout<<"class C deleted."<<endl;
		}
};

int main(int argc, char **argv){
	B *b = new B();
	C *c = new C();
	A *pab = dynamic_cast<B*>(b);
	A *pac = dynamic_cast<C*>(c);
	B *pbc = dynamic_cast<C*>(c);

	//B *pb = dynamic_cast<A*>(a);// downward cast failed
	delete(b);
	delete(c);
	return 0;
}
