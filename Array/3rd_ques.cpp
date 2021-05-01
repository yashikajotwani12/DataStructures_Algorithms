#include<bits/stdc++.h>
using namespace std;
void reverse(int arr[], int start, int end)
{
    if(start >= end)
    return;
    int temp=arr[start];
    arr[start]=arr[end];
    arr[end]=temp;

    reverse(arr,start+1,end-1);


}
void printarry(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
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
    reverse(arr,0,n-1);
   cout<<"the reversed array is "<<" ";
   printarry(arr,n);
    


}
