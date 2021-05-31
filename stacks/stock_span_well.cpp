#include<bits/stdc++.h>
using namespace std;
void stockspan(int price[], int n, int span[])
{
    stack<int>s;
    s.push(0);
    span[0]=1;
    for(int i=1;i<=n-1;i++)
    {
        int currentprice = price[i];
        while(!s.empty() and price[s.top()]<=currentprice)
        {
            s.pop();
        }
        if(!s.empty())
        {
        int prevhighest = s.top();
        span[i]=i-prevhighest;
        }else{
            span[i]=i+1;
        }
        s.push(i);

    }
}

int main()
{
    int prices[]={100,80,60,70,60,75,85};
    int n = sizeof(prices)/sizeof(prices[0]);
    int span[100000]={0};
    stockspan(prices,n,span);
    for(int i=0;i<n;i++)
    {
        cout<<span[i]<<" ";
    }
    return 0;


}