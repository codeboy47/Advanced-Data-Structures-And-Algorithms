// Given array find triplets that sum to zero (asked in google)
// eg : 0, -1, 2, -3, 1 and  sum = 0
// triplets are  0 -1 1	   2 -3 1

// this can be done by brute force : time : O(n^3) , space : O(1)
// by sliding window(with the help of 2 iterators) : time : O(n^2) , space : O(1)

#include <iostream>
#include <algorithm>
using namespace std;

void printTripletsSumToZero(int *arr, int n){
	for(int i = 0; i <= n-3; i++){
		int j = i + 1, k = n-1;
		while(j < k){
			if(arr[i]+arr[j]+arr[k] == 0){
				cout<<arr[i]<<", "<<arr[j]<<", "<<arr[k]<<endl;
				j++;
				k--;
			}
			else if(arr[i]+arr[j]+arr[k] > 0){
				k--;
			}
			else if(arr[i]+arr[j]+arr[k] < 0){
				j++;
			}
		}
	}
}

int main(){
	int arr[] = {0, -1, 2, -3, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	sort(arr,arr+n); // O(nlogn)
	printTripletsSumToZero(arr,n);
	return 0;
}