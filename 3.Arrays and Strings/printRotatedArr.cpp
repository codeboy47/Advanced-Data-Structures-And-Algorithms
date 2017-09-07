#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin>>arr[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout<<arr[j][n-i-1]<<" ";
		}
		cout<<endl;
	}
	return 0;
}