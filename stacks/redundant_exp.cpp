#include<bits/stdc++.h>
using namespace std;
bool validexp(string &s)
{
    stack<char>st;

   for(auto & ch :s)
   {
       
       if(ch==')')
       {
           char top =st.top();
           st.pop();
           bool flag=true;
           while(!st.empty() and top!='(')
           {
               if(top=='+' || top=='-' || top=='*' || top=='/')
               {
                   flag=false;
               }
               top =st.top();
               st.pop();
               
           }
           if(flag==true)
           {
               return true;
           }

       }
      else
       {
           st.push(ch);
       }
   }
   return false;
}

void findRedundant(string& str)
{
    bool ans = validexp(str);
    if (ans == true)
        cout << "Yes\n";
    else
        cout << "No\n";
}
 
int main()
{
    string str = "((a+b))";
    findRedundant(str);
 
    str = "(a+(b)/c)";
    findRedundant(str);
 
    str = "(a+b*(c-d))";
    findRedundant(str);
 
    return 0;
}