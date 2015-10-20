/*
Shortest Path problem:

Read in the ant path, and record "walkable" position on a matrix.
	Because the length of path < 60, the size of matrix will be less than (60+60)*(60+60);
	The array size could be [121][121], or a little bit larger to guard boundary.
Set the initial position at the center of the matrix, whenever the ants goes, mark the cell as walkable.

Whenever the ant moves from a cell to another, record the direction on both cells.
	If the ant moves from cell(1,2) to cell(1,3);
	Mark direction[1][2][0] = 1, and mark direction[1][3][1] = 1;
	Because in the following program, 0 represents South, 1 represents North;
	
	i.e. direction[x][y][0] == 1
		means that from cell (x,y) can move to the direction South;

Use any algorithm to find the shortest path between the final position back to the center of the matrix.
	
*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <utility>
#include <queue>

using namespace std;

bool map[140][140], direction[140][140][4];

int SPFA(int xx, int yy){
	queue< pair<int,int> > table;
	table.push(make_pair(xx,yy));
	bool inQueue[140][140]={0};
	int dis[140][140];
	for(int i=0;i<140;++i) for(int j=0;j<140;++j) dis[i][j]=140;

	int shift[4][2]={{0,1},{0,-1},{-1,0},{1,0}};

	dis[xx][yy]=0;

	while(!table.empty()){

		pair<int,int> pos = table.front();
		table.pop();

		int i = pos.first;
		int j = pos.second;
		//cout<<i<<","<<j<<" "<<dis[i][j]<<endl;
		inQueue[i][j]=0;

		for(int k=0;k<4;++k){
		int x = i+shift[k][0];
		int y = j+shift[k][1];
		if(direction[i][j][k] && map[x][y] && dis[x][y] > dis[i][j]+1 ){
			dis[x][y]=dis[i][j]+1;
			if(!inQueue[x][y]){
				inQueue[x][y]=1;
				table.push(make_pair(x,y));
				}
			}
		}
	}
	return dis[70][70];
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int m,n;
	cin>>m;
	while(m--){
		memset(map,0,sizeof(map));
		memset(direction,0,sizeof(direction));
		cin>>n;
		int x=70,y=70;
		map[70][70]=1;
		while(n--){
			char path;
			cin>>path;
			if(path=='S'){
				direction[x][y][0]=1;
				y++;
				map[x][y]=1;
				direction[x][y][1]=1;
			}
			if(path=='N'){
				direction[x][y][1]=1;
				y--;
				map[x][y]=1;
				direction[x][y][0]=1;
			}
			if(path=='W'){
				direction[x][y][2]=1;
				x--;
				map[x][y]=1;
				direction[x][y][3]=1;
			}
			if(path=='E'){
				direction[x][y][3]=1;
				x++;
				map[x][y]=1;
				direction[x][y][2]=1;
			}
		}

		cout<<SPFA(x,y)<<endl;
	}
	return 0;
}
