#include<bits/stdc++.h>
using namespace std;

class graph{
    int v;
    list<int>*adj;
    public:
    graph(int v);
    void addedge(int u, int v);
    void toposort();
};

graph::graph(int v)
{
    this->v=v;
    adj= new list<int>[v];
}
void graph::addedge(int u, int v)
{
    adj[u].push_back(v);
}
void graph::toposort()
{
    vector<int> indegree(v,0);
    for(int u=0;u<v;u++)
    {
        list<int>::iterator i;
        for(i=adj[u].begin();i!=adj[u].end();i++)
        {
            indegree[*i]++;
        }
    }

    queue<int>q;
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    int count=0;
    vector<int>toporder;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        toporder.push_back(u);



        list<int>::iterator i;
        for(i=adj[u].begin();i !=adj[u].end();i++)
        {
            if(--indegree[*i]==0)
            q.push(*i);
        }
        count++;
    }
    if(count!=v)
    {
        cout << "There exists a cycle in the graph\n";
        return;

    }

    for(int i=0;i< toporder.size();i++)
    {
         cout << toporder[i] << " ";
    
    }
    cout << endl;

}
int main()
{
    // Create a graph given in the
    // above diagram
    graph g(6);
    g.addedge(5, 2);
    g.addedge(5, 0);
    g.addedge(4, 0);
    g.addedge(4, 1);
    g.addedge(2, 3);
    g.addedge(3, 1);
  
    cout << "Following is a Topological Sort of\n";
    g.toposort();
  
    return 0;
}