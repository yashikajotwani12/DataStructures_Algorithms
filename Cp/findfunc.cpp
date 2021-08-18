#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={1,3,4,4,52,1,25,9};
    int n = 8;
    int key = 5200;
    auto it = find(arr, arr+n, key);
    int index = it - arr;
    if(index ==n)
    {
        cout<<key<<"not present "<<endl;
    }else{
      cout<<index<<endl;
    }
    int arr1[]={20,30,40,40,50,100,1100};
    int n1= 7;

    auto ite = lower_bound(arr1,arr1+n1,40);
    auto itie = upper_bound(arr1,arr1+n1,40);
    cout<<(ite-arr1)<<endl;
    cout<<(itie-arr1)<<endl;
   
    return 0;
}