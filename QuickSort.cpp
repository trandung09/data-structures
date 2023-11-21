#include <iostream>
#include <cmath>

typedef long long ll;
using namespace std;

// phan hoach Lomuto

template <class T>
void swap_(T& x, T &y){
	T tmp = x;
	x = y;
	y = tmp;
}

template <class T>
int partition(T A[], int L, int R){ // phan hoach Lomuto
	T pivot = A[R];
	int i = L-1;
	
	for (int j=L ; j<R ; j++){
		if (A[j] <= pivot){
			i++; // tang bien dem i
			swap_(A[j], A[i]);
		}
	}
	
	swap_(A[i+1], A[R]);
	
	return i+1;
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
	int A[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	quickSort(A, 0, 9);
	
	for (int i=0 ; i<10 ; i++){
		cout << A[i] << " ";
	}
	return 0;
}
