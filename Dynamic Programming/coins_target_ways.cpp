#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int dp[1000][1000];

    int solve(int s[], int m, int n)
    {
        if(m==-1 and n>0) return 0;
        if(n==0) return 1;
        if(n<0) return 0;
        
       if(dp[m][n]!=-1) return dp[m][n];
        return dp[m][n]=solve(s,m-1,n) + solve(s,m,n-s[m]);

    }

    int countcoinways(int s[], int m, int n)
    {
        int dp[m][n+1];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                dp[i][j]=-1;
            }
        }
        return solve(s,m-1,n);
    }

};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int arr[m];
        for(int i=0;i<m;i++)
        {
          cin>>arr[i];
        }
        Solution ob;
        cout<<ob.countcoinways(arr,m,n)<<endl;
    }
   return 0;
}