// Find median of 2 sorted arrays
// median is average of mid and mid+1 element

#include <iostream>
#include <vector>
using namespace std;

// time complexity O(n)
// can be optimized by using binary search - O(logn)

int getMedian(int arr1[], int arr2[], int n){
	int i = 0, j = 0;
	int count = 0, m1 = -1, m2 = -1;
	while(count <= n){
		if(i == n){
			m1 = m2;
			m2 = arr2[0];
			break;
		}
		if(j == n){
			m1 = m2;
			m2 = arr1[0];
			break;
		}
		if(arr1[i] < arr2[j]){
			m1 = m2;
			m2 = arr1[i];
			i++;
		}else {
			m1 = m2;
			m2 = arr2[j];
			j++;
		}
		count++;
	}
	return (m1+m2)/2;
}

int main(){
	int n;
	cin>>n;
	int arr1[1000], arr2[1000];
	for(int i = 0; i < n; i++){
		cin>>arr1[i];
	}
	for(int i = 0; i < n; i++){
		cin>>arr2[i];
	}
	int ans = getMedian(arr1,arr2,n);

    cout<<ans;
	return 0;
}