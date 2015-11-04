#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

template<typename T>
class fenwick_tree{
public:
    vector<T> tree;
    fenwick_tree(const int aSize){
        tree.resize(aSize+10);
    }
    void increase(int i, T delta){
        for (; i < (int)tree.size(); i |= i + 1)
            tree[i] += delta;
    }
    T sum(int ind){
        T sum = 0;
        while (ind>=0){
            sum += tree[ind];
            ind &= ind + 1;
            ind--;
        }
        return sum;
    }
};

struct point{
    int x,y,z;
    point(int xx,int yy):x(xx),y(yy){}
    point(int xx,int yy, int zz):x(xx),y(yy),z(zz){}
    bool operator< (const point &rhs) const
        {return x >= rhs.x;}
};
vector<point> days,ppl;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n,m;
    cin>>n>>m;
    int a,b;

    for(int i=0;i<m;++i){
        cin>>a;
        days.push_back(point(a,i));
    }
    for(int i=0;i<n;++i){
        cin>>a>>b;
        ppl.push_back(point(a,b,i));
    }
    sort(ppl.begin(),ppl.end());
    sort(days.begin(),days.end());

    fenwick_tree<long long> eli(m),cday(m);

    int res[200010] = {0};
    int k = 0;
    for(int p=0;p<n;++p)
    {
        int i = ppl[p].z;
        long long d = ppl[p].x;
        int r = ppl[p].y;

        while( k<days.size() && days[k].x > d){
            eli.increase(days[k].y,days[k].x);
            cday.increase(days[k].y,1);
            ++k;
        }

        long long ans = eli.sum(m-1) - cday.sum(m-1)*d;
        if(ans < r) res[i]=0;
        else{
            int low = 0, high = m-1;
            while(low < high){
                int mid = (low + high)/2;
                ans = eli.sum(mid) - cday.sum(mid)*d;
                if(ans >= r) high = mid;
                else low = mid+1;
            }
            res[i] = low+1;
        }
    }

    for(int i=0;i<n;++i) cout<<res[i]<<' ';
    cout<<endl;
}

// COMMENT force to long long in any calculation involve long long