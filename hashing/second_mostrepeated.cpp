#include<bits/stdc++.h>
using namespace std;

string secmost(vector<string> seq)
{
    unordered_map<string, int>occ;
    for(int i=0;i<seq.size();i++)
    {
        occ[seq[i]]++;

    }
    int firstmax=INT_MIN;
    int secmax=INT_MIN;
    for(auto it=occ.begin();it!=occ.end();it++)
    {
        if(it->second>firstmax)
        {
            secmax=firstmax;
            firstmax=it->second;
                    }
                    
        else if(it->second > secmax && it->second !=firstmax)
        {
            secmax=it->second;
        }
    }
    for(auto it=occ.begin();it!=occ.end();it++)
    
        if (it->second == secmax) 
            
            return it->first;
}
int main() 
{ 
    vector<string> seq = { "ccc", "aaa", "ccc", 
                          "ddd", "aaa", "aaa" }; 
    cout << secmost(seq); 
    return 0; 
} 