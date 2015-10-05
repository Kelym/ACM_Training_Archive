#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

string start, dest;
int n;

map<string, vector<int> > belongsTo; 
vector<string> nameList[101];
int clubSize [ 101];

void SPFA(){
	map<string, int> distance;
	map<string, string> from;
	queue<string> table;
	set<string> inQueue;

	table.push(start);
	distance[start]=0;

	while(!table.empty()){

		string i = table.front();
		table.pop();
		inQueue.erase(i);

		for(auto c:belongsTo[i]){
			int dis = clubSize[c] - 2 + distance[i];
			for( auto t:nameList[c]){
				if(distance.find(t)==distance.end() || distance[t]>dis){
					distance[t]=dis;
					from[t]=i;
					if(inQueue.find(t) == inQueue.end()){
						inQueue.insert(t);
						table.push(t);
					}
				}
			}
		}
	}
	if(distance.find(dest) == distance.end()) cout<<"impossible"<<endl;
	else{
		vector<string> path;
		for(string d = dest; d!=start; d=from[d])
			path.push_back(d);
		cout<< (distance[dest]+ path.size()-1)<<" ";
		for(auto i:path) cout<<i<<" ";
		cout<<start<<endl;
	}
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(cin>>start>>dest){
		swap(start,dest);
		cin>>n;cin.ignore();
		string line,name;
		belongsTo.clear();
		for(int i=0;i<n;++i){
			getline(cin,line);
			stringstream ss(line);
			nameList[i].clear();
			clubSize[i]=0;

			while(ss >> name){
				clubSize[i]++;
				nameList[i].push_back(name);
				if(belongsTo.find(name)==belongsTo.end()) belongsTo[name] = vector<int> ();
				belongsTo[name].push_back(i);
			}
		}
		SPFA();
	}
	return 0;
}