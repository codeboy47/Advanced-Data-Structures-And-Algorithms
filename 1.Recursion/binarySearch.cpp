#include <iostream>
using namespace std;

int binarySearch(int *arr, int start, int end, int m){
	if(start <= end){
		int mid = (start + end)/2;

		if(arr[mid] == m) {
			return mid;
		}
		else if(m < arr[mid]){
			return binarySearch(arr,start,mid-1,m);
		}
		else{
			return binarySearch(arr,mid+1,end,m);
		}
	}
	return -1;
}

int main() {
	int n,m;
	int arr[100000000];
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	cin>>m;
	cout<<binarySearch(arr,0,n,m);
	return 0;    
}
