#include <iostream>
using namespace std;

bool ratInMaze(char maze[][10], int i, int j,int m,int n){
	if(i == m-1 && j == n-1){
		maze[i][j] = '1';
		for(int a = 0; a < m; a++){
			for(int b = 0; b < n; b++){
				cout<<maze[a][b]<<" ";
			}
			cout<<endl;
		}
		return true;
	}
	maze[i][j] = '1';
	if(j+1 < n && maze[i][j+1] != 'X'){
		bool ans = ratInMaze(maze,i,j+1,m,n);
		if(ans == true){
			return true;
		}
	}
	if(i+1 < m && maze[i+1][j] != 'X'){
		bool ans = ratInMaze(maze,i+1,j,m,n);
		if(ans == true){
			return true;
		}
	}

	// backtracking
	maze[i][j] = '0';
	return false;	
}

int main(){
	char maze[10][10] = {
		"0000XX",
		"00XX0X",
		"X000X0",
		"XXX000"	
	};
	cout<<ratInMaze(maze,0,0,4,6);

	return 0;
}