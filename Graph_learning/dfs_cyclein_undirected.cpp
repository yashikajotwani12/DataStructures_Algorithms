#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
    unordered_map<int,vector<int>>mp;
    void addedge(int u,int v)
    {
        mp[u].push_back(v);
        mp[v].push_back(u);
    }

    bool cycleutil(int src, int parent, vector<bool>&vis)
    {
        vis[src]= true;
        for(auto i:mp[src])
        {
            if(!vis[i])
            {
              if(cycleutil(i,src,vis)) return true;
            }else if(i!=parent)
            {
                return true;
            }

        }
        return false;
    }
    bool cycle()
    {
        int n= mp.size();
        vector<bool>vis(n+1,false);
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                if(cycleutil(i,-1,vis)) return true;

            }


        }
        return false;
    }


};
