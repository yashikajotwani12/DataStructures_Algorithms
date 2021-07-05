#include<bits/stdc++.h>
using namespace std;

int firstocc(int *arr, int n, int key)
{
    if(n==0){
        return -1;
    }
    if(arr[0]== key)
    {
        return 0;
    }
    int i = firstocc(arr+1,n-1,key);
    if(i==-1) return -1;
    else return i+1;

}
// different syle
int linearsearch(int *arr,int i, int n, int key)
{
    // type of for loop 
    // base case
    if(i==n) return -1;// stopping criteria
    //rec 
    if(arr[i]==key) return i; // condition if found then return
    else return linearsearch(arr, i+1,n,key);// increment

}
int main()
{
    int arr[]={1,2,3,7,4,6,7,10};
    int n=sizeof(arr)/sizeof(int);
    int key=7;
   cout<< firstocc(arr,n,key);
    return 0;
}