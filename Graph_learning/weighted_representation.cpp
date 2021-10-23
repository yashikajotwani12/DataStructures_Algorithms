#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
    unordered_map<int,vector<pair<int,int>>>mp;
    void addedge(int v, int u, int w)
    {
        mp[u].push_back(make_pair(v,w));
        mp[v].push_back(make_pair(u,w));
    }
    void bfsutil(int src)
    {
        queue<int>q;
        q.push(src);
        vector<bool>visited(mp.size(),false);
        visited[src]=true;
        while(!q.empty())
        {
            int node = q.front();
            cout<<node<<" ";
            q.pop();
            for(auto i:mp[node])
            {
                if(visited[i.first]==false)
                {
                    q.push(i.first);
                    visited[i.first]=true;
                }
            }
            
        }
    }
   

};
int main()
{
    graph g;
    g.addedge(0,1,1);
    g.addedge(0,3,3);
    g.addedge(1,2,4);
    g.addedge(2,3,2);
    g.addedge(3,4,4);
    g.addedge(4,5,2);
    g.bfsutil(0);
    return 0;
}