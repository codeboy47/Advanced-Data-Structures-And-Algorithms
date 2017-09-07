#include <iostream>
using namespace std;

int main(){
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
		cout<<b[i]<<endl;
	}
}