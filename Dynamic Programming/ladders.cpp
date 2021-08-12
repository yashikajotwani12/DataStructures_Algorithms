#include<bits/stdc++.h>
using namespace std;
int ladders(int n, int k, int dp[])
{
    // base case
    if(n==0) return 1;

    // lookup
    if(dp[n]!=0)
    {
        return dp[n];
    }
    


    // rec case
    int ways=0;
    for(int i=1;i<=k;i++)
    {
        if(n-i>=0)
        ways+=ladders(n-i,k,dp);

    }
    return dp[n] = ways;
}
int main()
{
    int n,k;
    cin>>n>>k;
    int dp[100]={0};
    cout<<ladders(n,k,dp);

    return 0;
}

// tc array of size n , for every n in n: sum -> o(k) --> o(nk)
// sc o(n);