#include<bits/stdc++.h>
using namespace std;
int search(int arr[], int n, int x)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==x)
        {
            return i;
        }
        
    }
    return -1;
}
int main()
{
    int arr[]={2,3,4,10,40};
    int x=10;
    int n=sizeof(arr)/sizeof(arr[0]);

    int result=search(arr,n,x);
    (result==-1)
    ?cout<<" element is not present in the array"
    : cout<<"element is present at index "<<result;
    return 0;
}