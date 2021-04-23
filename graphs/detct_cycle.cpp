#include<bits/stdc++.h>
using namespace std;
class graph{
    int v;
    list<int> *adj;
    bool iscyclicutil(int v, bool visited[], bool *rs);

    public:
    graph(int v);
    void addedge(int u, int w);

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
 bool graph:: iscyclicutil(int v, bool visited[], bool *recstack)
 {
     if(visited[v]== false)
     {
         visited[v]=true;
         recstack[v]= true;

         list<int>:: iterator i;
         for(i=adj[v].begin(); i != adj[v].end();++i)
         {
             if(!visited[*i] && iscyclicutil(*i , visited, recstack))
             {
                 return true;
             }
             else if(recstack[*i])
             {
                 return true;
             }
         }
     }
     recstack[v]=false;
     return false;

 }


 bool graph::iscyclic()
 {
     bool *visited = new bool[v];
     bool *recstack = new bool[v];
     for(int i=0;i<v;i++)
     {
         if(iscyclicutil(i, visited, recstack))
         return true;
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
  
    if(g.iscyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}