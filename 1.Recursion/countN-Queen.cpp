#include <iostream>
using namespace std;

bool canPlace(int board[][100], int n, int rpos, int cpos){
	for(int i = 0; i < n; i++){
		if(board[i][cpos] == 1){
			return false;
		}
	}
	int i,j;
	
	for(i = rpos,j = cpos;i >= 0 && j >= 0; i--,j--){
		if(board[i][j] == 1){
			return false;
		}
	}
	
	for(i = rpos,j= cpos;i >= 0 && j < n; i--,j++){
		if(board[i][j] == 1){
			return false;
		}
	}
	return true;
}

int solve(int board[][100], int n, int i){
	int count = 0;
	if(i >= n){
		return 1;
	}

	for(int j = 0; j < n; j++){
		if(canPlace(board,n,i,j)){
			board[i][j] = 1;
			count = solve(board,n,i+1) + count;	
			
			board[i][j] = 0;
		}
	}
	
	return count;
}

int main(){
	int board[100][100] = {0};
	int n,count;
	cin>>n;
	count = solve(board,n,0);
	cout<<count;
	return 0;
}