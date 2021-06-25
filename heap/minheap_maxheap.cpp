#include<bits/stdc++.h>
using namespace std;
void maxheapify(int arr[], int i, int n)
{
    int l=2*i+1;
    int r=2*i+2;
    int largest =i;
    if( l< n and arr[l]> arr[i])
    {
        largest =l;
    }
    if( r < n and arr[r]> arr[largest])
    {
        largest =r;
    }
    if(largest != i)
    {
        swap(arr[i], arr[largest]);
        maxheapify(arr, largest, n);
    }
}
void convertmaxheap(int arr[], int size)
{
    for(int i=(size-2)/2;i>=0;--i)
    {
        maxheapify(arr, i,size);
    }

}

void printarray(int *arr, int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[]={3,5,9,6,8,20,10,12,18,9};
    int n= sizeof(arr)/sizeof(arr[0]);
    cout<<" Min Heap Array  :"<<endl;
    printarray(arr,n);

    convertmaxheap(arr,n);
    cout<<" Max Heap Array  :"<<endl;
    printarray(arr,n);

    return 0;


}