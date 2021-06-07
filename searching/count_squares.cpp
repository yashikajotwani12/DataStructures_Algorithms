#include<bits/stdc++.h>
using namespace std;
int squareans(int n)
{
    int a=sqrt(n);
    if(a*a == n)
    {
        return a-1;
        
    }else{
        return a;
    }
}



int main()
{
    int n=23;
    int ans= squareans(n);
    cout<<ans<<"\n";

    return 0;
}