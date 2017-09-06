#include <iostream>
using namespace std;

void Replace(char *str, int i){
	if(str[i] == '\0' || str[i+1] == '\0' || str[i+2] == '\0' || str[i+3] == '\0'){
		return; 
	}
	else if(str[i] == '3' && str[i+1] == '.' && str[i+2] == '1' && str[i+3] == '4'){
		int j = i+4;
		while(str[j] != '\0'){
			str[j-2] = str[j];
			j++;
		}
		str[j-2] = str[j];
		str[i] = 'p';
		str[i+1] = 'i';
		Replace(str,i+2);
	}
	else 
		Replace(str,i+1);

}

int main(){
	int n;
	cin>>n;
	char str[1000];
	while(n--){ 
		cin.getline(str,1000,'$');  // consider spaces
		//cin>>str; // dont consider spaces
		Replace(str,0);
		cout<<str<<endl;
	}
	return 0;
}