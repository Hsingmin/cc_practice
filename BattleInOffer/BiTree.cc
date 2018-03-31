
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct BTNode{
	int key;
	BTNode* left;
	BTNode* right;
};

void del(BTNode* node){
	delete(node);
	return;
}

void visit(BTNode* node){
	if(NULL == node)
		return;
	cout<<(node->key)<<" ";
	return;
}

class BiTree{
	public:
		BiTree();
		BTNode* BTCreate();
		void BTPreOrderTraverse(BTNode* node, void (*pf)(BTNode*));
		void BTInOrderTraverse(BTNode* node, void (*pf)(BTNode*));
		void BTPostOrderTraverse(BTNode* node, void (*pf)(BTNode*));
		int BTSearch(BTNode* node, int key);
		int BTGetSize(BTNode* node);
		int BTGetDeepth(BTNode* node);
		~BiTree();
	private:
		BTNode* root;
};

BiTree::BiTree(){
	root = NULL;
}

BiTree::~BiTree(){
	BTPostOrderTraverse(root, del);
}

BTNode* BiTree::BTCreate(){
	BTNode* node = 0;
	int val = 0;
	cout<<"Input key to create BiTree, -1 to end:"<<endl;
	cin>>val;
	if(-1 == val)
		return NULL;
	node = new BTNode;
	node->key = val;
	node->left = BTCreate();
	node->right = BTCreate();
	return node;
}

void BiTree::BTPreOrderTraverse(BTNode* node, void (*pf)(BTNode*)){
	if(NULL == node)
		return;
	(*pf)(node);
	BTPreOrderTraverse(node->left, (*pf));
	BTPreOrderTraverse(node->right, (*pf));
	return;
}

void BiTree::BTInOrderTraverse(BTNode* node, void (*pf)(BTNode*)){
	if(NULL == node)
		return;
	BTPreOrderTraverse(node->left, (*pf));
	(*pf)(node);
	BTPreOrderTraverse(node->right, (*pf));
	return;
}

void BiTree::BTPostOrderTraverse(BTNode* node, void (*pf)(BTNode*)){
	if(NULL == node)
		return;
	BTPreOrderTraverse(node->left, (*pf));
	BTPreOrderTraverse(node->right, (*pf));
	(*pf)(node);
	return;
}

int BiTree::BTGetSize(BTNode* node){
	if(NULL == node)
		return 0;

	return BTGetDeepth(node->left) + BTGetDeepth(node->right) + 1;
}

int BiTree::BTGetDeepth(BTNode* node){
	int ldeepth;
	int rdeepth;
	
	if(NULL == node)
		return 0;

	ldeepth = BTGetDeepth(node->left);
	rdeepth = BTGetDeepth(node->right);
	return (ldeepth > rdeepth) ? ldeepth+1 : rdeepth+1; 
}

int BiTree::BTSearch(BTNode* node, int val){
	if(NULL == node)
		return 0;
	int cnt = 0;
	if(val == node->key)
		cnt++;
	cnt += BTSearch(node->left, val);
	cnt += BTSearch(node->right, val);
	return cnt;
}

void TestBiTree(void){
	int i;
	BiTree tree;
	BTNode* root;
	root = tree.BTCreate();
	
	//cout<<"Size of BiTree = "<<tree.BTGetSize(root)<<endl;
	//cout<<"Deepth of BiTree = "<<tree.BTGetDeepth(root)<<endl;

	//tree.BTInOrderTraverse(root, visit);

}

int main(int args, char** argv){
	TestBiTree();
	return 0;
}













































