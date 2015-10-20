// Sparse Table (RMQ)
// Haven't tested yet #TODO
vector<int> dfsTable;
int h[MAXN], first[MAXN];

void dfs(int u){
    dfsTable.push_back(u);
    for(auto &i : edge[u]) if(first[i] = -1){
        h[i] = h[u]+1;
        first[i] = dfsTable.size();
        dfs(i);
        dfsTable.push_back(u);
    }
}

void preprocess(int root)
{
    h[u] = first[u] = 0;
    dfsTable.clear();
    dfs(root);

    int len = dfsTable.size(), loglen = log2(dfsTable.size());
    for(int i=0;i<len;++i) RMQ[i][0] = dfsTable[i];

    for(int k=1;k<=loglen;++k)
        for(int i=(len - (1<<k));i>=0;--i)
            if(h[ RMQ[i][k-1] ] < h [ RMQ[i+(1<<(k-1))][k-1] ] ) RMQ[i][k] = RMQ[i][k-1];
            else RMQ[i][k] = RMQ[i+(1<<(k-1))][k-1];
}

void lca(int u, int v)
{  
    int fu = first[u], fv = first[v];
    int dis = abs(fu-fv);
    int logdis = log2(dis);
    if(h[ RMQ[fu][logdis] ] < h [ RMQ[fv + 1 - (1<<logdis)][logdis] ] ) return RMQ[fu][logdis];
    else return RMQ[fv + 1 - (1<<logdis)][logdis];
}


// Lazy Sparse Table

void dfs(int u)
{
    
}