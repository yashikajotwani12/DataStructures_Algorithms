#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[], int n , int i)
{
   int largest =i;
   int l = 2*i+1;
   int r =2*i+2;

   if(l< n and arr[l]> arr[largest])
   {
       largest=l;
       
   } 
   if(r< n and arr[r]> arr[largest])
   {
       largest=r;
      
   } 

   if(largest !=i)
   {
       swap(arr[i], arr[largest]);
   }
   heapify(arr,n, largest);
}
void buildheap(int arr[], int n)
{
    int startidx=(n/2)-1;
    for(int i=startidx; i>=0;i--)
    {
        heapify(arr,n,i);
    }
}
void printheap(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[]={1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    int n=sizeof(arr)/sizeof(arr[0]);
    buildheap(arr, n);
    printheap(arr, n);

    return 0;
}


//edited
