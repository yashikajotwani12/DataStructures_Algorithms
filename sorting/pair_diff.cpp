#include<bits/stdc++.h>
using namespace std;
bool findpair(int arr[], int n, int diff)
{
    int i=0;
    int j=1;
    while(i<n and j<n)
    {
        if(i!=j and arr[j]-arr[i]==diff)
        {
            cout<<"Pair found "<< arr[i]<<" "<<arr[j]<<endl;
            return true;
        }else if(arr[j]-arr[i] < diff)
        {
            j++;
        }
        else
        {
            i++;
        }
       
    }
     cout<<"No such pair";
        return false;
}
int main()
{
    int arr[]={5,20,3,2,50,80};
    int n=sizeof(arr)/sizeof(arr[0]);
    int diff=78;
    findpair(arr,n,diff);
    return 0;
}