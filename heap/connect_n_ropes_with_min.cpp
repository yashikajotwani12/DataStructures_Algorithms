#include<bits/stdc++.h>
using namespace std;
int mincost(int arr[], int n)
{
    priority_queue<int, vector<int>, greater<int>>pq(arr,arr+n);
    int res=0;
    while(pq.size()>1)
    {
        int first =pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        res+=first+second;
        pq.push(first+second);
    }
    return res;
}


int main()
{
     int len[] = { 4, 3, 2, 6 };
    int size = sizeof(len) / sizeof(len[0]);
    cout << "Total cost for connecting ropes is " << mincost(len, size);
    return 0;
}