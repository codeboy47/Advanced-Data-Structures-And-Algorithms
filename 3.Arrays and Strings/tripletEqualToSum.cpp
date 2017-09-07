// Given array find triplets that sum to particular no
// eg : 1, 4, 45, 6, 10, 8, 17 and  sum = 22
// triplets are 1,4,17  4,8,10 

// this can be done by brute force : time : O(n^3) , space : O(1)
// by sliding window(with the help of 2 iterators) : time : O(n^2) , space : O(1)

#include <iostream>
#include <algorithm>
using namespace std;

void printTriplets(int *arr, int sum, int n){

	for(int i = 0; i <= n-3; i++){
		int j = i + 1, k = n-1;
		while(j < k){
			if(arr[i]+arr[j]+arr[k] == sum){
				cout<<arr[i]<<", "<<arr[j]<<", "<<arr[k]<<endl;
				j++;
				k--;
			}
			else if(arr[i]+arr[j]+arr[k] > sum){
				k--;
			}
			else{
				j++;
			}
		}
	}
}

int main(){
	int arr[] = {1, 4, 45, 6, 10, 8, 17};
	int n = sizeof(arr)/sizeof(arr[0]);
	int sum = 22;
	sort(arr,arr+n); // O(nlogn)
	printTriplets(arr,sum,n);
	return 0;
}