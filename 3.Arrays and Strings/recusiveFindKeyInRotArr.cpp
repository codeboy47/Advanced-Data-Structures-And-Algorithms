#include <iostream>
using namespace std;

// 1st find if mid is on left side sorted path or on right sorted part
// let array be 6 7 1 2 3 4 5

int recursivelyFindKey(int *arr,int s, int e, int key){
	if(s <= e){
		int mid = (s + e) / 2;
		if(arr[mid] == key){
			return mid;
		}
		// to check mid is on left side of array or not i.e 6 7
		if(arr[s] <= arr[mid]){
			// no check if key is towards start or not
			if(key >= arr[s] && key <= arr[mid]){
				// search on left side of mid
				return recursivelyFindKey(arr,s,mid-1,key);
			}else{
				// search on right side of mid
				return recursivelyFindKey(arr,mid+1,e,key);
			}
		}
		// otherwise mid is on right side of array i.e. 1 2 3 4
		if(arr[s] > arr[mid]){
			if(key <= arr[e] && key >= arr[mid]){
				// search right of mid
				return recursivelyFindKey(arr,mid+1,e,key);
			}else{
				return recursivelyFindKey(arr,s,mid-1,key);
			}
		}
	}
	return -1;
}

int main(){
	int n;
	cin>>n;
	int arr[1000000];
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	int key;
	cin>>key;
	int ans = recursivelyFindKey(arr,0,n-1,key);
	cout<<ans;
	return 0;
}