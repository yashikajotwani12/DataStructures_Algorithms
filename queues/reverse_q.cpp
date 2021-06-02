#include<bits/stdc++.h>
using namespace std;

void reverseq(queue<int>&q)
{
    stack<int>st;
    while(!q.empty())
    {
        st.push(q.front());
        q.pop();

    }

    while(!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
}

void printq(queue<int>&q)
{
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
}
int main()
{
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    reverseq(q);
    printq(q);

    return 0;
}