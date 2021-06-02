#include<bits/stdc++.h>
using namespace std;


void printnse(int arr[], int n)
{
    stack<int>s;
    unordered_map<int , int>mp;
    s.push(arr[0]);
    for(int i=1;i<n;i++)
    {
        if(s.empty())
        {
            s.push(arr[i]);
            continue;
        }
        while(!s.empty() and s.top() > arr[i])
        {
            mp[s.top()]=arr[i];
            s.pop();
        }
        s.push(arr[i]);
    }
    while(!s.empty())
    {
        mp[s.top()]=-1;
        s.pop();
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"-->"<<mp[arr[i]]<<endl;
    }

}
int main()
{
    int arr[]={11,12,21,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    printnse(arr, n);
    return 0;
}