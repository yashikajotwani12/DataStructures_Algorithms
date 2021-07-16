#include<bits/stdc++.h>
using namespace std;

int findplat(int arr[], int dep[], int n)
{
    sort(arr,arr+n);
    sort(dep,dep+n);
    int platform = 1;
    int result=1;
    int i=1;
    int j=0;
   while(i< n and j<n)
   {
       if(arr[i] <= dep[j])
       {
           platform++;
           i++;
       }else if(arr[i] > dep[j])
       {
           platform--;
           j++;
       }

       if(platform > result)
       {
           result=platform;
       }
   }
   return result;

}
int main()
{
    int arr[]={900,940,950,1100,1500,1800};
    int dep[]={910,1200,1120,1130,1900,2000};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Minimum no of platform req = "
        <<findplat(arr,dep,n);


    return 0;
}