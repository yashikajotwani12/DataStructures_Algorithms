#include<bits/stdc++.h>
using namespace std;
int findlongestcon(int arr[], int n)
{
    priority_queue<int, vector<int>, greater<int>>pq;

    for(int i=0;i<n;i++)
    {
        pq.push(arr[i]);
    }

    int prev= pq.top();
    pq.pop();
    int count=1;
    int max=1;

    for(int i=1;i<n;i++)
    {
        if(pq.top() - prev >1)
        {
            count=1;
            prev=pq.top();
            pq.pop();
        }else if(pq.top()- prev ==0)
        {
            prev= pq.top();
            pq.pop();
        }else{
            count++;
            prev= pq.top();
            pq.pop();
        }
        if(max < count)
        {
            max=count;
        }
    }
    return max;
}

int main()
{
    int arr[]={1,9,3,10,4,20,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<" ans is : "<<findlongestcon(arr,n);
    return 0;
}