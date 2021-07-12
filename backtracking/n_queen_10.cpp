            //   { 0,  1,  0,  0}
            //   { 0,  0,  0,  1}
            //   { 1,  0,  0,  0}
            //   { 0,  0,  1,  0}


#include<bits/stdc++.h>
#define N 4
using namespace std;


void printsolution(int board[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<board[i][j];
        }
        cout<<endl;
    }
}

// utility function to check whether a queen can be placed or not
bool issafe(int board[N][N], int row, int col)
{
    int i,j;
    // row checks
    for( i=0;i<col;i++)
    {
        if(board[row][i])
        {
            return false;
        }
    }
    for(i = row,j=col ; i>=0 and j>=0 ; i--,j--)
    {
        if(board[i][j])
        {
            return false;
        }
    }
    for(i = row,j=col ; j>=0 and i<N ; i++,j--)
    {
        if(board[i][j])
        {
            return false;
        }
    }
    return true;
}

bool solveNqueensUtil(int board[N][N] , int col)
{
    // base case
    if(col >= N)
    {
        return true;
    }

    for(int i=0;i<N;i++)
    {
        if(issafe(board,i,col))
        {
            board[i][col]=1;

          // recur to place rest of the queens
            if(solveNqueensUtil(board, col+1))
            return true;

            
             // does not lead to a solution then backtrack
            board[i][col]=0;

        }
    }
    return false;
}
bool solveNqueens()
{
    int board[N][N]= { { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 } };

 if(solveNqueensUtil(board,0) == false)
 {
     cout<<" No Solution ";
     return false;
 }
 printsolution(board);
 return true;
}
int main()
{
    solveNqueens();
    return 0;
}

// another solution

#include<bits/stdc++.h>
using namespace std;
int ar[11][11];
 int n;

 bool issafe(int row,int col)
 {
    // coloumn check
    int count=0;
      for(int k=0;k<row;k++)
           if(ar[k][col]==1)
            return false;


  //upper right diagnoal 
  int k=row; int l=col;
    while(k>=0&&l<n){
       if(ar[k][l]==1)
         return false;
     k--; l++;    
    }

 //upper left diagnoal
 k=row; l=col;
 while(k>=0&&l>=0)
 {
     if(ar[k][l]==1)
         return false;
 k--; l--;
 }

 return true;
 }

bool solve(int row)
{
  if(row>=n)
    return true;

     for(int i=0;i<n;i++)
     {
        if(issafe(row,i))
          {ar[row][i]=1;
            if(solve(row+1))
             return true;
             ar[row][i]=0;
           }
      }
      return false;

}
void print1()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<ar[i][j]<<" ";
        }
        cout<<endl;
    }


}


main()
{

 cin>>n;
for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
     ar[i][j]=0;

if(solve(0))
    print1();
else
    cout<<"Not possible";



}
