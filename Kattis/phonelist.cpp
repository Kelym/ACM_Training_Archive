#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	int t,n;
	cin>>t;
	string readi;
	vector<string> ins;
	while(t--){
		cin>>n;
		ins.clear();
		for(int i=0;i<n;++i){
			cin>>readi;
			ins.push_back(readi);
		}
		sort(ins.begin(),ins.end());
		//for(int i=0;i<n;++i) cout<<ins[i]<<endl;

		bool flag = false;
		for(int i=0;i<n-1 && !flag;++i) if(ins[i].size() < ins[i+1].size()){
			readi = ins[i+1].substr(0,ins[i].size());
			if(readi == ins[i]) flag=true;
		}
		if(flag) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}