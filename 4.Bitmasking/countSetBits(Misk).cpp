// find no of set bits in no. Ex: 9 or 1001 so ans is 2

#include <iostream>
using namespace std;

// O(less than logN)
int fun1(int n){
	int count = 0;
	while(n > 0){
		count++;
		n = n&(n-1);
	}
	return count;
}

// O(logN)
int fun2(int n){
	int count = 0;
	int temp = n;
	while(temp > 0){
		if(temp&1){
			count++;
		}
		temp >>= 1;
	}
	return count;
}

int main(){
	int n  = 9;
	//cin>>n;
	cout<<fun1(n)<<endl;
	cout<<fun2(n)<<endl;
	return 0;
}