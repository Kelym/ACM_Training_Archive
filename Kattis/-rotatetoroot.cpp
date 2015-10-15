#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int n;
int l[100001]={0},r[100001]={0},h[100001],rh[100001],p[100001];
bool isL[100001];

void findHeight(int i){
	int lc = 0;
	if(l[i]){
		findHeight(l[i]);
		lc = h[l[i]];
	}
	if(r[i]){
		findHeight(r[i]);
		lc = max(lc,h[r[i]]);
	}
	h[i]=lc+1;
}

void rotateHeight(int i){
	int father = p[i];
	int brother=-10, lc=-10, rc=-10;
	if(isL[i]){
		if(l[i]) lc = h[l[i]]+1;
		if(r[i]) rc = h[r[i]]+2;
		if(r[father]) brother = h[r[father]]+2;
	}
	else{
		if(l[i]) lc = h[l[i]]+2;
		if(r[i]) rc = h[r[i]]+1;
		if(l[father]) brother = h[l[father]]+2;
	}
	rh[i] = max(lc,rc);
	rh[i] = max(rh[i],brother);

	
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	cin >> n;
	for(int i=1;i<=n;++i){
		cin>>l[i]>>r[i];
		p[l[i]]=i;
		p[r[i]]=i;
		isL[l[i]] = true;
		isL[r[i]] = false;
	}
	
	memset(h,0,sizeof(h));
	findHeight(1);

	memset(h,0,sizeof(h));
	rh[1]=h[1];
	rotateHeight(l[1]);
	rotateHeight(r[1]);

	return 0;
}