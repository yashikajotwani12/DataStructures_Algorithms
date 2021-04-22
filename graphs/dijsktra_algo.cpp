#include<bits/stdc++.h>
using namespace std;

#define v 6

int selectminvertex(vector<int>&value, vector<bool>&processed)
{
    int minimum = INT_MAX;
    int vertex;
    for(int i=0;i<v;i++)
    {
        if(processed[i]== false && value[i]< minimum)
        {
            vertex = i;
            minimum = value[i];
        }
    }
    return vertex;
}

void dijkstra(int graph[v][v])
{
    int parent[v];
    vector<int> value(v, INT_MAX);
    vector<bool> processed(v, false);
    parent[0]=-1;
    value[0]=0;

    for(int i=0;i<v-1;i++)
    {
        int u=selectminvertex(value, processed);
        processed[u]=true;
        for(int j=0;j<v;j++)
        {
            if(graph[u][j]!=0 && processed[j]==false && value[u]!=INT_MAX && (value[u]+graph[u][j]< value[j]))
            {
                value[j]=value[u]+graph[u][j];
                parent[j]=u;
            }
        }

    }
    for(int i=1;i<v;i++)
    {
        cout<<"u->v "<<parent[i]<<"-> "<<i<<" wt = "<<graph[parent[i]][i]<<"\n";
    }
    
}
int main()
{
	int graph[v][v] = { {0, 1, 4, 0, 0, 0},
						{1, 0, 4, 2, 7, 0},
						{4, 4, 0, 3, 5, 0},
						{0, 2, 3, 0, 4, 6},
						{0, 7, 5, 4, 0, 7},
						{0, 0, 0, 6, 7, 0} };

	dijkstra(graph);	
	return 0;
}

//TIME COMPLEXITY: O(V^2)
//TIME COMPLEXITY: (using Min-Heap + Adjacency_List): O(ElogV)
