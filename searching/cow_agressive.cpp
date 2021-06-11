#include<bits/stdc++.h>
using namespace std;

int countcows(int arr[], int n, int c)
{
    sort(arr,arr+n);
    int ub =1e9;
    int lb=1;
    int ans=0;
    while(lb<=ub)
    {
        int mid= (ub+lb)/2;
        int cow=1;
        int prev=arr[0];
        for(int i=1;i<n;i++)
        {
            if(arr[i] - prev >=mid)
            {
                cow++;
                prev=arr[i];
                if(c==cow) break;
            }
        }
        if(cow == c)
        {
            ans= mid;
            lb=mid+1;
        }else{
            ub=mid-1;
        }
       
    }
     cout<<ans<<endl;

}
int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
    int N[]={1,5,8,11,13,16};
    int cows=4;
    int n=6;
    countcows(arr,n,cows);

    return 0;
}