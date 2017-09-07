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
	int n;
	cin>>n;
	int arr[1000000];
	cout<<solve(arr,n);
	return 0;
}