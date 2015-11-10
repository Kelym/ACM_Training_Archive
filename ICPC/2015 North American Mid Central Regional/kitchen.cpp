#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

map<int, int> dis;
queue<int> table;
bool inTable[1100000000] = {0};

int n,ins[5],target;
int optimal = 1100000000;

inline int at(int digit, int i){
	if(i<n-1) return ((digit>>(6*i))& 63);
	else return (digit >> (6*i));
}

inline int min(int a,int b){
	return (a<b? a:b);
}

void SPFA(){
	int v[5];
	
	while(!table.empty()){
		int s = table.front();
		table.pop();
		int taken = dis[s];
		
		inTable[s]=false;
		
		//cout<<s<<" : ";
		for(int i=0;i<5;++i){
			v[i]=at(s,i);
			//cout<<v[i]<<", ";
		}
		//cout<<taken<<endl;
		
		int ns;
		for(int i=0;i<n;++i) if( v[i]> 0){
			for(int j=0;j<n;++j) if(j!=i && v[j]<ins[j]){
				
				int diff =min(v[i], ins[j]-v[j]);
				
				ns = s - (diff << (6*i)) + (diff << (6*j));

				if(dis.find(ns) == dis.end() || dis[ns] > taken+diff){
					dis[ns] = taken+diff;
					if(!inTable[ns]){
						inTable[ns]=true;
						table.push(ns);
					}
				}
			}
			if(at(ns,n-1) == target && dis[ns]<optimal){
				optimal = dis[ns]; 
			}
		}
	}
}

int main(){
	
	cin>>n;
	for(int i=n-1;i>=0;--i) cin>>ins[i];
	cin>>target;
	
	int realStart = (ins[n-1] << ((n-1)*6) );
	int realTarget = (target << ((n-1)*6) );
	
	table.push(realStart);
	dis[realStart] = 0;
	//cout<<"enter "<<realStart<<endl;
	SPFA();
	
	if(optimal < 1100000000) cout<<optimal<<endl;
	else cout<<"impossible"<<endl;
	return 0;
}