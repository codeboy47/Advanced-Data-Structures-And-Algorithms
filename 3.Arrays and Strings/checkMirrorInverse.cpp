#include <iostream>
using namespace std;

int main(){
	bool flag = true;
	int n;
	int arr[100000],b[100000];
	cin>>n;
	for(int i = 0; i < n;i++){
		cin>>arr[i];
	}
	for(int i = 0; i < n;i++){
		b[arr[i]] = i;
	}
	for(int i = 0; i < n;i++){
		if(b[i] != arr[i]){
			cout<<"false";
			flag = false;
			break;
		}
	}
	if(flag == true){
		cout<<"true";
	}
}