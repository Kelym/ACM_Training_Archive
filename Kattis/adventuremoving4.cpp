#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    // Input
    int n,destination;
    int dis[105],price[105];
    cin>>destination;

    dis[0]=0; // Set a virtual city: starting city.
    price[0]=10000000;

    n=1;
    while(cin>>dis[n]>>price[n]) n++;

    dis[n]=destination + 100; // Set a virtual city: destination city.
    // It requires you to have 100 litre of gas when you arrive there. 
    // Therefore set the distance of it to be 100 more kilo than it actually is.
    // This way, if you can arrive at this virtual destination
    //  You are able to arrive the real destination with 100 more litre of gas.
    price[n]=10000000;

    if(dis[1]>100) // Check if the first city is reachable
    {
        cout<<"Impossible"<<endl;
        return 0;
    }

    int payment = 0;
    int gas = 100;
    for(int i=0;i<n;++i)
    {
        if(dis[i+1] - dis[i] > 200) // Unable to arrive at next city
        {
            cout<<"Impossible"<<endl;
            return 0;
        }
        int j = i+1;
        while(j<n && price[j]>price[i] && dis[j]-dis[i]<=200) ++j; // Find the city on the road that has a lower price than the current
        if(j==n)
        {
            int calDis = dis[n]-dis[i];
            if(calDis > 200)
            {
                payment += price[i]*(200-gas);
                gas = 200;
            }
            else if(calDis > gas)
            {
                payment += price[i]*(calDis-gas);
                gas = calDis;
            }
        }
        else if(dis[j]-dis[i]>200)
        {
            payment += price[i]*(200-gas);
            gas = 200;
        }
        else if(dis[j]-dis[i]>gas)
        {
            payment += price[i]*(dis[j]-dis[i]-gas);
            gas = dis[j]-dis[i];
        }

        gas-=dis[i+1]-dis[i];
    }

    cout<<payment<<endl;

    return 0;
}