#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	int n;
	long long count[31];
	cin >> n;
	for(int i=1;i<n;++i) cin>>count[i];
	
	double need = 2.0;
	double ans = 0;
	double len = 1000000.0 * pow(2.0, -0.75);
	double len2 = 1000000.0 * pow(2.0, -1.25);
	bool flag = false;
	for(int i=1;i<n;++i){
		//cout<<i+1<<" "<<need<<' '<<len<<endl;
		ans += need * len;
		need -= count[i];
		if(need <= 0){
			flag = true;
			break;
		}
		double temp = len / 2.0;
		len = len2;
		len2 = temp;
		need *= 2.0;
	}
	if(flag)
		printf("%.8lf\n", (ans/2000000.0));
	else
		cout << "impossible" << endl;
	return 0;
}