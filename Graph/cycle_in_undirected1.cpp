#include<bits/stdc++.h>
using namespace std;

bool cycleutil(vector<int>adj[], int src, vector<int>&vis)
{
    vis[src]= true;
    queue<pair<int,int>>q;
    q.push({src,-1});
    while(!q.empty())
    {
        int node = q.front().first;
        int par = q.front().second;
        q.pop();
        for(auto nbr : adj[node])
        {
            if(!vis[nbr])
            {
                vis[nbr] = 1;
                q.push({nbr, node});
            }else if(par != nbr)
            {
                return true;
            }
        }


    }
    return false;

}

bool cycle(vector<int>adj[], int v)
{
    vector<int>vis(v+1,0);
    for(int i=1;i<=v;i++)
    {
        if(!vis[i])
        {
            if(cycleutil(adj, i, vis))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    return 0;
}