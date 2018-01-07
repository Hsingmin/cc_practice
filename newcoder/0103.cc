
//0103.cc

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <cstring>
#include <math.h>

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

char* func(char *p){
	return p;
}

struct StTask{
	uint16_t id;
	uint32_t value;
	uint64_t timestamp;
};

void fool(){
	StTask task = {};
	uint64_t a = 0x00010001;
	memcpy(&task, &a, sizeof(uint64_t));
	printf("%11u, %11u, %11u\n", task.id, task.value, task.timestamp);
}

// count the "1"s in binary value
int BitCount(unsigned int n){
	n = (n&0x55555555)+((n>>1)&0x55555555);
	n = (n&0x33333333)+((n>>2)&0x33333333);
	n = (n&0x0f0f0f0f)+((n>>4)&0x0f0f0f0f);
	n = (n&0x00ff00ff)+((n>>8)&0x00ff00ff);
	n = (n&0x0000ffff)+((n>>16)&0x0000ffff);
	return n;
}

class Point{
	friend double Distance(const Point &p1, const Point &p2){
		double dx = p1.x_ - p2.x_;
		double dy = p1.y_ - p2.y_;
		return (sqrt(dx*dx + dy*dy));
	}

	public:
		Point(int x, int y): x_(x), y_(y){}

	private:
		int x_;
		int y_;
};

class TA{
public:
	int func1();
	virtual void func2();
private:
	int _a1;
	static int _a2;
};

class TB: public TA{
public:
	virtual void func2(); //virtual function table pointer
};

#pragma pack(2)
class BU{
	int number;
	union UBuffer{
		char buffer[13];
		int number;
	}ubuf;
	void foo(){}
	typedef char* (*f)(void*);
	enum{hdd, ssd, blueray}disk;
}bu;

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
	/*
	int i = 10, j = 0;
	if(j = 1)
		i++;
	else
		i--;
	printf("%d\n", i);
	
	char* pt;
        char c = 'a';
	pt = func(&c);
	printf("%d\n", pt);
	*/

	//fool();
	/*
	int i = 2, j = 4;
	int a[4][10] = {0};
	printf("*(%x) = %d\n", *(a+i)+j, *(*(a+i)+j));

	printf("%d\n", BitCount(197));
	
	static char *s[] = {"black", "white", "pink", "violet"};
	char **ptr[] = {s+3, s+2, s+1, s}, ***p;
	p = ptr;
	++p;
	printf("%s\n", **p+1);
	*/

	//int a = 5;
	//printf("%d\n", ++(a++)); //lvalue required as increment operand
	Point p1(3, 4);
	Point p2(6, 9);
	cout<<Distance(p1, p2)<<endl;

	cout<<"sizeof(TB)="<<sizeof(TB)<<endl;
	cout<<"sizeof(bu)="<<sizeof(bu)<<endl;

	enum{a,b,c,d,e,f,g,h}alphabet;
	cout<<"sizeof(alphabet)="<<sizeof(alphabet)<<endl;

	return 0;
}
























