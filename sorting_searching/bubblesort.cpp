#include<bits/stdc++.h>
using namespace std;
vector<int>bubblesort(vector<int>arr)
{
    int n= arr.size();
    for(int i=0;i<n-1;i++ )
    {
        bool isswapped = false;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                isswapped=true;
            }
        }
        if(!isswapped)
        {
            break;
        }
    }
    return arr;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int>ans = bubblesort(arr);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    return 0;
}