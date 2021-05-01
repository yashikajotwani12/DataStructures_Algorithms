#include<bits/stdc++.h>
using namespace std;

void solve(int arr[], int left, int right)
{
    while(left <=right)
    {
        if(arr[left]<0 && arr[right] <0) left++;
        else if(arr[left] >0 && arr[right] <0 ) {swap(arr[left], arr[right]); left++; right--;}
        else if(arr[left] >0 && arr[right] >0) right--;
        else left++;right--;

    }
}
void display(int arr[], int right)
{
    for(int i=0;i<=right;++i)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[]={-12,11,-13,-5,6,-7,5,-3,11};
    int n=sizeof(arr)/sizeof(arr[0]);
    solve(arr,0,n-1);
    display(arr,n-1);
    return 0;
}