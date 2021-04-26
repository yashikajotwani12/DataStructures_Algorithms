// //given boolean 2d matrix
// // Input : mat[][] = {{1, 1, 0, 0, 0},
// //                    {0, 1, 0, 0, 1},
// //                    {1, 0, 0, 1, 1},
// //                    {0, 0, 0, 0, 0},
// //                    {1, 0, 1, 0, 1} 
// // Output : 5

// //connected components

// #include<bits/stdc++.h>
// using namespace std;

// #define row 5
// #define col 5

// // a function that a given cell can be included in dfs
// //1 row is in range
// //2 col is in range
// //3 value is 1
// //4 not yet visited

// int issafe(int m[][col] ,int rows, int cols, bool visited[][col] )
// {
//     return (rows >=0) && (rows < row) && (col >=0) && (cols <col) && (m[row][col] && !visited[row][col]);
// }
// // 2d boolean matrix , it only considers the 8 neighbours as adjacent vertices
// void dfs(int m[][col], int rows, int cols, bool visited[][col])
// {
//     // these arrays are used to get row and col num of 8 neighbours 

//     static int rownbr[] = {-1,-1,-1,0,0,1,1,1};
//     static int colnbr[] = {-1,0,1,-1,1,-1,0,1};

//     visited[rows][cols]= true;
//     for(int k = 0 ; k < 8; ++k)
//     {
//         if(issafe(m,rows +rownbr[k], cols + colnbr[k], visited))
//         dfs(m, rows +rownbr[k] , cols+ colnbr[k], visited);
//     }

// }
// //main function that returns count of islands in a given boolean 2d matrix

// int countislands(int m[][col])
// {
//     bool visited[row][col]; // to mark the visited cells
//     memset(visited, 0, sizeof(visited)); //all cells are unvisited

//     int count=0;
//     for(int i=0;i< row; ++i)
    
//         for(int j=0;j<col;++j)
        
//             if(m[i][j] && !visited[i][j])
            
//              {  
//                   dfs(m,i,j,visited);
//                ++count;
//              }

//       return count;
// }
// int main()
// {
//     int M[][col] = { { 1, 1, 0, 0, 0 },
//                      { 0, 1, 0, 0, 1 },
//                      { 1, 0, 0, 1, 1 },
//                      { 0, 0, 0, 0, 0 },
//                      { 1, 0, 1, 0, 1 } };
 
//     cout << "Number of islands is: " << countislands(M);
 
//     return 0;
// }
// // Time complexity: O(ROW x COL)

// C++ Program to count islands in boolean 2D matrix
#include <bits/stdc++.h>
using namespace std;
 
#define ROW 5
#define COL 5
 
// A function to check if a given
// cell (row, col) can be included in DFS
int isSafe(int M[][COL], int row, int col,
           bool visited[][COL])
{
    // row number is in range, column
    // number is in range and value is 1
    // and not yet visited
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (M[row][col] && !visited[row][col]);
}
 
// A utility function to do DFS for a
// 2D boolean matrix. It only considers
// the 8 neighbours as adjacent vertices
void DFS(int M[][COL], int row, int col,
         bool visited[][COL])
{
    // These arrays are used to get
    // row and column numbers of 8
    // neighbours of a given cell
    static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
 
    // Mark this cell as visited
    visited[row][col] = true;
 
    // Recur for all connected neighbours
    for (int k = 0; k < 8; ++k)
        if (isSafe(M, row + rowNbr[k], col + colNbr[k], visited))
            DFS(M, row + rowNbr[k], col + colNbr[k], visited);
}
 
// The main function that returns
// count of islands in a given boolean
// 2D matrix
int countIslands(int M[][COL])
{
    // Make a bool array to mark visited cells.
    // Initially all cells are unvisited
    bool visited[ROW][COL];
    memset(visited, 0, sizeof(visited));
 
    // Initialize count as 0 and
    // travese through the all cells of
    // given matrix
    int count = 0;
    for (int i = 0; i < ROW; ++i)
        for (int j = 0; j < COL; ++j)
 
            // If a cell with value 1 is not
            if (M[i][j] && !visited[i][j]) {
                // visited yet, then new island found
                // Visit all cells in this island.
                DFS(M, i, j, visited);
 
                // and increment island count
                ++count;
            }
 
    return count;
}
 
// Driver code
int main()
{
    int M[][COL] = { { 1, 1, 0, 0, 0 },
                     { 0, 1, 0, 0, 1 },
                     { 1, 0, 0, 1, 1 },
                     { 0, 0, 0, 0, 0 },
                     { 1, 0, 1, 0, 1 } };
 
    cout << "Number of islands is: " << countIslands(M);
 
    return 0;
}