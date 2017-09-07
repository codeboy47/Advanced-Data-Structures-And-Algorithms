#include <iostream>
using namespace std;

void readline(char *str, int size, char delim){
	int i;
	for(i = 0; i < size-1; i++){
		char ch = cin.get();
		if(ch == delim){
			break;
		}
		str[i] = ch;
	}
	str[i] = '\0';
}

int main(){
	char str[10];
	//cin.getline(str,10,'$');
	readline(str,10,'$');
	cout<<str<<endl;
	return 0;
}