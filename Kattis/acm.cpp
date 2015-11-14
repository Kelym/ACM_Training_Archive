#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main(){
	
	int ins;
	string name,result;
	bool solved[27]={0};
	int elapse[27]={0};
	
	while(cin>>ins && ins != -1){
		cin>>name>>result;
		int prob = name[0]-'A';
		if(solved[prob] == true) continue;
		if(result == "right"){
			solved[prob]=true;
			elapse[prob]+=ins;
		}
		else{
			elapse[prob]+=20;
		}
	}	
	
	int countr = 0, totalt = 0;
	for(int i=0;i<26;++i){
		if(solved[i]){countr++;totalt+=elapse[i];}
	}
	cout<<countr<<" "<<totalt<<endl;
	
	return 0;
}