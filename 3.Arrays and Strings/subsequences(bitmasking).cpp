#include <iostream>
#include <cstring>
using namespace std;

void subsequences(char *str, int n, int len){
	for(int i = 0; i <= n; i++){
		int temp = i;
		for(int j = 0; j < len;j++){
			if(temp&1){
				cout<<str[j];
			}
			temp >>= 1;
		}
		cout<<endl;
	}
}

int main(){
	char str[100];
	cin>>str;
	int len = strlen(str);
	int n = (1<<len) - 1;
	subsequences(str,n,len);
	return 0;
}