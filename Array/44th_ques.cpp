#include<bits/stdc++.h>
using namespace std;
int stock(int arr[], int n)
{
    int min_so_far=arr[0];
    int profit=0;
    int maxprofit=0;
    for(int i=0;i<n;i++)
    {
        min_so_far = min(min_so_far, arr[i]);
        profit = arr[i] - min_so_far;
        maxprofit= max(maxprofit, profit);

    }
    return maxprofit;
}
int main()
{
    int arr[]={7,1,5,3,6,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<stock(arr,n);
    return 0;
}