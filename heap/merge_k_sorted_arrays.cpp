#include<bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int, int>>ppi;

vector<int>mergekarrays(vector<vector<int>>arr)
{
    vector<int>output;
    priority_queue<ppi, vector<ppi>,greater<ppi>>pq;

    for(int i=0;i<arr.size();i++)
    {
        pq.push({arr[0][i],{i,0}});
    }
    while(!pq.empty())
    {
        ppi curr = pq.top();
        pq.pop();


        int i= curr.second.first;
        int j=curr.second.second;

        output.push_back(curr.first);

        if(j+1 < arr[i].size())
        {
            pq.push({arr[i][j+1],{i,j+1}});
        }
      
    }




    return output;

}

int main()
{
    vector<vector<int>> arr{{2,6,12},
                             {1,9},
                            {22,34,90,2000}
                             };
     vector<int>output = mergekarrays(arr);
     cout<<"Merged Array is "<<endl;
     for(auto x:output)
     {
         cout<<x<<" ";
     }                        

    return 0;

}