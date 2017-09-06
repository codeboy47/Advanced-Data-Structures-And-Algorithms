#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sub(char input[], char output[], vector<string> &arr,int i, int j){
	if(input[i] == '\0'){
		output[j] = '\0';
		//cout<<output<<endl;
		arr.push_back(output);
 		return;
	}

	output[j] = input[i];

	// sending with variable
	sub(input,output,arr,i+1,j+1);

	// sending without variable
	sub(input,output,arr,i+1,j);
}

bool compare(const string  s1, const string s2){ // use const when you are
	return s1 < s2;
	//return s1.length() < s2.length();
}

int main(){
	char input[] = "abc";
	char output[1000];
	vector<string> arr;
	sub(input,output,arr,0,0);
	sort(arr.begin(),arr.end(),compare); // sorting according to length
	for(int i = 0; i < arr.size(); i++){
		cout<<arr[i]<<endl;
	}
	return 0;
}
