#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
double rad(double d){
   return d * 3.1415926 / 180.0;
}
double distance(double lat1,double lng1,double lat2,double lng2){
    double radLat1 = rad(lat1);
	double radLat2 = rad(lat2);
	double a = radLat1 - radLat2;
	double b = rad(lng1) - rad(lng2);
	double s = 2 * asin(sqrt(pow(sin(a/2),2) +cos(radLat1)*cos(radLat2)*pow(sin(b/2),2)));
	return s;
}
int main(){
	int n,res;
	double x[1001],y[1001],best;
	while(cin>>n){
		for(int i=0;i<n;++i) cin>>x[i]>>y[i];
		if(n==1){
			printf("%.2lf %.2lf\n",x[0],y[0]);
		}
		else{
			best=100000000.0;
			res=n;
			for(int i=n-1;i>=0;--i){
				double dis=0.0;
				for(int j=0;j<n;++j) if(j!=i) dis=max(distance(x[i],y[i],x[j],y[j]),dis);
				if(dis<best){
					best=dis;
					res=i;
				}
			}
			printf("%.2lf %.2lf\n",x[res],y[res]);
		}
	}
	return 0;
}
