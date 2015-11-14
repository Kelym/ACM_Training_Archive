#include <cstdio>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
using namespace std;
int r;
string ins[20];
int cost[20][20]={0}, step = 0, ans = 0, optimal = 10000000;
bool used[20] = {0};

void DFS(int u){
	//cout<<step<<": "<<ins[u]<<" "<<ans<<endl;
	if(step == r){
		if(optimal > ans) optimal = ans;
		return ;
	}
	int tmp = ans;
	for(int i = 1; i<=r;++i) if(!used[i] && tmp + cost[u][i] < optimal){
		used[i]=1;
		ans = tmp + cost[u][i];
		step ++;
		DFS(i);
		step --;
		used[i]=0;
		ans = tmp;
	}
	return ;
}

int main(){
	
	cin>>r;
	for(int i=1;i<=r;++i) cin>>ins[i];
	for(int i=1;i<=r;++i) for(int j=1;j<=r;++j){
		int cal = 0;
		for(int t=0;t<ins[j].size();++t) for(int k=0;k<ins[i].size();++k) if(ins[i][k] == ins[j][t]) cal++;
		cost[i][j]=cal;
		//cout<<ins[i]<<" "<<ins[j]<<' '<<cost[i][j]<<endl;
	}
	step = ans = 0;
	DFS(0);
	cout<<optimal<<endl;
	return 0;
}