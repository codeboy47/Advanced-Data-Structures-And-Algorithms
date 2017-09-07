#include <iostream>
using namespace std;

void InsertionSort(int *arr, int n){
	for(int i = 1; i <= n-1; i++){
		int j,key = arr[i];
		for(j = i-1; j >= 0 && key < arr[j]; j--){
				arr[j+1] = arr[j];
		}
		arr[j+1] = key;
	}
}

int main(){
	int arr[100000000];
	int n;
	cin>>n;
	for(int i = 0; i <n;i ++)	cin>>arr[i];
	InsertionSort(arr,n);
	for(int i = 0; i < n; i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}