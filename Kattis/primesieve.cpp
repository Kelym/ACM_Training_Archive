#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

vector<int> prime;

void getPrimes(int n)
{
    vector<bool> isComposite(n,0);

    isComposite[0]=isComposite[1]=true;

    for(int i=2;i<=n;++i)
    {
        if(!isComposite[i]) prime.push_back(i);
        for(int j=0;j<prime.size() && i * prime[j] <= n;++j) 
        {
            isComposite[i*prime[j]] = true;
            if(!(i%prime[j])) break;
        }
    }
}

int binarySearch(int n)
{
    int i=0,j=prime.size();
    while(i<j)
    {
        int m = (i+j)/2;
        if(prime[m] < n) i=m+1;
        else if(prime[m]>n) j=m-1;
        else return 1;
    }
    if(prime[i]==n) return 1;
    else return 0;
}

int main()
{

    int n,q;
    cin>>n>>q;
    getPrimes(n);
    cout<<prime.size()<<endl;
    while(q--)
    {
        cin>>n;
        cout<<binarySearch(n)<<endl;
    }
    return 0;
}