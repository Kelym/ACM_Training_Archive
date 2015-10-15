#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int n,m;
vector< pair<int,int> > list[10001];
vector< int > dis;

void SPFA(int s){
	dis[s]=0;
	queue<int> table;
	table.push(s);
	bool inTable[100001]={0};
	inTable[s]=1;

	int u,v;
	while(!table.empty()){
		u = table.front();
		table.pop();
		inTable[u]=false;
		for(auto& pair : list[u]){
			v = pair.first;
			if(dis[v] > dis[u]+pair.second){
				dis[v] = dis[u]+pair.second;
				if(!inTable[v]){
					table.push(v);
					inTable[v]=true;
				}
			}
		}
	}
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	int tc=0;
	int q,s;
	int u,v,w;

	while(cin>>n>>m>>q>>s && n){
		if(tc++ > 0) cout<<endl;

		dis.clear();
		for(int i=0;i<n;++i){
			dis.push_back(100000000);
			list[i].clear();
		}

		while(m--){
			cin>>u>>v>>w;
			list[u].push_back(make_pair(v,w));
		}

		SPFA(s);

		while(q--){
			cin>>u;
			if(dis[u] == 100000000) cout<<"Impossible"<<endl;
			else cout<<dis[u]<<endl;
		}
	}

	return 0;
}