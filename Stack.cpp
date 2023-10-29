//cai dat stack bang mang
#include<bits/stdc++.h>
#ifndef stack__cpp
#define stack__cpp

typedef long long ll;
using namespace std;

template <class T>
class Stack
{
	ll num,cap; //cap-suc chua, num-size hien tai
	T *elem;
	public:
		Stack() {
			num=cap=0;
			elem=NULL;
		}
		
		ll size() {return num;}
		bool empty() {return num==0;}
		
		T &top() {
			return elem[num-1];
		}
		
		void pop() { 
			if (num > 0) num--;
		}
		
		void push(T x)
		{
			if(cap==num)
			{
				cap=cap?cap*2:1;
				T *tem=new T[cap]; 
				for(ll i=0;i<num;i++) tem[i]=elem[i];
				if(elem) delete []elem;
				elem=tem;
			}
			elem[num++] = x; 
		}
		
		void clear() {num=0;}
};