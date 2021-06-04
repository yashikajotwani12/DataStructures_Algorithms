#include<bits/stdc++.h>
using namespace std;

void dnfsort(int arr[], int n)
{
    int low=0;
    int mid=0;
    int high=n-1;
   
    while(mid<=high)
   {

        
        if(arr[mid]==0)
        {
            swap(arr[low],arr[mid]);
            mid++;
            low++;
        }else if(arr[mid]==2)
        {
            swap(arr[high], arr[mid]);
            high--;

        }else{
            mid++;
        }
    
    }
}
int main()
{
    int arr[]={1,1,2,0,0,1,2,2,1,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    dnfsort(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}