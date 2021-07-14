#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0,i;
        mp[0]=-1;
        
        for(i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            int key=sum%k;
            
            if(mp.find(key)!=mp.end())
            {
                if(i-mp[key]>=2)
                    return true;
            }
            else
            {
                mp[key]=i;
            }
            
        }
        
        return false;
    }
};