#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
set<long long> res;
int main(){
	long long n;
	cin>>n;
	long long sqt = sqrt(n);
	for(long long i=1;i<=sqt;++i){
		if(n%i==0){
			res.insert(i-1);
			res.insert(n/(long long)i-1);
		}
	}
	for(auto i:res) cout<<i<<" ";
	cout<<endl;
	return 0;
}
