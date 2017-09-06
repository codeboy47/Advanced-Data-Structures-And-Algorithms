#include <iostream>
using namespace std;

// 0-1 Knapsack is always done by dp (top down approach)
// time complexity is exponential O(2^n)

// g4g method
int knapsack(int *wt, int *val, int n, int totalWt)
{
   // Base Case
   if (n == 0 || totalWt == 0)
       return 0;
 
   // If weight of the nth item is more than Knapsack capacity W, then
   // this item cannot be included in the optimal solution
   if (wt[n-1] > totalWt)
       return knapsack(wt, val, n-1, totalWt);
 
   // Return the maximum of two cases: 
   // (1) nth item included 
   // (2) not included
   else return max( val[n-1] + knapsack(wt, val, n-1, totalWt-wt[n-1]),
                    knapsack(wt, val, n-1, totalWt));
}

// my method both are correct 
int knapsackRecursive(int *wt, int *val, int n, int totalWt){
	// base condition
	if(totalWt < 0){
		return -1;
	}
	if(n == 0 || totalWt == 0){
		return 0;
	}

	// including value of wt 
	int ans = knapsackRecursive(wt,val,n-1,totalWt-wt[n-1]);
	if(ans != -1){
		ans = ans + val[n-1];
	}

	// excluding value of wt
	// we want to check which ans gives max value including or excluding wt
	return max(ans, knapsackRecursive(wt,val,n-1,totalWt));

}

int main() {
	int totalWeight; 
	cin>>totalWeight;
	int n;  // no of items
	cin>>n; 
	int wt[10000],val[10000];
	for(int i = 0; i < n; i++){
		cin>>wt[i]>>val[i];
	}
	cout<<knapsackRecursive(wt,val,n,totalWeight);
	return 0;
}