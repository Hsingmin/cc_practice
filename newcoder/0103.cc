
//0103.cc

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class AConst{
public:
	AConst(){
		cout<<"AConst"<<endl;
	}
};

void ConstFunc(const AConst** p){
	cout<<"const A**"<<endl;
}

void ConstGunc(const AConst* const* p){
	cout<<"const A* const* p"<<endl;
}

void ConstKunc(const AConst* &p){
	cout<<"const A* &p"<<endl;
}

int main(int argc, char *argv[]){
	
	/*
	const AConst* ca = new AConst();
	AConst* a = new AConst();
	AConst** p = &a;
	//const AConst** q = new AConst();
	ConstKunc(ca); //
	//ConstFunc(q);
	ConstGunc(p);
	*/
	
	/*
	const int x = 1;
	int* p;
	int const** q = &p;
	*q = &x;
	**q = 2;
	*p = 2;
	printf("%d\n", x);
	*/

	

	return 0;
}
























