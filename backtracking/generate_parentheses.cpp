#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(vector<string> &ans,int n,int o=0,int c=0,string curr=""){
        if(size(curr)==2*n){
            ans.push_back(curr);
            return;
        }
        if(o<n){
            helper(ans,n,o+1,c,curr+"(");
        }
        
        if(c<o){
            helper(ans,n,o,c+1,curr+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(ans,n);
        return ans;
    }
};