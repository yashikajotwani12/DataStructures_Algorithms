// print connected components in an undirected graph

#include<bits/stdc++.h>
using namespace std;

class graph{
    int v;
    list<int>*adj;
    void dfsutil(int v, bool visited[]);

    public:
    graph(int v);
    ~graph();
    void addedge(int v, int w);
    void connectedcomponents();
};

void graph :: connectedcomponents()
{
    bool *visited =new bool[v];
    for(int i=0;i<v;i++)
    {
        visited[v]=false;
    }
    for(int i=0;i<v;i++)
    {
        if(visited[i]== false)
        {
            dfsutil(i,visited);
            cout<<"\n";
        }
    }
    delete[] visited;
}

void graph:: dfsutil(int v, bool visited[])
{
    visited[v]=true;
    cout<<v<<" ";
    list<int>:: iterator i;
    for(i=adj[v].begin() ; i != adj[v].end() ; ++i)
    {
        if(!visited[*i])
        {
            dfsutil(*i, visited);
        }
    }
}
graph::graph(int v)
{
    this->v=v;
    adj= new list<int> [v];
}
graph ::~graph()
{
    delete[] adj;
}
void graph:: addedge(int u, int v)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}
int main()
{
    // Create a graph given in the above diagram
    graph g(5); // 5 vertices numbered from 0 to 4
    g.addedge(1, 0);
    g.addedge(2, 3);
    g.addedge(3, 4);
 
    cout << "Following are connected components \n";
    g.connectedcomponents();
 
    return 0;
}