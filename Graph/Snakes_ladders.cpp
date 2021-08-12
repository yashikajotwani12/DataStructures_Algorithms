#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
    map<T,list<T>>l;
    public:
    void addedge(int x, int y)
    {
        l[x].push_back(y);
        
    }
    int  bfs(T src, T dest)
    {
        map<T, int>dist;
        queue<T>q;
        
        for(auto node_pair: l)
        {
            T node= node_pair.first;
            dist[node]= INT_MAX;

        }
        q.push(src);
        dist[src]=0;

        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            for(int nbr: l[node])
            {
                if(dist[nbr]==INT_MAX)
                {
                    q.push(nbr);
                    dist[nbr]= dist[node]+1;
                }
            }

        }
      
        return dist[dest];

    }

};



int main()
{
    Graph<int>g;
    int board[50] ={0};
    // snakes // ladders

    board[2]=13;
    board[5]=2;
    board[9]=18;
    board[18]=11;
    board[17]=-13;
    board[20]=-14;
    board[24]=8;
    board[25]=-10;
    board[32]=-2;
    board[34]=-22;
    //all edges to the graph
   
   
    for(int i=0;i<36;i++)
    {
        for(int dices =1;i<=6;i++)
        {
            int j = i + dices;
            j+= board[j];

            if(j<=36)
            {
                g.addedge(i,j);
            }
        
        }
    }
    g.addedge(36,36);
    cout<< g.bfs(0,36);
    return 0;
}