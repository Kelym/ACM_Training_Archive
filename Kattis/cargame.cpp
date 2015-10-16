#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
vector<int> wor[5001][26];
int siz[5001][26];
string word[5001];
int n,m;
void searchFor(int a,int b,int c){
    int k,t;
	for(int i=0;i<n;++i) if(siz[i][a] && siz[i][b] && siz[i][c]){
		k=wor[i][a][0];
		t=wor[i][c][siz[i][c]-1];
		int j=0;
		for(;j<siz[i][b] && wor[i][b][j]<t;++j) if(wor[i][b][j]>k) break;
		if(j<siz[i][b] && wor[i][b][j]<t && wor[i][b][j]>k){
			cout<<word[i]<<endl;
			return ;
		}
	}
	cout<<"No valid word"<<endl;
}
int main(){
	cin>>n>>m;
	string ins;
	for(int i=0;i<n;++i){
		cin>>ins;
		word[i]=ins;
		bool flag[100]={0};
		for(int j=3;j<ins.size();++j)
			if(ins[j]==ins[j-1]){
				if(flag[j-1] || (ins[j-1]==ins[j-2] && ins[j-2]==ins[j-3])) flag[j]=1;
			}
		for(int j=0;j<ins.size();++j) if(!flag[j]){
			int s=ins[j]-'a';
			wor[i][s].push_back(j);
		}
		for(int j=0;j<26;++j) siz[i][j]=wor[i][j].size();
	}
	while(m--){
		cin>>ins;
		searchFor(ins[0]-'A',ins[1]-'A',ins[2]-'A');
	}
	return 0;
}
