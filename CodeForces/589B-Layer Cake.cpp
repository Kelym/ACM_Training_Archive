#include <set>
#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

struct cakelayer
{
    int x,y;
    cakelayer(int xx,int yy):x(xx),y(yy){}
    const bool operator<(const cakelayer &rhs)
        {return x > rhs.x;}
};

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n,a,b;
    vector<cakelayer> ins;
    cin >> n;
    for(int i=0;i<n;++i){
        cin >> a >> b;
        if(a>b) swap(a,b);
        ins.push_back(cakelayer(a,b));
    }
    sort(ins.begin(),ins.end());

    multiset<long long> curY;
    long long curX, ansV = 0, ansX, ansY;
    for(int i=0;i<n;++i)
    {
        curX = ins[i].x;
        curY.insert(ins[i].y);
        long long countCakes = i+1;
        for(auto y : curY)
        {
            long long volumn = ((long long)countCakes * y) * curX;
            if(volumn > ansV)
            {
                ansV = volumn;
                ansX = curX;
                ansY = y;
            }
            countCakes --;
        }
    }
    cout << ansV <<endl<<ansX << " " << ansY<<endl;
    return 0;
}

//COMMENT: Initialize Variable before use!