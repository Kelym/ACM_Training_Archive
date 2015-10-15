#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int whats(int i, int a, int b){
	switch(i){
		case 0: return a+b;
		case 1: return a-b;
		case 2: return a*b;
		case 3: return (int)a/b;
	}
}
char trans(int i){
	switch(i){
		case 0: return '+';
		case 1: return '-';
		case 2: return '*';
		case 3: return '/';
	}
}

int calculate(int a,int b,int c){
	int t[4];
	int n[3];
	t[0]=t[1]=t[2]=t[3]=4;
	n[0]=a;n[1]=b;n[2]=c;

	int num = 4;
	for(int i=0;i<num-1;++i) if(n[i]>1){
		int res = whats(n[i],t[i],t[i+1]);
		--num;
		for(int j=i+1;j<num;++j) t[j]=t[j+1];
		for(int j=i;j<num-1;++j) n[j]=n[j+1];
		t[i] = res;
		--i;
	}
	for(int i=0;i<num-1;++i){
		int res = whats(n[i],t[i],t[i+1]);
		--num;
		for(int j=i+1;j<num;++j) t[j]=t[j+1];
		for(int j=i;j<num-1;++j) n[j]=n[j+1];
		t[i] = res;
		--i;
	}
	return t[0];
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	int ans[100][4];
	int countAns = 0;

	for(int i=0;i<4;++i)
		for(int j=0;j<4;++j)
			for(int k=0;k<4;++k){
				int result = calculate(i,j,k);
				ans[countAns][0] = result;
				ans[countAns][1] = i;
				ans[countAns][2] = j;
				ans[countAns][3] = k;
				++countAns;
			}

	int m,n;
	cin>>m;
	while(m--){
		cin>>n;
		bool find = false;
		for(int i=0;i<countAns && !find;++i) if(ans[i][0] == n){
			find = true;
			printf("4 %c 4 %c 4 %c 4 = %d\n",trans(ans[i][1]),trans(ans[i][2]),trans(ans[i][3]),n);
		}
		if(!find){
			printf("no solution\n");
		}
	}
	return 0;
}