#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[10000000],leftMax[10000000],rightMax[10000000];
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	leftMax[0] = arr[0];
	for(int i = 1; i < n; i++){
		leftMax[i] = max(arr[i],leftMax[i-1]);
	}
	rightMax[n-1] = arr[n-1];
	for(int i = n-2; i >= 0; i--){
		rightMax[i] = max(arr[i],rightMax[i+1]);
	}
	int count = 0;
	for(int i = 0; i < n; i++){
		count = min(leftMax[i],rightMax[i]) - arr[i] + count;
	}
	cout<<count;
	return 0;
}