#include<bits/stdc++.h>
using namespace std;


void bellmanford( int graph[][3] , int v , int e, int src )
{
    int dis[v]; // initialize distance of all vertices as infinite
    for(int i=0;i<v;i++)
    {
        dis[i]=INT_MAX;
    } 


    dis[src]=0; // initialize distance of sorce as 0

    // relax all edges v-1 times. a simple path from src to any other vertex  can have atmost v-1 edges
    for(int i=0;i<v-1;i++) 
    {
        for(int j=0;j<e;j++)
        {
            if(dis[graph[j][0]]!=INT_MAX && dis[graph[j][0]]+graph[j][2] < dis[graph[j][1]])
            {
                dis[graph[j][1]]= dis[graph[j][0]]+graph[j][2] ;
            }

        }
    } 

    for(int i=0;i<e;i++)
    {
        int x= graph[i][0];
        int y= graph[i][1];
        int weigth =graph[i][2];

        if(dis[x]!=INT_MAX and dis[x]+ weigth < dis[y])
        cout<<"Graph contaims negative weight cycle "<<endl;
    }
    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < v; i++)
        cout << i << "\t\t" << dis[i] << endl;

}
// Driver program to test above functions
int main()
{
    int V = 5; // Number of vertices in graph
    int E = 8; // Number of edges in graph
 
    // Every edge has three values (u, v, w) where
    // the edge is from vertex u to v. And weight
    // of the edge is w.
    int graph[][3] = { { 0, 1, -1 }, { 0, 2, 4 },
                       { 1, 2, 3 }, { 1, 3, 2 },
                       { 1, 4, 2 }, { 3, 2, 5 },
                       { 3, 1, 1 }, { 4, 3, -3 } };
 
    bellmanford(graph, V, E, 0);
    return 0;
}