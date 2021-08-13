#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
class sol{
    public:

    // to form adj list from pairs
    vector<unordered_set<int>> make_graph(vector<pair<int, int>>&arr, int n)
    {
        vector<unordered_set<int>>graph(n);
        for(auto p : arr)
        {
            graph[p.second].insert(p.first);
        }
        return graph;

    }

    // dfs function to check if the cycle exisit or not

    bool dfs(vector<unordered_set<int>>&graph, int node, vector<bool>&onpath, vector<bool>&visited)
    {
        if(visited[node]) return false;

        onpath[node] = visited[node] = true;
        for(int nbr: graph[node])
        {
            if(onpath[nbr] or dfs(graph, nbr, onpath,visited))
            {
                return true;
            }
        }
        return onpath[node] = false;

    }


    // main function to check for all the pairs if it is possible or not
    bool prereq(vector<pair<int, int>>&arr, int n)
    {
     vector<unordered_set<int>>graph = make_graph(arr, n);
     vector<bool> onpath(n, false), visited(n, false);
     for(int i=0;i<n;i++)
     {
         if(!visited[i] and dfs(graph,i, onpath, visited)) return false;

     }
     return true;

    }

};
int main()
{
    return 0;
}