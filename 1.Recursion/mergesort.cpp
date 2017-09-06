#include <iostream>
#include <vector>
using namespace std;
 
void Merge(vector<int> &left, vector<int> &right, vector<int> &arr){
	int i = 0, j = 0, k = 0;
	while(i < left.size() && j < right.size()){
		if(left[i] <= right[j]){
			arr[k++] = left[i++];
		}else if(left[i] > right[j]){
			arr[k++] = right[j++];
		}
	}
	while(i < left.size()){
		arr[k++] = left[i++];
	}
	while(j < right.size()){
		arr[k++] = right[j++];
	}
}
 
void MergeSort(vector<int> &arr){
	if(arr.size() < 2)	return ; 
	int mid = arr.size()/2;
	vector<int> left(mid,1),right(arr.size() - mid,1);
	int i , j;
	for(i = 0, j = mid; i < mid, j < arr.size(); i++, j++){
		//left.push_back(arr[i]);  for that dont initialize vector as vector<int> left(mid,1)
		left[i] = arr[i];	
		//right.push_back(arr[j]); to do this intialize vector as vector<int> left,right;
		right[j-mid] = arr[j];
	}
	
	MergeSort(left);
	MergeSort(right);
	Merge(left,right,arr);
	left.clear();
	right.clear();
}
 
int main(){
	vector<int> arr = {4,2,1,6,8,5,3,7};
	MergeSort(arr);
	for(int i = 0; i < arr.size(); i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}