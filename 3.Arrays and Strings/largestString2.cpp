// find largest string 
// read n strings from user
// dont use string instead use character array

#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n; // after cin there is \n in buffer so cin.getline will take this 
	// to avoid this use cin.get that takes single character
	cin.get(); // it takes \n
	char str[1000],longest[1000];
	int large = 0;
	for(int i = 0; i < n; i++){
		cin.getline(str,1000); // it takes all characters including spaces unlike cin
		int length = strlen(str);
		if(length > large){
			large = length;
			strcpy(longest,str);
		}
	}
	cout<<endl<<"longest string from n strings is : "<<longest<<endl;
	cout<<"length of longest string is : "<<large<<endl;
	return 0;
}

/*
string str;
to find length use str.size() or str.length()

char str[1000];
then to find length use strlen(str)
*/