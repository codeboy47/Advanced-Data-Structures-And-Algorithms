#include <iostream>
#include <cstring>
using namespace std;


void uncompressedString1(char* str, char* out, int i){

     if(str[i] == '\0'){
          return ;
     }

     else if(str[i] == 49){
     	for( ; str[i] != '\0'; i++){
     		str[i] = str[i+1];
     	}
     }

     else if(str[i] >= 48 && str[i] < 58){

          int sindex = i;
          int no = 0;
          while(str[i] != '\0' && (str[i] >= 48 && str[i] < 58)){
               no = (no*10) + str[i] - 48;
               i++;
          }

          int l = (no*strlen(out)) + (strlen(str)-i) - strlen(str);

          int eindex = i-1;
          i = sindex;

          while(str[i] != '\0'){
               i++;
          }

          while(i != eindex){
               str[i + l] = str[i];
               i--;
          }

          int k = 0;
          int j = i + l;
          while(sindex <= j){
               str[sindex] = out[k++];
               sindex++;
               if(k == strlen(out)){
                    k = 0;
               }
          }


          for(int a = 0; a < sindex; a++){
               out[a] = str[a];
          }

		  uncompressedString1(str,out,sindex);

     }

     else{
          out[i] = str[i];
          //cout<<out<<endl;
          uncompressedString1(str,out,i+1);
     }

}

void uncompressedString2(char* str, int i){
     if(str[i] == '\0'){
          return ;
     }

     else if(str[i] == 49){
     	for( ; str[i] != '\0'; i++){
     		str[i] = str[i+1];
     	}
     }

     else if(str[i] >= 48 && str[i] < 58){
          int sindex = i;
          int no = 0;
          while(str[i] != '\0' && (str[i] >= 48 && str[i] < 58)){
               no = (no*10) + str[i] - 48;
               i++;
          }

          int eindex = i;
          char out[1000000000];

          int k = 0;
          int i;
          for(i = 0; i < sindex*no; i++){
               out[i] = str[k++];
               if(k == sindex){
                    k = 0;
               }
          }

          int x = i;

          for(int k = eindex; str[k] != '\0'; k++){
               out[i] = str[k];
               i++;
          }

          for( i = 0; out[i] != '\0'; i++){
               str[i] = out[i];
          }
          uncompressedString2(str,x);
     }

     else{

          uncompressedString2(str,i+1);
     }
}

int main(){

     char str1[1000000000],str2[1000000000],out[1000000000];
     cin>>str1;
     strcpy(str2,str1);

     uncompressedString1(str1,out,0);
     cout<<str1<<endl;
     uncompressedString2(str2,0);
     cout<<str2<<endl;

     return 0;
}
