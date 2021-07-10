#include<bits/stdc++.h>
using namespace std;
int gettile(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    return gettile(n-1) + gettile(n-2);
}
int main()
{
    cout<<gettile(4)<<endl;
    cout<<gettile(5)<<endl;
    return 0;
}