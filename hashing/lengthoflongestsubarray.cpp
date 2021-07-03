#include<bits/stdc++.h>
using namespace std;

int longestsubarray0sum(int arr[], int n)
{
    unordered_map<int , int>m;
    int presum=0;
    int len =0;
    for(int i=0;i<n;i++)
    {
        presum+=arr[i];
        if(arr[i]==0)
        {
            len = max(len, i+1);
        }
        if(m.find(presum)!=m.end())
        {
            len = max(len, i - m[presum]);
        }else
        {
            //store the first occurrence
            m[presum]=i;
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
    int ans=  longestsubarray0sum(arr,n);
    cout<<ans<<endl;
    return 0;

}