#include <cstdio>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>

int n,C;
int w[5010],h[5010];
int sumw[5010];
bool doable[5010][5010];
int height[5010][5010];
	
#define max(a,b) a>b?a:b

using namespace std;
int main(){
	
	cin>>n>>C;
	for(int i=1;i<=n;++i) cin>>w[i]>>h[i];
	
	sumw[0]=0;
	for(int i=1;i<=n;++i) sumw[i]=sumw[i-1]+w[i];
	
	for(int i=1;i<=n;++i)
	{
		for(int j=i;j<=n;++j) doable[i][j] = ((sumw[j]-sumw[i-1]) <= C);
		height[i][i]=h[i];
		for(int j=i+1;j<=n;++j) height[i][j] = max(height[i][j-1],h[j]);
	}
	long dp[5010];
	dp[0]=0;
	for(int i=1;i<=n;++i)
	{
		dp[i]=2147483647;
		int j=i-1;
		while(j>=0 && doable[j+1][i])  {
			if(dp[j]+height[j+1][i] < dp[i]) dp[i]=dp[j]+height[j+1][i];
			--j;
		}
	}
	
	cout<<dp[n]<<endl;
	
	return 0;
}