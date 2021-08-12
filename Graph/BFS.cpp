#include<bits/stdc++.h>
using namespace std;

template<typename T>

class Graph{
    map<T, list<T>>l;
    public:
    void addedge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void bfs(T src)
    {
        map<T, bool>visited;
        queue<T>q;
        q.push(src);
        visited[src]=true;

        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            cout<<node<<" ";
            for(int nbr: l[node])
            {
                if(!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }


    }


};
int main()
{

    Graph<int>g;
    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(2,3);
    g.addedge(3,4);
    g.addedge(4,5);
    g.bfs(0);

   return 0;
}