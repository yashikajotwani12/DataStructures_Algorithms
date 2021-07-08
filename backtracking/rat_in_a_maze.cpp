#include<bits/stdc++.h>
using namespace std;
bool ratinamaze(char maze[10][10] , int sol[][10] , int i, int j, int m , int n)
{
    if(i==m and j==n)
    {
        sol[m][n]=1;
        // print the path
        for(int p=0;p<=m;p++)
        {
            for(int q=0;q<=n;q++)
            {
                cout<<sol[p][q]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    // rat should be inside grid
    if( i> m and j>n)
    {
        return false;
    }
    // deadend
    if(maze[i][j]=='X')
    {
        return  false;
    }
    // assume solution exist through current cell

    sol[i][j]=1;

    bool rightside = ratinamaze(maze, sol,i,j+1,m,n);
    bool downside = ratinamaze(maze, sol,i+1,j,m,n);

    
    // backtracking 
    sol[i][j] = 0; // returning and making 0
    if(rightside || downside)
    {

        return true;

    }
    return false;

}
int main()
{
    char maze[10][10]={
        "0000",
        "00X0",
        "000X",
        "0X00",
    };
    int sol[10][10]={0};
    int m = 4, n = 4;
    bool ans = ratinamaze(maze,sol, 0 ,0 ,m-1,n-1);
    if(ans==false)
    {
        cout<<"Path does'nt exist!";
    }


    return 0;
}