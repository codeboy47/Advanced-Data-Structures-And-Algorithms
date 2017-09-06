#include <iostream>
using namespace std;

void printFibonacci(int n){
	int prev = 0,curr = 1,next;
	for(int i = 0; prev <= n; i++){
		cout<<prev<<endl;
		next = prev + curr;
		prev = curr;
		curr = next;
	}
}

int main(){
	int n;
	cin>>n;
	printFibonacci(n);
	return 0;
}