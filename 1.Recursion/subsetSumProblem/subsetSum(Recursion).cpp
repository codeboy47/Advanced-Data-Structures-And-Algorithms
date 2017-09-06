#include <iostream>
using namespace std;

// this is improved algo for subset problem other than bitmasking but not works for negative numbers

bool subsetSum(int *arr, int n, int sum){
	if(sum == 0){
		return true;
	}
	if(n==0 && sum > 0)	return false;

	// including last element
	if(sum >= arr[n-1]){
		bool ans = subsetSum(arr,n-1,sum - arr[n-1]);
		if(ans == true){
			return true;
		}
	}

	// excluding n-1
	return subsetSum(arr,n-1,sum);
}

int main() {
	int t;
	int arr[10000000];
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cin>>sum;
		for(int i = 0;i < n; i++){
			cin>>arr[i];  // 2 34 1 12 5 4
		}
		cout<<subsetSum(arr,n,sum);
	}
	return 0;    
}
