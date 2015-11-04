#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int target[10000000] = {0};
int direction[10000000] = {0};
char a[10000005],b[10000005];

int execsubstr(int begin, int end)
{
    if(begin == end) return 0;
    int minel = 26;
    for(int i=begin;i<end;++i) if(minel > target[i]) minel = target[i];
    for(int i=begin;i<end;++i) target[i]-=minel;
    int res = minel, i=begin;
    while(i<end){
        while(i<end && target[i] == 0) ++i;
        int left = i;
        while(i<end && target[i] > 0) ++i;
        int right = i;
        res+=execsubstr(left,right);
    }
    //cout<<begin<<" "<<end<<" = " <<res<<endl;
    return res;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    char ins;
    int n =0;
    while(scanf("%c",&ins) && ins!=' '){
        a[n++]=ins;
    }
    int tt = 0;
    while(scanf("%c",&ins) != EOF){
        b[tt++]=ins;
    }

    for(int i=0;i<n;++i){
        target[i] = abs(b[i]-a[i]);
        if(b[i]-a[i] > 0) direction[i]=1;
        else if(b[i]-a[i]<0) direction[i]=-1;
    }

    int i = 0, res = 0;
    while(i<n){
        while(i<n && target[i] == 0) ++i;
        int start = i;
        while(i<n && direction[i] == direction[start]) ++i;
        int end = i;

        res+=execsubstr(start,end);

    }
    cout<<res<<endl;
    return 0;
}