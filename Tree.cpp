#include <iostream>
#include <list>
#ifndef __treeNode__cpp__
#define __treeNode__cpp__

typedef long long ll;
using namespace std;

template <class T>
class treeNode
{
	private:
		T elem;
		treeNode *parent;
		list<treeNode<T> *> child; // vector <treeNode<T>*> child
		
	public:	
		treeNode(){
			parent = NULL;
		}
		treeNode(T elem){
			this->elem = elem;
			parent = NULL;
		}
		T getElem(){ return elem; }
		treeNode<T>* getParent(){ return parent; }
		treeNode<T>* getChild(){ return child.front(); }
		void setElem(T elem){ this->elem = elem; }
		void insertChild(treeNode<T>* chil){ child.push_back(chil); }
		void setParent(treeNode<T>* parent){ this->parent = parent; }
		list<treeNode<T>*>& get_Child() { return child; }
};

template <class T>
class tree
{
	private:
		treeNode<T>* root;
		ll num = 0;
	
	public:
		tree();
		ll size();
		bool isEmpty();
		treeNode<T>* getRoot();
		bool isRoot(treeNode<T>* node);
		bool isInternal(treeNode<T>* node);
		bool isExternal(treeNode<T>* node);
		treeNode<T>* insert(treeNode<T>* parent, T elem);
		void remove(treeNode<T>* node);
		void preOder(treeNode<T>* , void (*visit)(treeNode<T>*));
		void inOder(treeNode<T>* , void (*visit)(treeNode<T>*));
		void postOder(treeNode<T>* , void (*visit)(treeNode<T>*));
		
		void oder(treeNode<T>* node){ //  = visit
     		cout << node->getElem() << " ";
		}
};

template <class T>
tree<T>::tree(){
	root = NULL;
	num = 0;
}

template <class T>
ll tree<T>::size(){
	return num;
}

template <class T>
bool tree<T>::isEmpty(){
	if (num == 0) return 1;
	return 0;
}

template <class T>
treeNode<T>* tree<T>::getRoot(){
	return root;
}

template <class T> // node co la node goc khong
bool tree<T>::isRoot(treeNode<T>* node){
	return node->getChild() == NULL;
}

template <class T> // node co la node trong khong
bool tree<T>::isInternal(treeNode<T>* node){
	if (node->get_Child().size() > 0) return 1;
	return 0;
}

template <class T> // node co la node ngoai (la) khong
bool tree<T>::isExternal(treeNode<T>* node){
	if (node->get_Child().size() > 0) return 0;
	return 1;
}

template <class T> // them node
treeNode<T>* tree<T>::insert(treeNode<T>* parent, T elem){
	treeNode<T>* par = new treeNode<T>;
	par->setParent(parent);
	par->setElem(elem);
	
	if (parent == NULL) root = par;
	else (parent->get_Child()).push_back(par);
		
	num++; // tang so luong phan tu
	
	return par;
}

template <class T> // xoa node
void tree<T>::remove(treeNode<T>* node){
	if (node != NULL){
		// ung dung dequy
		for (auto x : node.get_Child())
			remove(x);
		num--;
		delete node;
	}
}

template <class T> // duyet tien thu tu
void tree<T>::preOder(treeNode<T>* node, void (*visit)(treeNode<T>* p)){
	if (node != NULL){
		visit(node);
		for (auto x : node->get_Child())
			preOder(x, visit);
	}
}

template <class T> // duyet trung thu tu
void tree<T>::inOder(treeNode<T>* node, void (*visit)(treeNode<T>* p)){
	if (node != NULL){
		inOder(node->getChild(), visit);
		visit(node);
		for (auto x : node->get_Child()){
			if (x == node->getChild()) continue;
			inOder(x, visit); 
		}
	}
}

template <class T> // duyet hau thu tu
void tree<T>::postOder(treeNode<T>* node, void (*visit)(treeNode<T>* p)){
	if (node != NULL){
		for (auto x : node->get_Child())
			postOder(x, visit);
		visit(node);
	}
}

#endif
