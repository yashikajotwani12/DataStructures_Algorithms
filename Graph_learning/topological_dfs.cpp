#include<bits/stdc++.h>
using namespace std;
class graph{
    public:
    unordered_map<int,vector<int>>mp;
    void addEdge(int u, int v)
    {
        mp[u].push_back(v);
    }
    
    void topoutil(int src, vector<bool>&visisted,vector<int>&ordering)
    {
        visisted[src]=true;
        for(auto i:mp[src])
        {
            if(!visisted[i])
            {
                topoutil(i,visisted,ordering);
            }
        }
        ordering.push_back(src);

    }
    vector<int>toposort()
    {
        vector<int>ordering;
        vector<bool>visited(mp.size(),false);
       
        for(int i=0;i<mp.size();i++)
        {
            if(!visited[i])
            {
                topoutil(i,visited,ordering);
            }

        }
        reverse( ordering.begin(), ordering.end());
        return ordering;
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
   vector<int>ans= g.toposort();
   for(auto i:ans)
   {
       cout<<i<<" ";
   }
    return 0;
 
}