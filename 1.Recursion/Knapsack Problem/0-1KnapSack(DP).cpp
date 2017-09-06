#include <iostream>
using namespace std;

// 0-1 Knapsack is always done by dp (bottom up approach)
// to do general knapsack we use greedy algorithm

int knapsackDP(int arr[][10000], int totalWt, int n){
	int output[n+1][totalWt+1];
	for(int i = 0; i <= n; i++){
		output[i][0] = 0;
	}
	for(int i = 0; i <= totalWt;i++){
		output[0][i] = 0;
	}
	for(int i = 1; i <= n; i++){ 	// i = 1 because we check for prev row i-1 
		for(int j = 0; j <= totalWt; j++){
			if(arr[i-1][0] > j){
				output[i][j] = output[i-1][j];
			}else{
				// to find max we check if we include that wt(row) or exclude
				// if we exclude simply use previous row result for that col wt
				// if include then value of wt(row) + value of wt(col) - wt(row)
				output[i][j] = max(output[i-1][j],arr[i-1][1] + output[i-1][j - arr[i-1][0]]);
			}
		}
	}
	return output[n][totalWt];
}

int main() {
	int totalWeight; 
	cin>>totalWeight;
	int n;  // no of items
	cin>>n; 
	int arr[10000][10000];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 2; j++){
			// arr[wt][val]
			cin>>arr[i][j];
		}		
	}
	cout<<knapsackDP(arr,totalWeight,n);
	return 0;
}