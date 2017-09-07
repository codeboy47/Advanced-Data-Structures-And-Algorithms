// Every element is occurring thrice except for one element

#include <iostream>
#include <cmath>
#define INT_SIZE 32
using namespace std;

int solve(int *arr, int n){
	int ans = 0;
	for(int i = 0; i < INT_SIZE; i++){
		int count = 0;
		for(int j = 0; j < n; j++){
			int temp = arr[j];
			if(temp&1){
				count++;
			}
			arr[j] >>= 1;
		}
		count = count%3;
		//cout<<count<<" ";
		ans = pow(2,i)*count + ans;
	}
	return ans;
}


int main(){
	int arr[] = {12, 1, 12, 3, 12, 1, 1, 2, 3, 2, 2, 3, 7};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<solve(arr,n);
	return 0;
}
