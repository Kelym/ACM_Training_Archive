#include <cstdio>
#include <vector>
#include <algorithm>
int m,n,l;
struct coord{
	int x,y;
	coord(int a,int b):x(a),y(b){}
	bool operator< (const coord &rhs){return x<rhs.x;}
};
vector<coord> pairs;
bool cover[10001][10001];
coord translate(int index){

}
bool fill(){
    
}
int main()
{
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int tc,a,b;
    scanf("%d",&tc);
    while(tc--){
    	cin>>m>>n>>l;
    	pairs.clear();
    	for(int i=0;i<l;++i){
    		cin>>a>>b;
    		pairs.push_back(coord(a,b));
    	}
        sort(pairs.begin(),pairs.end());
        for(int i=0;i<l;++i)
    }
	return 0;
}