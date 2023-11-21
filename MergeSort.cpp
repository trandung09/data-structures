#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

template <class T>
void Merge(T A[], int i, int k, int j){
	vector<T> B; // mang phu B de luu cac phan tu
	int left = i, right = k+1;
	
	while(left <= k && right <= j){
		if (A[left] < A[right]){
			B.push_back(A[left]);
			left++;
		}
		else{
			B.push_back(A[right]);
			right++;
		}
	}
	
	if (left > k){
		for (int L=right ; L<=j ; L++)
			B.push_back(A[L]);
	}
	else{
		for (int L=left ; L<=k ; L++)
			B.push_back(A[L]);
	}
	
	for (int L=i ; L<=j ; L++) A[L] = B[L-i];
}

template <class T>
void MergeSort(T A[], int i, int j){
	if (i < j){
		int k = 1.0*(i+j)/2;
		MergeSort(A, i, k);
		MergeSort(A, k+1, j);
		Merge(A, i, k, j);
	}
}

int main()
{
	int n; cin >> n;
	int A[n];
	
	for (int i=0 ; i<n ; i++) cin >> A[i];
	
	MergeSort(A, 0, n-1);
	
	for (int i=0 ; i<n; i++) cout << A[i] << " ";
	return 0;
}
