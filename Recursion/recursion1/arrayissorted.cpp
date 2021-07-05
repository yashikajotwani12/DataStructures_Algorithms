// problem to check if the array is sorted recursively
#include<bits/stdc++.h>
using namespace std;
bool issorted(int arr[], int n)
{
    if(n==0 or n==1)
    {
        return true;
    }
    if((arr[0] < arr[1]) and issorted(arr+1,n-1));
    {
        return true;
    }
    return false;
}
int main()
{
    int arr[]={1,22,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    // if(issorted(arr,n))
    // {
    //     cout<<"Yes";
    // }else{
    //     cout<<"No";
    // }
    cout<<issorted(arr,n)<<endl;
    return 0;
}