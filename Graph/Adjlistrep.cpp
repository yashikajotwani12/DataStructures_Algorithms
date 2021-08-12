#include<bits/stdc++.h>
using namespace std;
// weighted graph
// hashmaps
// list<pair<string, int>>


class Graph{
    unordered_map<string, list<pair<string, int>>>l;
    public:
    void addedge(string x, string y, bool bidir, int wt)
    {
        l[x].push_back(make_pair(y,wt));
        if(bidir)
        {
            l[y].push_back(make_pair(x,wt));
        }
    }
    void printlist()
    {
        for(auto p:l)
        {
            string city = p.first;
            list<pair<string, int>>nbrs = p.second;

            cout<<city<<" -> ";

            for(auto nbr: nbrs)
            {
                string dest = nbr.first;
                int dist = nbr.second;

                cout<<dest<<" "<<dist<<",";
            }
            cout<<endl;


        }
    }



};
int main()
{
    Graph g;
     g.addedge("A","B",true, 20); // true for bidirectional and weight is 20
     g.addedge("B","D",true, 40);
     g.addedge("A","C",true, 10);
     g.addedge("C","D",true, 40);
     g.addedge("A","D",false, 50); // directed edge
     g.printlist();
    return 0;
}