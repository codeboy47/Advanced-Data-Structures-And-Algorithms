#include <iostream>
using namespace std;

int main(){
	int n,m; // rows and cols
	int arr[1000][1000];
	cin>>n>>m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin>>arr[i][j];
		}
	}
	int rs = 0, re = n-1, cs = 0, ce = m-1;
	while(rs <= re && cs <= ce){
		for(int i = cs; i <= ce && rs <= re; i++){
			cout<<arr[rs][i]<<" ";
		}
		rs++;
		for(int i = rs; i <= re && cs <= ce; i++){
			cout<<arr[i][ce]<<" ";
		}
		ce--;
		for(int i = ce; i >= cs && rs <= re; i--){
			cout<<arr[re][i]<<" ";
		}
		re--;
		for(int i = re; i >= rs && cs <= ce; i--){
			cout<<arr[i][cs]<<" ";
		}
		cs++;	

	} 
	return 0;
}