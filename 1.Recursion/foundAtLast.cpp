#include <iostream>
using namespace std;

int foundAtLast(int *arr, int n, int m){
	if(n == 0)	return -1;
	if(arr[n-1] == m){
		return n-1;
	}
	int ans = foundAtLast(arr,n-1,m);

	return ans;
}

int main() {
	int n;
	int arr[10000];
	cin>>n;
	for(int i = 0; i <n;i++){
		cin>>arr[i];
	}
	int m;
	cin>>m;
	cout<<foundAtLast(arr,n,m);
	return 0;    
}
