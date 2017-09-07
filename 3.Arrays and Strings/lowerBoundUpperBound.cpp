#include <iostream>
using namespace std;

// lower bound
int firstOcc(int *arr, int n, int key){
	int s = 0, e = n-1;
	while(s <= e){
		int mid = (s + e)/2;
		if(arr[mid] == key){
			if(mid == 0 || arr[mid-1] < key){
				return mid;
			}
			if(arr[mid-1] == key){
				e = mid - 1;
			}
		}
		else if(arr[mid] > key){
			e = mid - 1;
		}
		else{
			s = mid + 1;
		}
	}
	return -1;
}

// upper bound
int lastOcc(int *arr, int n, int key){
	int s = 0, e = n-1;
	while(s <= e){
		int mid = (s + e)/2;
		if(arr[mid] == key){
			if(mid+1 == n || arr[mid+1] > key){
				return mid;
			}
			if(arr[mid+1] == key){
				s = mid + 1;
			}
		}
		else if(arr[mid] > key){
			e = mid - 1;
		}
		else{
			s = mid + 1;
		}
	}
	return -1;
}

int main(){
	int a[] = {1,1,2,2,2,2,4,4};
    int n = sizeof(a)/sizeof(a[0]);
    int key = 2;

    int ans = firstOcc(a,n,key);
    cout<<"First occ of 2 is  "<<ans<<endl;
    cout<<"Last occ of 2 is "<<lastOcc(a,n,key)<<endl;
    cout<<"First occ of 3 is  "<<firstOcc(a,n,3)<<endl;

	return 0;
}