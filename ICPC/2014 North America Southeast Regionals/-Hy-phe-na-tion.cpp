#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

char toLower(char c){
	if(c>='A' && c<='Z') c = 'a'+c-'A';
	return c;
}

bool isVowel(char c){
	c = toLower(c);
	return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y');
}

bool isSingleConsonant(char c){
	c = toLower(c);
	return (c<='z' && c>='a' && !isVowel(c));
}

bool isDoubleConsonant(string s){
	s[0]= toLower(s[0]);
	s[1]= toLower(s[1]);
	return (s=="qu" || s=="tr" || s=="br" || s=="st" || s=="sl" || s=="bl" || s=="cr" || s=="ph" || s=="ch");
}

int aConsonant(string s){
	if(s.size()>=3){
		if(toLower(s[0])=='s' && toLower(s[1])=='t' && toLower(s[2])=='r') return 3;
	}
	if(s.size()>=2 && isDoubleConsonant(s.substr(0,2))) return 2;
	if(isSingleConsonant(s[0])) return 1;
	return -1;
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	string in;
	vector<string> btV;
	vector<char> vowels;
	while(cin>>in && in!="===")
	{
		btV.clear();
		vowels.clear();

		int i=0,j;
		while(i<in.size()){
			j=i;
			while(i<in.size()){
				if(!isVowel(in[i])) ++i;
				else if((in[i]=='u' || in[i]=='U') && (j<i && in[i-1]=='q' || in[i-1]=='Q')) ++i;
				else break;
			}
			btV.push_back(in.substr(j,i-j));
			if(i<in.size()){
				vowels.push_back(in[i]);
				++i;
			}
		}

		for(auto &ccc : btV) cout<<ccc<<",";cout<<endl;
		for(auto &ccc : vowels) cout<<ccc<<",";cout<<endl;
		

		if(btV.size()>0) cout<<btV[0];
		if(vowels.size()>0) cout<<vowels[0];

		for(int t=1;t<vowels.size();++t){

			string cur = btV[t];
			int findS = aConsonant(cur);
			if(findS > 0){
				if(findS == cur.size()){
					if(!(t == vowels.size() - 1 && t == btV.size() - 1)){
						cout<<"-";
						cout<<cur;
					}
					else cout<<cur;
				}
				else{
					int findT = aConsonant(cur.substr(findS));
					if(findS+findT == cur.size()){
						cout<<cur.substr(0,findS)<<"-"<<cur.substr(findS);
					}
					else cout<<cur;
				}
			}
			else cout<<cur;

			cout<<vowels[t];
		}

		if(btV.size() > vowels.size()) cout<<btV[btV.size()-1];
		cout<<endl;
	}
	return 0;
}