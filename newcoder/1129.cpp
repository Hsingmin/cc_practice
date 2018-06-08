
#include<stdio.h>
#include<iostream>
#include<vector>
#include<sys/types.h>
#include<unistd.h>
using namespace std;

/*
#define SUB(x, y) x-y
//macro expansion *&element-offset=value lack of legal left value
// #define ACCESS_BEFORE(element, offset, value) *SUB(&element, offset) = value 
#define ACCESS_BEFORE(element, offset, value) *(SUB(&element, offset)) = value

int main(void){
	int array[10] = {1,2,3,4,5,6,7,8,9,10};
	int i;
	ACCESS_BEFORE(array[5], 4, 6);
	printf("array : ");
	for(i = 0; i < 10; i++){
		printf("%d", array[i]);
	}
	printf("\n");
	return 0;
}
*/

/**
class A{
	public: A(){
		cout<<"1";
	}
	~A(){
		cout<<"2";
	}
};

class B: public A{
	public: B(){
		cout<<"3";
	}
	~B(){
		cout<<"4";
	}
};

int main(){
	B b;
}

int main(){
	int a[] = {2,4,6,8,10}, *p, **k;
	p = a;
	k = &p;
	printf("%d\n", *(p++));
	printf("%d\n", **k);
	return 0;
}
*/

/*
int main(void){
	vector<int> array;
	array.push_back(100);
	array.push_back(300);
	array.push_back(300);
	array.push_back(300);
	array.push_back(300);
	array.push_back(500);

	vector<int>:: iterator itor;
	for(itor = array.begin(); itor != array.end; itor++){
		if(*itor == 300){
			itor = array.erase(itor);
		}
	}

	for(itor = array.begin(); itor != array.end; itor++){
		cout<<*itor<<"";
	}

	return 0;
}
*/
/*
//global variable
int d = 1;
void func(int p){
	//local variable
	int d = 5;
	d += p++;
	printf("%d", d);
}

int main(void){
	int a = 3;
	//transfer value reference 
	func(a);
	d += a++;
	printf("%d\n", d);

	//main() calling causes stack overflow 
	//main();
}
*/

/*
//keyword virtual disambiguate extending super Class A 
class A{
	public:
	A(char *s){
		cout<<s<<endl;
	}
	~A(){}
};

class B: virtual public A{
	public:
	B(char *s1, char *s2): A(s1){
		cout<<s2<<endl;
	}
};

class C: virtual public A{
	public:
	C(char *s1, char *s2): A(s1){
		cout<<s2<<endl;
	}
};

class D: public B, public C{
	public:
	D(char *s1, char *s2, char *s3, char *s4): B(s1, s2), C(s1, s3), A(s1){
		cout<<s4<<endl;
	}
};

int main(void){
	D *p = new D("class A", "class B", "class C", "class D");
	delete p;
	return 0;
}
*/

int main(void){
	int i;
	//pid_t fpid;

	printf("_main pid = %4d\n", getpid());
	printf(" i    c/p    ppid    pid    fpid    \n");

	for(i = 0; i < 2; i++){
		//fork child pid return twice
		pid_t fpid = fork();
		if(0 == fpid){
			printf(" %d  child  %4d  %4d  %4d  \n", i, getppid(), getpid(), fpid);
			//printf("-\n");
		}
		else{
			printf(" %d  parent  %4d  %4d  %4d  \n", i, getppid(), getpid(), fpid);
			//printf("-\n");
		}
		//"\n" can clear the line buffer
		//printf("-\n");
		//printf("-");
	}

	return 0;
}

























