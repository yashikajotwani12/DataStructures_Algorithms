#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>arr, int n)
{
   vector<int>dp(n+1);
   dp[0]=0;
   dp[1]=0;
   for(int i=2;i<=n;i++)
   {
       dp[i]= min(dp[i-1]+abs(arr[i]-arr[i-1]),dp[i-2]+abs(arr[i]-arr[i-2]));
   }
   return dp[n];
   
}

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    cout<<solve(arr,n);
    return 0;
}