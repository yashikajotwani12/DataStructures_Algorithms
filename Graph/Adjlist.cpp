#include<bits/stdc++.h>
using namespace std;
// array of lists of size of v 
// 0th array will store the neightbours it has

class Graph{
    int v;
    list<int>*l; // pointer to an array of lists 
public:
    Graph(int v) // constructor
    {
        this->v = v;
        l = new list<int>[v]; // runtime 
    }
    void addedge(int x, int y)
    {
       l[x].push_back(y);
       l[y].push_back(x);
    }

    void printlist()
    {
        // iterate over all vertices
        for(int i=0;i<v;i++)
        {
            cout<<"vertex"<<i<<"->";
            for(int x: l[i])
            {
                cout<<x<<" , ";
            }
            cout<<endl;
          
        }
    }

};

int main()
{
  Graph g(4);
   g.addedge(0,1);
   g.addedge(0,2);
   g.addedge(2,3);
   g.addedge(1,2);
   g.printlist();


    return 0;

}