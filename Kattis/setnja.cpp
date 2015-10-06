#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int radix = 1000000;
void mult(int *value, int &len, int multiplier){
	int carryOver = 0;
	for(int i=0;i<len;++i){
		value[i]=value[i]*multiplier + carryOver;
		carryOver = value[i]/radix;
		value[i]%=radix;
	}
	while(carryOver){
		value[len++]=carryOver%radix;
		carryOver/=radix;
	}
}

void add(int *a, int aLen, int *b, int bLen){
	int carryOver = 0;
	int i=0;
	for(;i<aLen && i<bLen;++i){
		a[i]+=b[i]+carryOver;
		carryOver=a[i]/radix;
		a[i]%=radix;
	}
	if(aLen<bLen){
		while(i<bLen){
			a[aLen++] = carryOver + b[i];
			carryOver=a[aLen]/radix;
			a[aLen]%=radix;
		}
	}
	else{
		while(i<aLen && carryOver){
			a[i]+=carryOver;
			carryOver=a[i]/radix;
			a[i]%=radix;
			i++;
		}
		while(carryOver){
			a[aLen++]=carryOver%radix;
			carryOver/=radix;
		}
	}
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	string line;
	cin>>line;

	int value[10000] = {0};
	int division[10000] = {0};
	int lenV = 1, lenD = 1;
	value[0]=1;
	division[0]=1;

	for(int pos=0;pos<line.size();pos++){

		if(line[pos]=='L' || line[pos]=='R'){
			mult(value,lenV,2);
		}
		if(line[pos]=='*'){
			mult(value,lenV,5);
		}
		if(line[pos]=='R' || line[pos]=='*'){
			add(value,lenV,division,lenD);
		}
		if(line[pos]=='*') mult(division,lenD,3);
	}
	cout<<value[lenV-1];
	for(int i=lenV-2;i>=0;--i) printf("%06d",value[i]);
	
	return 0;
}