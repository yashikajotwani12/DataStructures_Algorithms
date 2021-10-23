#include<bits/stdc++.h>
using namespace std;
unordered_map<int,vector<int>>mp;
void addEdge(int u,int v)
{
    mp[u].push_back(v);
    mp[v].push_back(u);

}
void printgraph()
{
    for(auto i:mp)
    {
        cout<<i.first<<"--> ";
        for(auto j:mp[i.first])
        {
            cout<<j<<" , ";
        }
        cout<<endl;

    }
}
int main()
{
    // unordered_map<int,vector<int>>adj;
    addEdge( 0, 1);
    addEdge(0, 4);
    addEdge( 1, 2);
    addEdge(1, 3);
    addEdge( 1, 4);
    addEdge( 2, 3);
    addEdge( 3, 4);
    printgraph();
    cout<<"printed";
    return 0;
}