#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
    unordered_map<int, vector<int>>mp;
    void add(int u, int v)
    {
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    // bool bfs(int src, vector<int>&color)
    // {
    //     queue<int>q;
    //     q.push(src);
    //     color[src]=1;
    //     while(!q.empty())
    //     {
    //         int node = q.front();
    //         q.pop();
    //         for(auto i:mp[node])
    //         {
    //             if(color[i]==-1)
    //             {
    //                 color[i] = 1-color[node];
    //                 q.push(i);
    //             }else if(color[i]==color[node])
    //             {
    //                 return false;
    //             }
    //         }
    //     }
    //     return true;
    // }
    bool dfs(int src, vector<int>&color, int currcolor)
    {
        color[src]=currcolor;
       
        for(auto i:mp[src])
        {
            if(color[i]==-1)
            {
                dfs(i,color,1-currcolor);
              
            }else if(color[i]==color[src])
            {
                return false;
            }
        }
        return true;
    }
    bool check()
    {
        int n= mp.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
               if(!dfs(i,color,1)) 
               {
                   return false;

               }
            }
        }
        return true;
    }

};

int main()
{
    return 0;
}