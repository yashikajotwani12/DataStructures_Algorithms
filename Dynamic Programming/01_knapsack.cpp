#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int cap;
    vector<int>vals(n);
    vector<int>weig(n);
    for(int i=0;i<n;i++)
    {
        cin>>vals[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>weig[i];
    }
   vector<vector<int>>dp(n+1,vector<int>(cap+1));

    return 0;
}