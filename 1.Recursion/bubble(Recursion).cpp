#include <iostream>
using namespace std;

void bubbleSortRecursive(int *arr, int n){
	if(n == 1){
		return;
	}
	for(int i = 0; i < n-1; i++){
		if(arr[i] > arr[i+1]){
			swap(arr[i],arr[i+1]);
		}
	}
	
	bubbleSortRecursive(arr,n-1);
}

int main() {
    int n;
    int arr[1000000];
    cin>>n;
    for(int i = 0; i < n; i++){
    	cin>>arr[i];
    }
    bubbleSortRecursive(arr,n);
    for(int i = 0; i < n; i++){
    	cout<<arr[i]<<" ";
    }
	return 0;
}