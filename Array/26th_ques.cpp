#include<bits/stdc++.h>
using namespace std;
int findmin(int arr[], int low, int high)
{
    int mid= low + (high-low)/2;
    if(arr[mid] == arr[high])
    {
        high--;
    }
    else if(arr[mid] > arr[high])
    {
        low=mid+1;
    }
    else{
        high= mid;
    }
return arr[high];
}
int main()
{
    int arr[]={2,3,4,5,6,7,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<" ans is : "<<findmin(arr,0, n-1);
    return 0;
}