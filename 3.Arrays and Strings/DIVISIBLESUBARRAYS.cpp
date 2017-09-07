#include <iostream>
#include <vector>
using namespace std;

// brute force (naive approach) O(n^2)
int divSubArr(int *arr, int n){
	int count = 0, sum = 0;
	for(int i = 0; i < n; i++){
		sum = 0;
		for(int j = i; j < n;j++){
			if((arr[i]+sum)%n==0){
				count++;
			}
			if(j+1 < n)
			sum = sum + arr[j+1];
		}
	}
	return count;
}

// O(n+k) and O(k) space
int divSubArr2(vector<int> &arr, int n, int k){ // n is size of array and k is the divisor
	int *mod = new int[100000000],count = 0;
	for(int i = 0; i < k; i++){
		mod[i] = 0;
	}
	mod[0]++; // this is done to add nos divisible by k itself like 10 divible by 2 or 5 by 5
	// if mod[0] is 1 but is not added in count, hence we increase mod[0] by 1
	int cumulativeSum = 0;
	for(int i = 0; i < n; i++){
		cumulativeSum = (cumulativeSum + arr[i])%k;
		while(cumulativeSum < 0){
		    cumulativeSum = cumulativeSum + k;
		}
        mod[cumulativeSum]++;
	}
	for(int i = 0; i < k; i++){
		count += (mod[i]*(mod[i]-1))/2; 
	}
	return count;
}

int main(){
	int t;
	vector<int> arr;
	//int arr[1000000];
	cin>>t;
	int n;
	while(t--){
		cin>>n;
		for(int i = 0;i < n; i++){
		    int d;
			cin>>d;
			arr.push_back(d);
		}
		cout<<divSubArr2(arr,n,n)<<endl;
	    arr.clear();
	}
	return 0;
}