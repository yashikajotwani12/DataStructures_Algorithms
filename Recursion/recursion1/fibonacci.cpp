#include<bits/stdc++.h>
using namespace std;
// fib no depends upon its previous two numbers 
int nfib(int n)
{
    //base case
    if(n== 0 or n==1)
    {
        return n;

    }
    //recursive case
    // int f1= nfib(n-1);
    // int f2 = nfib(n-2);
    // return f1+f2;
    return nfib(n-1) + nfib(n-2);
}

int main()
{
    int n;
    cin>>n;
    cout<<nfib(n);
    return 0;
}