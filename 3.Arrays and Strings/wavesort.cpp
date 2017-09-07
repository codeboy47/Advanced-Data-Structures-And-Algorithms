#include <iostream>
using namespace std;

void wave(int *arr, int n){
	for(int i = 0; i < n-1; i++){
		if(i%2==0 && arr[i] < arr[i+1]){
			swap(arr[i],arr[i+1]);
		}
		if(i%2==1 && arr[i] > arr[i+1]){
			swap(arr[i],arr[i+1]);
		}
	}
	for(int i = 0; i <= n-1; i++){
		cout<<arr[i]<<" ";
	}
}

int main(){
	int arr[] = {1,4,2,6,8,9};
	int n = 6;
	wave(arr,n);
	return 0;
}