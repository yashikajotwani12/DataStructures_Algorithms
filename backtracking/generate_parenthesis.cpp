// Algorithm:

// Keep track of counts of open and close brackets.

// Initialize these counts as 0.

// Recursively call the generateParenthesis() function until open bracket count is less than the given n.

// If open bracket count becomes more than the close bracket count, then put a closing bracket and recursively call for the remaining brackets.

// If open bracket count is less than n, then put an opening bracket and call _printParenthesis() for the remaining brackets.
#include<bits/stdc++.h>
using namespace std;

void generateparenthesis( int n, int openb, int closeb, string str)
{
    if(closeb== n)
    {
        cout<<str<<endl;
    }
    if(openb > closeb)
    {
        generateparenthesis(n, openb, closeb+1, str+')');

    }
    if(openb < n)
    {
        generateparenthesis(n, openb+1, closeb, str+'(');
    }
}
int main()
{
    int n;
    cin>>n;
    generateparenthesis(n, 0,0,"");
    return 0;
}