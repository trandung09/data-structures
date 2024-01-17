#include <vector>	
#include "compare.cpp"

#include <algorithm>
	
#ifndef priority_queue_cpp
#define priority_queue_cpp

using namespace std;
	
template <class T, class Compare>
class PriorityQueue
{
private:
	vector<T> heap;
	Compare compare;
		
public:
	PriorityQueue(){ }
		
	void push(T elem){
		heap.push_back(elem);
		heapify_up(heap.size()-1);
	}
		
	void pop(){
		if (!heap.empty()){
			swap(heap[0], heap[heap.size()-1]);
			heap.pop_back();
			heapify_down(0);
			
		} else return;
	}
		
	T top(){ return heap.front(); }
	int size(){ return heap.size(); }	
	bool empty(){ return heap.empty(); }
	
private:	
	void heapify_down(int index);
	void heapify_up(int index);
};
	
template<class T, class Compare>
void PriorityQueue<T, Compare>::heapify_down(int index) // update dong khi xoa phan tu dau tien
{
	int left = 2*index+1; 
	int right = 2*index+2; 
	int tmp = index;
	
	if (left < heap.size() && compare(heap[left], heap[tmp]))
		tmp = left;
		
	if (right < heap.size() && compare(heap[right], heap[tmp]))
		tmp = right;
		
	if (tmp != index){
		swap(heap[index], heap[tmp]);
		heapify_down(tmp);
	}
}
	
template<class T, class Compare>
void PriorityQueue<T, Compare>::heapify_up(int index) // update dong khi them mot phan tu va heap
{
	while(index > 0){
		int parent = 1.0*(index-1)/2;
		if (compare(heap[index], heap[parent])){
			swap(heap[parent], heap[index]);
			index = parent;
		}
		else break;
	}
}

#endif