#include<bits/stdc++.h>
using namespace std;
int las(int arr[], int n)
{
    int inc=1;
    int dec=1;
  for(int i=1;i<n;i++)
  {
      if(arr[i] > arr[i-1])
      {
          inc=dec+1;

      }else if(arr[i] < arr[i-1])
      {
          dec=inc+1;
      }
  }
  return max(inc,dec);
}
int main()
{
    int arr[]={10,22,9,33,49,50,31,60};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<las(arr,n);
    return 0;
}