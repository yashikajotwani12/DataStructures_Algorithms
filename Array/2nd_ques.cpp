#include<bits/stdc++.h>
using namespace std;
int minarray(int arr[], int n)
{
    // return *min_element(arr,arr+n);
    return (n==0)?arr[0]:min(arr[0],minarray(arr+1,n-1));// recursively calling the above function
}
int maxarray(int arr[], int n)
{
    return *max_element(arr,arr+n);
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<"The minimum element of an array is "<<minarray(arr,n)<<endl;
    cout<<"The maximum element of an array is "<<maxarray(arr,n);
    return 0;


}