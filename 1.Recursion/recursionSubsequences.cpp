#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sub(char input[], char output[], vector<string> &arr,int i, int j, int &count){
	if(input[i] == '\0'){
		output[j] = '\0';
		count++;
		//cout<<output<<endl;
		arr.push_back(output);
 		return;
	}

	output[j] = input[i];

	// sending with variable
	sub(input,output,arr,i+1,j+1,count);

	// sending without variable
	sub(input,output,arr,i+1,j,count);
}

bool compare(const string  s1, const string s2){ // use const when you are 
	return s1 < s2;
	//return s1.length() < s2.length();	
}

int main(){
    int count = 0;
	char input[1000000];
	char output[1000000];
	cin>>input;
	vector<string> arr;
	sub(input,output,arr,0,0,count);
	cout<<count<<endl;
	//sort(arr.begin(),arr.end(),compare); // sorting according to length
	for(int i = arr.size()-1; i >= 0; i--){
		cout<<arr[i]<<" ";
	}
	return 0;
}