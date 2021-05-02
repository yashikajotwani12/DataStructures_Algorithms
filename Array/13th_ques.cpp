#include<bits/stdc++.h>
using namespace std;
int getpair(int arr[], int n, int sum)
{
    unordered_map<int , int>m;
    for(int i=0;i<n;i++)
    {
        m[arr[i]]++;
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        count+=m[sum-arr[i]];

        if(sum-arr[i]==arr[i])
           count++;
    }
    return count/2;
}
int main()
{
    int arr[]={1,5,7,-1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=6;
    cout<<getpair(arr,n , sum);
    return 0;
}