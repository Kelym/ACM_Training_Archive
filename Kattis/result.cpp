#include <cstdio>
#include <cstring>
#include <sstream>
#include <iostream>
using namespace std;

inline long long cal(long long a, long long b, char sign)
{
    if(sign == '+') return a+b;
    return a*b;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string input;
    long long dp[101][101][2];
    char sign[101];
    while(getline(cin,input) && input!="END")
    {
        stringstream ss(input);
        int n = 0, ins;
        while(ss>>ins){
            dp[n][n][0]=dp[n][n][1]=ins;
            ss>>sign[n];
            ++n;
        }
        for(int k=1;k<n;++k)
            for(int i=0;i<n-k;++i){
                long long dpmin = cal(dp[i][i][0],dp[i+1][i+k][0],sign[i]);
                long long dpmax = cal(dp[i][i][1],dp[i+1][i+k][1],sign[i]);
                long long temp; 
                for(int j=i+1;j<i+k;++j)
                {
                    temp = cal(dp[i][j][0],dp[j+1][i+k][0],sign[j]);
                    if(temp < dpmin) dpmin = temp;
                    temp = cal(dp[i][j][1],dp[j+1][i+k][1],sign[j]);
                    if(temp > dpmax) dpmax = temp;
                }
                dp[i][i+k][0] = dpmin;
                dp[i][i+k][1] = dpmax;
            }
        cout<<dp[0][n-1][0]<<" "<<dp[0][n-1][1]<<endl;
    }
    return 0;
}