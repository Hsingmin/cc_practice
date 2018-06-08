
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

struct QueueType{
	Data node[MAXLEN+1];
	int front;
	int tail;
};

void QInit(QueueType &QT){
	QT.front = 0;
	QT.tail = 0;
}

int QIsEmpty(QueueType &QT){
	if(QT.front == QT.tail)
		return 1;
	else
		return 0;
}

int QIsFull(QueueType &QT){
	if(MAXLEN == (QT.tail-QT.front))
		return 1;
	else
		return 0;
}

void QPush(QueueType &QT, Data node){
	if(MAXLEN == (QT.tail-QT.front)){
		cout<<"Queue is Full, Push Failed."<<endl;
		return;
	}
	QT.node[QT.tail++] = node;
	return;
}

int QPop(QueueType &QT, Data &node){
	if(QT.front == QT.tail){
		cout<<"Queue is Empty, Pop Failed."<<endl;
		return 0;
	}
	node = QT.node[QT.front++];
	return 1;
}

void QShow(QueueType &QT){
	if(QT.front == QT.tail){
		cout<<"Empty Queue."<<endl;
		return;
	}
	cout<<"============ </> Show Queue ============="<<endl;
	int index;
	for(index = QT.front; index < QT.tail; index++)
		cout<<QT.node[index].key<<" "<<QT.node[index].value<<" "<<QT.node[index].id<<endl;
	cout<<"============ Show Queue </> ============="<<endl;
	return;
}
void QTClear(QueueType &QT){
	QT.front = 0;
	QT.tail = 0;
	return;
}

void QueueTest(){
	QueueType queue;
	QInit(queue);
	
	Data node;
	strcpy(node.key, "name");
	strcpy(node.value, "localhost");
	node.id = 0;
	QPush(queue, node);
	
	strcpy(node.key, "port");
	strcpy(node.value, "8080");
	node.id = 1;
	QPush(queue, node);

	strcpy(node.key, "user");
	strcpy(node.value, "admin");
	node.id = 2;
	QPush(queue, node);
	QShow(queue);
	
	Data popnode;
	QPop(queue, popnode);
	QPop(queue, popnode);
	QShow(queue);
}

int main(int args, char** argv){
	QueueTest();
	return 1;
}





















