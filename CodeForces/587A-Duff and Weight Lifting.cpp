#include <cstdio>
#include <iostream>
#include <map>
#define max(a,b) a>b?a:b
using namespace std;
int n,readi,m;
int ins[1002001] = {0};
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&readi);
        m = max(m,readi);
        ins[readi] ++ ;
    }

    int res = 0;
    for(int i=0;i<=m;++i) if(ins[i])
    {
        res += ins[i]%2;
        if(ins[i]>1)
        {
            ins[i+1] += ins[i]/2;
            m = max(m,i+1);
        }
    }
    printf("%d\n", res);
    return 0;
}