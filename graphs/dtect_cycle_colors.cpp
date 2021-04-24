#include<bits/stdc++.h>
using namespace std;

enum color { WHITE , GRAY , BLACK};

class graph{
    int v;
    list<int>*adj;
    bool dfsutil(int v, int color[]);

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
void graph::addedge(int v, int w)
{
    adj[v].push_back(w);
}

bool graph::dfsutil(int u, int color[])
{
    color[u]=GRAY;
    list<int>::iterator i;
    for(i=adj[u].begin(); i !=adj[u].end();i++)
    {
        int v = *i;
        if(color[v]== GRAY)
        return true;

        if(color[v] == WHITE && dfsutil(v,color))
            return true;
    }
    color[u]=BLACK;
    return false;

}
bool graph::iscyclic()
{
    int *color = new int[v];
    for(int i=0;i<v;i++)
    {
        color[i]=WHITE;
    }

    for(int i=0;i<v;i++)
    {
        if(color[i]==WHITE)
        {
            if(dfsutil(i,color)==true)
            return true;
        }
    }
    return false;
}
int main()
{
    // Create a graph given in the above diagram
    graph g(4);
    g.addedge(0, 1);
    g.addedge(0, 2);
    g.addedge(1, 2);
    g.addedge(2, 0);
    g.addedge(2, 3);
    g.addedge(3, 3);
  
    if (g.iscyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
  
    return 0;
}