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
	ans2 = ans1^ans;
	if(ans1 < ans2){
		cout<<ans1<<" "<<ans2;
	}else{
		cout<<ans2<<" "<<ans1;
	}
}

int main(){
	int arr[1000000];
	int n;
	cin>>n;
	for(int i = 0; i < n;i++)   cin>>arr[i];
	solve(arr,n);
	return 0;
}