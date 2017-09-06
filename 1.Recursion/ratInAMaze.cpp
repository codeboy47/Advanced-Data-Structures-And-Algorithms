#include <iostream>
using namespace std;

bool isSafe(int maze[][1000], int x, int y, int m, int n){
    // if (x,y outside maze) return false
    if(x >= 0 && x < m && y >= 0 && y < n && maze[x][y] != 'X')
        return true;
 
    return false;
}

bool ratInMaze(char maze[][1000], int i, int j,int m,int n, bool visited[][1000]){
	if(i == m-1 && j == n-1){
		maze[i][j] = '1';
		return true;
	}
	char ch = maze[i][j];
	maze[i][j] = '1';
	if(isSafe(maze,i,j+1,m,n) == true && visited[i][j+1] == true){
		bool ans = ratInMaze(maze,i,j+1,m,n,visited);
		if(ans == true){
			return true;
		}
	}
	if(isSafe(maze,i+1,j,m,n) == true && visited[i+1][j] == true){
		bool ans = ratInMaze(maze,i+1,j,m,n,visited);
		if(ans == true){
			return true;
		}
	}

	// backtracking
	visited[i][j] = false;
	maze[i][j] = ch;
	return false;	
}

int main(){
    int n , m;
    cin>>n>>m;
	char maze[1000][1000] = {};
	for(int a = 0; a < n; a++){
			for(int b = 0; b < m; b++){
				cin>>maze[a][b];
			}
	}
	bool visited[1000][1000];
	for(int a = 0; a < n; a++){
			for(int b = 0; b < m; b++){
				visited[a][b] = true;
			}
	}
	bool ans = ratInMaze(maze,0,0,n,m,visited);
	char ch;
	for(int a = 0; a < n; a++){
		for(int b = 0; b < m; b++){
		    if(maze[a][b] == 'O' && a == 0 && b == 0){
		        maze[a][b] = '1';
		    }
		    if(maze[a][b] == 'O' && a == n-1 && b == m-1){
		        maze[a][b] = '1';
		    }
			ch = maze[a][b]=='1'?'1':'0';
			cout<<ch<<" ";
		}
		cout<<endl;
	}
	return 0;
}