#include<bits/stdc++.h>
using namespace std;

int lastocc(int arr[], int n, int key)
{
    // base case
    if(n==0) return -1;
    int i =lastocc(arr+1,n-1,key);
    if(i==-1)
    {
        if(arr[0]==key)
        {
            return 0;
        }
        else{
            return -1;
        }
    }
    return i+1;
}
int main()
{
    int arr[]={1,2,3,7,4,6,7,10};
    int n=sizeof(arr)/sizeof(int);
    int key=7;
   cout<<lastocc(arr, n, key);
   return 0;

}