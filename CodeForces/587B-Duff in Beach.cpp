#include <cstdio>
#include <algorithm>
using namespace std;
int n,k;
long long l;
const int MAXN = 1000005;
const int MODANS = 1000000007;
vector<int> ins, a, dp[MAXN];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%d %I64d %d",&n,&l,&k);
    for(int i=0;i<n;++i)
    {
        int readi; 
        scanf("%d",&readi);
        ins.push_back(readi);
        dp[i].resize(k+1,0);
        dp[i][1] = 1;
    }
    a = ins;
    sort(a.begin() , a.end());
    
    for(int i=2;i<=k;++i)
    {
        int sum = 0, jj = 0;
        for(int j=0;j<n;++j)
        {
            while(jj<n && a[jj]<=a[j])
            {
                sum = (sum+dp[jj][i-1]) % MODANS;
                ++jj;
            }
            dp[j][i] = sum;
        }
    }

    long long c = l / n;
    long long t = l % n;
    long long cnt;

    int ans = 0;
    for(int i=0; i<n; ++i)
    {
        int pos = lower_bound(a.begin(), a.end(), ins[i]) - a.begin();
        for(int j=1;j<=k && j<=c;++j)
        {
            cnt = c-j+1;
            if(i<t) cnt++;
            cnt = (cnt % MODANS * (long long) dp[pos][j]) % MODANS;
            ans = ( cnt + ans) % MODANS;
        }
        if(i<t && c+1<=k)
        {
            ans = (ans+dp[pos][c+1]) % MODANS;
        }
    }
    printf("%d",ans);
    return 0;
}