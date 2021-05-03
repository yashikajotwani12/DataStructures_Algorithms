#include<bits/stdc++.h>
using namespace std;
int maxsubarray(int arr[], int n)
{
    int maxsofar= arr[0];
    int currentmax=arr[0];
    for(int i=1;i<n;i++)
    {
        currentmax= max(arr[i], currentmax+arr[i]);
        maxsofar= max(maxsofar, currentmax);
    }
    return maxsofar;

}
int main()
{
    int arr[]={-2,-3,4,-1,-2,1,5,-3};
    int n= sizeof(arr)/sizeof(arr[0]);
    int maxsum= maxsubarray(arr,n);
    cout<<"Max sum is :" <<maxsum;
}