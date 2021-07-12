#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    vector<string> relations ={"0","1","abc","def", "ghi","jkl","mno","pqrs","tuv","wxyz"};
    void helper(string digits, vector<string> &ans, string currentstr, int i)
    {
        if(i >= digits.size())
        {
            ans.push_back(currentstr);
            return;
        }
        
        string s = relations[digits[i]-'0'];
        for(auto ch : s)
        {
            currentstr += ch;
            helper(digits, ans, currentstr, i+1);
            currentstr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        
        vector<string>ans;
    
        if(digits.size()==0)
            return ans;
        
        
       helper(digits,ans, "",0);         
      return ans;
        
    }
};