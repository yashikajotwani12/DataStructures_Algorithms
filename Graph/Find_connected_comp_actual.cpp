#include<bits/stdc++.h>
using namespace std;
template<typename T>

class Graph{
    map<T, list<T>>l;
    public:
    void addedeg(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);

    }
    void dfshelp(T src, map<T, bool> &visited)
    {
        // recursive func that will traverse the graph
        cout<<src<<" ";
        visited[src]= true;
        // go to the node whivh id=s not visited
        for(T nbr : l[src])
        {
            if(!visited[nbr])
            {
                dfshelp(nbr, visited);
            }
        }
    }
    void dfs(T src)
    {
        map<T, bool> visited;
        for(auto p :l)
        {
            // mark all the nodes as not visited
            T node= p.first;
            visited[node]= false;
        }
         int count=0;
        for(auto p:l)
        {
            T node = p.first;
           
            if(!visited[node])
            cout<<"Component"<<count<<" --> ";
              dfshelp(src, visited);
              count++;
              cout<<endl;
        }
    }

};

int main()
{
    Graph<int>g;
    g.addedeg(0,1);
    g.addedeg(1,2);
    g.addedeg(2,3);
    g.addedeg(0,3);
    g.addedeg(0,4);
    g.addedeg(5,6);
    g.addedeg(6,7);
    g.addedeg(8,8);
    g.dfs(0);

    return 0;
}