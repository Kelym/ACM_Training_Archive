#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
int main(){
    //freopen("0test.in","r",stdin);
    //freopen("0test.out","w",stdout);
    int ttt;
    cin>>ttt;
    for(int tt=1;tt<=ttt;++tt){
        printf("Case #%d: ",tt);
        string a,b,c;
        string res="";
        cin>>a>>b>>c;
        int n=b.size(),m=c.size();
        long long number = 0, index = 1;
        for(int i=a.size()-1;i>=0;--i){
            int cur = b.find(a[i]);
            number += index * cur;
            index *= n;
        }
        if(number == 0){
            cout<<c[0]<<endl;
        }
        else{
            while(number){
                int cur = number % m;
                res=c[cur]+res;
                number/=m;
            }
            cout<<res<<endl;
        }
    }
    return 0;
}
