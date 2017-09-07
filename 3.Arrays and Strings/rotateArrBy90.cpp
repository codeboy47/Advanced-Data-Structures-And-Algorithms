#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[1000][1000];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin>>arr[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			int temp = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = temp;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n/2; j++){
			int temp = arr[i][j];
			arr[i][j] = arr[i][n-j-1];
			arr[i][n-j-1] = temp;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}