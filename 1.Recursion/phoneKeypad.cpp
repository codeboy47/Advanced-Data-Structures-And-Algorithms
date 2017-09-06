#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

void solve(vector<string> & vs, vector<int> & arr, char * output, int i){
	if(i == arr.size()){
		output[i] = '\0';
		cout<<output<<endl;
		return;
	}
	for(int j = 0; vs[arr[i]][j] != '\0' ; j++){
		output[i] = vs[arr[i]][j];
		solve(vs,arr,output,i+1);
	}
}

int main(){

	vector<string> vs;
	char output[1000];
	string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
	//string s[] = {"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	for(int i = 0; i < 10;i++){
		vs.push_back(table[i]);
	} 
	//char str[1000];
	string str;
	cin>>str;
	vector<int> arr;
	for(int i = 0; i < str.size(); i++){
		str[i] = str[i] - '0';
		arr.push_back(str[i]);  // 2 3
	}
	solve(vs,arr,output,0);
	return 0;
}