#include<bits/stdc++.h>
using namespace std;
class Graph{
   
    map<int, bool> visited;
    map<int,list<int>>l;
    public:
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
    }
    void dfs(int s)
    {
        visited[s]=true;
        cout<<s<<" ";

        list<int>:: iterator i;
        for(i= l[s].begin(); i!= l[s].end();i++)
        {
            if(!visited[*i])
            {
                dfs(*i);
            }
        }
    }

};

int main()
{
    // Create a graph given in the above diagram
    Graph g;
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