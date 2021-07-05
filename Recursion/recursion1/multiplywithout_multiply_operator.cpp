#include<bits/stdc++.h>
using namespace std;

int mul(int a,int b)
{
    if(b==0) return 0;

    if(b>0)  {
        return (a + mul(a,b-1));}
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<mul(a,b)<<endl;
    return 0;
}