#include<bits/stdc++.h>
using namespace std;
// void printrep(int arr[], int n)
// {
//     int i;
//     for(i=0;i<n;i++)
//     {
//         if(arr[abs(arr[i])] >=0)
//         {
//             arr[abs(arr[i])] = -arr[abs(arr[i])];

//         }else{
//             cout<<abs(arr[i])<<" ";
//         }
//     }
// }


int main()
{
    int arr[]={1,2,3,1,3,6,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    // printrep(arr,n);

    for(int i=0;i<n;i++)
    {
        arr[arr[i]%n]=arr[arr[i]% n]+n;
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i] >=n*2)
        {
            cout<<i<<" ";
        }
    }
    return 0;
}