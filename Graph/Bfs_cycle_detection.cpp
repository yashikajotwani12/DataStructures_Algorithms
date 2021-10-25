#include<bits/stdc++.h>
using namespace std;
class graph{
    public:
    unordered_map<int, vector<int>>mp;
    void addEdge(int u , int v)
    {
        mp[u].push_back(v);
        
    }
    bool cycleutil(int src, vector<int>&vis, vector<int>&stack)
    {
        vis[src]= 1;
        stack[src]=1;
        for(auto nbr:mp[src])
        {
            if(!vis[nbr])
            {
               return cycleutil(nbr,vis,stack);

            }else if(stack[nbr])
            {
                return true;
            }

        }
        stack[src]= 0;
        return false;

    }
    bool cycle()
    {
        int n= mp.size();
        vector<int>vis(n,0);
        vector<int>stack(n,0);
        for(auto i: mp)
        {
            if(!vis[i.first])
            {
                if(cycleutil(i.first,vis,stack))
                {
                    return true;
                }
            }
        }
        return false;

    }


};
int main()
{
    graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout<<  g.cycle();
    return 0;
}