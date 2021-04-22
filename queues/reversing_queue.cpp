#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void print( queue<int>&queue )
{
    while(!queue.empty())
    {
        cout<<queue.front()<<" ";
        queue.pop();
    }

}
void reversequeue(queue<int> &revq)
{
    stack<int>st;
    while(!revq.empty())
    {
        st.push(revq.front());
        revq.pop();

    }
    while(!st.empty())
    {
        revq.push(st.top());
        st.pop();
    }
}
int main()
{
    queue<int>qq;
    qq.push(10);
    qq.push(20);
    qq.push(30);
    qq.push(40);
    qq.push(50);
    qq.push(60);
    qq.push(70);
    qq.push(80);
    qq.push(90);
    qq.push(100);
    reversequeue(qq);
    print(qq);
    return 0;
}