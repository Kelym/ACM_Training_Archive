// https://open.kattis.com/problems/tractor

#include <cstdio>
#include <cstring>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

int ff(vector<bool> src, int pos){
	int res = 0, rad = 1;
	for(int i=0;i<pos;++i){
		if(src[i]) res += rad;
		rad*=2;
	}
	return res;
}

int main(){

	int n,aa,bb;
	cin>>n;
	while(n--){		
		cin>>aa>>bb;
		if(aa<bb) swap(aa,bb);

		int originalA = aa, originalB = bb;

		vector<bool> a,b;
		while(aa){
			a.push_back(aa%2);
			aa/=2;
		}
		while(bb){
			b.push_back(bb%2);
			bb/=2;
		}

		int k = b.size(), kk = 1;
		for(int i=1;i<=k;++i) kk*=2;

		int res = kk - 1;

		int bprime = originalB - kk/2 + 1;
		int aprime = kk/2;

		if(a.size() == b.size()){
			aprime = originalA - kk/2 + 1;
			res+=(aprime+bprime);
		}
		else{
			res += (a.size()-b.size())*(aprime+bprime);
			//cout<<"!"<<res<<endl;
			bool check = true;
			for(int i=a.size()-1;i>=b.size() && check;--i) if(!a[i]) check = false;
			for(int i=b.size()-1;i>=0 && check;--i)
				if(!a[i] && !b[i]){
					check = false;
					break;
				}
				else if(a[i]&&b[i]){
					//cout<<"*"<<i<<endl;
					check = false;
					res+= ff(b,i) + ff(a,i) + 2;
					break;
				}
			if(check) res++;
		}

		cout<<res<<endl;
	}
	return 0;
}