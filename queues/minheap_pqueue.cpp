//demonstrate min heap
#include<iostream>
#include<queue>
using namespace std;
void show(
    priority_queue<int, vector<int>,greater<int>>gp)
{
    priority_queue<int, vector<int>,greater<int>>g=gp;
    while(!g.empty())
    {cout<<'\t'<<g.top();
    g.pop();

    }
    cout<<'\n';
}
int main()
{
    priority_queue<int, vector<int>,  
                       greater<int> > gquiz;
    gquiz.push(10);
    gquiz.push(30);
    gquiz.push(20);
    gquiz.push(5);
    gquiz.push(1);
 
    cout << "The priority queue gquiz is : ";
    show(gquiz);
 
    cout << "\ngquiz.size() : " << gquiz.size();
    cout << "\ngquiz.top() : " << gquiz.top();
 
    cout << "\ngquiz.pop() : ";
    gquiz.pop();
    show(gquiz);
 
    return 0;
}