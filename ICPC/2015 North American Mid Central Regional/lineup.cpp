#include <cstdio>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <vector>


using namespace std;

bool compare(string a, string b){
	int i=0;
	while(i<a.size() && i<b.size()) {
		if(a[i]>b[i]) return true;
		else if(a[i] < b[i]) return false;
		i++;
	}
	return a.size() > b.size();
}
int main(){
	int N;
	bool as = true, des = true;
	vector <string> words(21);
	cin>>N;
	for (int i = 0; i < N ; i++) {
		cin >> words[i];
	}
	for(int i = 0 ; i < N-1; i++)
		if(compare(words[i],words[i+1])){
			//cout<<words[i]<<' '<<words[i+1]<<" A"<<endl;
			as = false;
			}
		else
			des = false;
		
	if(as) cout << "INCREASING" << endl;
	else if(des) cout << "DECREASING" <<  endl;
	else cout << "NEITHER" << endl;
	return 0;
}