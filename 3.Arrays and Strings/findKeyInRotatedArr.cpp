#include <iostream>
using namespace std;

// 1st find if mid is on left side sorted path or on right sorted part
// let array be 6 7 1 2 3 4 5

int findingKey(int *arr, int n, int key){
	int s = 0, e = n - 1;
	while(s <= e){
		int mid = (s + e) / 2;
		if(arr[mid] == key){
			return mid;
		}
		// to check mid is on left side of array or not i.e 6 7
		else if(arr[s] <= arr[mid]){
			// no check if key is towards start or not
			if(key >= arr[s] && key <= arr[mid]){
				// search on left side of mid
				e = mid - 1;
			}else{
				// search on right side of mid
				s = mid + 1;
			}
		}
		// otherwise mid is on right side of array i.e. 1 2 3 4
		else if(arr[s] > arr[mid]){
			if(key <= arr[e] && key >= arr[mid]){
				// search right of mid
				s = mid + 1;
			}else{
				e = mid - 1;
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
	int ans = findingKey(arr,n,key);
	cout<<ans;
	return 0;
}