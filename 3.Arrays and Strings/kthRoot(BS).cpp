// calculate kth root of n upto 3 decimal places using binary search

#include <iostream>
#include <cmath>
using namespace std;

float kthRootBS(int n, int k, int p){
	float ans;
	int s = 0, e = n/k;
	while(s <= e){
		int mid = (s + e) / 2;
		if(pow(mid,k) == n){
			return mid;
		}
		else if(pow(mid,k) > n){
			e = mid - 1;
		}else{
			s = mid + 1;
			ans = mid;
		}	
	}

	// floating part
	float inc = 0.1;
	for(int i = 0; i < p; i++){
		while(pow(ans,k) <= n){
			ans = ans + inc;
		}
		ans = ans - inc;
		inc = inc/10;
	}
	return ans;
}

int main(){
	int n = 20; 
	int k = 4;
	int p = 3; // p is precision
	float ans = kthRootBS(n,k,p); // ans is 2.114
	cout<<ans;
	return 0;
}