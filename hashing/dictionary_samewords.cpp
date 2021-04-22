#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;
#define MAX_CHAR 26

string getkey(string &str)
{ 
    bool visited[MAX_CHAR]={false};
    for(int j=0;j<str.length();j++)
    { 
        visited[str[j]-'a']=true;
        string key="";
        for(int j=0;j<MAX_CHAR;j++)
        {
            if(visited[j])
            {
                key=key+(char)('a'+j);
            }
        }
        return key;

    }
    

}
void words(string words[], int n)
{
    unordered_map<string, vector<int>>hash;
    for(int i=0;i<n;i++)
    {
        string key=getkey(words[i]);
        hash[key].push_back(i);
    }
    
}