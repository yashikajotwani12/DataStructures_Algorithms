#include<bits/stdc++.h>
using namespace std;

void addedge(vector<int>adj[] , int u , int v)
{
    adj[u].push_back(v);
}

void bfsutil(int u, vector<int> adj[], vector<bool> &visited)
{
     list<int>qu;
     visited[u]=true;
     qu.push_back(u);

     while(!qu.empty())
     {
         u=qu.front();
         cout<<u<<" ";
         qu.pop_front();

        for(int i=0; i !=adj[u].size();i++)
        {
            if(!visited[adj[u][i]])
            {
                visited[adj[u][i]]=true;
                qu.push_back(adj[u][i]);

            }
        }

     }
}
void bfs( vector<int>adj[] , int v)
{
    vector<bool> visited(v, false);
    for(int u=0;u<v;u++){
        if(visited[u]== false)
        {
            bfsutil(u, adj, visited);
        }
    }
}
int main()
{
    int V = 5;
    vector<int> adj[V];
  
    addedge(adj, 0, 4);
    addedge(adj, 1, 2);
    addedge(adj, 1, 3);
    addedge(adj, 1, 4);
    addedge(adj, 2, 3);
    addedge(adj, 3, 4);
    bfs(adj, V);
    return 0;
}

