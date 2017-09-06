#include <iostream>
using namespace std;

bool subsetSum(int *arr, int n, int sum, int i){
	bool key = false;
	if(sum == 0){
		return true;
	}
	if(i == n && sum > 0)	return false;
	if(sum >= arr[i]){
		sum = sum - arr[i];
		key = true;
		for(int j = i + 1; j < n; j++){
			if(sum >= arr[j]){
				bool ans = subsetSum(arr,n,sum,j);
				if(ans == true ){
					return true;
				}
			}
		}
		if(sum != 0){
			key = false;
			sum = sum + arr[i];
		}
	}
	//if(sum < arr[i]){
	bool ans =  subsetSum(arr,n,sum,i+1);
	if(ans == false && key == true){
		sum = sum + arr[i];	
	}
	return ans;
	//}
	//return false;
}

int main() {
	int t;
	int arr[10000000];
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i = 0;i < n; i++){
			cin>>arr[i];
		}
		cout<<subsetSum(arr,n,9,0);
	}
	return 0;    
}
