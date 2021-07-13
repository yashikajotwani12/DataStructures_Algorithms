#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void backtrack(const vector<int>& nums, vector<bool>& used, vector<int>& path, vector<vector<int>>& rst) {
        if (path.size() == nums.size()) {
            // all numbers are in the path, append the path to the rst
            rst.push_back(path);
        }
        else {
            // path size < number size, loop unused numbers
            for (int i(0); i < nums.size(); ++i) {
                if (!used[i]) {
                    used[i] = true;
                    path.push_back(nums[i]);
                    backtrack(nums, used, path, rst);
                    path.pop_back();
                    used[i] = false;
                }
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        vector<vector<int>> rst;
        vector<int> path;
        backtrack(nums, used, path, rst);
        return rst;
    }
};




class Solution {
private:
    vector<vector<int>> result;
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums, 0, (int)nums.size() - 1);
        
        return result;
    }
    
    void helper(vector<int> num_arr, int l, int r) {
        if (l == r){
            result.push_back(num_arr);
        } 
        else {  
            for (int i = l; i <= r; i++) {
                swap(num_arr[l], num_arr[i]);

                helper(num_arr, l + 1, r); 

                swap(num_arr[l], num_arr[i]);  
            }  
        }
    }  
};