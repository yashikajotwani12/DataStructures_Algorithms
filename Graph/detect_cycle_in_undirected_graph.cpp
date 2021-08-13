#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }
    void addedge(int x, int y, bool directed = true)
    {
        l[x].push_back(y);
        if (!directed)
        {
            l[y].push_back(x);
        }
    }
    bool cycle_helper(int node, bool *visited, int parent)
    {
        visited[node]= true;
        for(auto nbr:l[node])
        {
            // two cases
            if(!visited[nbr])
            {
                // go and recursively visit the neighbour
                bool found = cycle_helper(nbr, visited, node);
                if(found)
                {
                    return true;
                }



            }// neighbour  is visited and is not equal to parent
            else if(nbr!= parent)
            {
                return true;


            }
        }
        return false;
    }
    bool contains_cycle()
    {
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }
        cycle_helper(0, visited, -1);
    }
};

int main()
{
    return 0;
}