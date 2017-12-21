
#include "stdio.h"
#include <iostream>
#include "string.h"
using namespace std;

/*
//static member includes the specified class
//only static const member can be initilized inner
class Fred{
	public:
	void print(){
		cout<<DATA<<endl;
	}
	void setData(double d){
		data = d;
	}

	//static member must be defined inner 
	static int count;
	static const int value = 0;

	private:
		double data;
};
//initialized outter
int Fred:: count = 0;

class A{
	
	//:~

	private:
		int a;
	public:
		const int b;
		float* &c;
		
		//static variable included in class not object
		static const char* d;
		static double *e;
};


class _A{
	public:
		_A(){
			printf("1");
		}

		_A(_A &a){
			printf("2");
		}

		_A &operator=(const _A &a){
			printf("3");
			return *this;
		}
};
*/

/*

//using traits
template <typename T>
//generalization 
struct is_void{
	static const bool value = false;
};
template <>
//specailaization
struct is_void<void>{
	static const bool value = true;
};
int main(){
	//call generalization version by param int
	std::cout<<is_void<int>::value;
	//call specialization version by param void
	std::cout<<is_void<void>::value;
}

void func(char (&p)[10]){
	printf("%d\n", sizeof(p));
}

int main(void){
	//_A a;
	//_A b = a;
	char p[10] = {'0'};
	enum string{
		x1,
		x2,
		x3=10,
		x4,
		x5
	} x;

	//printf("%d\n", x);
	func(char(&p));

}
*/

/*
char* f(char *str, char ch){
	char *it1 = str;
	char *it2 = str;
	while(*it2 != '\0'){
		while(*it2 == ch){
			it2++;
		}
		*it1++ = *it2++;
	}
	return str;
}

int main(int argc, char *argv[]){
	char *a = new char[10];
	strcpy(a, "abcdcccd");
	cout<<f(a, 'c')<<endl;
}
*/

/*
int FindSubString(char *pch){
	int count = 0;
	char *p1 = pch;
	while(*p1 != '\0'){
		if(*p1 == p1[1]-1){
			p1++;
			count++;
		}
		else{
			break;
		}
	}

	int count2 = count;
	while(*p1 != 0){
		if(*p1 == p1[1]+1){
			p1++;
			count2--;
		}
		else{
			break;
		}
	}

	if(count2 == 0){
		return count2;
	}

	return 0;
}

void ModifyString(char *pText){
	char *p1 = pText;
	char *p2 = p1;
	while(*p1 != '\0'){
		int count = FindSubString(p1);
		if(count > 0){
			*p2++ = *p1;
			sprintf(p2, "%i", count);
			while(*p2 != '\0'){
				p2++;
			}
			p1 += count + count + 1;
		}
		else{
			*p2++ = *p1++;
		}
	}
}

int main(void){
	char text[32] = "XYBCDCBABABA";
	ModifyString(text);
	printf("%s\n", text);
}
*/
/*
class parent{
	public:
	virtual void output();
};
void parent::output(){
	printf("parent!");
}

class son{
	public:
	virtual void output();
};
void son::output(){
	printf("son!");
}

int main(void){
	son s;
	memset(&s, 0, sizeof(s));
	parent &p = s;
	p.output();
}
*/

//c1 calls constructor
//c2 just a pointer
MyClass c1, *c2;
//c3 new MyClass
MyClass *c3 = new MyClass;
//c4 is just a nickname of c1
MyClass &c4 = c1;

//memory leak with no delete
int func(){
	int *a = new int(3);
	return *a;
}

//temporary a[3]
int *func(){
	int a[3] = {1,2,3};
	return a;
}

vector<int> func(){
	vector<int> v(3);
	return v;
}

//returns nothing for temporary a[3]
void func(int *ret){
	int a[3] = {1,2,3};
	ret = a++;
	return;
}

int main(void){
	int a[2][2][3] = {{{1,2,3}, {4,5,6}}, {{7,8,9}, {10,11,12}}};
	int *ptr = (int *)(&a + 1); //&a+i = a+i*sizeof(a)
	//a+i = a+i*sizeof(a[0])
	printf("%d %d\n", *(int*)(a+1), *(ptr-1));
}
















