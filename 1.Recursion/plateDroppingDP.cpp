// Egg/Plate Dropping Dynamic Programming

#include <iostream>
#include <climits>
using namespace std;

int findMinimumTrials(int x, int n){
	int dp[x+1][n+1];

	
	for(int i = 0; i <= n; i++){
		dp[0][i] = 0;
	}
	
	for(int i = 0; i <= x; i++){
		dp[i][0] = 0;  // we need 0 trials for 0th floor
		dp[i][1] = 1;  // we need only 1 trial for 1st floor i.e. egg breaks or not doesnot matter as trial will always remain 1
	}
    
    for(int i = 0; i <= n; i++){
		dp[1][i] = i; // we always start from 1st floor as we have one egg only
	}
	
	for(int i = 2; i <= x; i++){
		for(int j = 2; j <= n; j++){
			if(i > j){
				dp[i][j] = dp[i-1][j];
			}else{
				int ans = 1000000;
				for(int k = 1; k <= j; k++){
					//				 egg breaks(go below)  egg not break(go up)			
					ans = min(ans,1 + max(dp[i-1][k-1] ,  dp[i][j-k]));
				}
				dp[i][j] = ans;
			}
		}
	}
	/*for(int i = 0; i <= x; i++){
		for(int j = 0; j <= n; j++){
	        cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
	return dp[x][n];
}

int main(){
	
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k; // k is eggs/plates n is floors  
		cout<<findMinimumTrials(k,n)<<endl;
	}

	return 0;
}