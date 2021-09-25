#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
string s;
int countsq(int i,int j)
{
    if(i>j) return 0;
    if(i==j) return dp[i][j]=1;
    if(dp[i][j]!=-1) return dp[i][j];
    else if(s[i]==s[j])
    {
      return  dp[i][j] = countsq(i,j-1)+ countsq(i+1,j+1);
    }else 
    {
        return dp[i][j] = countsq(i,j-1)+countsq(i+1,j) + countsq(i+1,j-1);
    }



}
int main()
{    
    cin>>s;
    int n = s.size();
    memset(dp,-1,sizeof(dp));
   cout<< countsq(0,n-1)<<endl;

    return 0;
}