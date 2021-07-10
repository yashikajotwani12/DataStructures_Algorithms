#include<bits/stdc++.h>
using namespace std;

int countpairs(int n)
{
    // base condition
    if(n==0 || n==1 || n==2) return n;
    return  countpairs(n-1) + (n-1)*countpairs(n-2);
   
}

int main()
{
    int n=4;
    cout<<countpairs(n)<<endl;
    return 0;
}