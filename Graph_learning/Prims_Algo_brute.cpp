#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n,m;
    cin>>n>>m;
    unordered_map<int, vector<pair<int,int>>>mp;
    int a,b,wt;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>wt;
        mp[a].push_back(make_pair(b,wt));
        mp[b].push_back(make_pair(a,wt));
    }
    vector<int>parent(n,-1);
    vector<int>key(n,INT_MAX);
    vector<bool>mst(n,false);

    key[0]=0;
    parent[0]=-1;
    int answeigh =0;
    for(int i=0;i<n-1;i++)
    {
        int mini = INT_MAX,u;
        for(int v=0;v<n;v++)
        {
            if(mst[v]==false and key[v] < mini)
            {
                mini = key[v];
                u=v;
            }
            mst[u]= true;

        }
        for(auto it:mp[u])
        {
            int v= it.first;
            int weight = it.second;
            if(mst[v]==false and weight < key[v])
            {
                parent[v]=u;
                key[v]=weight;
            }

        }
    }
    for(int i=1;i<n;i++)
    {
        cout<<parent[i]<<" - "<<i<<"\n";
    }



    return 0;
}