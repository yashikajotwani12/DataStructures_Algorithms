#include<bits/stdc++.h>
using namespace std;

int storeocc(int *arr, int i, int n, int key, int *ouput, int j)
{
    if(i==n) return j+1;


}

void allocc(int *arr, int n, int i, int key)
{
    if(i==n) return;
    if(arr[i]==key) cout<<i<<" ";
    allocc(arr,n,i+1,key);
}

int main()
{
    int arr[]={1,2,3,7,4,5,6,7,10};
    int n=sizeof(arr)/sizeof(int);


    int output[100];
     int key=7;
    int count = storeocc(arr,0,n,key,output,0);
   
    allocc(arr,n,0,key);
    return 0;
}