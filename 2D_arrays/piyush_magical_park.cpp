// park 2d grid
// piyush enters the park with strength s
// obstacles . -2 loose
// magical beans * +5 gain
// blockages # blocked
// --> row wise left to right
// strength of 1 for every step
// strength > k other lost
// return with atleast k strength
// row col k s

// 4 4 5 20
// . . * .
// . # . .
// . # * *

// 13 ans
// easy and good to test fundamentals
// adhoc 
#include<bits/stdc++.h>
using namespace std;

void magicalpark(char a[][100], int m , int n , int k, int s)
{
    bool success = true;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            char ch = a[i][j];
            // one check
            if(s<k)
            {
                success = false;
                break;
            }
            if(ch=='*')
            {
                s+=5;
            }else if(ch=='.')
            {
                s-=2;

            }else{
                break;
            }
            // we also loose 1 point when we move right except for last col
            if(j!=n-1)
            {
                s--;
            }
        }
    }
    if(success)
    {
        cout<<"Yes"<<" ";
        cout<<s<<endl;
    }else{
        cout<<"No"<<endl;
    }
}
int main()
{
    int m,n,k,s;
    cin>>m>>n>>k>>s;
    char park[100][100];

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>> park[i][j];
        }
    }
    magicalpark(park,m,n,k,s);
    return 0;
}
// 4 4 5 20
// . . * .
// . # . .
// * * . .
// . # * *
// Yes 13