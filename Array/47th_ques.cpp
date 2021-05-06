#include<bits/stdc++.h>
using namespace std;

int findlongest(int arr[], int n)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int max=1;
    for(int i=0;i<n;i++)
    {
        pq.push(arr[i]);
    }
     int prev= pq.top();
    pq.pop();
    int c=1;
    while(!pq.empty())
    {

    if(pq.top() - prev > 1)
    {
        c=1;
        prev=pq.top();
        pq.pop();
    }else if(pq.top()-prev==0)
    {
        prev=pq.top();
        pq.pop();
    }else{
        c++;
        prev=pq.top();
        pq.pop();
    }
    if(max < c)
    {
        max=c;
    }
}
   
 return max;

}
int main()
{
    int arr[]={1,9,3,10,4,20,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<" Longest Consecutive subsequence is :"<<findlongest(arr,n);
    return 0;
}