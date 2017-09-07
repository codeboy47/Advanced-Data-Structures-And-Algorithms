#include <iostream>
using namespace std;

void BubbleSort(int *arr, int n){
	for(int i = 0; i <= n-2; i++){
		for(int j = 0; j <= n-2-i; j++){
			if(arr[j] > arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int main(){
	int arr[100000000];
	int n;
	cin>>n;
	for(int i = 0; i <n;i ++)	cin>>arr[i];
	BubbleSort(arr,n);
	for(int i = 0; i < n; i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}