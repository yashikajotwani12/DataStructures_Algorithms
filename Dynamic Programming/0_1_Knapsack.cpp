#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int dp[1000][1000];
    int solve(int w,int wei[], int val[],int n)
    {
        if(w==0 or n==-1) return 0;
        if(dp[n][w]!=-1) return dp[n][w];
        if(wei[n]>w)
        {
            return dp[n][w] = solve(w,wei,val,n-1);
        }
        int a,b;
        a = val[n] + solve(w-wei[n], wei,val,n-1);
        b = solve(w,wei,val,n-1);
        return dp[n][w] = max(a,b); 

    }
    int knapsack( int w, int wei[],int val[],int n)
    {
        int dp[n][w];
        memset(dp,-1,sizeof(dp));
        return solve(w,wei,val,n);
    }

};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,w;
        cin>>n>>w;
        int wei[n];
        int val[n];
        for(int i=0;i<n;i++)
        {
          cin>>wei[i];
        }
        for(int i=0;i<n;i++)
        {
          cin>>val[i];
        }
        Solution ob;
        cout<<ob.knapsack(w,wei,val,n)<<endl;
    }
    return 0;
}
