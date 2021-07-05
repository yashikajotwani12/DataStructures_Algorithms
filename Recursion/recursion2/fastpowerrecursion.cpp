#include<bits/stdc++.h>
using namespace std;



// a^n -> (a^n/2)^2 n is even 
// a^n -> a( a^n/2)^2 n is odd

// a ^ 9= a(a^4)^2
//         (a^2)^2
//          (a^1)^2
//          a(a^0)^2
//           log n



int fastpower(int a, int n)
{
    if(n==0)
    {
        return 1;
    }
    int  subprob = fastpower(a,n/2);
    subprob*=subprob;
    if( n&1) // odd
    {
        return subprob*a;
    }
    return subprob;
    // log n

}


int main()
{
    int a,n;
    cin>>a>>n;

    cout<<fastpower(a, n);
    return 0;
}