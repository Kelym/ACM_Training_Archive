// https://open.kattis.com/problems/tractor
/*

Notice that this problem is closely related to binary form.
	When the cow moves at step n, it means its position increases by 2^n-1.
	Therefore if we write the x-coordinate and y-coordinate in binary form, we will get:
		11010001
		00101110
	And their sumes should look like 11111111

Then this problem can be turned to another form:
	You have to find two numbers A' and B', such that:
		1> A' is less than or equal to a given A, and B' <= B.
		2> Let S = A' + B', then write S in its binary form, and S will look like:
			11111....11111
	Your task is to calculate how many pair of (A',B') satisfy the above constraints.

To solve this new problem, take a look at A and B.
	1> If S's binary form has less numbers than both A and B, then however you divide S does not matter.
		Then, you can have (S+1) different pairs satisfying the avoe constraints.
	2> If A and B has same length in binary form, then you either give the highest '1' to A or B.
	3> If A and B has different length, suppose A is longer than B.
		    110
		1100100

		You just need to consider how many different pairs you can get from this situation.

P.S. Pay attention to special case:
		1111
	11111100
and
		1000
	10000000

*/

#include <cstdio>
#include <cstring>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

int ff(vector<bool> src, int pos){
	int res = 0, rad = 1;
	for(int i=0;i<pos;++i){
		if(src[i]) res += rad;
		rad*=2;
	}
	return res;
}

int main(){

	int n,aa,bb;
	cin>>n;
	while(n--){		
		cin>>aa>>bb;
		if(aa<bb) swap(aa,bb);

		int originalA = aa, originalB = bb;

		vector<bool> a,b;
		while(aa){
			a.push_back(aa%2);
			aa/=2;
		}
		while(bb){
			b.push_back(bb%2);
			bb/=2;
		}

		int k = b.size(), kk = 1;
		for(int i=1;i<=k;++i) kk*=2;

		int res = kk - 1;

		int bprime = originalB - kk/2 + 1;
		int aprime = kk/2;

		if(a.size() == b.size()){
			aprime = originalA - kk/2 + 1;
			res+=(aprime+bprime);
		}
		else{
			res += (a.size()-b.size())*(aprime+bprime);

			bool check = true;
			for(int i=a.size()-1;i>=b.size() && check;--i) if(!a[i]) check = false;
			for(int i=b.size()-1;i>=0 && check;--i)
				if(!a[i] && !b[i]){
					check = false;
					break;
				}
				else if(a[i]&&b[i]){
					check = false;
					res+= ff(b,i) + ff(a,i) + 2;
					break;
				}
			if(check) res++;
		}

		cout<<res<<endl;
	}
	return 0;
}