#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <cstdio>
using namespace std;
#define MAXN 20010

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

int T,m;
bool inEdge[MAXN],outEdge[MAXN];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        for (int i=0;i<n;i++) edge[i].clear();
        int u,v;
        while(m--)
        {
            scanf("%d%d",&u,&v);
            edge[--u].push_back(--v);
        }
        Tarjan();
        memset(inEdge,0,sizeof(inEdge));
        memset(outEdge,0,sizeof(outEdge));
        for(int i=0;i<n;++i)
            for(auto &j : edge[i])
                if(belong[i] != belong[j])
                {
                    outEdge[belong[i]]=1;
                    inEdge[belong[j]]=1;
                }
        int ans = 0, noInEdge = 0, noOutEdge = 0;
        for(int i=0;i<n;++i)
            if(belong[i]==i)
            {
                if(inEdge[i]==0) ++noInEdge;
                if(outEdge[i]==0) ++noOutEdge;
            }
        ans = max(noInEdge,noOutEdge);
        if(scc == 1) ans = 0;
        printf("%d\n",ans);
    }
    return 0;
}