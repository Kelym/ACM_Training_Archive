#include <cstdio>
#include <map>
#include <cstring>
#include <iostream>
using namespace std;
int main ()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int m;
    cin>>m;
    string table[50001],readstr;
    int ins = 0, tmp;
    char flag;
    map<string,int> pos;
    while(m--){
        cin>>flag;
        if(flag == 'E'){
            cin>>table[ins];
            pos[table[ins]]=ins++;
        }
        else if(flag == 'D'){
            cin>>tmp;
            while(tmp--){
                ins--;
                pos.erase(table[ins]);
            }
        }
        else{
            cin>>tmp;
            int dreampos = ins, validpos = -1;
            bool flag = false;
            for(int i=0;i<tmp;++i){
                cin>>readstr;
                if(readstr[0]=='!'){
                    readstr = readstr.substr(1);
                    if(pos.find(readstr)!=pos.end() && pos[readstr] < dreampos) dreampos =pos[readstr];
                }
                else{
                    if(pos.find(readstr)==pos.end()) flag=true;
                    else if(validpos < pos[readstr]) validpos = pos[readstr];
                }
            }
            if(!flag && dreampos == ins) printf("Yes\n");
            else if(flag || dreampos <= validpos) printf("Plot Error\n");
            else printf("%d Just A Dream\n",(ins-dreampos));
        }
    }
    return 0;
}