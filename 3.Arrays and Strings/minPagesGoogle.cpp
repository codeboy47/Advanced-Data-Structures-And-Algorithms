#include <iostream>
#define ll long long int
using namespace std;

bool isValid(ll *arr, ll n, ll m, ll mid){


    ll sum = 0;
    ll count = 1;
    for(ll i = 0 ; i < n; i++){

        if(arr[i] > mid){
            return false;
        }

        if(arr[i] + sum <= mid){
            sum += arr[i];
        }

        else if(arr[i] + sum > mid){
            count++;
            sum = arr[i];
        }

        if(count > m){
            return false;
        }

    }

    return true;
}


ll solve(ll *arr, ll n ,ll m){

    ll sum = 0;
    for(ll i = 0; i < n; i++){
        sum += arr[i];
    }


    ll s = 0, e = sum;

    ll ans;

    while(s <= e){
        ll mid = (s + e)/2;
        //cout<<mid<<endl;
        bool flag = isValid(arr,n,m,mid);

        if(flag){
            ans = mid;
            e = mid - 1;
        }

        else{
            s = mid + 1 ;
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
