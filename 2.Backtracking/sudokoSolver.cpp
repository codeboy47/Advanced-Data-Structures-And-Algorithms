#include <iostream>
#include <math.h>
using namespace std;


bool canPlace(int arr[][9], int no,int i, int j, int n){
	
	for(int a = 0;a < n;a++){
		if(arr[i][a] == no){
			return false;
		}
	}
	for(int a = 0;a < n;a++){
		if(arr[a][j] == no){
			return false;
		}
	}
	n = sqrt(n);
	i = (i/n)* n;
	j = (j/n)* n;
	
	for(int a = i; a < n + i; a++){
		for(int b = j; b < n + j; b++){
			if(arr[a][b] == no){
				return false;
			}
		}
	}
	return true;
}

bool solveM(int arr[][9],int i, int j, int n){

	if(i >= n){
		return true;
	}

	if(j >= n){
		bool ans = solveM(arr,i+1,0,n);
		return ans;
	}
	if(arr[i][j] !=  0){
		return solveM(arr,i,j+1,n);
	}
	if(arr[i][j] == 0 ){
		int a;
		for(a = 1; a <= n; a++){
			if(canPlace(arr,a,i,j,n)){
				arr[i][j] = a;
				bool ans = solveM(arr,i,j+1,n);
				if(ans == true){
					return true;
				}else{
					arr[i][j] = 0;
				}
			}	
		}
		
	}
	return false;
}

int main(){
	int n = 9;
	int arr[9][9] = {
		/*{0,0,9,0,0,0,7,0,0},
        {0,0,1,0,0,0,9,5,8},
        {0,0,0,0,8,7,0,0,2},
        {5,8,2,3,0,1,4,0,0},
        {1,0,7,4,0,8,3,0,5},
        {0,0,4,2,0,9,8,7,1},
        {3,0,0,8,4,0,0,0,0},
        {2,1,5,0,0,0,6,0,0},
        {0,0,8,0,0,0,5,0,0}*/
		{7,8,0,4,0,0,1,2,0},
		{6,0,0,0,7,5,0,0,9},
		{0,0,0,6,0,1,0,7,8},
		{0,0,7,0,4,0,2,6,0},
		{0,0,1,0,5,0,9,3,0},
		{9,0,4,0,6,0,0,0,5},
		{0,7,0,3,0,0,0,1,2},
		{1,2,0,0,0,7,4,0,0},
		{0,4,9,2,0,6,0,0,7}
	};
	solveM(arr,0,0,9);
	for(int a = 0; a < n; a++){
		for(int b = 0; b < n; b++){
			cout<<arr[a][b]<<" ";
		}
		cout<<endl;
	}
}