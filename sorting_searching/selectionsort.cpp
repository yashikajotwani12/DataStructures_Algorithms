#include<bits/stdc++.h>
using namespace std;

int minindex(vector<int>&arr, int start)
{
    int mini = start;
    int i= start+1;
    while(i<arr.size())
    {
        if(arr[i]<arr[mini])
        {
            mini = i;
        }
        i++;
    }
    return mini;

}
void selectionsort(vector<int>arr)
{
    
    for(int i=0;i<arr.size();i++)
    {
       int mini = minindex(arr,i);
       if(mini !=i)
       {
           swap(arr[i], arr[mini]);
       }
    }
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
    selectionsort(arr);
    for(auto i:arr)
    {
        cout<<i<<" ";
    }
    return 0;
    
}