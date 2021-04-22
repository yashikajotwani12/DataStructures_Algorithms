//find the missing number
//1st approach
#include<iostream>
using namespace std;
// int getmissing(int arr[], int n)
// {
//     int total=(n+1)*(n+2)/2;
//     for(int i=0;i<n;i++)
//     {
//         total-=arr[i];
//     }
//     return total;
// }
// int main()
// {
//     int arr[]={1,2,3,4,6};
//     int n=sizeof(arr)/sizeof(arr[0]);
//     int miss= getmissing(arr,n);
//     cout<<miss;
//     return 0;
// }

// optimized 1st approach

// int getmissing(int arr[], int n)
// {
//     int total=1;
//     for(int i=2;i<=(n+1);i++)
//     {
//         total+=i;
//         total-=arr[i-2];
//     }
//     return total;
// }
// int main()
// {
//     int arr[]={1,2,3,4,6};
//     int n=sizeof(arr)/sizeof(arr[0]);
//     int miss= getmissing(arr,n);
//     cout <<miss;
//     return 0;
// }

// method2:
int getmissing(int arr[], int n)
{
    int x=arr[0];
    int y=1;
    for(int i=1;i<n;i++)
    {
        x=x^arr[i];
    }
    for(int i=2;i<=n+1;i++)
    {
        y=y^i;
    }
    return (x^y);
}
int main()
{
    int arr[]={1,2,3,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int miss= getmissing(arr,n);
    cout <<miss;
    return 0;
}