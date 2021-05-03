#include<bits/stdc++.h>
using namespace std;
int find3(int arr[], int n , int k)
{
    int l,r;
    sort(arr,arr+n);
    for(int i=0;i<n-2;i++)
    {
        l=i+1;
        r=n-1;
        while(l<r)
        {
            if(arr[i]+arr[l]+arr[r] == k)
            {
                cout<<arr[i] <<" "<<arr[l]<<" "<<arr[r]<<endl;
                return true;
            }
            else if(arr[i]+arr[l]+arr[r] < k)
            {
                l++;
               
            }else{
                 r--;
            }
        }

    }
    return false;
}
int main()
{
    int arr[]={1,2,45,6,10,8 };
    int sum=22;
    int n=sizeof(arr)/sizeof(arr[0]);
    find3(arr,n,sum);
    return 0;
}