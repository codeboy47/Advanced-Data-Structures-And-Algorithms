#include <iostream>
using namespace std;

int main(){
	int n;
	int arr[1000000];
	long sum[1000000];
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	for(int i = 0; i < n; i++){
		sum[i] = 0;
		for(int j = 0; j < i;j++){
			if(arr[i] > arr[j]){
				sum[i] = sum[i] + arr[j];
			}
		}
		//cout<<sum[i]<<" ";
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans = ans + sum[i];
	}
	cout<<ans%1000000007;
	return 0;
}