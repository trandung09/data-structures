#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

// phan hoach Lomuto

void swap(int& x, int &y){
	int tmp = x;
	x = y;
	y = tmp;
}

int partition(int A[], int L, int R){ // phan hoach Lomuto
	int pivot = A[R];
	int i = L-1;
	
	for (int j=L ; j<R ; j++){
		if (A[j] <= pivot){
			i++; // tang bien dem i
			swap(A[j], A[i]);
		}
	}
	
	swap(A[i+1], A[R]);
	
	return i+1;
}

void quickSort(int A[], int L, int R){
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
