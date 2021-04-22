#include<iostream>
#include<list>
// #include<bits/stdc++.h>
using namespace std;

class graph{
    int v;
    list <int> *adj;
    public:
    graph(int v);
    void addEdge(int v, int w);
    void bfs(int s);


};
graph::graph(int v)
{
    this->v=v;
    adj=new list<int>[v];
}
void graph::addEdge(int v, int u)
{
    adj[v].push_back(u);
}
void graph::bfs(int s)
{
    bool *visited=new bool[v];
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
    }
    list<int>qq;
    visited[s]=true;
    qq.push_back(s);

    list<int>::iterator i;
    while(!qq.empty())
    {
        s=qq.front();
        cout<<s<<" ";
        qq.pop_back();
        for(i=adj[s].begin();i!=adj[s].end();++i)
        {
            if(!visited[*i])
            {
                visited[*i]=true;
                qq.push_back(*i);
            }
        }
    }
}
int main()
{
    // Create a graph given in the above diagram
    graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.bfs(2);
 
    return 0;
}