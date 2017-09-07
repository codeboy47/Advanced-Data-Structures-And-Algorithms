#include <iostream>
using namespace std;

int main(){
	int n,m;
	int arr[100][100];
	cin>>n>>m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin>>arr[i][j];
		}
	}
	int rs = 0, re = n-1, cs = 0, ce = m-1;
	while(cs <= ce){
		for(int i = rs; i <= re; i++){
			cout<<arr[i][cs]<<", ";
		}
		cs++;
		for(int i = re; i >= rs && cs <= ce; i--){
			cout<<arr[i][cs]<<", ";
		}
		cs++;
	}
	cout<<"END";
	return 0;
}