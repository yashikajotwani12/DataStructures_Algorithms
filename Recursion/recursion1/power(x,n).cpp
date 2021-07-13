#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    double myPow(double x, int n)
    {
        if(n==0)
        return 1;

        if(n%2==0)
        {
            if(n<0)
            {
                myPow((1/x)*(1/x), abs(n/2));
            }else{
                myPow(x*x,n/2);
            }
        }else{
            if(n<0)
            {
                (1/x)*myPow((1/x)*(1/x), abs(n/2));
            }else
            {
                x*myPow(x*x, abs(n/2));
            }
        }
    }
};