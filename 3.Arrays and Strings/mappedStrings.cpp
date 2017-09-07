#include <iostream>
#include <vector>
#include <set>

using namespace std;

// j is iterator for output and i is for str
// break problem into 2 parts call with 1st element, after that combine 1st and 2nd element into one letter and call
void print(char *str, char *output, set<string> &ss,int i, int j){
	if(str[i] == '\0'){
		output[j] = '\0';
		string s(output);
		ss.insert(s);
		return;
	} 
	output[j] =  str[i] - '0' + 64;
	print(str,output,ss,i+1,j+1);
	
	if(str[i+1] != '\0'){
		int n = (str[i] - '0') * 10; // dont use output in these calculations it may give right ans but still
		// it is advisable not to use that thing in recursion which gets updated during calls because 
		//output is not same as above output because it has changed in above recursion call instead use str
		// as we are not updating str. This is important thing to note for performing recursion
		n = n + (str[i+1] - '0');
		if(n <= 26){
			output[j] = n + 64;
			print(str,output,ss,i+2,j+1);
		}
	}
}

int main(){
	set<string> ss; // set will store unique string lexiographically
	char str[] = "123",output[1000000];
	//cin>>str;
	print(str,output,ss,0,0);
	set<string>::iterator it;
	for(it = ss.begin(); it != ss.end(); it++){
		cout<<*it<<endl;
	}
}