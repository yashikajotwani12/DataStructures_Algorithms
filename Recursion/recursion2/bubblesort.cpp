#include<bits/stdc++.h>
using namespace std;


void bubblesort(int arr[], int n)
{
    if(n==1) return;

// after you have moved the largest elemenst in the current part to the end of the array by pairwise swapping
    for(int j=0;j<n-1;j++)
    {
        if(arr[j] > arr[j+1])
        {
            swap(arr[j], arr[j+1]);
        }
    }
    // sort the first n-1 elements
    bubblesort(arr, n-1);


}
void bubblesort_recursive(int arr[], int j , int n)
{
    if(n==1) return;
    if(j==n-1)
    {
        // single pass of the current array
        return bubblesort_recursive(arr,0,n-1);
    }
    if(arr[j] > arr[j+1])
    {
        swap(arr[j], arr[j+1]);
    }
    bubblesort_recursive(arr, j+1,n);
    return ;


}

int main()
{
    int arr[]={5,4,3,1,2};
    int n=5;
    bubblesort(arr, n);
    return 0;
}