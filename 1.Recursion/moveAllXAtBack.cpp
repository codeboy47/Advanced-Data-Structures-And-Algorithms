// "axbxa"  ->  "abaxx"

#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

void moveAllXAtBack(string &str, int count, int i, int j){

	if(j == count || str[i] == '\0'){
		return;
	}

	if(str[i] == 'x'){
		// move x at the back
		int k = i;
		while(str[k+1] != '\0'){
			str[k] = str[k+1];
			k++;
		}
		str[k] = 'x';
		moveAllXAtBack(str,count,i+1,j+1);
		return;
	}

	moveAllXAtBack(str,count,i+1,j);

}


int main(){

	string s;
	cin>>s;

	int count = 0;
	for(int i = 0; i< s.length(); i++){

		if(s[i] == 'x'){
			count++;
		}
	}

	moveAllXAtBack(s,count,0,0);
	cout<<s;
}