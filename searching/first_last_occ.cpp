#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int n, int x, int tog)
{
    int high=n-1;
    int low=0;
    int ans=-1;
  
    while(low<=high)
    {
          int mid=(high+low)/2;
          if(arr[mid] < x)
          {
              low=mid+1;
          }else if(arr[mid] > x)
          {
              high=mid-1;
          }else{
              ans=mid;
              if(tog==-1) high =mid+tog;
              else low=mid+tog;

          }

    }
    return ans;
}

int main()
{
    int arr[]={1,3,5,5,5,5,67,123,125};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x=5;
    int ind1 = solve(arr,n, x,-1);
    int ind2 = solve(arr,n, x,1);
    if(ind1==-1)
    {
    cout<<"-1\n";

    }else
    {
        cout<<ind1<<" "<<ind2<<endl;
    }
    return 0;
}