#include <iostream>
#include <algorithm>
using namespace std;

// time complexity is O(n^2)
// it can be optimized to O(nlogn) using mergesort
int findingArrayCost(int *arr, int n){
	int count = 0;
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			if(arr[i] > arr[j]){
				count++;
			}
		}
	}
	return count;
}


int main(){
	int t;
	int arr[100000000];
	int n;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i = 0; i <n;i ++)	cin>>arr[i];
		//sort(arr,arr+n);
		cout<<findingArrayCost(arr,n)<<endl;
		
	}
	return 0;
}