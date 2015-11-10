#include <set>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

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
bool connect(int a, int b){
    
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
        memset(cover,0,sizeof(cover));
        set<int> rhs;
        bool flag = true;
        for(int i=0;i<l && flag;++i)
        {
            a = pairs[i].x;
            b = pairs[i].y;
            while(rhs.size() && *(rhs.begin()) < a){
                rhs.erase(rhs.begin());
            }
            if( rhs.size() && b > *(rhs.begin()){
                flag = false;
                break;
            }
            rhs.insert(b);
            flag = connect(a,b);
        }

        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
	return 0;
}