// This problem is also offered on CodeForce Gym http://codeforces.com/gym/100502/
// But the time limit is 9s on Kattis and 1s on CodeForce

#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXN = 200001;
int n,m;
vector<int> edge[MAXN];
int mark[MAXN];
bool flag = true;
int reach = 0;

void populate(int u, int v){
    mark[v]=0-mark[u];
    for(auto &k:edge[v])
        if(mark[k] != 0) {if(mark[v]+mark[k]!=0) flag = false;}
        else populate(v,k);
}

int dfs(int u, int paint){
    int newP = (paint==1);
    ++reach;
    mark[u]=paint;
    for(auto &v : edge[u]) 
        if(mark[v] != 0){
            if(mark[v]+mark[u]!=0) {newP = MAXN;break;}
        }
        else{
            newP += dfs(v,0-mark[u]);
            if(newP>=MAXN) break;
        }
    return newP;
}

void clear(int u){
    mark[u]=0;
    for(auto &v : edge[u]) if(mark[v]!=0) clear(v);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin>>n>>m;
    memset(mark,0,sizeof(mark));
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        if(c==0)
        {
            if(mark[a] == 1 || mark[b] == 1) flag=false;
            else mark[a]=mark[b]=-1;
        }
        else if(c==2)
        {
            if(mark[a] == -1 || mark[b] == -1) flag=false;
            else mark[a]=mark[b]=1;
        }
        else
        {
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
    }

    for(int i=1;i<=n && flag;++i) if(mark[i]!=0 && edge[i].size()) for(auto &j:edge[i])
        if(mark[j] != 0) {if(mark[i]+mark[j]!=0) flag = false;}
        else populate(i,j);

    int ans = 0; 
    for(int i=1;i<=n;++i) if(mark[i]==1) ++ans;

    for(int i=1;i<=n && flag;++i) if(mark[i]==0) 
    {
        reach = 0;
        int cnt0 = dfs(i,-1);
        if(cnt0 >= MAXN) flag = false;
        else{
            int cnt1 = reach - cnt0;
            ans += min(cnt0, cnt1);
        }
    }

    if(flag) cout<<ans<<endl;
    else cout<<"impossible"<<endl;

    return 0;
}
