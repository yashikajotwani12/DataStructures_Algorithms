#include<bits/stdc++.h>
using namespace std;
class graph{
    int v;
    list<int>*adj;
    public:
    graph(int v);
    void addedge(int u, int v);
    void bfs(int s);

};
graph::graph(int v)
{
    this ->v=v;
    adj= new list<int>[v];
}
void graph::addedge(int u, int v)
{
    adj[u].push_back(v);
}
void graph::bfs(int s)
{
    list<int>queue;
    bool* visited= new bool[v];
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
    }
        visited[s]=true;
        
        queue.push_back(s);
        list<int>::iterator i;

    while(!queue.empty())
    {
       s=queue.front();
       cout<<s<<" ";
       queue.pop_front();
       for( i=adj[s].begin();i !=adj[s].end();++i)
       {
           if(!visited[*i])
           {
               visited[*i]=true;
               queue.push_back(*i);

           }
       }

    }
}
 int main()
{
    graph g(4);
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(1,2);
    g.addedge(2,0);
    g.addedge(2,3);
    g.addedge(3,3);
  cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2) \n"; 

        g.bfs(2);
        return 0;
}
     