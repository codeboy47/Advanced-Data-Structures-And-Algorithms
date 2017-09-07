// Given array find pairs that sum to particular no
// eg : -3 2 0 1 3 6 5 7 8 10 12 and  sum = 7
// pairs are 0,7  -3,10  1,6

// this can be done by brute force : time : O(n^2) , space : O(1)
// by using hashing : time O(n) , space : O(n)
// by sliding window(with the help of 2 iterators) : time : O(nlogn) , space : O(1)

#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

void findPairsUsingSlidingWindow(int *arr, int sum, int n){

	sort(arr, arr+n);
	int s = 0, e = n-1;
	while(s < e){
		if(arr[s] + arr[e] == sum){
			cout<<arr[s]<<" "<<arr[e]<<endl;
			s++;
			e--;
		}
		else if(arr[s] + arr[e] > sum){
			e--;
		}
		else{
			s++;
		}
	}
}

void findPairsUsingHashing(int *arr, int sum, int n){

	unordered_map<int,int> hash;

	for(int i = 0; i < n; i++){
		if(hash.count(arr[i])){
			cout<<hash[arr[i]]<<" "<<arr[i]<<endl;
		}
		else{
			hash[sum-arr[i]] = arr[i];
		}
	}

}

int main(){
	int n, sum;
	cin>>n>>sum;
	int arr[100000];
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}

	findPairsUsingSlidingWindow(arr,sum,n);
	cout<<endl;
	findPairsUsingHashing(arr,sum,n);
	return 0;
}
