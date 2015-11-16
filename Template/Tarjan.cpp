#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <cstdio>

int n,ind,scc;
vector<int> edge[MAXN];
stack<int> S;
int dfn[MAXN],reach[MAXN],belong[MAXN];
bool inStack[MAXN];

void dfs(int u)
{
    dfn[u]=reach[u]=++ind;
    S.push(u);
    inStack[u]=true;

    for(auto &i : edge[u])
        if(!dfn[i])
        {
            dfs(i);
            reach[u]=min(reach[u],reach[i]);
        }
        else if(inStack[i] && dfn[i]<reach[u])
        {
            reach[u]=dfn[i];
        }
    if(dfn[u]==reach[u])
    {
        ++scc;
        int i = -1;
        while(i != u)
        {
            i = S.top();
            belong[i] = u;
            inStack[i]=false;
            S.pop();
        }
    }
}

void Tarjan()
{
    memset(dfn,0,sizeof(dfn));
    memset(inStack,0,sizeof(inStack));
    ind = scc = 0;
    for(int i=0;i<n;++i) if(!dfn[i]) dfs(i);
}
