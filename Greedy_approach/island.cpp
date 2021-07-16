#include<bits/stdc++.h>
using namespace std;

int main()
{
    int s,n,m;
    cin>>s>>n>>m;
    int x=s/7;
    int y= s - x;
    int sm = s*m;
    int days= sm/n;
    if(sm%n!=0)
    {
        days++;
    }
    if(days <=y)
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;


    return 0;
}