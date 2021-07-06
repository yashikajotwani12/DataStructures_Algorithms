#include<bits/stdc++.h>
using namespace std;
int merge(int *a, int s, int e)
{
    int mid =(s+e)/2;
    int i =s;
    int j=mid+1;
    int k=s;
    int temp[1000];
    int count=0;
    while(i<=mid and j<=e)
    {
        if(a[i] <= a[j])
        {
            temp[k++]=a[i++];
        }else{
            temp[k++] = a[j++];
            count += mid-i+1;
        }

    }
    // fill the array
    while(i<=mid)
    {
     temp[k++]=a[i++];   
    }
    while(j<=e)
    {
         temp[k++] = a[j++];

    }
    //copy all the elements
    for(int i=s;i<=e;i++)
    {
        a[i]=temp[i];
    }
    return count;
}

int inversioncount(int arr[], int s, int e)
{
    // base case
    if( s>= e)
    {
        return 0;
    }
    // mergesort
    // divide
    int mid =(s+e)/2;

    // conquering the sub problems
    int x = inversioncount(arr,s,mid);
    int y = inversioncount(arr, mid+1, e);
    int z = merge(arr,s,e); // cross inversions
    return x+y+z; // returning the solved problems in combined form
}
int main()
{
    int arr[]={1,5,2,6,3,0};
    int  n= sizeof(arr)/sizeof(arr[0]);
    cout<<inversioncount(arr,0,n-1)<<endl;
    return 0;
}