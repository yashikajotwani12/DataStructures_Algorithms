#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int main()
{
    unordered_map< string , double> map;
    map["yashika"]=1.00;
    map["vedant"]=2.00;
    map["sanya"]=3.00;
    map["betu"]=4.00;

    map.insert(make_pair("sakshi",5.00));

    string key="vedant";
    if(map.find(key) == map.end())
    {
       cout << key << " not found\n\n"; 
    }else{
         cout << "Found " << key << "\n\n"; 
    }
    key="yashraj";
    if(map.find(key) == map.end())
    {
       cout << key << " not found\n\n"; 
    }else{
         cout << "Found " << key << "\n\n"; 
    }
    unordered_map<string, double> ::iterator i;
    cout<<"all elements are"<<"\n";
    for(i=map.begin();i!=map.end();i++)
    {
        cout<<i->first<<" "<<i->second <<endl;
          
     }


}