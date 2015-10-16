#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int tt,n;
	long long inss,res;
	cin>>tt;
	while(tt--){
		cin>>n;
		res=0;
		for(int i=0;i<n;++i){
			cin>>inss;
			inss%=n;
			res+=inss;
			res%=n;
		}
		if(res) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
