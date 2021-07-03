#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<string,int>m;
    m.insert(make_pair("Mango",100));
    pair<string,int>p;
    p.first="Apple";
    p.second=120;
    m.insert(p);

    m["Banana"]=20;

    string key;
    // cin>>key;

    auto it = m.find(key);
    if(it !=m.end())
    {
        cout<<"price of"<<key<<"is"<<m[key]<<endl;
    }else{
        cout<<"fruit is not present"<<endl;
    }
    //another way to find partivualr map
    // it stores unique keys
    // m.erase(key);
    m[key]+=20;

    if(m.count(key))
    {
        cout<<"Price of fruit is "<<m[key]<<endl;
    }else
    {
        cout<<"could not find a fruit"<<endl;
    }
    //iterate over all the keys
    m["Pineapple"]=80;
    m["Lichi"]=60;

    for(auto it =m.begin();it!=m.end();it++)
    {
        cout<<it->first<<" and "<<it->second<<endl;
    }




    return 0;
}