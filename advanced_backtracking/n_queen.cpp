#include<bits/stdc++.h>
using namespace std;

bool canplace(int board[][10], int n, int x, int y)
{

   // column
   for(int k=0;k<x;k++)
   {
       if(board[k][y]==1)
       {
           return false;
       }
   }

    // left diagonal
    int i=x,j=y;
    while(i>=0 and j>=0)
    {
        if(board[i][j]==1)
        {
            return false;
        }
        i--;
        j++;
    }

    // right diagonal
    i=x;j=y;
    while(i>=0 and j<n)
    {
        if(board[i][j]==1)
        {
            return false;
        }
        i--;
        j++;
    }

    return false;
}
void nqueen(int n, int board[][10], int i) // i is the current row =0
{
    // base case
    if(i==n)
    {
        // print the board
        for(int x=0;x<n;x++)
        {
            for(int y=0;y<n;y++)
            {
                cout<<board[x][y]<<" ";

            }
            cout<<endl;
           
        }
          cout<<endl;
       
          return 1;
        //  return false;
    }
    // rec case
    // try to place queen at every column/ position in the current row
    for(int j=0;j<n;j++)
    {
        if(canplace(board, n, i,j))
        {
            board[i][j]=1;
            // bool morequeens=
             nqueen(n,board,i+1);
            // if(morequeens)
            // {
            //     return true;

            // }
            board[i][j]=0;
        }
    }
    return;
    //  false;

}
int main()
{
    int board[10][10]={0};
    int n;
    cin>>n;

    cout<<nqueen(n, board,0);
    return 0;
}