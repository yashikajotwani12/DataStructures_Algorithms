#include<bits/stdc++.h>
using namespace std;

struct edge{
    int src, dst , wt;
};
int v, e;

void bellmanford(vector<edge>& Edges)
{
    int parent[v]; // stores shortest path structure
    int cost_parent[v];  // cost of the node to parent edge weight
    vector<int> value(v, INT_MAX); // keeps shortest path values to each vertex from source


     parent[0]=-1; // start node has no parent
     value[0]=0;  // start node has value=0 to get picked first

     bool updated;

     for(int i=0;i<v-1;i++)
     {
         updated=false;

         for(int j=0;j<e;j++)
         {
             int u = Edges[j].src;
             int v = Edges[j].dst;
             int wt= Edges[j].wt;

             if(value[u]!=INT_MAX and value[u]+wt < value[v])
             {
                 value[v] = value[u]+wt;
                 parent[v] = u;
                 cost_parent[v] = value[v];
                 updated=true;


             }



         }
         if(updated ==false)
         break;
     }
     for(int j=0;j<e and updated ==true;++j)
     {
         int u= Edges[j].src;
         int v=Edges[j].dst;
         int wt =Edges[j].wt;
         if(value[u]!=INT_MAX and value[u]+wt <value[v])
         {
             cout<<" Graph has a negative edge cycle \n";
             return;
         }
     }
     for(int i=0;i<v;i++)
     {
         cout<<"U->V: "<<parent[i]<<"->"<<i<<"  Cost to reach "<<parent[i]<<"from source 0 = "<<value[i]<<"\n";
     }

    


}
int main()
{
    cin>>v>>e;
    vector<edge> Edges(e);
    int src, dst, wt;
    for(int i=0;i<e;i++)
    {
        cin>>src>>dst>>wt;
        Edges[i].src =src;
        Edges[i].dst =dst;
        Edges[i].wt =wt;
    

    }
    bellmanford(Edges);
    return 0;

}

