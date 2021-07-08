#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> result;

bool issafe(vector<vector<int>>board, int col, int row)
{
    int i,j;
    int n=board.size();
   

   // check this row on left side
    for(i =0; i<col;i++)
    {
        if(board[row][i])
        {
            return false;
        }
    }
    // check upper diagonal on left side
    for(i =row , j=col; i>=0 and j>=0 ;i--,j--)
    {
        if(board[i][j])
        {
            return false;
        }

    }
    /* Check lower diagonal on left side */
    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;

 return true;

}
bool solvenq(vector<vector<int>>& board, int col)
{
    int n=board.size();
    if(col== n)
    {
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==1)
                {
                    v.push_back(j+1);
                }

            }
        }
         result.push_back(v);
          return true;
    }


    bool res = false;
    for(int i=0;i<n;i++)
    {
        if(issafe(board, i, col))
        {
            board[i][col]=1;

            res = solvenq(board, col+1) || res;

            board[i][col]=0;
        }
    
    }
    return res;
   
   

}
vector<vector<int> > nQueen(int n)
{
    result.clear();
    vector<vector<int> > board(n, vector<int>(n, 0));
 
    if (solvenq(board, 0) == false) {
        return {};
    }
 
    sort(result.begin(), result.end());
    return result;
}
 
int main()
{
     int n = 4;
    vector<vector<int> > v = nQueen(n);
 
    for (auto ar : v) {
        cout << "[";
        for (auto it : ar)
            cout << it << " ";
        cout << "]";
    }
    return 0;
}