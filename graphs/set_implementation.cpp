#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

struct graph{
    int v;
    unordered_set<int> *adjlist;
};

graph*creategraph(int v)
{
    graph* ga =new graph();
    ga->v=v;

    ga->adjlist=new unordered_set<int>[v];
    return ga;

}
void addEdge(graph *ga , int src, int dest)
{
    ga->adjlist[src].insert(dest);
    ga->adjlist[dest].insert(src);
}
void printgraph(graph *gg)
{
    for(int i=0;i<gg->v;i++)
    {
        unordered_set<int>fist=gg->adjlist[i];
        cout<<endl<<" adjancency list of vertex "<<i<<endl;
    

    for(auto itr=fist.begin();itr!=fist.end();itr++)
    {
        cout<<*itr<<" ";
        cout<<endl;
    }

    }
}
void searchEdge(graph*gg, int src, int dest)
{
    auto itr=gg->adjlist[src].find(dest);
    if(itr==gg->adjlist[src].end())
    cout << endl << "Edge from " << src
             << " to " << dest << " not found."
             << endl;
    else
        cout << endl << "Edge from " << src
             << " to " << dest << " found."
             << endl;
}
 
// Driver code
int main()
{
    // Create the graph given in the above figure
    int V = 5;
    struct graph* graph = creategraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
 
    // Print the adjacency list representation of
    // the above graph
    printgraph(graph);
 
    // Search the given edge in the graph
    searchEdge(graph, 2, 1);
    searchEdge(graph, 0, 3);
 
    return 0;
}
