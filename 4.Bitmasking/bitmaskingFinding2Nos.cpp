// all nos are occuring twice except 2 nos, Find these nos

#include <iostream>
using namespace std;

void solve(int *arr, int n){
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans = ans ^ arr[i];
	}
	int pos = 0;
	int temp = ans;
	//cout<<ans<<endl;
	while(temp > 0){
		if(temp&1){
			break;
		}
		pos++;
		temp >>= 1;
	}
	int ans1 = 0;
	int ans2 = 0;
	for(int i = 0; i < n; i++){
		temp = arr[i];
		temp >>= pos;
		if(temp&1){
			ans1 = ans1 ^ arr[i];
		}
	}
	cout<<ans1<<endl;
	ans2 = ans1^ans;
	cout<<ans2<<endl;
}

int main(){
	int arr[] = {6,1,3,5,1,3,2,6};
	int n = sizeof(arr)/sizeof(arr[0]);
	solve(arr,n);
	return 0;
}
