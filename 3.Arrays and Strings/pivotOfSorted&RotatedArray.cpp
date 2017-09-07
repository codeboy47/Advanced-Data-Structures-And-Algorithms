#include <iostream>
using namespace std;

int findingPivot(int *arr, int n){
	int s = 0, e = n - 1;
	while(s <= e){
		int mid = (s + e) / 2;
		if(arr[mid] > arr[mid+1]){
			return mid;
		}
		else if(arr[mid-1] > arr[mid]){
			return mid-1;
		}
		else if(arr[s] > arr[mid]){
			e = mid - 1;
		}
		else if(arr[s] <= arr[mid]){
			s = mid + 1;
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
	int ans = findingPivot(arr,n);
	cout<<ans;
	return 0;
}