#include<bits/stdc++.h>
using namespace std;

int main()
{
    int array[100][100];
    int m,n;
    cin>>m>>n;
    int val=1;
    // iterating and printing
    for(int row = 0;row<=m-1;row++)
    {
        for(int col =0;col<=n-1;col++)
        {
            array[row][col]= val;
            val= val+1;
            cout<<array[row][col]<<" ";

        }
        cout<<endl;

    }
    // to print the wave
    for(int col = 0;col<n;col++)
    {
        // col is even then top down
        if(col%2==0)
        {
          for(int row=0;row<m;row++)
          {
              cout<<array[row][col]<<" ";
          }
        }else{
            for(int row = m-1;row>=0;row--)
            {
                cout<<array[row][col]<<" ";
            }
        }
         
    }
    return 0;
 
}