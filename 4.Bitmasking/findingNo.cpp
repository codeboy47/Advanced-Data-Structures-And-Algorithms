// all nos in array are occuring twice except one no. Find that no.

#include <iostream>
using namespace std;

int solve(int *arr, int n){
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans = ans ^ arr[i];
	}
	return ans;
}

int main(){
	int arr[] = {2,3,4,2,4};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<solve(arr,n);
	return 0;
}