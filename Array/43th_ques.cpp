#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={4,3,6,2,1,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    unordered_map<int , bool>mp;
    for(int i: arr)
    {
        if(mp.find(i)== mp.end())
        {
            mp[i]=true;
        }else{
            cout<<"Repeating is : "<<i;
        }
    }
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        if(mp.find(i)==mp.end())
        {
            cout<<" Missing is : "<<i;
        }
    }
    cout<<endl;
    return 0;
}