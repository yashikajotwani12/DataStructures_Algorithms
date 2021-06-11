#include<bits/stdc++.h>
using namespace std;
int majority(int arr[], int n)
{
    int major=arr[0];
    int count=1;
    for(int i=1;i<n;i++)
    { 
        if(arr[i]==major) count++;
        else count--; 
        if(count==0)
        {
            major=arr[i];
            count=1;
        }
    }
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==major) c++;
    }
    if(c > n/2) return major;
    else return -1;
}



int main()
{
    int arr1[]={3,1,3,3,2,1,2,3};
    int n= sizeof(arr1)/sizeof(arr1[0]);
    cout<<majority(arr1,n);

    return 0;
}