#include<iostream>
using namespace std;

int merge(int a[],int x[],int y[],int s,int e){
    int i = s;
    int mid = (s+e)/2;
    int j = mid+1;
    int k = s;
    int count = 0;
    while(i<=mid && j<=e){
        if(x[i]<= y[j]){
            a[k++] = x[i++];
        }
        else{
            count = count + mid - i + 1;
            a[k++] = y[j++];
        }
    }

    while(i<=mid){
        a[k++] = x[i++];
    }
    while(j<=e){
        a[k++] = y[j++];
    }
    return count;
}

int mergeSort(int a[],int s,int e){
    ///Base Case
    int ans = 0;
    if(s>=e){
        return 0;
    }
    ///Rec Case
    /// Divide into two parts
    int x[100000],y[100000];

    int mid  = (s+e)/2;

    for(int i=0;i<=mid;i++){
        x[i] = a[i];
    }
    for(int i=mid+1;i<=e;i++){
        y[i] = a[i];
    }
    /// Sort them recursively
    ans = mergeSort(x,s,mid);
    ans +=mergeSort(y,mid+1,e);

    ///Merge the sorted arrays
    ans += merge(a,x,y,s,e);
    return ans;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int a[1000000];
        int n;
        cin>>n;
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        int ans = mergeSort(a,0,n-1);
        cout<<ans<<endl;

        /*for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }*/
    }
return 0;
}
