#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

char toLower(char c){
	if(c>='A' && c<='Z') c = 'a'+c-'A';
	return c;
}

bool isVowel(char c){
	return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y');
}

bool isDoubleConsonant(string s){
	s[0]= toLower(s[0]);
	s[1]= toLower(s[1]);
	return (s=="qu" || s=="tr" || s=="br" || s=="st" || s=="sl" || s=="bl" || s=="cr" || s=="ph" || s=="ch");
}

int whatsNext(string s){
	if(s.size()>=3){
		if(toLower(s[0])=='s' && toLower(s[1])=='t' && toLower(s[2])=='r') return 3;
	}
	if(s.size()>=2 && isDoubleConsonant(s.substr(0,2))) return 2;
	char c = toLower(s[0]);
	if(isVowel(c)) return 0;
	else if(c>='a' && c<='z') return 1;
	return -1;
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	string in;
	vector<string> components;
	vector<int> flag;
	while(cin>>in && in!="===")
	{
		components.clear();
		flag.clear();

		int pos = 0;
		while(pos < in.size()){
			int tag = whatsNext(in.substr(pos));
			flag.push_back(tag);
			if(tag > 0){
				components.push_back(in.substr(pos,tag));
				pos+=tag;
			}
			else{
				components.push_back(in.substr(pos,1));
				pos++;
			}
		}

		//for(auto &ccc : components) cout<<ccc<<",";cout<<endl;
		//for(auto &ccc : flag) cout<<ccc<<",";cout<<endl;

		pos = 0;
		while(pos < components.size()){

			if(flag[pos] == 0){
				if(pos+3 < components.size() && flag[pos+1]>0 && flag[pos+2]>0 && flag[pos+3]==0){
					cout<<components[pos]<<components[pos+1]<<"-"<<components[pos+2];
					pos+=3;
				}
				else if( pos+2 < components.size() && flag[pos+1] >0 && flag[pos+2]==0){
					if(components[pos+2] == "e" && pos+2 == components.size() - 1){
						cout<<components[pos]<<components[pos+1];
						pos+=2;
					}
					else{
						cout<<components[pos]<<"-"<<components[pos+1];
						pos+=2;
					}
				}
				else cout<<components[pos++];
			}
			else cout<<components[pos++];
		}
		cout<<endl;
	}
	return 0;
}