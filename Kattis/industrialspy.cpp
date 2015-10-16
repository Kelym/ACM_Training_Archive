#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
#define N 100000000
bool prime[N]={0};
bool selec[10];
string n,cur;
set<int> ins;
void dfs(int pos){
    if(pos>=n.size()) return;
	for(int i=0;i<n.size();++i) if(!selec[i]){
		selec[i]=1;
		cur=cur+n[i];
		ins.insert(atoi(cur.c_str()));
		dfs(pos+1);
		cur.pop_back();
		selec[i]=0;
	}
}
int main(){
	prime[1]=prime[0]=1;
    for(int i=3;i*i<N;){
    	int k=i*2;
    	for(int j=i+k;j<N;j+=k) prime[j]=1;
    	i+=2;
    	while(prime[i] && i*i<N) i+=2;
        }
    int c;
    cin>>c;
    while(c--){
    	cin>>n;
    	cur="";
    	ins.clear();
    	memset(selec,0,sizeof(selec));
    	dfs(0);
    	int res=0;
    	for(auto i:ins){
    		if(i==2) res++;
    		else if(i%2!=0 && !prime[i]) res++;
    	}
    	cout<<res<<endl;
    }
	return 0;
}
