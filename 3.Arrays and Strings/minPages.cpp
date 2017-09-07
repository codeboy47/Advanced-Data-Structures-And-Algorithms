// time complexity of this program is O(NlogN)

#include <iostream>
using namespace std;

#define ll long long int

bool isValid(ll *arr, ll n, ll m, ll mid){
	ll sum = 0, count = 1;
	for(int i = 0; i < n; i++){
		if(arr[i] > mid){
			return false;
		}
		else if(sum + arr[i] <= mid){
			sum = sum + arr[i];
		}
		else{
			count++;
			sum = arr[i];
			if(count > m){
				return false;
			}
		}
	}

	return true;
}


ll solve(ll *arr, ll n, ll m){

	ll sum = 0;
	for(ll i = 0; i < n; i++){
		sum = sum + arr[i];
	}

	ll s = 0, e = sum;

	ll ans = 0;
	while(s <= e){
		ll mid = (s + e) / 2;
		
		if(isValid(arr,n,m,mid)){
			ans = mid;
			//cout<<s<<" "<<e<<" "
			e = mid - 1;
		}else{
			s = mid + 1;
		}
	}
	
	return ans;
}

int main(){
	ll n, m;
	ll arr[1000000];
	cin>>n>>m;
	for(ll i = 0; i < n; i++){
		cin>>arr[i];
	}
	
	cout<<solve(arr,n,m);
	return 0;
}