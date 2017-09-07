#include <iostream>
#include <vector>
using namespace std;


int main() {

	int n,b;
	int classes[10000000],out[10000000];
	cin>>n>>b;
	for(int i = 0; i < n; i++){
	    cin>>classes[i];
	}

     if(n > b){
          cout<<-1;
     }
     else if(n == b){
          int l  = -1;
          for(int i = 0; i < n; i++){
	         l = max(classes[i],l);
	    }
         cout<<l;
     }
     else{
          int t = 0;
     	for(int i = 0; i < n; i++){
     	    t += classes[i];
     	}

          int av = t/b;

          int cakesLeft = b;
          int i;
          for( i = 0; i < n-1; i++){
               int count = 1;
               while(classes[i]/count > av){
                    count++;
               }
               out[i] = count;
               cakesLeft = cakesLeft - count;
          }

          out[i] = cakesLeft;

          int l = -1;
          for( i = 0; i < n; i++){
               int j = out[i];
               int prev = 0;
               int curr = classes[i];
               while(j > 0){
                    int ans = (curr - prev)/j;
                    curr = curr - prev;
                    prev = ans;
                    l = max(l,ans);
                    j--;
               }
          }
          cout<<l;
     }


	return 0;
}
