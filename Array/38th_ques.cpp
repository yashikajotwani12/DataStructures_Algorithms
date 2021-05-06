#include<bits/stdc++.h>
using namespace std;
void findme(int arr[], int n)
{
    unordered_map<int, int>mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }
    int count=0;
    for(auto i: mp)
    {
        if(i.second > n/2)
        {
            count=1;
            cout<<"Majority element  is "<<i.first<<endl;
            break;
        }
    }
    if(count==0)
    {
        cout<<"No majority Element "<<endl;
    }
}
int main()
{
    int arr[]={2,2,2,2,5,5,2,3,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    findme(arr,n);
    return 0;
}