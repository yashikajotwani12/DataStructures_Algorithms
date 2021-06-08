#include<bits/stdc++.h>
using namespace std;

int minswaps(int arr[], int n)
{
    vector<pair<int , int>>v(n);
    for(int i=0;i<n;i++)
    {
        v[i]={arr[i],i};
    }
    sort(v.begin(),v.end());
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(v[i].second==i)
        {
            continue;
        }else{
            c++;
            swap(v[i],v[v[i].second]);
            i--;
        }
    }
    return c;
}
int main()
{
    int arr[]={1,5,4,3,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int ans = minswaps(arr,n);
    cout<<ans;
    return 0;
}