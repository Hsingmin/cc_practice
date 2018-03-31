
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;

template<class T>
struct BTNode{
	T key;
	BTNode<T>* left;
	BTNode<T>* right;
	BTNode(T key = T()): key(key), left(NULL), right(NULL){}
};

template<class T>
class BiTree{
	public:
		BiTree(const T & data);
		BiTree<T> & operator=(BiTree<T> t);
		void BiTreeCreate(const T* keys, size_t size, int &index, T &invalid);
		void BiTreePreOrderTraverse();
		~BiTree();
	private:
		BTNode<T>* root;
};

template<class T>
BiTree<T> &BiTree<T>::operator=(BiTree<T> t){
	if(this != &t){
		swap(root, t.root);
	}
	return *this;
}

template<class T>
BiTree<T>::BiTree(const T & data){
	BTNode<T> node = BTNode<T>(data);
	root = &node;
}

template<class T>
void BTNodeDestroy(BTNode<T> *node){
	if(node != NULL){
		BTNodeDestroy(node->left);
		BTNodeDestroy(node->right);
	}
	delete(node);
}

template<class T>
BiTree<T>::~BiTree(){
	BTNode<T> *node = root;
	BTNodeDestroy(node);
	delete(node);
}

template<class T>
BTNode<T>* BTNodeCreate(const T* keys, size_t size, int &index, T &invalid){
	BTNode<T> *node = NULL;
	if(index < size && keys[index] != invalid){
		node = &BTNode<T>(keys[index]);
		node->left = BTNodeCreate(keys, size, ++index, invalid)
		node->right = BTNodeCreate(keys, size, ++index, invalid)
	}
	return node;
}

template<class T>
void BiTree<T>::BiTreeCreate(const T* keys, size_t size, int &index, T &invalid){
	root = BTNodeCreate(keys, size, index, invalid);
}

template<class T>
void vist(BTNode<T> *node){
	if(NULL == node)
		return;
	cout<<node->key<<" ";
	return;
}

template<class T>
void BTNodePreOrderTraverse(BTNode<T> *node, void (*pf)){
	if(NULL == node)
		return;
	(*pf)(node);
	BTNodePreOrderTraverse(node->left, (*pf))
	BTNodePreOrderTraverse(node->right, (*pf))
	return;
}

template<class T>
void BiTree<T>::BiTreePreOrderTraverse(){
	BTNode<T> *node = root;
	BTNodePreOrderTraverse(node, vist);
}

void TestBT(){
	//BTNode<int> bt = BTNode<int>(2);
	//cout<<bt.key<<endl;

	BiTree<int> tree = BiTree<int>(9);
	
}

int main(int args, char** argv){
	TestBT();
	return 0;
}










