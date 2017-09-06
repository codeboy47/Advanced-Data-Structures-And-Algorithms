#include <iostream>
using namespace std;

void printComb(char *input, char *output, int i ,int j){
	if(input[i] == '\0'){
		output[j] = '\0';
		cout<<output<<endl;
		return;
	}
	
	char ch = input[i] - '0';
	int n  = ch + 64;
	output[j] = n;	  	/// 49('1') - 48('0') + 64 = 65('A') 
	
	printComb(input,output,i+1,j+1);
	
	if(input[i+1] != '\0'){
		n = (ch*10) + (input[i+1] - '0') + 64;
		if(n <= 26+64){
			output[j] = n;
			printComb(input,output,i+2,j+1);
		}
	}
		



}

int main(){
	char str[] = "126";
	char output[1000];
	printComb(str,output,0,0); 
	return 0;
}