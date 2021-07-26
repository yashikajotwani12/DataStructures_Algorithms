#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[1000][1000]={0};
    int val=1;
    int n,m;
    cin>>m>>n;

    for(int row =0; row<=m-1;row++)
    {
        for(int col =0;col<=n-1;col++)
        {
            a[row][col]= val;
            val = val+1;
            
             cout<<a[row][col]<<" ";

        }
       cout<<endl;
    }
    return 0;
}