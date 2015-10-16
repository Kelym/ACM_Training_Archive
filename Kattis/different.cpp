#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
int main(){
    string a,b;
    while(cin>>a>>b){
        if(a==b){
            cout<<"0"<<endl;
            continue;
        }
        if(b.size()>a.size()) swap(a,b);
        else if(a.size()==b.size() && a.compare(b)<0) swap(a,b);
        vector<int> x,y,z;
        for(int i=a.size()-1;i>=0;i--) x.push_back(a[i]-'0');
        //for(int i=x.size()-1;i>=0;i--) cout<<x[i];cout<<endl;
        for(int i=b.size()-1;i>=0;i--) y.push_back(b[i]-'0');
        //for(int i=y.size()-1;i>=0;i--) cout<<y[i];cout<<endl;
        for(int i=0;i<y.size();++i){
            if(x[i]<y[i]){
                x[i]+=10;
                x[i+1]--;
            }
            z.push_back(x[i]-y[i]);
            //cout<<x[i]<<" "<<y[i]<<" "<<z[z.size()-1]<<endl;
        }
        int i=y.size();
        while(i<x.size()){
            if(x[i]<0){
                x[i]+=10;
                x[i+1]--;
            }
            z.push_back(x[i]);
            i++;
        }
        i=z.size()-1;
        while(i>=0 && z[i]==0) i--;
        for(;i>=0;--i) cout<<z[i];
        cout<<endl;
    }
    return 0;
}

