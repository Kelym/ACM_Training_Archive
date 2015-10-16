#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;
int main(){
	string line;
	getline(cin,line);
	while(line.length()>1){
		double CfromF=0, sumC=0;
		do{
			std::istringstream iss(line);
			int num[5];
			char sign[5];
			int totalC=0,totalP=0;
			for(int i=0;i<5;++i){
				iss>>num[i]>>sign[i];
				if(sign[i]=='g'){
					sign[i]='C';
					if(i==0) num[i]*=9;
					else if(i==4) num[i]*=7;
					else num[i]*=4;
				}
				if(sign[i]=='C') totalC+=num[i];
				else totalP+=num[i];
			}
			double totalCC = (double)totalC*100/(double)(100-totalP);
			sumC+=totalCC;
			if(sign[0]=='C') CfromF+=num[0];
			else CfromF += (double)num[0] * totalCC/100.0;
			getline(cin,line);
		}while(line.length()>1);
		double val = CfromF*100/sumC;
		int vv = val;
		if(val-(double)vv >= 0.5) vv++;
		cout<<vv<<"%"<<endl;
		getline(cin,line);
	}
	return 0;
}
