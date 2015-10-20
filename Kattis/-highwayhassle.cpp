/*
TODO https://open.kattis.com/problems/highwayhassle
N nodes, M edges and S from N nodes are gas stations, tank hold up to T units of gas.
Each edge consume certain amount of gases.
Give the price of gas at each station and a starting point + ending point.
Find the min pay.
*/
#include <cstdio>
#include <cstring>
#include <utility>
#include <iostream>
using namespace std;
int isStation[1001];
vector< pair<int,int> > connect[1001];
vector< map<int,int> > dp[1001];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int tc = 0;
    cin>>tc;
    while(tc--)
    {
        int n,m,stations,p,S,T;
        cin>>n>>m>>stations>>p;
        for(int i=1;i<=n;++i) connect[i].clear();
        memset(isStation,0,sizeof(isStation));
        while(m--)
        {
            int a,b,c;
            cin>>a>>b>>c;
            connect[a].push_back(make_pair(b,c));
            connect[b].push_back(make_pair(a,c));
        }
        while(s--)
        {
            int x,p;
            cin>>x>>p;
            isStation[x]=p;
        }

    }
   
    return 0;
}