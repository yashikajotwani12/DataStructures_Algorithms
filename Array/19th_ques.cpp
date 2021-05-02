#include<bits/stdc++.h>
using namespace std;
void solve(int arr[], int n)
{
    sort(arr,arr+n); //O(nlog n)
    // cout<<arr[n-1]<<" ";
    // cout<<arr[n-2]<<" ";
    // cout<<arr[n-3]<<" ";
    int check=0;
    int count=1;
    for(int i=1;i<=n;i++)
    {
        if(count <4)
        {
        if(check !=arr[n-i])
        {
            cout<<arr[n-i]<<" ";
            check=arr[n-i];
            count++;

        }
        }else{
            break;
        }

    }


}
int main()
{
    int arr[]={12,45,1,-1,45,54,23,5,0,-10};
    int n=sizeof(arr)/sizeof(arr[0]);
    solve(arr,n);
    return 0;
}