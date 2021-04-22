#include<bits/stdc++.h>
using namespace std;
class graph{
    int v;
    list<int>*adj;
    void dfsutil(int v, bool visited[]);
    public:
    graph(int v);
    void addEdge(int v, int u);
    void dfs(int v);

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
void graph::dfsutil(int v, bool visited[])
{
    visited[v]=true;
    cout<<v<<" ";
    list<int>::iterator i;
    for(i=adj[v].begin();i!=adj[v].end();++i)
    {
        if(!visited[*i])
        {
            dfsutil(*i,visited);
        }
    }
}
void graph::dfs(int v)
{
    bool*visited=new bool[v];
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
    }

    dfsutil(v,visited);
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
 
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.dfs(2);
 
    return 0;
}