#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int no){
	int x = sqrt(no);
	for(int i = 2; i <= x; i++){
		if(no%i == 0){
			return false;
		}
	}
	return true;
}

int main(){
	int t;
	cin>>t;
	int arr[1000000];
	for(int i = 0; i < 1000000; i++){
		arr[i] = 0;
	}
	int k = 0;
	while(t--){
		int n;
		cin>>n;
		if(arr[n-1] != 0){
			cout<<arr[n-1]<<endl;
		}else{
			int no = 2;
			for(int i = 0; i < n; ){
				if(arr[i] != 0){
					no = arr[i];
					//cout<<no<<"-";
					i++;
				}
				else if(isPrime(no)){
					arr[k] = no;
					//cout<<arr[k]<<" k "<<k;
					k++;
					i++;
				}
				no++;
			}
			cout<<no-1<<endl;
		}
	}
	return 0;
}