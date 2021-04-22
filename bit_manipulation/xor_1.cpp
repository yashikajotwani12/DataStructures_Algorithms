// function returning only odd occuring element
#include<iostream>
using namespace std;
int findodd(int arr[], int n)
{
    int res=0,i;
    for(i=0;i<n;i++)
    {
        res^=arr[i];
    }
    return res;

}
int main()
{
    int arr[]={12,12,14,90,14,14,14};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("odd one is %d",findodd(arr,n));
    return 0;
}