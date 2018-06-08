
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;

template<class T>
class Stack{
	public:
		Stack();
		bool IsEmpty();
		bool IsFull();
		bool Push(const T & item);
		bool Pop(T & item);
		~Stack();
	private:
		enum {MAX = 10};
		T items[MAX];
		int top;
};

template<class T>
Stack<T>::Stack(){
	top = 0;
}

template<class T>
Stack<T>::~Stack(){
	top = -1;
}

template<class T>
bool Stack<T>::IsEmpty(){
	return top == 0;
}

template<class T>
bool Stack<T>::IsFull(){
	return top == MAX;
}

template<class T>
bool Stack<T>::Push(const T & item){
	if(top < MAX){
		items[top++] = item;
		return true;
	}
	else
		return false;
}

template<class T>
bool Stack<T>::Pop(T & item){
	if(top > 0){
		item = items[--top];
		return true;
	}
	else
		return false;
}

void TestStack(){
	Stack<int> stack;
	cout<<"stack is empty : "<<stack.IsEmpty()<<endl;
	int element[10] = {0,1,2,3,4,5,6,7,8,9}; 
	for(int i=0; i<(sizeof(element)/sizeof(int)); i++){
		stack.Push(element[i]);
	}
	cout<<"stack is empty : "<<stack.IsEmpty()<<endl;
	
	int popout = 0;
	stack.Pop(popout);
	cout<<"stack pop out : "<<popout<<endl;
}

template<class T1, class T2>
class Pair{
	public:
		T1 & first();
		T2 & second();
		T1 first() const {return a;}
		T2 second() const {return b;}
		Pair(const T1 & aval, const T2 & bval): a(aval), b(bval) {}
		Pair(){}
	private:
		T1 a;
		T2 b;
};

template<class T1, class T2>
T1 & Pair<T1, T2>::first(){
	return a;
}

template<class T1, class T2>
T2 & Pair<T1, T2>::second(){
	return b;
}

void TestTemplate(){
	Pair<string, int> ratings[4] = {
		Pair<string, int>("The Purple Duck", 5),
		Pair<string, int>("Jaquie's Frisco Al Fresco", 4),
		Pair<string, int>("Cafe Souffle", 5),
		Pair<string, int>("Bertie's Eats", 3)
	};

	int joints = sizeof(ratings)/sizeof(Pair<string, int>);
	cout<<"Rating:\t Eatery\n";
	
	for(int i = 0; i < joints; i++){
		cout<<ratings[i].second()<<":\t"<<ratings[i].first()<<endl;
	}

	return;
}

int main(int args, char** argv){
	TestStack();
	return 0;
}



















