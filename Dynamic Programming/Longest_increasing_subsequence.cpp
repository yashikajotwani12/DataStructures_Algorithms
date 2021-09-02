#include<bits/stdc++.h>
using namespace std;
long long lis(vector<int>&arr)
{
  vector<long long>dp(arr.size(),1);
  for(int i=1;i<arr.size();i++)
  {
      for(int j=0;j<i;j++)
      {
          if(arr[j] < arr[i])
          {
              dp[i]  = max(dp[i],dp[j]+1);
          }
      }
  }
  long long result  = INT_MIN;
  for(int i=0;i<dp.size();i++)
  {
      result = max(result, dp[i]);
  }
  return result;

}
int main()
{
  vector<int>arr{2,4,1,6,3,8,10};
  cout<< lis(arr)<<endl;
    return 0;
}