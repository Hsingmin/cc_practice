
/*
* 1228.cc
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Singleton.h"

using namespace std;

typedef int * T;

// Singleton 
class CSingleton{
	private:
		CSingleton(){} //private constructor
		static CSingleton *m_pInstance;
	public:
		static CSingleton *GetInstance(){
			if(m_pInstance == NULL){
				m_pInstance = new CSingleton();
				return m_pInstance;
			}
		}
};

class A{
public:
	A():m_iVal(0){
		test();
	}
	virtual void func(){
		cout<<m_iVal<<' ';
	}
	void test(){
		func();
	}
public:
	int m_iVal;
};

class B: public A{
public:
	B(){
		test();
	}
	virtual void func(){
		++m_iVal;
		cout<<m_iVal<<' ';
	}
};

char* GetMem(void){
	char p[] = "hello world";
	p[5] = 0x0;
	return p;
}

class Printer{
public:
	Printer(string name){
		cout<<name;
	}
};

class Container{
public:
	Container(): b("b"), a("a"){}
	Printer a;
	Printer b;
};

int main(int argc, char *argv[]){
	
	//T a[10]; //int *a[10] address array
	//printf("sizeof(a[0])=%d\n", sizeof(a[0]));

	//Singleton* ps = Singleton::Instance(); //get Instance by global access point
	//Singleton::Destroy();
	
	//parent A() 0 -- child B() 1
	//A* p = new B;
	//B::test() -- 2
	//p->test();
	/*
	char *s = 0x0;
	s = GetMem(); //pointer p deleted when function returns
	printf("%s\n", s);
	*/
	/*
	int a[3][4] = {0};
	*(a[2]+1) = 2;
	printf("%d\n", a[2][1]);
	*/

	//Container c;
	printf("%s, %5.3s\n", "computer", "computer");

	return 0;
}
