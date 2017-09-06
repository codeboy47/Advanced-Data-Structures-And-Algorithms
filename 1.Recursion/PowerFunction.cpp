#include <iostream>
using namespace std;

int powerFunc(int a, int b){
	if(b == 0){
		return 1;
	}
	else if(b == 1){
		return a;
	}
	else if(b&1){  // b%2 == 1
		int x = powerFunc(a,b/2);
		return a*x*x;
	}
	else{
		int y = powerFunc(a,b/2);
		return y*y;
	}
	
}

int main(){
	int a = 2;
	int b = 9;
	int ans = powerFunc(a,b);
	cout<<ans;
	return 0;
}