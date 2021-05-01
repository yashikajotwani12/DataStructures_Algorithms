// frequency of an element in an array
#include<bits/stdc++.h>
using namespace std;
unordered_map<int , int>hm;
void countfreq(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        hm[arr[i]]++;
    }
}
int query(int x)
{
    return hm[x];
}
int main()
{
    int arr[]={1,3,2,4,3,2,1,2,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    countfreq(arr,n);
    cout<<query(2)<<endl;
    cout<<query(1)<<endl;
    cout<<query(3)<<endl;
    cout<<query(4)<<endl;
    return 0;
}