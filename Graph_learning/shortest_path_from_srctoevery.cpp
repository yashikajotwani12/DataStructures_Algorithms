#include <bits/stdc++.h>
using namespace std;
class graph
{
public:
    unordered_map<int, vector<pair<int, int>>> mp;
    void addedge(int u, int v, int w)
    {
        mp[u].push_back(make_pair(v, w));
        mp[v].push_back(make_pair(u, w));
    }
    void dfs(int src)
    {
        vector<int> dist(mp.size(), INT_MAX);
        queue<int> q;
        dist[src] = 0;
        q.push(src);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto i : mp[node])
            {
                if (dist[node] + 1 < dist[i.first])
                {
                    dist[i.first] = dist[node] + 1;
                    q.push(i.first);
                }
            }
        }
        for (auto i : dist)
        {
            cout << i << " ";
        }
    }
};

int main()
{
    graph g;
    g.addedge(0,1,1);
    g.addedge(0,3,1);
    g.addedge(1,2,1);
    g.addedge(1,3,1);
    g.addedge(4,5,1);
    g.addedge(3,4,1);
    g.addedge(2,6,1);
    g.addedge(5,6,1);
    g.addedge(6,8,1);
    g.addedge(6,7,1);
    g.addedge(7,8,1);
    
    g.dfs(0);

    return 0;
}