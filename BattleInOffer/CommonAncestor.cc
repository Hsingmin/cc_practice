
// Tree.cc

#include <iostream>
#include <stdlib.h>

using namespace std;

template<typename T>
struct Node{
	T key;
	Node * left;
	Node * right;
	Node(T key): key(key), left(NULL), right(NULL){}
};

template<typename T>
class Tree{
	public:
		Tree();
		Tree(T *, size_t, int &);
		~Tree();
		Tree<T> & operator=(Tree<T> &);
		void TreeShow();
		int FindLCA(T a, T b, T &out);
	private:
		Node<T> *root;
};

template<typename T>
Tree<T> & Tree<T>::operator=(Tree<T> &t){
	if(this != &t){
		swap(root, t.root);
	}
	return *this;
}

template<typename T>
Node<T>* CreateTree(T * keys, size_t size, int & index){
	Node<T> *node;
	if(index < size){
		node = new Node<T>(keys[index]);
		if(index/2)
			node->left = CreateTree(keys, size, ++index);
		else
			node->right = CreateTree(keys, size, ++index);
	}
	else
		node = NULL;
	if(node != NULL)
		cout<<"Insert node value = "<<(node->key)<<endl;
	return node;
}

template<typename T>
Tree<T>::Tree(){
	root = NULL;
}

template<typename T>
Tree<T>::Tree(T * keys, size_t size, int & index){
	root = CreateTree(keys, size, index);
}

template<typename T>
void DestroyNode(Node<T> *node){
	if(node != NULL){
		DestroyNode(node->left);
		DestroyNode(node->right);
		delete(node);
	}
	else
		delete(node);
	return;
}

template<typename T>
Tree<T>::~Tree(){
	DestroyNode(root);
}

template<typename T>
void show(Node<T> * node){
	if(node != NULL)
		cout<<"show node : "<<node->key<<endl;
	else
		cout<<"NULL node"<<endl;
	return;
}

template<typename T>
void VisitNode(Node<T> * node, void (*pf)(Node<T> *)){
	if(node != NULL){
		(pf)(node);
		cout<<"--L--"<<endl;
		VisitNode(node->left, show);
		cout<<"--R--"<<endl;
		VisitNode(node->right, show);
	}
	return;
}

template<typename T>
void Tree<T>::TreeShow(){
	VisitNode(root, show);
}

template<typename T>
int LeastCommonAncestor(Node<T> *node, T a, T b, T &out){
	if(node == NULL)
		return 0;
	cout<<"Root key = "<<(node->key)<<endl;
	cout<<"node->left->key = "<<(node->left->key)<<endl;
	cout<<"node->right->key = "<<(node->right->key)<<endl;
	cout<<"Find "<<a<<" and "<<b<<" Common Ancestor. "<<endl;
	if(node->key == a || node->key == b)
		return 1;
	int iLeft = LeastCommonAncestor(node->left, a, b, out);
	cout<<"iLeft = "<<iLeft<<endl;
	if(iLeft == 2)
		return 2;
	
	int iRight = LeastCommonAncestor(node->right, a, b, out);
	cout<<"iRight = "<<iRight<<"node->key = "<<(node->key)<<endl;
	if(iRight == 2)
		return 2;
		
	if(iLeft+iRight == 2)
		out = node->key;
	return iRight+iLeft;
} 

template<typename T>
int Tree<T>::FindLCA(T a, T b, T &out){
	return LeastCommonAncestor(root, a, b, out);
}

int main(int args, char **argv){
	int keys[] = {1,2,3,4,5,6,7,8,9};
	size_t size = sizeof(keys)/sizeof(int);
	int index = 0;
	Tree<int> tree = Tree<int>(keys, size, index);
	tree.TreeShow();
	
	Tree<int> another_tree = Tree<int>();
	another_tree = tree;
	cout<<"another_tree nodes show : "<<endl;
	another_tree.TreeShow();
	int a = 2;
	int b = 3;
	int out = 0;
	cout<<another_tree.FindLCA(a, b, out)<<endl;
	cout<<"Common Ancestor: "<<(out)<<endl;
	return 0;
}



























