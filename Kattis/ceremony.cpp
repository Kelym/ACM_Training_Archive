#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int ins[100001];
    int n;
    cin>>n;
    for(int i=0;i<n;++i) cin>>ins[i];
    sort(ins,ins+n);
    
    int blow = 0, res = 0, low = 0, high = n-1;
    while(low<=high)
    {
        if(ins[high] - blow >= high-low+1)
        {
            high --;
            res++;
        }
        else
        {
            blow++;
            res++;
            while(ins[low]<=blow && low <= high) low++;
        }
    }
    cout<<res<<endl;
    return 0;
}