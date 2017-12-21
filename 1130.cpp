
#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

class A{
	public: A(){
		cout<<"create A"<<endl;
	}
	
	A(const A& other){
		cout<<"copy A"<<endl;
	}

	~A(){
		cout<<"~A"<<endl;
	}
};

/* class C calls A() */
class C{
	public: C(){
		cout<<"create C"<<endl;
	}
	C(const A& other){
		cout<<"copy C"<<endl;
	}
	~C(){
		cout<<"~C"<<endl;
	}
};

/* class B extends A 
   1. calls parent class A constructor;
   2. calls private member constructor C;
   3. calls own constructor B;
   --------------------------------------
   4. calls own destructor ~B;
   5. calls private member destructor ~C;
   6. calls parent class A destructor ~A;
*/
class B: public A{
	public: B(){
		cout<<"create B"<<endl;
	}
	~B(){
		cout<<"~B"<<endl;
	}
	/* private member function */
	private: C _a;
};

/* template case */
//function template
template<typename T>
bool equivalent(const T& a, const T& b){
	return !(a < b) && !(b < a);
}

//class template
template<typename  T = int>
class bignumber{
	T _v;
public:
	bignumber(T a): _v(a){}
	inline bool operator<(const bignumber& b) const;// (const bignumber<T> b)
};

template<typename T>
bool bignumber<T>:: operator<(const bignumber& b) const{
	return _v < b._v;
}
/*
template<typename T = int>
int operator+(const T& x, const T& y){
	return (x+y);
}
*/
template<typename T = int> 
class Bignumber{
	T _l;
	public:
		Bignumber(T i): _l(i){}
		Bignumber operator+(const Bignumber<T> b){
			return (_l+b._l);
		}
};

int main(void){
	//B b;
	//cout<<"---------------------------------"<<endl;
	
	/*
	int a[3][3], *p, i;
	p = &a[0][0];
	for(i=0; i<9; i++){
		p[i] = i;
	}
	for (i=0; i<3; i++)
		printf("%d\n", a[1][i]);

	*/
	
	/*
	bignumber<> a(1), b(1);
	cout<< equivalent(a, b)<<endl;
	cout<< equivalent<double>(1, 2)<<endl;
	cin.get();
	return 0;
	*/
	/*
	Bignumber<> b1(1), b2(2);
	Bignumber<> b = b1+b2;
	//cout<<"---- using template (b1+b2) = %d", (b1+b2);
	std::cout<<b;
	cin.get();
	*/

	char s1[] = "\\123456\123456\t";
	char s2[] = "//123456/123456/t";
	printf("length of s1 = %d\n", strlen(s1));	
	printf("length of s2 = %d\n", strlen(s2));

	return 0;	
}



























