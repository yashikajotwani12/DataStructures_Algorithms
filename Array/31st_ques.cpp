#include<bits/stdc++.h>
using namespace std;

void printrep(int arr[], int n)
{
    int *count = new int [sizeof(int)*(n-2)];
    int i;
    cout<<" Repeating elements are : ";
    for(int i=0;i<n;i++)
    {
        if(count[arr[i]]==1)
        {
            cout<<arr[i]<<" ";

        }else{
            count[arr[i]]++;
        }
    }



}
int main()
{
    int arr[]={4,2,4,5,2,3,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    printrep(arr,n);
    return 0;
}