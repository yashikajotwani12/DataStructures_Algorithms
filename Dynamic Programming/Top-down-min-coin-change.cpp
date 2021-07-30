#include <bits/stdc++.h>
using namespace std;

int mincoins(int n, int coins[], int t, int dp[])
{
    // base case
    if (n == 0)
    {
        return 0;
    }
     // lookup
    if(dp[n]!=0)
    {
        return dp[n];
    }
    // rec case
    int ans = INT_MAX;
    
    for (int i = 0; i < t; i++)
    {
        if (n - coins[i] >= 0)
        {
            int subprob = mincoins(n - coins[i], coins, t, dp);
            ans = min(ans,subprob+1);
        }
        
    }
    dp[n]=ans;
    return dp[n];

}
int main()
{
    int n = 15;
    int coins[] = {1, 7, 10};
    int dp[] = {0};
    int t=3;
    int ans = mincoins(n,coins,t,dp);
    cout<<ans<<endl;
    return 0;
}