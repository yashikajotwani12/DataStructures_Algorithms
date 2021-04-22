 #include<bits/stdc++.h>
 using namespace std;
 class graph{
     int v;
     list<int> *adj;
     void dfsutil(int v, vector<bool> &visited);
     public:
     graph(int v);
     void addEdge(int v, int w);
     int findMother();

 };
 graph::graph(int v)
 {
    this->v=v;
    adj=new list<int>[v];

 }
 void graph::dfsutil(int v, vector<bool> &visited)
 {
     visited[v]=true;
     list<int>::iterator i;
     for(i=adj[v].begin();i!=adj[v].end();i++)
     {
         if(!visited[*i])
         {
             dfsutil(*i, visited);
         }
     }
 }
 void graph ::addEdge(int v, int w)
 {
     adj[v].push_back(w);
 }
 int graph::findMother()
 {
     vector<bool>visited(v, false);
     int V=0;
     for(int i=0;i<v;i++)
     {
         if(visited[i]==false)
         {
             dfsutil(i, visited);
             V=i;
         }
     }

fill(visited.begin(), visited.end(), false);
dfsutil(v, visited);
for(int i=0;i<v;i++)
{
    if(visited[i]==false)
    {
        return -1;
    }
    
}

return v;
 }
 int main()
{
    // Create a graph given in the above diagram
    graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 1);
    g.addEdge(6, 4);
    g.addEdge(5, 6);
    g.addEdge(5, 2);
    g.addEdge(6, 0);
 
    cout << "A mother vertex is " << g.findMother();
 
    return 0;
}