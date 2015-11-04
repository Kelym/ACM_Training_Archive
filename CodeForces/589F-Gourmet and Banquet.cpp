#include <set>
#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

struct point{
    int x,y;
    point(int xx,int yy):x(xx),y(yy){}
    bool operator<(const point &rhs) const
    {return x<rhs.x || (x==rhs.x && y<rhs.y);}
};

vector<point> ins;

bool check(int limit)
{
    multiset<point> table;
    int curT = 0, consumeI[101]={0};
    for(int i=0;i<ins.size();++i)
    {
        curT = ins[i].x;
        table.insert(point(ins[i].y,i));

        while(table.size())
        {
            auto nextOut = table.begin();
            int nextOutTime = nextOut -> x;
            int whichDish = nextOut -> y;
            int needTime = limit - consumeI[whichDish];

            if(i<ins.size() - 1 && ins[i+1].x < nextOutTime)
            {
                int nextTime = ins[i+1].x;
                if(curT + needTime > ins[i+1].x)
                {
                    consumeI[whichDish] += ins[i+1].x - curT;
                    curT = ins[i+1].x;
                    break;
                }
                else
                {
                    curT += needTime;
                    consumeI[whichDish] = limit;
                    table.erase(nextOut);
                }
                
            }
            else
            {
                if(nextOutTime - curT >= needTime)
                {
                    consumeI[whichDish] = limit;
                    curT += needTime;
                    table.erase(nextOut);
                }
                else
                {
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n,a,b,maxL = 100000;
    cin >> n;
    for(int i=0;i<n;++i){
        cin >> a >> b;
        maxL = min (maxL, b-a);
        ins.push_back(point(a,b));
    }

    sort(ins.begin(),ins.end());
    int minL = 0;
    while(minL < maxL){
        int mid = (minL + maxL + 1) / 2;
        if(check(mid)) minL = mid;
        else maxL = mid-1;
    }
    cout << (minL*n) <<endl;
    return 0;
}
// COMMENT: In Binary Search: MID = (L+H+1)/2; Don't forget +1.