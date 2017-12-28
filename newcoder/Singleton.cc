
#include <iostream>
#include "Singleton.h"

using namespace std;

Singleton* Singleton::pInstance = NULL;

Singleton::Singleton(){ //access private constructor
	cout<<"Singleton..."<<endl;
}

Singleton* Singleton::Instance(){
	if(NULL == pInstance){ // construct new Object
		pInstance = new Singleton();
	}
	return pInstance;
}

void Singleton::Destroy(){
	delete pInstance;
	pInstance = NULL;
	cout<<"Destroy..."<<endl;
}
