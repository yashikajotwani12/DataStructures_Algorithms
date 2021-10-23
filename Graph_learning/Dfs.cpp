#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    unordered_map<int,vector<int>>mp;
    void add(int u,int v)
    {
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    void dfsutil(int src, vector<bool>&visited)
    {
        visited[src]= true;
        cout<<src<<" ";
        for(auto i:mp[src])
        {
            if(visited[i]==false)
            {
                dfsutil(i,visited);
            }
        }
    }
    void dfs()
    {
        int n = mp.size();
        vector<bool>visited(n, false);
        for(auto i:mp)
        {
            if(visited[i.first]==false)
            {

               dfsutil(i.first,visited); 

            }
        }
    }
};
int main()
{
    Graph g;
    g.add(0,1);
    g.add(0,4);
    g.add(1,2);
    g.add(1,3);
    g.add(1,4);
    g.add(2,3);
    g.add(3,4);
    g.dfs();

    return 0;

}