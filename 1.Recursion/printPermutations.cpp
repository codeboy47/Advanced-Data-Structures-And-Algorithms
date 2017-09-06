#include <iostream>
#include <set>
#include <cstring>
using namespace std;

void printPermutations(string str, int i, set<string> &s){

	if(str[i] == '\0'){
		s.insert(str);
		//cout<<str<<endl;
		return;
	}

	for(int j = i; j < str.length(); j++){
		swap(str[i],str[j]);
		printPermutations(str,i+1,s);

		// swap(str[i],str[j]); -> no need to use this because string is like int variable that does not
		// retains its value when we return. However char str[100] (behave somewhat like pointer) if 
		// changed here and when we return we see change in str[] just like static or pointer variable.
		// It does not have that value before calling. It has value which is passed on by its call
	}
}


int main(){

    set<string> s;
	string str;
	cin>>str;
	printPermutations(str,0,s);
	set<string>:: iterator it;
	for(it = s.begin(); it!=s.end(); it++){
	    cout<<*it<<endl;
	}
}
