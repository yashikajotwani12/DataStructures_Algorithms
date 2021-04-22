#include<bits/stdc++.h>
using namespace std;
int maxlen(int arr[], int n)
{
    int maxlength=0;
    int sum=0;
    unordered_map<int , int>maps;
    for(int i=0;i<n;i++)
    {
       sum+=arr[i];
       if(arr[i]==0 && maxlen==0)
       {
           maxlength=1;
       }
       if(sum==0)
       {
           maxlength=i+1;
       }
       if(maps.find(sum)!=maps.end())
       {
           maxlength=max(maxlength,i-maps[sum]);
       }else
       {
        maps[sum]=i;
       }
    }
    return maxlength;

}
int main() 
{ 
    int arr[] = { 15, -2, 2, -8, 1, 7, 10, 23 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << "Length of the longest 0 sum subarray is "
         << maxlen(arr, n); 
  
    return 0; 
} 