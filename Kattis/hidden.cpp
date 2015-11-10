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


int main(){

	string word, message;
	cin >> word >> message;
	int firstAppear[10], lastOf[28];
	for(int i = 0; i < 10; i++) firstAppear[i] = -1;
	for(int i = 0; i < 28; i++) lastOf[i] = -1;
	for(int i = 0; i < word.length(); i++) {
		for(int j = lastOf[word[i]-'A']+1; j < message.length(); j++)
			if(word[i] == message[j]) {
				firstAppear[i] = j;
				lastOf[word[i]-'A']=j;
				break;
			}
	}/*
	for(int i = 0; i < word.length(); i++) {
		cout << firstAppear[i] << endl;
	}*/
	for(int i = 0; i < word.length()-1; i++) {
		if(firstAppear[i] > firstAppear[i+1] || firstAppear[i] < 0) {
			cout << "FAIL" <<endl;
			return 0;
		}
	}
	cout << "PASS" << endl;
	return 0;
}