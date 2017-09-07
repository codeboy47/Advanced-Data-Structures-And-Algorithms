/*Write a program to create a matrix of alternate rectangles of O and X
For N = 5;
Output :    OOOOO
		    OXXXO
		    OXOXO
		    OXXXO
		    OOOOO
*/

#include <iostream>
using namespace std;

int main(){
	int n;
	char arr[1000][1000];
	cin>>n;
	int rs = 0, re = n-1, cs = 0, ce = n-1;
	int j = 0;
	while(rs <= re && cs <= ce){
		for(int i = cs; i <= ce && rs <= re; i++){
			if(j&1)
				arr[rs][i] = 'X';
			else
				arr[rs][i] = 'O';
		}
		rs++;
		for(int i = rs; i <= re && cs <= ce; i++){
			if(j&1)
				arr[i][ce] = 'X';
			else
				arr[i][ce] = 'O';
		}
		ce--;
		for(int i = ce; i >= cs && rs <= re; i--){
			if(j&1)
				arr[re][i] = 'X';
			else
				arr[re][i] = 'O';

			
		}
		re--;
		for(int i = re; i >= rs && cs <= ce; i--){
			if(j&1)
				arr[i][cs] = 'X';
			else
				arr[i][cs] = 'O';
		}
		cs++;	
		j++;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
 
	return 0;
}