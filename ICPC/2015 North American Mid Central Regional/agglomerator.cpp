#include <cstdio>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <vector>

#define FOR(i,a,b) for (int i=(a);i<(b);i++)

using namespace std;

struct BALL{
	double x,y,vx,vy,r;
};

BALL ball[100];
int n;

double dist(double ax,double ay,double bx,double by) {
	double x=abs(ax-bx);
	double y=abs(ay-by);
	return sqrt(x*x+y*y);
}

BALL colli(BALL a, BALL b,double t) {
	BALL n;
	a.x=a.x+t*a.vx;
	a.y=a.y+t*a.vy;
	b.x=b.x+t*b.vx;
	b.y=b.y+t*b.vy;
	double tmp=a.r*a.r+b.r*b.r;
	n.r=sqrt(tmp);
	n.x=(a.x*a.r*a.r+b.x*b.r*b.r)/tmp;
	n.y=(a.y*a.r*a.r+b.y*b.r*b.r)/tmp;
	n.vx=(a.vx*a.r*a.r+b.vx*b.r*b.r)/tmp;
	n.vy=(a.vy*a.r*a.r+b.vy*b.r*b.r)/tmp;
	return n;
}

double getT(BALL a,BALL b) {

	double d=dist(a.x,a.y,b.x,b.y);
	double x = a.x-b.x,y=a.y-b.y,vx=a.vx-b.vx,vy=a.vy-b.vy;
	double aa=vx*vx+vy*vy;
	if (aa == 0)
		return -1;
	double bb=2*x*vx+2*y*vy;
	double cc=x*x+y*y-(a.r+b.r)*(a.r+b.r);
	if ((bb*bb - 4*aa*cc) < 0)
		return -1;
	double t1=-1*bb-sqrt(bb*bb-4*aa*cc);
	double t2=-1*bb+sqrt(bb*bb-4*aa*cc);
	t1=t1/(2*aa);
	t2=t2/(2*aa);
	if(t1 <=0 && t2<=0)
		return -1;
	if(t1 <= 0)
		return t2;
	if(t2 <= 0)
		return t1;
	return min(t1,t2);


}

int main(){
	scanf("%d",&n);
	FOR(i,0,n) {
		scanf("%lf%lf%lf%lf%lf",&ball[i].x,&ball[i].y,&ball[i].vx,&ball[i].vy,&ball[i].r);
	}
	
	double tott=0;
	int rec=0;
	FOR(k,0,n-1) {
		double mint=0;
		int minx,miny;
		bool flag=false;
		FOR(i,0,n-1) 
			if (ball[i].r!=0) 
				FOR(j,i+1,n)
					if (ball[j].r!=0)
					{
						double t=getT(ball[i],ball[j]);
						if (t!=-1) 
							{
								flag=true;
								if (mint==0||mint>t) {
									mint=t;
									minx=i;
									miny=j;
								}
							}
					}
		if (!flag) break;	
		rec++;
		ball[minx]=colli(ball[minx],ball[miny],mint);
		ball[miny].r=0;
		//printf("%d %d\n%lf %lf %lf %lf %lf %lf\n\n",minx,miny,ball[minx].x,ball[minx].y,ball[minx].vx,ball[minx].vy,ball[minx].r,mint);
		tott+=mint;
		FOR(i,0,n) 
			if (ball[i].r!=0 && i!=minx) {
				ball[i].x=ball[i].x+mint*ball[i].vx;
				ball[i].y=ball[i].y+mint*ball[i].vy;
			}
			
		/*cout << "BALLS" << endl;
		for(int i = 0; i < n; i++) {
			cout << "x: " << ball[i].x << "; y: " << ball[i].y << "; vx=:" <<  ball[i].vx << "; vy: " << ball[i].vy << "; rad: " << ball[i].r << endl;
		}
		cout << "_______" << endl << endl;*/
				
	}
	
	printf("%d %lf",n-rec,tott);
	return 0;
}