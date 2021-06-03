#include<bits/stdc++.h>
using namespace std;

string simplify(string s)
{
    stack<string>st;
    string ans;
    ans+= "/";
    int len=s.length();
    for(int i=0;i<len;i++)
    {
        string dir;
        while(i < len and s[i]=='/')
        {
            i++;
        }
        while(i< len and s[i]!='/')
        {
            dir+= s[i];
            i++;
        }
        if(dir =="..")
        {
            if(!st.empty())
            {
                st.pop();
            }
        }else if(dir ==".")
        {
            continue;
        }
        else if(dir.length()!=0)
        {
            st.push(dir);
        }
    }
    stack<string>strev;
    while(!st.empty())
    {
        strev.push(st.top());
        st.pop();
    }
    while(!strev.empty())
    {
        if(strev.size()!=1)
        {
            ans+= strev.top();
            strev.pop();
            ans+="/";
        }else{
            ans+= strev.top();
            strev.pop();
        }
    }
    return ans;
}
int main()
{
    string s="/a/./b/../../c/";
   string ans= simplify(s);
   cout<<ans<<" ";

    return 0;
}