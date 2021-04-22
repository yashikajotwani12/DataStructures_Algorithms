#include<bits/stdc++.h>
using namespace std;

class graph{
    int v;
    list<int>*adj;
    void dfsutil(int v, bool visited[]);

    public:
    graph(int v);
    void addedge(int v, int w);
    void dfs(int v);

};

graph :: graph(int v)
{
    this->v=v;
    adj=new list<int>[v];

}