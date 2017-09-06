#include<iostream>
using namespace std;

int triangle(int n){
	if(n == 0){
		return 0;
	}
	int ans = n + triangle(n-1);
	return ans;
}

int main() {
	int n;
	cin>>n;
	cout<<triangle(n);
	return 0;
}