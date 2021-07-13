#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checker(vector<vector<char>>& board, int x, int y, char u){
        for(int i=0;i<9;i++)
            if(board[x][i] == u or board[i][y] == u) return false;
        
        int row = x - (x%3);
        int col = y - (y%3);
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(board[row+i][col+j] == u) return false;
        return true;
    }
    
    void solve(vector<vector<char>>& board, int i, int j , bool &found){
        if(i==9){
            found = true;
            return;
        }
        if(board[i][j] == '.'){
            for(int k=0;k<9;k++){
                char temp = '1'+ k;
                
                if(checker(board, i,j, temp)){
                    board[i][j] = temp;
                    if(j == 8)
                        solve(board,i+1, 0, found);
                    else
                        solve(board,i, j+1, found);
                    if(!found)
                        board[i][j] = '.';
                }
               
            }  
        }
        else if(j == 8)
            solve(board,i+1, 0, found);
        else
             solve(board,i, j+1, found);
    }
    void solveSudoku(vector<vector<char>>& board) {
        bool found = false;
        solve(board, 0, 0, found);
    }
};