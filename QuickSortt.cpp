#include <iostream>
#include <cmath>

typedef long long ll;
using namespace std;

// phan hoach Hoare

template <class T>
int partition(T A[], int L, int R){
	T pivot = A[L];
	int left = L, right = R;
	while(1){
		while(A[left] < pivot) left++;
		while(A[right] > pivot) right--;
		
		if (left < right) swap(A[left], A[right]);
		else return right;
	}
}

template <class T>
void quickSort(T A[], int L, int R){
	if (L < R){
		int par = partition(A, L, R);
		quickSort(A, L, par-1);
		quickSort(A, par+1, R);
	}
}

int main()
{
	int A[5] = {5, 3, 4, 1, 2};
	
	quickSort(A, 0, 4);
	
	for (int x : A) cout << x << " ";
	
	return 0;
}
