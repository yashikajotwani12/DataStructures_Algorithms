#include<bits/stdc++.h>
using namespace std;

int binarys(int arr[], int low, int high)
{
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==mid)
        {
            return mid;
        }else if(mid > arr[mid])
        {
            return binarys(arr,(mid+1), high);
        }else{
            return binarys(arr,low, mid-1);
        }
    }
    return -1;
}

int main()
{
    int arr[]={-10,-5,0,3,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    int fixedpoint = binarys(arr,0,n-1);
    cout<<fixedpoint<<endl;
return 0;

}