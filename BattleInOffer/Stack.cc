
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

#define MAXLEN 50

struct Data{
	char key[10];
	char value[10];
	int id;
};

struct StackType{
	Data node[MAXLEN+1];
	int top;
};

void STInit(StackType &ST){
	ST.top = -1;
}

int STIsEmpty(StackType &ST){
	if(-1 == ST.top)
		return 1;
	else
		return 0;
}

int STIsFull(StackType &ST){
	if(MAXLEN == ST.top)
		return 1;
	else
		return 0;
}

void STPush(StackType &ST, Data node){
	if(MAXLEN == ST.top){
		cout<<"Stack is Full, Push Failed."<<endl;
		return;
	}
	ST.node[++ST.top] = node;
	return;
}

int STPop(StackType &ST, Data &node){
	if(-1 == ST.top){
		cout<<"Stack is Empty, Pop Failed."<<endl;
		return 0;
	}
	node = ST.node[ST.top--];
	return 1;
}

void STShow(StackType &ST){
	if(-1 == ST.top){
		cout<<"Empty Stack."<<endl;
		return;
	}
	cout<<"============ Show Stack ============="<<endl;
	int index;
	for(index = ST.top; index >=0; index--)
		cout<<ST.node[index].key<<" "<<ST.node[index].value<<" "<<ST.node[index].id<<endl;
	cout<<"============ Show Stack ============="<<endl;
	return;
}
void STClear(StackType &ST){
	ST.top = -1;
	return;
}

void StackTest(){
	StackType stack;
	STInit(stack);
	STShow(stack);
	
	// Stack push test.
	Data node;
	strcpy(node.key, "name");
	strcpy(node.value, "localhost");
	node.id = 0;
	STPush(stack, node);
	
	strcpy(node.key, "port");
	strcpy(node.value, "8080");
	node.id = 1;
	STPush(stack, node);
	STShow(stack);
	
	// Stack pop test.
	Data popnode;
	STPop(stack, popnode);
	STShow(stack);
}

int main(int args, char** argv){
	StackTest();
	return 1;
}





















