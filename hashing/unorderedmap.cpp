#include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string, int>m;
     m.insert(make_pair("Mango",100));
    pair<string,int>p;
    p.first="Apple";
    p.second=120;
    m.insert(p);

    m["Banana"]=20;
    
    for(auto it =m.begin();it!=m.end();it++)
    {
        cout<<it->first<<" and "<<it->second<<endl;
    }


    return 0;
}