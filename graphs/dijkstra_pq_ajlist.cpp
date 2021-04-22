//using priority queue and adjacency list for better time complexity

#include<bits/stdc++.h>
using namespace std;

void addedge(vector<pair<int , int>>graph[], int u, int v , int w)
{
    graph[u].push_back({v,w});
    graph[v].push_back({u,w});

}

void dijkstra(vector<pair<int , int>> graph[], int src, int v)
{
    priority_queue<pair<int , int> , vector<pair<int , int>>, greater<pair<int , int>>> pq;

    vector<int> dist(v, INFINITY);
    pq.push(make_pair(0, src));
    dist[src]=0;

    while(!pq.empty())
    {
        int u= pq.top().second;
        pq.pop();

        for(auto x: graph[u])
        {
            int v= x.first;
            int wt=x.second;
            if(dist[v]>dist[u]+wt)
            {
                dist[v]=dist[u]+wt;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    cout<<"Vertex distance from src \n";

    for(int i=0;i<v;i++)
    {
        cout<<i<<"\t"<<dist[i]<<endl;
    }
}
int main(){
    int v = 9;
    vector<pair<int, int>> graph[v];
    addedge(graph ,0, 1, 4); 
    addedge(graph ,0, 7, 8); 
    addedge(graph ,1, 2, 8); 
    addedge(graph ,1, 7, 11); 
    addedge(graph ,2, 3, 7); 
    addedge(graph ,2, 8, 2); 
    addedge(graph ,2, 5, 4); 
    addedge(graph ,3, 4, 9); 
    addedge(graph ,3, 5, 14); 
    addedge(graph ,4, 5, 10); 
    addedge(graph ,5, 6, 2); 
    addedge(graph ,6, 7, 1); 
    addedge(graph ,6, 8, 6); 
    addedge(graph ,7, 8, 7); 

    dijkstra(graph, 0, 9);
}