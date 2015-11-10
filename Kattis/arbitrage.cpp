/*
Given n<=200 currencies name and m exchange relationships specified as
    A B a:b
Means pay a units of A to get b units of B;
Find if we can make profit from this.

Previously I was thinking about gcd to preserve precision. 
But it turns out the test data does not require guard against such precision (a,b<=100).
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <sstream>
using namespace std;
#define MAXN 220
int n,m;
map<string, int> ind;
double dis[MAXN][MAXN];

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string name,c1,c2;
    while(cin>>n && n){
        ind.clear();
        int a,b,c,i1,i2;

        for(int i=0;i<n;++i){
            cin>>name;
            ind[name] = i;
            for(int j=0;j<n;++j) dis[i][j]=0.0;
            dis[i][i] = 1.0;
        }
        cin>>m;
        for(int i=0;i<m;++i){
            cin>>c1>>c2;
            getline(cin,name,':');
            stringstream ss(name);
            ss>>a;
            cin>>b;
            i1 = ind[c1];
            i2 = ind[c2];
            dis[i1][i2] = max(dis[i1][i2],(double)b/(double)a);
            
        }
        for(int k=0;k<n;++k)
            for(int i=0;i<n;++i)
                for(int j=0;j<n;++j)
                    dis[i][j]=max(dis[i][j],dis[i][k]*dis[k][j]);

        bool flag = true;
        for(int i=0;i<n;++i) if(dis[i][i]>1.0) flag = false;
        if(flag) cout<<"Ok"<<endl;
        else cout<<"Arbitrage"<<endl;
    }

    return 0;
}   