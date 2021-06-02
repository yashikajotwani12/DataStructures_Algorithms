#include<bits/stdc++.h>
using namespace std;

int longest(string s)
{
    stack<int>st;
    st.push(-1);
    int result=0;
    for(int i=0;i<s.length();i++ )
    {
        if(s[i]=='(')
        {
            st.push(i);
        }
        else
        {
            if(!st.empty())
            {
                st.pop();
            }
            if(!st.empty())
            {
                result = max(result, i-st.top());


            }else{
                st.push(i);
            }
        }
    }
    return result;
}

int main()
{
    string str = "((()()";
   
    // Function call
    cout << longest(str) << endl;
 
    str = "()(()))))";
   
    // Function call
    cout << longest(str) << endl;
 
    return 0;
}