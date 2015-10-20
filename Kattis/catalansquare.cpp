#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

vector<int> res;
const int radix = 10;

void highMulti(int m)
{
    int carryOver = 0;
    for(int i=0;i<res.size();++i)
    {
        res[i]=res[i]*m+carryOver;
        carryOver = res[i] / radix;
        res[i] %= radix;
    }
    while(carryOver)
    {
        res.push_back(carryOver%radix);
        carryOver/=radix;
    }
}

void highDivide(int m)
{
    int carryOver = 0;
    for(int i=res.size()-1; i>=0; --i)
    {
        res[i] += carryOver*radix;
        carryOver = res[i]%m;
        res[i]/=m;
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;
    cin>>n;
    ++n;

    res.push_back(1);

    for(int i=n+2;i<=2*n;++i) highMulti(i);
    for(int i=2;i<=n;++i) highDivide(i);

    int i=res.size()-1;
    while(res[i] == 0) --i;
    while(i>=0)
    {
        printf("%d",res[i]);
        --i;
    }
    return 0;
}
