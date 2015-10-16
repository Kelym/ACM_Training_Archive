#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
int main(){
	long long n;
	vector<int> p;
	cin>>n;
	if(n%2==0){
		int c=0;
		while(n%2==0){c++;n/=2;}
		p.push_back(c);
	}
	long long i=3;
	while(i*i<=n){
		if(n%i==0){
			int c=0;
			while(n%i==0){c++;n/=i;}
			p.push_back(c);
		}
		i+=2;
	}
	if(n%i==0){
		int c=0;
		while(n%i==0){c++;n/=i;}
		p.push_back(c);
	}
	if(n>1) p.push_back(1);
	int res=0;
	for(auto j:p) res+=j;
	printf("%d\n",res);
	return 0;
}
