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
vector< int > dis, rec;

void SPFA(int s){
	dis[s]=0;
	rec[s]=1;
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
				rec[v] = rec[u];
				if(!inTable[v]){
					table.push(v);
					inTable[v]=true;
				}
			}
			else if(dis[v] == dis[u]+pair.second){
				rec[v]+=rec[u];
			}
		}
	}
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int u,v,w;

	cin>>n>>m;
	for(int i=0;i<n;++i){
		dis.push_back(10000000);
		rec.push_back(0);
	}

	while(m--){
		cin>>u>>v>>w;
		list[u].push_back(make_pair(v,w));
	}

	int s,t;
	cin>>s>>t;
	SPFA(s);
	cout<<rec[t]<<endl;

	return 0;
}