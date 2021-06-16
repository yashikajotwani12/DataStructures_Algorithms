// 905. Sort Array By Parity
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        vector<int>ans;
        
        while(i<j)
        {
            if(nums[i]%2!=0)
            {
                swap(nums[i], nums[j]);
                j--;
            }else
            {
                i++;
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            ans.push_back(nums[i]);
            
        }
        return ans;
    }
};