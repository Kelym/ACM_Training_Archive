/*
Input an permutation len n <= 10^4.
Decide whether exists {pi,pj,pk} such that pi+pk=2pj.
i<j<k but not necessarily adjacent.
Output yes if not exists.
Multiple test case.
*/
#include <set>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int const MAXN = 10010;
int n , num[MAXN];
set<int>s;

bool solve(){
    for(int i = 0 ; i < n ; i++){
        s.erase(num[i]);
        for(int j = 0 ; j < i ; j++){
            int value = 2*num[i]-num[j];
            if(s.find(value) != s.end()) return true;
        }
    }
    return false;
}
int main(){
    char str[10];
    while(scanf("%s" , str)){
        if(!strcmp(str,"0")) break;
        sscanf(str,"%d:",&n);
        s.clear();
        for(int i = 0 ; i < n ; i++){
            scanf("%d" , &num[i]);
            s.insert(num[i]);
        }
        printf("%s\n" , solve() ? "no" : "yes");
    }
    return 0;
}
