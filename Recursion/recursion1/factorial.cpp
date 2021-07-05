#include<bits/stdc++.h>
using namespace std;

int factorial(int n)
{    // base case
    if(n==0 )
    {
        return 1;
    }
     // recursive case
        // int smallans = factorial(n-1);
        // int ans= n* smallans;

        // return ans;
        return n*factorial(n-1);

}
int main()
{
    int n;
    cin>>n;
    int ans = factorial(n);
    cout<<ans<<endl;
    return 0;

}