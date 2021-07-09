#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rows,cols;
    vector<vector<bool>> visited;
    string target;
    
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size()==0) return false;
        
        rows=board.size();
        cols=board[0].size();
        target=word;
        
        vector<bool> col(cols,false);
        visited.assign(rows,col);
        
        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)   
            {
                if(backtracking(board,i,j,0)) return true;
            }
        }
        
        return false;
    }
    
    bool backtracking(vector<vector<char>>& board, int r, int c, int cur)
    {
        if(cur==target.length()) return true;
        if(r<0||r>rows-1||c<0||c>cols-1||board[r][c]!=target[cur]) return false;
        if(visited[r][c]) return false;
        
        visited[r][c]=true;
        
        if(backtracking(board,r+1,c,cur+1)
            || backtracking(board,r,c+1,cur+1)
            || backtracking(board,r,c-1,cur+1)
            || backtracking(board,r-1,c,cur+1)) 
            return true;
        
        visited[r][c]=false;
        
        return false;
    }
};