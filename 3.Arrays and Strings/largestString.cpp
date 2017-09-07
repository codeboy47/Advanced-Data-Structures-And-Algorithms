#include <iostream>
#include <cstring>
using namespace std;

void findLargest(string arr[], int n){
	string s = "";
	for(int i = 0; i < n; i++){
		if(arr[i].size() > s.size()){
			s = arr[i];
		}
	}
	cout<<s<<endl;
}

int main(){
	//char arr[1000][1000];
	string arr[1000];
	int n;
	cin>>n;
	for(int i = 0; i < n;i++){
		cin>>arr[i];
		//cin.getline(arr[i],1000);
	}
	findLargest(arr,n);
	return 0;
}