#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

void solve(vector<string> & vs, vector<int> & arr, char * output, int i, vector<string> &ans){
	if(i == arr.size()){
		output[i] = '\0';
		string s(output);
		ans.push_back(s);
		//cout<<output<<endl;
		return;
	}
	for(int j = 0; vs[arr[i]][j] != '\0' ; j++){
		output[i] = vs[arr[i]][j];
		solve(vs,arr,output,i+1,ans);
	}
}

void findNames(vector<string> &vs, vector<string> &output, int i){
	bool flag = false;
	for(int x = 0; x < output.size(); x++){
		for(int i = 0; i < vs.size(); i++){
			int k = 0;
			flag = false;
			for(int j = 0; vs[i][j] != '\0' ; j++){
				if(output[x][k] != vs[i][j] && flag == true){
					flag = false;
					k = 0;
				}
				if(output[x][k] == vs[i][j]){
					k++;
					flag = true;
					if(output[x][k] == '\0'){
						cout<<vs[i]<<endl;
						break;
					}
				}
			}
		}
	}
}

int main(){

	vector<string> vs,ans;
	char output[1000];
	string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
	string searchIn [] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };
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
	solve(vs,arr,output,0,ans);
	for(int i = 0; i < 10;i++){
		vs[i].clear(); 
	}
	for(int i = 0; i < 11;i++){
		vs.push_back(searchIn[i]);
	}
	findNames(vs,ans,0);
	return 0;
}