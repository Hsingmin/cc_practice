
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct LinkNode{
	int key;
	LinkNode* next;
	LinkNode(int val): key(val), next(NULL){}
};

class LinkList{
	public:
		LinkList();
		void InsertHead(int val);
		void InsertNode(int val, int pos);
		void DeleteNode(int val);
		int GetLength();
		void Reverse();
		int FindNode(int val);
		void Print();
		bool IsLoop();
		~LinkList();
	private:
		LinkNode *head;
		int length;
};

LinkList::LinkList(){
	head = NULL;
	length = 0;
}

LinkList::~LinkList(){
	LinkNode* p;
	int i;
	for(i=0; i<length; i++){
		p = head;
		head = head->next;
		delete(p);
	}
}

void LinkList::InsertHead(int val){
	InsertNode(val, 0);
}

void LinkList::InsertNode(int val, int pos){
	if(pos < 0){
		cout<<"Invalid position."<<endl;
		return;
	}
	int index;
	LinkNode* p = head;
	LinkNode* node = new LinkNode(val);
	if(0 == pos){
		head = node;
		head->next = p;
		length ++;
		return;
	}
	while(index < pos && p != NULL){
		p = p->next;
		index ++;
	}
	if(NULL == p){
		cout<<"Position exceeds length of linklist."<<endl;
		return;
	}
	node->next = p->next;
	p->next = node;
	length ++;
	return;
}

void LinkList::DeleteNode(int val){
	int pos = FindNode(val);
	if(-1 == pos){
		cout<<"Cannot find node with key= "<<val<<endl;
		return;
	}
	LinkNode* p = head;
	if(0 == pos){
		head = head->next;
		delete(p);
		length --;
		return;
	}
	int index = 1;
	while(index < pos){
		p = p->next;
		index ++;
	}
	LinkNode* q = p->next;
	p->next = p->next->next;
	delete(q);
	return;
}

int LinkList::FindNode(int val){
	int pos = 0;
	LinkNode* p;
	p = head;
	while(p != NULL){
		if(val == p->key)
			return pos;
		p = p->next;
		pos ++;
	}
	return -1;
}

int LinkList::GetLength(){
	return length;
}

void LinkList::Reverse(){
	LinkNode* curr = head;
	LinkNode* pre = curr->next;
	LinkNode* tmp;
	while(pre != NULL){
		tmp = pre->next;
		pre->next = curr;
		curr = pre;
		pre = tmp;
	}
	head->next = NULL;
	head = curr;
}

void LinkList::Print(){
	LinkNode* p = head;
	while(p != NULL){
		cout<<(p->key)<<" ";
		p = p->next;
	}
	cout<<endl;
	return;
}

bool LinkList::IsLoop(){
	
	LinkNode* pFast = head;
	LinkNode* pSlow = head;
	while(pFast != NULL && pFast->next != NULL){
		pFast = pFast->next->next;
		pSlow = pSlow->next;
		
		if(pFast == pSlow)
			break;
	}	

	if(NULL == pFast || NULL == pFast->next)
		return false;
	else
		return true;
}

void TestIsLoop(void){
	int a[] = {1,2,3,4,5,6,7,8,9};
	int i;
	LinkList link;
	for(i=(sizeof(a)/sizeof(int) - 1); i>=0; i--){
		link.InsertHead(a[i]);
	}
	link.Print();
	link.Reverse();
	link.Print();
	cout<<"Is Loop in LinkList ? "<<link.IsLoop()<<endl;
}

int main(int args, char** argv){
	TestIsLoop();
	return 0;
}













































