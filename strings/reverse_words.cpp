#include<bits/stdc++.h>
using namespace std;
void reversed(string s)
{
    vector<string>temp;
    string str="";
    for(int i=0;i<s.size();i++)
    {
       if(s[i]==' ')
       {
           temp.push_back(str);
           str="";
       }else{
           str+=s[i];
       }

    }
    temp.push_back(str);

    for(int i=temp.size()-1 ; i>0 ; i--)
    {
        cout<<temp[i]<<" ";
        
    }
    cout<<temp[0];

}
int main()
{
    string s="i like this program very much";
    reversed(s);
    return 0;
}