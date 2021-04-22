#include<iostream>
#include<queue>
using namespace std;
void show( priority_queue<int>pq )
{
    priority_queue<int> g= pq;
    while(!g.empty())
    {
        cout<<'\t'<<g.top();
        g.pop();
    }
    cout<<'\n';


}
int main()
{
    priority_queue<int> qp;
    qp.push(20);
    qp.push(90);
    qp.push(40);
    qp.push(10);
    qp.push(100);
    cout<<"priority queue is: ";
    show(qp);
    cout<<"size is "<<qp.size()<<endl;
    cout<<"top is "<<qp.top()<<endl;
    qp.pop();
    show(qp);
    return 0;
}