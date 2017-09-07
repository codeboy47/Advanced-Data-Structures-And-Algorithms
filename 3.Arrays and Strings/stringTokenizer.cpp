/* String Tokenizer - strtok() function, which separates a given a string about some given delimiters.
 The strtok() function internally maintains a static pointer variable to store the the state of string.
*/
#include <iostream>
#include <cstring>
using namespace std;

#include<iostream>
#include<cstring>
using namespace std;

char * myStrtok(char *str, char *delim){
	
	static char *input ;//static pointer variable that stores the state of string in previous function call
	if(str != NULL){
		input = str;
	}	
	if(input == NULL){
		return NULL;
	}

	char *output = new char[strlen(input)+1];
	int i;
	bool flag = false;
	for(i = 0; input[i] != '\0'; i++){
		int k = i;
		for(int j = 0; j < strlen(delim); j++){
			if(input[k] == delim[j]){
				output[i] = '\0';
				flag = true;
				k++;
				j = -1; // because before condition is checked it iterates(j++) making j equal to 0
			}
		}
		if(flag == true){
			input = input + k ;
			//cout<<"-"<<input[0]<<"-";
			if(input[0] == '\0'){
				input = NULL;
			}
			return output;
		}
		output[i] = input[i];
	}
	output[i] = '\0'; // whole str is finished so put \0 in end of output
	input = NULL; // this is because if whole string is traversed then return NULL when it is called again
	return output;  // returning address of output
}


int main(){
	char input[] = "Hey, this is something new!!";
	char *token = myStrtok(input," ,");
	while(token != NULL){
		cout<<token<<endl;
		token = myStrtok(NULL," ,!"); //NULL tells me jo original string hamne store ki h uska next word extract karke dena h
	}
	return 0;
}