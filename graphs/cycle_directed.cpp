#include<bits/stdc++.h>
using namespace std;

bool iscyclic_util(vector<int> adj[] , vector<bool> visited, int curr)
{
    if(visited[curr] == true)
    return true;

    visited[curr]= true;
    bool flag= false;

    for(int i=0;i< adj[curr].size();i++)
    { 
        flag=iscyclic_util(adj, visited, adj[curr][i]);
        if(flag== true)
         return true;

      
    }
    return false;

}

bool iscyclic(int v , vector<int> adj[])
{
    vector<bool> visited(v, false);
    bool flag=true;
    for(int i=0;i<v;i++)
    {
    for(int j=0;j<adj[i].size();++j)
    {
        flag= iscyclic_util(adj, visited, adj[i][j]);
        if(flag== true)
        return true;
    }
     visited[i]=false;
    }
    return false;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int v,e;
        cin>>v>>e;

        vector<int> adj[v];
        for(int i=0;i<e;i++)
        {
            int u,v;
            adj[u].push_back(v);

        }
        cout<<iscyclic(v, adj)<<endl;
    }
    return 0;
}