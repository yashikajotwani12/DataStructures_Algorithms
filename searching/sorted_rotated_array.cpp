#include<bits/stdc++.h>
using namespace std;
int searchrotated(int arr[], int n, int target)
{
    int low=0;
    int high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==target) return mid;
        else if(arr[mid]> arr[low])
        {
            if(arr[mid] >= target and arr[low]<=target)
            {
                high=mid-1;
            }else{
                low=mid+1;
            }
        }else{
            if(arr[mid] <=target and arr[high] >=target)
            {
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
    }
    return -1;
}

int main()
{
    int arr[]={4,5,6,7,1,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=6;
    int ans= searchrotated(arr, n, target);
    cout<<ans<<" \n";
    return 0;
}