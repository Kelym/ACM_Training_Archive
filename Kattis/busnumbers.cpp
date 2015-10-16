#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
int main(){
	int n,ins;
	vector<int> bus;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>ins;
		bus.push_back(ins);
	}
	sort(bus.begin(),bus.end());
	int i=0;
	while(i<n){
		cout<<bus[i];
		int j=i+1;
		while(j<n && bus[j]==bus[j-1]+1) ++j;
		if(j>i+2){
			cout<<"-"<<bus[j-1]<<" ";
			i=j;
		}
		else{
			++i;
			cout<<" ";
		}
	}
	return 0;
}
