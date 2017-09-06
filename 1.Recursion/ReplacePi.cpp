#include <iostream>
using namespace std;

void ReplacePi(char *str, int i){
	if(str[i] == '\0' || str[i+1] == '\0'){
		return; 
	}
	else if(str[i] == 'p' && str[i+1] == 'i'){
		int j = i + 2;
		while(str[j] != '\0'){
			j++;
		}
		str[j+2] = '\0';
		while(j > i+2){
			str[j+1] = str[j-1];
			j--;
		}
		str[i] = '3';
		str[i+1] = '.';
		str[i+2] = '1';
		str[i+3] = '4';
		ReplacePi(str,i+4);
	}
	else 
		ReplacePi(str,i+1);

}

int main(){
	char str[1000] = "xpipypiipipi";
	ReplacePi(str, 0);
	cout<<str;
	return 0;
}