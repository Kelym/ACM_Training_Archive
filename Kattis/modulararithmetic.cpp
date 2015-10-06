#include <cstdio>
#include <cstring>
#include <iostream>

#include <math.h>

using namespace std;

long long mod(long long a, long long b){
	if(a%b<0) return (a%b+b);
	return (a%b);
}

long long x,y,q;
void ext(long long a, long long b){
	if(a==0){
		x=0;y=1;q=b;
		return;
	}
	if(b==0){
		x=1;y=0;q=a;
		return;
	}
	long long r = mod(a,b);
	long long q = (a-r)/b;
	ext(b,mod(a,b));
	long long temp = x;
	x = y;
	y = temp - q*y;
}

long long mod_add(long long a, long long b, long long n){
	if(a+b>=n) return a+b-n;
	else return a+b;
}

long long mod_minus(long long a, long long b, long long n){
	if(a<b) return a+n-b;
	else return a-b;
}

long long mod_multi(long long a, long long b,long long n){
	long long res = 0;
	while(b){
		if(b%2==1) res=mod_add(res,a,n);
		b/=2;
		a=mod_add(a,a,n);
	}
	return res;
}

long long mod_divide(long long a, long long b, long long n){
	q=0;
	ext(b,n);
	if(b*x+n*y==1){
		x=mod(x,n);
		return mod_multi(a,x,n);
	}
	else return -1;
}



int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m;
	while(cin>>n>>m && n && m){
		int a,b;
		char op;
		while(m--){
			cin >> a >> op >> b;
			if(op=='+') cout<<mod_add(a,b,n)<<endl;
			else if(op=='-') cout<<mod_minus(a,b,n)<<endl;
			else if(op=='*') cout<<mod_multi(a,b,n)<<endl;
			else if(op=='/') cout<<mod_divide(a,b,n)<<endl;
		}
	}
	return 0;
}