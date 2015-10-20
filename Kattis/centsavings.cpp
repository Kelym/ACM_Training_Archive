#include <cstdio>
#include <cstring>
#include <iostream>
#define min(a,b) a<b?a:b
const int MAXN = 2000000000;
using namespace std;
int roundUp(int cents)
{
    int tail = cents % 10;
    if(tail >= 5) return cents+(10-tail);
    return cents - tail;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int price[2001],sum[2001]={0};
    int dp[2001][22]={0};
    int n,m;

    cin>>n>>m;
    ++m;
    sum[0]=0;
    for(int i=1;i<=n;++i)
    {
        cin>>price[i];
        sum[i]=sum[i-1]+price[i];
        for(int j=1;j<=m;++j) dp[i][j]=roundUp(sum[i]);
        dp[i][0]=MAXN;
    }

    for(int i=1;i<=n;++i)
        for(int k=2;k<=m;++k)
            for(int j=0;j<i;++j)
                dp[i][k] = (min(dp[i][k],dp[j][k-1]+roundUp(sum[i]-sum[j])));
            
    cout<<dp[n][m]<<endl;
    return 0;
}