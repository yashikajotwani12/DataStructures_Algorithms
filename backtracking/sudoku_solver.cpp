// given a partially filled 9 X 9 grid
// Input:
// grid = { {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
//          {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
//          {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
//          {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
//          {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
//          {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
//          {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
//          {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
//          {0, 0, 5, 2, 0, 6, 3, 0, 0} }
// Output:
//           3 1 6 5 7 8 4 9 2
//           5 2 9 1 3 4 7 6 8
//           4 8 7 6 2 9 5 3 1
//           2 6 3 4 1 5 9 8 7
//           9 7 4 8 6 3 1 2 5
//           8 5 1 7 9 2 6 4 3
//           1 3 8 9 4 7 2 5 6
//           6 9 2 3 5 1 8 7 4
//           7 4 5 2 8 6 3 1 9

// backtracking
// solved by assigning numbers to empty cells. before assigning check whether it is safe to assign
//check if the same no is not present in a same row, column or subgrid. If the assignment doesn’t lead to a solution, then try the next number for the current empty cell. And if none of the number (1 to 9) leads to a solution, return false and print no solution exists.

#include<bits/stdc++.h>
using namespace std;

#define UNASSIGNED 0
#define N 9


bool findunassignedlocation(int grid[N][N] , int &row, int &col)
{
    for(row =0 ; row<N;row++)
    {
        for(col =0 ;col<N;col++)
        {
            if(grid[row][col] == UNASSIGNED)
            return true;
        }
    }
    return false;
}

bool usedinrow(int grid[N][N] , int row, int num)
{
    for(int col =0; col<N ; col++)
    {
        if(grid[row][col]==num)
        {
           return true;
        }
    }
    return false;
}
bool usedincol(int grid[N][N] , int col, int num)
{
    for(int row =0; row<N ; row++)
    {
        if(grid[row][col]==num)
        {
           return true;
        }
    }
    return false;
}
bool usedinbox(int grid[N][N] , int boxstartrow, int boxstartcol , int num)
{
    for(int row =0;row<3;row++)
    {
        for(int col=0;col<3;col++)
        {
            if(grid[row+boxstartrow][col+boxstartcol]==num)
            {
                return true;
            }
        }
    }
    return false;
}
bool issafe(int grid[N][N], int row, int col, int num)
{
    return !usedinrow(grid, row, num) and !usedincol(grid, col, num) and !usedinbox(grid, row-row%3, col-col%3, num) and grid[row][col] ==UNASSIGNED;

}
bool solvesudoku(int grid[N][N])
{
    int row,col;
   // no unassigned location that is all are filled then we are done and retuen true
   // base case
    if(!findunassignedlocation(grid, row, col))
    {
        return true;
    }
    for(int num =1 ; num<=9 ; num++)
    {
        if(issafe(grid, row, col, num))
        {
            grid[row][col] = num;
            // return if succes
            if(solvesudoku(grid))
              return true;
            // failure unmake and try and assign
              grid[row][col]= UNASSIGNED;
        }

    }
    // this triggers backtracking
    return false;

}
void printGrid(int grid[N][N])
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
            cout << grid[row][col] << " ";
        cout << endl;
    }
}
int main()
{
     int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
    if (solvesudoku(grid) == true)
        printGrid(grid);
    else
        cout << "No solution exists";
 
    return 0;
}