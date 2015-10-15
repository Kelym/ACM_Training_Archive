#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a,b;
int nex[200001];

void GetNext(){
	int i=0,j=-1,len=str.size();
	nex[0]=-1;
	while(i<len){
		if( j == -1 || str[i]==str[j]){
			++i;
			++j;
			nex[i]=j;
		}
		else j=nex[j];
	}
}

bool KMP(){
	int aLen = a.size(), bLen = b.size();
	GetNext();
	int i=0,j=0;
	while(i<aLen && j<bLen){
		if(j==-1 || a[i]==b[j]){
			++i;++j;
		}
		else j=nex[j];
	}
	if(j==bLen) return true;
	else return false;
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int n;
	int c1[200000],c2[200000];
	cin>>n;
	for(int i=0;i<n;++i) cin>>c1[i];
	for(int i=0;i<n;++i) cin>>c2[i];

	sort(c1,c1+n);
	sort(c2,c2+n);

	for(int i=1;i<n;++i) a.push_back(c1[i]-c1[i-1]);
	a.push_back(360000 - c1[n-1] + c1[0]);
	for(int i=0;i<n-1;++i) a.push_back(a[i]);

	for(int i=1;i<n;++i) b.push_back(c2[i]-c2[i-1]);
	b.push_back(360000 - c2[n-1] + c2[0]);

	bool res = KMP();

	if(res) cout<<"possible"<<endl;
	else cout<<"impossible"<<endl;
	return 0;
}