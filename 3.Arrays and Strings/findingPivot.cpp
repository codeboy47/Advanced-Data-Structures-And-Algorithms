// find pivot element in sorted and rotated array using binary search

#include <iostream>
using namespace std;

int findingPivot(int *arr, int start, int end){
	if(start <= end){
		int mid = (start+end)/2;
		if(arr[mid] > arr[mid+1] ){
			return mid;
		}
		else if(arr[mid-1] > arr[mid]){
			return mid-1;
		}
		else if(arr[start] <= arr[mid]){
			return findingPivot(arr,mid+1,end);
		}else{
			return findingPivot(arr,start,mid-1);
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
	int ans = findingPivot(arr,0,n-1);
	cout<<ans;
	return 0;
}