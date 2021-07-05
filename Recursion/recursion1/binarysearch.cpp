#include<bits/stdc++.h>
using namespace std;

// int binarysearch(int arr[], int n, int key)
// {
//     int left =arr[0];
//     int right = arr[n-1];
//     while(left < right)
//     {
//         int mid = (left+right)/2;
//         if(arr[mid]==key)
//         {
//             return mid;
//         }else if(arr[mid] > key)
//         {
//             right = mid-1;
//         }else{
//             left = mid+1;
//         }
//     }
// }
int binarysearch(int arr[], int left, int right, int key)
{
    

    int mid = (left+(right-1))/2;
    if(arr[mid]==key)
    {
        return mid;
    }
    if(arr[mid] > key)
    {

     return binarysearch(arr,left,mid-1,key);
    }
     else{
        return   binarysearch(arr, mid+1,right,key);

     }
     return -1;

   
}
int main()
{
    int arr[]={3,4,5,7,1,2,9,10,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int key=9;
    cout<<binarysearch(arr,0,n-1,key);

    return 0;
}