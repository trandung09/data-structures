#include <bits/stdc++.h>

using namespace std;

template <class T>
void heapify(T a[], int n, int i) // xay dung maxHeap
{
	int left = 2*i+1;
	int right = 2*i+2;
	int largest = i;
	
	if (left < n && a[left] > a[largest])
		largest = left;
	if (right < n && a[right] > a[largest])
		largest = right;
		
	if (largest != i){
		swap(a[i], a[largest]);
		heapify(a, n, largest);
	}
}

template <class T>
void heapSort(T a[], int n)
{
	// xay dung max heap
	for (int i=n/2-1 ; i>=0 ; i--)
		heapify(a, n, i);
		
	for (int i=n-1 ; i>=0 ; i--){
		swap(a[i], a[0]);
		heapify(a, i, 0);
	}
}

int main()
{
	int a[6] = {6,5,3,4,2,1};
	heapSort(a, 6);
	
	for (int i=0 ; i<6 ; i++)
		cout << a[i] << " ";
	return 0;
}
