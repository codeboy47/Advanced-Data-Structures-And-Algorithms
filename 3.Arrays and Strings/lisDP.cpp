#include <iostream>
using namespace std;

// this is bottom up dynamic programming
// time complexity is O(n^2)

int lis(int *arr, int n){
	int dp[1000];
	for(int i = 0; i <n; i++){
		dp[i] = 0;
	}
	int large;
	for(int i = n-1;i >= 0; i--){
		large = 0;
		for(int j = i + 1; j < n; j++){
			if(arr[i] < arr[j]){
				large = max(large,dp[j]);
			}
		}
		dp[i] = large + 1;
	}
	large = 0;
	for(int i = 0; i < n; i++){
		large = max(large,dp[i]);
	}
	return large;
}

int main(){
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Length of lis is "<<lis( arr, n )<<endl;
    return 0;
}