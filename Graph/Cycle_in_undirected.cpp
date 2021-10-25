#include<bits/stdc++.h>
using namespace std;
class graph{
    bool checkcycle(int s, int v, vector<int>adj[], vector<int>&vis)
    {
        queue<pair<int,int>>q;
        vis[s]=1;
        q.push({s,-1});
        while(!q.empty())
        {
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
            for(auto i:adj[node])
            {
                if(!vis[i])
                {
                    vis[i]=1;
                    q.push({i,node});

                }else if(par!=i)
                {
                    return true;
                }
            }
        }
        return  false;


    }
    

    bool iscyclic(int v, vector<int>adj[])
    {
        vector<int>vis(v+1,0);
        for(int i=1;i<=v;i++)
        {
            if(!vis[i])
            {
                if(checkcycle(i,v,adj,vis))
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
    return 0;
}