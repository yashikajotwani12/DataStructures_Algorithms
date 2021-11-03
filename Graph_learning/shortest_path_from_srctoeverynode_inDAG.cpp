#include<bits/stdc++.h>
using namespace std;
class graph{
    public:
    int n;
    graph(int n)
    {   
        this->n=n;
    }
    unordered_map<int,vector<pair<int,int>>>mp;
    void addEdge(int u,int v, int w)
    {
        mp[u].push_back(make_pair(v,w));
    }
    void toposort(int node, vector<int>&vis, stack<int>&st)
    {
        vis[node]=1;
        for(auto it: mp[node])
        {
            if(!vis[it.first])
            {
                toposort(it.first, vis,st);
            }
        }
        st.push(node);
    }

    void shortestPath(int src)
    {
        
        vector<int>vis(n,0);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                toposort(i,vis,st);
            }
        }


        vector<int>dis(n,INT16_MAX);
        dis[src]=0;
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            if(dis[node]!= -1)
            {
                for(auto i:mp[node])
                {
                    if(dis[node]+ i.second < dis[i.first])
                    {
                         dis[i.first]= dis[node]+ i.second ;
                    }
                }

            }
        }
        for(int i=0;i<n;i++)
        {
            dis[i]==-1 ? cout<<"-1" :cout<<dis[i]<<" ";
        }
    }


};
int main()
{
    graph g(6);

    unordered_map<int,vector<pair<int,int>>>mp;
    g.addEdge(0,1,5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

	

	g.shortestPath(1); 

	return 0; 
}