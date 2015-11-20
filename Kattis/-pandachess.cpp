/*
TODO https://open.kattis.com/problems/pandachess
Given a graph
Given an order of its node
Use least operations (remove an item / insert an item) to make it a legit topological order
*/

#include <map>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXN = 100001;
int n,m;
map<string, int> rank;
vector<int> edge[MAXN];
int mark[MAXN], current, ans;

void dfs(int u){
	if(u==n){
		ans = max(ans,current);
		return;
	}
	int ub = min(n,n-(ans-current));
	for(int i=u;i<ub;++i) if(!pick[i] && !mark[i]){
		mark[i]=1;
		for(auto &j: edge[i]) mark[j]++;
		current++;
		dfs(u+1);
		for(auto &j: edge[i]) mark[j]--;
		current--;
		mark[i]=0;
	}
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    string list[2*MAXN][2],ins;
    int d;

    cin>>n>>m>>d;
    for(int i=0;i<m;++i) cin>>list[i][0]>>list[i][1]; 
    for(int i=0;i<n;++i){
    	cin>>ins;
    	rank[ins]=i;
    }
    for(int i=0;i<m;++i){
        int a = rank[list[i][0]];
        int b = rank[list[i][1]];

        if(a>=b){
			edge[a].push_back(b);
            edge[b].push_back(a);
        }
    }

    ans=0;
    memset(mark,0,sizeof(mark));
    dfs(0);

    cout<<ans<<endl;
    return 0;
}
