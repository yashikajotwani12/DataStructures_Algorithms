#include<bits/stdc++.h>
using namespace std;
class graph
{
    int v;
    list<int>*adj;
    void topologicalsortutil(int v, bool visited[], stack<int>& st);

    public:
    graph(int v);
    void addedge(int u, int v);
    void topologicalsort();


};
graph::graph(int v)
{
    this ->v=v;
    adj= new list<int>[v];
}
void graph ::addedge(int u, int v)
{
    adj[u].push_back(v);
}

void graph :: topologicalsortutil( int v, bool visited[], stack<int>&st)
{
    visited[v] =true;
    list<int> ::iterator i;
    for(i=adj[v].begin(); i != adj[v].end();i++)
    {
        if(!visited[*i])
        {
            topologicalsortutil(*i, visited, st);
        }
    }
    st.push(v);

}
void graph:: topologicalsort()
{
    stack<int>s;

    bool*visited= new bool[v];
    for(int i=0;i<v;i++)
    {
        visited[i]=false;

    }
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
        {
            topologicalsortutil(i, visited, s);
        }
    }
    while(s.empty()==false)
    {
        cout<<s.top()<<" ";
        s.pop();

    }
    
}
int main()
{
    // Create a graph given in the above diagram
    graph g(6);
    g.addedge(5, 2);
    g.addedge(5, 0);
    g.addedge(4, 0);
    g.addedge(4, 1);
    g.addedge(2, 3);
    g.addedge(3, 1);
 
    cout << "Following is a Topological Sort of the given "
            "graph \n";
 
    // Function Call
    g.topologicalsort();
 
    return 0;
}