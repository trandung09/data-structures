#include <iostream>
#ifndef __bnNode__cpp__
#define __bnNode__cpp__

typedef long long ll;
using namespace std;

template <class T>
class bnNode
{
	private:	
		T elem;
		bnNode *parent, *left, *right;
		
	public:
		bnNode(){
			parent = NULL;
			left = NULL;
			right = NULL;
		}
		T& getElem(){ return elem; }
		bnNode<T>* getParent(){ return parent; }
		bnNode<T>*& getParentRef() { return parent; }
		bnNode<T>* getLeft(){ return left; }
		bnNode<T>* getRight(){ return right; }
		void setElem(T elem){ this->elem = elem; }
		void setParent(bnNode<T>* parent){ this->parent = parent; }
		void setLeft(bnNode<T>* left){ this->left = left; }
		void setRight(bnNode<T>* right){ this->right = right; }
		bool hasLeft(){ // kiem tra node co ton tai node trai khong
			if (this->left != NULL) return 1;
			return 0; 
		}
		bool hasRight(){ // kiem tra node co ton tai node phai khong
			if (this->right != NULL) return 1;
			return 0;
		}
};

#ifndef __bnTree__cpp__
#define __bnTree__cpp__

template <class T>
class bnTree
{
	private:
		bnNode<T>* root;
		ll num = 0;
	
	public:
		ll size(){ return num; }
		bool empty(){ return num == 0; }
		bnNode<T>* getRoot(){ return root; }
		bool isRoot(bnNode<T>* node){ 
			return node->getParent() == NULL; 
		}
		bool isInternal(bnNode<T>* node){
			if (node->getLeft() != NULL || node->getRight() != NULL)
				return 1;
			return 0;
		}
		bool isExternal(bnNode<T>* node){
			if (node->getLeft() == NULL && node->getRight() != NULL)
				return 1;
			return 0;
		}	
		void preOder(bnNode<T>* node, void (*visit)(bnNode<T>* p));
		void inOder(bnNode<T>* node, void (*visit)(bnNode<T>* p));
		void postOder(bnNode<T>* node, void (*visit)(bnNode<T>* p));
		bnNode<T>* insert(bnNode<T>* parent, T elem);
		void remove(bnNode<T>*& node);
};

template <class T>
bnNode<T>* bnTree<T>::insert(bnNode<T>* parent, T elem){
	bnNode<T>* par = new bnNode<T>;
	par->setElem(elem);
	par->setParent(parent);
	
	if (parent == NULL) // this->root == NULL
		root = par;
	else if (!parent->hasLeft())
		parent->setLeft(par);
	else{
		if (!parent->hasRight())
			parent->setRight(par);
		else return NULL;
	}
	
	num++;

	return par;
}

template <class T>
void bnTree<T>::remove(bnNode<T>*& node){
	if (node != NULL){
		if (node->hasLeft()) remove(node->getLeft());
		if (node->hasRight()) remove(node->getRight());	
		bnNode<T>* p = node->getParent();
		if (p->getLeft() == node)
			p->setLeft(NULL);
		else p->setRight(NULL);
		num--;
		delete node;
	}
}

template <class T>
void bnTree<T>::preOder(bnNode<T>* node, void (*visit)(bnNode<T>* p)){
	if (node != NULL){
		visit(node);
		preOder(node->getLeft(), visit);
		preOder(node->getRight(), visit);
	}
}

template <class T>
void bnTree<T>::inOder(bnNode<T>* node , void (*visit)(bnNode<T>* p)){
	if (node != NULL){
		inOder(node->getLeft(), visit);
		visit(node);
		inOder(node->getRight(), visit);
	}
}

template <class T> 
void bnTree<T>::postOder(bnNode<T>* node, void (*visit)(bnNode<T>* p)){
	if (node != NULL){
		postOder(node->getLeft(), visit);
		postOder(node->getRight(), visit);
		visit(node);
	}
}

#endif
#endif
