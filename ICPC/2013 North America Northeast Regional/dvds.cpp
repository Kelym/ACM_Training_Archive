#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int m, n;
	cin>>m;
	while(m--)
	{
		cin>>n;
		bool pos[1000005]={0};
		int bound = 1, res = 0;
		for(int i=0;i<n;++i)
		{
			int ins;
			cin>>ins;
			if(ins == bound){
				pos[ins]=1;
				while(pos[bound]==1) ++bound;
			}
			else{
				pos[ins]=1;
				res++;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}