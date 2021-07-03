#include<bits/stdc++.h>
using namespace std;

int subarraysumk(int arr[], int n,int k)
{
    unordered_map<int,int>m;
    int sum=0;
    int len=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum == k)
        {
            len= max(len,i+1);

        }
        if(m.find(sum-k)!=m.end())
        {
            len = max(len, i-m[sum-k]);
        }else{
            m[sum]=i;
        }
    }
    return len;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];

    for(int i =0; i< n;i++)
    {
        cin>>arr[i];


    }
    int ans = subarraysumk(arr,n,3);
    cout<<ans<<endl;
    return 0;

}