// Pass Kattis but WA on ICPC Baylor Judge
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int m, n;
	cin>>m;
    vector<int> ins;
	while(m--)
	{
		cin>>n;
        ins.reserve(n);
		for(int i=0;i<n;++i) cin>>ins[i];
        int seek = 1, i=0;
        while(i<n){
            if(ins[i]==seek) ++seek;
            ++i;
        }
        cout<<(n-seek+1)<<endl;
	}
	return 0;
}