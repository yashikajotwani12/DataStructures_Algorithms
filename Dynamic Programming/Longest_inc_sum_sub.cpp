#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int>dp(n);
    int omax=0;
    for(int i=0;i<dp.size();i++)
    {
        int max=INT_MIN;
        for(int j=0;j<i;j++)
        {
            if(arr[j] < arr[i])
            {
                if(max == NULL)
                {
                     max = dp[j];
                }
                else if(dp[j]> max)
                {
                    max= dp[j];
                }
            }
        }
        if(max==NULL)
        {
            dp[i]=arr[i];
        }else{
            dp[i]= max+arr[i];
        }
        if(dp[i] > omax)
        {
            omax= dp[i];
        }
       
    }
     cout<<omax<<endl;
    return 0;
}