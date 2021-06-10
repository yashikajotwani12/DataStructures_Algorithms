#include<bits/stdc++.h>
using namespace std;

int peak(int arr[], int n)
{
    if(n==1)
    return arr[0];


    if(arr[0]>=arr[1])
    return arr[0];

    if(arr[n-1]>=arr[n-2])
    return arr[n-1];


    int l=1;
    int r=n-2;
    int ans=l;

    while(l<=r)
    {
        int mid=(l+r)/2;
        if(arr[mid] < arr[mid-1])
        {
           r=mid-1;
        }else if(arr[mid] < arr[mid+1])
        {
            l=mid+1;
        }else{
            ans=mid;
            break;
        }
    }
    return arr[ans];
}



int main()
{
    int arr[]={1, 8, 3,5 ,2};
    int n=5;
    cout<<peak(arr,n);
    return 0;
}