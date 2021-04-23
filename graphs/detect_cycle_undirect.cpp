#include<bits/stdc++.h>
using namespace std;
class graph{
    int v;

    list<int>*adj;
    bool iscyclicutil(int v, bool visited[], int parent);

    public:
    graph(int v);
    void addedge(int v, int w);
    bool iscyclic();

};

graph::graph(int v)
{
    this->v=v;
    adj= new list<int>[v];
}

void graph:: addedge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

bool graph::iscyclicutil(int v,bool visited[], int parent)
{

    visited[v]=true;

    list<int>::iterator i;
    for( i= adj[v].begin(); i!=adj[v].end();++i)
    {
        if(!visited[*i])
        {
            if(iscyclicutil(*i, visited, v))
            return true;
        }
        else  if(*i!=parent)
              return true;
    }
    return false;

}

bool graph::iscyclic()
{
    bool* visited= new bool[v];
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
    }

    for(int u=0;u<v;u++)
    {
        if(!visited[u])
          {
              if(iscyclicutil(u, visited, -1))
              return true;
          }
    }
    return false;
}
// Driver program to test above functions
int main()
{
    graph g1(5);
    g1.addedge(1, 0);
    g1.addedge(0, 2);
    g1.addedge(2, 1);
    g1.addedge(0, 3);
    g1.addedge(3, 4);
    g1.iscyclic()?
       cout << "Graph contains cycle\n":
       cout << "Graph doesn't contain cycle\n";
 
    graph g2(3);
    g2.addedge(0, 1);
    g2.addedge(1, 2);
    g2.iscyclic()?
       cout << "Graph contains cycle\n":
       cout << "Graph doesn't contain cycle\n";
 
    return 0;
}