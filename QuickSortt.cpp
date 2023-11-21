#include <iostream>
#include <cmath>

typedef long long ll;
using namespace std;

// phan hoach Hoare

template <class T>
int partition(T A[], int L, int R){
	T pivot = A[L];
	int left = L-1, right = R+1;
	
	while(1){ // thuc hien cho den khi left >= right
		do{
			left++;
		}while(A[left] < pivot); // neu A[left] < pivot thi A[left] da o dung vi tri
		
		do{
			right--;
		}while(A[right] > pivot); // neu A[right] > pivot thi A[right] da o dung vi tri
		
		if (left < right) {
			swap(A[left], A[right]);
		}
		else {
			return right; 
		}
	}
}

template <class T>
void quickSort(T A[], int L, int R){
	if (L < R){
		int par = partition(A, L, R);
		quickSort(A, L, par);
		quickSort(A, par+1, R);
	}
}

int main()
{
	int n; cin >> n;
	int A[n];
	for (int i=0 ; i<n ; i++) cin >> A[i];
	quickSort(A, 0, n-1);
	
	for (auto x : A) cout << x << " ";
	
	return 0;
}
