#include <iostream>
#include <algorithm>
using namespace std;

// time complexity is O(nlogn) if sorted then O(n)
// other method is to sort smaller array and and for every element of larger array do binary search in 
// smaller array 


int *findIntersection1(int *arr1, int *arr2, int &n){
	int i = 0, j = 0, k = 0;
	//int arr3[10000];  wrong method always send dynamic array to main
	int *arr3 = new int[10000];
	while(i < n && j < n){
		if(arr1[i] == arr2[j]){
			arr3[k++] = arr1[i];
			i++;
			j++; 
		}
		else if(arr1[i] < arr2[j]){
			i++;
		}
		else{
			j++;
		}
	}
	n = k;
	return arr3;
}
/*
int binarySearch(int arr[], int s, int e, int x){
    if (s <= e){
        int mid = (s+e)/2;
 
        if (arr[mid] == x)  return mid;
 
        if (arr[mid] > x) return binarySearch(arr, s, mid-1, x);

        return binarySearch(arr, mid+1, e, x);
    }
 
    // We reach here when element is not present in array
    return -1;
}

// unsorted arrays of diff lengths m and n
void printIntersection2(int arr1[], int arr2[], int m, int n){
    // Before finding intersection, make sure arr1[0..m-1] is smaller
    if (m > n)
    {
        int *tempp = arr1;
        arr1 = arr2;
        arr2 = tempp;
 
        int temp = m;
        m = n;
        n = temp;
    }

    // Now arr1[] is smaller
 
    // Sort smaller array arr1[0..m-1]
    sort(arr1, arr1 + m);
 
    for (int i=0; i<n; i++)
        if (binarySearch(arr1, 0, m-1, arr2[i]) != -1)
            cout << arr2[i] << " ";
}
*/
int main(){
	int n;
	cin>>n;
	int arr1[10000],arr2[10000];
	for(int i = 0; i <n; i++){
		cin>>arr1[i];
	}
	sort(arr1,arr1+n);
	for(int i = 0; i < n; i++){
		cin>>arr2[i];
	}
	sort(arr2,arr2+n);
	int *arr = findIntersection1(arr1,arr2,n);
	cout<<"[";
	int i;
	for(i = 0; i <n-1; i++){
		cout<<arr[i]<<", ";
	}
	if(n != 0)
	    cout<<arr[i];
	cout<<"]";
	return 0;
}