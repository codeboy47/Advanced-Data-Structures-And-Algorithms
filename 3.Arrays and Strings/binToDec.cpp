#include <iostream>
#include <math.h>
using namespace std;

int binToDec(int binNo, int i){
	if(binNo == 0)	return 0;
	
	return pow(2,i)*(binNo&1) + binToDec(binNo/10,i+1);
}

int main() {
	int bin;
	cin>>bin;
	cout<<binToDec(bin,0);    
}
