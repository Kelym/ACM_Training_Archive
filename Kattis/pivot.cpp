#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	int n;
	cin>>n;
	long ins[100001];
	bool isMax[100001];
	bool isMin[100001];
	
	for(int i=0;i<n;++i) cin>>ins[i];
	long bound = ins[0];
	isMax[0]=true;

	for(int i=1;i<n;++i){
		if(bound <= ins[i]){
			isMax[i]=true;
			bound = ins[i];
		}
		else isMax[i]=false;
	}

	bound = ins[n-1];
	isMin[n-1]=true;

	for(int i=n-2;i>=0;--i){
		if(bound > ins[i]){
			isMin[i]=true;
			bound = ins[i];
		}
		else isMin[i]=false;
	}

	int res = 0;
	for(int i=0;i<n;++i) if(isMin[i] && isMax[i]) res++;
	cout<<res<<endl;

	return 0;
}