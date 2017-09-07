// calculate exact square root upto 3 decimal places using binary search

#include <iostream>
using namespace std;

int sqrtBS(int n, int start, int end){
	int ans;
	if(start == end){
		return start;
	}
	if(start < end){
		int mid = (start + end)/2;
		if(mid*mid == n){
			return mid;
		}
		else if(mid*mid  < n){
			ans = sqrtBS(n,mid+1,end);
		}else{
			ans = sqrtBS(n,start,mid-1);
		}
	}
	return ans;
}

// floating part
float sqrtPrecision(int n, int sqrt, int prec){
	float x = 0.1;
	int i = 0;
	while(i < prec){
		while(sqrt*sqrt < n){
			sqrt = sqrt + x;
		}
		sqrt = sqrt - x;
		x = x/10;
		i++;
	}
	return sqrt;
}

int main(){
	int n = 10;
	int p = 3; // p is precision
	int sqrt = sqrtBS(n,0,n/2);
	cout<<sqrtPrecision(n,sqrt,p);
	return 0;
}