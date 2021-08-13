#include<bits/stdc++.h>
using namespace std;
class Sol{
    public:
    void dfs(int i, vector<int>adj[], int v, bool vis[], vector<int>&res)
    {
        if(vis[i]) return;

        vis[i]= true;
        res.push_back(i);
        for(int j : adj[i])
        {
            if(!vis[j])
            {
              dfs(j,adj,v,vis,res);
            }
        }


    }

    // main function
    vector<int> dfsmain(int v, vector<int>adj[])
    {
        vector<int>res;
        bool visited[v];
        memset(visited, false, sizeof(visited));

        for(int i=0;i<v;i++)
        {
            if(!visited)
            {
                dfs(i, adj, v, visited, res);
            }
        }
        return res;

    }

    
};

int main()
{
    return 0;
}