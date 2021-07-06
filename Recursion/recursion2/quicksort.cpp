// used in libraries
// divide and conquer
// nlogn time 
// worst case : o n2 can be optimized using randomized
// inplace algo
// requires extra space for recursion call stack
// steps:
//1> choose the pivot
// 2 7 8 6 1 5 4 
//             |
//           pivot
// 2> divide  -> elements <= pivot  // partition function most imp
//            -> elements >=pivot
// 2,1,   4   , 7 ,6,5,8
//
// 3> recursively sort the smaller part
#include<bits/stdc++.h>
using namespace std;
int partiton(int *arr, int s, int e)
{
    // inplace 
    int i=
    int j=
    

}
void quicksort(int *arr, int s, int e)
{
    if(s >=e)
    {
        return;
    }
    int p = partition(arr,s,e);

    quicksort(arr,s,p-1);
    quicksort(arr, p+1,e);
}

int main()
{
    int arr[]={2,7,8,6,1,5,4};
    int n=sizeof(arr)/sizeof(int);
    quicksort(arr,0,n-1);


    return 0;
}