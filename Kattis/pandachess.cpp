/*
Given a graph
Given an order of its node
Use least operations (remove an item / insert an item) to make it a legit topological order.

DP:
From one permutation to another
Longest Increasing Subsequence.
*/

#include <map>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXN = 100001;
vector<int> dp;

int binary_search(int val){
    if(val > dp[dp.size() - 1]) return dp.size();
    int i = 0, j = dp.size()-1, k;
    while(i<j){
        k = (i+j)/2;
        if(dp[k] > val) j=k;
        else if(dp[k]==val) return k;
        else i=k+1;
    }
    return i;
}

map<string, int> ind;
vector<int> edge[MAXN], ranking;

int block[MAXN],place[MAXN];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    int n,m,d;
    cin>>n>>m>>d;
    d=0;

    for(int i=0;i<m;++i){
        string name1,name2;
        cin>>name1>>name2;
        if(ind.find(name1) == ind.end()) ind[name1]=d++;
        if(ind.find(name2) == ind.end()) ind[name2]=d++;
        int id1 = ind[name1];
        int id2 = ind[name2];
        edge[id1].push_back(id2);
        block[id2]++;
    }

    for(d=0;d<n;++d) if(!block[d]) break;
    for(int i=0;i<n;++i){
        place[d] = i;
        int nextd;
        for(auto &j: edge[d]){
            --block[j];
            if(!block[j]) nextd = j;
        }
        d = nextd;
    }

    for(int i=0;i<n;++i){
        cin>>name1;
        if(ind.find(name1) != ind.end()) ranking.push_back(place[ ind[name1] ]);
    }

    if(ranking.size())
        dp.push_back(ranking[0]);

    for(int i=1;i<ranking.size();++i){
        int pos = binary_search(ranking[i]);
        if(pos != dp.size()) dp[pos] = ranking[i];
        else                dp.push_back(ranking[i]);
    }   

    cout<< (2*(n-dp.size()))<<endl;

    return 0;
}
