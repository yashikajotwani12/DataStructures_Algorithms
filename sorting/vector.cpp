#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>v;
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    vector<int>::iterator i;
    for(i=v.begin();i!=v.end();i++)
    {
         cout<<*i<<" ";
    }
    cout<<endl;
    for(auto i:v)
    {
         cout<<i<<" ";
    }

}
