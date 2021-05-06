#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,m,arr[1000][1000],i,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>m;
        for( i=0;i<n;i++)
        {
            for( j=0;j<m;j++)
            {
                cin>>arr[i][j];

            }

        }
        for(j=0;j<m;j++)
        {
            for(i=0;i<n;i++)
            {
                if(arr[i][j]==1)
                goto x;
            }

        }
        x:cout<<i<<endl;

    }
    return 0;
    
}