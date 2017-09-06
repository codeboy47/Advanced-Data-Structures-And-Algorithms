#include <iostream>
#include <set>
using namespace std;

void printPermuations(char *input,set<string> &s,int i){
	if(input[i] == '\0'){
		string str(input);
		s.insert(str);
		//cout<<input<<endl;
		return;
	}
	for(int j = i; input[j] != '\0'; j++){
		swap(input[i],input[j]);
		printPermuations(input,s,i+1);
		swap(input[i],input[j]);
	}
	return;
}

int main(){
	set<string> s;
	char input[] = "aabc";
 	printPermuations(input,s,0);

	for(auto it = s.begin(); it != s.end(); it++){
		cout<<*it<<endl;
	}
	return 0;
}