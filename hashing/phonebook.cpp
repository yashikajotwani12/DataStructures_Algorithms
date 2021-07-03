#include<bits/stdc++.h>
using namespace std;


int main()
{
    unordered_map<string , vector<string>>phonebook;
    phonebook["yashika"].push_back("9100019");
    phonebook["yashika"].push_back("9100016");
    phonebook["yashika"].push_back("9100013");
    phonebook["yashika"].push_back("9100014");
    phonebook["kajal"].push_back("3773737");
    phonebook["kajal"].push_back("37737357");
    phonebook["kajal"].push_back("3773734");
    phonebook["kajal"].push_back("377373432");

    for(auto p:phonebook){
        cout<<endl;
        cout<<"Name   "<<p.first<<"->";
        
        for(string s:p.second){
            cout<<s<<",";
          
        }
    }
    string name;
    cin>>name;
    if(phonebook.count(name)==0)
    {
        cout<<"absent";

    }else{
        for(string s: phonebook[name])
        {
            cout<<s<<endl;
        }
    }


    return 0;
}