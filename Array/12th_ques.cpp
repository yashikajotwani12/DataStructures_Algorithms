#include<bits/stdc++.h>
using namespace std;
int getmissing(int arr[], int n)
{
    int a=arr[0];
    int b=1;
    for(int i=1;i<n;i++)
    {
        a=a^arr[i];
    }
    for(int i=2;i<=n+1;i++)
    {
        b=b^i;
    }
    return (a^b);
}
int main()
{
    
    int arr[]={1,2,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<< getmissing(arr,n);
   return 0;
}