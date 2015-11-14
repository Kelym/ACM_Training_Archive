#include <cstdio>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <vector>

#define FOR(i,a,b) for (long i=(a);i<(b);i++)

using namespace std;

long r[250000],rec[250000][400];
long num[1000000];
long ans[250000],nn[250000];
long  x,i;

void make(long num,long x,long l) {
	
	long xx,y,z;
	FOR(i,0,18) {
		if (i!=0) xx=(x>>i); else xx=x;
		if (xx%2==0) {
			if (i==0) y=x+1; else y=x+(1<<i);
			bool check=true;
			FOR(j,0,r[num]) 
				if(rec[num][j]==y) {
					check=false;
					break;
				}
			if (check) {
				rec[num][r[num]]=y;
				r[num]++;
				//printf("%ld\n",y);
			}
			if (l==1) {
			make(num,y,2);
			FOR(j,0,18) 
				if (j!=i) {
					long xxx;
					if (j!=0) xxx=(y>>j); else xxx=y;
					if (xxx%2==1) {
						if (j==0) z=y-1; else z=y-(1<<j);		
						check=true;
						FOR(k,0,r[num])
							if(rec[num][k]==z) {
								check=false;
								break;
							}
						if (check) {
							rec[num][r[num]]=z;
							r[num]++;
											//printf("%ld\n",z);
						}
						//if (l==1) make(num,z,2);
					}	
				}
			}
		}
	}
}

int main(){
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	i=0;
	scanf("%ld",&x);
	while(x!=-1) {
		//printf("%ld:\n",x);
		r[i]=0;
		num[x]=1;
		nn[i]=x;
		make(i,x,1);
		i++;
		scanf("%ld",&x);
	}
	
	FOR(j,0,i) {
		ans[j]=0;
		FOR(k,0,r[j]) {
			if (num[rec[j][k]]==1 && rec[j][k]>nn[j]) {
				ans[j]++;
				//rintf("!!!%ld\n",rec[j][k]);
			}
		}
		printf("%ld:%ld\n",nn[j],ans[j]);
	}
	
	return 0;
}