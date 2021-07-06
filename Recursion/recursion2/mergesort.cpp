#include<bits/stdc++.h>
using namespace std;

void merge(int *a, int s, int e)
{
    int mid =(s+e)/2;

    int i =  s;
    int j = mid+1;
    int k = s;

    int temp[100];
    while(i<=mid and j<=e)
    {
        if(a[i] < a[j])
        {
            temp[k++]=a[i++];
        }else{
            temp[k++] = a[j++];
        }
    }
    while(i<=mid)
    {
        temp[k++]=a[i++];

    }
    while(j<=e)
    {
          temp[k++] = a[j++];
    }
    for(int i=s;i<=e;i++)
    {
        a[i]=temp[i];
    }

}

void mergesort(int a[], int s, int e)
{
    // base case -1 or 0 elements
    if(s==e)
    {
        return;
    }

    // follow 3 steps:
    // divide
    int mid = (s+e)/2;

    // recursively sort arrays from s to mid and mid+1 to e

    mergesort(a, s, mid);
    mergesort(a,mid+1,e);

    // merge the sorted arrays
    merge(a,s,e);

}


int main()
{
    int n;
    cin>>n;
    int arr[10];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}