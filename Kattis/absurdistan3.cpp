/*

*/

#include <cstdio>
#include <vector>
using namespace std;

#define MAXN 100001

int n;
vector<int> has[MAXN];
int connect[MAXN],belongs[MAXN];
int take[MAXN];
bool path[MAXN];

bool match(int i){
    path[i]=true; // May not be optimal
    for(auto &j:has[i]){
        if(belongs[j]==-1){
            belongs[j]=i;
            take[i]=j;
            path[i]=false; // May not be optimal
            return true;
        }
        else{
            int other = belongs[j];
            if(!path[other] && match(other)){
                belongs[j]=i;
                take[i]=j;
                path[i]=false; // May not be optimal
                return true;
            }
        }
    }
    path[i]=false;
    return false;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    
    for(int i=1;i<=n;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        has[a].push_back(i);
        has[b].push_back(i);
        connect[i]=a+b;
        take[i]=belongs[i]=-1;
        path[i]=0;
    }
    for(int i=1;i<=n;++i) if(take[i]==-1){
        match(i);
    }
    for(int i=1;i<=n;++i){
        printf("%d %d\n",belongs[i],connect[i]-belongs[i]);
    }
    return 0;
}