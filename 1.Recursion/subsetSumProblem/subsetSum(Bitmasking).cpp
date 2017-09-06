#include <iostream>
using namespace std;

// time complexity is O(n*2^n)

bool subsetSum(int *arr, int n){
	int last = (1<<n) - 1;  // total no of subsets
	for(int i = 1; i <= last; i++){
		int temp = i;
		int sum = 0;
		bool flag = false;
		for(int j = 0; j < n; j++){
			if(temp%2 == 1){
				sum = sum + arr[j];
				flag = true;
			}
			temp = temp>>1;
		}
		if(sum == 0 && flag == true){
			return true;
		}
	}
	return false;
}

int main() {
	int t;
	int arr[100000];
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i = 0;i < n; i++){
			cin>>arr[i]; 
		}
		subsetSum(arr,n)?cout<<"Yes":cout<<"No";
		
	}
	return 0;    
}
