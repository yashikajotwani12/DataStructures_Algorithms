#include<bits/stdc++.h>
using namespace std;

void printclosest(int arr[], int n , int x)
{
    int res_l,res_r;
    int l=0;
    int r=n-1;
    int diff=INT_MAX;
    while(r > l )
    {
        if(abs(arr[r]+arr[l]-x) < diff)
        {
            res_l = l;
            res_r = r;
            diff = abs(arr[l]+arr[r]-x);
        }

        if(arr[l]+arr[r] > x)
        r--;
        else
        l++;

    }
    cout<<"The closest pair would be "<<arr[res_l]<<" and "<<arr[res_r];


}
int main()
{
    int arr[]={10,22,28,29,30,40};
    int x=54;
    int n=sizeof(arr)/sizeof(arr[0]);
    printclosest(arr,n,x);
    return 0;
}