#include<bits/stdc++.h>
using namespace std;

vector<int> nextgreaterelement(vector<int>& arr, int n)
{
    vector<int> ans(n);
    stack<int>s;
    for(int i=n-1;i>=0;i--)
    {
        while(!s.empty() && arr[i] >=s.top())
        {
            s.pop();
        }
        if(!s.empty())
        {
            ans[i]=s.top();
        }
        else{
            arr[i]=-1;
           
        }
         s.push(arr[i]);
    }
    return ans;
}
int main()
{
    vector<int>arr;
    arr.push_back(7);
    arr.push_back(12);
    arr.push_back(1);
    arr.push_back(20);
    cout<<"next greater element ";
    arr = nextgreaterelement(arr,4);
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;



}