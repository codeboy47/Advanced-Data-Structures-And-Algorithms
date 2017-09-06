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

bool solve(int board[][100], int n, int i){
	if(i >= n){
		return true;
	}

	for(int j = 0; j < n; j++){
		if(canPlace(board,n,i,j)){
			board[i][j] = 1;
			bool ans = solve(board,n,i+1);	
			if(ans == true){
				return ans;
			}
			board[i][j] = 0;
		}
	}
	
	return false;
}

int main(){
	int board[100][100] = {0};
	int n = 4;
	solve(board,n,0);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			char ch = board[i][j]?'Q':'0';
			cout<<ch<<" ";
		}
		cout<<endl;
	}
	return 0;
}