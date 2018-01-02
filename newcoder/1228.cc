
/*
* 1228.cc
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Singleton.h"

#define INT_PTR int*
typedef int* int_ptr;

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

class Point{
public:
	Point(int xx, int yy);
	Point(Point &p);
	Point(void);

	int GetX(){
		return X;
	}
	
	int GetY(){
		return Y;
	}

private:
	int X, Y;
};

Point:: Point(int xx, int yy){
	X = xx;
	Y = yy;
}

Point:: Point(Point &p){
	X = p.X;
	Y = p.Y;
}

Point:: Point(void){
	X = 0;
	Y = 0;
}

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
	//printf("%s, %5.3s\n", "computer", "computer");
	/*
	int k, a, b;
	unsigned int w = 5;
	double x = 1.42;

	//x %= 3;
	//printf("%f\n", x);
	printf("%d\n", (w+=-20)); //convert unsigned to signed
	printf("%d\n", (k=(a=200, b=300)));
	printf("%d\n", (a+=a-=a=9));
	printf("%10s\n", "abcdefg");

	//Pointer A(); //error calling constructor
	Point A; //constructor without param
	Point B(1, 2);
	Point C(B);
	cout<<A.GetX()<<endl;
	cout<<B.GetX()<<endl;
	cout<<C.GetX()<<endl;
	*/
	/*
	char acX[] = "abc";
	char acY[] = {'a', 'b', 'c'};
	char *szX = "abc";
	char *szY = "abc";
	printf("&acX = %x\n", acX);
	printf("&acY = %x\n", acY);
	printf("&szX = %x\n", szX);
	printf("&szY = %x\n", szY);
	*/
	/*
	int i = 10;
	int j = 1;
	const int *p1;
	int const *p2 = &i;
	p2 = &j;
	int *const p3 = &i;
	*p3 = 20;
	//*p2 = 30;
	//p3 = &j;
	*/
	/*
	INT_PTR a, b;
	int_ptr c, d;
	printf("sizeof(a)=%d, sizeof(b)=%d, sizeof(c)=%d, sizeof(d)=%d\n", sizeof(a), sizeof(b), sizeof(c), sizeof(d));
	*/

	string a = "hello world";
	string b;
	if(a.c_str() == b.c_str()){
		cout<<"true"<<endl;
	}
	else{
		cout<<"false"<<endl;
	}

	string c = b;
	c = "";
	if(a.c_str() == c.c_str()){
		cout<<"true"<<endl;
	}
	else{
		cout<<"false"<<endl;
	}

	a = "";
	if(a.c_str() == b.c_str()){
		cout<<"true"<<endl;
	}
	else{
		cout<<"false"<<endl;
	}

	return 0;
}


































