#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n, dp[32][8]={0};

    dp[0][0] = 0;
    dp[1][0] = 1;

    for(int i=1;i<31;++i)
    {
        dp[i+1][0] = dp[i][1]+dp[i][4]+dp[i][7];
        dp[i+1][1] = dp[i][0]+dp[i][6];
        dp[i+1][2] = dp[i][5];
        dp[i+1][3] = dp[i][4];
        dp[i+1][4] = dp[i][0] + dp[i][3];
        dp[i+1][5] = dp[i][2];
        dp[i+1][6] = dp[i][1];
        dp[i+1][7] = dp[i][0];
    }

    while(cin>>n && n>=0)
    {
        cout<<dp[n+1][0]<<endl;
    }
    return 0;
}