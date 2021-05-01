#include<bits/stdc++.h>
using namespace std;
void printarray(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void sortarray(int arr[], int n)
{
    int i;
    int c0=0;
    int c1=0;
    int c2=0;
    for(int i=0;i<n;i++)
    {
        switch (arr[i])
        {
        case 0:
             c0++;
            break;
        case 1:
             c1++;
            break;
        case 2:
             c2++;
            break;
        
        default:
            break;
        }
    }
    i=0;
    while(c0 >0)
    {
        arr[i++]=0;
        c0--;
    }
    while(c1 >0)
    {
        arr[i++]=1;
        c1--;
    }
    while(c2 >0)
    {
        arr[i++]=2;
        c2--;
    }
    printarray(arr,n);
}

int main()
{
    int arr[]={0,2,1,1,0,2,2,1,0,1,0,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    sortarray(arr,n);
    return 0;
}