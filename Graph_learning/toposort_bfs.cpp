#include<bits/stdc++.h>
using namespace std;
class graph{
    public:
    unordered_map<int, vector<int>>mp;
   
    void addEdge(int u, int v)
    {
        mp[u].push_back(v);
    }
    vector<int> toposort()
    {
        int n= mp.size();
        queue<int>q;
        vector<int>ans;
        vector<int>indegree(n+1,0);
        for(auto i:mp)
        {
            for(auto j:mp[i.first])
            {
                indegree[j]++;

            }
        }
        for(int i=0;i<=indegree.size();i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int src = q.front();
            ans.push_back(src);
            q.pop();
            for(auto i:mp[src])
            {
                indegree[i]--;
                if(indegree[i]==0)
                {
                    q.push(i);
                }

            }
        }
        return ans;
    }


};
int main()
{
    graph g;
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
 
    cout << "Following is a Topological Sort of the given "
            "graph \n";
 
    // Function Call
   vector<int>ans = g.toposort();
   for(auto i:ans)
   {
       cout<<i<<" ";
   }
    return 0;
 
}