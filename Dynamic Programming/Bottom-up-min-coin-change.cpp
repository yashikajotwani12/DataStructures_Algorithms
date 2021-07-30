#include<bits/stdc++.h>
using namespace std;
int mincoins(int n, int coins[], int T)
{
  int dp[100]={0};
  // iterate over all states
  for(int i=0;i<n;i++)
  {
     dp[i]=INT_MAX;
     for(int t=1;t<T;t++)
     {
        if(n-coins[i] >=0)
        {
            int subprob = dp[n-coins[i]];
            dp[i] = min(dp[i], subprob+1);
        }
     }
  }
  return dp[n];

}
int main()
{
    int n=15;
    int coins[]={1,7,10};
    cout<<mincoins(n,coins,3);
    return 0;
}