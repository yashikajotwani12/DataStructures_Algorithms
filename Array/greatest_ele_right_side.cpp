#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        
        int n=arr.size();
        int max_ele_so_far=0;
        vector<int>ans;
        ans.push_back(-1);
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i+1] > max_ele_so_far)
            {
                ans.push_back(arr[i+1]);
                max_ele_so_far=arr[i+1];
                
            }else
            {
                ans.push_back(max_ele_so_far);
            }
            
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};