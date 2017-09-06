#include <iostream>
using namespace std;

int sumOfDigits(char *input, int i){
	if(input[i] == '\0'){
		return 0;
	}
	int sum = input[i] - '0' ;
	sum = sum + sumOfDigits(input,i+1);
	return sum;
}

int main(){
	char str[1000];
	cin>>str;
	cout<<sumOfDigits(str,0);
	return 0;
}