#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100005;

int n,m,q;
vector<int> edge[MAXN];
vector<int> ppl[MAXN][20];

int father[MAXN][20];
bool visit[MAXN]={0};
int h[MAXN] = {0};

void DFS(int u)
{
    visit[u]=true;
    for(auto &i : edge[u]) if(!visit[i]){
        father[i][0] = u;
        h[i]=h[u]+1;
        DFS(i);
    }
}

vector<int> mergePpl(vector<int> &a, vector<int> &b){
    vector<int> c;
    int i = 0, j = 0;
    while(i < a.size() && j < b.size() && i+j < 10)
    {
        if(a[i]<b[j]) c.push_back(a[i++]);
        else c.push_back(b[j++]);
    }
    while(i < a.size() && i+j < 10) c.push_back(a[i++]);
    while(j < b.size() && i+j < 10) c.push_back(b[j++]);
    return c;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%d%d%d",&n,&m,&q);

    for(int i=1;i<n;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        --a;--b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for(int i=1;i<=m;++i){
        int a;
        scanf("%d",&a);
        --a;
        if(ppl[a][0].size() < 10) ppl[a][0].push_back(i);
        else
        {
            auto maxE = max_element(ppl[a][0].begin(),ppl[a][0].end());
            int dis = distance(ppl[a][0].begin(),maxE);
            if(ppl[a][0][dis] > i) ppl[a][0][dis]=i;
        }
    }

    DFS(0);

    int maxH = *(max_element(h,h+n));
    int lenH = log2(maxH);

    for(int k=1;k<=lenH;++k)
        for(int i=0;i<n;++i) if(h[i] >= (1<<k)){
            father[i][k] = father[father[i][k-1]][k-1];
            ppl[i][k] = mergePpl(ppl[i][k-1],ppl[father[i][k-1]][k-1]);
        }

    while(q--){
        int u,v,x;
        scanf("%d%d%d",&u,&v,&x);
        --u;--v;
        if(h[u]>h[v]) swap(u,v);
        vector<int> res;

        for(int i = lenH; i>=0; --i)
            if(h[v] >= (1<<i) && h[ father[v][i] ] >= h[u]){
                res = mergePpl(ppl[v][i],res);
                v = father[v][i];
            }

        if(v==u){
            res = mergePpl(res, ppl[v][0]);
        }
        else{
            for(int i = lenH; i>=0; --i) if(h[v]>=(1<<i) && father[u][i] != father[v][i]) {
                res = mergePpl(ppl[u][i],res);
                res = mergePpl(ppl[v][i],res);
                u=father[u][i];
                v=father[v][i];
            }
            res = mergePpl(ppl[v][0],res);
            res = mergePpl(ppl[u][0],res);
            res = mergePpl(ppl[father[u][0]][0],res);
        }
        int ans = res.size();
        if(x<ans) ans = x;
        printf("%d",ans);
        for(int i=0;i<ans;++i) printf(" %d", res[i]);
        printf("\n");
    }

    return 0;
}