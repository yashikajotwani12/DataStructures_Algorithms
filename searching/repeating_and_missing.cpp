#include<bits/stdc++.h>
using namespace std;


int *findtwo(int *arr, int n)
{
    int a,b;
    for(int i=0;i<n;i++)
    {
        if(arr[abs(arr[i])-1]<0)
        {
            a=abs(arr[i]);
        }
        else{
            arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
        }
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]>0)
        {
            b=i+1;
            break;
        }
    }
    int*v = new int[2];
    v[0]=a;
    v[1]=b;
    return v;


}
int main()
{
    int arr[]={4,3,6,2,1,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    




    return 0;
}