#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n,m;
	while(cin>>n>>m && n){
		vector<int> a;
		int res=0,cur=0,ins;
		for(int i=0;i<n;++i){
			scanf("%d",&ins);
			a.push_back(ins);
		}
		a.push_back(-1);
		for(int i=0;i<m;++i){
			scanf("%d",&ins);
			while(cur<n && a[cur]<ins) ++cur;
			if(a[cur]==ins) ++res,++cur;
		}
		cout<<res<<endl;
	}
	return 0;
}
