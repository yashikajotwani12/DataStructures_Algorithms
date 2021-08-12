#include<bits/stdc++.h>
using namespace std;
int ladders(int n, int k)
{
    int dp[100]={0};
    if(n==0) return 0;
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        dp[i]=0;
        for(int j=1;j<=k;j++)
        {
            if(i-j>=0)
              dp[i]+=dp[i-j];
        }
    }
    // see the bottom up
    for(int i=0;i<=n;i++)
    {
        cout<<dp[i]<<" ";
    }
 return dp[n];
    
}
int main()
{
    int n, k;
    cin>>n>>k;

   cout<< ladders(n,k);
    return 0;
}
